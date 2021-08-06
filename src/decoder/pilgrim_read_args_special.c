/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* This file is generated automatically. Do not change. */
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include "pilgrim.h"
#include "pilgrim_reader.h"


void read_record_args_special(int func_id, void* buff, CallSignature *cs) {
    int pos;
    switch(func_id) {
        case ID_free:
        {
            INIT_CALL_ARGS(cs, 1);
            cs->arg_sizes[0] = sizeof(MemPtrAttr);
			cs->arg_types[0] = TYPE_MEM_PTR;
			cs->arg_directions[0] = DIRECTION_IN;
            cs->args[0] = malloc(cs->arg_sizes[0]);
            memcpy(cs->args[0], buff, cs->arg_sizes[0]);
            break;
        }
        case ID_MPI_Pcontrol:
        {
            // TODO not finished yet.
            //cs->args[0] = malloc(cs->arg_sizes[0]);
            //memcpy(cs->args[0], buff, cs->arg_sizes[0]);
            break;
        }
    }
}
