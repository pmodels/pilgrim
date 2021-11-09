/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    int rank;
    int world_size;

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int N = sqrt(world_size);   // NxN grid
    // int niters = atoi(argv[2]);
    int niters = 1;

    int i = rank / N;
    int j = rank % N;

    int sbuf, rbuf;
    MPI_Request reqs[2];

    int iter;
    int transpose_rank;
    for(iter = 0; iter < niters; iter++) {
        transpose_rank = j * N + i;

        //if(iter == 0)
        //    printf("rank: %d, i: %d, j: %d, transpose rank: %d\n", rank, i, j, transpose_rank);

        int a = 3; int b = 1;
        MPI_Isend(&sbuf, 1, MPI_INT, rank, a*rank+b, MPI_COMM_WORLD, &(reqs[0]));
        MPI_Irecv(&rbuf, 1, MPI_INT, rank, a*rank+b, MPI_COMM_WORLD, &(reqs[1]));
        MPI_Waitall(2, reqs, MPI_STATUSES_IGNORE);
    }

    MPI_Finalize();
    return 0;
}
