#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "pilgrim_mem_hooks.h"
#include "dlmalloc-2.8.6.h"

AvlTree *addr_tree;
static bool hook_installed = false;
int rank;

// The only public available function in .h
void install_hooks(int r, AvlTree *t) {
    hook_installed = true;
    addr_tree = t;
    rank = rank;
}

void remove_hooks() {
    hook_installed = false;
}




/**
 * Wrappers
 */
void* malloc(size_t size) {
    if(!hook_installed)
        return dlmalloc(size);

    void* ptr = dlmalloc(size);

    intptr_t tmp = (intptr_t)ptr;
    avl_insert(addr_tree, (intptr_t)ptr, size);
    return ptr;
}

void* calloc(size_t nitems, size_t size) {
    if(!hook_installed)
        return dlcalloc(nitems, size);

    void *ptr = dlcalloc(nitems, size);

    avl_insert(addr_tree, (intptr_t)ptr, size*nitems);
    return ptr;
}

void* realloc(void *ptr, size_t size) {

    // Before hooks are installed, the *ptr passed-in is returned from
    // our malloc wrapper, which is a stack address. We can not
    // realloc the stack pointer, so instead we pass NULL to real_realloc
    if(!hook_installed)
        return dlrealloc(ptr, size);

    void *new_ptr = dlrealloc(ptr, size);

    if(new_ptr == ptr) {
        AvlTree t = avl_search(*addr_tree, (intptr_t)ptr);
        if(t != AVL_EMPTY) {
            t->size = size;
        }
    } else {
        avl_delete(addr_tree, (intptr_t)ptr);
        avl_insert(addr_tree, (intptr_t)new_ptr, size);
    }
    return new_ptr;
}

void free(void *ptr) {
    // Before hooks are installed, the *ptr passed-in is returned from
    // our malloc wrapper, which is a stack address. We do not need to
    // release it.
    if(!hook_installed) {
        dlfree(ptr);
        return;
    }

    avl_delete(addr_tree, (intptr_t)ptr);
    dlfree(ptr);
}
