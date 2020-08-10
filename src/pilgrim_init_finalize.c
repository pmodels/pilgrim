#include <mpi.h>
#include "pilgrim.h"
#include "pilgrim_mem_hooks.h"
// MPI_Init, MPI_Finalize are not implemented in pilgrim_warrper.c


int rank;
int nprocs;
double elapsed_time;

void pilgrim_init(int *argc, char ***argv) {
    PMPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    PMPI_Comm_rank(MPI_COMM_WORLD, &rank);

    logger_init(rank, nprocs);
    install_hooks();
    elapsed_time = pilgrim_wtime();
}

void pilgrim_exit() {
    remove_hooks();
    logger_exit();
    elapsed_time = pilgrim_wtime() - elapsed_time;
    if (rank == 0)
        printf("[Pilgrim] elapsed time: %.2f\n", elapsed_time);
}

int MPI_Init(int *argc, char ***argv) {
    int res = PMPI_Init(argc, argv);
    pilgrim_init(argc, argv);
    return res;
}

int MPI_Init_thread(int *argc, char ***argv, int required, int *provided) {
    int res = PMPI_Init_thread(argc, argv, required, provided);
    pilgrim_init(argc, argv);
    return res;
}

int MPI_Finalize(void) {
    pilgrim_exit();
    return PMPI_Finalize();
}
