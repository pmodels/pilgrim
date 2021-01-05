#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "pilgrim_mem_hooks.h"
#include "pilgrim_interval_tree.h"
#include "dlmalloc-2.8.6.h"
#include "utlist.h"

IntervalNode *addr_tree;
AddrIdNode *addr_id_list;               // free list of addr ids
static bool hook_installed = false;
static int allocated_addr_id = 0;


// Three public available function in .h
void install_mem_hooks() {
    hook_installed = true;
    addr_tree = NULL;
    addr_id_list = NULL;
}

void uninstall_mem_hooks() {
    hook_installed = false;
    itree_destroy(addr_tree);

    AddrIdNode *node, *tmp;
    DL_FOREACH_SAFE(addr_id_list, node, tmp) {
        DL_DELETE(addr_id_list, node);
        dlfree(node);
    }
}

// Symbolic representation of memory addresses
int* addr2id(const void* buffer) {
    return &allocated_addr_id;
    if(buffer == NULL)
        return &allocated_addr_id;

    //return &allocated_addr_id;
    IntervalNode *itree_node = itree_search(addr_tree, (intptr_t) buffer);
    if(itree_node == NULL) {
        // Not found in addr_tree suggests that this buffer is not dynamically allocated
        // Maybe a stack buffer so we don't know excatly the size
        // We assume it as a 1 byte memory area.
        //addr_tree = itree_insert(addr_tree, (intptr_t)buffer, 1, false);
        itree_node = itree_search(addr_tree, (intptr_t)buffer);
    }

    // Two possible cases:
    // 1. New created itree_node
    // 2. Already created but never used by MPI call
    // In both cases, need to assign it a addr id node.
    return &allocated_addr_id;
    /*
    if(itree_node->id_node == NULL) {
        if(addr_id_list == NULL) {
            // free id list is empty? create one
            itree_node->id_node = (AddrIdNode*) dlmalloc(sizeof(AddrIdNode));
            itree_node->id_node->id = allocated_addr_id++;
        } else {
            // free id list is not empty, get the first one and remove it from list
            itree_node->id_node = addr_id_list;
            DL_DELETE(addr_id_list, itree_node->id_node);
        }
    }

    return &(itree_node->id_node->id);
    */
}

/**
 * Below are Wrappers for intercepting memory management calls.
 */
void* malloc(size_t size) {
    if(!hook_installed)
        return dlmalloc(size);

    void* ptr = dlmalloc(size);
    addr_tree = itree_insert(addr_tree, (intptr_t)ptr, size, true);
    return ptr;
}

void* calloc(size_t nitems, size_t size) {
    if(!hook_installed)
        return dlcalloc(nitems, size);

    void *ptr = dlcalloc(nitems, size);

    addr_tree = itree_insert(addr_tree, (intptr_t)ptr, size*nitems, true);
    return ptr;
}

void* realloc(void *ptr, size_t size) {
    if(!hook_installed)
        return dlrealloc(ptr, size);

    void *new_ptr = dlrealloc(ptr, size);

    if(new_ptr == ptr) {
        IntervalNode *t = itree_search(addr_tree, (intptr_t)ptr);
        if(t != NULL)
            t->size = size;
    } else {
        addr_tree = itree_delete(addr_tree, (intptr_t)ptr);
        addr_tree = itree_insert(addr_tree, (intptr_t)new_ptr, size, true);
    }
    return new_ptr;
}

void free(void *ptr) {
    if(!hook_installed) {
        dlfree(ptr);
        return;
    }

    IntervalNode *itree_node = itree_search(addr_tree, (intptr_t)ptr);

    if(itree_node == NULL) {
        if(ptr != NULL) {
            // TODO: potential memory leak. why
            //printf("Huh?? at free() wrapper?????? %p\n", ptr);
        }
    } else {
        if(itree_node->id_node)
            DL_APPEND(addr_id_list, itree_node->id_node);
        bool heap = itree_node->heap && (itree_node->start == (intptr_t)ptr);
        addr_tree = itree_delete(addr_tree, (intptr_t)ptr);
        if(heap)
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
