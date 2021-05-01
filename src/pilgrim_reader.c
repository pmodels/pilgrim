#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pilgrim.h"
#include "pilgrim_reader.h"
#include "uthash.h"
#include "dlmalloc-2.8.6.h"

typedef struct RuleHash_t {
    int rule_id;
    int *rule_body;     // 2i+0: val of symbol i,  2i+1: exp of symbol i
    int symbols;        // how many symbols in the rule body
    UT_hash_handle hh;
} RuleHash;

typedef struct VariablePool_t {
    int value;
    int id;
    UT_hash_handle hh;
} VariablePool;


static int rank;
static int nprocs;
static RuleHash* rules_table;
static VariablePool* variable_pools[15];    // One variable pool for each variable type
static int variable_current_ids[15];



void read_global_metadata(char* path, GlobalMetadata *gm) {
    char global_metadata_path[256];
    sprintf(global_metadata_path, "%s/pilgrim.mt", path);
    FILE* fh = fopen(global_metadata_path, "rb");
    fread(gm, sizeof(GlobalMetadata), 1, fh);
    fclose(fh);

    printf("Total procs: %d, Time resolution: %.1fus\n\n", gm->ranks, gm->time_resolution*1000000);
}

void read_local_metadata(char* path, int rank, LocalMetadata *lm) {
    char local_metadata_path[256];
    sprintf(local_metadata_path, "%s/%d.mt", path, rank);
    FILE* fh = fopen(local_metadata_path, "rb");
    fread(lm, sizeof(LocalMetadata), 1, fh);
    fclose(fh);
    printf("rank: %d, tstart: %f, tend: %f, records: %ld\n", lm->rank, lm->tstart, lm->tend, lm->records_count);
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
int decode_rule(int* decompressed_symbols, int rule_id, int start_rule_id) {
    int advance = 0;

    RuleHash *rule;
    HASH_FIND_INT(rules_table, &rule_id, rule);

    for(int i = 0; i < rule->symbols; i++) {
        int sym_val = rule->rule_body[2*i+0];
        int sym_exp = rule->rule_body[2*i+1];
        // Non-terminal, i.e., a rule
        if(sym_val < start_rule_id) {
            for(int j = 0; j < sym_exp; j++) {
                int advanced = decode_rule(decompressed_symbols, sym_val, start_rule_id);
                decompressed_symbols += advanced;
                advance += advanced;
            }
        }
        // Terminal
        else {
            *decompressed_symbols = sym_val;
            decompressed_symbols++;
            *decompressed_symbols = sym_exp;
            decompressed_symbols++;
            advance += 2;
        }
    }

    return advance;
}

char* get_variable_name(CallSignature *cs, int i) {
    int type = cs->arg_types[i];
    int direction = cs->arg_directions[i];

    char *name = calloc(sizeof(char), 20);
    if(type == TYPE_NON_MPI) {
        sprintf(name, "[Not Handled]");
    } else if(type == TYPE_MPI_Comm) {
        sprintf(name, "%s_0", TYPE_VAR_STR[type]);
    } else {    // all other mpi objects with integer values
        int value = *((int*)cs->args[i]);
        VariablePool* var = NULL;
        HASH_FIND_INT(variable_pools[type], &value, var);

        assert(var);

        if(direction == DIRECTION_IN)
            sprintf(name, "%s_%d", TYPE_VAR_STR[type], var->id);
        else
            sprintf(name, "&%s_%d", TYPE_VAR_STR[type], var->id);
    }

    return name;
}


void write_call(FILE* f, CallSignature *cs) {
    fprintf(f, "%s(", func_names[cs->func_id]);
    for(int i = 0; i < cs->arg_count; i++) {
        char* var = get_variable_name(cs, i);
        fprintf(f, "%s", var);
        free(var);

        if(i != cs->arg_count - 1)
            fprintf(f, ", ");
        else
            fprintf(f, ");\n");
    }
}


/**
 * Second pass: for each rank, decode its grammar
 */
void decode_and_write(int rule_id, FILE *f, CallSignature *call_sigs) {

    RuleHash *rule;
    HASH_FIND_INT(rules_table, &rule_id, rule);
    for(int i = 0; i < rule->symbols; i++) {
        int sym = rule->rule_body[2*i+0];
        int exp = rule->rule_body[2*i+1];

        // Non-terminal, i.e., a rule
        if(sym < -1) {
            decode_and_write(sym, f, call_sigs);
        }
        // Terminal
        else {
            CallSignature *cs = &(call_sigs[sym]);
            write_call(f, cs);
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

void read_cfg(char *path, int total_ranks, CallSignature* funcs) {
    printf("\nRead CFG\n");
    char grammar_file_path[256];
    sprintf(grammar_file_path, "%s/grammars.dat", path);

    FILE* f = fopen(grammar_file_path, "rb");

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

        print_rule(rule);
        HASH_ADD_INT(rules_table, rule_id, rule);
    }

    int *decompressed  = malloc(sizeof(int) * uncompressed_integers);
    decode_rule(decompressed, start_rule_id, start_rule_id);
    clean_rules_table();

    int pos = 0;
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

            rule->rule_body = malloc(sizeof(int)*rule->symbols*2);
            rule->rule_body = malloc(2*sizeof(int)*rule->symbols);
            memcpy(rule->rule_body, &(decompressed[pos]), 2*sizeof(int)*rule->symbols);
            pos += (rule->symbols)*2;
            HASH_ADD_INT(rules_table, rule_id, rule);
        }

        // write out to this rank
        /*
        char output_path[256];
        sprintf(output_path, "%s/main.c", path);
        FILE *fout = fopen(output_path, "a");
        fprintf(fout, "\n\n//======================================\n");
        fprintf(fout, "// Code for Rank = %d\n", rank);
        fprintf(fout, "//======================================\n");
        //decode_and_write(-1, fout, funcs);
        fprintf(fout, "//======================================\n");
        fclose(fout);
        */

        clean_rules_table();
    }

    fclose(f);
    free(decompressed);
}

CallSignature* read_cst(char *directory, int *num_funcs) {
    printf("\nRead CST\n");
    char path[256];
    sprintf(path, "%s/funcs.dat", directory);
    FILE* f = fopen(path, "rb");

    short func_id;
    int entries, key_len, terminal, rank, duration, interval;
    fread(&entries, sizeof(int), 1, f);
    *num_funcs = entries;

    CallSignature *call_sigs = malloc(sizeof(CallSignature) * entries);

    char buff[512];
    for(int i = 0; i < entries; i++) {

        fread(&terminal, sizeof(int), 1, f);
        fread(&rank, sizeof(int), 1, f);
        fread(&key_len, sizeof(int), 1, f);

        fread(&func_id, sizeof(short), 1, f);
        fread(buff, 1, key_len-sizeof(short), f);

        assert(terminal < entries);
        call_sigs[terminal].func_id = func_id;
        read_record_args(func_id, buff, &(call_sigs[terminal]));
        printf("Terminal: %d, Key len: %d, Func: %s\n", terminal, key_len, func_names[func_id]);
    }


    fclose(f);
    return call_sigs;
}


void write_init_variables(const char* path, CallSignature *call_sigs, int num_sigs) {

    char output_path[256] = {0};
    sprintf(output_path, "%s/main.c", path);
    FILE *fout = fopen(output_path, "w");

    bool comm_flag = false;

    CallSignature *cs;
    for(int i = 0; i < num_sigs; i++) {
        cs = &(call_sigs[i]);
        for(int j = 0; j < cs->arg_count; j++) {
            int type = cs->arg_types[j];
            int dir = cs->arg_directions[j];
            if(type == TYPE_NON_MPI) {

            } else if(type == TYPE_MPI_Comm) {
                if(!comm_flag) {
                    fprintf(fout, "%s %s_0 = MPI_COMM_WORLD;\n", TYPE_STR[type], TYPE_VAR_STR[type]);
                    comm_flag = true;
                }
            } else {    // all types with interger values
                int value = *((int*)cs->args[j]);

                VariablePool* var = NULL;
                HASH_FIND_INT(variable_pools[type], &value, var);

                if(var == NULL) {
                    var = malloc(sizeof(VariablePool));
                    var->value = value;
                    var->id = variable_current_ids[type]++;
                    HASH_ADD_INT(variable_pools[type], value, var);

                    if(dir == DIRECTION_IN)
                        fprintf(fout, "%s %s_%d = %d;\n", TYPE_STR[type], TYPE_VAR_STR[type], var->id, value);
                    else
                        fprintf(fout, "%s %s_%d;\n", TYPE_STR[type], TYPE_VAR_STR[type], var->id);
                }
            }
        }
    }

    fclose(fout);
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

    int num_sigs;
    CallSignature *call_sigs = read_cst(directory, &num_sigs);
    write_init_variables(directory, call_sigs, num_sigs);
    read_cfg(directory, gm.ranks, call_sigs);


    for(int i = 0; i < num_sigs; i++) {
        for(int j = 0; j < call_sigs[i].arg_count; j++)
            free(call_sigs[i].args[j]);
        free(call_sigs[i].arg_sizes);
        free(call_sigs[i].arg_types);
        free(call_sigs[i].arg_directions);
        free(call_sigs[i].args);
    }
    free(call_sigs);


    return 0;
}
