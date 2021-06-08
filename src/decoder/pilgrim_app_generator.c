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


void write_call(FILE* f, CallSignature *cs, const char* indent) {
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
    fprintf(f, "\tMPI_Comm_size(MPI_COMM_WORLD, &g_mpi_size);\n");
    fprintf(f, "\tMPI_Comm_rank(MPI_COMM_WORLD, &g_mpi_rank);\n");
}

void write_epilogue(FILE* f) {
    fprintf(f, "\tMPI_Finalize();\n");
    fprintf(f, "\treturn 0;\n}\n");
}


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
    int num_symbols[gm.ranks];
    int** decoded_symbols = read_cfg(cfg_path, gm.ranks, num_symbols);

    // 3. Generate a MPI program
    char source_file_path[256];
    sprintf(source_file_path, "%s/proxy_app.c", directory);
    FILE* f = fopen(source_file_path, "w");

    write_prologue(f);

    for(int rank = 0; rank < gm.ranks; rank++) {
        fprintf(f, "\tif(g_mpi_rank == %d) { \n", rank);

        write_init_variables(f, decoded_symbols[rank], num_symbols[rank], cst);

        for(int i = 0; i < num_symbols[rank]; i+=2) {

            int sym = decoded_symbols[rank][i];
            int exp = decoded_symbols[rank][i+1];
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

        free(decoded_symbols[rank]);
    }

    free(decoded_symbols);

    write_epilogue(f);
    fclose(f);

    return 0;
}
