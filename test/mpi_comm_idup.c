/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int rank, flag;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm newcomm = MPI_COMM_NULL;
    MPI_Request req;

    MPI_Comm_idup(MPI_COMM_WORLD, &newcomm, &req);
    printf("%d\n", req == MPI_REQUEST_NULL);

    MPI_Test(&req, &flag, MPI_STATUS_IGNORE);
    printf("%d, %d\n", flag, req == MPI_REQUEST_NULL);

    MPI_Finalize();
    return 0;
}
