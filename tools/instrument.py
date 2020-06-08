#!/usr/bin/env python
# encoding: utf-8
import pickle, os
from codegen import MPIFunction, MPIArgument

def filter_with_local_mpi_functions(funcs):
    cleaned = {}

    os.system('grep -E "PMPI" /usr/include/mpi/*.h > /tmp/local_funcs.tmp')
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
    function_id_file.write('#endif')
    function_id_file.close()

def codegen_assemble_args(func):
    line = ""
    assemble_args = []
    for arg in func.arguments:
        if 'void' in arg.type:
            assemble_args.append("&"+arg.name)
        elif 'MPI_Status*' in arg.type and 'const' not in arg.type:
            line += "\tvoid* tmp = status;\n"
            line += "\tif(status == MPI_STATUS_IGNORE) {\n"
            line += "\t\ttmp = malloc(sizeof(MPI_Status)); \n\t\tmemset(tmp, 0, sizeof(MPI_Status));\n\t}\n"
            assemble_args.append("tmp")
        elif '*' in arg.type or '[' in arg.type:
            assemble_args.append(arg.name)      # its already the adress
        else:
            assemble_args.append( "&"+arg.name)

    if len(assemble_args) > 0:
        assemble_args_str = ', '.join(assemble_args)
        line += '\tvoid **args = assemble_args_list(%d, %s);\n' %(len(assemble_args), assemble_args_str)
    else:
        line = '\tvoid **args = NULL;\n'

    return line

def codegen_sizeof_args(func):
    sizeof_args = []
    #sizeof_args = special_sizeof_args(func, args)
    for arg in func.arguments:
        if 'void' in arg.type:
            sizeof_args.append('sizeof(void*)')
        elif '*' in arg.type or '[' in arg.type:
            n = "1" if not arg.length else arg.length
            fixed_type = arg.type.split('[')[0].replace('*', '')
            sizeof_args.append("%s * sizeof(%s)" %(n, fixed_type))
        else:
            sizeof_args.append("sizeof(%s)" %arg.name)

    line = '\tint* sizes = NULL;\n';
    if len(sizeof_args) > 0:
        sizeof_args_str = ', '.join(sizeof_args)
        line = '\tint sizes[] = { %s };\n' %sizeof_args_str

    return line


def handle_special_apis(wrapper_file, func):
    # Ignore
    if func.name == "MPI_Init" or func.name == "MPI_Init_thread" or func.name == "MPI_Finalize":
        return True

    ignored = ["MPI_Waitsome", "MPI_Waitall", "MPI_Testsome", "MPI_Testall", "MPI_Pcontrol"]
    if func.name in ignored:
        return True

    '''
    if func.name == "MPI_Pcontrol":
        wrapper_file.write('int MPI_Pcontrol(const int level, ...)\n{\n')
        wrapper_file.write('\tvoid **args = assemble_args_list(1, &level);\n');
        wrapper_file.write('\tint sizes[] = { sizeof(level) };\n')
        wrapper_file.write('\tva_list pcontrol_args;\n')
        wrapper_file.write('\tva_start(pcontrol_args, level);\n')
        wrapper_file.write('\tPILGRIM_TRACING(int, MPI_Pcontrol, (level, pcontrol_args), 1, sizes, args);\n')
        wrapper_file.write('\tva_end(pcontrol_args);\n}\n')
        return True
    '''

    return False

def generate_wrapper_file(funcs):
    f = open('../src/pilgrim_wrappers.c', 'w')
    f.write('#include <mpi.h>\n')
    f.write('#include <stdarg.h>\n')
    f.write('#include <stdlib.h>\n')
    f.write('#include <string.h>\n')
    f.write('#include "pilgrim.h"\n')

    for name in funcs:
        func = funcs[name]

        if handle_special_apis(f, func):
            continue

        # Signature
        line = func.ret_type + " " + func.name + func.signature + "\n"
        f.write(line + '{\n')

        # Real thing
        f.write(codegen_assemble_args(func))
        f.write(codegen_sizeof_args(func))

        arg_names = []
        for arg in func.arguments:
            arg_names.append(arg.name)
        f.write('\tPILGRIM_TRACING(%s, %s, (%s), %d, sizes, args);\n' %(func.ret_type, func.name, ', '.join(arg_names), len(arg_names)))
        f.write('}\n')


    f.close()


if __name__ == "__main__":
    f = open("./mpi_functions.pickle", 'r')
    funcs = pickle.load(f)
    f.close()

    funcs = filter_with_local_mpi_functions(funcs)
    print(len(funcs))

    generate_function_id_file(funcs)
    generate_wrapper_file(funcs)

