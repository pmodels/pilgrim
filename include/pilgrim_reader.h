/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#ifndef _PILGRIM_READER_H_
#define _PILGRIM_READER_H_

#include "pilgrim_logger.h"

typedef struct CallSignature_t {
    short func_id;
    int arg_count;
    void **args;

    int* arg_sizes;         // size of each argument (in bytes)
    int* arg_types;
    int* arg_directions;
    int* arg_lengths;       // length of each array argument (-1 if not an array)

} CallSignature;


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

typedef struct DecodedGrammars_t {
    int num_grammars;               // number of unique grammars

    RuleHash** intra_cfgs;          // size of nprocs. for each unique grammar
    int **unique_grammars;          // decoded unique grammars

    int *num_symbols;               // number of symbols of each unique grammar
    int *grammar_ids;               // size of nprocs. each rank's grammar id
} DecodedGrammars;


void free_decoded_grammars(DecodedGrammars *dg);

#define TYPE_NON_MPI                    0
#define TYPE_MPI_Info                   1
#define TYPE_MPI_Datatype               2
#define TYPE_MPI_File                   3
#define TYPE_MPI_Win                    4
#define TYPE_MPI_Request                5
#define TYPE_MPI_Group                  6
#define TYPE_MPI_Op                     7
#define TYPE_MPI_Message                8
#define TYPE_MPI_Comm                   9
#define TYPE_MPI_Status                 10
#define TYPE_RANK_ENCODED               11
#define TYPE_TAG                        12
#define TYPE_MEM_PTR                    13
#define TYPE_INT                        14
#define TYPE_STRING                     15
#define TYPE_MPI_Errhandler             16
#define TYPE_MPI_Aint                   17
#define TYPE_MPI_Count                  18

#define TYPE_MPI_User_function                  19
#define TYPE_MPI_Copy_function                  20
#define TYPE_MPI_Delete_function                21
#define TYPE_MPI_Comm_copy_attr_function        22
#define TYPE_MPI_Comm_delete_attr_function      23
#define TYPE_MPI_Win_copy_attr_function         24
#define TYPE_MPI_Win_delete_attr_function       25
#define TYPE_MPI_Type_delete_attr_function      26
#define TYPE_MPI_Type_copy_attr_function        27
#define TYPE_MPI_Datarep_conversion_function    28
#define TYPE_MPI_Datarep_extent_function        29
#define TYPE_MPI_Grequest_query_function        30
#define TYPE_MPI_Grequest_free_function         31
#define TYPE_MPI_Grequest_cancel_function       32
#define TYPE_MPI_Comm_errhandler_function       33
#define TYPE_MPI_Win_errhandler_function        34
#define TYPE_MPI_File_errhandler_function       35



static char* TYPE_STR[] = {
    "NON_MPI",
    "MPI_Info",
    "MPI_Datatype",
    "MPI_File",
    "MPI_Win",
    "MPI_Request",
    "MPI_Group",
    "MPI_Op",
    "MPI_Message",
    "MPI_Comm",
    "MPI_Status",
    "MPI_RANK_ENCODED",
    "MPI_TAG",
    "void*",
    "int",
    "char*",
    "MPI_Errhandler",
    "MPI_Aint",
    "MPI_Count",
    "MPI_User_function",                // 19
    "MPI_Copy_function",
    "MPI_Delete_function",
    "MPI_Comm_copy_attr_function",
    "MPI_Comm_delete_attr_function",
    "MPI_Win_copy_attr_function",
    "MPI_Win_delete_attr_function",
    "MPI_Type_delete_attr_function",
    "MPI_Type_copy_attr_function",
    "MPI_Datarep_conversion_function",
    "MPI_Datarep_extent_function",
    "MPI_Grequest_query_function",
    "MPI_Grequest_free_function",
    "MPI_Grequest_cancel_function",
    "MPI_Comm_errhandler_function",
    "MPI_Win_errhandler_function",
    "MPI_File_errhandler_function",     // 35
};

static char* TYPE_VAR_STR[] = {
    "obj",
    "mpi_info",
    "mpi_datatype",
    "mpi_file",
    "mpi_win",
    "mpi_request",
    "mpi_group",
    "mpi_op",
    "mpi_message",
    "mpi_comm",
    "mpi_status",
    "",                     // RANK_ENCODED
    "",                     // TAG
    "buf",
    "var",                  // INT
    "str",                  // char* STRING
    "mpi_err_handler",
    "mpi_aint",
    "mpi_count",
    "mpi_user_function",                // 19
    "mpi_copy_function",
    "mpi_delete_function",
    "mpi_comm_copy_attr_function",
    "mpi_comm_delete_attr_function",
    "mpi_win_copy_attr_function",
    "mpi_win_delete_attr_function",
    "mpi_type_delete_attr_function",
    "mpi_type_copy_attr_function",
    "mpi_datarep_conversion_function",
    "mpi_datarep_extent_function",
    "mpi_grequest_query_function",
    "mpi_grequest_free_function",
    "mpi_grequest_cancel_function",
    "mpi_comm_errhandler_function",
    "mpi_win_errhandler_function",
    "mpi_file_errhandler_function",     // 35
};


#define DIRECTION_IN        0
#define DIRECTION_OUT       1
#define DIRECTION_INOUT     2


#define INIT_CALL_ARGS(cs, count)                                       \
    cs->arg_count      = count;                                         \
    cs->arg_sizes      = malloc(count * sizeof(int));                   \
    cs->arg_types      = malloc(count * sizeof(int));                   \
    cs->arg_lengths    = malloc(count * sizeof(int));                   \
    cs->arg_directions = malloc(count * sizeof(int));                   \
    cs->args           = malloc(count * sizeof(void*));                 \
    memset(cs->arg_types, TYPE_NON_MPI, count*sizeof(int));             \
    memset(cs->arg_sizes, 0, count*sizeof(int));                        \
    memset(cs->arg_directions, DIRECTION_IN, count*sizeof(int));        \
    memset(cs->arg_lengths, -1, count*sizeof(int));


DecodedGrammars* read_cfg(char* cfg_path, int nprocs);
CallSignature* read_cst(char* cst_path, int *num_sigs);
void read_metadata(char* metadata_path, GlobalMetadata *gm);

void read_record_args(int func_id, void* buff, CallSignature *cs);
void read_record_args_special(int func_id, void* buff, CallSignature *cs);

#endif
