#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    MPI_Comm newcomm = MPI_COMM_NULL;
    MPI_Request req;
    printf("newcom: %d\n", newcomm);
    MPI_Comm_idup(MPI_COMM_WORLD, &newcomm, &req);
    printf("newcom: %d\n", newcomm);

    MPI_Wait(&req, MPI_STATUS_IGNORE);
    printf("newcom: %d\n", newcomm);

    MPI_Finalize();
    return 0;
}
