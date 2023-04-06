/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pilgrim.h"
#include "pilgrim_timings.h"
#include "pilgrim_reader.h"
#include "uthash.h"


double* read_timings_core(const char* path, GlobalMetadata* gm) {
    if(strcmp(gm->timing_mode, TIMING_MODE_LOSSLESS)==0) {
        FILE* f = fopen(path, "rb");
        fseek(f, 0, SEEK_END);
        long int size = ftell(f);
        fseek(f, 0, SEEK_SET);
        int num_calls = size/sizeof(double);
        double *ts = malloc(sizeof(double)*num_calls);
        fread(ts, sizeof(double), num_calls, f);
        fclose(f);
        return ts;
    } else {
        printf("Not supported for now.");
        return NULL;
    }
}

double* read_tstarts(GlobalMetadata* gm) {
    char path[1024];
    sprintf(path, "%s/intervals.dat", gm->trace_dir);
    return read_timings_core(path, gm);
}

double* read_tends(GlobalMetadata* gm) {
    char path[1024];
    sprintf(path, "%s/durations.dat", gm->trace_dir);
    return read_timings_core(path, gm);
}
