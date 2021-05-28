/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "mpi.h"

int mpi_rank, mpi_size;

void rank2coor(int rank, int p, int *x, int *y, int *z) {
    *z = rank / (p*p);
    int res = rank % (p*p);
    *y = res / p;
    *x = res % p;
}

void coor2rank(int p, int x, int y, int z, int *rank) {
    // periodic
    x = (x+p) %p;
    y = (y+p) %p;
    z = (z+p) %p;
    *rank = z*(p*p) + p*y + x;
}

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);
    MPI_Comm comm = MPI_COMM_WORLD;
    MPI_Comm_rank(comm, &mpi_rank);
    MPI_Comm_size(comm, &mpi_size);
    int niters, p, bx, by, bz;

    // Assume p is the cube root of the number of processes
    if (mpi_rank==0) {
        // argument checking
        if(argc < 3) {
            if(!mpi_rank) printf("usage: stencil_mpi <p> <niters>\n");
            MPI_Finalize();
            exit(1);
        }
        p = atoi(argv[1]);
        niters = atoi(argv[2]);   // number of iterations
    }
    MPI_Bcast(&niters, 1, MPI_INT, 0, comm);
    MPI_Bcast(&p, 1, MPI_INT, 0, comm);

    bx = p*50;
    by = p*50;
    bz = p*50;

    // my coor
    int x, y, z;
    rank2coor(mpi_rank, p, &x, &y, &z);

    // Get my neighbors rank
    int top_rank, bottom_rank, west_rank, east_rank, north_rank, south_rank;
    coor2rank(p, x, y, z+1, &top_rank);
    coor2rank(p, x, y, z-1, &bottom_rank);
    coor2rank(p, x-1, y, z, &west_rank);
    coor2rank(p, x+1, y, z, &east_rank);
    coor2rank(p, x, y+1, z, &north_rank);
    coor2rank(p, x, y-1, z, &south_rank);

    // allocate communication buffers
    double *sbufnorth = (double*)calloc(1,bx*sizeof(double)); // send buffers
    double *sbufsouth = (double*)calloc(1,bx*sizeof(double));
    double *sbufeast = (double*)calloc(1,by*sizeof(double));
    double *sbufwest = (double*)calloc(1,by*sizeof(double));
    double *sbuftop = (double*)calloc(1,bz*sizeof(double));
    double *sbufbottom = (double*)calloc(1,bz*sizeof(double));

    double *rbufnorth = (double*)calloc(1,bx*sizeof(double)); // receive buffers
    double *rbufsouth = (double*)calloc(1,bx*sizeof(double));
    double *rbufeast = (double*)calloc(1,by*sizeof(double));
    double *rbufwest = (double*)calloc(1,by*sizeof(double));
    double *rbuftop = (double*)calloc(1,bz*sizeof(double));
    double *rbufbottom = (double*)calloc(1,bz*sizeof(double));

    int iter;
    for(iter=0; iter<niters; ++iter) {
        // Computation...

        // exchange data with neighbors
        MPI_Request reqs[12];

        MPI_Isend(sbufnorth, bx, MPI_DOUBLE, north_rank, 9, comm, &reqs[0]);
        MPI_Isend(sbufsouth, bx, MPI_DOUBLE, south_rank, 9, comm, &reqs[1]);
        MPI_Isend(sbufeast, by, MPI_DOUBLE, east_rank, 9, comm, &reqs[2]);
        MPI_Isend(sbufwest, by, MPI_DOUBLE, west_rank, 9, comm, &reqs[3]);
        MPI_Isend(sbuftop, by, MPI_DOUBLE, top_rank, 9, comm, &reqs[4]);
        MPI_Isend(sbufbottom, by, MPI_DOUBLE, bottom_rank, 9, comm, &reqs[5]);

        MPI_Irecv(rbufnorth, bx, MPI_DOUBLE, north_rank, 9, comm, &reqs[6]);
        MPI_Irecv(rbufsouth, bx, MPI_DOUBLE, south_rank, 9, comm, &reqs[7]);
        MPI_Irecv(rbufeast, by, MPI_DOUBLE, east_rank, 9, comm, &reqs[8]);
        MPI_Irecv(rbufwest, by, MPI_DOUBLE, west_rank, 9, comm, &reqs[9]);
        MPI_Irecv(rbuftop, by, MPI_DOUBLE, top_rank, 9, comm, &reqs[10]);
        MPI_Irecv(rbufbottom, by, MPI_DOUBLE, bottom_rank, 9, comm, &reqs[11]);

        MPI_Waitall(12, reqs, MPI_STATUSES_IGNORE);
    }

    MPI_Finalize();
}
