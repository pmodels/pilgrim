#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank;
    int world_size;

    int *data = malloc(sizeof(int)*3);
    int *data2 = malloc(sizeof(int)*5);
    int *data3 = malloc(sizeof(int)*10);

    free(data);
    free(data2);
    free(data3);

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    /*
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Allreduce(&world_size, &rank, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    MPI_Allreduce(&rank, &world_size, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    */

    //int flag;
    //MPI_Finalized(&flag);

    MPI_Finalize();

    return 0;
}
