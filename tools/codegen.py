##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

#!/usr/bin/env python
# encoding: utf-8
import os, glob, sys,re
import pickle

class MPIArgument:
    def __init__(self):
        self.type = ""
        self.name = ""
        self.length = ""            # if its an array type
        self.direction = "IN"       #  IN, OUT, INOUT

class MPIFunction:
    def __init__(self, func_block):
        self.signature = ""
        self.name = ""
        self.ret_type = ""
        self.need_comm_size = False # comm size for array arguments length
        self.arguments = []

        if 'function_name' in func_block:
            func_block = func_block.replace('\n', '').replace(' ', '')
            name = func_block.split('function_name(\"')[1]
            name = name.split('\"')[0]
            self.name = name


            # arguments
            parameters = func_block.split('parameter(\"')
            for parameter in parameters[1:]:
                arg = MPIArgument()
                arg.name =  parameter.split('\"')[0]

                if 'direction=' in parameter:
                    direction = parameter.split('direction=\"')[1].split('\"')[0]
                    if "INOUT" in direction.upper(): arg.direction = "INOUT"
                    elif "OUT" in direction.upper(): arg.direction = "OUT"

                if 'length=[' in parameter: # only in MPI_Group_range_excl/incl, the argument ranges[][3], length is ['n', '3']
                    length = parameter.split('length=[')[1].split(']')[0]
                    arg.length = '*'.join( length.split(',') ).replace('\"', '')
                elif 'length=' in parameter:
                    length = parameter.split('length=\"')[1].split('\"')[0]

                    arg.length = '' if length == '*' else length
                # For OUT only array arguments, we can not infer the length from MPI standard.
                # Need to do it manually.
                self.arguments.append(arg)

        # c2f and f2c functions
        if "mpiemptybindidx" in func_block:
            func_block = func_block.replace("mpiemptybindidx{", "")
            func_block = func_block.replace("~", " ")
            self.name = func_block.split("(")[0]
            tmp = func_block.split("(")[1].split(")")[0]
            for parameter in tmp.split(", "):
                arg = MPIArgument()
                arg.type =  parameter.split(' ')[-2]
                arg.name =  parameter.split(' ')[-1]
                if "*" in arg.name:
                    arg.name = arg.name.replace("*", "")
                    arg.type += "*"
                self.arguments.append(arg)

            tmp = func_block.split(")")[1].split("{")[1]
            self.ret_type = tmp.split("}")[0]
            self.signature = func_block.split("}")[0].split(self.name)[1]

            # debug output
            output_str = self.ret_type + " " + self.name + ": "
            for arg in self.arguments:
                output_str += arg.type + " " + arg.name + " " + arg.direction + " " + arg.length + ","
            #print output_str

    def update_argument_type(self, arg_name, arg_type):
        for arg in self.arguments:
            if arg_name == arg.name:
                arg.type = arg_type
                break

def initialize_mpi_functions(MPI_STANDARD_DIR):
    func_blocks = []
    chapters = glob.glob(MPI_STANDARD_DIR+'/chap*/*.tex')
    for tex_file in chapters:
        f = open(tex_file, 'r')
        lines = f.readlines()
        f.close()


        func_block = ""
        in_block = False
        for line in lines:

            if "begin{mpi-binding}" in line:
                in_block = True
                func_block = ""

            if "end{mpi-binding}" in line:
                in_block = False
                func_blocks.append(func_block)

            if in_block and line.strip() and "begin{" not in line:
                func_block += line.replace('\'', '\"')

            # For c2f and f2c functions
            if line.startswith("\mpiemptybindidx"):
                func_blocks.append( line.replace('\\', '') )

    funcs = {}
    for func_block in func_blocks:
        func = MPIFunction(func_block)

        if func.name:
            funcs[func.name] = func

    return funcs


def parse_args(signature):
    signature = signature.strip().replace('(', '').replace(')', '')
    args = signature.split(',')

    arg_types = []
    arg_names = []
    for arg in args:
        arg = arg.strip()
        if len(arg.split(' ')) < 2: continue

        arg_type = ' '.join( arg.split(' ')[0: -1] )
        arg_name = arg.split(' ')[-1]

        # Fix arg_type and arg_name
        if '*' in arg_name:      # sometimes its int* a, but sometimes its int *a;
            arg_type = arg_type + '*' * (arg_name.count('*'))
            arg_name = arg_name.replace('*', '')
        if '[' in arg_name:      # int a[]
            arg_type = arg_type + '[]' * (arg_name.count('['))
            arg_name = arg_name.split('[')[0]

        arg_types.append(arg_type)
        arg_names.append(arg_name)
    return arg_types, arg_names


def complete_mpi_functions(cnames_file, funcs):
    f = open(cnames_file, 'r')
    lines = f.readlines()
    f.close()

    for line in lines:
        line = line.strip().replace('ldots', '...')

        if not (line.startswith('\mpibind') or line.startswith('\mpiemptybindNOidx')):
            continue

        name, ret_type, signature= "", "", ""

        if line.startswith('\mpibind{'):
            line = line.replace('\mpibind{', '')
            line = line.replace('{', '').replace('}', '')
            line = line.replace('\\', '').replace('~', ' ')
            name = line.split('(')[0]
            ret_type = "int"
            signature = '(' + line.split('(')[1]
        elif line.startswith('\mpibindnotint{'):
            line = line.replace('\mpibindnotint{', '')
            line = line.replace('{', '').replace('}', '')
            line = line.replace('\\', '').replace('~', ' ')
            name = line.split(' ')[1].split('(')[0]
            ret_type = line.split(' ')[0]
            signature = '(' + line.split('(')[1]
        elif line.startswith('\mpiemptybindNOidx{'):
            # nothing needs change for c2f and f2c functions
            pass

        arg_types, arg_names = parse_args(signature)

        if name in funcs:
            funcs[name].ret_type = ret_type
            funcs[name].signature = signature
            for idx, arg_type in enumerate(arg_types):
                funcs[name].update_argument_type(arg_names[idx], arg_type)
        else:
            # TODO why?
            #print "HUH???", ret_type, name, signature
            pass

    # Clean up funcs, remove those with on return types, etc.
    # Basically compute an intersection of mpi-bind chap*/*.text and appLang-CNAMES.tex
    wait_for_clean = []
    for name in funcs:
        if not funcs[name].ret_type:
            wait_for_clean.append(name)
    for name in wait_for_clean:
        funcs.pop(name, None)


def set_comm_size(funcs):
    # TODO: ugly fix, in MPI_Waitall, MPI_Testall, MPI_Waitsome, MPI_Testsome
    # argument MPI_Status[] should have the length "count", but the MPI standard
    # latex does not specifiy it.
    funcs["MPI_Waitall"].arguments[2].length = "count"
    funcs["MPI_Testall"].arguments[3].length = "count"
    funcs["MPI_Testsome"].arguments[3].length = "incount"
    funcs["MPI_Testsome"].arguments[4].length = "incount"
    funcs["MPI_Waitsome"].arguments[3].length = "incount"
    funcs["MPI_Waitsome"].arguments[4].length = "incount"

    for name in funcs:
        func = funcs[name]
        arg_names = set( [arg.name for arg in func.arguments] )
        for arg in func.arguments:
            if ('[' in arg.type) and (not arg.length) and \
               ('char' not in arg.type) and ('comm' in arg_names):
                func.need_comm_size = True
                break



if __name__ == "__main__":

    MPI_STANDARD_DIR = sys.argv[1]

    # This does not give the function signature and argument type
    funcs = initialize_mpi_functions(MPI_STANDARD_DIR)
    print(len(funcs))


    # Retrive the signature and argument type from "appLang-CNames.tex"
    # Not this file has to be generated in advance from mpi-standard directory by calling MAKE-APPLANG
    complete_mpi_functions(MPI_STANDARD_DIR+"/appLang-CNames.tex", funcs)
    print(len(funcs))

    # Check if we need comm size to determine array arumgnet's length
    set_comm_size(funcs)

    f = open('mpi_functions.pickle', 'w')
    pickle.dump(funcs, f)
    f.close()
