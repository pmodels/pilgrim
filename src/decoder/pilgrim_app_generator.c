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

static int grammar_splitter = 10000000;

static int tmp_var_idx = 0;

typedef struct VariablePool_t {
    char* name;
    int symbolic_id;          // value (symbolic id in trace) as key
    UT_hash_handle hh;
} VariablePool;



#define NUM_VAR_TYPES 17
static VariablePool* variable_pools[NUM_VAR_TYPES];    // One variable pool for each variable type


void set_var_name(char* name, int type, int direction, int id_or_val) {
    if(type==TYPE_INT && direction == DIRECTION_IN)
        sprintf(name, "%d", id_or_val);
    else {
        if(direction == DIRECTION_IN) {
            if(id_or_val < 0)
                sprintf(name, "%s__%d", TYPE_VAR_STR[type], (-1)*id_or_val);
            else
                sprintf(name, "%s_%d", TYPE_VAR_STR[type], id_or_val);
        } else {
            if(id_or_val < 0)
                sprintf(name, "&%s__%d", TYPE_VAR_STR[type], (-1)*id_or_val);
            else
                sprintf(name, "&%s_%d", TYPE_VAR_STR[type], id_or_val);
        }
    }
}

bool is_mpi_user_function(int type) {
    if(type >= TYPE_MPI_User_function && type <= TYPE_MPI_File_errhandler_function)
        return true;
    return false;
}

VariablePool* var_find_or_add(int type, int symbolic_id, bool *exist) {
    *exist = true;
    VariablePool* var = NULL;
    HASH_FIND_INT(variable_pools[type], &symbolic_id, var);
    if(var == NULL) {
        *exist = false;
        var = malloc(sizeof(VariablePool));
        var->symbolic_id = symbolic_id;
        var->name = malloc(sizeof(64));
        if(symbolic_id < 0)
            sprintf(var->name, "%s__%d", TYPE_VAR_STR[type], (-1)*symbolic_id);
        else
            sprintf(var->name, "%s_%d", TYPE_VAR_STR[type], symbolic_id);
        HASH_ADD_INT(variable_pools[type], symbolic_id, var);
    }
    return var;
}


void free_vars_pool() {
    for(int i = 0; i < NUM_VAR_TYPES; i++) {
        VariablePool *var, *tmp;
        HASH_ITER(hh, variable_pools[i], var, tmp) {
            HASH_DEL(variable_pools[i], var);
            free(var->name);
            free(var);
        }
        variable_pools[i] = NULL;
    }
}

// use size_t for the last argument so it accomandates both int and MPI_Aint
void write_vars_declaration_core(FILE* f, int type, size_t id_or_val) {
    bool exist;
    VariablePool* var = var_find_or_add(type, id_or_val, &exist);
    if(!exist) {
        fprintf(f, "%s %s;\n", TYPE_STR[type], var->name);
    }
}

void write_vars_declaration(FILE* f, Grammar *grammar, CallSignature *cst) {
    CallSignature* cs;
    Symbol *rule, *sym;

    int max_str_len = -1;

    DL_FOREACH(grammar->rules, rule) {
        DL_FOREACH(rule->rule_body, sym) {
            if(sym->val < 0 || sym->val >= grammar_splitter)
                continue;
            cs = &(cst[sym->val]);

            for(int j = 0; j < cs->arg_count; j++) {
                int type = cs->arg_types[j];
                int dir = cs->arg_directions[j];

                if(type == TYPE_NON_MPI) {
                } else if(type == TYPE_MPI_Comm || type == TYPE_MPI_Datatype || type == TYPE_MPI_Op || type == TYPE_MPI_Errhandler) {
                    int id = *((int*)cs->args[j]);
                    if(id >= 0 || dir == DIRECTION_OUT)     // custom MPI object
                        write_vars_declaration_core(f, type, id);
                } else if(is_mpi_user_function(type)) {
                } else if(type == TYPE_MPI_Status) {
                } else if(type == TYPE_RANK_ENCODED) {
                } else if(type == TYPE_TAG) {
                } else if(type == TYPE_INT_ARRAY) {
                } else if(type == TYPE_MEM_PTR) {
                    MemPtrAttr* attr = (MemPtrAttr*) cs->args[j];
                    write_vars_declaration_core(f, type, attr->id);
                } else if(type == TYPE_STRING) {
                    if(dir == DIRECTION_OUT) {
                        int len = strlen((char*)cs->args[j]);
                        if(len > max_str_len)
                            max_str_len = len;
                    }
                } else {    // all types with interger values or MPI_Aint
                    size_t value;

                    value = *((int*)cs->args[j]);

                    if(type == TYPE_INT && dir == DIRECTION_IN)
                        continue;
                    write_vars_declaration_core(f, type, value);
                }
            }
        }
    }
    if(max_str_len > 0)
        fprintf(f, "char g_str[%d];\n", max_str_len+1);
    else
        fprintf(f, "char g_str[MPI_MAX_ERROR_STRING];\n");

    fprintf(f, "\n");
}


void write_vars_initialization(FILE* f, CallSignature *cs) {
    if(cs->func_id == ID_free)
        return;

    int arr_vars_count = 0;
    for(int i = 0; i < cs->arg_count; i++) {
        int type = cs->arg_types[i];
        if(type == TYPE_MEM_PTR) {
            MemPtrAttr* attr = (MemPtrAttr*) cs->args[i];
            fprintf(f, "\tif(!%s_%d) %s_%d = malloc(%lu);\n", TYPE_VAR_STR[TYPE_MEM_PTR], attr->id, TYPE_VAR_STR[TYPE_MEM_PTR], attr->id, attr->size);
        }
        if(type == TYPE_INT_ARRAY) {
            // only two mpi functions use 2D int[][3] arry
            if(cs->func_id == ID_MPI_Group_range_excl || cs->func_id == ID_MPI_Group_range_incl) {
                fprintf(f, "\t%s %s_%d[][3] = {", TYPE_STR[type], TYPE_VAR_STR[type], tmp_var_idx++);
                int n = cs->arg_sizes[i]/sizeof(int)/3;
                int *tmp = (int*) cs->args[i];
                int tmp_idx = 0;
                for(int j = 0; j < n; j++) {
                    fprintf(f, "{%d, ", tmp[tmp_idx++]);
                    fprintf(f, "%d, ", tmp[tmp_idx++]);
                    if(j != n - 1)
                        fprintf(f, "%d},", tmp[tmp_idx++]);
                    else
                        fprintf(f, "%d}};\n", tmp[tmp_idx++]);
                }
            } else {
                // all the rest use 1D array.
                fprintf(f, "\t%s %s_%d[] = {", TYPE_STR[type], TYPE_VAR_STR[type], tmp_var_idx++);
                int n = cs->arg_sizes[i]/sizeof(int);
                for(int j = 0; j < n-1; j++) {
                    int val = ((int*)cs->args[i])[j];
                    fprintf(f, "%d, ", val);
                }
                fprintf(f, "};\n");

            }
            arr_vars_count++;
        }
    }

    tmp_var_idx -= arr_vars_count;
}



char* write_argument(CallSignature *cs, int i) {
    int type = cs->arg_types[i];
    int direction = cs->arg_directions[i];

    char *name = calloc(sizeof(char), 128); // TODO longer argument name
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
        if(id < 0 && direction != DIRECTION_OUT)
            strcpy(name, symbolic_id_to_mpi_datatype_str(id));
        else
            set_var_name(name, type, direction, id);
    } else if(type == TYPE_MPI_Op) {
        int id = *((int*)cs->args[i]);
        if(id < 0 && direction != DIRECTION_OUT)
            strcpy(name, symbolic_id_to_mpi_op_str(id));
        else
            set_var_name(name, type, direction, id);
    } else if(type == TYPE_MPI_Errhandler) {
        int id = *((int*)cs->args[i]);
        if(id < 0 && direction != DIRECTION_OUT)
            strcpy(name, symbolic_id_to_mpi_errhandler_str(id));
        else
            set_var_name(name, type, direction, id);
    } else if(type == TYPE_MPI_Comm) {
        int id = *((int*)cs->args[i]);
        if(id < 0 && direction != DIRECTION_OUT)
            strcpy(name, symbolic_id_to_mpi_comm_str(id));
        else
            set_var_name(name, type, direction, id);
    } else if(is_mpi_user_function(type)) {
        strcpy(name, TYPE_VAR_STR[type]);
    } else if(type == TYPE_INT_ARRAY) {
        sprintf(name, "%s_%d", TYPE_VAR_STR[type], tmp_var_idx++);
    } else if(type == TYPE_STRING) {
        if(direction == DIRECTION_IN) {
            // Do not directly print \n in the string
            // TODO need to escape it, but this will increase string length
            char *tmp = (char*)cs->args[i];
            for(int k = 0; k < strlen(tmp)+1; k++) {
                if(tmp[k] == '\n')
                    tmp[k] = '|';
            }
            sprintf(name, "\"%s\"", (char*)cs->args[i]);
        } else {
            strcpy(name, "g_str");
        }
    } else {    // all other (basic data types or mpi objects) with integer values
        int value = *((int*)cs->args[i]);
        set_var_name(name, type, direction, value);
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
    if(cs->func_id == ID_free) {
        MemPtrAttr* attr = (MemPtrAttr*) cs->args[0];
        fprintf(f, "\tfree(%s_%d);\n\t%s_%d = NULL;\n", TYPE_VAR_STR[TYPE_MEM_PTR], attr->id, TYPE_VAR_STR[TYPE_MEM_PTR], attr->id);
    }
}


void write_call(FILE* f, CallSignature *cs, const char* indent) {
    if(cs->func_id == ID_MPI_Waitall || cs->func_id == ID_free) {
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

    fprintf(f, "void mpi_user_function(void* in, void* out, int* len, MPI_Datatype* type) {}\n");
    fprintf(f, "void mpi_comm_errhandler_function(MPI_Comm* comm, int* err, ...) {}\n");
    fprintf(f, "MPI_Copy_function* mpi_copy_function = MPI_NULL_COPY_FN;\n");
    fprintf(f, "MPI_Delete_function* mpi_delete_function = MPI_NULL_DELETE_FN;\n");
    fprintf(f, "MPI_Comm_copy_attr_function* mpi_comm_copy_attr_function = MPI_COMM_NULL_COPY_FN;\n");
    fprintf(f, "MPI_Comm_delete_attr_function* mpi_comm_delete_attr_function = MPI_COMM_NULL_DELETE_FN;\n");
    fprintf(f, "MPI_Type_copy_attr_function* mpi_type_copy_attr_function = MPI_TYPE_NULL_COPY_FN;\n");
    fprintf(f, "MPI_Type_delete_attr_function* mpi_type_delete_attr_function = MPI_TYPE_NULL_DELETE_FN;\n");
    fprintf(f, "MPI_Win_copy_attr_function* mpi_win_copy_attr_function = MPI_WIN_NULL_COPY_FN;\n");
    fprintf(f, "MPI_Win_delete_attr_function* mpi_win_delete_attr_function = MPI_WIN_NULL_DELETE_FN;\n");

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
    //sequitur_print_rules(grammar);
    *final_splitter = splitter;

    return grammar;
}

void handle_one_symbol(FILE* f, Symbol* sym, CallSignature* cst) {

    CallSignature *cs = &cst[sym->val];

    if(sym->val >= 0)
        write_vars_initialization(f, cs);

    if(sym->exp > 1)
        fprintf(f, "\tfor(int i = 0; i < %d; i++)\n", sym->exp);
    if(sym->val >= 0) {
        CallSignature *cs = &cst[sym->val];
        //printf("%s\n", func_names[cs->func_id]);
        write_call(f, cs, sym->exp>1?"\t\t":"\t");
    } else {
        fprintf(f, "\t%sfunc_%d();\n", sym->exp>1?"\t":"", -1*sym->val);
    }
}

void one_func_per_rule(FILE* f, Grammar* grammar, CallSignature *cst, int final_splitter) {

    Symbol *rule, *sym;
    DL_FOREACH(grammar->rules, rule) {
        fprintf(f, "void func_%d();\n", -1*rule->val);
    }
    fprintf(f, "\n");

    DL_FOREACH(grammar->rules, rule) {
        fprintf(f, "void func_%d() {\n", -1*rule->val);

        if(rule->val == -1)
            fprintf(f, "\tif(g_ugi == 0) {\n");

        DL_FOREACH(rule->rule_body, sym) {
            if(sym->val < grammar_splitter) {
                handle_one_symbol(f, sym, cst);
            } else {
                // This code is only executed for rule -1
                if(sym->val == final_splitter - 1)
                    fprintf(f, "\t}\n");
                else
                    fprintf(f, "\t}\n\tif(g_ugi == %d) {\n", sym->val - grammar_splitter + 1);
            }
        }


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

    one_func_per_rule(f, grammar, cst, final_splitter);

    write_epilogue(f, gm.ranks, dg);

    free_vars_pool();

    sequitur_cleanup(grammar);
    fclose(f);

    free_decoded_grammars(dg);
    // TODO free cst?

    return 0;
}

