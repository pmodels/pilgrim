/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */
#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    void *p = malloc(sizeof(10));
    free(p);

    if(size >= 2) {
        if(rank == 0) {
            MPI_Request reqs[1];
            MPI_Isend(&rank, 1, MPI_INT, 1, 123, MPI_COMM_WORLD, &reqs[0]);
            MPI_Request old = reqs[0];
            MPI_Waitall(1, reqs, MPI_STATUSES_IGNORE);
            if(old == MPI_REQUEST_NULL)
                printf("Okay!\n");
        } else if(rank == 1) {
            int buf;
            MPI_Request reqs[1];
            MPI_Irecv(&buf, 1, MPI_INT, 0, 123, MPI_COMM_WORLD, &reqs[0]);
            MPI_Waitall(1, reqs, MPI_STATUSES_IGNORE);
        }
    }

    MPI_Finalize();
    return 0;
}
