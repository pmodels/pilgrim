/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "pilgrim_addr_avl.h"
#include "pilgrim_utils.h"

/* implementation of an AVL tree with explicit heights */

/* free a tree */
void
avl_destroy(AvlTree t)
{
    if(t != AVL_EMPTY) {
        avl_destroy(t->child[0]);
        avl_destroy(t->child[1]);
        if(t->id_node)
            pilgrim_free(t->id_node, sizeof(AddrIdNode));
        pilgrim_free(t, sizeof(AvlNode));
    }
}

/* return height of an AVL tree */
int
avl_get_height(AvlTree t)
{
    if(t != AVL_EMPTY) {
        return t->height;
    } else {
        return 0;
    }
}

/* return nonzero if key is present in tree */
AvlTree
avl_search(AvlTree t, intptr_t addr)
{
    if(t == AVL_EMPTY) {
        return AVL_EMPTY;
    }

    intptr_t lower = t->addr;
    intptr_t upper = t->addr + (intptr_t)(t->size); // must cast size_t to intptr_t first!
    if(lower <= addr && addr < upper) {
        return t;
    } else {
        return avl_search(t->child[addr> t->addr], addr);
    }
}

#define Max(x,y) ((x)>(y) ? (x) : (y))

/* assert height fields are correct throughout tree */
void
avl_sanity_check(AvlTree root)
{
    int i;

    if(root != AVL_EMPTY) {
        for(i = 0; i < 2; i++) {
            avl_sanity_check(root->child[i]);
        }

        assert(root->height == 1 + Max(avl_get_height(root->child[0]), avl_get_height(root->child[1])));
    }
}

/* recompute height of a node */
static void
avl_fix_height(AvlTree t)
{
    assert(t != AVL_EMPTY);

    t->height = 1 + Max(avl_get_height(t->child[0]), avl_get_height(t->child[1]));
}

/* rotate child[d] to root */
/* assumes child[d] exists */
/* Picture:
 *
 *     y            x
 *    / \   <==>   / \
 *   x   C        A   y
 *  / \              / \
 * A   B            B   C
 *
 */
static void
avl_rotate(AvlTree *root, int d)
{
    AvlTree oldRoot;
    AvlTree newRoot;
    AvlTree oldMiddle;

    oldRoot = *root;
    newRoot = oldRoot->child[d];
    oldMiddle = newRoot->child[!d];

    oldRoot->child[d] = oldMiddle;
    newRoot->child[!d] = oldRoot;
    *root = newRoot;

    /* update heights */
    avl_fix_height((*root)->child[!d]);   /* old root */
    avl_fix_height(*root);                /* new root */
}


/* rebalance at node if necessary */
/* also fixes height */
static void
avl_rebalance(AvlTree *t)
{
    int d;

    if(*t != AVL_EMPTY) {
        for(d = 0; d < 2; d++) {
            /* maybe child[d] is now too tall */
            if(avl_get_height((*t)->child[d]) > avl_get_height((*t)->child[!d]) + 1) {
                /* imbalanced! */
                /* how to fix it? */
                /* need to look for taller grandchild of child[d] */
                if(avl_get_height((*t)->child[d]->child[d]) > avl_get_height((*t)->child[d]->child[!d])) {
                    /* same direction grandchild wins, do single rotation */
                    avl_rotate(t, d);
                } else {
                    /* opposite direction grandchild moves up, do double rotation */
                    avl_rotate(&(*t)->child[d], !d);
                    avl_rotate(t, d);
                }

                return;   /* avl_rotate called avl_fix_height */
            }
        }

        /* update height */
        avl_fix_height(*t);
    }
}

/* insert into tree */
/* this may replace root, which is why we pass
 * in a AvlTree * */
AvlTree
avl_insert(AvlTree *t, intptr_t addr, size_t size, bool heap)
{
    /* insertion procedure */
    if(*t == AVL_EMPTY) {
        /* new t */
        *t = pilgrim_malloc(sizeof(AvlNode));
        assert(*t);

        (*t)->child[0] = AVL_EMPTY;
        (*t)->child[1] = AVL_EMPTY;

        (*t)->addr = addr;
        (*t)->size = size;
        (*t)->used = false;
        (*t)->heap = heap;
        (*t)->id_node = NULL;      // id is assigned only when used in MPI calls

        (*t)->height = 1;
        /* done */
        return (*t);
    } else if(addr == (*t)->addr) {
        /* nothing to do */
        return (*t);
    } else {
        /* do the insert in subtree */
        AvlTree new_node = avl_insert(&(*t)->child[addr > (*t)->addr], addr, size, heap);
        avl_rebalance(t);
        return new_node;
    }
}


/* print all elements of the tree in order */
void
avl_print_keys(AvlTree t)
{
    if(t != AVL_EMPTY) {
        avl_print_keys(t->child[0]);
        printf("addr: %ld, id: %d, size: %ld\n", t->addr, t->id_node->id, t->size);
        avl_print_keys(t->child[1]);
    }
}


/* delete and return minimum value in a tree
 * do not free the node, we free it in avl_delete()
 */

AvlTree
avl_delete_min(AvlTree *t)
{
    AvlTree oldroot;
    intptr_t minValue;

    assert(t != AVL_EMPTY);

    if((*t)->child[0] == AVL_EMPTY) {
        /* root is min value */
        oldroot = *t;
        minValue = oldroot->addr;
        *t = oldroot->child[1];
    } else {
        /* min value is in left subtree */
        oldroot = avl_delete_min(&(*t)->child[0]);
    }

    avl_rebalance(t);
    return oldroot;
}

/* delete the given value */
void
avl_delete(AvlTree *t, intptr_t addr)
{
    AvlTree oldroot;

    if(*t == AVL_EMPTY) {
        return;
    } else if((*t)->addr == addr) {
        /* do we have a right child? */
        if((*t)->child[1] != AVL_EMPTY) {
            /* give root min node vlaues in right subtree */
            AvlTree min_node = avl_delete_min(&(*t)->child[1]);
            (*t)->addr = min_node->addr;
            (*t)->size = min_node->size;
            (*t)->id_node = min_node->id_node;
            pilgrim_free(min_node, sizeof(AvlNode));
        } else {
            /* splice out root */
            oldroot = (*t);
            *t = (*t)->child[0];
            pilgrim_free(oldroot, sizeof(AvlNode));
        }
    } else {
        avl_delete(&(*t)->child[addr > (*t)->addr], addr);
    }

    /* rebalance */
    avl_rebalance(t);
}

