/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank;
    int world_size;

    for(int i = 0; i < 10; i++) {
        /*
        for(int j = 0; j < 4; j++) {
            MPI_Comm_size(MPI_COMM_WORLD, &world_size);
            MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        }
        */
        MPI_Barrier(MPI_COMM_WORLD);
    }

    /*

    int data, data2, data3;
    MPI_Allreduce(&data, &data2, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    MPI_Allreduce(&data, &data3, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    int N = 3;
    int outcount;
    int indices[2];
    MPI_Request reqs[2];
    if(rank == 0) {
        for(int i = 0; i < N; i++) {
            MPI_Isend(&rank, 1, MPI_INT, 1, 999, MPI_COMM_WORLD, &(reqs[0]));
            MPI_Isend(&rank, 1, MPI_INT, 1, 999, MPI_COMM_WORLD, &(reqs[1]));
            MPI_Waitsome(2, reqs, &outcount, indices, MPI_STATUSES_IGNORE);
        }
    }

    if(rank == 1) {
        for(int i = 0; i < N; i++) {
            MPI_Recv(&data, 1, MPI_INT, MPI_ANY_SOURCE, 999, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Recv(&data, 1, MPI_INT, MPI_ANY_SOURCE, 999, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    }
    */

    MPI_Finalize();

    return 0;
}
