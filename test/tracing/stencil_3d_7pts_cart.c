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


int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);
    int rank, mpi_size;
    MPI_Comm comm = MPI_COMM_WORLD;
    MPI_Comm_rank(comm, &rank);
    MPI_Comm_size(comm, &mpi_size);
    int niters, bx, by, bz;

    if (rank==0) {
        // argument checking
        if(argc < 2) {
            if(!rank) printf("usage: stencil_mpi <niters>\n");
            MPI_Finalize();
            exit(1);
        }
        niters = atoi(argv[1]);   // number of iterations
    }
    MPI_Bcast(&niters, 1, MPI_INT, 0, comm);

    int dims[3] = {0, 0, 0};
    int periods[3] = {1, 1, 1};
    MPI_Comm cartcomm;
    MPI_Dims_create(mpi_size, 3, dims);
    MPI_Cart_create(MPI_COMM_WORLD, 3, dims, periods, 0, &cartcomm);

    bx = dims[0]*50;
    by = dims[1]*50;
    bz = dims[2]*50;

    int cart_rank;
    MPI_Comm_rank(cartcomm, &cart_rank);
    int coords[3];
    MPI_Cart_coords(cartcomm, cart_rank, 3, coords);

    int top[3] = {coords[0], coords[1], coords[2]+1};
    int bottom[3] = {coords[0], coords[1], coords[2]-1};
    int west[3] = {coords[0]-1, coords[1], coords[2]};
    int east[3] = {coords[0]+1, coords[1], coords[2]};
    int north[3] = {coords[0], coords[1]+1, coords[2]};
    int south[3] = {coords[0], coords[1]-1, coords[2]};

    int top_rank, bottom_rank, west_rank, east_rank, north_rank, south_rank;
    MPI_Cart_rank(cartcomm, top, &top_rank);
    MPI_Cart_rank(cartcomm, bottom, &bottom_rank);
    MPI_Cart_rank(cartcomm, west, &west_rank);
    MPI_Cart_rank(cartcomm, east, &east_rank);
    MPI_Cart_rank(cartcomm, north, &north_rank);
    MPI_Cart_rank(cartcomm, south, &south_rank);

    // printf("my rank: %d %d, coords: %d %d %d, top: %d, bottom: %d\n", rank, cart_rank, coords[0], coords[1], coords[2], top_rank, bottom_rank);

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
