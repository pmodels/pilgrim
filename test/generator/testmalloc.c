#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <mpi.h>

static int sbuf[1024];
static int rbuf[1024];

static int size, rank;

static int sendcounts[16];
static int sdispls[16];

static int recvcounts[16];
static int rdispls[16];

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm comm = MPI_COMM_WORLD;
    // many mallocs this call
    //MPI_Comm_dup(MPI_COMM_WORLD, &comm);

    MPI_Barrier(MPI_COMM_WORLD);
    if(rank == 0)
        fprintf(stderr, "\n\n\n\nCHEN==============\n\n\n\n");

    // 2 malloc per call per rank
    MPI_Alltoall(sbuf, 10, MPI_INT, rbuf, 10, MPI_INT, comm);

    if(rank == 0)
        fprintf(stderr, "\n\n\n\nCHEN==============\n\n\n\n");


    /*
    int c = 3;
    for(int i = 0; i < size; i++) {
        sendcounts[i] = c;
        sdispls[i] = c * i;
        recvcounts[i] = c;
        rdispls[i] = c * i;
    }
    */

    // 2 malloc per call per rank
    //MPI_Alltoallv(sbuf, sendcounts, sdispls, MPI_INT, rbuf, recvcounts, rdispls, MPI_INT, MPI_COMM_WORLD);

    // 2 malloc per call per rank
    //MPI_Allreduce(sbuf, rbuf, 1, MPI_INT, MPI_SUM, comm);


    /*
    if(rank % 2 == 0) {
        MPI_Send(sbuf, 10, MPI_INT, rank+1, 999, comm);
    } else {
        MPI_Request req;
        MPI_Irecv(rbuf, 10, MPI_INT, rank-1, 999, comm, &req);
        MPI_Wait(&req, MPI_STATUS_IGNORE);
    }
    */

    MPI_Finalize();
    return 0;
}
