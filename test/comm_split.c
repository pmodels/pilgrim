/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */
#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);
    MPI_Comm newcomm;
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Comm_split(MPI_COMM_WORLD, rank%2, rank, &newcomm);
    MPI_Finalize();
    return 0;
}
