/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <mpi.h>

void myfunc(void* in, void* out, int* len, MPI_Datatype *dtype) {
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;

    MPI_Comm dupcomm = MPI_COMM_WORLD;
    MPI_Comm splitcomm = MPI_COMM_WORLD;

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Datatype subarray;
    int array_size[2] = { 3, 3 };
    int array_subsize[2] = { 2, 2 };
    int array_start[2] = { 1, 1 };
    MPI_Type_create_subarray(2, array_size, array_subsize, array_start, MPI_ORDER_C, MPI_INT, &subarray);
    MPI_Type_commit(&subarray);
    MPI_Type_free(&subarray);

    MPI_Op op;
    MPI_Op_create(myfunc, 1, &op);

    MPI_Group group, newgroup;
    MPI_Comm_group(MPI_COMM_WORLD, &group);
    int ranges[][3] = {0, size-1, 2};
    MPI_Group_range_excl(group, 1, ranges, &newgroup);
    int group_size;
    MPI_Group_size(newgroup, &group_size);
    MPI_Group_free(&newgroup);

    MPI_Comm_dup(MPI_COMM_WORLD, &dupcomm);
    MPI_Comm_split(MPI_COMM_WORLD, rank < 2, 1, &splitcomm);
    assert(size >= 2);

    int* data;
    if(rank == 0) {
        data = malloc(sizeof(int)*3);
        for(int i = 0; i < 3;i ++)
            MPI_Send(data, 3, MPI_INT, 1, 123, splitcomm);
        free(data);
    } else if(rank == 1) {
        data = malloc(sizeof(int)*5);
        for(int i = 0; i < 3;i ++)
            MPI_Recv(&(data[2]), 3, MPI_INT, 0, 123, splitcomm, MPI_STATUS_IGNORE);
        free(data);
    } else {
        for(int i = 0; i < 10;i ++)
            MPI_Comm_size(dupcomm, &size);
    }


    MPI_Comm_free(&dupcomm);
    MPI_Comm_free(&splitcomm);

    MPI_Finalize();
    return 0;
}
