#include <mpi.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "pilgrim.h"
int MPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval)
{
	PILGRIM_TRACING_1(int, MPI_Type_delete_attr, (datatype, type_keyval));
	void **args = assemble_args_list(2, &datatype, &type_keyval);
	int sizes[] = { sizeof(MPI_Datatype), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Sendrecv_replace, (buf, count, datatype, dest, sendtag, source, recvtag, comm, status));
	void **args = assemble_args_list(8, addr2id(buf), &count, &datatype, &dest, &sendtag, &source, &recvtag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(8, sizes, args);
}
int MPI_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win)
{
	PILGRIM_TRACING_1(int, MPI_Win_create, (base, size, disp_unit, info, comm, win));
	void **args = assemble_args_list(6, addr2id(base), &size, &disp_unit, &info, &comm, win);
	int sizes[] = { sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(MPI_Info), sizeof(MPI_Comm), 1 * sizeof(MPI_Win) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_File_write_all_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype)
{
	PILGRIM_TRACING_1(int, MPI_File_write_all_begin, (fh, buf, count, datatype));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Error_class(int errorcode, int *errorclass)
{
	PILGRIM_TRACING_1(int, MPI_Error_class, (errorcode, errorclass));
	void **args = assemble_args_list(2, &errorcode, errorclass);
	int sizes[] = { sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Free_mem(void *base)
{
	PILGRIM_TRACING_1(int, MPI_Free_mem, (base));
	void **args = assemble_args_list(1, addr2id(base));
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Win_get_info(MPI_Win win, MPI_Info *info_used)
{
	PILGRIM_TRACING_1(int, MPI_Win_get_info, (win, info_used));
	void **args = assemble_args_list(2, &win, info_used);
	int sizes[] = { sizeof(MPI_Win), 1 * sizeof(MPI_Info) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Buffer_detach(void *buffer_addr, int *size)
{
	PILGRIM_TRACING_1(int, MPI_Buffer_detach, (buffer_addr, size));
	void **args = assemble_args_list(2, addr2id(buffer_addr), size);
	int sizes[] = { sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
MPI_Aint MPI_Aint_add(MPI_Aint base, MPI_Aint disp)
{
	PILGRIM_TRACING_1(MPI_Aint, MPI_Aint_add, (base, disp));
	void **args = assemble_args_list(2, &base, &disp);
	int sizes[] = { sizeof(MPI_Aint), sizeof(MPI_Aint) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Win_flush_local_all(MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_flush_local_all, (win));
	void **args = assemble_args_list(1, &win);
	int sizes[] = { sizeof(MPI_Win) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn, MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval, void *extra_state)
{
	PILGRIM_TRACING_1(int, MPI_Comm_create_keyval, (comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state));
	void **args = assemble_args_list(4, comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, addr2id(extra_state));
	int sizes[] = { 1 * sizeof(MPI_Comm_copy_attr_function), 1 * sizeof(MPI_Comm_delete_attr_function), 1 * sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Comm_get_parent(MPI_Comm *parent)
{
	PILGRIM_TRACING_1(int, MPI_Comm_get_parent, (parent));
	void **args = assemble_args_list(1, parent);
	int sizes[] = { 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Testany(int count, MPI_Request array_of_requests[], int *index, int *flag, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Testany, (count, array_of_requests, index, flag, status));
	void **args = assemble_args_list(3, &count, index, flag);
	int sizes[] = { sizeof(int), 1 * sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle, MPI_T_cvar_handle *handle, int *count)
{
	PILGRIM_TRACING_1(int, MPI_T_cvar_handle_alloc, (cvar_index, obj_handle, handle, count));
	void **args = assemble_args_list(4, &cvar_index, addr2id(obj_handle), handle, count);
	int sizes[] = { sizeof(int), sizeof(int), 1 * sizeof(MPI_T_cvar_handle), 1 * sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Comm_idup, (comm, newcomm, request));
	void **args = assemble_args_list(2, &comm, newcomm);
	int sizes[] = { sizeof(MPI_Comm), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Win_set_name(MPI_Win win, const char *win_name)
{
	PILGRIM_TRACING_1(int, MPI_Win_set_name, (win, win_name));
	void **args = assemble_args_list(2, &win, win_name);
	int sizes[] = { sizeof(MPI_Win), strlen(win_name)+1 };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_dup, (oldtype, newtype));
	void **args = assemble_args_list(2, &oldtype, newtype);
	int sizes[] = { sizeof(MPI_Datatype), 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_T_pvar_get_index(const char *name, int var_class, int *pvar_index)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_get_index, (name, var_class, pvar_index));
	void **args = assemble_args_list(3, name, &var_class, pvar_index);
	int sizes[] = { strlen(name)+1, sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Add_error_code(int errorclass, int *errorcode)
{
	PILGRIM_TRACING_1(int, MPI_Add_error_code, (errorclass, errorcode));
	void **args = assemble_args_list(2, &errorclass, errorcode);
	int sizes[] = { sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_resized, (oldtype, lb, extent, newtype));
	void **args = assemble_args_list(4, &oldtype, &lb, &extent, newtype);
	int sizes[] = { sizeof(MPI_Datatype), sizeof(MPI_Aint), sizeof(MPI_Aint), 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Get_address(const void *location, MPI_Aint *address)
{
	PILGRIM_TRACING_1(int, MPI_Get_address, (location, address));
	void **args = assemble_args_list(2, addr2id(location), address);
	int sizes[] = { sizeof(int), 1 * sizeof(MPI_Aint) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Iallgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Iallgather, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request));
	void **args = assemble_args_list(7, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), &recvcount, &recvtype, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype, int *count)
{
	PILGRIM_TRACING_1(int, MPI_Get_count, (status, datatype, count));
	void **args = assemble_args_list(2, &datatype, count);
	int sizes[] = { sizeof(MPI_Datatype), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Grequest_start(MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn, MPI_Grequest_cancel_function *cancel_fn, void *extra_state, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Grequest_start, (query_fn, free_fn, cancel_fn, extra_state, request));
	void **args = assemble_args_list(4, query_fn, free_fn, cancel_fn, addr2id(extra_state));
	int sizes[] = { 1 * sizeof(MPI_Grequest_query_function), 1 * sizeof(MPI_Grequest_free_function), 1 * sizeof(MPI_Grequest_cancel_function), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Cartdim_get(MPI_Comm comm, int *ndims)
{
	PILGRIM_TRACING_1(int, MPI_Cartdim_get, (comm, ndims));
	void **args = assemble_args_list(2, &comm, ndims);
	int sizes[] = { sizeof(MPI_Comm), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Allgather, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm));
	void **args = assemble_args_list(7, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), &recvcount, &recvtype, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[])
{
	PILGRIM_TRACING_1(int, MPI_Cart_coords, (comm, rank, maxdims, coords));
	void **args = assemble_args_list(4, &comm, &rank, &maxdims, coords);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), sizeof(int), maxdims * sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Comm_split_type(MPI_Comm comm, int split_type, int key, MPI_Info info, MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_split_type, (comm, split_type, key, info, newcomm));
	void **args = assemble_args_list(5, &comm, &split_type, &key, &info, newcomm);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), sizeof(int), sizeof(MPI_Info), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Rsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Rsend, (buf, count, datatype, dest, tag, comm));
	void **args = assemble_args_list(6, addr2id(buf), &count, &datatype, &dest, &tag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_File_get_amode(MPI_File fh, int *amode)
{
	PILGRIM_TRACING_1(int, MPI_File_get_amode, (fh, amode));
	void **args = assemble_args_list(2, &fh, amode);
	int sizes[] = { sizeof(MPI_File), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Neighbor_allgatherv, (sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm));
	void **args = assemble_args_list(8, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), recvcounts, displs, &recvtype, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(8, sizes, args);
}
int MPI_Info_create(MPI_Info *info)
{
	PILGRIM_TRACING_1(int, MPI_Info_create, (info));
	void **args = assemble_args_list(1, info);
	int sizes[] = { 1 * sizeof(MPI_Info) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Type_create_f90_complex(int p, int r, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_f90_complex, (p, r, newtype));
	void **args = assemble_args_list(3, &p, &r, newtype);
	int sizes[] = { sizeof(int), sizeof(int), 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Status_set_elements_x(MPI_Status *status, MPI_Datatype datatype, MPI_Count count)
{
	PILGRIM_TRACING_1(int, MPI_Status_set_elements_x, (status, datatype, count));
	void **args = assemble_args_list(2, &datatype, &count);
	int sizes[] = { sizeof(MPI_Datatype), sizeof(MPI_Count) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Comm_set_name(MPI_Comm comm, const char *comm_name)
{
	PILGRIM_TRACING_1(int, MPI_Comm_set_name, (comm, comm_name));
	void **args = assemble_args_list(2, &comm, comm_name);
	int sizes[] = { sizeof(MPI_Comm), strlen(comm_name)+1 };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group)
{
	PILGRIM_TRACING_1(int, MPI_Comm_remote_group, (comm, group));
	void **args = assemble_args_list(2, &comm, group);
	int sizes[] = { sizeof(MPI_Comm), 1 * sizeof(MPI_Group) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest)
{
	PILGRIM_TRACING_1(int, MPI_Cart_shift, (comm, direction, disp, rank_source, rank_dest));
	void **args = assemble_args_list(5, &comm, &direction, &disp, rank_source, rank_dest);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), sizeof(int), 1 * sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Comm_size(MPI_Comm comm, int *size)
{
	PILGRIM_TRACING_1(int, MPI_Comm_size, (comm, size));
	void **args = assemble_args_list(2, &comm, size);
	int sizes[] = { sizeof(MPI_Comm), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_T_pvar_get_num(int *num_pvar)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_get_num, (num_pvar));
	void **args = assemble_args_list(1, num_pvar);
	int sizes[] = { 1 * sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Request_free(MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Request_free, (request));
	void **args = NULL;
	int* sizes = NULL;
	PILGRIM_TRACING_2(0, sizes, args);
}
int MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read_all_end, (fh, buf, status));
	void **args = assemble_args_list(2, &fh, addr2id(buf));
	int sizes[] = { sizeof(MPI_File), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Irsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Irsend, (buf, count, datatype, dest, tag, comm, request));
	void **args = assemble_args_list(6, addr2id(buf), &count, &datatype, &dest, &tag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result)
{
	PILGRIM_TRACING_1(int, MPI_Comm_compare, (comm1, comm2, result));
	void **args = assemble_args_list(3, &comm1, &comm2, result);
	int sizes[] = { sizeof(MPI_Comm), sizeof(MPI_Comm), 1 * sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Ineighbor_alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ineighbor_alltoall, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request));
	void **args = assemble_args_list(7, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), &recvcount, &recvtype, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_Query_thread(int *provided)
{
	PILGRIM_TRACING_1(int, MPI_Query_thread, (provided));
	void **args = assemble_args_list(1, provided);
	int sizes[] = { 1 * sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_T_cvar_get_index(const char *name, int *cvar_index)
{
	PILGRIM_TRACING_1(int, MPI_T_cvar_get_index, (name, cvar_index));
	void **args = assemble_args_list(2, name, cvar_index);
	int sizes[] = { strlen(name)+1, 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Allgatherv, (sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm));
	void **args = assemble_args_list(8, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), recvcounts, displs, &recvtype, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(8, sizes, args);
}
int MPI_Neighbor_allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Neighbor_allgather, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm));
	void **args = assemble_args_list(7, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), &recvcount, &recvtype, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_T_category_get_pvars(int cat_index, int len, int indices[])
{
	PILGRIM_TRACING_1(int, MPI_T_category_get_pvars, (cat_index, len, indices));
	void **args = assemble_args_list(3, &cat_index, &len, indices);
	int sizes[] = { sizeof(int), sizeof(int), len * sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Comm_free_keyval(int *comm_keyval)
{
	PILGRIM_TRACING_1(int, MPI_Comm_free_keyval, (comm_keyval));
	void **args = assemble_args_list(1, comm_keyval);
	int sizes[] = { 1 * sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op)
{
	PILGRIM_TRACING_1(int, MPI_Op_create, (user_fn, commute, op));
	void **args = assemble_args_list(3, user_fn, &commute, op);
	int sizes[] = { 1 * sizeof(MPI_User_function), sizeof(int), 1 * sizeof(MPI_Op) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name, int *name_len)
{
	PILGRIM_TRACING_1(int, MPI_T_enum_get_info, (enumtype, num, name, name_len));
	void **args = assemble_args_list(4, &enumtype, num, name, name_len);
	int sizes[] = { sizeof(MPI_T_enum), 1 * sizeof(int), strlen(name)+1, 1 * sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Ssend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ssend_init, (buf, count, datatype, dest, tag, comm, request));
	void **args = assemble_args_list(6, addr2id(buf), &count, &datatype, &dest, &tag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Rsend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Rsend_init, (buf, count, datatype, dest, tag, comm, request));
	void **args = assemble_args_list(6, addr2id(buf), &count, &datatype, &dest, &tag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Igatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Igatherv, (sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request));
	void **args = assemble_args_list(9, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), recvcounts, displs, &recvtype, &root, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(9, sizes, args);
}
int MPI_Mrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Mrecv, (buf, count, datatype, message, status));
	void **args = assemble_args_list(4, addr2id(buf), &count, &datatype, message);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), 1 * sizeof(MPI_Message) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Group_excl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup)
{
	PILGRIM_TRACING_1(int, MPI_Group_excl, (group, n, ranks, newgroup));
	void **args = assemble_args_list(4, &group, &n, ranks, newgroup);
	int sizes[] = { sizeof(MPI_Group), sizeof(int), n * sizeof(const int), 1 * sizeof(MPI_Group) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Comm_test_inter(MPI_Comm comm, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Comm_test_inter, (comm, flag));
	void **args = assemble_args_list(2, &comm, flag);
	int sizes[] = { sizeof(MPI_Comm), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype)
{
	PILGRIM_TRACING_1(int, MPI_File_read_all_begin, (fh, buf, count, datatype));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size)
{
	PILGRIM_TRACING_1(int, MPI_Win_attach, (win, base, size));
	void **args = assemble_args_list(3, &win, addr2id(base), &size);
	int sizes[] = { sizeof(MPI_Win), sizeof(int), sizeof(MPI_Aint) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read_at_all, (fh, offset, buf, count, datatype, status));
	void **args = assemble_args_list(5, &fh, &offset, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Offset), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read_ordered_end, (fh, buf, status));
	void **args = assemble_args_list(2, &fh, addr2id(buf));
	int sizes[] = { sizeof(MPI_File), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Type_set_attr(MPI_Datatype datatype, int type_keyval, void *attribute_val)
{
	PILGRIM_TRACING_1(int, MPI_Type_set_attr, (datatype, type_keyval, attribute_val));
	void **args = assemble_args_list(3, &datatype, &type_keyval, addr2id(attribute_val));
	int sizes[] = { sizeof(MPI_Datatype), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup)
{
	PILGRIM_TRACING_1(int, MPI_Group_union, (group1, group2, newgroup));
	void **args = assemble_args_list(3, &group1, &group2, newgroup);
	int sizes[] = { sizeof(MPI_Group), sizeof(MPI_Group), 1 * sizeof(MPI_Group) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Type_get_contents(MPI_Datatype datatype, int max_integers, int max_addresses, int max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Datatype array_of_datatypes[])
{
	PILGRIM_TRACING_1(int, MPI_Type_get_contents, (datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes));
	void **args = assemble_args_list(7, &datatype, &max_integers, &max_addresses, &max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes);
	int sizes[] = { sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(int), max_integers * sizeof(int), max_addresses * sizeof(MPI_Aint), max_datatypes * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_lock, (lock_type, rank, assert, win));
	void **args = assemble_args_list(4, &lock_type, &rank, &assert, &win);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size)
{
	PILGRIM_TRACING_1(int, MPI_Type_size_x, (datatype, size));
	void **args = assemble_args_list(2, &datatype, size);
	int sizes[] = { sizeof(MPI_Datatype), 1 * sizeof(MPI_Count) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_T_category_changed(int *stamp)
{
	PILGRIM_TRACING_1(int, MPI_T_category_changed, (stamp));
	void **args = assemble_args_list(1, stamp);
	int sizes[] = { 1 * sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Comm_set_info(MPI_Comm comm, MPI_Info info)
{
	PILGRIM_TRACING_1(int, MPI_Comm_set_info, (comm, info));
	void **args = assemble_args_list(2, &comm, &info);
	int sizes[] = { sizeof(MPI_Comm), sizeof(MPI_Info) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_T_pvar_stop(MPI_T_pvar_session session, MPI_T_pvar_handle handle)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_stop, (session, handle));
	void **args = assemble_args_list(2, &session, &handle);
	int sizes[] = { sizeof(MPI_T_pvar_session), sizeof(MPI_T_pvar_handle) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner)
{
	PILGRIM_TRACING_1(int, MPI_Type_get_envelope, (datatype, num_integers, num_addresses, num_datatypes, combiner));
	void **args = assemble_args_list(5, &datatype, num_integers, num_addresses, num_datatypes, combiner);
	int sizes[] = { sizeof(MPI_Datatype), 1 * sizeof(int), 1 * sizeof(int), 1 * sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Send, (buf, count, datatype, dest, tag, comm));
	void **args = assemble_args_list(6, addr2id(buf), &count, &datatype, &dest, &tag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Win_delete_attr(MPI_Win win, int win_keyval)
{
	PILGRIM_TRACING_1(int, MPI_Win_delete_attr, (win, win_keyval));
	void **args = assemble_args_list(2, &win, &win_keyval);
	int sizes[] = { sizeof(MPI_Win), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Type_create_hindexed_block(int count, int blocklength, const MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_hindexed_block, (count, blocklength, array_of_displacements, oldtype, newtype));
	void **args = assemble_args_list(5, &count, &blocklength, array_of_displacements, &oldtype, newtype);
	int sizes[] = { sizeof(int), sizeof(int), count * sizeof(const MPI_Aint), sizeof(MPI_Datatype), 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Keyval_free(int *keyval)
{
	PILGRIM_TRACING_1(int, MPI_Keyval_free, (keyval));
	void **args = assemble_args_list(1, keyval);
	int sizes[] = { 1 * sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr)
{
	PILGRIM_TRACING_1(int, MPI_Alloc_mem, (size, info, baseptr));
	void **args = assemble_args_list(3, &size, &info, addr2id(baseptr));
	int sizes[] = { sizeof(MPI_Aint), sizeof(MPI_Info), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_File_get_atomicity(MPI_File fh, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_File_get_atomicity, (fh, flag));
	void **args = assemble_args_list(2, &fh, flag);
	int sizes[] = { sizeof(MPI_File), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Dist_graph_create(MPI_Comm comm_old, int n, const int sources[], const int degrees[], const int destinations[], const int weights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph)
{
	PILGRIM_TRACING_1(int, MPI_Dist_graph_create, (comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph));
	void **args = assemble_args_list(9, &comm_old, &n, sources, degrees, destinations, weights, &info, &reorder, comm_dist_graph);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), n * sizeof(const int), n * sizeof(const int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Info), sizeof(int), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(9, sizes, args);
}
int MPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write_at, (fh, offset, buf, count, datatype, status));
	void **args = assemble_args_list(5, &fh, &offset, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Offset), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_File_close(MPI_File *fh)
{
	PILGRIM_TRACING_1(int, MPI_File_close, (fh));
	void **args = assemble_args_list(1, fh);
	int sizes[] = { 1 * sizeof(MPI_File) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode)
{
	PILGRIM_TRACING_1(int, MPI_Comm_call_errhandler, (comm, errorcode));
	void **args = assemble_args_list(2, &comm, &errorcode);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Win_flush_local(int rank, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_flush_local, (rank, win));
	void **args = assemble_args_list(2, &rank, &win);
	int sizes[] = { sizeof(int), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_File_create_errhandler(MPI_File_errhandler_function *file_errhandler_fn, MPI_Errhandler *errhandler)
{
	PILGRIM_TRACING_1(int, MPI_File_create_errhandler, (file_errhandler_fn, errhandler));
	void **args = assemble_args_list(2, file_errhandler_fn, errhandler);
	int sizes[] = { 1 * sizeof(MPI_File_errhandler_function), 1 * sizeof(MPI_Errhandler) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Group_free(MPI_Group *group)
{
	PILGRIM_TRACING_1(int, MPI_Group_free, (group));
	void **args = assemble_args_list(1, group);
	int sizes[] = { 1 * sizeof(MPI_Group) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Ialltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ialltoall, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request));
	void **args = assemble_args_list(7, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), &recvcount, &recvtype, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_Comm_rank(MPI_Comm comm, int *rank)
{
	PILGRIM_TRACING_1(int, MPI_Comm_rank, (comm, rank));
	void **args = assemble_args_list(2, &comm, rank);
	int sizes[] = { sizeof(MPI_Comm), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Cancel(MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Cancel, (request));
	void **args = NULL;
	int* sizes = NULL;
	PILGRIM_TRACING_2(0, sizes, args);
}
int MPI_Win_post(MPI_Group group, int assert, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_post, (group, assert, win));
	void **args = assemble_args_list(3, &group, &assert, &win);
	int sizes[] = { sizeof(MPI_Group), sizeof(int), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Type_commit(MPI_Datatype *datatype)
{
	PILGRIM_TRACING_1(int, MPI_Type_commit, (datatype));
	void **args = assemble_args_list(1, datatype);
	int sizes[] = { 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_File_iwrite_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iwrite_shared, (fh, buf, count, datatype, request));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb, MPI_Count *extent)
{
	PILGRIM_TRACING_1(int, MPI_Type_get_extent_x, (datatype, lb, extent));
	void **args = assemble_args_list(3, &datatype, lb, extent);
	int sizes[] = { sizeof(MPI_Datatype), 1 * sizeof(MPI_Count), 1 * sizeof(MPI_Count) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Probe, (source, tag, comm, status));
	void **args = assemble_args_list(3, &source, &tag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[])
{
	PILGRIM_TRACING_1(int, MPI_Cart_get, (comm, maxdims, dims, periods, coords));
	void **args = assemble_args_list(5, &comm, &maxdims, dims, periods, coords);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), maxdims * sizeof(int), maxdims * sizeof(int), maxdims * sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Win_flush(int rank, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_flush, (rank, win));
	void **args = assemble_args_list(2, &rank, &win);
	int sizes[] = { sizeof(int), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader, MPI_Comm peer_comm, int remote_leader, int tag, MPI_Comm *newintercomm)
{
	PILGRIM_TRACING_1(int, MPI_Intercomm_create, (local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm));
	void **args = assemble_args_list(6, &local_comm, &local_leader, &peer_comm, &remote_leader, &tag, newintercomm);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), sizeof(MPI_Comm), sizeof(int), sizeof(int), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Allreduce, (sendbuf, recvbuf, count, datatype, op, comm));
	void **args = assemble_args_list(6, addr2id(sendbuf), addr2id(recvbuf), &count, &datatype, &op, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Op), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Type_contiguous(int count, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_contiguous, (count, oldtype, newtype));
	void **args = assemble_args_list(3, &count, &oldtype, newtype);
	int sizes[] = { sizeof(int), sizeof(MPI_Datatype), 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Reduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Reduce, (sendbuf, recvbuf, count, datatype, op, root, comm));
	void **args = assemble_args_list(7, addr2id(sendbuf), addr2id(recvbuf), &count, &datatype, &op, &root, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Op), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_File_get_position(MPI_File fh, MPI_Offset *offset)
{
	PILGRIM_TRACING_1(int, MPI_File_get_position, (fh, offset));
	void **args = assemble_args_list(2, &fh, offset);
	int sizes[] = { sizeof(MPI_File), 1 * sizeof(MPI_Offset) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Recv_init(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Recv_init, (buf, count, datatype, source, tag, comm, request));
	void **args = assemble_args_list(6, addr2id(buf), &count, &datatype, &source, &tag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Comm_group(MPI_Comm comm, MPI_Group *group)
{
	PILGRIM_TRACING_1(int, MPI_Comm_group, (comm, group));
	void **args = assemble_args_list(2, &comm, group);
	int sizes[] = { sizeof(MPI_Comm), 1 * sizeof(MPI_Group) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Is_thread_main(int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Is_thread_main, (flag));
	void **args = assemble_args_list(1, flag);
	int sizes[] = { 1 * sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_File_iwrite_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iwrite_all, (fh, buf, count, datatype, request));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Type_create_indexed_block(int count, int blocklength, const int array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_indexed_block, (count, blocklength, array_of_displacements, oldtype, newtype));
	void **args = assemble_args_list(5, &count, &blocklength, array_of_displacements, &oldtype, newtype);
	int sizes[] = { sizeof(int), sizeof(int), count * sizeof(const int), sizeof(MPI_Datatype), 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Wait(MPI_Request *request, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Wait, (request, status));
	void **args = NULL;
	int* sizes = NULL;
	PILGRIM_TRACING_2(0, sizes, args);
}
int MPI_Type_create_hindexed(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_hindexed, (count, array_of_blocklengths, array_of_displacements, oldtype, newtype));
	void **args = assemble_args_list(5, &count, array_of_blocklengths, array_of_displacements, &oldtype, newtype);
	int sizes[] = { sizeof(int), count * sizeof(const int), count * sizeof(const MPI_Aint), sizeof(MPI_Datatype), 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[], int sourceweights[], int maxoutdegree, int destinations[], int destweights[])
{
	PILGRIM_TRACING_1(int, MPI_Dist_graph_neighbors, (comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights));
	void **args = assemble_args_list(7, &comm, &maxindegree, sources, sourceweights, &maxoutdegree, destinations, destweights);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), maxindegree * sizeof(int), 1 * sizeof(int), sizeof(int), maxoutdegree * sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_Error_string(int errorcode, char *string, int *resultlen)
{
	PILGRIM_TRACING_1(int, MPI_Error_string, (errorcode, string, resultlen));
	void **args = assemble_args_list(3, &errorcode, string, resultlen);
	int sizes[] = { sizeof(int), strlen(string)+1, 1 * sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_File_sync(MPI_File fh)
{
	PILGRIM_TRACING_1(int, MPI_File_sync, (fh));
	void **args = assemble_args_list(1, &fh);
	int sizes[] = { sizeof(MPI_File) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Ineighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ineighbor_allgatherv, (sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request));
	void **args = assemble_args_list(8, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), recvcounts, displs, &recvtype, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(8, sizes, args);
}
int MPI_Compare_and_swap(const void *origin_addr, const void *compare_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Compare_and_swap, (origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win));
	void **args = assemble_args_list(7, addr2id(origin_addr), addr2id(compare_addr), addr2id(result_addr), &datatype, &target_rank, &target_disp, &win);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Aint), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_Win_unlock_all(MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_unlock_all, (win));
	void **args = assemble_args_list(1, &win);
	int sizes[] = { sizeof(MPI_Win) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Type_get_attr(MPI_Datatype datatype, int type_keyval, void *attribute_val, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Type_get_attr, (datatype, type_keyval, attribute_val, flag));
	void **args = assemble_args_list(4, &datatype, &type_keyval, addr2id(attribute_val), flag);
	int sizes[] = { sizeof(MPI_Datatype), sizeof(int), sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Comm_disconnect(MPI_Comm *comm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_disconnect, (comm));
	void **args = assemble_args_list(1, comm);
	int sizes[] = { 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_T_pvar_readreset(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void *buf)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_readreset, (session, handle, buf));
	void **args = assemble_args_list(3, &session, &handle, addr2id(buf));
	int sizes[] = { sizeof(MPI_T_pvar_session), sizeof(MPI_T_pvar_handle), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Attr_get, (comm, keyval, attribute_val, flag));
	void **args = assemble_args_list(4, &comm, &keyval, addr2id(attribute_val), flag);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle)
{
	PILGRIM_TRACING_1(int, MPI_T_cvar_handle_free, (handle));
	void **args = assemble_args_list(1, handle);
	int sizes[] = { 1 * sizeof(MPI_T_cvar_handle) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_T_enum_get_item(MPI_T_enum enumtype, int index, int *value, char *name, int *name_len)
{
	PILGRIM_TRACING_1(int, MPI_T_enum_get_item, (enumtype, index, value, name, name_len));
	void **args = assemble_args_list(5, &enumtype, &index, value, name, name_len);
	int sizes[] = { sizeof(MPI_T_enum), sizeof(int), 1 * sizeof(int), strlen(name)+1, 1 * sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_File_call_errhandler(MPI_File fh, int errorcode)
{
	PILGRIM_TRACING_1(int, MPI_File_call_errhandler, (fh, errorcode));
	void **args = assemble_args_list(2, &fh, &errorcode);
	int sizes[] = { sizeof(MPI_File), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Group_compare(MPI_Group group1, MPI_Group group2, int *result)
{
	PILGRIM_TRACING_1(int, MPI_Group_compare, (group1, group2, result));
	void **args = assemble_args_list(3, &group1, &group2, result);
	int sizes[] = { sizeof(MPI_Group), sizeof(MPI_Group), 1 * sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Imrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Imrecv, (buf, count, datatype, message, request));
	void **args = assemble_args_list(4, addr2id(buf), &count, &datatype, message);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), 1 * sizeof(MPI_Message) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_T_category_get_index(const char *name, int *cat_index)
{
	PILGRIM_TRACING_1(int, MPI_T_category_get_index, (name, cat_index));
	void **args = assemble_args_list(2, name, cat_index);
	int sizes[] = { strlen(name)+1, 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Test_cancelled(const MPI_Status *status, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Test_cancelled, (status, flag));
	void **args = assemble_args_list(1, flag);
	int sizes[] = { 1 * sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Buffer_attach(void *buffer, int size)
{
	PILGRIM_TRACING_1(int, MPI_Buffer_attach, (buffer, size));
	void **args = assemble_args_list(2, addr2id(buffer), &size);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Win_call_errhandler(MPI_Win win, int errorcode)
{
	PILGRIM_TRACING_1(int, MPI_Win_call_errhandler, (win, errorcode));
	void **args = assemble_args_list(2, &win, &errorcode);
	int sizes[] = { sizeof(MPI_Win), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors)
{
	PILGRIM_TRACING_1(int, MPI_Graph_neighbors_count, (comm, rank, nneighbors));
	void **args = assemble_args_list(3, &comm, &rank, nneighbors);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset)
{
	PILGRIM_TRACING_1(int, MPI_File_get_position_shared, (fh, offset));
	void **args = assemble_args_list(2, &fh, offset);
	int sizes[] = { sizeof(MPI_File), 1 * sizeof(MPI_Offset) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[], const int periods[], int *newrank)
{
	PILGRIM_TRACING_1(int, MPI_Cart_map, (comm, ndims, dims, periods, newrank));
	void **args = assemble_args_list(5, &comm, &ndims, dims, periods, newrank);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), ndims * sizeof(const int), ndims * sizeof(const int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iread, (fh, buf, count, datatype, request));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree, int *outdegree, int *weighted)
{
	PILGRIM_TRACING_1(int, MPI_Dist_graph_neighbors_count, (comm, indegree, outdegree, weighted));
	void **args = assemble_args_list(4, &comm, indegree, outdegree, weighted);
	int sizes[] = { sizeof(MPI_Comm), 1 * sizeof(int), 1 * sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity, MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind, int *scope)
{
	PILGRIM_TRACING_1(int, MPI_T_cvar_get_info, (cvar_index, name, name_len, verbosity, datatype, enumtype, desc, desc_len, bind, scope));
	void **args = assemble_args_list(10, &cvar_index, name, name_len, verbosity, datatype, enumtype, desc, desc_len, bind, scope);
	int sizes[] = { sizeof(int), strlen(name)+1, 1 * sizeof(int), 1 * sizeof(int), 1 * sizeof(MPI_Datatype), 1 * sizeof(MPI_T_enum), strlen(desc)+1, 1 * sizeof(int), 1 * sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(10, sizes, args);
}
int MPI_T_pvar_read(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void *buf)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_read, (session, handle, buf));
	void **args = assemble_args_list(3, &session, &handle, addr2id(buf));
	int sizes[] = { sizeof(MPI_T_pvar_session), sizeof(MPI_T_pvar_handle), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Type_set_name(MPI_Datatype datatype, const char *type_name)
{
	PILGRIM_TRACING_1(int, MPI_Type_set_name, (datatype, type_name));
	void **args = assemble_args_list(2, &datatype, type_name);
	int sizes[] = { sizeof(MPI_Datatype), strlen(type_name)+1 };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Neighbor_alltoallw(const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Neighbor_alltoallw, (sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm));
	void **args = assemble_args_list(9, addr2id(sendbuf), sendcounts, sdispls, sendtypes, addr2id(recvbuf), recvcounts, rdispls, recvtypes, &comm);
	int sizes[] = { sizeof(int), 1 * sizeof(const int), 1 * sizeof(const MPI_Aint), 1 * sizeof(const MPI_Datatype), sizeof(int), 1 * sizeof(const int), 1 * sizeof(const MPI_Aint), 1 * sizeof(const MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(9, sizes, args);
}
int MPI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Neighbor_alltoallv, (sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm));
	void **args = assemble_args_list(9, addr2id(sendbuf), sendcounts, sdispls, &sendtype, addr2id(recvbuf), recvcounts, rdispls, &recvtype, &comm);
	int sizes[] = { sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(9, sizes, args);
}
int MPI_Publish_name(const char *service_name, MPI_Info info, const char *port_name)
{
	PILGRIM_TRACING_1(int, MPI_Publish_name, (service_name, info, port_name));
	void **args = assemble_args_list(3, service_name, &info, port_name);
	int sizes[] = { strlen(service_name)+1, sizeof(MPI_Info), strlen(port_name)+1 };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb, MPI_Aint *extent)
{
	PILGRIM_TRACING_1(int, MPI_Type_get_extent, (datatype, lb, extent));
	void **args = assemble_args_list(3, &datatype, lb, extent);
	int sizes[] = { sizeof(MPI_Datatype), 1 * sizeof(MPI_Aint), 1 * sizeof(MPI_Aint) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Graph_create(MPI_Comm comm_old, int nnodes, const int index[], const int edges[], int reorder, MPI_Comm *comm_graph)
{
	PILGRIM_TRACING_1(int, MPI_Graph_create, (comm_old, nnodes, index, edges, reorder, comm_graph));
	void **args = assemble_args_list(6, &comm_old, &nnodes, index, edges, &reorder, comm_graph);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), nnodes * sizeof(const int), 1 * sizeof(const int), sizeof(int), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Put(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Put, (origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win));
	void **args = assemble_args_list(8, addr2id(origin_addr), &origin_count, &origin_datatype, &target_rank, &target_disp, &target_count, &target_datatype, &win);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(8, sizes, args);
}
int MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win)
{
	PILGRIM_TRACING_1(int, MPI_Win_create_dynamic, (info, comm, win));
	void **args = assemble_args_list(3, &info, &comm, win);
	int sizes[] = { sizeof(MPI_Info), sizeof(MPI_Comm), 1 * sizeof(MPI_Win) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Ibsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ibsend, (buf, count, datatype, dest, tag, comm, request));
	void **args = assemble_args_list(6, addr2id(buf), &count, &datatype, &dest, &tag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Win_complete(MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_complete, (win));
	void **args = assemble_args_list(1, &win);
	int sizes[] = { sizeof(MPI_Win) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Graph_map(MPI_Comm comm, int nnodes, const int index[], const int edges[], int *newrank)
{
	PILGRIM_TRACING_1(int, MPI_Graph_map, (comm, nnodes, index, edges, newrank));
	void **args = assemble_args_list(5, &comm, &nnodes, index, edges, newrank);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), nnodes * sizeof(const int), 1 * sizeof(const int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Info_get_valuelen(MPI_Info info, const char *key, int *valuelen, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Info_get_valuelen, (info, key, valuelen, flag));
	void **args = assemble_args_list(4, &info, key, valuelen, flag);
	int sizes[] = { sizeof(MPI_Info), strlen(key)+1, 1 * sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Cart_sub(MPI_Comm comm, const int remain_dims[], MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Cart_sub, (comm, remain_dims, newcomm));
	void **args = assemble_args_list(3, &comm, remain_dims, newcomm);
	int sizes[] = { sizeof(MPI_Comm), 1 * sizeof(const int), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Info_get(MPI_Info info, const char *key, int valuelen, char *value, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Info_get, (info, key, valuelen, value, flag));
	void **args = assemble_args_list(5, &info, key, &valuelen, value, flag);
	int sizes[] = { sizeof(MPI_Info), strlen(key)+1, sizeof(int), strlen(value)+1, 1 * sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iwrite_at, (fh, offset, buf, count, datatype, request));
	void **args = assemble_args_list(5, &fh, &offset, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Offset), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Comm_spawn(const char *command, char *argv[], int maxprocs, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
{
	PILGRIM_TRACING_1(int, MPI_Comm_spawn, (command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes));
	void **args = assemble_args_list(8, command, argv, &maxprocs, &info, &root, &comm, intercomm, array_of_errcodes);
	int sizes[] = { strlen(command)+1, sizeof(int), sizeof(MPI_Info), sizeof(int), sizeof(MPI_Comm), 1 * sizeof(MPI_Comm), 1 * sizeof(int) };
	PILGRIM_TRACING_2(8, sizes, args);
}
int MPI_Group_intersection(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup)
{
	PILGRIM_TRACING_1(int, MPI_Group_intersection, (group1, group2, newgroup));
	void **args = assemble_args_list(3, &group1, &group2, newgroup);
	int sizes[] = { sizeof(MPI_Group), sizeof(MPI_Group), 1 * sizeof(MPI_Group) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Iallgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Iallgatherv, (sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request));
	void **args = assemble_args_list(8, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), recvcounts, displs, &recvtype, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(8, sizes, args);
}
int MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ibcast, (buffer, count, datatype, root, comm, request));
	void **args = assemble_args_list(5, addr2id(buffer), &count, &datatype, &root, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype)
{
	PILGRIM_TRACING_1(int, MPI_File_read_at_all_begin, (fh, offset, buf, count, datatype));
	void **args = assemble_args_list(5, &fh, &offset, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Offset), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Info_get_nthkey(MPI_Info info, int n, char *key)
{
	PILGRIM_TRACING_1(int, MPI_Info_get_nthkey, (info, n, key));
	void **args = assemble_args_list(3, &info, &n, key);
	int sizes[] = { sizeof(MPI_Info), sizeof(int), strlen(key)+1 };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_File_get_size(MPI_File fh, MPI_Offset *size)
{
	PILGRIM_TRACING_1(int, MPI_File_get_size, (fh, size));
	void **args = assemble_args_list(2, &fh, size);
	int sizes[] = { sizeof(MPI_File), 1 * sizeof(MPI_Offset) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Rput(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Rput, (origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request));
	void **args = assemble_args_list(8, addr2id(origin_addr), &origin_count, &origin_datatype, &target_rank, &target_disp, &target_count, &target_datatype, &win);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(8, sizes, args);
}
int MPI_Type_indexed(int count, const int array_of_blocklengths[], const int array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_indexed, (count, array_of_blocklengths, array_of_displacements, oldtype, newtype));
	void **args = assemble_args_list(5, &count, array_of_blocklengths, array_of_displacements, &oldtype, newtype);
	int sizes[] = { sizeof(int), count * sizeof(const int), count * sizeof(const int), sizeof(MPI_Datatype), 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Send_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Send_init, (buf, count, datatype, dest, tag, comm, request));
	void **args = assemble_args_list(6, addr2id(buf), &count, &datatype, &dest, &tag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_File_write(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write, (fh, buf, count, datatype, status));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_File_set_info(MPI_File fh, MPI_Info info)
{
	PILGRIM_TRACING_1(int, MPI_File_set_info, (fh, info));
	void **args = assemble_args_list(2, &fh, &info);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Info) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_File_set_atomicity(MPI_File fh, int flag)
{
	PILGRIM_TRACING_1(int, MPI_File_set_atomicity, (fh, flag));
	void **args = assemble_args_list(2, &fh, &flag);
	int sizes[] = { sizeof(MPI_File), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges, int index[], int edges[])
{
	PILGRIM_TRACING_1(int, MPI_Graph_get, (comm, maxindex, maxedges, index, edges));
	void **args = assemble_args_list(5, &comm, &maxindex, &maxedges, index, edges);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), sizeof(int), maxindex * sizeof(int), maxedges * sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Pack_external_size(const char datarep[], int incount, MPI_Datatype datatype, MPI_Aint *size)
{
	PILGRIM_TRACING_1(int, MPI_Pack_external_size, (datarep, incount, datatype, size));
	void **args = assemble_args_list(4, datarep, &incount, &datatype, size);
	int sizes[] = { 1 * sizeof(const char), sizeof(int), sizeof(MPI_Datatype), 1 * sizeof(MPI_Aint) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Type_create_darray(int size, int rank, int ndims, const int array_of_gsizes[], const int array_of_distribs[], const int array_of_dargs[], const int array_of_psizes[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_darray, (size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype));
	void **args = assemble_args_list(10, &size, &rank, &ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, &order, &oldtype, newtype);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), ndims * sizeof(const int), ndims * sizeof(const int), ndims * sizeof(const int), ndims * sizeof(const int), sizeof(int), sizeof(MPI_Datatype), 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(10, sizes, args);
}
int MPI_Win_set_errhandler(MPI_Win win, MPI_Errhandler errhandler)
{
	PILGRIM_TRACING_1(int, MPI_Win_set_errhandler, (win, errhandler));
	void **args = assemble_args_list(2, &win, &errhandler);
	int sizes[] = { sizeof(MPI_Win), sizeof(MPI_Errhandler) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn, MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval, void *extra_state)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_keyval, (type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state));
	void **args = assemble_args_list(4, type_copy_attr_fn, type_delete_attr_fn, type_keyval, addr2id(extra_state));
	int sizes[] = { 1 * sizeof(MPI_Type_copy_attr_function), 1 * sizeof(MPI_Type_delete_attr_function), 1 * sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Comm_accept(const char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_accept, (port_name, info, root, comm, newcomm));
	void **args = assemble_args_list(5, port_name, &info, &root, &comm, newcomm);
	int sizes[] = { strlen(port_name)+1, sizeof(MPI_Info), sizeof(int), sizeof(MPI_Comm), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Type_create_struct(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], const MPI_Datatype array_of_types[], MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_struct, (count, array_of_blocklengths, array_of_displacements, array_of_types, newtype));
	void **args = assemble_args_list(5, &count, array_of_blocklengths, array_of_displacements, array_of_types, newtype);
	int sizes[] = { sizeof(int), count * sizeof(const int), count * sizeof(const MPI_Aint), count * sizeof(const MPI_Datatype), 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Gather, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm));
	void **args = assemble_args_list(8, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), &recvcount, &recvtype, &root, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(8, sizes, args);
}
int MPI_Close_port(const char *port_name)
{
	PILGRIM_TRACING_1(int, MPI_Close_port, (port_name));
	void **args = assemble_args_list(1, port_name);
	int sizes[] = { strlen(port_name)+1 };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Win_sync(MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_sync, (win));
	void **args = assemble_args_list(1, &win);
	int sizes[] = { sizeof(MPI_Win) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Type_create_subarray(int ndims, const int array_of_sizes[], const int array_of_subsizes[], const int array_of_starts[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_subarray, (ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype));
	void **args = assemble_args_list(7, &ndims, array_of_sizes, array_of_subsizes, array_of_starts, &order, &oldtype, newtype);
	int sizes[] = { sizeof(int), ndims * sizeof(const int), ndims * sizeof(const int), ndims * sizeof(const int), sizeof(int), sizeof(MPI_Datatype), 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_Win_free_keyval(int *win_keyval)
{
	PILGRIM_TRACING_1(int, MPI_Win_free_keyval, (win_keyval));
	void **args = assemble_args_list(1, win_keyval);
	int sizes[] = { 1 * sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_File_write_at_all_end(MPI_File fh, const void *buf, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write_at_all_end, (fh, buf, status));
	void **args = assemble_args_list(2, &fh, addr2id(buf));
	int sizes[] = { sizeof(MPI_File), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Rget_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Rget_accumulate, (origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request));
	void **args = assemble_args_list(12, addr2id(origin_addr), &origin_count, &origin_datatype, addr2id(result_addr), &result_count, &result_datatype, &target_rank, &target_disp, &target_count, &target_datatype, &op, &win);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Op), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(12, sizes, args);
}
int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval)
{
	PILGRIM_TRACING_1(int, MPI_Comm_delete_attr, (comm, comm_keyval));
	void **args = assemble_args_list(2, &comm, &comm_keyval);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Comm_create_errhandler(MPI_Comm_errhandler_function *comm_errhandler_fn, MPI_Errhandler *errhandler)
{
	PILGRIM_TRACING_1(int, MPI_Comm_create_errhandler, (comm_errhandler_fn, errhandler));
	void **args = assemble_args_list(2, comm_errhandler_fn, errhandler);
	int sizes[] = { 1 * sizeof(MPI_Comm_errhandler_function), 1 * sizeof(MPI_Errhandler) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Barrier(MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Barrier, (comm));
	void **args = assemble_args_list(1, &comm);
	int sizes[] = { sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Win_get_attr(MPI_Win win, int win_keyval, void *attribute_val, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Win_get_attr, (win, win_keyval, attribute_val, flag));
	void **args = assemble_args_list(4, &win, &win_keyval, addr2id(attribute_val), flag);
	int sizes[] = { sizeof(MPI_Win), sizeof(int), sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp)
{
	PILGRIM_TRACING_1(int, MPI_File_get_byte_offset, (fh, offset, disp));
	void **args = assemble_args_list(3, &fh, &offset, disp);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Offset), 1 * sizeof(MPI_Offset) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Win_lock_all(int assert, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_lock_all, (assert, win));
	void **args = assemble_args_list(2, &assert, &win);
	int sizes[] = { sizeof(int), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen)
{
	PILGRIM_TRACING_1(int, MPI_Comm_get_name, (comm, comm_name, resultlen));
	void **args = assemble_args_list(3, &comm, comm_name, resultlen);
	int sizes[] = { sizeof(MPI_Comm), strlen(comm_name)+1, 1 * sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup)
{
	PILGRIM_TRACING_1(int, MPI_Group_range_excl, (group, n, ranges, newgroup));
	void **args = assemble_args_list(4, &group, &n, ranges, newgroup);
	int sizes[] = { sizeof(MPI_Group), sizeof(int), n*3 * sizeof(int), 1 * sizeof(MPI_Group) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_split, (comm, color, key, newcomm));
	void **args = assemble_args_list(4, &comm, &color, &key, newcomm);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), sizeof(int), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_T_pvar_handle_alloc(MPI_T_pvar_session session, int pvar_index, void *obj_handle, MPI_T_pvar_handle *handle, int *count)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_handle_alloc, (session, pvar_index, obj_handle, handle, count));
	void **args = assemble_args_list(5, &session, &pvar_index, addr2id(obj_handle), handle, count);
	int sizes[] = { sizeof(MPI_T_pvar_session), sizeof(int), sizeof(int), 1 * sizeof(MPI_T_pvar_handle), 1 * sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype)
{
	PILGRIM_TRACING_1(int, MPI_File_read_ordered_begin, (fh, buf, count, datatype));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read_ordered, (fh, buf, count, datatype, status));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Attr_delete(MPI_Comm comm, int keyval)
{
	PILGRIM_TRACING_1(int, MPI_Attr_delete, (comm, keyval));
	void **args = assemble_args_list(2, &comm, &keyval);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Win_get_errhandler(MPI_Win win, MPI_Errhandler *errhandler)
{
	PILGRIM_TRACING_1(int, MPI_Win_get_errhandler, (win, errhandler));
	void **args = assemble_args_list(2, &win, errhandler);
	int sizes[] = { sizeof(MPI_Win), 1 * sizeof(MPI_Errhandler) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_File_get_info(MPI_File fh, MPI_Info *info_used)
{
	PILGRIM_TRACING_1(int, MPI_File_get_info, (fh, info_used));
	void **args = assemble_args_list(2, &fh, info_used);
	int sizes[] = { sizeof(MPI_File), 1 * sizeof(MPI_Info) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Info_dup(MPI_Info info, MPI_Info *newinfo)
{
	PILGRIM_TRACING_1(int, MPI_Info_dup, (info, newinfo));
	void **args = assemble_args_list(2, &info, newinfo);
	int sizes[] = { sizeof(MPI_Info), 1 * sizeof(MPI_Info) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_File_write_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write_shared, (fh, buf, count, datatype, status));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iread_at, (fh, offset, buf, count, datatype, request));
	void **args = assemble_args_list(5, &fh, &offset, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Offset), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_File_write_all_end(MPI_File fh, const void *buf, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write_all_end, (fh, buf, status));
	void **args = assemble_args_list(2, &fh, addr2id(buf));
	int sizes[] = { sizeof(MPI_File), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Comm_remote_size(MPI_Comm comm, int *size)
{
	PILGRIM_TRACING_1(int, MPI_Comm_remote_size, (comm, size));
	void **args = assemble_args_list(2, &comm, size);
	int sizes[] = { sizeof(MPI_Comm), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Type_get_name(MPI_Datatype datatype, char *type_name, int *resultlen)
{
	PILGRIM_TRACING_1(int, MPI_Type_get_name, (datatype, type_name, resultlen));
	void **args = assemble_args_list(3, &datatype, type_name, resultlen);
	int sizes[] = { sizeof(MPI_Datatype), strlen(type_name)+1, 1 * sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write_at_all, (fh, offset, buf, count, datatype, status));
	void **args = assemble_args_list(5, &fh, &offset, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Offset), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_File_get_group(MPI_File fh, MPI_Group *group)
{
	PILGRIM_TRACING_1(int, MPI_File_get_group, (fh, group));
	void **args = assemble_args_list(2, &fh, group);
	int sizes[] = { sizeof(MPI_File), 1 * sizeof(MPI_Group) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_File_preallocate(MPI_File fh, MPI_Offset size)
{
	PILGRIM_TRACING_1(int, MPI_File_preallocate, (fh, size));
	void **args = assemble_args_list(2, &fh, &size);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Offset) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_File_iread_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iread_all, (fh, buf, count, datatype, request));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_T_cvar_write(MPI_T_cvar_handle handle, const void *buf)
{
	PILGRIM_TRACING_1(int, MPI_T_cvar_write, (handle, buf));
	void **args = assemble_args_list(2, &handle, addr2id(buf));
	int sizes[] = { sizeof(MPI_T_cvar_handle), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Group_translate_ranks(MPI_Group group1, int n, const int ranks1[], MPI_Group group2, int ranks2[])
{
	PILGRIM_TRACING_1(int, MPI_Group_translate_ranks, (group1, n, ranks1, group2, ranks2));
	void **args = assemble_args_list(5, &group1, &n, ranks1, &group2, ranks2);
	int sizes[] = { sizeof(MPI_Group), sizeof(int), n * sizeof(const int), sizeof(MPI_Group), n * sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Type_create_hvector(int count, int blocklength, MPI_Aint stride, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_hvector, (count, blocklength, stride, oldtype, newtype));
	void **args = assemble_args_list(5, &count, &blocklength, &stride, &oldtype, newtype);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Aint), sizeof(MPI_Datatype), 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval, void *attribute_val, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Comm_get_attr, (comm, comm_keyval, attribute_val, flag));
	void **args = assemble_args_list(4, &comm, &comm_keyval, addr2id(attribute_val), flag);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Initialized(int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Initialized, (flag));
	void **args = assemble_args_list(1, flag);
	int sizes[] = { 1 * sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag, MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_create_group, (comm, group, tag, newcomm));
	void **args = assemble_args_list(4, &comm, &group, &tag, newcomm);
	int sizes[] = { sizeof(MPI_Comm), sizeof(MPI_Group), sizeof(int), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Grequest_complete(MPI_Request request)
{
	PILGRIM_TRACING_1(int, MPI_Grequest_complete, (request));
	void **args = NULL;
	int* sizes = NULL;
	PILGRIM_TRACING_2(0, sizes, args);
}
int MPI_Get_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Get_accumulate, (origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win));
	void **args = assemble_args_list(12, addr2id(origin_addr), &origin_count, &origin_datatype, addr2id(result_addr), &result_count, &result_datatype, &target_rank, &target_disp, &target_count, &target_datatype, &op, &win);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Op), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(12, sizes, args);
}
int MPI_Win_create_errhandler(MPI_Win_errhandler_function *win_errhandler_fn, MPI_Errhandler *errhandler)
{
	PILGRIM_TRACING_1(int, MPI_Win_create_errhandler, (win_errhandler_fn, errhandler));
	void **args = assemble_args_list(2, win_errhandler_fn, errhandler);
	int sizes[] = { 1 * sizeof(MPI_Win_errhandler_function), 1 * sizeof(MPI_Errhandler) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Win_fence(int assert, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_fence, (assert, win));
	void **args = assemble_args_list(2, &assert, &win);
	int sizes[] = { sizeof(int), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_T_category_get_info(int cat_index, char *name, int *name_len, char *desc, int *desc_len, int *num_cvars, int *num_pvars, int *num_categories)
{
	PILGRIM_TRACING_1(int, MPI_T_category_get_info, (cat_index, name, name_len, desc, desc_len, num_cvars, num_pvars, num_categories));
	void **args = assemble_args_list(8, &cat_index, name, name_len, desc, desc_len, num_cvars, num_pvars, num_categories);
	int sizes[] = { sizeof(int), strlen(name)+1, 1 * sizeof(int), strlen(desc)+1, 1 * sizeof(int), 1 * sizeof(int), 1 * sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(8, sizes, args);
}
int MPI_Group_difference(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup)
{
	PILGRIM_TRACING_1(int, MPI_Group_difference, (group1, group2, newgroup));
	void **args = assemble_args_list(3, &group1, &group2, newgroup);
	int sizes[] = { sizeof(MPI_Group), sizeof(MPI_Group), 1 * sizeof(MPI_Group) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_T_pvar_start(MPI_T_pvar_session session, MPI_T_pvar_handle handle)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_start, (session, handle));
	void **args = assemble_args_list(2, &session, &handle);
	int sizes[] = { sizeof(MPI_T_pvar_session), sizeof(MPI_T_pvar_handle) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen)
{
	PILGRIM_TRACING_1(int, MPI_Win_get_name, (win, win_name, resultlen));
	void **args = assemble_args_list(3, &win, win_name, resultlen);
	int sizes[] = { sizeof(MPI_Win), strlen(win_name)+1, 1 * sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Win_wait(MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_wait, (win));
	void **args = assemble_args_list(1, &win);
	int sizes[] = { sizeof(MPI_Win) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Scatterv(const void *sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Scatterv, (sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm));
	void **args = assemble_args_list(9, addr2id(sendbuf), sendcounts, displs, &sendtype, addr2id(recvbuf), &recvcount, &recvtype, &root, &comm);
	int sizes[] = { sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(9, sizes, args);
}
int MPI_File_write_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write_all, (fh, buf, count, datatype, status));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Comm_connect(const char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_connect, (port_name, info, root, comm, newcomm));
	void **args = assemble_args_list(5, port_name, &info, &root, &comm, newcomm);
	int sizes[] = { strlen(port_name)+1, sizeof(MPI_Info), sizeof(int), sizeof(MPI_Comm), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Win_flush_all(MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_flush_all, (win));
	void **args = assemble_args_list(1, &win);
	int sizes[] = { sizeof(MPI_Win) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Win_get_group(MPI_Win win, MPI_Group *group)
{
	PILGRIM_TRACING_1(int, MPI_Win_get_group, (win, group));
	void **args = assemble_args_list(2, &win, group);
	int sizes[] = { sizeof(MPI_Win), 1 * sizeof(MPI_Group) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_File_set_size(MPI_File fh, MPI_Offset size)
{
	PILGRIM_TRACING_1(int, MPI_File_set_size, (fh, size));
	void **args = assemble_args_list(2, &fh, &size);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Offset) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Status_set_cancelled(MPI_Status *status, int flag)
{
	PILGRIM_TRACING_1(int, MPI_Status_set_cancelled, (status, flag));
	void **args = assemble_args_list(1, &flag);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Reduce_local(const void *inbuf, void *inoutbuf, int count, MPI_Datatype datatype, MPI_Op op)
{
	PILGRIM_TRACING_1(int, MPI_Reduce_local, (inbuf, inoutbuf, count, datatype, op));
	void **args = assemble_args_list(5, addr2id(inbuf), addr2id(inoutbuf), &count, &datatype, &op);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Op) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_T_pvar_write(MPI_T_pvar_session session, MPI_T_pvar_handle handle, const void *buf)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_write, (session, handle, buf));
	void **args = assemble_args_list(3, &session, &handle, addr2id(buf));
	int sizes[] = { sizeof(MPI_T_pvar_session), sizeof(MPI_T_pvar_handle), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors, int neighbors[])
{
	PILGRIM_TRACING_1(int, MPI_Graph_neighbors, (comm, rank, maxneighbors, neighbors));
	void **args = assemble_args_list(4, &comm, &rank, &maxneighbors, neighbors);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), sizeof(int), maxneighbors * sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Dims_create(int nnodes, int ndims, int dims[])
{
	PILGRIM_TRACING_1(int, MPI_Dims_create, (nnodes, ndims, dims));
	void **args = assemble_args_list(3, &nnodes, &ndims, dims);
	int sizes[] = { sizeof(int), sizeof(int), ndims * sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Scatter, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm));
	void **args = assemble_args_list(8, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), &recvcount, &recvtype, &root, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(8, sizes, args);
}
int MPI_Ireduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ireduce_scatter_block, (sendbuf, recvbuf, recvcount, datatype, op, comm, request));
	void **args = assemble_args_list(6, addr2id(sendbuf), addr2id(recvbuf), &recvcount, &datatype, &op, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Op), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Ialltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ialltoallw, (sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request));
	void **args = assemble_args_list(9, addr2id(sendbuf), sendcounts, sdispls, sendtypes, addr2id(recvbuf), recvcounts, rdispls, recvtypes, &comm);
	int sizes[] = { sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), 1 * sizeof(const MPI_Datatype), sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), 1 * sizeof(const MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(9, sizes, args);
}
int MPI_Ialltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ialltoallv, (sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request));
	void **args = assemble_args_list(9, addr2id(sendbuf), sendcounts, sdispls, &sendtype, addr2id(recvbuf), recvcounts, rdispls, &recvtype, &comm);
	int sizes[] = { sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(9, sizes, args);
}
int MPI_Comm_free(MPI_Comm *comm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_free, (comm));
	void **args = assemble_args_list(1, comm);
	int sizes[] = { 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_T_cvar_read(MPI_T_cvar_handle handle, void *buf)
{
	PILGRIM_TRACING_1(int, MPI_T_cvar_read, (handle, buf));
	void **args = assemble_args_list(2, &handle, addr2id(buf));
	int sizes[] = { sizeof(MPI_T_cvar_handle), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Neighbor_alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Neighbor_alltoall, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm));
	void **args = assemble_args_list(7, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), &recvcount, &recvtype, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_Alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Alltoall, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm));
	void **args = assemble_args_list(7, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), &recvcount, &recvtype, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[], const int array_of_maxprocs[], const MPI_Info array_of_info[], int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
{
	PILGRIM_TRACING_1(int, MPI_Comm_spawn_multiple, (count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes));
	void **args = assemble_args_list(9, &count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, &root, &comm, intercomm, array_of_errcodes);
	int sizes[] = { sizeof(int), count * sizeof(const int), count * sizeof(const MPI_Info), sizeof(int), sizeof(MPI_Comm), 1 * sizeof(MPI_Comm), 1 * sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args);
}
int MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info, MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_dup_with_info, (comm, info, newcomm));
	void **args = assemble_args_list(3, &comm, &info, newcomm);
	int sizes[] = { sizeof(MPI_Comm), sizeof(MPI_Info), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_T_pvar_handle_free(MPI_T_pvar_session session, MPI_T_pvar_handle *handle)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_handle_free, (session, handle));
	void **args = assemble_args_list(2, &session, handle);
	int sizes[] = { sizeof(MPI_T_pvar_session), 1 * sizeof(MPI_T_pvar_handle) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Type_free(MPI_Datatype *datatype)
{
	PILGRIM_TRACING_1(int, MPI_Type_free, (datatype));
	void **args = assemble_args_list(1, datatype);
	int sizes[] = { 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Win_test(MPI_Win win, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Win_test, (win, flag));
	void **args = assemble_args_list(2, &win, flag);
	int sizes[] = { sizeof(MPI_Win), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype)
{
	PILGRIM_TRACING_1(int, MPI_File_write_at_all_begin, (fh, offset, buf, count, datatype));
	void **args = assemble_args_list(5, &fh, &offset, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Offset), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *errhandler)
{
	PILGRIM_TRACING_1(int, MPI_Comm_get_errhandler, (comm, errhandler));
	void **args = assemble_args_list(2, &comm, errhandler);
	int sizes[] = { sizeof(MPI_Comm), 1 * sizeof(MPI_Errhandler) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Mprobe(int source, int tag, MPI_Comm comm, MPI_Message *message, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Mprobe, (source, tag, comm, message, status));
	void **args = assemble_args_list(4, &source, &tag, &comm, message);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Comm), 1 * sizeof(MPI_Message) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Info_get_nkeys(MPI_Info info, int *nkeys)
{
	PILGRIM_TRACING_1(int, MPI_Info_get_nkeys, (info, nkeys));
	void **args = assemble_args_list(2, &info, nkeys);
	int sizes[] = { sizeof(MPI_Info), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Finalized(int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Finalized, (flag));
	void **args = assemble_args_list(1, flag);
	int sizes[] = { 1 * sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Op_commutative(MPI_Op op, int *commute)
{
	PILGRIM_TRACING_1(int, MPI_Op_commutative, (op, commute));
	void **args = assemble_args_list(2, &op, commute);
	int sizes[] = { sizeof(MPI_Op), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree, const int sources[], const int sourceweights[], int outdegree, const int destinations[], const int destweights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph)
{
	PILGRIM_TRACING_1(int, MPI_Dist_graph_create_adjacent, (comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph));
	void **args = assemble_args_list(10, &comm_old, &indegree, sources, sourceweights, &outdegree, destinations, destweights, &info, &reorder, comm_dist_graph);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), indegree * sizeof(const int), 1 * sizeof(const int), sizeof(int), outdegree * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Info), sizeof(int), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(10, sizes, args);
}
int MPI_Info_delete(MPI_Info info, const char *key)
{
	PILGRIM_TRACING_1(int, MPI_Info_delete, (info, key));
	void **args = assemble_args_list(2, &info, key);
	int sizes[] = { sizeof(MPI_Info), strlen(key)+1 };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_File_iread_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iread_at_all, (fh, offset, buf, count, datatype, request));
	void **args = assemble_args_list(5, &fh, &offset, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Offset), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Cart_rank(MPI_Comm comm, const int coords[], int *rank)
{
	PILGRIM_TRACING_1(int, MPI_Cart_rank, (comm, coords, rank));
	void **args = assemble_args_list(3, &comm, coords, rank);
	int sizes[] = { sizeof(MPI_Comm), 1 * sizeof(const int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read_at, (fh, offset, buf, count, datatype, status));
	void **args = assemble_args_list(5, &fh, &offset, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Offset), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Iallreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Iallreduce, (sendbuf, recvbuf, count, datatype, op, comm, request));
	void **args = assemble_args_list(6, addr2id(sendbuf), addr2id(recvbuf), &count, &datatype, &op, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Op), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Type_size(MPI_Datatype datatype, int *size)
{
	PILGRIM_TRACING_1(int, MPI_Type_size, (datatype, size));
	void **args = assemble_args_list(2, &datatype, size);
	int sizes[] = { sizeof(MPI_Datatype), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Fetch_and_op(const void *origin_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Op op, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Fetch_and_op, (origin_addr, result_addr, datatype, target_rank, target_disp, op, win));
	void **args = assemble_args_list(7, addr2id(origin_addr), addr2id(result_addr), &datatype, &target_rank, &target_disp, &op, &win);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Aint), sizeof(MPI_Op), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_Reduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Reduce_scatter_block, (sendbuf, recvbuf, recvcount, datatype, op, comm));
	void **args = assemble_args_list(6, addr2id(sendbuf), addr2id(recvbuf), &recvcount, &datatype, &op, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Op), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Rget(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Rget, (origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request));
	void **args = assemble_args_list(8, addr2id(origin_addr), &origin_count, &origin_datatype, &target_rank, &target_disp, &target_count, &target_datatype, &win);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(8, sizes, args);
}
int MPI_Win_set_attr(MPI_Win win, int win_keyval, void *attribute_val)
{
	PILGRIM_TRACING_1(int, MPI_Win_set_attr, (win, win_keyval, attribute_val));
	void **args = assemble_args_list(3, &win, &win_keyval, addr2id(attribute_val));
	int sizes[] = { sizeof(MPI_Win), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Type_create_f90_integer(int r, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_f90_integer, (r, newtype));
	void **args = assemble_args_list(2, &r, newtype);
	int sizes[] = { sizeof(int), 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Iscatterv(const void *sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Iscatterv, (sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request));
	void **args = assemble_args_list(9, addr2id(sendbuf), sendcounts, displs, &sendtype, addr2id(recvbuf), &recvcount, &recvtype, &root, &comm);
	int sizes[] = { sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(9, sizes, args);
}
int MPI_File_delete(const char *filename, MPI_Info info)
{
	PILGRIM_TRACING_1(int, MPI_File_delete, (filename, info));
	void **args = assemble_args_list(2, filename, &info);
	int sizes[] = { strlen(filename)+1, sizeof(MPI_Info) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read_all, (fh, buf, count, datatype, status));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Group_size(MPI_Group group, int *size)
{
	PILGRIM_TRACING_1(int, MPI_Group_size, (group, size));
	void **args = assemble_args_list(2, &group, size);
	int sizes[] = { sizeof(MPI_Group), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val)
{
	PILGRIM_TRACING_1(int, MPI_Attr_put, (comm, keyval, attribute_val));
	void **args = assemble_args_list(3, &comm, &keyval, addr2id(attribute_val));
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Iscatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Iscatter, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request));
	void **args = assemble_args_list(8, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), &recvcount, &recvtype, &root, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(8, sizes, args);
}
int MPI_Win_start(MPI_Group group, int assert, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_start, (group, assert, win));
	void **args = assemble_args_list(3, &group, &assert, &win);
	int sizes[] = { sizeof(MPI_Group), sizeof(int), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Win_free(MPI_Win *win)
{
	PILGRIM_TRACING_1(int, MPI_Win_free, (win));
	void **args = assemble_args_list(1, win);
	int sizes[] = { 1 * sizeof(MPI_Win) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Alltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Alltoallw, (sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm));
	void **args = assemble_args_list(9, addr2id(sendbuf), sendcounts, sdispls, sendtypes, addr2id(recvbuf), recvcounts, rdispls, recvtypes, &comm);
	int sizes[] = { sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), 1 * sizeof(const MPI_Datatype), sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), 1 * sizeof(const MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(9, sizes, args);
}
int MPI_Alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Alltoallv, (sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm));
	void **args = assemble_args_list(9, addr2id(sendbuf), sendcounts, sdispls, &sendtype, addr2id(recvbuf), recvcounts, rdispls, &recvtype, &comm);
	int sizes[] = { sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(9, sizes, args);
}
int MPI_Exscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Exscan, (sendbuf, recvbuf, count, datatype, op, comm));
	void **args = assemble_args_list(6, addr2id(sendbuf), addr2id(recvbuf), &count, &datatype, &op, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Op), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Op_free(MPI_Op *op)
{
	PILGRIM_TRACING_1(int, MPI_Op_free, (op));
	void **args = assemble_args_list(1, op);
	int sizes[] = { 1 * sizeof(MPI_Op) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Iscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Iscan, (sendbuf, recvbuf, count, datatype, op, comm, request));
	void **args = assemble_args_list(6, addr2id(sendbuf), addr2id(recvbuf), &count, &datatype, &op, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Op), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Keyval_create(MPI_Copy_function *copy_fn, MPI_Delete_function *delete_fn, int *keyval, void *extra_state)
{
	PILGRIM_TRACING_1(int, MPI_Keyval_create, (copy_fn, delete_fn, keyval, extra_state));
	void **args = assemble_args_list(4, copy_fn, delete_fn, keyval, addr2id(extra_state));
	int sizes[] = { 1 * sizeof(MPI_Copy_function), 1 * sizeof(MPI_Delete_function), 1 * sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Type_vector(int count, int blocklength, int stride, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_vector, (count, blocklength, stride, oldtype, newtype));
	void **args = assemble_args_list(5, &count, &blocklength, &stride, &oldtype, newtype);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Datatype), 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn, MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval, void *extra_state)
{
	PILGRIM_TRACING_1(int, MPI_Win_create_keyval, (win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state));
	void **args = assemble_args_list(4, win_copy_attr_fn, win_delete_attr_fn, win_keyval, addr2id(extra_state));
	int sizes[] = { 1 * sizeof(MPI_Win_copy_attr_function), 1 * sizeof(MPI_Win_delete_attr_function), 1 * sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Type_match_size(int typeclass, int size, MPI_Datatype *datatype)
{
	PILGRIM_TRACING_1(int, MPI_Type_match_size, (typeclass, size, datatype));
	void **args = assemble_args_list(3, &typeclass, &size, datatype);
	int sizes[] = { sizeof(int), sizeof(int), 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Scan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Scan, (sendbuf, recvbuf, count, datatype, op, comm));
	void **args = assemble_args_list(6, addr2id(sendbuf), addr2id(recvbuf), &count, &datatype, &op, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Op), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Startall(int count, MPI_Request array_of_requests[])
{
	PILGRIM_TRACING_1(int, MPI_Startall, (count, array_of_requests));
	void **args = assemble_args_list(1, &count);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence)
{
	PILGRIM_TRACING_1(int, MPI_File_seek_shared, (fh, offset, whence));
	void **args = assemble_args_list(3, &fh, &offset, &whence);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Offset), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
double MPI_Wtime(void)
{
	PILGRIM_TRACING_1(double, MPI_Wtime, ());
	void **args = NULL;
	int* sizes = NULL;
	PILGRIM_TRACING_2(0, sizes, args);
}
int MPI_Add_error_class(int *errorclass)
{
	PILGRIM_TRACING_1(int, MPI_Add_error_class, (errorclass));
	void **args = assemble_args_list(1, errorclass);
	int sizes[] = { 1 * sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Igather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Igather, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request));
	void **args = assemble_args_list(8, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), &recvcount, &recvtype, &root, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(8, sizes, args);
}
int MPI_Info_free(MPI_Info *info)
{
	PILGRIM_TRACING_1(int, MPI_Info_free, (info));
	void **args = assemble_args_list(1, info);
	int sizes[] = { 1 * sizeof(MPI_Info) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Open_port(MPI_Info info, char *port_name)
{
	PILGRIM_TRACING_1(int, MPI_Open_port, (info, port_name));
	void **args = assemble_args_list(2, &info, port_name);
	int sizes[] = { sizeof(MPI_Info), strlen(port_name)+1 };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win)
{
	PILGRIM_TRACING_1(int, MPI_Win_allocate, (size, disp_unit, info, comm, baseptr, win));
	void **args = assemble_args_list(6, &size, &disp_unit, &info, &comm, addr2id(baseptr), win);
	int sizes[] = { sizeof(MPI_Aint), sizeof(int), sizeof(MPI_Info), sizeof(MPI_Comm), sizeof(int), 1 * sizeof(MPI_Win) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Win_set_info(MPI_Win win, MPI_Info info)
{
	PILGRIM_TRACING_1(int, MPI_Win_set_info, (win, info));
	void **args = assemble_args_list(2, &win, &info);
	int sizes[] = { sizeof(MPI_Win), sizeof(MPI_Info) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Unpublish_name(const char *service_name, MPI_Info info, const char *port_name)
{
	PILGRIM_TRACING_1(int, MPI_Unpublish_name, (service_name, info, port_name));
	void **args = assemble_args_list(3, service_name, &info, port_name);
	int sizes[] = { strlen(service_name)+1, sizeof(MPI_Info), strlen(port_name)+1 };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Group_rank(MPI_Group group, int *rank)
{
	PILGRIM_TRACING_1(int, MPI_Group_rank, (group, rank));
	void **args = assemble_args_list(2, &group, rank);
	int sizes[] = { sizeof(MPI_Group), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Lookup_name(const char *service_name, MPI_Info info, char *port_name)
{
	PILGRIM_TRACING_1(int, MPI_Lookup_name, (service_name, info, port_name));
	void **args = assemble_args_list(3, service_name, &info, port_name);
	int sizes[] = { strlen(service_name)+1, sizeof(MPI_Info), strlen(port_name)+1 };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Recv, (buf, count, datatype, source, tag, comm, status));
	void **args = assemble_args_list(6, addr2id(buf), &count, &datatype, &source, &tag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Type_free_keyval(int *type_keyval)
{
	PILGRIM_TRACING_1(int, MPI_Type_free_keyval, (type_keyval));
	void **args = assemble_args_list(1, type_keyval);
	int sizes[] = { 1 * sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used)
{
	PILGRIM_TRACING_1(int, MPI_Comm_get_info, (comm, info_used));
	void **args = assemble_args_list(2, &comm, info_used);
	int sizes[] = { sizeof(MPI_Comm), 1 * sizeof(MPI_Info) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_T_pvar_session_create(MPI_T_pvar_session *session)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_session_create, (session));
	void **args = assemble_args_list(1, session);
	int sizes[] = { 1 * sizeof(MPI_T_pvar_session) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_T_init_thread(int required, int *provided)
{
	PILGRIM_TRACING_1(int, MPI_T_init_thread, (required, provided));
	void **args = assemble_args_list(2, &required, provided);
	int sizes[] = { sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_File_open(MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh)
{
	PILGRIM_TRACING_1(int, MPI_File_open, (comm, filename, amode, info, fh));
	void **args = assemble_args_list(5, &comm, filename, &amode, &info, fh);
	int sizes[] = { sizeof(MPI_Comm), strlen(filename)+1, sizeof(int), sizeof(MPI_Info), 1 * sizeof(MPI_File) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Bsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Bsend, (buf, count, datatype, dest, tag, comm));
	void **args = assemble_args_list(6, addr2id(buf), &count, &datatype, &dest, &tag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Ireduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ireduce_scatter, (sendbuf, recvbuf, recvcounts, datatype, op, comm, request));
	void **args = assemble_args_list(6, addr2id(sendbuf), addr2id(recvbuf), recvcounts, &datatype, &op, &comm);
	int sizes[] = { sizeof(int), sizeof(int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(MPI_Op), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Irecv, (buf, count, datatype, source, tag, comm, request));
	void **args = assemble_args_list(6, addr2id(buf), &count, &datatype, &source, &tag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Issend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Issend, (buf, count, datatype, dest, tag, comm, request));
	void **args = assemble_args_list(6, addr2id(buf), &count, &datatype, &dest, &tag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iwrite_at_all, (fh, offset, buf, count, datatype, request));
	void **args = assemble_args_list(5, &fh, &offset, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Offset), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Abort(MPI_Comm comm, int errorcode)
{
	PILGRIM_TRACING_1(int, MPI_Abort, (comm, errorcode));
	void **args = assemble_args_list(2, &comm, &errorcode);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Pack(const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize, int *position, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Pack, (inbuf, incount, datatype, outbuf, outsize, position, comm));
	void **args = assemble_args_list(7, addr2id(inbuf), &incount, &datatype, addr2id(outbuf), &outsize, position, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), 1 * sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_File_iwrite(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iwrite, (fh, buf, count, datatype, request));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Gatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Gatherv, (sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm));
	void **args = assemble_args_list(9, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), recvcounts, displs, &recvtype, &root, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(9, sizes, args);
}
int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_create, (comm, group, newcomm));
	void **args = assemble_args_list(3, &comm, &group, newcomm);
	int sizes[] = { sizeof(MPI_Comm), sizeof(MPI_Group), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_File_write_ordered(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write_ordered, (fh, buf, count, datatype, status));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_dup, (comm, newcomm));
	void **args = assemble_args_list(2, &comm, newcomm);
	int sizes[] = { sizeof(MPI_Comm), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_T_finalize(void)
{
	PILGRIM_TRACING_1(int, MPI_T_finalize, ());
	void **args = NULL;
	int* sizes = NULL;
	PILGRIM_TRACING_2(0, sizes, args);
}
int MPI_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iread_shared, (fh, buf, count, datatype, request));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_File_set_errhandler(MPI_File file, MPI_Errhandler errhandler)
{
	PILGRIM_TRACING_1(int, MPI_File_set_errhandler, (file, errhandler));
	void **args = assemble_args_list(2, &file, &errhandler);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Errhandler) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Register_datarep(const char *datarep, MPI_Datarep_conversion_function *read_conversion_fn, MPI_Datarep_conversion_function *write_conversion_fn, MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state)
{
	PILGRIM_TRACING_1(int, MPI_Register_datarep, (datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state));
	void **args = assemble_args_list(5, datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, addr2id(extra_state));
	int sizes[] = { strlen(datarep)+1, 1 * sizeof(MPI_Datarep_conversion_function), 1 * sizeof(MPI_Datarep_conversion_function), 1 * sizeof(MPI_Datarep_extent_function), sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Reduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Reduce_scatter, (sendbuf, recvbuf, recvcounts, datatype, op, comm));
	void **args = assemble_args_list(6, addr2id(sendbuf), addr2id(recvbuf), recvcounts, &datatype, &op, &comm);
	int sizes[] = { sizeof(int), sizeof(int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(MPI_Op), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Ibarrier(MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ibarrier, (comm, request));
	void **args = assemble_args_list(1, &comm);
	int sizes[] = { sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Type_create_f90_real(int p, int r, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_f90_real, (p, r, newtype));
	void **args = assemble_args_list(3, &p, &r, newtype);
	int sizes[] = { sizeof(int), sizeof(int), 1 * sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence)
{
	PILGRIM_TRACING_1(int, MPI_File_seek, (fh, offset, whence));
	void **args = assemble_args_list(3, &fh, &offset, &whence);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Offset), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_T_cvar_get_num(int *num_cvar)
{
	PILGRIM_TRACING_1(int, MPI_T_cvar_get_num, (num_cvar));
	void **args = assemble_args_list(1, num_cvar);
	int sizes[] = { 1 * sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Group_incl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup)
{
	PILGRIM_TRACING_1(int, MPI_Group_incl, (group, n, ranks, newgroup));
	void **args = assemble_args_list(4, &group, &n, ranks, newgroup);
	int sizes[] = { sizeof(MPI_Group), sizeof(int), n * sizeof(const int), 1 * sizeof(MPI_Group) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Get_version(int *version, int *subversion)
{
	PILGRIM_TRACING_1(int, MPI_Get_version, (version, subversion));
	void **args = assemble_args_list(2, version, subversion);
	int sizes[] = { 1 * sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Pack_external(const char datarep[], const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, MPI_Aint outsize, MPI_Aint *position)
{
	PILGRIM_TRACING_1(int, MPI_Pack_external, (datarep, inbuf, incount, datatype, outbuf, outsize, position));
	void **args = assemble_args_list(7, datarep, addr2id(inbuf), &incount, &datatype, addr2id(outbuf), &outsize, position);
	int sizes[] = { 1 * sizeof(const char), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Aint), 1 * sizeof(MPI_Aint) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read, (fh, buf, count, datatype, status));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb, MPI_Aint *true_extent)
{
	PILGRIM_TRACING_1(int, MPI_Type_get_true_extent, (datatype, true_lb, true_extent));
	void **args = assemble_args_list(3, &datatype, true_lb, true_extent);
	int sizes[] = { sizeof(MPI_Datatype), 1 * sizeof(MPI_Aint), 1 * sizeof(MPI_Aint) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Cart_create(MPI_Comm comm_old, int ndims, const int dims[], const int periods[], int reorder, MPI_Comm *comm_cart)
{
	PILGRIM_TRACING_1(int, MPI_Cart_create, (comm_old, ndims, dims, periods, reorder, comm_cart));
	void **args = assemble_args_list(6, &comm_old, &ndims, dims, periods, &reorder, comm_cart);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), ndims * sizeof(const int), ndims * sizeof(const int), sizeof(int), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Sendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Sendrecv, (sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status));
	void **args = assemble_args_list(11, addr2id(sendbuf), &sendcount, &sendtype, &dest, &sendtag, addr2id(recvbuf), &recvcount, &recvtype, &source, &recvtag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(11, sizes, args);
}
int MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit, void *baseptr)
{
	PILGRIM_TRACING_1(int, MPI_Win_shared_query, (win, rank, size, disp_unit, baseptr));
	void **args = assemble_args_list(5, &win, &rank, size, disp_unit, addr2id(baseptr));
	int sizes[] = { sizeof(MPI_Win), sizeof(int), 1 * sizeof(MPI_Aint), 1 * sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val)
{
	PILGRIM_TRACING_1(int, MPI_Comm_set_attr, (comm, comm_keyval, attribute_val));
	void **args = assemble_args_list(3, &comm, &comm_keyval, addr2id(attribute_val));
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win)
{
	PILGRIM_TRACING_1(int, MPI_Win_allocate_shared, (size, disp_unit, info, comm, baseptr, win));
	void **args = assemble_args_list(6, &size, &disp_unit, &info, &comm, addr2id(baseptr), win);
	int sizes[] = { sizeof(MPI_Aint), sizeof(int), sizeof(MPI_Info), sizeof(MPI_Comm), sizeof(int), 1 * sizeof(MPI_Win) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Type_get_true_extent_x(MPI_Datatype datatype, MPI_Count *true_lb, MPI_Count *true_extent)
{
	PILGRIM_TRACING_1(int, MPI_Type_get_true_extent_x, (datatype, true_lb, true_extent));
	void **args = assemble_args_list(3, &datatype, true_lb, true_extent);
	int sizes[] = { sizeof(MPI_Datatype), 1 * sizeof(MPI_Count), 1 * sizeof(MPI_Count) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Bcast, (buffer, count, datatype, root, comm));
	void **args = assemble_args_list(5, addr2id(buffer), &count, &datatype, &root, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Get_processor_name(char *name, int *resultlen)
{
	PILGRIM_TRACING_1(int, MPI_Get_processor_name, (name, resultlen));
	void **args = assemble_args_list(2, name, resultlen);
	int sizes[] = { strlen(name)+1, 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Info_set(MPI_Info info, const char *key, const char *value)
{
	PILGRIM_TRACING_1(int, MPI_Info_set, (info, key, value));
	void **args = assemble_args_list(3, &info, key, value);
	int sizes[] = { sizeof(MPI_Info), strlen(key)+1, strlen(value)+1 };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Ineighbor_allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ineighbor_allgather, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request));
	void **args = assemble_args_list(7, addr2id(sendbuf), &sendcount, &sendtype, addr2id(recvbuf), &recvcount, &recvtype, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_Raccumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Raccumulate, (origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request));
	void **args = assemble_args_list(9, addr2id(origin_addr), &origin_count, &origin_datatype, &target_rank, &target_disp, &target_count, &target_datatype, &op, &win);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Op), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(9, sizes, args);
}
int MPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm, int *size)
{
	PILGRIM_TRACING_1(int, MPI_Pack_size, (incount, datatype, comm, size));
	void **args = assemble_args_list(4, &incount, &datatype, &comm, size);
	int sizes[] = { sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Comm), 1 * sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm)
{
	PILGRIM_TRACING_1(int, MPI_Intercomm_merge, (intercomm, high, newintracomm));
	void **args = assemble_args_list(3, &intercomm, &high, newintracomm);
	int sizes[] = { sizeof(MPI_Comm), sizeof(int), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent)
{
	PILGRIM_TRACING_1(int, MPI_File_get_type_extent, (fh, datatype, extent));
	void **args = assemble_args_list(3, &fh, &datatype, extent);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Datatype), 1 * sizeof(MPI_Aint) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Get_library_version(char *version, int *resultlen)
{
	PILGRIM_TRACING_1(int, MPI_Get_library_version, (version, resultlen));
	void **args = assemble_args_list(2, version, resultlen);
	int sizes[] = { strlen(version)+1, 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Isend, (buf, count, datatype, dest, tag, comm, request));
	void **args = assemble_args_list(6, addr2id(buf), &count, &datatype, &dest, &tag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_T_pvar_reset(MPI_T_pvar_session session, MPI_T_pvar_handle handle)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_reset, (session, handle));
	void **args = assemble_args_list(2, &session, &handle);
	int sizes[] = { sizeof(MPI_T_pvar_session), sizeof(MPI_T_pvar_handle) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Start(MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Start, (request));
	void **args = NULL;
	int* sizes = NULL;
	PILGRIM_TRACING_2(0, sizes, args);
}
int MPI_Unpack(const void *inbuf, int insize, int *position, void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Unpack, (inbuf, insize, position, outbuf, outcount, datatype, comm));
	void **args = assemble_args_list(7, addr2id(inbuf), &insize, position, addr2id(outbuf), &outcount, &datatype, &comm);
	int sizes[] = { sizeof(int), sizeof(int), 1 * sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype, char *datarep)
{
	PILGRIM_TRACING_1(int, MPI_File_get_view, (fh, disp, etype, filetype, datarep));
	void **args = assemble_args_list(5, &fh, disp, etype, filetype, datarep);
	int sizes[] = { sizeof(MPI_File), 1 * sizeof(MPI_Offset), 1 * sizeof(MPI_Datatype), 1 * sizeof(MPI_Datatype), strlen(datarep)+1 };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_T_pvar_session_free(MPI_T_pvar_session *session)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_session_free, (session));
	void **args = assemble_args_list(1, session);
	int sizes[] = { 1 * sizeof(MPI_T_pvar_session) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Iexscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Iexscan, (sendbuf, recvbuf, count, datatype, op, comm, request));
	void **args = assemble_args_list(6, addr2id(sendbuf), addr2id(recvbuf), &count, &datatype, &op, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Op), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Unpack_external(const char datarep[], const void *inbuf, MPI_Aint insize, MPI_Aint *position, void *outbuf, int outcount, MPI_Datatype datatype)
{
	PILGRIM_TRACING_1(int, MPI_Unpack_external, (datarep, inbuf, insize, position, outbuf, outcount, datatype));
	void **args = assemble_args_list(7, datarep, addr2id(inbuf), &insize, position, addr2id(outbuf), &outcount, &datatype);
	int sizes[] = { 1 * sizeof(const char), sizeof(int), sizeof(MPI_Aint), 1 * sizeof(MPI_Aint), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_Win_unlock(int rank, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_unlock, (rank, win));
	void **args = assemble_args_list(2, &rank, &win);
	int sizes[] = { sizeof(int), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Test, (request, flag, status));
	void **args = assemble_args_list(1, flag);
	int sizes[] = { 1 * sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Request_get_status(MPI_Request request, int *flag, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Request_get_status, (request, flag, status));
	void **args = assemble_args_list(1, flag);
	int sizes[] = { 1 * sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Waitany(int count, MPI_Request array_of_requests[], int *index, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Waitany, (count, array_of_requests, index, status));
	void **args = assemble_args_list(2, &count, index);
	int sizes[] = { sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read_at_all_end, (fh, buf, status));
	void **args = assemble_args_list(2, &fh, addr2id(buf));
	int sizes[] = { sizeof(MPI_File), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, const char *datarep, MPI_Info info)
{
	PILGRIM_TRACING_1(int, MPI_File_set_view, (fh, disp, etype, filetype, datarep, info));
	void **args = assemble_args_list(6, &fh, &disp, &etype, &filetype, datarep, &info);
	int sizes[] = { sizeof(MPI_File), sizeof(MPI_Offset), sizeof(MPI_Datatype), sizeof(MPI_Datatype), strlen(datarep)+1, sizeof(MPI_Info) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Status_set_elements(MPI_Status *status, MPI_Datatype datatype, int count)
{
	PILGRIM_TRACING_1(int, MPI_Status_set_elements, (status, datatype, count));
	void **args = assemble_args_list(2, &datatype, &count);
	int sizes[] = { sizeof(MPI_Datatype), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_T_category_get_categories(int cat_index, int len, int indices[])
{
	PILGRIM_TRACING_1(int, MPI_T_category_get_categories, (cat_index, len, indices));
	void **args = assemble_args_list(3, &cat_index, &len, indices);
	int sizes[] = { sizeof(int), sizeof(int), len * sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup)
{
	PILGRIM_TRACING_1(int, MPI_Group_range_incl, (group, n, ranges, newgroup));
	void **args = assemble_args_list(4, &group, &n, ranges, newgroup);
	int sizes[] = { sizeof(MPI_Group), sizeof(int), n*3 * sizeof(int), 1 * sizeof(MPI_Group) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Get(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Get, (origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win));
	void **args = assemble_args_list(8, addr2id(origin_addr), &origin_count, &origin_datatype, &target_rank, &target_disp, &target_count, &target_datatype, &win);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(8, sizes, args);
}
int MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Iprobe, (source, tag, comm, flag, status));
	void **args = assemble_args_list(4, &source, &tag, &comm, flag);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Comm), 1 * sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Comm_join(int fd, MPI_Comm *intercomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_join, (fd, intercomm));
	void **args = assemble_args_list(2, &fd, intercomm);
	int sizes[] = { sizeof(int), 1 * sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read_shared, (fh, buf, count, datatype, status));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_Win_detach(MPI_Win win, const void *base)
{
	PILGRIM_TRACING_1(int, MPI_Win_detach, (win, base));
	void **args = assemble_args_list(2, &win, addr2id(base));
	int sizes[] = { sizeof(MPI_Win), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag, MPI_Message *message, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Improbe, (source, tag, comm, flag, message, status));
	void **args = assemble_args_list(5, &source, &tag, &comm, flag, message);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Comm), 1 * sizeof(int), 1 * sizeof(MPI_Message) };
	PILGRIM_TRACING_2(5, sizes, args);
}
int MPI_Ssend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Ssend, (buf, count, datatype, dest, tag, comm));
	void **args = assemble_args_list(6, addr2id(buf), &count, &datatype, &dest, &tag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Ineighbor_alltoallw(const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ineighbor_alltoallw, (sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request));
	void **args = assemble_args_list(9, addr2id(sendbuf), sendcounts, sdispls, sendtypes, addr2id(recvbuf), recvcounts, rdispls, recvtypes, &comm);
	int sizes[] = { sizeof(int), 1 * sizeof(const int), 1 * sizeof(const MPI_Aint), 1 * sizeof(const MPI_Datatype), sizeof(int), 1 * sizeof(const int), 1 * sizeof(const MPI_Aint), 1 * sizeof(const MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(9, sizes, args);
}
int MPI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ineighbor_alltoallv, (sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request));
	void **args = assemble_args_list(9, addr2id(sendbuf), sendcounts, sdispls, &sendtype, addr2id(recvbuf), recvcounts, rdispls, &recvtype, &comm);
	int sizes[] = { sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(int), 1 * sizeof(const int), 1 * sizeof(const int), sizeof(MPI_Datatype), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(9, sizes, args);
}
double MPI_Wtick(void)
{
	PILGRIM_TRACING_1(double, MPI_Wtick, ());
	void **args = NULL;
	int* sizes = NULL;
	PILGRIM_TRACING_2(0, sizes, args);
}
int MPI_T_category_get_cvars(int cat_index, int len, int indices[])
{
	PILGRIM_TRACING_1(int, MPI_T_category_get_cvars, (cat_index, len, indices));
	void **args = assemble_args_list(3, &cat_index, &len, indices);
	int sizes[] = { sizeof(int), sizeof(int), len * sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Errhandler_free(MPI_Errhandler *errhandler)
{
	PILGRIM_TRACING_1(int, MPI_Errhandler_free, (errhandler));
	void **args = assemble_args_list(1, errhandler);
	int sizes[] = { 1 * sizeof(MPI_Errhandler) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Topo_test(MPI_Comm comm, int *status)
{
	PILGRIM_TRACING_1(int, MPI_Topo_test, (comm, status));
	void **args = assemble_args_list(2, &comm, status);
	int sizes[] = { sizeof(MPI_Comm), 1 * sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Ireduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ireduce, (sendbuf, recvbuf, count, datatype, op, root, comm, request));
	void **args = assemble_args_list(7, addr2id(sendbuf), addr2id(recvbuf), &count, &datatype, &op, &root, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Op), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(7, sizes, args);
}
int MPI_File_get_errhandler(MPI_File file, MPI_Errhandler *errhandler)
{
	PILGRIM_TRACING_1(int, MPI_File_get_errhandler, (file, errhandler));
	void **args = assemble_args_list(2, &file, errhandler);
	int sizes[] = { sizeof(MPI_File), 1 * sizeof(MPI_Errhandler) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Bsend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Bsend_init, (buf, count, datatype, dest, tag, comm, request));
	void **args = assemble_args_list(6, addr2id(buf), &count, &datatype, &dest, &tag, &comm);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(int), sizeof(MPI_Comm) };
	PILGRIM_TRACING_2(6, sizes, args);
}
int MPI_Add_error_string(int errorcode, const char *string)
{
	PILGRIM_TRACING_1(int, MPI_Add_error_string, (errorcode, string));
	void **args = assemble_args_list(2, &errorcode, string);
	int sizes[] = { sizeof(int), strlen(string)+1 };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Accumulate, (origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win));
	void **args = assemble_args_list(9, addr2id(origin_addr), &origin_count, &origin_datatype, &target_rank, &target_disp, &target_count, &target_datatype, &op, &win);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Datatype), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(MPI_Datatype), sizeof(MPI_Op), sizeof(MPI_Win) };
	PILGRIM_TRACING_2(9, sizes, args);
}
int MPI_T_category_get_num(int *num_cat)
{
	PILGRIM_TRACING_1(int, MPI_T_category_get_num, (num_cat));
	void **args = assemble_args_list(1, num_cat);
	int sizes[] = { 1 * sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args);
}
int MPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler)
{
	PILGRIM_TRACING_1(int, MPI_Comm_set_errhandler, (comm, errhandler));
	void **args = assemble_args_list(2, &comm, &errhandler);
	int sizes[] = { sizeof(MPI_Comm), sizeof(MPI_Errhandler) };
	PILGRIM_TRACING_2(2, sizes, args);
}
MPI_Aint MPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2)
{
	PILGRIM_TRACING_1(MPI_Aint, MPI_Aint_diff, (addr1, addr2));
	void **args = assemble_args_list(2, &addr1, &addr2);
	int sizes[] = { sizeof(MPI_Aint), sizeof(MPI_Aint) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_File_write_ordered_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype)
{
	PILGRIM_TRACING_1(int, MPI_File_write_ordered_begin, (fh, buf, count, datatype));
	void **args = assemble_args_list(4, &fh, addr2id(buf), &count, &datatype);
	int sizes[] = { sizeof(MPI_File), sizeof(int), sizeof(int), sizeof(MPI_Datatype) };
	PILGRIM_TRACING_2(4, sizes, args);
}
int MPI_File_write_ordered_end(MPI_File fh, const void *buf, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write_ordered_end, (fh, buf, status));
	void **args = assemble_args_list(2, &fh, addr2id(buf));
	int sizes[] = { sizeof(MPI_File), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges)
{
	PILGRIM_TRACING_1(int, MPI_Graphdims_get, (comm, nnodes, nedges));
	void **args = assemble_args_list(3, &comm, nnodes, nedges);
	int sizes[] = { sizeof(MPI_Comm), 1 * sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *var_class, MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind, int *readonly, int *continuous, int *atomic)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_get_info, (pvar_index, name, name_len, verbosity, var_class, datatype, enumtype, desc, desc_len, bind, readonly, continuous, atomic));
	void **args = assemble_args_list(13, &pvar_index, name, name_len, verbosity, var_class, datatype, enumtype, desc, desc_len, bind, readonly, continuous, atomic);
	int sizes[] = { sizeof(int), strlen(name)+1, 1 * sizeof(int), 1 * sizeof(int), 1 * sizeof(int), 1 * sizeof(MPI_Datatype), 1 * sizeof(MPI_T_enum), strlen(desc)+1, 1 * sizeof(int), 1 * sizeof(int), 1 * sizeof(int), 1 * sizeof(int), 1 * sizeof(int) };
	PILGRIM_TRACING_2(13, sizes, args);
}
