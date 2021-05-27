#ifndef _PILGRIM_MEM_HOOKS_H_
#define _PILGRIM_MEM_HOOKS_H_

typedef struct MemPtrAttr_t {
    int id;             // symbolic id
    size_t offset;
    size_t size;
    char type;          // memory location, retrived cudaPointerGetAttributes()
    char device;         // if on gpu, device id of the gpu, retrived cudaPointerGetAttributes()
} MemPtrAttr;

/*
static void * (*real_calloc)(size_t nitems, size_t size);
static void * (*real_malloc)(size_t size);
static void * (*real_valloc)(size_t size);
static void * (*real_pvalloc)(size_t size);
static void * (*real_realloc)(void *ptr, size_t size);
static void   (*real_free)(void *ptr);
*/

void install_mem_hooks();
void uninstall_mem_hooks();
void addr2id(const void *buffer, MemPtrAttr *mem_attr);

#endif
