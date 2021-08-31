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

void print_rule(RuleHash *rule) {
    printf("rule %d, symbols: %d\n\t-->", rule->rule_id, rule->symbols);
    for(int i = 0; i < rule->symbols; i++)
        printf(" %d^%d", rule->rule_body[2*i], rule->rule_body[2*i+1]);
    printf("\n");
}

void print_grammar(RuleHash *rules_table) {
    RuleHash *current, *tmp;
    HASH_ITER(hh, rules_table, current, tmp) {
        print_rule(current);
    }
}


/**
 * Decompress a CFG by recursive rule application
 *
 * The decompressed symbols will be stored in the
 * decoded_symbols array.
 *
 * rule_id: id of the current rule to decode
 * start_rule_id: the id of the first rule, not always -1 due
 *                to inter-process compression
 *
 */
void rule_application(RuleHash* rules, int rule_id, int start_rule_id, int* decoded_symbols, int* pos) {
    RuleHash *rule = NULL;
    HASH_FIND_INT(rules, &rule_id, rule);
    assert(rule != NULL);

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

void clean_rules(RuleHash* rules_table) {
    RuleHash *current, *tmp;
    HASH_ITER(hh, rules_table, current, tmp) {
        HASH_DEL(rules_table, current);
        free(current->rule_body);
        free(current);
    }
    rules_table = NULL;
}

void free_decoded_grammars(DecodedGrammars* dg) {
    free(dg->num_symbols);
    free(dg->grammar_ids);
    for(int i = 0; i < dg->num_grammars; i++) {
        free(dg->unique_grammars[i]);
        clean_rules(dg->intra_cfgs[i]);
    }
    free(dg->unique_grammars);
    free(dg);
}


/**
 * Read the inter-process compressed grammar
 * And store its rules in a hash-table.
 * It will be later used for decopmression.
 *
 * in: path, nprocs
 * out: original_integers, start_rule_id, dg
 */
RuleHash* read_inter_compressed_grammar(char* path, int nprocs, size_t* original_integers, int* start_rule_id, DecodedGrammars* dg) {

    FILE* f = fopen(path, "rb");

    fread(dg->grammar_ids, sizeof(int), nprocs, f);
    fread(&dg->num_grammars, sizeof(int), 1, f);

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
    //printf("Unique Grammars: %d, Start_rule_id: %d, Rules: %d, Uncompressed integers: %ld\n",
    //        dg->num_grammars, *start_rule_id, rules, *original_integers);

    return rules_table;
}

/**
 * After decopmress the inter-process compressed grammar into
 * an array, we can read every ranks copmressed grammar.
 *
 * This function will read the grammar (integer array) to form
 * a hash table of rules
 */
RuleHash* read_one_unique_grammar(int* grammar, int *size, bool last_grammar) {
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

        int rule_integers = 2 * rule->symbols;   // val and exp
        rule->rule_body = malloc(sizeof(int)*rule_integers);
        memcpy(rule->rule_body, &(grammar[pos]), sizeof(int)*rule_integers);
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
DecodedGrammars* read_cfg(char* path, int nprocs) {

    DecodedGrammars *dg = malloc(sizeof(DecodedGrammars));
    dg->grammar_ids = malloc(sizeof(int) * nprocs);

    // 1. Read and decompress inter-process compressed grammar
    size_t original_integers;
    int start_rule_id;
    int pos = 0;
    RuleHash* inter_cfg = read_inter_compressed_grammar(path, nprocs, &original_integers, &start_rule_id, dg);
    //print_grammar(inter_cfg);
    int* inter_decompressed_t = malloc(sizeof(int)*original_integers);
    int* inter_decompressed = inter_decompressed_t;
    rule_application(inter_cfg, start_rule_id, start_rule_id, inter_decompressed, &pos);
    clean_rules(inter_cfg);
    //printf("Finsihed decopmressing inter-process compressed grammar\n");

    // 2. Read and decompress each rank's grammar
    dg->unique_grammars = malloc(sizeof(int*)*dg->num_grammars);
    dg->num_symbols = malloc(sizeof(int)*dg->num_grammars);
    dg->intra_cfgs = malloc(sizeof(RuleHash*) * dg->num_grammars);

    for(int ugi = 0; ugi < dg->num_grammars; ugi++) {
        int advance = 0;
        bool last_grammar = (ugi == dg->num_grammars-1);
        dg->intra_cfgs[ugi] = read_one_unique_grammar(inter_decompressed, &advance, last_grammar);

        // First pass to copmute the number of symbols after decompression
        dg->num_symbols[ugi] = 0;
        rule_application(dg->intra_cfgs[ugi], -1, -1, NULL, &dg->num_symbols[ugi]);

        // Second pass to fill in the symbols
        dg->unique_grammars[ugi] = malloc(sizeof(int) * dg->num_symbols[ugi]);
        dg->num_symbols[ugi] = 0;
        rule_application(dg->intra_cfgs[ugi], -1, -1, dg->unique_grammars[ugi], &dg->num_symbols[ugi]);

        inter_decompressed += advance;
    }

    free(inter_decompressed_t);
    return dg;
}

