/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include <stdio.h>
#include "mpi.h"
/*
 * Group 0 and Group 2 have one inter-communicator
 * Group 1 has two inter-communicators
 *  _________          _________          _________
 * |         |        |         |        |         |
 * | Group 0 | <----> | Group 1 | <----> | Group 2 |
 * |_________|        |_________|        |_________|
 *
 */
int main(int argc, char **argv)
{
    MPI_Comm   myComm;       /* intra-communicator of local sub-group */
    MPI_Comm   myFirstComm;  /* inter-communicator */
    int membershipKey;
    int rank;
    int data = 999;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    /* User code must generate membershipKey in the range [0, 1, 2] */
    membershipKey = rank % 3;

    /* Build intra-communicator for local sub-group */
    MPI_Comm_split(MPI_COMM_WORLD, membershipKey, rank, &myComm);

    /* Build inter-communicators.  Tags are hard-coded. */
    if (membershipKey == 0)
    {
        MPI_Intercomm_create( myComm, 0, MPI_COMM_WORLD, 1, 1, &myFirstComm);
        MPI_Comm_rank(myComm, &rank);
        // I am the local leader
        if(rank == 0) {
            MPI_Send(&data, 1, MPI_INT, 0, 1, myFirstComm);
        }
    }
    else if (membershipKey == 1)
    {
        MPI_Intercomm_create( myComm, 0, MPI_COMM_WORLD, 0, 1, &myFirstComm);
        MPI_Comm_rank(myComm, &rank);
        // I am the local leader
        if(rank == 0) {
            MPI_Recv(&data, 1, MPI_INT, 0, 1, myFirstComm, MPI_STATUS_IGNORE);
        }
    }
    else if (membershipKey == 2)
    {
        // pass
    }



    /* Do work ... */

    if(membershipKey <= 1)
        MPI_Comm_free(&myFirstComm);
    MPI_Finalize();
}
