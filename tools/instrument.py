#!/usr/bin/env python
# encoding: utf-8
import pickle, os
from codegen import MPIFunction, MPIArgument

def filter_with_local_mpi_functions(funcs):
    cleaned = {}

    os.system('grep -E "PMPI" /opt/pkgs/software/MPICH/3.3-GCC-7.2.0-2.29/include/*.h > /tmp/local_funcs.tmp')
    f = open('/tmp/local_funcs.tmp', 'r')
    for line in f.readlines():
        func_name = line.strip().split('(')[0].split(' ')[1]
        func_name = func_name.replace('PMPI_', 'MPI_')
        if func_name in funcs:
            cleaned[func_name] = funcs[func_name]
    f.close()
    os.system('rm /tmp/local_funcs.tmp')

    return cleaned


def generate_function_id_file(funcs):
    function_id_file = open('../include/pilgrim_func_ids.h', 'w')
    function_id_file.write('/* This file is generated automatically, please do not change! */\n')
    function_id_file.write('#ifndef _PILGRIM_FUNC_IDS_H_\n#define _PILGRIM_FUNC_IDS_H_\n')
    idx = 0
    for name in funcs:
        function_id_file.write('#define ID_'+name+' '+str(idx)+'\n')
        idx += 1

    function_id_file.write('static char *func_names[] = {\n')
    for name in funcs:
        function_id_file.write('"%s", \n' %name)
    function_id_file.write('};\n\n')

    function_id_file.write('#endif')
    function_id_file.close()

def codegen_assemble_args(func):
    line = ""
    assemble_args = []
    for arg in func.arguments:
        if 'void' in arg.type:                  # void* buf
            assemble_args.append("addr2id("+arg.name+")")
        elif 'MPI_Request' in arg.type:          # ignore for now (TODO)
            if '*' in arg.type:
                line += "\tappend_request(%s);\n" %(arg.name)
            else:
                line += "\tappend_request(&%s);\n" %(arg.name)
        elif 'MPI_Status' in arg.type:
            pass
        elif 'MPI_Status*' in arg.type and 'const' not in arg.type:
            line += "\tvoid* tmp = status;\n"
            line += "\tif(status == MPI_STATUS_IGNORE) {\n"
            line += "\t\ttmp = malloc(sizeof(MPI_Status)); \n\t\tmemset(tmp, 0, sizeof(MPI_Status));\n\t}\n"
            assemble_args.append("tmp")
        elif '*' in arg.type or '[' in arg.type:
            assemble_args.append(arg.name)      # its already the adress
        elif 'int' in arg.type and ('source' in arg.name or 'dest' in arg.name):    # pattern recognization for rank-1/rank+1 as src or dest
            line += "\tint %s_rank = self_rank - %s;\n" %(arg.name, arg.name)
            line += "\tif(%s == MPI_ANY_SOURCE) %s_rank = -99999;\n" %(arg.name, arg.name)
            assemble_args.append( "&%s_rank" %arg.name )
        else:
            assemble_args.append( "&"+arg.name)

    if func.name == "MPI_Comm_rank":
        line += "\tself_rank = *rank;\n"

    if len(assemble_args) > 0:
        assemble_args_str = ', '.join(assemble_args)
        line += '\tvoid **args = assemble_args_list(%d, %s);\n' %(len(assemble_args), assemble_args_str)
    else:
        line = '\tvoid **args = NULL;\n'

    return line, len(assemble_args)

def codegen_sizeof_args(func):
    sizeof_args = []
    for arg in func.arguments:
        if 'void' in arg.type:
            sizeof_args.append('sizeof(int)')
        elif 'char*' in arg.type:
            if '**' not in arg.type and '[' not in arg.type:    # only consider one single string
                sizeof_args.append('strlen(%s)+1' %arg.name)
        elif 'MPI_Status' in arg.type or 'MPI_Request' in arg.type: # ignore for now (TODO)
            continue
        elif '*' in arg.type or '[' in arg.type:
            n = "1" if not arg.length else arg.length
            fixed_type = arg.type.split('[')[0].replace('*', '')
            sizeof_args.append("%s * sizeof(%s)" %(n, fixed_type))
        else:
            sizeof_args.append("sizeof(%s)" %arg.type)

    line = '\tint* sizes = NULL;\n';
    if len(sizeof_args) > 0:
        sizeof_args_str = ', '.join(sizeof_args)
        line = '\tint sizes[] = { %s };\n' %sizeof_args_str

    return line


def handle_special_apis(func):
    # These are handled in pilgrim_init_finalize.c
    if func.name == "MPI_Init" or func.name == "MPI_Init_thread" or func.name == "MPI_Finalize":
        return True

    # These are handled in pilgrim_init_pilgrim_wrappers_special.c
    ignored = ["MPI_Wait", "MPI_Waitany", "MPI_Waitsome", "MPI_Waitall", "MPI_Request_free", "MPI_Startall",
               "MPI_Test", "MPI_Testany", "MPI_Testsome", "MPI_Testall", "MPI_Pcontrol"]
    if func.name in ignored:
        return True

    # TODO Ignore MPI IO functions for now
    if "MPI_File_write" in func.name:
        return True

    return False

def generate_wrapper_file(funcs):
    f = open('../src/pilgrim_wrappers.c', 'w')
    f.write('#include <mpi.h>\n')
    f.write('#include <stdarg.h>\n')
    f.write('#include <stdlib.h>\n')
    f.write('#include <string.h>\n')
    f.write('#include "pilgrim.h"\n')
    f.write('static int self_rank;\n')

    for name in funcs:
        func = funcs[name]

        if handle_special_apis(func):
            continue

        # Signature
        line = func.ret_type + " " + func.name + func.signature + "\n"
        f.write(line + '{\n')

        arg_names = []
        for arg in func.arguments:
            arg_names.append(arg.name)
        f.write('\tPILGRIM_TRACING_1(%s, %s, (%s));\n' %(func.ret_type, func.name, ', '.join(arg_names)))

        # Real thing
        line, num_args = codegen_assemble_args(func)
        f.write(line)
        f.write(codegen_sizeof_args(func))
        f.write('\tPILGRIM_TRACING_2(%d, sizes, args);\n' %num_args)

        f.write('}\n')

    f.close()


def codegen_read_one_arg(func, i):

    def find_arg_idx(func, arg_name):
        for idx, arg in enumerate(func.arguments):
            if arg.name == arg_name:
                return idx
        return -1

    arg = func.arguments[i]

    lines = []
    if 'void' in arg.type:
        lines.append('size = sizeof(void*);')
    elif 'char*' in arg.type:
        if '**' not in arg.type and '[' not in arg.type:    # only consider one single string
            lines = ['getdelim(((char**)&args[%d]), &n, 0, f);' %i]
            return lines
    elif '*' in arg.type or '[' in arg.type:
        fixed_type = arg.type.split('[')[0].replace('*', '')
        if arg.length:
            if '*' in arg.length:   # n*3
                pass
            else:
                idx = find_arg_idx(func, arg.length)
                lines.append( 'length = *((int*) (args[%d]));' %idx )
                lines.append( "size = length * sizeof(%s);" %fixed_type )
        else:
            lines.append( "size = sizeof(%s);" %fixed_type )
    else:
        lines.append( "size = sizeof(%s);" %arg.type )

    lines.append('args[%d] = malloc(size);' %i)
    lines.append('fread(args[%d], size, 1, f);' %i)

    return lines


def generate_reader_file(funcs):
    f = open('../src/pilgrim_read_args.c', 'w')
    block = \
'''/* This file is generated automatically. Do not change. */
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include "pilgrim.h"
void** read_record_args(FILE* f, int func_id) {
    void **args;
    int size;
    int length;
    size_t n;
    switch(func_id) {
'''
    f.write(block)

    for name in funcs:
        func = funcs[name]

        f.write('\t\tcase ID_%s:\n\t\t{\n' %name)

        if handle_special_apis(func):
            f.write('\t\t\tread_record_args_special(f, func_id);')
        else:
            f.write('\t\t\targs = malloc(%d * sizeof(void*));' %len(func.arguments))
            for i in range(len(func.arguments)):
                f.write('\n\t\t\t');
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

    generate_function_id_file(funcs)
    generate_wrapper_file(funcs)

    generate_reader_file(funcs)
