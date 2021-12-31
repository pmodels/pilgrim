##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

#!/usr/bin/env python
# encoding: utf-8
import pickle, os
from codegen import MPIFunction, MPIArgument

def filter_with_local_mpi_functions(funcs):
    cleaned = {}

    os.system('grep -E "PMPI" /usr/include/mpich/*.h > /tmp/local_funcs.tmp')
    #os.system('grep -E "PMPI" /usr/tce/packages/impi/impi-2018.0-intel-19.1.0/include/*.h > /tmp/local_funcs.tmp')
    #os.system('grep -E "PMPI" /opt/pkgs/software/MPICH/3.3-GCC-7.2.0-2.29/include/*.h > /tmp/local_funcs.tmp')
    #os.system('grep -E "PMPI" /opt/intel/compilers_and_libraries_2020.0.166/linux/mpi/intel64/include/*.h > /tmp/local_funcs.tmp')
    f = open('/tmp/local_funcs.tmp', 'r')
    for line in f.readlines():
        if "#define" in line or "MPI_Fint" in line:
            continue

        func_name = line.strip().split('(')[0].split(' ')[1]
        func_name = func_name.replace('PMPI_', 'MPI_')
        if func_name in funcs:
            cleaned[func_name] = funcs[func_name]
    f.close()
    os.system('rm /tmp/local_funcs.tmp')

    return cleaned


def generate_function_id_file(funcs):
    function_id_file = open('../include/pilgrim_func_ids.h', 'w')
    function_id_file.write("/*\n * Copyright (C) by Argonne National Laboratory\n *     See COPYRIGHT in top-level directory\n */\n")
    function_id_file.write('/* This file is generated automatically, please do not change! */\n')
    function_id_file.write('#ifndef _PILGRIM_FUNC_IDS_H_\n#define _PILGRIM_FUNC_IDS_H_\n')

    idx = 0
    for name in funcs:
        function_id_file.write('#define ID_'+name+' '+str(idx)+'\n')
        idx += 1
    function_id_file.write('#define ID_free'+' '+str(idx)+'\n')


    function_id_file.write('static char *func_names[] = {\n')
    for name in funcs:
        function_id_file.write('"%s", \n' %name)
    function_id_file.write('"free", \n')
    function_id_file.write('};\n\n')

    function_id_file.write('#endif')
    function_id_file.close()

def is_mpi_object_arg(arg_type):
    # Do not include MPI_Request, MPI_Status, MPI_Comm, and MPI_Offset
    mpi_objects = set([
        "MPI_Info", "MPI_Datatype", "MPI_File", "MPI_Win", "MPI_Errhandler",
        "MPI_Group", "MPI_Op", "MPI_Message", "MPI_Comm", "MPI_Request"])
    if arg_type in mpi_objects:
        return True
    return False

def is_fortran_mpi_object(arg_type):
    if "MPI_" in arg_type and "MPI_Offset" not in arg_type \
        and "MPI_Aint" not in arg_type and "MPI_Count" not in arg_type:
            return True
    return False

# Return if this funciton is used to free a MPI object
# If so, also return the index of this MPI object
def is_mpi_object_release(func):
    release_funcs = set([
        "MPI_Info_free", "MPI_Type_free", "MPI_File_close", "MPI_Errhandler_free",
        "MPI_Win_free", "MPI_Group_free", "MPI_Op_free", "MPI_Comm_free"])
    if func.name in release_funcs:
        return True, 0
    elif func.name == "MPI_Imrecv" or func.name == "MPI_Mrecv":
        return True, 3
    return False, 0

def arg_type_strip(type_str):
    t = type_str.replace('*', '').replace('[', '').replace(']', '').replace(' ', '').replace('const', '')
    return t;

def codegen_assemble_args(func):
    line = ""
    assemble_args = []
    args_set = set( [arg.name for arg in func.arguments] )
    obj_count, buffer_count = 0, 0

    # First check if we need comm size to determine array arumgnet's length
    if func.need_comm_size:
        line += "\tint comm_size;\n"
        line += "\tPMPI_Comm_size(comm, &comm_size);\n"

    # Now iterate through every argument
    for arg in func.arguments:

        arg_name = None

        if 'void' in arg.type:                                  # void* buf
            line += "\tMemPtrAttr mem_attr_%d;\n" %buffer_count
            line += "\taddr2id(%s, &mem_attr_%d);\n" %(arg.name, buffer_count)
            arg_name =  "&mem_attr_%d" %buffer_count
            buffer_count+=1;
        elif 'MPI_Offset' in arg.type and '*' not in arg.type:  # keep separately
            line += "\tappend_offset(%s);\n" %(arg.name)
        elif 'MPI_Status*' in arg.type:
            line += "\tint status_arg[2] = {0};\n"
            arg_name = "status_arg"
            if "source" in args_set:
                line += "\tif(source == MPI_ANY_SOURCE && status && status!=MPI_STATUS_IGNORE) status_arg[0] = status->MPI_SOURCE;\n"
            if "recvtag" in args_set:
                line += "\tif(recvtag == MPI_ANY_TAG && status && status!=MPI_STATUS_IGNORE) status_arg[1] = status->MPI_TAG;\n"
            elif "tag" in args_set:
                line += "\tif(tag == MPI_ANY_TAG && status && status!=MPI_STATUS_IGNORE) status_arg[1] = status->MPI_TAG;\n"
        elif is_mpi_object_arg(arg_type_strip(arg.type)):
            if 'MPI_Request' in arg.type and '*' in arg.type:
                # These functions generate request id from signature-specific request id pool
                # src/dst, tag, and comm is enough for the signature. obj_id_1 is comm.
                func_id = "ID_" + func.name
                if (func.name == "MPI_Irecv" or func.name == "MPI_Recv_init"):
                    # Only these two functions need to store "source, tag" information
                    line += "\tint obj_id_%d = create_request_id(%s, false, %s, source, tag, obj_id_1);\n" %(obj_count, arg.name, func_id)
                    arg_name = "&obj_id_%d" %(obj_count)
                if func.name == "MPI_Isend":
                    line += "\tint obj_id_%d = create_request_id(%s, false, %s, dest, tag, obj_id_1);\n" %(obj_count, arg.name, func_id)
                    arg_name = "&obj_id_%d" %(obj_count)
            else:
                if '*' in arg.type:
                    line += "\tint obj_id_%d = MPI_OBJ_ID(%s, %s);\n" %(obj_count, arg_type_strip(arg.type), arg.name)
                    arg_name = "&obj_id_%d" %obj_count
                elif '[' in arg.type:
                    if arg.length:
                        line += "\tint obj_id_%d[%s];\n" %(obj_count, arg.length)
                        line += "\tfor(int i=0; i<%s; i++) obj_id_%d[i] = (%s==NULL) ? PILGRIM_INVALID_MPI_OBJECT_ID: MPI_OBJ_ID(%s, &%s[i]);\n" %(arg.length, obj_count, arg.name, arg_type_strip(arg.type), arg.name)
                    else:
                        line += "\tint obj_id_%d[comm_size];\n" %(obj_count)
                        line += "\tfor(int i=0; i<comm_size; i++) obj_id_%d[i] = (%s==NULL) ? PILGRIM_INVALID_MPI_OBJECT_ID: MPI_OBJ_ID(%s, &%s[i]);\n" %(obj_count, arg.name, arg_type_strip(arg.type), arg.name)
                    arg_name = "obj_id_%d" %obj_count
                else:
                    line += "\t%s obj_%d = %s;\n" %(arg.type, obj_count, arg.name)
                    line += "\tint obj_id_%d = MPI_OBJ_ID(%s, &obj_%d);\n" %(obj_count, arg_type_strip(arg.type), obj_count)
                    arg_name = "&obj_id_%d" %obj_count
            obj_count += 1
        elif '*' in arg.type or '[' in arg.type:
            arg_name = arg.name      # its already the adress
        elif 'int' in arg.type and ('source' in arg.name or 'dest' in arg.name):    # pattern recognization for src or dest ranks
            line += "\tint %s_rank = g_mpi_rank - %s;\n" %(arg.name, arg.name)
            line += "\tif(%s == MPI_ANY_SOURCE) %s_rank = PILGRIM_MPI_ANY_SOURCE;\n" %(arg.name, arg.name)
            line += "\tif(%s == MPI_PROC_NULL) %s_rank = PILGRIM_MPI_PROC_NULL;\n" %(arg.name, arg.name)
            arg_name =  "&%s_rank" %arg.name
        elif 'int' in arg.type and ('tag' == arg.name):    # pattern recognization for src or dest ranks
            line += "\tint my_tag = %s;\n" %(arg.name)
            line += "\tif(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;\n"
            arg_name = "&my_tag"
        else:
            arg_name = "&"+arg.name

        if arg_name: assemble_args.append(arg_name)

    if func.name == "MPI_Comm_rank":
        # For MPI_Comm_rank, we always set the last argument(output rank) to 0
        # So every process will have the same function signature.
        assemble_args[-1] = "&placeholder"

    if len(assemble_args) > 0:
        assemble_args_str = ', '.join(assemble_args)
        line += '\tvoid **args = assemble_args_list(%d, %s);\n' %(len(assemble_args), assemble_args_str)

        # Check if this is a MPI object free function
        free_mpi_object, arg_idx = is_mpi_object_release(func)
        if free_mpi_object:
            obj_type = arg_type_strip(func.arguments[arg_idx].type)
            obj_name = func.arguments[arg_idx].name
            line += '\tMPI_OBJ_RELEASE(%s, %s);\n' %(obj_type, obj_name)
    else:
        line = '\tvoid **args = NULL;\n'


    return line, len(assemble_args)

def codegen_sizeof_args(func):
    sizeof_args = []
    for arg in func.arguments:
        if 'void' in arg.type:
            sizeof_args.append('sizeof(MemPtrAttr)')                # memory buffer
        elif ('char[]' in arg.type or 'char*' in arg.type):
            if '**' not in arg.type and '*[]' not in arg.type:        # only consider one single string
                sizeof_args.append('strlen(%s)+1' %arg.name)
        elif 'MPI_Request' in arg.type:
            sizeof_args.append('sizeof(int)')
        elif 'MPI_Status' in arg.type:
            sizeof_args.append('sizeof(int)*2')
        elif 'MPI_Offset' in arg.type and '*' not in arg.type:  # keep separately
            continue
        elif is_mpi_object_arg(arg_type_strip(arg.type)):
            if '[' in arg.type:
                if arg.length:
                    sizeof_args.append('%s*sizeof(int)' %arg.length)
                else:
                    sizeof_args.append('(comm_size)*sizeof(int)') # first extra element is used to store this array count
            else:
                sizeof_args.append('sizeof(int)')
        elif '*' in arg.type or '[' in arg.type:
            n = 1
            if not arg.length:
                if func.need_comm_size:
                    n = "comm_size"
            else:
                n = arg.length
            fixed_type = arg.type.split('[')[0].replace('*', '')
            sizeof_args.append("%s*sizeof(%s)" %(n, fixed_type))
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

    # These are handled in pilgrim_wrappers_special.c
    ignored = ["MPI_Wait", "MPI_Waitany", "MPI_Waitsome", "MPI_Waitall", "MPI_Request_free", "MPI_Startall",
               "MPI_Test", "MPI_Testany", "MPI_Testsome", "MPI_Testall", "MPI_Pcontrol"]

    # These two do not required by the standard to have their PMPI counterpart
    # So we don't trace them
    ignored += ["MPI_Wtime", "MPI_Wtick"]

    if func.name in ignored:
        return True

    return False

def handle_mpi_comm_creation(func, f):
    intra_creation_funcs = set([
        "MPI_Comm_split", "MPI_Comm_dup", "MPI_Comm_dup_with_info",
        "MPI_Comm_create", "MPI_Comm_create_group", "MPI_Comm_split_type",
        "MPI_Cart_sub", "MPI_Dist_graph_create", "MPI_Dist_graph_create_adjacent",
        "MPI_Graph_create", "MPI_Cart_create", "MPI_Intercomm_merge"])
    if func.name in intra_creation_funcs:
        f.write("\tgenerate_intracomm_id(%s);\n" %func.arguments[-1].name)
    elif func.name == "MPI_Intercomm_create":
        f.write("\tgenerate_intercomm_id(%s, %s, %s);\n" %(func.arguments[0].name, func.arguments[5].name, func.arguments[4].name))
    elif func.name == "MPI_Comm_accept" or func.name == "MPI_Comm_connect":
        f.write("\tgenerate_intercomm_id(%s, %s, 0);\n" %(func.arguments[-2].name, func.arguments[-1].name))
    elif func.name == "MPI_Comm_spawn" or func.name == "MPI_Comm_spawn_multiple":
        f.write("\tgenerate_intercomm_id(%s, %s, 0);\n" %(func.arguments[-3].name, func.arguments[-2].name))

def generate_wrapper_file(funcs):
    import re

    def signature(func, f):
        line = func.ret_type + " imp_" + func.name + func.signature + "\n"
        f.write(line + '{\n')

    def phase_one(func, f):
        arg_names = []
        for arg in func.arguments:
            arg_names.append(arg.name)
        f.write('\tPILGRIM_TRACING_1(%s, %s, (%s));\n' %(func.ret_type, func.name, ', '.join(arg_names)))

    def phase_two(num_args, comm_size, f):
        f.write('\tPILGRIM_TRACING_2(%d, sizes, args, %s);\n}\n' %(num_args, comm_size))

    def actual_wrapper(func, f):
        arg_names = []
        for arg in func.arguments:
            arg_names.append(arg.name)
        actual_call = "imp_" + func.name + "(" + ", ".join(arg_names)+");"

        # C wrapper
        line = func.ret_type + " " + func.name + func.signature
        f.write(line + ' { return ' + actual_call + " }\n")

        # TODO ignore MPI_T_ functions for Fortran
        if "MPI_T_" in func.name:
            return

        # Fortran wrappers
        fortran_sig = "("
        for arg in func.arguments:
            type_str = arg.type
            name_str = arg.name
            if is_fortran_mpi_object(arg.type):
                type_str = "MPI_Fint*"
                name_str = name_str.replace("[]", "")
            if "[][]" in arg.type:      # [][3]
                type_str = type_str.replace("[][]", "")
                name_str = name_str + "[][3]"
            elif "[]" in arg.type:
                type_str = type_str.replace("[]", "")
                name_str = name_str + "[]"

            fortran_sig += type_str + " " +  name_str + ", "

        if fortran_sig == "(":
            fortran_sig = "()"
        else:
            fortran_sig = fortran_sig[0:-2] + ")"

        '''
        fortran_sig = re.sub(r'MPI_[^ ]* ', "MPI_Fint ", func.signature)
        fortran_sig = fortran_sig.replace('(int ', " (MPI_Fint ")
        fortran_sig = fortran_sig.replace(' int ', " MPI_Fint ")
        fortran_sig = fortran_sig.replace('MPI_Fint ', "MPI_Fint *")
        fortran_sig = fortran_sig.replace('MPI_Fint **', "MPI_Fint *")
        fortran_sig = fortran_sig.replace('[]', "")
        fortran_sig = fortran_sig.replace('(void)', "()")
        '''

        before_call = ""
        arg_names = []
        for arg in func.arguments:
            t = arg.type.replace("*", "").replace(" ","").replace("[]","").replace("const", "")
            if is_fortran_mpi_object(arg.type):
                if "*" in arg.type or "[]" in arg.type:
                    arg_names.append("(%s*)%s" %(t, arg.name))
                else:
                    if "MPI_Status" == t:
                        before_call = "PMPI_Status_f2c(%s, &g_c_status);" %(arg.name)
                        arg_names.append("&g_c_status")
                    elif "MPI_Datatype" == t:
                        arg_names.append("PMPI_Type_f2c(*%s)" %arg.name)
                    else:
                        arg_names.append("P%s_f2c(*%s)" %(t, arg.name))
            else:
                arg_names.append(arg.name)

        actual_call = "imp_" + func.name + "(" + ", ".join(arg_names)+");"

        if fortran_sig == "()":
            fortran_sig = "(MPI_Fint *ierr)"
        else:
            fortran_sig = fortran_sig.replace(")", ", MPI_Fint *ierr)")
        #f.write("extern void " + func.name.upper() + fortran_sig + "{ " + before_call+actual_call + "}\n")
        #f.write("extern void " + func.name.lower() + fortran_sig + "{ " + before_call+actual_call + "}\n")
        #f.write("extern void " + func.name.lower() + "_" + fortran_sig + "{ "+before_call+actual_call + "}\n")
        #f.write("extern void " + func.name.lower() + "__" + fortran_sig + "{ "+before_call+actual_call + "}\n")


    def logging(func, f):
        line, num_args = codegen_assemble_args(func)
        f.write(line)
        f.write(codegen_sizeof_args(func))
        return num_args

    f = open('../src/pilgrim_wrappers.c', 'w')
    f.write("/*\n * Copyright (C) by Argonne National Laboratory\n *     See COPYRIGHT in top-level directory\n */\n")
    f.write('#include <mpi.h>\n')
    f.write('#include <stdarg.h>\n')
    f.write('#include <stdlib.h>\n')
    f.write('#include <string.h>\n')
    f.write('#include "pilgrim.h"\n')
    f.write('#include "pilgrim_consts.h"\n')
    f.write('static int placeholder = 0;\n')
    f.write('MPI_Status g_c_status;\n')

    for name in funcs:
        func = funcs[name]

        if handle_special_apis(func):
            continue

        signature(func, f)

        if is_mpi_object_release(func)[0]:
            num_args = logging(func, f)
            phase_one(func, f)
        else:
            phase_one(func, f)
            handle_mpi_comm_creation(func, f)
            num_args = logging(func, f)

        comm_size = "comm_size" if func.need_comm_size else "-1"
        phase_two(num_args, comm_size, f)
        actual_wrapper(func, f)

    f.close()


if __name__ == "__main__":
    f = open("./mpi_functions.pickle", 'r')
    funcs = pickle.load(f)
    f.close()
    print("all: ", len(funcs))

    funcs = filter_with_local_mpi_functions(funcs)
    print("filtered: ", len(funcs))

    generate_function_id_file(funcs)
    generate_wrapper_file(funcs)
