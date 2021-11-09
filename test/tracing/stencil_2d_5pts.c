/*
 * Copyright (c) 2012 Torsten Hoefler. All rights reserved.
 *
 * Author(s): Torsten Hoefler <htor@illinois.edu>
 *
 */

#include "mpi.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// row-major order
#define ind(i,j) (j)*(bx+2)+(i)
#define TAG 10000

int main(int argc, char **argv) {

    MPI_Init(&argc, &argv);
    int r,p;
    MPI_Comm comm = MPI_COMM_WORLD;
    MPI_Comm_rank(comm, &r);
    MPI_Comm_size(comm, &p);
    int n, energy, niters, px, py;
    int *args = malloc(sizeof(int)*5);

    if (r==0) {
        // argument checking
        if(argc < 4) {
            if(!r) printf("usage: stencil_mpi <px> <py> <niters>\n");
            MPI_Finalize();
            exit(1);
        }

        px=atoi(argv[1]);         // 1st dim processes
        py=atoi(argv[2]);         // 2nd dim processes
        niters = atoi(argv[3]);   // number of iterations
        energy = 1;               // energy to be injected

        n = 50*py;
        if((py % px !=0) || (px*py != p))
            MPI_Abort(comm, 0);

        // distribute arguments
        args[0] = n; args[1] = energy; args[2] = niters; args[3] = px; args[4] = py;
        //int args[5] = {n, energy, niters, px,  py};
        MPI_Bcast(args, 5, MPI_INT, 0, comm);
    }
    else {
        MPI_Bcast(args, 5, MPI_INT, 0, comm);
        n=args[0]; energy=args[1]; niters=args[2]; px=args[3]; py=args[4];
    }

    // determine my coordinates (x,y) -- r=x*a+y in the 2d processor array
    int rx = r % px;
    int ry = r / px;
    // determine my four neighbors
    int north = (ry-1)*px+rx; if(ry-1 < 0)   north = MPI_PROC_NULL;
    int south = (ry+1)*px+rx; if(ry+1 >= py) south = MPI_PROC_NULL;
    int west= ry*px+rx-1;     if(rx-1 < 0)   west = MPI_PROC_NULL;
    int east = ry*px+rx+1;    if(rx+1 >= px) east = MPI_PROC_NULL;
    // decompose the domain
    int bx = n/px; // block size in x
    int by = n/py; // block size in y
    int offx = rx*bx; // offset in x
    int offy = ry*by; // offset in y

    //printf("%i (%i,%i) - w: %i, e: %i, n: %i, s: %i\n", r, ry,rx,west,east,north,south);

    // allocate two work arrays
    double *aold = (double*)calloc(1,(bx+2)*(by+2)*sizeof(double)); // 1-wide halo zones!
    double *anew = (double*)calloc(1,(bx+2)*(by+2)*sizeof(double)); // 1-wide halo zones!
    double *tmp;

    // initialize three heat sources
#define nsources 3
    int sources[nsources][2] = {{n/2,n/2}, {n/3,n/3}, {n*4/5,n*8/9}};
    int locnsources=0; // number of sources in my area
    int locsources[nsources][2]; // sources local to my rank
    for (int i=0; i<nsources; ++i) { // determine which sources are in my patch
        int locx = sources[i][0] - offx;
        int locy = sources[i][1] - offy;
        if(locx >= 0 && locx < bx && locy >= 0 && locy < by) {
            locsources[locnsources][0] = locx+1; // offset by halo zone
            locsources[locnsources][1] = locy+1; // offset by halo zone
            locnsources++;
        }
    }

    double t=-MPI_Wtime(); // take time
    // allocate communication buffers
    double *sbufnorth = (double*)calloc(1,bx*sizeof(double)); // send buffers
    double *sbufsouth = (double*)calloc(1,bx*sizeof(double));
    double *sbufeast = (double*)calloc(1,by*sizeof(double));
    double *sbufwest = (double*)calloc(1,by*sizeof(double));
    double *rbufnorth = (double*)calloc(1,bx*sizeof(double)); // receive buffers
    double *rbufsouth = (double*)calloc(1,bx*sizeof(double));
    double *rbufeast = (double*)calloc(1,by*sizeof(double));
    double *rbufwest = (double*)calloc(1,by*sizeof(double));

    double heat; // total heat in system
    for(int iter=0; iter<niters; ++iter) {
        // refresh heat sources
        for(int i=0; i<locnsources; ++i) {
            aold[ind(locsources[i][0],locsources[i][1])] += energy; // heat source
        }

        // exchange data with neighbors
        MPI_Request reqs[8];
        for(int i=0; i<bx; ++i) sbufnorth[i] = aold[ind(i+1,1)];        // pack loop - last valid region
        for(int i=0; i<bx; ++i) sbufsouth[i] = aold[ind(i+1,by)];       // pack loop
        for(int i=0; i<by; ++i) sbufeast[i] = aold[ind(bx,i+1)];        // pack loop
        for(int i=0; i<by; ++i) sbufwest[i] = aold[ind(1,i+1)];         // pack loop
        MPI_Isend(sbufnorth, bx, MPI_DOUBLE, north, TAG, comm, &reqs[0]);
        MPI_Isend(sbufsouth, bx, MPI_DOUBLE, south, TAG, comm, &reqs[1]);
        MPI_Isend(sbufeast, by, MPI_DOUBLE, east, TAG, comm, &reqs[2]);
        MPI_Isend(sbufwest, by, MPI_DOUBLE, west, TAG, comm, &reqs[3]);
        MPI_Irecv(rbufnorth, bx, MPI_DOUBLE, north, MPI_ANY_TAG, comm, &reqs[4]);
        MPI_Irecv(rbufsouth, bx, MPI_DOUBLE, south, MPI_ANY_TAG, comm, &reqs[5]);
        MPI_Irecv(rbufeast, by, MPI_DOUBLE, east, MPI_ANY_TAG, comm, &reqs[6]);
        MPI_Irecv(rbufwest, by, MPI_DOUBLE, west, MPI_ANY_TAG, comm, &reqs[7]);
        MPI_Waitall(8, reqs, MPI_STATUSES_IGNORE);
        for(int i=0; i<bx; ++i) aold[ind(i+1,0)] = rbufnorth[i];        // unpack loop - into ghost cells
        for(int i=0; i<bx; ++i) aold[ind(i+1,by+1)] = rbufsouth[i];     // unpack loop
        for(int i=0; i<by; ++i) aold[ind(bx+1,i+1)] = rbufeast[i];      // unpack loop
        for(int i=0; i<by; ++i) aold[ind(0,i+1)] = rbufwest[i];         // unpack loop

        // update grid points
        heat = 0.0;
        for(int j=1; j<by+1; ++j) {
            for(int i=1; i<bx+1; ++i) {
                anew[ind(i,j)] = aold[ind(i,j)]/2.0 + (aold[ind(i-1,j)] + aold[ind(i+1,j)] + aold[ind(i,j-1)] + aold[ind(i,j+1)])/4.0/2.0;
                heat += anew[ind(i,j)];
            }
        }

        // swap arrays
        tmp=anew; anew=aold; aold=tmp;
    }
    t+=MPI_Wtime();

    // get final heat in the system
    double *rheat = malloc(sizeof(double));
    double *sheat = malloc(sizeof(double));
    *sheat = heat;
    MPI_Allreduce(sheat, rheat, 1, MPI_DOUBLE, MPI_SUM, comm);
    if(!r) printf("[%i] last heat: %f time: %f\n", r, *rheat, t);
    free(sheat);
    free(rheat);
    free(args);

    free(sbufnorth);
    free(sbufsouth);
    free(sbufwest);
    free(sbufeast);
    free(rbufnorth);
    free(rbufsouth);
    free(rbufwest);
    free(rbufeast);
    free(aold);
    free(anew);

    MPI_Finalize();
}
