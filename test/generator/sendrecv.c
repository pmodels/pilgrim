/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <mpi.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    assert(size >= 2);

    int* data;
    if(rank == 0) {
        data = malloc(sizeof(int)*3);
        for(int i = 0; i < 3;i ++)
            MPI_Send(data, 3, MPI_INT, 1, 123, MPI_COMM_WORLD);
        free(data);
    }
    else if(rank == 1) {
        data = malloc(sizeof(int)*5);
        for(int i = 0; i < 3;i ++)
            MPI_Recv(&(data[2]), 3, MPI_INT, 0, 123, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        free(data);
    } else {
        for(int i = 0; i < 10;i ++)
            MPI_Comm_size(MPI_COMM_WORLD, &size);
    }


    MPI_Finalize();
    return 0;
}
