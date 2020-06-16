/* This file is generated automatically. Do not change. */
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include "pilgrim.h"

void** read_record_args_special(FILE* f, int func_id) {
    void **args;
    int size;
    int length;
    size_t n;
    switch(func_id) {
        case ID_MPI_Pcontrol:
        {
            args = malloc(1 * sizeof(void*));
            args[0]  = malloc(sizeof(int));
            fread(args[0], sizeof(int), 1, f);      // lelvel
            break;
        }
        case ID_MPI_Waitsome:
        case ID_MPI_Testsome:
        {
            //(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status array_of_statuses[])
            args = malloc(5 * sizeof(void*));
            args[0] = malloc(sizeof(int));
            fread(args[0], sizeof(int), 1, f);

            size = (*(int*)args[0]) * sizeof(MPI_Request);
            args[1] = malloc(size);
            fread(args[1], size, 1, f);

            size = sizeof(int);
            args[2] = malloc(size);
            fread(args[2], size, 1, f);

            size = (*(int*)args[2]) * sizeof(int);
            args[3] = malloc(size);
            fread(args[3], size, 1, f);

            size = (*(int*)args[2]) * sizeof(MPI_Status);
            args[4] = malloc(size);
            fread(args[4], size, 1, f);
            break;
        }
        case ID_MPI_Waitall:
        {
            //MPI_Waitall(int count, MPI_Request array_of_requests[], MPI_Status array_of_statuses[])
            args = malloc(3 * sizeof(void*));
            args[0] = malloc(sizeof(int));
            fread(args[0], sizeof(int), 1, f);

            size = (*(int*)args[0]) * sizeof(MPI_Request);
            args[1] = malloc(size);
            fread(args[1], size, 1, f);

            size = (*(int*)args[0]) * sizeof(MPI_Status);
            args[2] = malloc(size);
            fread(args[2], size, 1, f);
            break;
        }
        case ID_MPI_Testall:
        {
            //MPI_Testall(int count, MPI_Request array_of_requests[], int *flag, MPI_Status array_of_statuses[])
            args = malloc(4 * sizeof(void*));
            args[0] = malloc(sizeof(int));
            fread(args[0], sizeof(int), 1, f);

            size = (*(int*)args[0]) * sizeof(MPI_Request);
            args[1] = malloc(size);
            fread(args[1], size, 1, f);

            args[2] = malloc(sizeof(int));
            fread(args[2], sizeof(int), 1, f);

            size = (*(int*)args[0]) * sizeof(MPI_Status);
            args[3] = malloc(size);
            fread(args[3], size, 1, f);
            break;
        }
    }

    return args;
}
