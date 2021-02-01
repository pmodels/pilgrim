/* This file is generated automatically. Do not change. */
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include "pilgrim.h"

void** read_record_args_special(int func_id, void* buff, int* nargs) {
    void **args;
    int size;
    int pos;
    *nargs = 0;
    switch(func_id) {
        case ID_MPI_Pcontrol:
        {
            size = sizeof(int);
            args[0] = malloc(size);
            memcpy(args[0], buff, size);
            break;
        }
        case ID_MPI_Waitsome:
        case ID_MPI_Testsome:
        {
            //(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status array_of_statuses[])
            args = malloc(5 * sizeof(void*));
            pos = 0;

            size = sizeof(int);
            args[0] = malloc(size);
            memcpy(args[0], buff, size);
            pos += size;

            size = (*(int*)args[0]) * sizeof(int);
            args[1] = malloc(size);
            memcpy(args[1], buff+pos, size);
            pos += size;

            size = sizeof(int);
            args[2] = malloc(size);
            memcpy(args[2], buff+pos, size);
            pos += size;

            int outcount = (* (int*)args[2]);
            if(outcount > 0) {
                *nargs = 5;
                size = outcount * sizeof(int);
                args[3] = malloc(size);
                memcpy(args[3], buff+pos, size);
                pos += size;

                size = outcount * 2 * sizeof(int);
                args[4] = malloc(size);
                memcpy(args[4], buff+pos, size);
            } else {
                *nargs = 3;
            }
            break;
        }
        case ID_MPI_Waitall:
        {
            //MPI_Waitall(int count, MPI_Request array_of_requests[], MPI_Status array_of_statuses[])
            *nargs = 3;
            args = malloc((*nargs) * sizeof(void*));
            pos = 0;

            size = sizeof(int);
            args[0] = malloc(size);
            memcpy(args[0], buff+pos, size);
            pos += size;

            size = (*(int*)args[0]) * sizeof(int);
            args[1] = malloc(size);
            memcpy(args[1], buff+pos, size);
            pos += size;

            size = (*(int*)args[0]) * sizeof(int) * 2;
            args[2] = malloc(size);
            memcpy(args[2], buff+pos, size);
            break;
        }
        case ID_MPI_Testall:
        {
            //MPI_Testall(int count, MPI_Request array_of_requests[], int *flag, MPI_Status array_of_statuses[])
            args = malloc(4 * sizeof(void*));
            pos = 0;

            size = sizeof(int);
            args[0] = malloc(size);
            memcpy(args[0], buff+pos, size);
            pos += size;

            size = (*(int*)args[0]) * sizeof(int);
            args[1] = malloc(size);
            memcpy(args[1], buff+pos, size);
            pos += size;

            size = sizeof(int);
            args[2] = malloc(size);
            memcpy(args[2], buff+pos, size);
            pos += size;

            int flag = *((int*)args[2]);
            if(flag) {
                *nargs = 4;
                size = (*(int*)args[0]) * sizeof(int) * 2;
                args[3] = malloc(size);
                memcpy(args[3], buff+pos, size);
            } else {
                *nargs = 3;
            }
            break;
        }
    }
    return args;
}
