#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    void* v;
    int rc;
    int flag;

    MPI_Init(&argc, &argv);
    MPI_Comm_set_errhandler(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
    rc = MPI_Attr_get(MPI_COMM_WORLD, MPI_TAG_UB, &v, &flag);
    MPI_Finalize();
    return 0;
}
