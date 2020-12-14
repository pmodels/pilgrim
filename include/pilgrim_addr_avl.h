#ifndef _PILGRIM_ADDR_AVL_H
#define _PILGRIM_ADDR_AVL_H
/* implementation of an AVL tree with explicit heights */
typedef struct AddrIdNode_t {
    int id;
    struct AddrIdNode_t *prev;
    struct AddrIdNode_t *next;
} AddrIdNode;


typedef struct AvlNode_t {
    struct AvlNode_t *child[2];  // left and right

    intptr_t addr;               // use addr as key
    size_t size;                 // size of allocated memory
    AddrIdNode* id_node;         // symbolic id to represent this memory buffer

    int height;
} AvlNode;

typedef struct AvlNode_t *AvlTree;

/* empty avl tree is just a null pointer */
#define AVL_EMPTY (0)

/* free a tree */
void avl_destroy(AvlTree t);

/* return the height of a tree */
int avl_get_height(AvlTree t);

/* return nonzero if key is present in tree */
AvlTree avl_search(AvlTree t, intptr_t addr);

/* insert a new element into a tree */
/* note *t is actual tree */
AvlTree avl_insert(AvlTree *t, intptr_t addr, size_t size);

/* run sanity checks on tree (for debugging) */
/* assert will fail if heights are wrong */
void avl_sanity_check(AvlTree t);

/* print all keys of the tree in order */
void avl_print_keys(AvlTree t);

void avl_delete(AvlTree *t, intptr_t addr);

/* delete and return minimum value in a tree */
AvlTree avl_delete_min(AvlTree *t);

#endif
