/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilgrim.h"
#include "pilgrim_reader.h"

GlobalMetadata* read_metadata(const char* trace_dir) {
    char path[1024];
    sprintf(path, "%s/pilgrim.mt", trace_dir);


    GlobalMetadata* gm = malloc(sizeof(GlobalMetadata));

    FILE* fh = fopen(path, "rb");
    fread(gm, sizeof(GlobalMetadata), 1, fh);
    fclose(fh);

    gm->trace_dir = strdup(trace_dir);
    printf("Total procs: %d, Time resolution: %.1fus\n\n", gm->ranks, gm->time_resolution*1000000);

    return gm;
}

void free_metadata(GlobalMetadata* gm) {
    free(gm->trace_dir);
    free(gm);
}
