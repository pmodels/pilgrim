#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "pilgrim.h"
#include "pilgrim_reader.h"
#include "pilgrim_utils.h"
#include "uthash.h"
#include "dlmalloc-2.8.6.h"

typedef struct RuleHash_t {
    int rule_id;
    int *rule_body;     // 2i+0: val of symbol i,  2i+1: exp of symbol i
    int symbols;        // how many symbols in the rule body
    UT_hash_handle hh;
} RuleHash;

static RuleHash* rules_table;

void read_global_metadata(char* path, GlobalMetadata *gm) {
    char global_metadata_path[256];
    sprintf(global_metadata_path, "%s/pilgrim.mt", path);
    FILE* fh = fopen(global_metadata_path, "rb");
    fread(gm, sizeof(GlobalMetadata), 1, fh);
    fclose(fh);

    printf("Total procs: %d, Time resolution: %.1fus\n\n", gm->ranks, gm->time_resolution*1000000);
}


void print_rule(RuleHash *rule) {
    printf("rule %d, symbols: %d\n\t-->", rule->rule_id, rule->symbols);
    for(int i = 0; i < rule->symbols; i++)
        printf(" %d^%d", rule->rule_body[2*i], rule->rule_body[2*i+1]);
    printf("\n");
}


/*
 * First pass: decompress the inter-process compressed grammars
 *
 * Recursively decode rules
 */
void decode_rule(int* decompressed_symbols, int *pos, int rule_id, int start_rule_id) {
    RuleHash *rule;
    HASH_FIND_INT(rules_table, &rule_id, rule);

    for(int i = 0; i < rule->symbols; i++) {
        int sym_val = rule->rule_body[2*i+0];
        int sym_exp = rule->rule_body[2*i+1];
        // Non-terminal, i.e., a rule
        if(sym_val < start_rule_id) {
            for(int j = 0; j < sym_exp; j++)
                decode_rule(decompressed_symbols, pos, sym_val, start_rule_id);
        }
        // Terminal
        else {
            decompressed_symbols[*pos]= sym_val;
            decompressed_symbols[*pos+1] = sym_exp;
            *pos = *pos + 2;
        }
    }
}

/**
 * Second pass: for each rank, decode its grammar
 */
void decode_and_write(int rule_id, FILE *f) {

    RuleHash *rule;
    HASH_FIND_INT(rules_table, &rule_id, rule);
    for(int i = 0; i < rule->symbols; i++) {
        int sym = rule->rule_body[2*i+0];
        int exp = rule->rule_body[2*i+1];

        // Non-terminal, i.e., a rule
        if(sym < -1) {
            decode_and_write(sym, f);
        }
        // Terminal
        else {
            if(sym == 9999999)
                fprintf(f, "0\n");
            else
                fprintf(f, "%.6f\n", pow(1.1, sym));
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

void decompress(char *path, int total_ranks) {

    FILE* f = fopen(path, "rb");

    int start_rule_id, rules;
    size_t uncompressed_integers;
    fread(&start_rule_id, sizeof(int), 1, f);
    fread(&uncompressed_integers, sizeof(size_t), 1, f);
    fread(&rules, sizeof(int), 1, f);

    printf("Start_rule_id: %d, Rules: %d, Uncompressed integers: %ld\n", start_rule_id, rules, uncompressed_integers);

    for(int i = 0; i < rules; i++) {
        RuleHash *rule = malloc(sizeof(RuleHash));

        fread(&(rule->rule_id), sizeof(int), 1, f);
        fread(&(rule->symbols), sizeof(int), 1, f);

        rule->rule_body = (int*) malloc(sizeof(int)*rule->symbols*2);
        fread(rule->rule_body, sizeof(int), rule->symbols*2, f);

        //print_rule(rule);
        HASH_ADD_INT(rules_table, rule_id, rule);
    }

    int *decompressed  = malloc(sizeof(int) * uncompressed_integers);
    int pos = 0;
    decode_rule(decompressed, &pos, start_rule_id, start_rule_id);
    clean_rules_table();


    char output_path[256] = {0};
    sprintf(output_path, "%s.txt", path);
    FILE *fout = fopen(output_path, "w");

    pos = 0;
    for(int rank = 0; rank < total_ranks; rank++) {

        int rules = decompressed[pos++];
        pos++;      // skip exp

        for(int j = 0; j < rules; j++) {
            RuleHash *rule = malloc(sizeof(RuleHash));

            rule->rule_id = decompressed[pos++];
            pos++;  // skip exp

            rule->symbols = decompressed[pos++];
            pos++;  // skip exp
            printf("rank: %d, add rule: %d, symbols: %d\n", rank, rule->rule_id, rule->symbols);

            rule->rule_body = malloc(2*sizeof(int)*rule->symbols);
            memcpy(rule->rule_body, &(decompressed[pos]), 2*sizeof(int)*rule->symbols);
            pos += (rule->symbols)*2;
            HASH_ADD_INT(rules_table, rule_id, rule);
        }

        // write out to this rank
        fprintf(fout, "\n\n//======================================\n");
        fprintf(fout, "// Rank = %d\n", rank);
        fprintf(fout, "//======================================\n");

        decode_and_write(-1, fout);

        fprintf(fout, "\n//======================================\n");

        clean_rules_table();
    }

    fclose(fout);
    fclose(f);
    free(decompressed);
}


int main(int argc, char** argv) {

    decompress(argv[1], atoi(argv[2]));

    return 0;
}
