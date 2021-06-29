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

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    assert(size >= 2);
    int* data = malloc(sizeof(int)*3);


    if(rank % 2 == 0) { // g_mpi_rank = size-1;
        for(int i = 0; i < 3; i++)
            MPI_Send(data, 3, MPI_INT, rank+1, 123, MPI_COMM_WORLD);
    }
    else {
        for(int i = 0; i < 3; i++)
            MPI_Recv(data, 3, MPI_INT, rank-1, 123, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    free(data);
    MPI_Finalize();
    return 0;
}
