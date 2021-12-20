/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

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
    PMPI_Barrier(MPI_COMM_WORLD);
    finalize_time = pilgrim_wtime() - finalize_time;

    tend = pilgrim_wtime();
    elapsed_time = pilgrim_wtime() - elapsed_time;

    PMPI_Reduce(&tstart, &tmin, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);
    PMPI_Reduce(&tend , &tmax, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
    //if (g_mpi_rank == 0)
    //    printf("[pilgrim] app elapsed time: %.2f, pilgrim fianlize time: %.2f\n", tmax-tmin, finalize_time);
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

extern void MPI_INIT(MPI_Fint * ierr) { PMPI_Init(0, NULL); pilgrim_init(0, NULL);}
extern void mpi_init(MPI_Fint * ierr) { PMPI_Init(0, NULL); pilgrim_init(0, NULL); }
extern void mpi_init_(MPI_Fint * ierr) { PMPI_Init(0, NULL); pilgrim_init(0, NULL); }
extern void mpi_init__(MPI_Fint * ierr) { PMPI_Init(0, NULL); pilgrim_init(0, NULL); }

int MPI_Init_thread(int *argc, char ***argv, int required, int *provided) {
    int res = PMPI_Init_thread(argc, argv, required, provided);
    pilgrim_init(argc, argv);
    return res;
}

int MPI_Finalize(void) {
    pilgrim_exit();
    return PMPI_Finalize();
}

extern void MPI_FINAZLIE(MPI_Fint * ierr) { pilgrim_exit(); PMPI_Finalize(); }
extern void mpi_FINALIZE(MPI_Fint * ierr) { pilgrim_exit(); PMPI_Finalize(); }
extern void mpi_finalize_(MPI_Fint * ierr) { pilgrim_exit(); PMPI_Finalize(); }
extern void mpi_finalize__(MPI_Fint * ierr) { pilgrim_exit(); PMPI_Finalize(); }
