#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "pilgrim_utils.h"
#include "pilgrim_mem_hooks.h"
#include "pilgrim_addr_avl.h"
#include "dlmalloc-2.8.6.h"
#include "uthash.h"
#include "utlist.h"

typedef struct PointerEntry_t {
    void *key;
    UT_hash_handle hh;
} PointerEntry;
PointerEntry *pointers_table;

AvlTree addr_tree;
AddrIdNode *addr_id_list;               // free list of addr ids
static bool hook_installed = false;
static int allocated_addr_id = 0;


void add_pointer_entry(void *ptr) {
    PointerEntry *find;
    HASH_FIND_PTR(pointers_table, &ptr, find);
    if(find == NULL) {
        find = pilgrim_malloc(sizeof(PointerEntry));
        find->key = ptr;
        HASH_ADD_PTR(pointers_table, key, find);
    }
}


// Three public available function in .h
void install_mem_hooks() {
    hook_installed = true;
    addr_tree = NULL;
    addr_id_list = NULL;
    pointers_table = NULL;
}

void uninstall_mem_hooks() {
    hook_installed = false;
    avl_destroy(addr_tree);

    AddrIdNode *node, *tmp;
    DL_FOREACH_SAFE(addr_id_list, node, tmp) {
        DL_DELETE(addr_id_list, node);
        pilgrim_free(node, sizeof(AddrIdNode));
    }

    PointerEntry *entry, *tmp2;
    HASH_ITER(hh, pointers_table, entry, tmp2) {
        HASH_DEL(pointers_table, entry);
        pilgrim_free(entry, sizeof(PointerEntry));
    }
}

// Symbolic representation of memory addresses
int* addr2id(const void* buffer) {
    return &allocated_addr_id;
    AvlTree avl_node = avl_search(addr_tree, (intptr_t) buffer);
    if(avl_node == AVL_EMPTY) {
        // Not found in addr_tree suggests that this buffer is not dynamically allocated
        // Maybe a stack buffer so we don't know excatly the size
        // We assume it as a 1 byte memory area.
        avl_node = avl_insert(&addr_tree, (intptr_t)buffer, 1, false);
    }

    // Two possible cases:
    // 1. New created avl_node
    // 2. Already created but never used by MPI call
    // In both cases, need to assign it a addr id node.
    if(avl_node->id_node == NULL) {
        if(addr_id_list == NULL) {
            // free id list is empty? create one
            avl_node->id_node = (AddrIdNode*) pilgrim_malloc(sizeof(AddrIdNode));
            avl_node->id_node->id = allocated_addr_id++;
        } else {
            // free id list is not empty, get the first one and remove it from list
            avl_node->id_node = addr_id_list;
            DL_DELETE(addr_id_list, avl_node->id_node);
        }
    }

    return &(avl_node->id_node->id);
}

/**
 * Below are Wrappers for intercepting memory management calls.
 */
/*
void* malloc(size_t size) {
    if(!hook_installed)
        return dlmalloc(size);

    void* ptr = dlmalloc(size);

    avl_insert(&addr_tree, (intptr_t)ptr, size, true);

    add_pointer_entry(ptr);
    return ptr;
}

void* calloc(size_t nitems, size_t size) {
    if(!hook_installed)
        return dlcalloc(nitems, size);

    void *ptr = dlcalloc(nitems, size);

    avl_insert(&addr_tree, (intptr_t)ptr, size*nitems, true);

    add_pointer_entry(ptr);
    return ptr;
}

void* realloc(void *ptr, size_t size) {

    if(!hook_installed)
        return dlrealloc(ptr, size);

    void *new_ptr = dlrealloc(ptr, size);

    if(new_ptr == ptr) {
        AvlTree t = avl_search(addr_tree, (intptr_t)ptr);
        if(t != AVL_EMPTY) {
            t->size = size;
        }
    } else {
        avl_delete(&addr_tree, (intptr_t)ptr);
        avl_insert(&addr_tree, (intptr_t)new_ptr, size, true);
        add_pointer_entry(new_ptr);
    }
    return new_ptr;
}

void free(void *ptr) {
    if(!hook_installed) {
        dlfree(ptr);
        return;
    }

    AvlTree avl_node = avl_search(addr_tree, (intptr_t)ptr);

    if(AVL_EMPTY == avl_node) {
        if(ptr != NULL) {
            // TODO: potential memory leak. why
            //printf("Huh?? at free() wrapper?????? %p\n", ptr);
        }
    } else {
        if(avl_node->id_node)
            DL_APPEND(addr_id_list, avl_node->id_node);
        //bool heap = avl_node->heap && (avl_node->addr==(intptr_t)ptr);
        avl_delete(&addr_tree, (intptr_t)ptr);
        //if(heap)
        //    dlfree(ptr);
    }

    PointerEntry *d = NULL;
    HASH_FIND_PTR(pointers_table, &ptr, d);
    if(d) {
        HASH_DEL(pointers_table, d);
        pilgrim_free(d, sizeof(PointerEntry));
        dlfree(ptr);
    }
}

int posix_memalign(void **memptr, size_t alignment, size_t size) {
    return dlposix_memalign(memptr, alignment, size);
}

void *valloc(size_t size) {
    return dlvalloc(size);
}

void *memalign(size_t alignment, size_t size) {
    return dlmemalign(alignment, size);
}

void *pvalloc(size_t size) {
    return dlpvalloc(size);
}
*/
