/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "uthash.h"
#include "pilgrim.h"
#include "pilgrim_reader.h"

typedef struct VariablePool_t {
    int value;          // value as key
    int id;
    UT_hash_handle hh;
} VariablePool;


static VariablePool* variable_pools[15];    // One variable pool for each variable type
static int variable_current_ids[15];

void free_init_variables(FILE* f) {
    for(int i = 0; i < 15; i++) {
        VariablePool *current, *tmp;
        HASH_ITER(hh, variable_pools[i], current, tmp) {
            HASH_DEL(variable_pools[i], current);

            if(i == TYPE_MEM_PTR)
                fprintf(f, "\t\tfree(%s_%d);\n", TYPE_VAR_STR[i], current->value);
            free(current);
        }
        variable_current_ids[i] = 0;
        variable_pools[i] = NULL;
    }
}

void write_init_variables(FILE* fout, int* decoded_symbols, int num_symbols, CallSignature *cst) {

    bool comm_flag = false;

    CallSignature *cs;

    for(int i = 0; i < num_symbols; i+=2) {
        int sym = decoded_symbols[i];
        cs = &(cst[sym]);

        for(int j = 0; j < cs->arg_count; j++) {
            int type = cs->arg_types[j];
            int dir = cs->arg_directions[j];
            if(type == TYPE_NON_MPI) {

            } else if(type == TYPE_MPI_Comm) {
                if(!comm_flag) {
                    fprintf(fout, "\t\t%s %s_0 = MPI_COMM_WORLD;\n", TYPE_STR[type], TYPE_VAR_STR[type]);
                    comm_flag = true;
                }
            } else if(type == TYPE_RANK_ENCODED) {
            } else if(type == TYPE_MEM_PTR) {
                MemPtrAttr* attr = (MemPtrAttr*) cs->args[j];

                VariablePool* var = NULL;
                HASH_FIND_INT(variable_pools[type], &attr->id, var);

                if(var == NULL) {
                    var = malloc(sizeof(VariablePool));
                    var->value = attr->id;
                    var->id = variable_current_ids[type]++;
                    HASH_ADD_INT(variable_pools[type], value, var);
                    fprintf(fout, "\t\t%s %s_%d = malloc(%lu);\n", TYPE_STR[type], TYPE_VAR_STR[type], var->id, attr->size);
                }

            } else {    // all types with interger values
                int value = *((int*)cs->args[j]);

                if(type==TYPE_INT && dir == DIRECTION_IN)
                    continue;

                VariablePool* var = NULL;
                HASH_FIND_INT(variable_pools[type], &value, var);

                if(var == NULL) {
                    var = malloc(sizeof(VariablePool));
                    var->value = value;
                    var->id = variable_current_ids[type]++;
                    HASH_ADD_INT(variable_pools[type], value, var);
                    if(dir == DIRECTION_IN) {
                        if(type == TYPE_MPI_Datatype)
                            fprintf(fout, "\t\t%s %s_%d = MPI_INT;\n", TYPE_STR[type], TYPE_VAR_STR[type], var->id);
                        else
                            fprintf(fout, "\t\t%s %s_%d = %d;\n", TYPE_STR[type], TYPE_VAR_STR[type], var->id, value);
                    }
                    else
                        fprintf(fout, "\t\t%s %s_%d;\n", TYPE_STR[type], TYPE_VAR_STR[type], var->id);
                }
            }
        }
    }
}


char* write_argument(CallSignature *cs, int i) {
    int type = cs->arg_types[i];
    int direction = cs->arg_directions[i];

    char *name = calloc(sizeof(char), 20);
    if(type == TYPE_NON_MPI) {
        sprintf(name, "[Not Handled]");
    } else if(type == TYPE_MPI_Comm) {
        sprintf(name, "%s_0", TYPE_VAR_STR[type]);
    } else if(type == TYPE_RANK_ENCODED) {
        int value = *((int*)cs->args[i]);
        if(value >= 0)
            sprintf(name, "g_mpi_rank-%d", value);
        else
            sprintf(name, "g_mpi_rank+%d", -value);
    } else if(type == TYPE_MEM_PTR) {
        MemPtrAttr* attr = (MemPtrAttr*)cs->args[i];
        sprintf(name, "%s_%d+%lu", TYPE_VAR_STR[type], attr->id, attr->offset);
    } else if(type == TYPE_MPI_Status) {
        sprintf(name, "MPI_STATUS_IGNORE");
    } else {    // all other (basic data types or mpi objects) with integer values
        int value = *((int*)cs->args[i]);

        if(type==TYPE_INT && direction == DIRECTION_IN)
            sprintf(name, "%d", value);
        else {
            VariablePool* var = NULL;
            HASH_FIND_INT(variable_pools[type], &value, var);
            assert(var);
            if(direction == DIRECTION_IN)
                sprintf(name, "%s_%d", TYPE_VAR_STR[type], var->id);
            else
                sprintf(name, "&%s_%d", TYPE_VAR_STR[type], var->id);
        }
    }

    return name;
}

void write_call_special(FILE* f, CallSignature *cs, const char* indent) {
    if(cs->func_id == ID_MPI_Waitall) {
        fprintf(f, "%sMPI_Request reqs[] = {", indent);
        int count = *((int*)cs->args[0]);
        for(int i = 0; i < count; i++) {
            int *ids = cs->args[1];
            VariablePool* var = NULL;
            HASH_FIND_INT(variable_pools[TYPE_MPI_Request], &ids[i], var);
            assert(var);
            fprintf(f, "%s_%d", TYPE_VAR_STR[TYPE_MPI_Request], var->id);
            if(i < count - 1)
                fprintf(f, ", ");
        }
        fprintf(f, "};\n");
        fprintf(f, "%sMPI_Waitall(%d, reqs, MPI_STATUSES_IGNORE);\n", indent, count);
    }
}


void write_call(FILE* f, CallSignature *cs, const char* indent) {
    if(cs->func_id == ID_MPI_Waitall) {
        write_call_special(f, cs, indent);
        return;
    }

    fprintf(f, "%s%s(", indent, func_names[cs->func_id]);
    for(int i = 0; i < cs->arg_count; i++) {
        char* var = write_argument(cs, i);
        fprintf(f, "%s", var);
        free(var);

        if(i != cs->arg_count - 1)
            fprintf(f, ", ");
        else
            fprintf(f, ");\n");
    }
}

void write_prologue(FILE* f) {
    fprintf(f, "#include <stdio.h>\n");
    fprintf(f, "#include <stdlib.h>\n");
    fprintf(f, "#include <mpi.h>\n\n");

    fprintf(f, "static int g_mpi_rank;\n");
    fprintf(f, "static int g_mpi_size;\n\n");

    fprintf(f, "int main(int argc, char* argv[]) {\n");
    fprintf(f, "\tMPI_Init(&argc, &argv);\n");
    fprintf(f, "\tPMPI_Comm_size(MPI_COMM_WORLD, &g_mpi_size);\n");
    fprintf(f, "\tPMPI_Comm_rank(MPI_COMM_WORLD, &g_mpi_rank);\n");
}

void write_epilogue(FILE* f) {
    fprintf(f, "\tMPI_Finalize();\n");
    fprintf(f, "\treturn 0;\n}\n");
}


static int loop_var;
void recursive_write_rule(FILE* f, RuleHash* rules, int rule_id, CallSignature *cst) {

    RuleHash *rule = NULL;
    HASH_FIND_INT(rules, &rule_id, rule);
    assert(rule != NULL);

    for(int i = 0; i < rule->symbols; i++) {
        int sym_val = rule->rule_body[2*i+0];
        int sym_exp = rule->rule_body[2*i+1];
        // Non-terminal, i.e., a rule
        if(sym_val < -1) {
            printf("write rule: %d\n", sym_val);
            if(sym_exp > 1) {
                fprintf(f, "\t\tfor(int i%d = 0; i%d < %d; i%d++) {\n", loop_var, loop_var, sym_exp, loop_var);
                loop_var++;
                recursive_write_rule(f, rules, sym_val, cst);
                fprintf(f, "\t\t};\n");
            } else {
                recursive_write_rule(f, rules, sym_val, cst);
            }
        }
        // Terminal
        else {
            CallSignature cs = cst[sym_val];
            if(sym_exp > 1) {
                fprintf(f, "\t\tfor(int i%d = 0; i%d < %d; i%d++)\n", loop_var, loop_var, sym_exp, loop_var);
                loop_var++;
                write_call(f, &cs, "\t\t\t");
            } else {
                write_call(f, &cs, "\t\t");
            }
        }
    }
}



/*
int main(int argc, char** argv) {

    char* directory = argv[1];
    char cfg_path[256];
    char cst_path[256];
    char metadata_path[256];
    sprintf(cfg_path, "%s/grammars.dat", directory);
    sprintf(cst_path, "%s/funcs.dat", directory);
    sprintf(metadata_path, "%s/pilgrim.mt", directory);

    // 0. Read metadata
    GlobalMetadata gm;
    read_metadata(metadata_path, &gm);

    // 1. Read CST
    int num_sigs;
    CallSignature *cst = read_cst(cst_path, &num_sigs);

    // 2. Read CFG
    DecodedGrammars* dg = read_cfg(cfg_path, gm.ranks);

    // 3. Generate a MPI program
    char source_file_path[256];
    sprintf(source_file_path, "%s/proxy_app.c", directory);
    FILE* f = fopen(source_file_path, "w");

    write_prologue(f);

    for(int ugi = 0; ugi < dg->num_grammars; ugi++) {

        bool first = true;
        fprintf(f, "\tif(");
        for(int rank = 0; rank < gm.ranks; rank++) {
            if(ugi == dg->grammar_ids[rank]) {
                if(first)
                    fprintf(f, "g_mpi_rank == %d", rank);
                else
                    fprintf(f, " || g_mpi_rank == %d", rank);
                first = false;
            }
        }
        fprintf(f, ") {\n");


        int* decoded_symbols = dg->unique_grammars[ugi];
        write_init_variables(f, decoded_symbols, dg->num_symbols[ugi], cst);

        for(int i = 0; i < dg->num_symbols[ugi]; i+=2) {

            int sym = decoded_symbols[i];
            int exp = decoded_symbols[i+1];
            CallSignature cs = cst[sym];

            if(exp > 1) {
                fprintf(f, "\t\tfor(int i = 0; i < %d; i++)\n", exp);
                write_call(f, &cs, "\t\t\t");
            } else {
                write_call(f, &cs, "\t\t");
            }
        }
        free_init_variables(f);

        fprintf(f, "\t}\n\n");
    }

    free_decoded_grammars(dg);
    write_epilogue(f);
    fclose(f);

    return 0;
}
*/


int main(int argc, char** argv) {

    char* directory = argv[1];
    char cfg_path[256];
    char cst_path[256];
    char metadata_path[256];
    sprintf(cfg_path, "%s/grammars.dat", directory);
    sprintf(cst_path, "%s/funcs.dat", directory);
    sprintf(metadata_path, "%s/pilgrim.mt", directory);

    // 0. Read metadata
    GlobalMetadata gm;
    read_metadata(metadata_path, &gm);

    // 1. Read CST
    int num_sigs;
    CallSignature *cst = read_cst(cst_path, &num_sigs);

    // 2. Read CFG
    DecodedGrammars* dg = read_cfg(cfg_path, gm.ranks);

    // 3. Generate a MPI program
    char source_file_path[256];
    sprintf(source_file_path, "%s/proxy_app.c", directory);
    FILE* f = fopen(source_file_path, "w");

    write_prologue(f);

    for(int ugi = 0; ugi < dg->num_grammars; ugi++) {

        // if condition for all ranks with the same grammar
        bool first = true;
        fprintf(f, "\tif(");
        for(int rank = 0; rank < gm.ranks; rank++) {
            if(ugi == dg->grammar_ids[rank]) {
                if(first)
                    fprintf(f, "g_mpi_rank == %d", rank);
                else
                    fprintf(f, " || g_mpi_rank == %d", rank);
                first = false;
            }
        }
        fprintf(f, ") {\n");

        // Acutal if body
        printf("write ugi: %d\n", ugi);
        loop_var = 0;
        int* decoded_symbols = dg->unique_grammars[ugi];
        write_init_variables(f, decoded_symbols, dg->num_symbols[ugi], cst);

        recursive_write_rule(f, dg->intra_cfgs[ugi], -1, cst);


        free_init_variables(f);

        // end of if
        fprintf(f, "\t}\n\n");
    }

    free_decoded_grammars(dg);
    write_epilogue(f);
    fclose(f);

    return 0;
}

