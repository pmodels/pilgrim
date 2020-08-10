#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "pilgrim_mem_hooks.h"
#include "pilgrim_addr_avl.h"
#include "dlmalloc-2.8.6.h"

static AvlTree addr_tree = AVL_EMPTY;
static bool hook_installed = false;

// The only public available function in .h
void install_hooks() {
    hook_installed = true;
}

void remove_hooks() {
    hook_installed = false;
    avl_destroy(addr_tree);
}




/**
 * Wrappers
 */
void* malloc(size_t size) {
    if(!hook_installed)
        return dlmalloc(size);

    void* ptr = dlmalloc(size);
    fprintf(stderr, "malloc %p, %ld\n", ptr, size);

    avl_insert(&addr_tree, (intptr_t)ptr, size);
    return ptr;
}

void* calloc(size_t nitems, size_t size) {
    if(!hook_installed)
        return dlcalloc(nitems, size);

    void *ptr = dlcalloc(nitems, size);
    fprintf(stderr, "calloc %ld %ld\n", nitems, size);

    avl_insert(&addr_tree, (intptr_t)ptr, size*nitems);
    return ptr;
}

void* realloc(void *ptr, size_t size) {

    // Before hooks are installed, the *ptr passed-in is returned from
    // our malloc wrapper, which is a stack address. We can not
    // realloc the stack pointer, so instead we pass NULL to real_realloc
    if(!hook_installed)
        return dlrealloc(ptr, size);

    void *new_ptr = dlrealloc(ptr, size);
    fprintf(stderr, "realloc %p, %ld\n", ptr, size);

    // The new memory address returnedy by realloc
    // maybe different from the given one
    avl_delete(&addr_tree, (intptr_t)ptr);
    avl_insert(&addr_tree, (intptr_t)new_ptr, size);
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
    fprintf(stderr, "free %p\n", ptr);

    avl_delete(&addr_tree, (intptr_t)ptr);
    dlfree(ptr);
}
