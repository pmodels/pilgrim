/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilgrim.h"
#include "pilgrim_reader.h"
#include "pilgrim_utils.h"
#include "uthash.h"

/**
 * A hash table to represent a CFG
 * Key: rule id
 * Val: rule body
 */
typedef struct RuleHash_t {
    int rule_id;
    int *rule_body;     // 2i+0: val of symbol i,  2i+1: exp of symbol i
    int symbols;        // There are a total of 2*symbols integers in the rule body
    UT_hash_handle hh;
} RuleHash;

void print_rule(RuleHash *rule) {
    printf("rule %d, symbols: %d\n\t-->", rule->rule_id, rule->symbols);
    for(int i = 0; i < rule->symbols; i++)
        printf(" %d^%d", rule->rule_body[2*i], rule->rule_body[2*i+1]);
    printf("\n");
}


/**
 * Decompress a CFG by recursive rule application
 *
 * The decompressed symbols will be represented by
 * decopmressed_symbols array.
 *
 */
void rule_application(RuleHash* rules, int rule_id, int start_rule_id, int* decoded_symbols, int* pos) {
    RuleHash *rule;
    HASH_FIND_INT(rules, &rule_id, rule);

    for(int i = 0; i < rule->symbols; i++) {
        int sym_val = rule->rule_body[2*i+0];
        int sym_exp = rule->rule_body[2*i+1];
        // Non-terminal, i.e., a rule
        if(sym_val < start_rule_id) {
            for(int j = 0; j < sym_exp; j++)
                rule_application(rules, sym_val, start_rule_id, decoded_symbols, pos);
        }
        // Terminal
        else {
            if(decoded_symbols) {
                decoded_symbols[*pos]= sym_val;
                decoded_symbols[*pos+1] = sym_exp;
            }
            *pos = *pos + 2;
        }
    }
}

/**
 * Second pass: for each rank, decode its grammar
 */
/*
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
*/


void clean_rules(RuleHash* rules_table) {
    RuleHash *current, *tmp;
    HASH_ITER(hh, rules_table, current, tmp) {
        HASH_DEL(rules_table, current);
        free(current->rule_body);
        free(current);
    }
    rules_table = NULL;
}

/**
 * Read the inter-process compressed grammar
 * And store its rules in a hash-table.
 *
 * It will be later used for decopmression.
 */
RuleHash* read_inter_compressed_grammar(char* path, size_t* original_integers, int* start_rule_id) {

    FILE* f = fopen(path, "rb");

    // Read the inter-process compressed grammar
    // The header has three values:
    // start rule id, number of rules, and number of intergers once decompressed.
    int rules;
    fread(start_rule_id, sizeof(int), 1, f);
    fread(original_integers, sizeof(size_t), 1, f);
    fread(&rules, sizeof(int), 1, f);

    RuleHash* rules_table = NULL;
    for(int i = 0; i < rules; i++) {
        RuleHash *rule = malloc(sizeof(RuleHash));

        fread(&(rule->rule_id), sizeof(int), 1, f);
        fread(&(rule->symbols), sizeof(int), 1, f);

        rule->rule_body = (int*) malloc(sizeof(int)*rule->symbols*2);
        fread(rule->rule_body, sizeof(int), rule->symbols*2, f);

        HASH_ADD_INT(rules_table, rule_id, rule);
    }
    printf("Start_rule_id: %d, Rules: %d, Uncompressed integers: %ld\n", *start_rule_id, rules, *original_integers);

    return rules_table;
}

/**
 * After decopmress the inter-process compressed grammar into
 * an array, we can read every ranks copmressed grammar.
 *
 * This function will read the grammar (integer array) to form
 * a hash table of rules
 */
RuleHash* read_intra_compressed_grammar(int* grammar, int *size) {
    int pos = 0;
    RuleHash* rules_table = NULL;
    int rules = grammar[pos++];
    pos++;
    for(int i = 0; i < rules; i++) {
        RuleHash *rule = malloc(sizeof(RuleHash));

        rule->rule_id = grammar[pos++];
        pos++;  // skip exp

        rule->symbols = grammar[pos++];
        pos++;  // skip exp

        rule->rule_body = malloc(2*sizeof(int)*rule->symbols);
        memcpy(rule->rule_body, &(grammar[pos]), 2*sizeof(int)*rule->symbols);
        pos += (rule->symbols)*2;
        HASH_ADD_INT(rules_table, rule_id, rule);
    }

    *size = pos;
    return rules_table;
}


/**
 * Decompress the inter-process compressed grammar
 * The grammar is read by read_compressed_grammar()
 *
 */
int** read_cfg(char* path, int nprocs, int *num_symbols) {

    // 1. Read and decompress inter-process compressed grammar
    size_t original_integers;
    int start_rule_id;
    int pos = 0;
    RuleHash* inter_cfg = read_inter_compressed_grammar(path, &original_integers, &start_rule_id);
    int* decompressed = malloc(sizeof(int)*original_integers);
    rule_application(inter_cfg, start_rule_id, start_rule_id, decompressed, &pos);
    clean_rules(inter_cfg);

    // 2. Read and decompress each rank's grammar
    int** decoded_symbols = malloc(sizeof(int*)*nprocs);

    int last_grammar_size = 0;
    int *grammar = decompressed;
    for(int rank = 0; rank < nprocs; rank++) {
        grammar += last_grammar_size;
        RuleHash* intra_cfg = read_intra_compressed_grammar(grammar, &last_grammar_size);

        // First pass to copmute the number of symbols after decompression
        num_symbols[rank] = 0;
        rule_application(intra_cfg, -1, -1, NULL, &num_symbols[rank]);

        // Second pass to fill in the symbols
        decoded_symbols[rank] = malloc(sizeof(int) * num_symbols[rank]);
        num_symbols[rank] = 0;
        rule_application(intra_cfg, -1, -1, decoded_symbols[rank], &num_symbols[rank]);

        clean_rules(intra_cfg);
    }

    free(decompressed);
    return decoded_symbols;
}

