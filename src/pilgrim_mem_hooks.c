/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include "pilgrim.h"
#include "pilgrim_utils.h"
#include "pilgrim_mem_hooks.h"
#include "pilgrim_addr_avl.h"
#include "dlmalloc-2.8.6.h"
#include "uthash.h"
#include "utlist.h"

#ifdef CUDA_POINTERS
#include <cuda.h>
#include <cuda_runtime.h>
#endif

AvlTree cpu_addr_tree;
AvlTree gpu_addr_tree;

AddrIdNode *addr_id_list;               // free list of addr ids
static bool hook_installed = false;
static int allocated_addr_id = 0;

static int num_malloc = 0;
static int num_used_malloc = 0;
static int num_free = 0;
static int num_malloc_by_mpi = 0;


pthread_mutex_t avl_lock = PTHREAD_MUTEX_INITIALIZER;


// Three public available function in .h
void install_mem_hooks() {
    hook_installed = true;
    cpu_addr_tree = NULL;
    gpu_addr_tree = NULL;
    addr_id_list = NULL;
}

void uninstall_mem_hooks() {
    hook_installed = false;
    avl_destroy(cpu_addr_tree);
    avl_destroy(gpu_addr_tree);

    AddrIdNode *node, *tmp;
    DL_FOREACH_SAFE(addr_id_list, node, tmp) {
        DL_DELETE(addr_id_list, node);
        pilgrim_free(node, sizeof(AddrIdNode));
    }

    /* comment out the print out
    int total_malloc, total_free, total_malloc_by_mpi, total_malloc_used;
    PMPI_Reduce(&num_malloc, &total_malloc, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    PMPI_Reduce(&num_free, &total_free, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    PMPI_Reduce(&num_malloc_by_mpi, &total_malloc_by_mpi, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    PMPI_Reduce(&num_used_malloc, &total_malloc_used, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    int rank;
    PMPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if(rank == 0)
        printf("num malloc: %d, num free: %d, num malloc by mpi: %d, num used malloc: %d\n",
                total_malloc, total_free, total_malloc_by_mpi, total_malloc_used);
    */
}

// Symbolic representation of memory addresses
void addr2id(const void* buffer, MemPtrAttr *mem_attr) {
    memset(mem_attr, 0, sizeof(MemPtrAttr)); // in case the padding area has random content
    mem_attr->id = 0;
    mem_attr->offset = 0;
    mem_attr->size = 0;
    mem_attr->type = 0;
    mem_attr->device = -1;

// Users do not want to track memory pointers
#ifndef MEMORY_POINTERS
    return;
#endif
    if(buffer == NULL) return;

    AvlTree avl_node;

#ifdef CUDA_POINTERS
    struct cudaPointerAttributes attr;
    cudaPointerGetAttributes(&attr, buffer);
    mem_attr->type = attr.memoryType;
    mem_attr->device = attr.device;

    pthread_mutex_lock(&avl_lock);
    if(mem_attr->type == 0)      // unregistered memory, which is allocated using malloc()
        avl_node = avl_search(cpu_addr_tree, (intptr_t) buffer);
    else
        avl_node = avl_search(gpu_addr_tree, (intptr_t) buffer);
#else
    avl_node = avl_search(cpu_addr_tree, (intptr_t) buffer);
#endif

    if(avl_node == AVL_EMPTY) {
        // Not found in addr_tree indicates that this buffer is not dynamically allocated
        // Maybe a stack buffer so we don't know excatly the size
        // We assume it is 1 byte memory area.
        avl_node = avl_insert(&cpu_addr_tree, (intptr_t)buffer, 1, false);
    } else {
        // First use of this memory buffer
        if(!avl_node->used && avl_node->heap)
            num_used_malloc++;
    }
    avl_node->used = true;

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

    mem_attr->id = avl_node->id_node->id;
    mem_attr->offset = ((intptr_t)buffer) - avl_node->addr;
    mem_attr->size = avl_node->size;
    if(!avl_node->heap) mem_attr->size = 0;   // use size = 0 to tell the post-processing that this is a stack var
    pthread_mutex_unlock(&avl_lock);
}

// Thread safe insert/delete from addr tree
void safe_insert_addr(AvlTree *addr_tree, void* ptr, size_t size) {
    pthread_mutex_lock(&avl_lock);
    num_malloc++;
    if(g_inside_mpi)
        num_malloc_by_mpi++;
    avl_insert(addr_tree, (intptr_t)ptr, size, true);
    pthread_mutex_unlock(&avl_lock);
}

void safe_delete_addr(AvlTree *addr_tree, void* ptr) {
    pthread_mutex_lock(&avl_lock);
    AvlTree avl_node = avl_search(*addr_tree, (intptr_t)ptr);
    num_free++;

    if(AVL_EMPTY == avl_node) {
        if(ptr != NULL) {
            // TODO: potential memory leak. why
        }
    } else {
        /* ------Experimental code below--------- */
        // Treat free() like a MPI call so we keep
        // a record for it in order to place it
        // during proxy app generation.
        if(addr_tree==&cpu_addr_tree && avl_node->heap && avl_node->used) {
            MemPtrAttr attr;
            addr2id(ptr, &attr);

            int arg_sizes[1] = {sizeof(MemPtrAttr)};
            Record record = {
                .tstart = 0,
                .tend = 0,
                .res = 0,
                .func_id = ID_free,
                .arg_count = 1,
                .arg_sizes = arg_sizes,
            };
            record.args = (void**) dlmalloc(sizeof(void*) * 1);
            record.args[0] = &attr;
            write_record(record);
            dlfree(record.args);
        }
        /* ------Experimental code above--------- */

        if(avl_node->id_node)
            DL_APPEND(addr_id_list, avl_node->id_node);
        bool heap = avl_node->heap && (avl_node->addr==(intptr_t)ptr);
        avl_delete(addr_tree, (intptr_t)ptr);
        if(heap)
            dlfree(ptr);
    }
    pthread_mutex_unlock(&avl_lock);
}


/**
 * Below are Wrappers for intercepting memory management calls.
 */
#ifdef MEMORY_POINTERS
void* malloc(size_t size) {
    if(!hook_installed || g_inside_mpi)
        return dlmalloc(size);

    void* ptr = dlmalloc(size);
    safe_insert_addr(&cpu_addr_tree, ptr, size);
    return ptr;
}

void* calloc(size_t nitems, size_t size) {
    if(!hook_installed || g_inside_mpi)
        return dlcalloc(nitems, size);

    void *ptr = dlcalloc(nitems, size);
    safe_insert_addr(&cpu_addr_tree, ptr, size*nitems);
    return ptr;
}

void* realloc(void *ptr, size_t size) {
    if(!hook_installed || g_inside_mpi)
        return dlrealloc(ptr, size);

    void *new_ptr = dlrealloc(ptr, size);

    pthread_mutex_lock(&avl_lock);
    if(new_ptr == ptr) {
        AvlTree t = avl_search(cpu_addr_tree, (intptr_t)ptr);
        if(t != AVL_EMPTY) {
            t->size = size;
        }
    } else {
        avl_delete(&cpu_addr_tree, (intptr_t)ptr);
        avl_insert(&cpu_addr_tree, (intptr_t)new_ptr, size, true);
    }
    pthread_mutex_unlock(&avl_lock);

    return new_ptr;
}

// Note that do not use printf() inside this funciton
// as printf itself may allocate memory
void free(void *ptr) {
    if(!hook_installed || g_inside_mpi) {
        dlfree(ptr);
        return;
    }
    safe_delete_addr(&cpu_addr_tree, ptr);
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

struct mallinfo mallinfo(void) {
    return dlmallinfo();
}

int malloc_trim(size_t pad) {
    return dlmalloc_trim(pad);
}

int mallopt(int param, int value) {
    return dlmallopt(param, value);
}

// ----------------------------------------------------------
// Trap CUDA memory operations
// ----------------------------------------------------------
#ifdef CUDA_POINTERS

#define MAP_OR_FAIL(func)                                                   \
    if (!(__real_##func)) {                                                 \
        __real_##func = dlsym(RTLD_NEXT, #func);                            \
        if (!(__real_##func)) {                                             \
            printf("Pilgrim failed to map symbol: %s\n", #func);            \
        }                                                                   \
    }
#define PILGRIM_FORWARD_DECL(ret, name, args) ret (*__real_##name) args;
#define PILGRIM_REAL_CALL(func) __real_##func

PILGRIM_FORWARD_DECL(cudaError_t, cudaMalloc, (void** devPtr, size_t size))
PILGRIM_FORWARD_DECL(cudaError_t, cudaHostAlloc, (void** ptr, size_t size, unsigned int flags))
PILGRIM_FORWARD_DECL(cudaError_t, cudaMallocHost, (void** ptr, size_t size))
PILGRIM_FORWARD_DECL(cudaError_t, cudaMallocManaged, (void** devPtr, size_t size, unsigned int flags))
PILGRIM_FORWARD_DECL(cudaError_t, cudaMallocPitch, (void** devPtr, size_t* pitch, size_t width, size_t height))
PILGRIM_FORWARD_DECL(cudaError_t, cudaFree, (void* devPtr))

cudaError_t cudaMalloc(void** devPtr, size_t size) {
    MAP_OR_FAIL(cudaMalloc);
    if(!hook_installed)
        return PILGRIM_REAL_CALL(cudaMalloc)(devPtr, size);

    cudaError_t err = PILGRIM_REAL_CALL(cudaMalloc)(devPtr, size);
    safe_insert_addr(&gpu_addr_tree, devPtr, size);
    return err;
}
cudaError_t cudaHostAlloc(void** ptr, size_t size, unsigned int flags) {
    MAP_OR_FAIL(cudaHostAlloc);
    if(!hook_installed)
        return PILGRIM_REAL_CALL(cudaHostAlloc)(ptr, size, flags);

    cudaError_t err = PILGRIM_REAL_CALL(cudaHostAlloc)(ptr, size, flags);
    safe_insert_addr(&cpu_addr_tree, ptr, size);
    return err;
}
cudaError_t cudaMallocHost(void** ptr, size_t size) {
    MAP_OR_FAIL(cudaMallocHost);
    if(!hook_installed)
        return PILGRIM_REAL_CALL(cudaMallocHost)(ptr, size);

    cudaError_t err = PILGRIM_REAL_CALL(cudaMallocHost)(ptr, size);
    safe_insert_addr(&cpu_addr_tree, ptr, size);
    return err;
}
cudaError_t cudaMallocManaged( void** devPtr, size_t size, unsigned int flags) {
    MAP_OR_FAIL(cudaMallocManaged);
    if(!hook_installed)
        return PILGRIM_REAL_CALL(cudaMallocManaged)(devPtr, size, flags);

    cudaError_t err = PILGRIM_REAL_CALL(cudaMallocManaged)(devPtr, size, flags);
    safe_insert_addr(&gpu_addr_tree, devPtr, size);
    return err;
}
cudaError_t cudaMallocPitch(void** devPtr, size_t* pitch, size_t width, size_t height) {
    MAP_OR_FAIL(cudaMallocPitch);
    if(!hook_installed)
        return PILGRIM_REAL_CALL(cudaMallocPitch)(devPtr, pitch, width, height);

    cudaError_t err = PILGRIM_REAL_CALL(cudaMallocPitch)(devPtr, pitch, width, height);
    safe_insert_addr(&gpu_addr_tree, devPtr, (*pitch)*height);
    return err;
}

cudaError_t cudaFree(void* devPtr) {
    MAP_OR_FAIL(cudaFree);
    if(!hook_installed)
        return PILGRIM_REAL_CALL(cudaFree)(devPtr);

    safe_delete_addr(&gpu_addr_tree, devPtr);
    return PILGRIM_REAL_CALL(cudaFree)(devPtr);
}

#endif      // CUDA_POINTERS
#endif      // MEMORY_POINTERS
