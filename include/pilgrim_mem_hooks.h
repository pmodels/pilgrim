/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#ifndef _PILGRIM_MEM_HOOKS_H_
#define _PILGRIM_MEM_HOOKS_H_

typedef struct MemPtrAttr_t {
    int id;              // symbolic id
    size_t offset;
    size_t size;
    char type;           // memory location, retrived cudaPointerGetAttributes()
    char device;         // if on gpu, device id of the gpu, retrived cudaPointerGetAttributes()
} MemPtrAttr;


int g_inside_mpi;


void install_mem_hooks();
void uninstall_mem_hooks();
void addr2id(const void *buffer, MemPtrAttr *mem_attr);


static void set_inside_mpi() {
    g_inside_mpi = 1;
}
static void unset_inside_mpi() {
    g_inside_mpi = 0;
}

#endif
