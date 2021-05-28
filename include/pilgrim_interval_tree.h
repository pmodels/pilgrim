/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

//#include <stdio.h>
//#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct AddrIdNode_t {
    int id;
    struct AddrIdNode_t *prev;
    struct AddrIdNode_t *next;
} AddrIdNode;


typedef struct IntervalNode_t {
    intptr_t start;
    size_t size;
    bool heap;

    AddrIdNode *id_node;

	struct IntervalNode_t *left, *right;
} IntervalNode;


IntervalNode* itree_insert(IntervalNode* node, intptr_t start, size_t end, bool heap);

void itree_destroy(IntervalNode* node);

IntervalNode* itree_search(IntervalNode* root, intptr_t start);

IntervalNode* itree_delete(IntervalNode* root, intptr_t start);
