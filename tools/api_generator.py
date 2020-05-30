#!/usr/bin/env python
# encoding: utf-8
import os, sys


MPI_STANDARD_TEX_FILES=["chap-pt2pt/pt2pt.tex",
        "chap-datatypes/datatypes.tex",
        "chap-coll/coll.tex",
        "chap-context/context.tex",
        "chap-topol/topol.tex",
        "chap-inquiry/inquiry.tex",
        "chap-misc/misc-2.tex",
        "chap-dynamic/dynamic-2.tex",
        "chap-one-side/one-side-2.tex",
        "chap-ei/ei-2.tex",
        "chap-io/io-2.tex",
        "chap-binding/binding-2.tex",
        "chap-tools/prof.tex",
        "chap-tools/mpit.tex",
        "chap-deprecated/deprecated.tex"
        ]

# We dont put these functions in the wrapper file
# They are handled in pilgrim_init_finalize.c
IGNORED_FUNCS = set(['MPI_Init', 'MPI_Init_thread', 'MPI_Finalize'])

def generate_api_signatures(MPI_STANDARD_DIR):
    open('1.c', 'w').close()    # create a empty file
    for chapter in MPI_STANDARD_TEX_FILES:
        #os.system('grep -E "mpibind|funcarg" %s >> 1.txt' %(path+'/'+chapter))
        os.system('grep -E "^[^%%]" %s > 1.c.tmp' %(MPI_STANDARD_DIR+'/'+chapter))  # ignore comments (lines start with % in .tex)
        os.system('grep -E "mpibind" 1.c.tmp >> 1.c && rm -rf 1.c.tmp')

    # remove latex marcos
    f = open('1.c', 'r')
    s = f.read()
    s = s.replace('~', ' ')
    s = s.replace('\\funcarg{\\IN}', 'IN ')
    s = s.replace('\\funcarg{\\OUT}', 'OUT ')
    s = s.replace('\\_', '_')
    s = s.replace('\\mpibind{', 'int ')
    s = s.replace('\\mpibindnotint{', '')
    s = s.replace('\\mpiemptybindidx{', 'void ')
    s = s.replace('\ldots', '...')
    s = s.replace('}', '')
    s = s.replace('MPI_info', 'MPI_Info')   # this is a tpyo in coll.tex
    f.close()

    f = open('1.c.tmp', 'w')
    f.write(s)
    f.close()
    os.rename('1.c.tmp', '1.c')

unique_types = set()
def assemble_arg_list(args):
    assemble_args = []
    sizeof_args = []

    arg_count = 0;
    for arg in args:
        arg = arg.strip()
        if len(arg.split(' ')) < 2: continue

        arg_count += 1
        arg_type = ' '.join( arg.split(' ')[0: -1] )
        arg_name = arg.split(' ')[-1]

        # Fix arg_type and arg_name
        if '*' in arg_name:      # sometimes its int* a, but sometimes its int *a;
            arg_name = arg_name.replace('*', '')
            arg_type = arg_type + '*'
        if '[' in arg_name:      # int a[]
            arg_name = arg_name.split('[')[0]
            arg_type = arg_type + '[]'  # TODO: 2d array [][]

        assemble_args.append( "&"+arg_name )
        unique_types.add(arg_type)

        if '[' in arg_type:
            sizeof_args.append("sizeof(%s)" %(arg_type.split('[')[0]))
        else:
            sizeof_args.append("sizeof(%s)" %arg_name)  # TODO: arrays


    line = '\tvoid **args = NULL;\n\tint* sizes = NULL;\n';
    if(arg_count > 0):
        assemble_args_str = ', '.join(assemble_args)
        sizeof_args_str = ', '.join(sizeof_args)

        line = '\tvoid **args = assemble_args_list(%d, %s);\n' %(arg_count, assemble_args_str)
        line += '\tint sizes[] = { %s };\n' %sizeof_args_str

    return arg_count, line



def tracing_instrumentation(vendor_funcs):
    f = open('1.c', 'r')
    lines = f.readlines()
    f.close()

    func_list_file = open('../include/pilgrim_func_ids.h', 'w')
    func_list_file.write('/* This file is generated automatically, please do not change! */\n')
    func_list_file.write('#ifndef _PILGRIM_FUNC_IDS_H_\n#define _PILGRIM_FUNC_IDS_H_\n')
    f = open('1.c', 'w')
    f.write('#include <mpi.h>\n')
    f.write('#include "pilgrim.h"\n')

    idx = 0
    for signature in lines:
        signature = signature.strip()
        ret_type = signature.split('(')[0].split(' ')[0]
        func = signature.split('(')[0].split(' ')[1]

        args = signature.split('(')[1].replace(')', '').replace('\n', '')
        arg_count, ass_str = assemble_arg_list(args.split(','))

        args = args.replace('*', '').split(',')
        args_str = ""

        for arg in args:
            arg = arg.strip()
            if len(arg.split(' ')) >= 2:
                arg_name = arg.split(' ')[-1].split('[')[0]
                args_str += arg_name + ', '
        args_str = "("+args_str[0:-2]+")"

        if func in vendor_funcs:
            idx += 1
            func_list_file.write('#define ID_'+func+' '+str(idx)+'\n')
            if func not in IGNORED_FUNCS:
                f.write(signature)
                f.write('\n{\n')
                f.write(ass_str)
                f.write('\tPILGRIM_TRACING(%s, %s, P%s, %d, sizes, args);\n}\n' %(ret_type, func, func+args_str, arg_count))

    func_list_file.write('#endif')
    f.close()
    func_list_file.close()
    os.system('mv 1.c ../src/pilgrim_wrappers.c')


# Get the function list of local mpi implementation
def get_vendor_funcs():
    funcs = set()
    os.system('grep -E "PMPI" /usr/include/mpi/*.h > funcs.tmp')
    f = open('funcs.tmp', 'r')
    for line in f.readlines():
        func = line.strip().split('(')[0].split(' ')[1]
        func = func.replace('PMPI_', 'MPI_')
        funcs.add(func)
    f.close()
    os.system('rm funcs.tmp')
    return funcs


if __name__ == "__main__":
    # 1. This generates signatures of all functions we can find in MPI standard
    generate_api_signatures(sys.argv[1])

    # 2. The local implementation may not support all MPI functions in the standard
    # We need make sure every function we trace is included in our local implementation
    vendor_funcs = get_vendor_funcs()

    tracing_instrumentation(vendor_funcs)
    #print('\n'.join(unique_types))


