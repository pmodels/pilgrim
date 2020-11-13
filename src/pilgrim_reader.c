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

void print_rule(int rule_head, int* sym, int symbols) {
    printf("rule %d, symbols: %d\n\t-->", rule_head, symbols);
    for(int i = 0; i < symbols; i++)
        printf(" %d", sym[i]);
    printf("\n");
}

void read_grammar(FILE *f) {
    int rules;
    fread(&rules, sizeof(int), 1, f);
    printf("rules: %d\n", rules);

    for(int i = 0; i < rules; i++) {
        int rule_head, symbols, *sym;

        fread(&rule_head, sizeof(int), 1, f);
        fread(&symbols, sizeof(int), 1, f);

        sym = (int*) malloc(sizeof(int) * symbols);
        fread(sym, sizeof(int), symbols, f);
        //print_rule(rule_head, sym, symbols);
        free(sym);
    }
}

void read_grammars(char *path, int nprocs) {
    char grammar_file_path[256];
    sprintf(grammar_file_path, "%s/grammars.dat", path);

    FILE* f = fopen(grammar_file_path, "rb");

    for(int i = 0; i < nprocs; i++)
        read_grammar(f);

    fclose(f);
}

void read_signatures_table(char *directory) {
    bool used[400] = {0};

    char path[256];
    sprintf(path, "%s/funcs.dat", directory);
    FILE* f = fopen(path, "rb");

    short func_id;
    int entries, key_len, terminal, duration, interval;
    fread(&entries, sizeof(int), 1, f);

    char args[100];
    for(int i = 0; i < entries; i++) {
        fread(&terminal, sizeof(int), 1, f);
        fread(&key_len, sizeof(int), 1, f);

        fread(&func_id, sizeof(short), 1, f);
        fread(&duration, sizeof(int), 1, f);
        fread(&interval, sizeof(int), 1, f);

        fread(args, 1, key_len-sizeof(short)-2*sizeof(int), f);

        used[func_id] = 1;
        //printf("terminal id: %d, func: %s, key len: %d\n", terminal, func_names[func_id], key_len);
    }

    for(func_id = 0; func_id < 400; func_id++) {
        if(used[func_id])
            printf("%s\n", func_names[func_id]);
    }

    fclose(f);
}

int main(int argc, char** argv) {
    char *directory = argv[1];

    printf("Global Metadata\n");
    GlobalMetadata gm;
    read_global_metadata(directory, &gm);

    /*
    printf("Local Metadata\n");
    for(int i = 0; i < gm.ranks; i++) {
        LocalMetadata lm;
        read_local_metadata(path, i, &lm);
    }
    */

    read_grammars(directory, gm.ranks);
    read_signatures_table(directory);

    return 0;
}
