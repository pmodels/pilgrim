/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pilgrim.h"
#include "pilgrim_reader.h"
#include "uthash.h"

#define BUF_LEN (20*1024)


static char buff[BUF_LEN];

CST* read_cst(GlobalMetadata* gm) {
    char path[1024];
    sprintf(path, "%s/funcs.dat", gm->trace_dir);
    FILE* f = fopen(path, "rb");

    short func_id;
    unsigned count;
    int tid, entries, key_len, terminal, rank, duration, interval;
    fread(&entries, sizeof(int), 1, f);

    CST *cst = malloc(sizeof(CST));
    cst->num_css = entries;
    cst->cs_list = malloc(sizeof(CallSignature) * entries);

    for(int i = 0; i < entries; i++) {
        fread(&terminal, sizeof(int), 1, f);
        fread(&rank, sizeof(int), 1, f);
        fread(&key_len, sizeof(int), 1, f);
        assert(key_len < BUF_LEN);
        fread(&count, sizeof(unsigned), 1, f);

        fread(&func_id, sizeof(short), 1, f);
        fread(&tid, sizeof(int), 1, f);
        fread(buff, 1, key_len-sizeof(short)-sizeof(int), f);
        assert(func_id >= 0);

        assert(terminal < entries);
        cst->cs_list[terminal].func_id = func_id;
        read_record_args(func_id, buff, &(cst->cs_list[terminal]));
    }

    fclose(f);
    return cst;
}

void free_cst(CST* cst) {
    assert(cst);
    free(cst);
}
