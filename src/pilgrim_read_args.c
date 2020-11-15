/* This file is generated automatically. Do not change. */
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include "pilgrim.h"
void** read_record_args(int func_id, void* buff) {
    void **args;
    int size, length, pos;
    size_t n;
    switch(func_id) {
		case ID_MPI_Type_delete_attr:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Sendrecv_replace:
		{
			args = malloc(9 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_create:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_write_all_begin:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Error_class:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Free_mem:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_get_info:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Buffer_detach:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Aint_add:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Aint);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_flush_local_all:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_create_keyval:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm_copy_attr_function);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm_delete_attr_function);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_get_parent:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Testany:
		{
			read_record_args_special(func_id, buff);
			break;
		}
		case ID_MPI_T_cvar_handle_alloc:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_T_cvar_handle);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_idup:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_set_name:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_dup:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_pvar_get_index:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = strlen(buff+pos)+1;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Add_error_code:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_create_resized:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Get_address:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Iallgather:
		{
			args = malloc(8 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Get_count:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int)*2;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Grequest_start:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Grequest_query_function);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Grequest_free_function);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Grequest_cancel_function);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Cartdim_get:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Allgather:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Cart_coords:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			length = *((int*) (args[2]));
			size = length * sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_split_type:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Rsend:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_get_amode:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Neighbor_allgatherv:
		{
			args = malloc(8 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Info_create:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_create_f90_complex:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Status_set_elements_x:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int)*2;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Count);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_set_name:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_remote_group:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Cart_shift:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_size:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_pvar_get_num:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Request_free:
		{
			read_record_args_special(func_id, buff);
			break;
		}
		case ID_MPI_File_read_all_end:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Irsend:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_compare:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Ineighbor_alltoall:
		{
			args = malloc(8 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Query_thread:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_cvar_get_index:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = strlen(buff+pos)+1;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Allgatherv:
		{
			args = malloc(8 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Neighbor_allgather:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_category_get_pvars:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_free_keyval:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Op_create:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_User_function);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_enum_get_info:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_T_enum);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Ssend_init:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Rsend_init:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Igatherv:
		{
			args = malloc(10 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[9] = calloc(size, 1);
			memcpy(args[9], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Mrecv:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Group_excl:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Group);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_test_inter:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_read_all_begin:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_attach:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_read_at_all:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_read_ordered_end:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_set_attr:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Group_union:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Group);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_get_contents:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			length = *((int*) (args[2]));
			size = length * sizeof(MPI_Aint);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_lock:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_size_x:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Count);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_category_changed:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_set_info:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_pvar_stop:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_T_pvar_session);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_T_pvar_handle);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_get_envelope:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Send:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_delete_attr:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Finalize:
		{
			read_record_args_special(func_id, buff);
			break;
		}
		case ID_MPI_Type_create_hindexed_block:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[0]));
			size = length * sizeof(MPI_Aint);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Keyval_free:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Alloc_mem:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Aint);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_get_atomicity:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Dist_graph_create:
		{
			args = malloc(9 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_write_at:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_close:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_call_errhandler:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_flush_local:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_create_errhandler:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_File_errhandler_function);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Errhandler);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Group_free:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Group);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Ialltoall:
		{
			args = malloc(8 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_rank:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Cancel:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Request);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_post:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Group);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_commit:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_iwrite_shared:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_get_extent_x:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Count);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Count);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Probe:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Cart_get:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_flush:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Intercomm_create:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Allreduce:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_contiguous:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Reduce:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_get_position:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Offset);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Recv_init:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_group:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Is_thread_main:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_iwrite_all:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_create_indexed_block:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[0]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Wait:
		{
			read_record_args_special(func_id, buff);
			break;
		}
		case ID_MPI_Type_create_hindexed:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			length = *((int*) (args[0]));
			size = length * sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[0]));
			size = length * sizeof(MPI_Aint);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Dist_graph_neighbors:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			length = *((int*) (args[4]));
			size = length * sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Error_string:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_sync:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Ineighbor_allgatherv:
		{
			args = malloc(9 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Compare_and_swap:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_unlock_all:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_get_attr:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_disconnect:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_pvar_readreset:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_T_pvar_session);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_T_pvar_handle);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Attr_get:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_cvar_handle_free:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_T_cvar_handle);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_enum_get_item:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_T_enum);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_call_errhandler:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Group_compare:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Group);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Imrecv:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_category_get_index:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = strlen(buff+pos)+1;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Test_cancelled:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int)*2;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Buffer_attach:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_call_errhandler:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Graph_neighbors_count:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_get_position_shared:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Offset);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Cart_map:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_iread:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Dist_graph_neighbors_count:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_cvar_get_info:
		{
			args = malloc(10 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_T_enum);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[9] = calloc(size, 1);
			memcpy(args[9], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_pvar_read:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_T_pvar_session);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_T_pvar_handle);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_set_name:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Neighbor_alltoallw:
		{
			args = malloc(9 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Neighbor_alltoallv:
		{
			args = malloc(9 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Publish_name:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = strlen(buff+pos)+1;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_get_extent:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Graph_create:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Put:
		{
			args = malloc(8 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_create_dynamic:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Ibsend:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_complete:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Graph_map:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Info_get_valuelen:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Cart_sub:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Info_get:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_iwrite_at:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_spawn:
		{
			args = malloc(8 * sizeof(void*));
			pos = 0;
			size = strlen(buff+pos)+1;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Group_intersection:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Group);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Iallgatherv:
		{
			args = malloc(9 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Ibcast:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_read_at_all_begin:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Info_get_nthkey:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_get_size:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Offset);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Rput:
		{
			args = malloc(9 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_indexed:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			length = *((int*) (args[0]));
			size = length * sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[0]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Send_init:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_write:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_set_info:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_set_atomicity:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Graph_get:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			length = *((int*) (args[2]));
			size = length * sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Pack_external_size:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(char);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_create_darray:
		{
			args = malloc(10 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			length = *((int*) (args[2]));
			size = length * sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			length = *((int*) (args[2]));
			size = length * sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			length = *((int*) (args[2]));
			size = length * sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			length = *((int*) (args[2]));
			size = length * sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[9] = calloc(size, 1);
			memcpy(args[9], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_set_errhandler:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Errhandler);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_create_keyval:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Type_copy_attr_function);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Type_delete_attr_function);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_accept:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = strlen(buff+pos)+1;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_create_struct:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			length = *((int*) (args[0]));
			size = length * sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[0]));
			size = length * sizeof(MPI_Aint);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Gather:
		{
			args = malloc(8 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Close_port:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = strlen(buff+pos)+1;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_sync:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_create_subarray:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			length = *((int*) (args[0]));
			size = length * sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[0]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			length = *((int*) (args[0]));
			size = length * sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_free_keyval:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_write_at_all_end:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Rget_accumulate:
		{
			args = malloc(13 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[9] = calloc(size, 1);
			memcpy(args[9], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[10] = calloc(size, 1);
			memcpy(args[10], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[11] = calloc(size, 1);
			memcpy(args[11], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[12] = calloc(size, 1);
			memcpy(args[12], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Waitall:
		{
			read_record_args_special(func_id, buff);
			break;
		}
		case ID_MPI_Comm_delete_attr:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Testall:
		{
			read_record_args_special(func_id, buff);
			break;
		}
		case ID_MPI_Comm_create_errhandler:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm_errhandler_function);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Errhandler);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Barrier:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_get_attr:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_get_byte_offset:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Offset);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Waitsome:
		{
			read_record_args_special(func_id, buff);
			break;
		}
		case ID_MPI_Win_lock_all:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_get_name:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Group_range_excl:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Group);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_split:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_pvar_handle_alloc:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_T_pvar_session);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(MPI_T_pvar_handle);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_read_ordered_begin:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_read_ordered:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Attr_delete:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_get_errhandler:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Errhandler);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_get_info:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Info_dup:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_write_shared:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_iread_at:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_write_all_end:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_remote_size:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_get_name:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_write_at_all:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_get_group:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_preallocate:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_iread_all:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_cvar_write:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_T_cvar_handle);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Group_translate_ranks:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Group);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Testsome:
		{
			read_record_args_special(func_id, buff);
			break;
		}
		case ID_MPI_Type_create_hvector:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_get_attr:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Initialized:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_create_group:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Grequest_complete:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Request);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Get_accumulate:
		{
			args = malloc(12 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[9] = calloc(size, 1);
			memcpy(args[9], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[10] = calloc(size, 1);
			memcpy(args[10], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[11] = calloc(size, 1);
			memcpy(args[11], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_create_errhandler:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Win_errhandler_function);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Errhandler);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Init_thread:
		{
			read_record_args_special(func_id, buff);
			break;
		}
		case ID_MPI_Win_fence:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_category_get_info:
		{
			args = malloc(8 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Group_difference:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Group);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_pvar_start:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_T_pvar_session);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_T_pvar_handle);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_get_name:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_wait:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Scatterv:
		{
			args = malloc(9 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_write_all:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_connect:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = strlen(buff+pos)+1;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_flush_all:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_get_group:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_set_size:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Status_set_cancelled:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int)*2;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Reduce_local:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_pvar_write:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_T_pvar_session);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_T_pvar_handle);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Graph_neighbors:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			length = *((int*) (args[2]));
			size = length * sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Dims_create:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Scatter:
		{
			args = malloc(8 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Ireduce_scatter_block:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Ialltoallw:
		{
			args = malloc(10 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[9] = calloc(size, 1);
			memcpy(args[9], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Ialltoallv:
		{
			args = malloc(10 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[9] = calloc(size, 1);
			memcpy(args[9], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_free:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_cvar_read:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_T_cvar_handle);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Neighbor_alltoall:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Alltoall:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_spawn_multiple:
		{
			args = malloc(9 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			length = *((int*) (args[0]));
			size = length * sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_dup_with_info:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Pcontrol:
		{
			read_record_args_special(func_id, buff);
			break;
		}
		case ID_MPI_T_pvar_handle_free:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_T_pvar_session);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_T_pvar_handle);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_free:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_test:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_write_at_all_begin:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_get_errhandler:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Errhandler);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Mprobe:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Info_get_nkeys:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Finalized:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Op_commutative:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Dist_graph_create_adjacent:
		{
			args = malloc(10 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			length = *((int*) (args[4]));
			size = length * sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[9] = calloc(size, 1);
			memcpy(args[9], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Info_delete:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_iread_at_all:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Cart_rank:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_read_at:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Iallreduce:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_size:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Fetch_and_op:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Reduce_scatter_block:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Rget:
		{
			args = malloc(9 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_set_attr:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_create_f90_integer:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Iscatterv:
		{
			args = malloc(10 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[9] = calloc(size, 1);
			memcpy(args[9], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_delete:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = strlen(buff+pos)+1;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_read_all:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Group_size:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Group);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Attr_put:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Iscatter:
		{
			args = malloc(9 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_start:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Group);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_free:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Alltoallw:
		{
			args = malloc(9 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Alltoallv:
		{
			args = malloc(9 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Exscan:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Op_free:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Iscan:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Keyval_create:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Copy_function);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Delete_function);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_vector:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_create_keyval:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Win_copy_attr_function);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Win_delete_attr_function);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_match_size:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Scan:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Startall:
		{
			read_record_args_special(func_id, buff);
			break;
		}
		case ID_MPI_File_seek_shared:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Wtime:
		{
			args = malloc(0 * sizeof(void*));
			pos = 0;
			break;
		}
		case ID_MPI_Add_error_class:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Igather:
		{
			args = malloc(9 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Info_free:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Open_port:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_allocate:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Aint);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_set_info:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Unpublish_name:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = strlen(buff+pos)+1;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Group_rank:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Group);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Lookup_name:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = strlen(buff+pos)+1;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Recv:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_free_keyval:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_get_info:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_pvar_session_create:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_T_pvar_session);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_init_thread:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_open:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Bsend:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Ireduce_scatter:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Irecv:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Issend:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_iwrite_at_all:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Abort:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Pack:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_iwrite:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Gatherv:
		{
			args = malloc(9 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_create:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_write_ordered:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_dup:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_finalize:
		{
			args = malloc(0 * sizeof(void*));
			pos = 0;
			break;
		}
		case ID_MPI_File_iread_shared:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_set_errhandler:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Errhandler);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Register_datarep:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = strlen(buff+pos)+1;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Datarep_conversion_function);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Datarep_conversion_function);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Datarep_extent_function);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Init:
		{
			read_record_args_special(func_id, buff);
			break;
		}
		case ID_MPI_Reduce_scatter:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Ibarrier:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_create_f90_real:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_seek:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_cvar_get_num:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Group_incl:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Group);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Get_version:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Pack_external:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(char);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_read:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_get_true_extent:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Cart_create:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Sendrecv:
		{
			args = malloc(12 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[9] = calloc(size, 1);
			memcpy(args[9], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[10] = calloc(size, 1);
			memcpy(args[10], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[11] = calloc(size, 1);
			memcpy(args[11], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_shared_query:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_set_attr:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_allocate_shared:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Aint);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Type_get_true_extent_x:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Count);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Count);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Bcast:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Get_processor_name:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = strlen(buff+pos)+1;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Info_set:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Ineighbor_allgather:
		{
			args = malloc(8 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Raccumulate:
		{
			args = malloc(10 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[9] = calloc(size, 1);
			memcpy(args[9], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Pack_size:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Intercomm_merge:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_get_type_extent:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Get_library_version:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = strlen(buff+pos)+1;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Isend:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_pvar_reset:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_T_pvar_session);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_T_pvar_handle);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Start:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Request);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Unpack:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_get_view:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Offset);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_pvar_session_free:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_T_pvar_session);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Iexscan:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Unpack_external:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(char);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_unlock:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Test:
		{
			read_record_args_special(func_id, buff);
			break;
		}
		case ID_MPI_Request_get_status:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Request);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Waitany:
		{
			read_record_args_special(func_id, buff);
			break;
		}
		case ID_MPI_File_read_at_all_end:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_set_view:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Status_set_elements:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int)*2;
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_category_get_categories:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Group_range_incl:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Group);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Group);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Get:
		{
			args = malloc(8 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Iprobe:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_join:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_read_shared:
		{
			args = malloc(5 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Win_detach:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Improbe:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Ssend:
		{
			args = malloc(6 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Ineighbor_alltoallw:
		{
			args = malloc(10 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[9] = calloc(size, 1);
			memcpy(args[9], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Ineighbor_alltoallv:
		{
			args = malloc(10 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[9] = calloc(size, 1);
			memcpy(args[9], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Wtick:
		{
			args = malloc(0 * sizeof(void*));
			pos = 0;
			break;
		}
		case ID_MPI_T_category_get_cvars:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			length = *((int*) (args[1]));
			size = length * sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Errhandler_free:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Errhandler);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Topo_test:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Ireduce:
		{
			args = malloc(8 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_get_errhandler:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Errhandler);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Bsend_init:
		{
			args = malloc(7 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Request);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Add_error_string:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Accumulate:
		{
			args = malloc(9 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_category_get_num:
		{
			args = malloc(1 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Comm_set_errhandler:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Errhandler);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Aint_diff:
		{
			args = malloc(2 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Aint);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(MPI_Aint);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_write_ordered_begin:
		{
			args = malloc(4 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_File_write_ordered_end:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int)*2;
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_Graphdims_get:
		{
			args = malloc(3 * sizeof(void*));
			pos = 0;
			size = sizeof(MPI_Comm)+sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			break;
		}
		case ID_MPI_T_pvar_get_info:
		{
			args = malloc(13 * sizeof(void*));
			pos = 0;
			size = sizeof(int);
			args[0] = calloc(size, 1);
			memcpy(args[0], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[1] = calloc(size, 1);
			memcpy(args[1], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[2] = calloc(size, 1);
			memcpy(args[2], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[3] = calloc(size, 1);
			memcpy(args[3], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[4] = calloc(size, 1);
			memcpy(args[4], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[5] = calloc(size, 1);
			memcpy(args[5], buff+pos, size);
			pos += size;
			size = sizeof(MPI_T_enum);
			args[6] = calloc(size, 1);
			memcpy(args[6], buff+pos, size);
			pos += size;
			size = strlen(buff+pos)+1;
			args[7] = calloc(size, 1);
			memcpy(args[7], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[8] = calloc(size, 1);
			memcpy(args[8], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[9] = calloc(size, 1);
			memcpy(args[9], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[10] = calloc(size, 1);
			memcpy(args[10], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[11] = calloc(size, 1);
			memcpy(args[11], buff+pos, size);
			pos += size;
			size = sizeof(int);
			args[12] = calloc(size, 1);
			memcpy(args[12], buff+pos, size);
			pos += size;
			break;
		}
	}
	return args;
}
