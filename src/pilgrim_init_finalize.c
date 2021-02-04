#include <mpi.h>
#include "pilgrim.h"

// MPI_Init, MPI_Finalize are not implemented in pilgrim_warrper.c

double tstart, tend, tmin, tmax;
double elapsed_time;

void pilgrim_init(int *argc, char ***argv) {
    PMPI_Comm_size(MPI_COMM_WORLD, &g_mpi_size);
    PMPI_Comm_rank(MPI_COMM_WORLD, &g_mpi_rank);

    logger_init();
    elapsed_time = pilgrim_wtime();
    tstart = pilgrim_wtime();

}

void pilgrim_exit() {

    double finalize_time = pilgrim_wtime();
    logger_exit();
    finalize_time = pilgrim_wtime() - finalize_time;

    tend = pilgrim_wtime();
    elapsed_time = pilgrim_wtime() - elapsed_time;

    PMPI_Reduce(&tstart, &tmin, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);
    PMPI_Reduce(&tend , &tmax, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
    if (g_mpi_rank == 0)
        printf("[Pilgrim] app elapsed time: %.2f, pilgrim fianlize time: %.2f\n", tmax-tmin, finalize_time);
}

int MPI_Init(int *argc, char ***argv) {
    int res = PMPI_Init(argc, argv);
    pilgrim_init(argc, argv);

    MPI_Comm intercomm;
    PMPI_Comm_get_parent(&intercomm);
    // Spawned by the parent calling MPI_Comm_spawn
    // Need to find out the id for the intercomm.
    if(intercomm != MPI_COMM_NULL)
        generate_intercomm_id(MPI_COMM_WORLD, &intercomm, 0);
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
