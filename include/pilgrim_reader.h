/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#ifndef _PILGRIM_READER_H_
#define _PILGRIM_READER_H_
//#include <ctype.h>

typedef struct CallSignature_t {
    short func_id;
    int arg_count;
    void **args;

    int* arg_sizes;
    int* arg_types;
    int* arg_directions;

} CallSignature;

#define TYPE_NON_MPI        0
#define TYPE_MPI_Info       1
#define TYPE_MPI_Datatype   2
#define TYPE_MPI_File       3
#define TYPE_MPI_Win        4
#define TYPE_MPI_Request    5
#define TYPE_MPI_Group      6
#define TYPE_MPI_Op         7
#define TYPE_MPI_Message    8
#define TYPE_MPI_Comm       9
#define TYPE_MPI_Status     10
#define TYPE_RANK_ENCODED   11
#define TYPE_MEM_PTR        12
#define TYPE_INT            13

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
    "void*",
    "int",
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
    "",
    "buf",
    "var",
};


#define DIRECTION_IN        0
#define DIRECTION_OUT       1
#define DIRECTION_INOUT     2


int** read_cfg(char* cfg_path, int nprocs, int* num_symbols);
CallSignature* read_cst(char* cst_path, int *num_sigs);
void read_metadata(char* metadata_path, GlobalMetadata *gm);

void read_record_args(int func_id, void* buff, CallSignature *cs);
void read_record_args_special(int func_id, void* buff, CallSignature *cs);

#endif

