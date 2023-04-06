/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "pilgrim.h"
#include "pilgrim_timings.h"
#include "pilgrim_reader.h"

int main(int argc, char** argv) {

    // 0. Read metadata
    GlobalMetadata *gm = read_metadata(argv[1]);

    // 1. Read CST and CFG
    CST *cst = read_cst(gm);
    CFG* cfg = read_cfg(gm);

    // 2. Read timestamps, tstarts and tends are array of timestamps
    // in rank order. e.g., tstarts[0...n] are tstarts of rank 0
    double *tstarts = read_tstarts(gm);
    double *tends   = read_tends(gm);
    double *p_tstarts = tstarts;
    double *p_tends   = tends;

    // 3. Write to text files
    char textfile_dir[256], textfile_path[256];
    sprintf(textfile_dir, "%s/_text", argv[1]);
    mkdir(textfile_dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    for(int rank = 0; rank < gm->ranks; rank++) {
        int ugi = cfg->grammar_ids[rank];

        int total_calls = 0;
        for(int i=0; i<cfg->num_symbols[ugi]; i+=2)
            total_calls += cfg->unique_grammars[ugi][i+1];
        printf("Rank %d, total number of calls: %d\n", rank, total_calls);

        sprintf(textfile_path, "%s/%d.txt", textfile_dir, rank);
        FILE* f = fopen(textfile_path, "w");
        for(int i = 0; i < cfg->num_symbols[ugi]; i+=2) {

            int sym = cfg->unique_grammars[ugi][i];
            int exp = cfg->unique_grammars[ugi][i+1];
            CallSignature *cs = &(cst->cs_list[sym]);
            for(int j = 0; j < exp; j++) {
                if(strcmp(gm->timing_mode, TIMING_MODE_LOSSLESS)==0)
                    fprintf(f, "%f %f ", p_tstarts[i/2], p_tends[i/2]);
                fprintf(f, "%s()\n", func_names[cs->func_id]);
            }
        }
        fclose(f);

        p_tstarts += total_calls;
        p_tends   += total_calls;
    }

    free_metadata(gm);
    free_cst(cst);
    free_cfg(cfg);
    free(tstarts);
    free(tends);

    return 0;
}
