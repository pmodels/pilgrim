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
#include "pilgrim_consts.h"
#include "pilgrim_sequitur.h"

#define max(a,b) (((a)>(b))?(a):(b))

static int grammar_splitter = 10000;

typedef struct VariablePool_t {
    char* name;
    int symbolic_id;          // value (symbolic id in trace) as key
    UT_hash_handle hh;
} VariablePool;

static VariablePool* variable_pools[15];    // One variable pool for each variable type

VariablePool* var_find_or_add(int type, int symbolic_id, bool *exist) {
    *exist = true;
    VariablePool* var = NULL;
    HASH_FIND_INT(variable_pools[type], &symbolic_id, var);
    if(var == NULL) {
        *exist = false;
        var = malloc(sizeof(VariablePool));
        var->symbolic_id = symbolic_id;
        var->name = malloc(sizeof(32));
        sprintf(var->name, "%s_%d", TYPE_VAR_STR[type], var->symbolic_id);
        HASH_ADD_INT(variable_pools[type], symbolic_id, var);
    }
    return var;
}

void free_vars_pool() {
    for(int i = 0; i < 15; i++) {
        VariablePool *var, *tmp;
        HASH_ITER(hh, variable_pools[i], var, tmp) {
            HASH_DEL(variable_pools[i], var);
            free(var->name);
            free(var);
        }
        variable_pools[i] = NULL;
    }
}

void write_vars_declaration(FILE* f, Grammar *grammar, CallSignature *cst) {
    CallSignature* cs;
    Symbol *rule, *sym;
    DL_FOREACH(grammar->rules, rule) {
        DL_FOREACH(rule->rule_body, sym) {
            if(sym->val < 0 || sym->val >= grammar_splitter)
                continue;
            cs = &(cst[sym->val]);
            for(int j = 0; j < cs->arg_count; j++) {
                int type = cs->arg_types[j];
                int dir = cs->arg_directions[j];
                if(type == TYPE_NON_MPI) {
                } else if(type == TYPE_MPI_Comm) {
                } else if(type == TYPE_MPI_Datatype) {
                } else if(type == TYPE_MPI_Op) {
                } else if(type == TYPE_MPI_Status) {
                } else if(type == TYPE_RANK_ENCODED) {
                } else if(type == TYPE_TAG) {
                } else if(type == TYPE_MEM_PTR) {
                    MemPtrAttr* attr = (MemPtrAttr*) cs->args[j];
                    bool exist;
                    VariablePool* var = var_find_or_add(type, attr->id, &exist);
                    //if(!exist)
                    //    fprintf(f, "%s %s;\n", TYPE_STR[type], var->name);
                } else {    // all types with interger values
                    int value = *((int*)cs->args[j]);
                    if(type == TYPE_INT && dir == DIRECTION_IN)
                        continue;
                    bool exist;
                    VariablePool* var = var_find_or_add(type, value, &exist);
                    if(!exist)
                        fprintf(f, "%s %s;\n", TYPE_STR[type], var->name);
                }
            }
        }
    }
    fprintf(f, "\n");
}

int* write_vars_initialization(FILE* f, Symbol* rule, CallSignature *cst) {
    CallSignature* cs;
    Symbol *sym;

    int *mem_buf_sizes = malloc(sizeof(int)*30);
    memset(mem_buf_sizes, 0, sizeof(int)*30);
    int mem_buf_count = 0;

    DL_FOREACH(rule->rule_body, sym) {
        if(sym->val < 0 || sym->val >= grammar_splitter)
            continue;
        cs = &(cst[sym->val]);
        for(int i = 0; i < cs->arg_count; i++) {
            int type = cs->arg_types[i];
            if(type == TYPE_MEM_PTR) {
                MemPtrAttr* attr = (MemPtrAttr*) cs->args[i];
                mem_buf_sizes[attr->id] = max(attr->size, mem_buf_sizes[attr->id]);
            }
        }
    }

    for(int i = 0; i < 30; i++) {
        if(mem_buf_sizes[i] > 0)
            fprintf(f, "\t%s %s_%d = malloc(%d);\n", TYPE_STR[TYPE_MEM_PTR], TYPE_VAR_STR[TYPE_MEM_PTR], i, mem_buf_sizes[i]);
    }

    return mem_buf_sizes;
}

void write_vars_free(FILE* f, int *mem_buf_sizes) {
    for(int i = 0; i < 30; i++) {
        if(mem_buf_sizes[i] > 0)
            fprintf(f, "\tfree(%s_%d);\n", TYPE_VAR_STR[TYPE_MEM_PTR], i);
    }
    free(mem_buf_sizes);
}


char* write_argument(CallSignature *cs, int i) {
    int type = cs->arg_types[i];
    int direction = cs->arg_directions[i];

    char *name = calloc(sizeof(char), 20);
    if(type == TYPE_NON_MPI) {
        sprintf(name, "[Not Handled]");
    } else if(type == TYPE_RANK_ENCODED) {
        int value = *((int*)cs->args[i]);
        if(value == PILGRIM_MPI_PROC_NULL)
            sprintf(name, "MPI_PROC_NULL");
        else if(value == PILGRIM_MPI_ANY_SOURCE)
            sprintf(name, "MPI_ANY_SOURCE");
        else {
            if(value >= 0)
                sprintf(name, "g_mpi_rank-%d", value);
            else
                sprintf(name, "g_mpi_rank+%d", -value);
        }
    } else if(type == TYPE_TAG) {
        int value = *((int*)cs->args[i]);
        if(value == PILGRIM_MPI_ANY_TAG)
            sprintf(name, "MPI_ANY_TAG");
        else
            sprintf(name, "%d", value);
    } else if(type == TYPE_MEM_PTR) {
        MemPtrAttr* attr = (MemPtrAttr*)cs->args[i];
        sprintf(name, "%s_%d+%lu", TYPE_VAR_STR[type], attr->id, attr->offset);
    } else if(type == TYPE_MPI_Status) {
        sprintf(name, "MPI_STATUS_IGNORE");
    } else if(type == TYPE_MPI_Datatype) {
        int id = *((int*)cs->args[i]);
        sprintf(name, "%s", symbolic_id_to_mpi_datatype_str(id));
    } else if(type == TYPE_MPI_Op) {
        int id = *((int*)cs->args[i]);
        sprintf(name, "%s", symbolic_id_to_mpi_op_str(id));
    } else if(type == TYPE_MPI_Comm) {
        int id = *((int*)cs->args[i]);
        sprintf(name, "%s", symbolic_id_to_mpi_comm_str(id));
    } else {    // all other (basic data types or mpi objects) with integer values
        int value = *((int*)cs->args[i]);
        if(type==TYPE_INT && direction == DIRECTION_IN)
            sprintf(name, "%d", value);
        else {
            if(direction == DIRECTION_IN)
                sprintf(name, "%s_%d", TYPE_VAR_STR[type], value);
            else
                sprintf(name, "&%s_%d", TYPE_VAR_STR[type], value);
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
            fprintf(f, "%s_%d", TYPE_VAR_STR[TYPE_MPI_Request], ids[i]);
            if(i < count - 1)
                fprintf(f, ", ");
            else
                fprintf(f, "};\n");
        }

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

void write_prologue(FILE* f, Grammar* grammar, CallSignature* cst) {
    fprintf(f, "#include <stdio.h>\n");
    fprintf(f, "#include <stdlib.h>\n");
    fprintf(f, "#include <mpi.h>\n\n");
    fprintf(f, "static int g_mpi_rank;\n");
    fprintf(f, "static int g_mpi_size;\n");
    fprintf(f, "static int g_ugi;\n\n");

    write_vars_declaration(f, grammar, cst);
}


void write_epilogue(FILE* f, int nprocs, DecodedGrammars *dg) {
    fprintf(f, "int main(int argc, char* argv[]) {\n");
    fprintf(f, "\tMPI_Init(&argc, &argv);\n");
    fprintf(f, "\tPMPI_Comm_size(MPI_COMM_WORLD, &g_mpi_size);\n");
    fprintf(f, "\tPMPI_Comm_rank(MPI_COMM_WORLD, &g_mpi_rank);\n");

    // if condition for all ranks with the same grammar
    bool first = true;
    fprintf(f, "\tint grammar_ids[] = {");

    for(int rank = 0; rank < nprocs; rank++) {
        int ugi = dg->grammar_ids[rank];
        if(rank == nprocs-1)
            fprintf(f, "%d};\n", ugi);
        else
            fprintf(f, "%d, ", ugi);
    }
    fprintf(f, "\tg_ugi = grammar_ids[g_mpi_rank];\n");

    fprintf(f, "\tfunc_1();\n");
    fprintf(f, "\tMPI_Finalize();\n");
    fprintf(f, "\treturn 0;\n}\n");
}


Grammar* final_sequitur(DecodedGrammars* dg, int *final_splitter) {
    int splitter = grammar_splitter;
    Grammar *grammar = malloc(sizeof(Grammar));
    sequitur_init(grammar);
    for(int ugi = 0; ugi < dg->num_grammars; ugi++) {
        for(int i = 0; i < dg->num_symbols[ugi]; i+=2) {
            int sym = dg->unique_grammars[ugi][i];
            int exp = dg->unique_grammars[ugi][i+1];
            append_terminal(grammar, sym, exp);
        }
        append_terminal(grammar, splitter++, 1);
    }
    sequitur_print_rules(grammar);
    *final_splitter = splitter;

    return grammar;
}

void experimental_code(FILE* f, Grammar* grammar, CallSignature *cst, int final_splitter) {

    Symbol *rule, *sym;
    DL_FOREACH(grammar->rules, rule) {
        fprintf(f, "void func_%d();\n", -1*rule->val);
    }
    fprintf(f, "\n");

    DL_FOREACH(grammar->rules, rule) {
        fprintf(f, "void func_%d() {\n", -1*rule->val);

        int* mem_buf_sizes = write_vars_initialization(f, rule, cst);

        if(rule->val == -1)
            fprintf(f, "\tif(g_ugi == 0) {\n");

        DL_FOREACH(rule->rule_body, sym) {

            if(sym->val < grammar_splitter) {
                if(sym->exp > 1)
                    fprintf(f, "\tfor(int i = 0; i < %d; i++)\n", sym->exp);

                if(sym->val >= 0) {
                    CallSignature *cs = &cst[sym->val];
                    write_call(f, cs, sym->exp>1?"\t\t":"\t");
                } else {
                    fprintf(f, "\t%sfunc_%d();\n", sym->exp>1?"\t":"", -1*sym->val);
                }
            } else {
                // This code is only executed for rule -1
                if(sym->val == final_splitter - 1)
                    fprintf(f, "\t}\n");
                else
                    fprintf(f, "\t}\n\tif(g_ugi == %d) {\n", sym->val - grammar_splitter + 1);
            }
        }

        write_vars_free(f, mem_buf_sizes);

        fprintf(f, "}\n");
    }

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

    // 1. Read CST and CFG
    int num_sigs;
    CallSignature *cst = read_cst(cst_path, &num_sigs);
    DecodedGrammars* dg = read_cfg(cfg_path, gm.ranks);

    // 2. Sequitur
    int final_splitter;
    Grammar *grammar = final_sequitur(dg, &final_splitter);

    // 3. Generate a MPI program
    char source_file_path[256];
    sprintf(source_file_path, "%s/proxy_app.c", directory);
    FILE* f = fopen(source_file_path, "w");

    write_prologue(f, grammar, cst);

    experimental_code(f, grammar, cst, final_splitter);

    write_epilogue(f, gm.ranks, dg);


    free_vars_pool();
    free_decoded_grammars(dg);
    sequitur_cleanup(grammar);
    fclose(f);

    return 0;
}

