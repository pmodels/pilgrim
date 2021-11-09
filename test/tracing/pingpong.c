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

    assert(argc == 2);  // pingpong.out $iters
    assert(size % 2 == 0);
    int half = size / 2;
    int iters = 100;

    if(rank == 0)
        iters = atoi(argv[1]);
    MPI_Bcast(&iters, 1, MPI_INT, 0, MPI_COMM_WORLD);


    int *data = malloc(1024*1024);

    for(int i = 0; i < 100; i++) {
        MPI_Request req;
        if(rank < half) {
            MPI_Isend(data, 1, MPI_INT, rank+half, 123, MPI_COMM_WORLD, &req);
            MPI_Wait(&req, MPI_STATUS_IGNORE);
        } else {
            MPI_Irecv(data, 1, MPI_INT, rank-half, 123, MPI_COMM_WORLD, &req);
            MPI_Wait(&req, MPI_STATUS_IGNORE);
        }
    }

    free(data);

    MPI_Finalize();
    return 0;
}
