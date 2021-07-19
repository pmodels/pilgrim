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

    int* data = malloc(sizeof(int) * 10);

    if( rank == 0) {
        for(int i = 0; i < 3; i++) {
            MPI_Comm_size(MPI_COMM_WORLD, &size);
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 5; k++) {
                    MPI_Send(data, 10, MPI_INT, 1, 123, MPI_COMM_WORLD);
                    MPI_Barrier(MPI_COMM_WORLD);
                }
            }
        }
    }
    if ( rank == 1) {
        for(int i = 0; i < 4; i++) {
            MPI_Comm_size(MPI_COMM_WORLD, &size);
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 5; k++) {
                    MPI_Recv(data, 10, MPI_INT, 0, 123, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    MPI_Barrier(MPI_COMM_WORLD);
                }
            }
        }
    }

    MPI_Finalize();
    return 0;
}
