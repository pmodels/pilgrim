##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

#!/usr/bin/env python
# encoding: utf-8
import pickle, os
from codegen import MPIFunction, MPIArgument
from instrument import arg_type_strip, is_mpi_object_arg, filter_with_local_mpi_functions


def handle_special_apis(func):
    # These are handled in pilgrim_init_finalize.c
    if func.name == "MPI_Init" or func.name == "MPI_Init_thread" or func.name == "MPI_Finalize":
        return True

    # These are handled in pilgrim_init_pilgrim_wrappers_special.c
    ignored = ["MPI_Pcontrol"]

    if func.name in ignored:
        return True

    return False


unique_types = set([])

def codegen_read_one_arg(func, i):

    def find_arg_idx(func, arg_name):
        for idx, arg in enumerate(func.arguments):
            if arg.name == arg_name:
                return idx
        return -1

    arg = func.arguments[i]

    unique_types.add(arg_type_strip(arg.type))

    lines = []

    # 1. Set argument direction
    #
    # (a) sometimes an argument with direction INOUT is not a pointer
    # e.g., MPI_Info_set(info, ...); We correct its direction to IN
    # for easier post-processing.
    # (b) some arguments are documented as IN, but it actually can be
    # modified if is a pointer
    # e.g., MPI_Cancel(MPI_Request *request)
    if (arg.direction == "INOUT") and ("*" not in arg.type and "[" not in arg.type):
        arg.direction = "IN"
    if (arg.direction == "IN") and ("*" in arg.type):
        arg.direction = "INOUT"
    lines.append('cs->arg_directions[%d] = DIRECTION_%s;' %(i, arg.direction))

    # 2. Fill in details for each unique type
    if arg_type_strip(arg.type) == "int":
        lines.append('cs->arg_sizes[%d] = sizeof(int);' %i)
        if "source" in arg.name or "dest" in arg.name:
            lines.append('cs->arg_types[%d] = TYPE_RANK_ENCODED;' %i)
        elif "tag" in arg.name:
            lines.append('cs->arg_types[%d] = TYPE_TAG;' %i)
        else:
            lines.append('cs->arg_types[%d] = TYPE_INT;' %i)
    elif 'void' in arg.type:
        lines.append('cs->arg_types[%d] = TYPE_MEM_PTR;' %i)
        lines.append('cs->arg_sizes[%d] = sizeof(MemPtrAttr);' %i)
    elif 'MPI_Status' in arg.type:
        lines.append('cs->arg_types[%d] = TYPE_MPI_Status;' %i)
        lines.append('cs->arg_sizes[%d] = sizeof(int)*2;' %i)
    elif 'MPI_Offset' in arg.type and '*' not in arg.type:  # keep separately
        pass
    elif 'MPI_Aint' in arg.type:
        lines.append('cs->arg_types[%d] = TYPE_MPI_Aint;' %i)
        lines.append('cs->arg_sizes[%d] = sizeof(%s);' %(i, arg_type_strip(arg.type)) )
    elif 'MPI_Count' in arg.type:
        lines.append('cs->arg_types[%d] = TYPE_MPI_Count;' %i)
        lines.append('cs->arg_sizes[%d] = sizeof(%s);' %(i, arg_type_strip(arg.type)) )
    elif ('MPI_' in arg.type) and ('function' in arg.type):
        arg_type = arg_type_strip(arg.type)
        lines.append('cs->arg_sizes[%d] = sizeof(%s);' %(i, arg_type))
        lines.append('cs->arg_types[%d] = TYPE_%s;' %(i, arg_type))
    elif is_mpi_object_arg(arg_type_strip(arg.type)):
        lines.append('cs->arg_sizes[%d] = sizeof(int);' %i)
        lines.append('cs->arg_types[%d] = TYPE_%s;' %(i, arg_type_strip(arg.type)))
    elif ('char[]' in arg.type or 'char*' in arg.type):
        if '**' not in arg.type and '*[]' not in arg.type:    # only consider one single string for now
            lines.append('cs->arg_sizes[%d] = strlen(buff+pos)+1;' %i)
            lines.append('cs->arg_types[%d] = TYPE_STRING;' %(i))
        else:
            # MPI_Comm_spawn, MPI_Comm_spawn_multi
            pass
    else:
        # MPI_T_* type parameters
        lines.append('cs->arg_sizes[%d] = sizeof(%s);' %(i, arg_type_strip(arg.type)) )


    # 3. Set up the length for array arguments of graph realated calls
    # We need to do this because for some of them, we can not directly
    # parse that info from the MPI Standard latex
    if (func.name == "MPI_Graph_create" or func.name == "MPI_Graph_map") and arg.name == "edges":
        # MPI_Graph_create(MPI_Comm comm_old, int nnodes, const int index[], const int edges[], int reorder, MPI_Comm * comm_graph)
        # MPI_Graph_map(MPI_Comm comm, int nnodes, const int index[], const int edges[], int *newrank)
        # length of edges: index[nnodes-1]
        lines.append('cs->arg_lengths[%d] = ((int*)cs->args[2])[*(int*)cs->args[1]-1];' %i)

    if func.name == "MPI_Dist_graph_create":
        # MPI_Dist_graph_create(MPI_Comm comm_old, int n, const int sources[], const int degrees[], const int destinations[], const int weights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph)
        # length of destinations/weights: sum(degress)
        if arg.name == "destinations" or arg.name == "weights":
            lines.append('cs->arg_lengths[%d] = pilgrim_sum_array((int*) cs->args[3], *(int*)cs->args[1]);' %i)

    if func.name == "MPI_Dist_graph_create_adjacent":
        # length of sourceweights = indegree
        # length of destweights = outdegree
        if arg.name == "sourceweights":
            lines.append('cs->arg_lengths[%d] = (*(int*) cs->args[1]);' %i)
        if arg.name == "destweights":
            lines.append('cs->arg_lengths[%d] = (*(int*) cs->args[4]);' %i)


    # 4. Finally, update size for array arguments
    if '[' in arg.type and 'char' not in arg.type and 'graph' not in func.name.lower():
        # could be MPI_Aint or int (int for int[], MPI_Datatype[])
        size_type = arg_type_strip(arg.type)
        if size_type == "MPI_Datatype": size_type = "int"

        if arg.length:
            # n*3 int array, see codegen.py
            if 'n*3' in arg.length:
                idx = find_arg_idx(func, "n")
                lines.append( 'cs->arg_lengths[%d] = 3 * (*((int*) (cs->args[%d])));' %(i, idx) )
            else:
                idx = find_arg_idx(func, arg.length)
                lines.append( 'cs->arg_lengths[%d] = *((int*) (cs->args[%d]));' %(i, idx) )
        else:
            # func.need_comm_size must be True so we have comm_size set already
            lines.append('cs->arg_lengths[%d] =  comm_size;' %(i))
            lines.append('assert(cs->arg_lengths[%d] > 0);' %i);

        if 'graph' in func.name.lower():
            print(func.name, arg.type, arg.name, arg.length)


        lines.append('cs->arg_sizes[%d] = sizeof(%s) * cs->arg_lengths[%d];' %(i, size_type, i))

    lines.append('cs->args[%d] = calloc(cs->arg_sizes[%d], 1);' %(i,i))
    lines.append('memcpy(cs->args[%d], buff+pos, cs->arg_sizes[%d]);' %(i,i))
    lines.append('pos += cs->arg_sizes[%d];' %i)
    return lines


def generate_reader_file(funcs):
    f = open('../src/decoder/pilgrim_read_args.c', 'w')
    block = \
'''/* This file is generated automatically. Do not change. */
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include "pilgrim.h"
#include "pilgrim_reader.h"
void read_record_args(int func_id, void* buff, CallSignature* cs) {
    int comm_size, pos;
    size_t n;
    switch(func_id) {
'''
    f.write(block)

    for name in funcs:
        func = funcs[name]

        f.write('\t\tcase ID_%s:\n\t\t{\n' %name)

        if handle_special_apis(func):
            f.write('\t\t\tread_record_args_special(func_id, buff, cs);')
        else:
            f.write('\t\t\tINIT_CALL_ARGS(cs, %d);' %len(func.arguments))
            f.write('\n\t\t\tpos = 0;')

            if func.need_comm_size:
                f.write('\n\t\t\tcomm_size =  *((int*) (buff+pos));')
                f.write('\n\t\t\tpos += sizeof(int);')

            for i in range(len(func.arguments)):
                f.write('\n\t\t\t')
                lines = codegen_read_one_arg(func, i)
                f.write('\n\t\t\t'.join(lines))

        f.write('\n\t\t\tbreak;\n\t\t}\n')

    # for free() function
    f.write('\t\tcase ID_free:\n\t\t{\n')
    f.write('\t\t\tread_record_args_special(func_id, buff, cs);')
    f.write('\n\t\t\tbreak;\n\t\t}\n')

    f.write('\t}\n}\n')
    f.close()

if __name__ == "__main__":
    f = open("./mpi_functions.pickle", 'r')
    funcs = pickle.load(f)
    f.close()

    funcs = filter_with_local_mpi_functions(funcs)

    generate_reader_file(funcs)
    print(len(unique_types), unique_types)
