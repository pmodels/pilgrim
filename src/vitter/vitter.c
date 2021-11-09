#include "vitter.h"
//#define _DEBUG 1
//#define DEBUG_VITTER_IO 1

_Static_assert(sizeof(vitter_node_t) == 8UL,
	"sizeof(vitter_node_t) ought to be 8");
_Static_assert(sizeof(vitter_tree_t) == 32UL,
	"sizeof(vitter_tree_t) ought to be 32");
//_Static_assert(sizeof(vitter_t) == 64UL,
//  "sizeof(vitter_t) ought to be 64");

#include <errno.h>
#include <stdlib.h>
#include <assert.h>

#if defined(_DEBUG) || defined(DEBUG_VITTER_IO)
#include <stdio.h>
#endif /* _DEBUG || DEBUG_VITTER_IO */

typedef vitter_tree_t *const vt_p;
typedef const vitter_tree_t *const cvt_p;

static void increment(vt_p tree, uint16_t node);
static uint16_t get_leader(vt_p tree, uint16_t node);
static uint16_t get_max(cvt_p tree);
static bool get_symbol(uint16_t *symbol, bitstream_t *source, cvt_p tree);
static void put_symbol(bitstream_t *destination, cvt_p tree, uint16_t symbol);
static uint16_t slide(vt_p tree, uint16_t node);
static bool split(uint16_t *node, vt_p tree, uint16_t symbol);


bool vitter_alloc(vitter_t *v, uint16_t size)
{
	if (size < 4 || size >> 15)
		return errno = EINVAL, false;
	v->tree.map = calloc(sizeof(*v->tree.map), size);
	v->tree.nodes = calloc(sizeof(*v->tree.nodes), size * 2);
	if (!v->tree.map || !v->tree.nodes)
		return vitter_dealloc(v), false;
	v->tree.escape = v->tree.root = size * 2 - 1;
	v->tree.size = size;
    v->current_bits = 0;
    v->total_bytes  = 0;
	return true;
}

void vitter_dealloc(vitter_t *v)
{
	if (v->tree.map)
		free(v->tree.map), v->tree.map = NULL;
	if (v->tree.nodes)
		free(v->tree.nodes), v->tree.nodes = NULL;
}

void vitter_inc_bits(vitter_t* v, uint16_t len) {
    v->current_bits += len;
    if(v->current_bits / 16 > 0) {
        v->total_bytes += 2*(v->current_bits / 16);
        v->current_bits = (v->current_bits % 16);
    }
}

size_t vitter_get_bytes(vitter_t* v) {
    return v->total_bytes;
}


bool vitter_decode(uint16_t *symbol, vitter_t *v)
{
	vitter_tree_t *const tree = &v->tree;
	uint16_t node = tree->root;
#ifdef DEBUG_VITTER_IO
	fputs(__FUNCTION__, stderr);
	fputs(": {", stderr);
#endif /* DEBUG_VITTER_IO */
	while (tree->nodes[node].child) {
		uint16_t c = bitstream_getbits(&v->stream, 1);
#ifdef DEBUG_VITTER_IO
		fprintf(stderr, "%hu", c);
#endif /* DEBUG_VITTER_IO */
		node = tree->nodes[node].child - c;
	}
#ifdef DEBUG_VITTER_IO
	fputc('}', stderr);
#endif /* DEBUG_VITTER_IO */
	if (node == tree->escape) {
		if (!tree->escape) {
#ifdef _DEBUG
			fprintf(stderr, "%s: tree is full\n", __FUNCTION__);
#endif /* _DEBUG */
			return false;
		}
		if (!get_symbol(symbol, &v->stream, tree))
			return false;
		if (!split(&node, tree, *symbol))
			return false;
	} else
		*symbol = tree->nodes[node].symbol;
#ifdef DEBUG_VITTER_IO
	fprintf(stderr, " => %03x\n", *symbol);
#endif /* DEBUG_VITTER_IO */
	increment(tree, node);
	return true;
}


bool vitter_encode(vitter_t *v, uint16_t symbol)
{
	vitter_tree_t *const tree = &v->tree;
	if (tree->size <= symbol) {
        #ifdef _DEBUG
		fprintf(stderr, "invalid symbol, %u\n", symbol);
        #endif /* _DEBUG */
		return false;
	}
	uint16_t node = tree->map[symbol], idx = node ? node : tree->escape;
	if (!idx) {
        #ifdef _DEBUG
		fprintf(stderr, "%s: tree is full\n", __FUNCTION__);
        #endif /* _DEBUG */
		return false;
	}
	uint16_t code = 1;
	while (tree->nodes[idx].parent) {
		uint16_t parent = tree->nodes[idx].parent;
		assert((code >> 15) == 0);
		code = code << 1 | (idx & 1);
		idx = parent;
	}

    #ifdef DEBUG_VITTER_IO
	fprintf(stderr, "%s: %d => {", __FUNCTION__, symbol);
    #endif /* DEBUG_VITTER_IO */

	while (code >> 1) {
		uint16_t half = code >> 1;
		bitstream_putbits(&v->stream, code, 1);
        vitter_inc_bits(v, 1);
        #ifdef DEBUG_VITTER_IO
		fprintf(stderr, "%u", code & 1);
        #endif /* DEBUG_VITTER_IO */
		code = half;
	}
    #ifdef DEBUG_VITTER_IO
	fprintf(stderr, "}");
    #endif /* DEBUG_VITTER_IO */

	if (!node) {
		put_symbol(&v->stream, tree, symbol);
        vitter_inc_bits(v, 16);
		if (!split(&node, tree, symbol))
			return false;
	}
#ifdef DEBUG_VITTER_IO
	fprintf(stderr, "\n");
#endif /* DEBUG_VITTER_IO */
	increment(tree, node);
	return true;
}

#ifdef USE_VITTER_SCALE
void vitter_scale(vitter_tree_t *tree, uint16_t bits)
{
	uint16_t node = tree->escape, weight, prev;
	while (++node <= tree->root) {
		vitter_node_t *nd = tree->nodes + node;
		if (nd->weight & 1) {
			vitter_node_t *l = tree->nodes + nd->child - 1;
			vitter_node_t *r = tree->nodes + nd->child;
			if ((weight = r->weight & ~1))
				weight += l->weight | 1;
		} else if (!(weight = nd->weight >> bits & ~1)) {
			tree->map[nd->symbol] = 0;
			if (tree->escape++)
				tree->escape++;
		}
		nd->weight = weight;
		prev = node;
		while (weight < tree->nodes[--prev].weight)
			(void)slide(tree, prev);
	}
	tree->nodes[tree->escape].child = 0;
}
#endif /* USE_VITTER_SCALE */

static void increment(vt_p tree, uint16_t node)
{
	vitter_node_t *nd = tree->nodes + node;
	if (nd->parent == node + 1) {
		nd->weight += 2;
		node++;
	} else
		node = get_leader(tree, node);
	for (;;) {
		nd = tree->nodes + node;
		nd->weight += 2;
		uint16_t parent = nd->parent;
		if (!parent)
			break;
		while (tree->nodes[node + 1].weight < nd->weight) {
			node = slide(tree, node);
			nd = tree->nodes + node;
		}
		node = (nd->weight & 1) ? parent : nd->parent;
	}
}

static uint16_t get_leader(vt_p tree, uint16_t node)
{
	uint16_t leader = node;
	while (tree->nodes[node].weight == tree->nodes[leader + 1].weight)
		leader++;
	if (leader == node)
		return node;
	uint16_t symbol = tree->nodes[node].symbol;
	uint16_t prev = tree->nodes[leader].symbol;
	tree->nodes[leader].symbol = symbol;
	tree->nodes[node].symbol = prev;
	tree->map[symbol] = leader;
	tree->map[prev] = node;
	return leader;
}

static uint16_t get_max(cvt_p tree)
{
	return tree->size - (tree->root - tree->escape) / 2 - 1;
}

static bool get_symbol(uint16_t *symbol, bitstream_t *source, cvt_p tree)
{
	uint16_t empty = 0;
	for (uint16_t bit = 1, max = get_max(tree); max; bit <<= 1, max >>= 1) {
		uint16_t c = bitstream_getbits(source, 1);
#ifdef DEBUG_VITTER_IO
		fprintf(stderr, "%hu", c);
#endif /* DEBUG_VITTER_IO */
		empty |= c ? bit : 0;
	}
	for (*symbol = 0; *symbol < tree->size; (*symbol)++)
		if (!tree->map[*symbol] && !empty--)
			return true;
#ifdef _DEBUG
	fputs("too few nodes\n", stderr);
#endif /* _DEBUG */
	return false;
}

static void put_symbol(bitstream_t *destination, cvt_p tree, uint16_t symbol)
{
	uint16_t empty = 0;
	while (symbol--)
		if (!tree->map[symbol])
			empty++;
	for (uint16_t max = get_max(tree); max; empty >>= 1, max >>= 1) {
		bitstream_putbits(destination, empty, 1);
        #ifdef DEBUG_VITTER_IO
		fprintf(stderr, "%u", empty & 1);
        #endif /* DEBUG_VITTER_IO */
	}
}

static uint16_t slide(vt_p tree, uint16_t node)
{
	uint16_t next = node;
	const vitter_node_t temp = tree->nodes[next++];
	if (temp.weight & 1)
		while (tree->nodes[next + 1].weight < temp.weight)
			next++;
	vitter_node_t *const nd = tree->nodes + node;
	vitter_node_t *const nx = tree->nodes + next;
	nd->child = nx->child;
	nd->symbol = nx->symbol;
	nd->parent = temp.parent;
	nd->weight = nx->weight;
	nx->child = temp.child;
	nx->symbol = temp.symbol;
	nx->weight = temp.weight;
	uint16_t child = temp.weight & 1 ? temp.child : nd->child;
	uint16_t symbol = temp.weight & 1 ? nd->symbol : temp.symbol;
	vitter_node_t *const l = tree->nodes + child - 1;
	vitter_node_t *const r = tree->nodes + child;
	l->parent = r->parent = temp.weight & 1 ? next : node;
	tree->map[symbol] = temp.weight & 1 ? node : next;
	return next;
}

static bool split(uint16_t *node, vt_p tree, uint16_t symbol)
{
	if (!tree->escape) {
#ifdef _DEBUG
		fprintf(stderr, "%s: tree is full\n", __FUNCTION__);
#endif /* _DEBUG */
		return false;
	}
	uint16_t parent = tree->escape;
	tree->escape--;
	if (tree->escape) {
		*node = tree->escape;
		tree->escape--;
		tree->nodes[parent].child = *node;
		tree->nodes[parent].weight = 1;
		tree->nodes[*node].parent = parent;
	} else {
		*node = 1;
		parent = 0;
	}
	tree->map[symbol] = *node;
	vitter_node_t *nd = tree->nodes + *node;
	nd->child = nd->weight = 0;
	nd->symbol = symbol;
	vitter_node_t *esc = tree->nodes + tree->escape;
	esc->child = esc->weight = 0;
	esc->parent = parent;
	return true;
}
