#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include "pilgrim.h"
#include "uthash.h"
#include "dlmalloc-2.8.6.h"

typedef struct RuleHash_t {
    int rule_id;
    int *rule_body;
    int symbols;        // how many symbols in the rule body
    UT_hash_handle hh;
} RuleHash;

static int rank;
static int nprocs;
static RuleHash* rules_table;


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


// Recursively decode rules
int decode_rule(int* decompressed_symbols, int rule_id, int start_rule_id) {
    int advance = 0;

    RuleHash *rule;
    HASH_FIND_INT(rules_table, &rule_id, rule);

    for(int i = 0; i < rule->symbols; i++) {
        int sym = rule->rule_body[i];

        // Non-terminal, i.e., a rule
        if(sym < start_rule_id) {
            int advanced = decode_rule(decompressed_symbols, sym, start_rule_id);
            decompressed_symbols += advanced;
            advance += advanced;
        }
        // Terminal
        else {
            *decompressed_symbols = sym;
            decompressed_symbols++;
            advance++;
        }
    }

    return advance;
}

void decode_and_write(int rule_id, FILE *f) {

    RuleHash *rule;
    HASH_FIND_INT(rules_table, &rule_id, rule);
    for(int i = 0; i < rule->symbols; i++) {
        int sym = rule->rule_body[i];

        // Non-terminal, i.e., a rule
        if(sym < -1) {
            decode_and_write(sym, f);
        }
        // Terminal
        else {
            fprintf(f, "%d ", sym);
        }
    }

}


void clean_rules_table() {
    RuleHash *current, *tmp;
    HASH_ITER(hh, rules_table, current, tmp) {
        HASH_DEL(rules_table, current);
        free(current->rule_body);
        free(current);
    }
    rules_table = NULL;
}

void read_grammars(char *path, int total_ranks) {
    char grammar_file_path[256];
    sprintf(grammar_file_path, "%s/grammars.dat", path);

    FILE* f = fopen(grammar_file_path, "rb");

    int start_rule_id, rules;
    size_t before, after;

    fread(&start_rule_id, sizeof(int), 1, f);
    fread(&before, sizeof(size_t), 1, f);
    fread(&after, sizeof(size_t), 1, f);
    fread(&rules, sizeof(int), 1, f);

    printf("Start_rule_id: %d, Before copmression: %ld, After compression: %ld, Rules: %d\n", start_rule_id, before, after, rules);

    for(int i = 0; i < rules; i++) {
        RuleHash *rule = malloc(sizeof(RuleHash));

        fread(&(rule->rule_id), sizeof(int), 1, f);
        fread(&(rule->symbols), sizeof(int), 1, f);

        rule->rule_body = (int*) malloc(sizeof(int) * rule->symbols);
        fread(rule->rule_body, sizeof(int), rule->symbols, f);

        print_rule(rule->rule_id, rule->rule_body, rule->symbols);
        HASH_ADD_INT(rules_table, rule_id, rule);
    }

    int *decompressed  = malloc(sizeof(int) * before);
    decode_rule(decompressed, start_rule_id, start_rule_id);
    clean_rules_table();

    int pos = 0;
    for(int rank = 0; rank < total_ranks; rank++) {
        int rules = decompressed[pos++];

        for(int j = 0; j < rules; j++) {
            RuleHash *rule = malloc(sizeof(RuleHash));
            rule->rule_id = decompressed[pos++];
            rule->symbols = decompressed[pos++];
            rule->rule_body = malloc(sizeof(int) * rule->symbols);
            memcpy(rule->rule_body, &(decompressed[pos]), sizeof(int)*rule->symbols);
            pos += (rule->symbols);
            HASH_ADD_INT(rules_table, rule_id, rule);
            printf("rank: %d ,add rule: %d, symbols: %d\n", rank, rule->rule_id, rule->symbols);
        }

        // write out to this rank
        char path[256];
        sprintf(path, "./log-%d.txt", rank);
        FILE *fout = fopen(path, "w");
        decode_and_write(-1, fout);
        fclose(fout);

        clean_rules_table();
    }

    free(decompressed);
    fclose(f);
}

void read_signatures_table(char *directory) {
    bool used[400] = {0};

    char path[256];
    sprintf(path, "%s/funcs.dat", directory);
    FILE* f = fopen(path, "rb");

    short func_id;
    int entries, key_len, terminal, duration, interval, nargs;
    fread(&entries, sizeof(int), 1, f);

    char buff[100];
    for(int i = 0; i < entries; i++) {

        fread(&terminal, sizeof(int), 1, f);
        fread(&key_len, sizeof(int), 1, f);

        fread(&func_id, sizeof(short), 1, f);
        fread(buff, 1, key_len-sizeof(short), f);

        used[func_id] = 1;
        void** args = read_record_args(func_id, buff, &nargs);
        printf("terminal id: %d, func: %s, key len: %d, nargs: %d\n", terminal, func_names[func_id], key_len, nargs);
        for(int j = 0; j < nargs; j++)
            free(args[j]);
        free(args);
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

    read_signatures_table(directory);
    read_grammars(directory, gm.ranks);

    return 0;
}
