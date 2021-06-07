/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilgrim.h"
#include "pilgrim_reader.h"

void read_metadata(char* path, GlobalMetadata *gm) {
    FILE* fh = fopen(path, "rb");
    fread(gm, sizeof(GlobalMetadata), 1, fh);
    fclose(fh);

    printf("Total procs: %d, Time resolution: %.1fus\n\n", gm->ranks, gm->time_resolution*1000000);
}
