#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include "pilgrim.h"

int rank;
int nprocs;
static int func_counter[400];


void read_global_metadata(char* path, GlobalMetadata *gm) {
    char global_metadata_path[256];
    sprintf(global_metadata_path, "%s/pilgrim.mt", path);
    FILE* fh = fopen(global_metadata_path, "rb");
    fread(gm, sizeof(GlobalMetadata), 1, fh);
    fclose(fh);

    printf("ranks: %d, time resolution: %f\n\n", gm->ranks, gm->time_resolution);
}

void read_local_metadata(char* path, int rank, LocalMetadata *lm) {
    char local_metadata_path[256];
    sprintf(local_metadata_path, "%s/%d.mt", path, rank);
    FILE* fh = fopen(local_metadata_path, "rb");
    fread(lm, sizeof(LocalMetadata), 1, fh);
    fclose(fh);

    printf("rank: %d, tstart: %f, tend: %f, records: %d\n", lm->rank, lm->tstart, lm->tend, lm->records_count);
}


int main(int argc, char** argv) {
    char *path = argv[1];

    printf("Global Metadata\n");
    GlobalMetadata gm;
    read_global_metadata(path, &gm);

    printf("Local Metadata\n");
    for(int i = 0; i < gm.ranks; i++) {
        LocalMetadata lm;
        read_local_metadata(path, i, &lm);
    }

    printf("Function Counter\n");
    for(int i = 0; i < 400; i++) {
        if(func_counter[i] > 0)
            printf("%s: %d\n", func_names[i], func_counter[i]);
    }

    return 0;
}
