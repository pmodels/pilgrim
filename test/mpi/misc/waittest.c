#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int mpi_size, mpi_rank;

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &mpi_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);

    int data = 100;
    int N = 5;
    MPI_Request reqs[N];

    if(mpi_rank == 0) {
        for(int i = 0; i < N; i++)
            MPI_Isend(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &reqs[i]);

        int complete = 0;
        int idx;
        int outcount;
        int indices[N];
        while(complete != N) {
            //MPI_Testany(N, reqs, &idx, &outcount, MPI_STATUS_IGNORE);
            //MPI_Waitsome(N, reqs, &outcount, indices, MPI_STATUSES_IGNORE);
            MPI_Testsome(N, reqs, &outcount, indices, MPI_STATUSES_IGNORE);

            MPI_Comm_rank(MPI_COMM_WORLD, &data);
            complete += outcount;
        }
    } else {
        for(int i = 0; i < N; i++)
            MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    MPI_Finalize();

    return 0;
}
