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
#include "dlmalloc-2.8.6.h"

CallSignature* read_cst(char *path, int *num_funcs) {
    FILE* f = fopen(path, "rb");

    short func_id;
    int entries, key_len, terminal, rank, duration, interval;
    fread(&entries, sizeof(int), 1, f);
    *num_funcs = entries;

    CallSignature *call_sigs = malloc(sizeof(CallSignature) * entries);

    char buff[512];
    for(int i = 0; i < entries; i++) {

        fread(&terminal, sizeof(int), 1, f);
        fread(&rank, sizeof(int), 1, f);
        fread(&key_len, sizeof(int), 1, f);

        fread(&func_id, sizeof(short), 1, f);
        fread(buff, 1, key_len-sizeof(short), f);

        assert(terminal < entries);
        call_sigs[terminal].func_id = func_id;
        read_record_args(func_id, buff, &(call_sigs[terminal]));
    }


    fclose(f);
    return call_sigs;
}
