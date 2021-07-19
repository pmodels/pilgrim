/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#ifndef _PILGRIM_ADDR_AVL_H
#define _PILGRIM_ADDR_AVL_H
#include <stdbool.h>

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

    bool used;                   // this memory buffer is used by user's MPI call
    bool heap;
    AddrIdNode* id_node;         // symbolic id to represent this memory buffer

    int height;
} AvlNode;

typedef struct AvlNode_t *AvlTree;

/* empty avl tree is just a null pointer */
#define AVL_EMPTY (0)


/*
 *  =============================================
 *  The following three functions:
 *  avl_search, avl_insert, avl_delete
 *  may be invoked concurrently (just like malloc/free)
 *  So, they need to be thread-safe, otherwise
 *  Pilgrim may crash occasionally.
 *  ============================================
 */


/*
 * Search for an allocated memory buffer
 */
AvlTree avl_search(AvlTree t, intptr_t addr);

/*
 * Insert a new memory buffer when allocated/reallocated
 * bool heap: indicate if this memory buffer is allocated on heap
 */
AvlTree avl_insert(AvlTree *t, intptr_t addr, size_t size, bool heap);

/*
 * Delete a memory buffer when freed
 */
void avl_delete(AvlTree *t, intptr_t addr);



void avl_destroy(AvlTree t);

/* print all keys of the tree in order */
void avl_print_keys(AvlTree t);

/* run sanity checks on tree (for debugging) */
/* assert will fail if heights are wrong */
void avl_sanity_check(AvlTree t);

/* return the height of a tree */
int avl_get_height(AvlTree t);

/* delete and return minimum value in a tree */
AvlTree avl_delete_min(AvlTree *t);

#endif
