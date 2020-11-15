#!/usr/bin/env python
# encoding: utf-8
import pickle, os
from codegen import MPIFunction, MPIArgument

def filter_with_local_mpi_functions(funcs):
    cleaned = {}

    #os.system('grep -E "PMPI" /opt/pkgs/software/MPICH/3.3-GCC-7.2.0-2.29/include/*.h > /tmp/local_funcs.tmp')
    os.system('grep -E "PMPI" /usr/include/mpich/*.h > /tmp/local_funcs.tmp')
    f = open('/tmp/local_funcs.tmp', 'r')
    for line in f.readlines():
        func_name = line.strip().split('(')[0].split(' ')[1]
        func_name = func_name.replace('PMPI_', 'MPI_')
        if func_name in funcs:
            cleaned[func_name] = funcs[func_name]
    f.close()
    os.system('rm /tmp/local_funcs.tmp')

    return cleaned

def arg_type_strip(type_str):
    t = type_str.replace('*', '').replace('[', '').replace(']', '').replace(' ', '').replace('const', '')
    return t;

def is_mpi_object_arg(arg_type):
    # Do not include MPI_Status, MPI_Comm, and MPI_Offset
    mpi_objects = set([
        "MPI_Info", "MPI_Datatype", "MPI_File", "MPI_Win", "MPI_Request"
        "MPI_Group", "MPI_Op", "MPI_Message", "MPI_Comm"])
    if arg_type in mpi_objects:
        return True
    return False

def handle_special_apis(func):
    # These are handled in pilgrim_init_finalize.c
    if func.name == "MPI_Init" or func.name == "MPI_Init_thread" or func.name == "MPI_Finalize":
        return True

    # These are handled in pilgrim_init_pilgrim_wrappers_special.c
    ignored = ["MPI_Wait", "MPI_Waitany", "MPI_Waitsome", "MPI_Waitall", "MPI_Request_free", "MPI_Startall",
               "MPI_Test", "MPI_Testany", "MPI_Testsome", "MPI_Testall", "MPI_Pcontrol"]

    if func.name in ignored:
        return True

    return False


def codegen_read_one_arg(func, i):

    def find_arg_idx(func, arg_name):
        for idx, arg in enumerate(func.arguments):
            if arg.name == arg_name:
                return idx
        return -1

    arg = func.arguments[i]

    lines = []
    if 'void' in arg.type:
        lines.append('size = sizeof(int);')
    elif 'MPI_Status' in arg.type:
        lines.append('size = sizeof(int)*2;')
    elif 'MPI_Offset' in arg.type and '*' not in arg.type:  # keep separately
        pass
    elif is_mpi_object_arg(arg_type_strip(arg.type)):
        if "MPI_Comm" in arg.type :
            lines.append('size = sizeof(MPI_Comm)+sizeof(int);')
        else:
            lines.append('size = sizeof(int);')
    elif 'char*' in arg.type:
        if '**' not in arg.type and '[' not in arg.type:    # only consider one single string
            lines.append('size = strlen(buff+pos)+1;')
    elif '*' in arg.type or '[' in arg.type:
        fixed_type = arg_type_strip(arg.type)
        if arg.length:
            if '*' in arg.length:   # n*3
                pass
            else:
                idx = find_arg_idx(func, arg.length)
                lines.append( 'length = *((int*) (args[%d]));' %idx )
                lines.append( "size = length * sizeof(%s);" %fixed_type)
        else:
            lines.append( "size = sizeof(%s);" %fixed_type )
    else:
        lines.append( "size = sizeof(%s);" %arg.type )

    lines.append('args[%d] = calloc(size, 1);' %i)
    lines.append('memcpy(args[%d], buff+pos, size);' %i)
    lines.append('pos += size;')
    return lines


def generate_reader_file(funcs):
    f = open('../src/pilgrim_read_args.c', 'w')
    block = \
'''/* This file is generated automatically. Do not change. */
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include "pilgrim.h"
void** read_record_args(int func_id, void* buff) {
    void **args;
    int size, length, pos;
    size_t n;
    switch(func_id) {
'''
    f.write(block)

    for name in funcs:
        func = funcs[name]

        f.write('\t\tcase ID_%s:\n\t\t{\n' %name)

        if handle_special_apis(func):
            f.write('\t\t\tread_record_args_special(func_id, buff);')
        else:
            f.write('\t\t\targs = malloc(%d * sizeof(void*));' %len(func.arguments))
            f.write('\n\t\t\tpos = 0;')
            for i in range(len(func.arguments)):
                f.write('\n\t\t\t')
                lines = codegen_read_one_arg(func, i)
                f.write('\n\t\t\t'.join(lines))
        f.write('\n\t\t\tbreak;\n\t\t}\n')

    f.write('\t}\n\treturn args;\n}\n')
    f.close()

if __name__ == "__main__":
    f = open("./mpi_functions.pickle", 'r')
    funcs = pickle.load(f)
    f.close()

    funcs = filter_with_local_mpi_functions(funcs)
    print(len(funcs))

    generate_reader_file(funcs)
