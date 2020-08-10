#include <stdio.h>
#include <mpi.h>



int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank;
    int world_size;

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Barrier(MPI_COMM_WORLD);

    /*
    MPI_Allreduce(&world_size, &rank, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    //MPI_Barrier(MPI_COMM_WORLD);

    //TEST_MPI_CALL(MPI_Comm_size, (MPI_COMM_WORLD, &world_size));
    //TEST_MPI_CALL(MPI_Comm_rank, (MPI_COMM_WORLD, &rank));

    //int flag;
    //MPI_Finalized(&flag);
    */

    MPI_Finalize();

    return 0;
}
