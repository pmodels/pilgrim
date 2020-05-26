#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);


    MPI_Datatype myNewType;
    int blocklen[3] = {1, 6, 7 };
    MPI_Aint disp[3];
    MPI_Datatype type[3] = {MPI_CHAR, MPI_DOUBLE, MPI_CHAR};

    MPI_Type_create_struct(3,
                         blocklen,
                         disp,
                         type,
                         &myNewType);
    //printf("myNewType: %x\n", myNewType);
    //printf("MPI_CHAR: %x\n", MPI_CHAR);

    MPI_Finalize();
    return 0;
}
