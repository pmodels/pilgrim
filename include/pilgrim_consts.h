#ifndef _PILGRIM_CONSTS_H_
#define _PILGRIM_CONSTS_H_

#include <assert.h>
#include <mpi.h>

#define PILGRIM_INVALID_MPI_OBJECT_ID   -9999

#define PILGRIM_CUSTOM_MPI_DATATYPE_ID  -9998
#define PILGRIM_CUSTOM_MPI_COMM_ID      -9997
#define PILGRIM_CUSTOM_MPI_OP_ID        -9996

#define PILGRIM_MPI_COMM_NULL_ID        -9995
#define PILGRIM_MPI_COMM_WORLD_ID       -9994
#define PILGRIM_MPI_COMM_SELF_ID        -9993

MPI_Datatype builtin_mpi_datatypes[] = {
    MPI_DATATYPE_NULL,
    MPI_CHAR,
    MPI_UNSIGNED_CHAR,
    MPI_SHORT,
    MPI_UNSIGNED_SHORT,
    MPI_INT,
    MPI_UNSIGNED,
    MPI_LONG,
    MPI_UNSIGNED_LONG,
    MPI_LONG_LONG,
    MPI_FLOAT,
    MPI_DOUBLE,
    MPI_LONG_DOUBLE,
    MPI_BYTE,
    MPI_WCHAR,
    MPI_PACKED,
    MPI_LB,
    MPI_UB,
    MPI_C_COMPLEX,
    MPI_C_DOUBLE_COMPLEX,
    MPI_C_LONG_DOUBLE_COMPLEX,
    MPI_2INT,
    MPI_C_BOOL,
    MPI_SIGNED_CHAR,
    MPI_CHARACTER,
    MPI_INTEGER,
    MPI_REAL,
    MPI_LOGICAL,
    MPI_COMPLEX,
    MPI_2INTEGER,
    MPI_2REAL,
    MPI_DOUBLE_COMPLEX,
    MPI_REAL4,
    MPI_COMPLEX8,
    MPI_REAL8,
    MPI_COMPLEX16,
    MPI_REAL16,
    MPI_COMPLEX32,
    MPI_INTEGER1,
    MPI_INTEGER2,
    MPI_INTEGER4,
    MPI_INTEGER8,
    MPI_INT8_T,
    MPI_INT16_T,
    MPI_INT32_T,
    MPI_INT64_T,
    MPI_UINT8_T,
    MPI_UINT16_T,
    MPI_UINT32_T,
    MPI_UINT64_T,
    MPI_AINT,
    MPI_FLOAT_INT,
    MPI_DOUBLE_INT,
    MPI_LONG_INT,
    MPI_SHORT_INT,
    MPI_LONG_DOUBLE_INT,
};

char* builtin_mpi_datatypes_str[] = {
    "MPI_DATATYPE_NULL",
    "MPI_CHAR",
    "MPI_UNSIGNED_CHAR",
    "MPI_SHORT",
    "MPI_UNSIGNED_SHORT",
    "MPI_INT",
    "MPI_UNSIGNED",
    "MPI_LONG",
    "MPI_UNSIGNED_LONG",
    "MPI_LONG_LONG",
    "MPI_FLOAT",
    "MPI_DOUBLE",
    "MPI_LONG_DOUBLE",
    "MPI_BYTE",
    "MPI_WCHAR",
    "MPI_PACKED",
    "MPI_LB",
    "MPI_UB",
    "MPI_C_COMPLEX",
    "MPI_C_DOUBLE_COMPLEX",
    "MPI_C_LONG_DOUBLE_COMPLEX",
    "MPI_2INT",
    "MPI_C_BOOL",
    "MPI_SIGNED_CHAR",
    "MPI_CHARACTER",
    "MPI_INTEGER",
    "MPI_REAL",
    "MPI_LOGICAL",
    "MPI_COMPLEX",
    "MPI_2INTEGER",
    "MPI_2REAL",
    "MPI_DOUBLE_COMPLEX",
    "MPI_REAL4",
    "MPI_COMPLEX8",
    "MPI_REAL8",
    "MPI_COMPLEX16",
    "MPI_REAL16",
    "MPI_COMPLEX32",
    "MPI_INTEGER1",
    "MPI_INTEGER2",
    "MPI_INTEGER4",
    "MPI_INTEGER8",
    "MPI_INT8_T",
    "MPI_INT16_T",
    "MPI_INT32_T",
    "MPI_INT64_T",
    "MPI_UINT8_T",
    "MPI_UINT16_T",
    "MPI_UINT32_T",
    "MPI_UINT64_T",
    "MPI_AINT",
    "MPI_FLOAT_INT",
    "MPI_DOUBLE_INT",
    "MPI_LONG_INT",
    "MPI_SHORT_INT",
    "MPI_LONG_DOUBLE_INT",
};

MPI_Op builtin_mpi_ops[] = {
    MPI_OP_NULL,
    MPI_MAX,
    MPI_MIN,
    MPI_SUM,
    MPI_PROD,
    MPI_LAND,
    MPI_BAND,
    MPI_LOR,
    MPI_BOR,
    MPI_LXOR,
    MPI_BXOR,
    MPI_MINLOC,
    MPI_MAXLOC,
    MPI_REPLACE
};

char* builtin_mpi_ops_str[] = {
    "MPI_OP_NULL",
    "MPI_MAX",
    "MPI_MIN",
    "MPI_SUM",
    "MPI_PROD",
    "MPI_LAND",
    "MPI_BAND",
    "MPI_LOR",
    "MPI_BOR",
    "MPI_LXOR",
    "MPI_BXOR",
    "MPI_MINLOC",
    "MPI_MAXLOC",
    "MPI_REPLACE"
};



// Guarantee that built-in MPI datatype will have an negative
// symbolic id. So in the app generator, we can recover the original
// MPI_Datatype
static int mpi_datatype_to_symbolic_id(const void* type_p) {
    MPI_Datatype datatype = *((MPI_Datatype*)type_p);
    for(int i = 0; i < sizeof(builtin_mpi_datatypes)/sizeof(MPI_Datatype); i++) {
        if(builtin_mpi_datatypes[i] == datatype)
            return -1 * i;
    }
    return PILGRIM_CUSTOM_MPI_DATATYPE_ID;
}


static char* symbolic_id_to_mpi_datatype_str(int id) {
    assert(id < 0 && id!=PILGRIM_CUSTOM_MPI_DATATYPE_ID);
    return builtin_mpi_datatypes_str[-id];
}

static int mpi_op_to_symbolic_id(const void* op_p) {
    MPI_Op op = *((MPI_Op*)op_p);
    for(int i = 0; i < sizeof(builtin_mpi_ops)/sizeof(MPI_Op); i++) {
        if(builtin_mpi_ops[i] == op)
            return -1 * i;
    }
    return PILGRIM_CUSTOM_MPI_OP_ID;
}


static char* symbolic_id_to_mpi_op_str(int id) {
    assert(id < 0 && id!=PILGRIM_CUSTOM_MPI_OP_ID);
    return builtin_mpi_ops_str[-id];
}


static int mpi_comm_to_symbolic_id(MPI_Comm *comm) {
    if(comm==NULL || *comm == MPI_COMM_NULL)
        return PILGRIM_MPI_COMM_NULL_ID;
    if(*comm == MPI_COMM_WORLD)
        return PILGRIM_MPI_COMM_WORLD_ID;
    if(*comm == MPI_COMM_SELF)
        return PILGRIM_MPI_COMM_SELF_ID;
    return PILGRIM_CUSTOM_MPI_COMM_ID;
}

static char* symbolic_id_to_mpi_comm_str(int id) {
    assert(id != PILGRIM_CUSTOM_MPI_COMM_ID && id < 0);
    if(id == PILGRIM_MPI_COMM_NULL_ID)
        return "MPI_COMM_NULL";
    if(id == PILGRIM_MPI_COMM_WORLD_ID)
        return "MPI_COMM_WORLD";
    if(id == PILGRIM_MPI_COMM_SELF_ID)
        return "MPI_COMM_SELF";
    return "MPI_COMM_WORLD";
}


#endif
