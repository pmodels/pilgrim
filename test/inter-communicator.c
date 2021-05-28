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
     MPI_Comm   mySecondComm; /* second inter-communicator (group 1 only) */
     int membershipKey;
     int rank;

     MPI_Init(&argc, &argv);
     MPI_Comm_rank(MPI_COMM_WORLD, &rank);

     /* User code must generate membershipKey in the range [0, 1, 2] */
     membershipKey = rank % 3;

     int new_rank;
     /* Build intra-communicator for local sub-group */
     MPI_Comm_split(MPI_COMM_WORLD, membershipKey, rank, &myComm);

     /* Build inter-communicators.  Tags are hard-coded. */
     if (membershipKey == 0)
     {                     /* Group 0 communicates with group 1. */
       MPI_Intercomm_create( myComm, 0, MPI_COMM_WORLD, 1,
                            1, &myFirstComm);
        MPI_Comm_size(myFirstComm, &new_rank);
        printf("Group 0: new rank: %d\n", new_rank);
     }
     else if (membershipKey == 1)
     {              /* Group 1 communicates with groups 0 and 2. */
       MPI_Intercomm_create( myComm, 0, MPI_COMM_WORLD, 0,
                            1, &myFirstComm);
       MPI_Intercomm_create( myComm, 0, MPI_COMM_WORLD, 2,
                            12, &mySecondComm);
        MPI_Comm_size(myFirstComm, &new_rank);
        printf("Group 1.1: new rank: %d\n", new_rank);
        MPI_Comm_size(mySecondComm, &new_rank);
        printf("Group 1.2: new rank: %d\n", new_rank);
     }
     else if (membershipKey == 2)
     {                     /* Group 2 communicates with group 1. */
       MPI_Intercomm_create( myComm, 0, MPI_COMM_WORLD, 1,
                            12, &myFirstComm);
        MPI_Comm_size(myFirstComm, &new_rank);
        printf("Group 2: new rank: %d\n", new_rank);
     }



     /* Do work ... */

     switch(membershipKey)  /* free communicators appropriately */
     {
     case 1:
        MPI_Comm_free(&mySecondComm);
     case 0:
     case 2:
        MPI_Comm_free(&myFirstComm);
        break;
     }

     MPI_Finalize();
}
