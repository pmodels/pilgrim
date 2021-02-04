/* This file is generated automatically. Do not change. */
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include "pilgrim.h"
#include "pilgrim_reader.h"

void read_record_args_special(int func_id, void* buff, CallSignature *cs) {
    int pos;
    switch(func_id) {
        case ID_MPI_Pcontrol:
        {
            cs->arg_count = 1;
            cs->arg_sizes = malloc(cs->arg_count * sizeof(int));
            cs->arg_sizes[0] = sizeof(int);
            cs->args[0] = malloc(cs->arg_sizes[0]);
            memcpy(cs->args[0], buff, cs->arg_sizes[0]);
            break;
        }
        case ID_MPI_Waitsome:
        case ID_MPI_Testsome:
        {
            //(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status array_of_statuses[])
            cs->args = malloc(5 * sizeof(void*));
            cs->arg_sizes = malloc(5 * sizeof(int));
            pos = 0;

            cs->arg_sizes[0] = sizeof(int);
            cs->args[0] = malloc(cs->arg_sizes[0]);
            memcpy(cs->args[0], buff, cs->arg_sizes[0]);
            pos += cs->arg_sizes[0];

            cs->arg_sizes[1] = (*(int*)cs->args[0]) * sizeof(int);
            cs->args[1] = malloc(cs->arg_sizes[1]);
            memcpy(cs->args[1], buff+pos, cs->arg_sizes[1]);
            pos += cs->arg_sizes[1];

            cs->arg_sizes[2] = sizeof(int);
            cs->args[2] = malloc(cs->arg_sizes[2]);
            memcpy(cs->args[2], buff+pos, cs->arg_sizes[2]);
            pos += cs->arg_sizes[2];

            int outcount = (* (int*)cs->args[2]);
            if(outcount > 0) {
                cs->arg_count = 5;
                cs->arg_sizes[3] = outcount * sizeof(int);
                cs->args[3] = malloc(cs->arg_sizes[3]);
                memcpy(cs->args[3], buff+pos, cs->arg_sizes[3]);
                pos += cs->arg_sizes[3];

                cs->arg_sizes[4] = outcount * 2 * sizeof(int);
                cs->args[4] = malloc(cs->arg_sizes[4]);
                memcpy(cs->args[4], buff+pos, cs->arg_sizes[4]);
            } else {
                cs->arg_count = 3;
            }
            break;
        }
        case ID_MPI_Waitall:
        {
            //MPI_Waitall(int count, MPI_Request array_of_requests[], MPI_Status array_of_statuses[])
            cs->arg_count = 3;
            cs->args = malloc(cs->arg_count * sizeof(void*));
            cs->arg_sizes = malloc(cs->arg_count * sizeof(int));
            pos = 0;

            cs->arg_sizes[0] = sizeof(int);
            cs->args[0] = malloc(cs->arg_sizes[0]);
            memcpy(cs->args[0], buff+pos, cs->arg_sizes[0]);
            pos += cs->arg_sizes[0];

            cs->arg_sizes[1] = (*(int*)cs->args[0]) * sizeof(int);
            cs->args[1] = malloc(cs->arg_sizes[1]);
            memcpy(cs->args[1], buff+pos, cs->arg_sizes[1]);
            pos += cs->arg_sizes[1];

            cs->arg_sizes[2] = (*(int*)cs->args[0]) * sizeof(int) * 2;
            cs->args[2] = malloc(cs->arg_sizes[2]);
            memcpy(cs->args[2], buff+pos, cs->arg_sizes[2]);
            break;
        }
        case ID_MPI_Testall:
        {
            //MPI_Testall(int count, MPI_Request array_of_requests[], int *flag, MPI_Status array_of_statuses[])
            cs->args = malloc(4 * sizeof(void*));
            pos = 0;

            cs->arg_sizes[0] = sizeof(int);
            cs->args[0] = malloc(cs->arg_sizes[0]);
            memcpy(cs->args[0], buff+pos, cs->arg_sizes[0]);
            pos += cs->arg_sizes[0];

            cs->arg_sizes[1] = (*(int*)cs->args[0]) * sizeof(int);
            cs->args[1] = malloc(cs->arg_sizes[1]);
            memcpy(cs->args[1], buff+pos, cs->arg_sizes[1]);
            pos += cs->arg_sizes[1];

            cs->arg_sizes[2] = sizeof(int);
            cs->args[2] = malloc(cs->arg_sizes[2]);
            memcpy(cs->args[2], buff+pos, cs->arg_sizes[2]);
            pos += cs->arg_sizes[2];

            int flag = *((int*)cs->args[2]);
            if(flag) {
                cs->arg_count = 4;
                cs->arg_sizes[3] = (*(int*)cs->args[0]) * sizeof(int) * 2;
                cs->args[3] = malloc(cs->arg_sizes[3]);
                memcpy(cs->args[3], buff+pos, cs->arg_sizes[3]);
            } else {
                cs->arg_count = 3;
            }
            break;
        }
    }
}
