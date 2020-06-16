#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include "pilgrim.h"

int rank;
int nprocs;
double elapsed_time;

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


void read_trace_file(char* path, GlobalMetadata gm, LocalMetadata lm) {
    char trace_file_path[256];
    sprintf(trace_file_path, "%s/%d.itf", path, lm.rank);
    FILE* fh = fopen(trace_file_path, "rb");

    Record record;
    int tstart, tend;

    for(int i = 0; i < lm.records_count; i++) {
        fread(&record.status, sizeof(record.status), 1, fh);
        fread(&tstart, sizeof(tstart), 1, fh);
        fread(&tend, sizeof(tend), 1, fh);
        fread(&record.res, sizeof(record.res), 1, fh);
        fread(&record.func_id, sizeof(record.func_id), 1, fh);
        printf("tstart:%d tend:%d res:%d func:%s\n", tstart, tend, record.res, func_names[record.func_id]);

        record.tstart = lm.tstart + gm.time_resolution * tstart;
        record.tend = lm.tstart + gm.time_resolution * tend;
        record.args = read_record_args(fh, record.func_id);
    }

    fclose(fh);
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
        read_trace_file(path, gm, lm);
    }

    return 0;
}
