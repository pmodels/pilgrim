#ifndef _PILGRIM_MEM_HOOKS_H_
#define _PILGRIM_MEM_HOOKS_H_
#include "pilgrim_addr_avl.h"

static void * (*real_calloc)(size_t nitems, size_t size);
static void * (*real_malloc)(size_t size);
static void * (*real_valloc)(size_t size);
static void * (*real_pvalloc)(size_t size);
static void * (*real_realloc)(void *ptr, size_t size);
static void   (*real_free)(void *ptr);

void install_hooks(int rank, AvlTree *t);
void remove_hooks();

#endif
