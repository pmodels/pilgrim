#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "uthash.h"
#include "pilgrim_mem_hooks.h"
#include "dlmalloc-2.8.6.h"

static bool hook_installed = false;

// The only public available function in .h
void install_hooks() {
    real_malloc  = dlsym(RTLD_NEXT, "malloc");
    real_calloc  = dlsym(RTLD_NEXT, "calloc");
    real_valloc  = dlsym(RTLD_NEXT, "valloc");
    real_pvalloc = dlsym(RTLD_NEXT, "pvalloc");
    real_realloc = dlsym(RTLD_NEXT, "realloc");
    real_free    = dlsym(RTLD_NEXT, "free");
    hook_installed = true;
}
void remove_hooks() {
    hook_installed = false;
}


// Entry in uthash
typedef struct AddrHash_t {
    void *key;
    size_t size;
    int id;
    UT_hash_handle hh;
} AddrHash;

static int current_addr_id = 0;
static AddrHash *addr_table = NULL;


void addr_put(void *buffer, size_t size) {
    void *key = malloc(sizeof(void*));
    memcpy(key, &buffer, sizeof(void*));

    AddrHash *entry;
    HASH_FIND(hh, addr_table, key, sizeof(void*), entry);
    if(entry) {                         // Found
        dlfree(key);
    } else {                            // Not exist, add to hash table
        entry = (AddrHash*) dlmalloc(sizeof(AddrHash));
        entry->key = key;
        entry->size = size;
        entry->id = current_addr_id++;
        HASH_ADD_KEYPTR(hh, addr_table, entry->key, sizeof(void*), entry);
    }
}

AddrHash* addr_get(void *buffer) {
    if(!buffer)
        return NULL;
    void *key = dlmalloc(sizeof(void*));
    memcpy(key, &buffer, sizeof(void*));

    AddrHash *entry;
    HASH_FIND(hh, addr_table, key, sizeof(void*), entry);
    if(entry)
        return entry;
    return NULL;
}


/**
 * Wrappers
 */
void* malloc(size_t size) {
    if(!hook_installed)
        return dlmalloc(size);

    void* ptr = dlmalloc(size);
    fprintf(stderr, "malloc %p, %ld\n", ptr, size);
    return ptr;
}

void* calloc(size_t nitems, size_t size) {
    if(!hook_installed)
        return dlcalloc(nitems, size);

    void *ptr = dlcalloc(nitems, size);
    fprintf(stderr, "calloc %ld %ld\n", nitems, size);
    return ptr;
}

void* realloc(void *ptr, size_t size) {

    // Before hooks are installed, the *ptr passed-in is returned from
    // our malloc wrapper, which is a stack address. We can not
    // realloc the stack pointer, so instead we pass NULL to real_realloc
    if(!hook_installed)
        return dlrealloc(ptr, size);

    void *new_ptr = dlrealloc(ptr, size);

    // The new memory address returnedy by realloc
    // maybe different from the given one
    if(new_ptr == ptr) {

    } else {

    }

    fprintf(stderr, "realloc %p, %ld\n", ptr, size);
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
    dlfree(ptr);
}
