/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */
#include <mpi.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "pilgrim.h"
#include "pilgrim_consts.h"
static int placeholder = 0;
static int g_local_rank;
MPI_Status g_c_status;
int c_MPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval)
{
	PILGRIM_TRACING_1(int, MPI_Type_delete_attr, (datatype, type_keyval));
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, &type_keyval);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval) { return c_MPI_Type_delete_attr(datatype, type_keyval); }
extern void f_mpi_type_delete_attr(MPI_Fint* datatype, int* type_keyval, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Type_delete_attr(c_handle_0, (*type_keyval));
	*datatype = PMPI_Type_c2f(c_handle_0);
}
extern void MPI_TYPE_DELETE_ATTR(MPI_Fint* datatype, int* type_keyval, MPI_Fint *ierr) {
	f_mpi_type_delete_attr(datatype, type_keyval, ierr);
}
extern void mpi_type_delete_attr(MPI_Fint* datatype, int* type_keyval, MPI_Fint *ierr) {
	f_mpi_type_delete_attr(datatype, type_keyval, ierr);
}
extern void mpi_type_delete_attr_(MPI_Fint* datatype, int* type_keyval, MPI_Fint *ierr) {
	f_mpi_type_delete_attr(datatype, type_keyval, ierr);
}
extern void mpi_type_delete_attr__(MPI_Fint* datatype, int* type_keyval, MPI_Fint *ierr) {
	f_mpi_type_delete_attr(datatype, type_keyval, ierr);
}
int c_MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Sendrecv_replace, (buf, count, datatype, dest, sendtag, source, recvtag, comm, status));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int dest_rank = g_mpi_rank - dest;
	if(dest == MPI_ANY_SOURCE) dest_rank = PILGRIM_MPI_ANY_SOURCE;
	if(dest == MPI_PROC_NULL) dest_rank = PILGRIM_MPI_PROC_NULL;
	int source_rank = g_mpi_rank - source;
	if(source == MPI_ANY_SOURCE) source_rank = PILGRIM_MPI_ANY_SOURCE;
	if(source == MPI_PROC_NULL) source_rank = PILGRIM_MPI_PROC_NULL;
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	int status_arg[2] = {0};
	if(source == MPI_ANY_SOURCE && status && status!=MPI_STATUS_IGNORE) status_arg[0] = status->MPI_SOURCE;
	if(recvtag == MPI_ANY_TAG && status && status!=MPI_STATUS_IGNORE) status_arg[1] = status->MPI_TAG;
	void **args = assemble_args_list(9, &mem_attr_0, &count, &obj_id_0, &dest_rank, &sendtag, &source_rank, &recvtag, &obj_id_1, status_arg);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(9, sizes, args, -1);
}
int MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status *status) { return c_MPI_Sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status); }
extern void f_mpi_sendrecv_replace(void* buf, int* count, MPI_Fint* datatype, int* dest, int* sendtag, int* source, int* recvtag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_Sendrecv_replace(buf, (*count), c_handle_0, (*dest), (*sendtag), (*source), (*recvtag), c_handle_1, &c_handle_2);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_SENDRECV_REPLACE(void* buf, int* count, MPI_Fint* datatype, int* dest, int* sendtag, int* source, int* recvtag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status, ierr);
}
extern void mpi_sendrecv_replace(void* buf, int* count, MPI_Fint* datatype, int* dest, int* sendtag, int* source, int* recvtag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status, ierr);
}
extern void mpi_sendrecv_replace_(void* buf, int* count, MPI_Fint* datatype, int* dest, int* sendtag, int* source, int* recvtag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status, ierr);
}
extern void mpi_sendrecv_replace__(void* buf, int* count, MPI_Fint* datatype, int* dest, int* sendtag, int* source, int* recvtag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status, ierr);
}
int c_MPI_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win)
{
	PILGRIM_TRACING_1(int, MPI_Win_create, (base, size, disp_unit, info, comm, win));
	MemPtrAttr mem_attr_0;
	addr2id(base, &mem_attr_0);
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	int obj_id_2 = MPI_OBJ_ID(MPI_Win, win);
	void **args = assemble_args_list(6, &mem_attr_0, &size, &disp_unit, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(MPI_Aint), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win) { return c_MPI_Win_create(base, size, disp_unit, info, comm, win); }
extern void f_mpi_win_create(void* base, MPI_Aint size, int* disp_unit, MPI_Fint* info, MPI_Fint* comm, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Win c_handle_2;
	c_handle_2 = PMPI_Win_f2c(*win);
	c_MPI_Win_create(base, size, (*disp_unit), c_handle_0, c_handle_1, &c_handle_2);
	*win = PMPI_Win_c2f(c_handle_2);
}
extern void MPI_WIN_CREATE(void* base, MPI_Aint size, int* disp_unit, MPI_Fint* info, MPI_Fint* comm, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_create(base, size, disp_unit, info, comm, win, ierr);
}
extern void mpi_win_create(void* base, MPI_Aint size, int* disp_unit, MPI_Fint* info, MPI_Fint* comm, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_create(base, size, disp_unit, info, comm, win, ierr);
}
extern void mpi_win_create_(void* base, MPI_Aint size, int* disp_unit, MPI_Fint* info, MPI_Fint* comm, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_create(base, size, disp_unit, info, comm, win, ierr);
}
extern void mpi_win_create__(void* base, MPI_Aint size, int* disp_unit, MPI_Fint* info, MPI_Fint* comm, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_create(base, size, disp_unit, info, comm, win, ierr);
}
int c_MPI_File_write_all_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype)
{
	PILGRIM_TRACING_1(int, MPI_File_write_all_begin, (fh, buf, count, datatype));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(4, &obj_id_0, &mem_attr_0, &count, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_File_write_all_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype) { return c_MPI_File_write_all_begin(fh, buf, count, datatype); }
extern void f_mpi_file_write_all_begin(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	c_MPI_File_write_all_begin(c_handle_0, buf, (*count), c_handle_1);
	*fh = PMPI_File_c2f(c_handle_0);
}
extern void MPI_FILE_WRITE_ALL_BEGIN(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_write_all_begin(fh, buf, count, datatype, ierr);
}
extern void mpi_file_write_all_begin(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_write_all_begin(fh, buf, count, datatype, ierr);
}
extern void mpi_file_write_all_begin_(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_write_all_begin(fh, buf, count, datatype, ierr);
}
extern void mpi_file_write_all_begin__(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_write_all_begin(fh, buf, count, datatype, ierr);
}
int c_MPI_Error_class(int errorcode, int *errorclass)
{
	PILGRIM_TRACING_1(int, MPI_Error_class, (errorcode, errorclass));
	void **args = assemble_args_list(2, &errorcode, errorclass);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Error_class(int errorcode, int *errorclass) { return c_MPI_Error_class(errorcode, errorclass); }
extern void f_mpi_error_class(int* errorcode, int* errorclass, MPI_Fint *ierr) {
	c_MPI_Error_class((*errorcode), errorclass);
}
extern void MPI_ERROR_CLASS(int* errorcode, int* errorclass, MPI_Fint *ierr) {
	f_mpi_error_class(errorcode, errorclass, ierr);
}
extern void mpi_error_class(int* errorcode, int* errorclass, MPI_Fint *ierr) {
	f_mpi_error_class(errorcode, errorclass, ierr);
}
extern void mpi_error_class_(int* errorcode, int* errorclass, MPI_Fint *ierr) {
	f_mpi_error_class(errorcode, errorclass, ierr);
}
extern void mpi_error_class__(int* errorcode, int* errorclass, MPI_Fint *ierr) {
	f_mpi_error_class(errorcode, errorclass, ierr);
}
int c_MPI_Free_mem(void *base)
{
	PILGRIM_TRACING_1(int, MPI_Free_mem, (base));
	MemPtrAttr mem_attr_0;
	addr2id(base, &mem_attr_0);
	void **args = assemble_args_list(1, &mem_attr_0);
	int sizes[] = { sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Free_mem(void *base) { return c_MPI_Free_mem(base); }
extern void f_mpi_free_mem(void* base, MPI_Fint *ierr) {
	c_MPI_Free_mem(base);
}
extern void MPI_FREE_MEM(void* base, MPI_Fint *ierr) {
	f_mpi_free_mem(base, ierr);
}
extern void mpi_free_mem(void* base, MPI_Fint *ierr) {
	f_mpi_free_mem(base, ierr);
}
extern void mpi_free_mem_(void* base, MPI_Fint *ierr) {
	f_mpi_free_mem(base, ierr);
}
extern void mpi_free_mem__(void* base, MPI_Fint *ierr) {
	f_mpi_free_mem(base, ierr);
}
int c_MPI_Win_get_info(MPI_Win win, MPI_Info *info_used)
{
	PILGRIM_TRACING_1(int, MPI_Win_get_info, (win, info_used));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Info, info_used);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Win_get_info(MPI_Win win, MPI_Info *info_used) { return c_MPI_Win_get_info(win, info_used); }
extern void f_mpi_win_get_info(MPI_Fint* win, MPI_Fint* info_used, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	MPI_Info c_handle_1;
	c_handle_1 = PMPI_Info_f2c(*info_used);
	c_MPI_Win_get_info(c_handle_0, &c_handle_1);
	*info_used = PMPI_Info_c2f(c_handle_1);
}
extern void MPI_WIN_GET_INFO(MPI_Fint* win, MPI_Fint* info_used, MPI_Fint *ierr) {
	f_mpi_win_get_info(win, info_used, ierr);
}
extern void mpi_win_get_info(MPI_Fint* win, MPI_Fint* info_used, MPI_Fint *ierr) {
	f_mpi_win_get_info(win, info_used, ierr);
}
extern void mpi_win_get_info_(MPI_Fint* win, MPI_Fint* info_used, MPI_Fint *ierr) {
	f_mpi_win_get_info(win, info_used, ierr);
}
extern void mpi_win_get_info__(MPI_Fint* win, MPI_Fint* info_used, MPI_Fint *ierr) {
	f_mpi_win_get_info(win, info_used, ierr);
}
int c_MPI_Buffer_detach(void *buffer_addr, int *size)
{
	PILGRIM_TRACING_1(int, MPI_Buffer_detach, (buffer_addr, size));
	MemPtrAttr mem_attr_0;
	addr2id(buffer_addr, &mem_attr_0);
	void **args = assemble_args_list(2, &mem_attr_0, size);
	int sizes[] = { sizeof(MemPtrAttr), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Buffer_detach(void *buffer_addr, int *size) { return c_MPI_Buffer_detach(buffer_addr, size); }
extern void f_mpi_buffer_detach(void* buffer_addr, int* size, MPI_Fint *ierr) {
	c_MPI_Buffer_detach(buffer_addr, size);
}
extern void MPI_BUFFER_DETACH(void* buffer_addr, int* size, MPI_Fint *ierr) {
	f_mpi_buffer_detach(buffer_addr, size, ierr);
}
extern void mpi_buffer_detach(void* buffer_addr, int* size, MPI_Fint *ierr) {
	f_mpi_buffer_detach(buffer_addr, size, ierr);
}
extern void mpi_buffer_detach_(void* buffer_addr, int* size, MPI_Fint *ierr) {
	f_mpi_buffer_detach(buffer_addr, size, ierr);
}
extern void mpi_buffer_detach__(void* buffer_addr, int* size, MPI_Fint *ierr) {
	f_mpi_buffer_detach(buffer_addr, size, ierr);
}
int c_MPI_Win_flush_local_all(MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_flush_local_all, (win));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(1, &obj_id_0);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Win_flush_local_all(MPI_Win win) { return c_MPI_Win_flush_local_all(win); }
extern void f_mpi_win_flush_local_all(MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_flush_local_all(c_handle_0);
}
extern void MPI_WIN_FLUSH_LOCAL_ALL(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_flush_local_all(win, ierr);
}
extern void mpi_win_flush_local_all(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_flush_local_all(win, ierr);
}
extern void mpi_win_flush_local_all_(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_flush_local_all(win, ierr);
}
extern void mpi_win_flush_local_all__(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_flush_local_all(win, ierr);
}
int c_MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn, MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval, void *extra_state)
{
	PILGRIM_TRACING_1(int, MPI_Comm_create_keyval, (comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state));
	MemPtrAttr mem_attr_0;
	addr2id(extra_state, &mem_attr_0);
	void **args = assemble_args_list(4, comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, &mem_attr_0);
	int sizes[] = { 1*sizeof(MPI_Comm_copy_attr_function), 1*sizeof(MPI_Comm_delete_attr_function), 1*sizeof(int), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn, MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval, void *extra_state) { return c_MPI_Comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state); }
extern void f_mpi_comm_create_keyval(MPI_Comm_copy_attr_function* comm_copy_attr_fn, MPI_Comm_delete_attr_function* comm_delete_attr_fn, int* comm_keyval, void* extra_state, MPI_Fint *ierr) {
	c_MPI_Comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state);
}
extern void MPI_COMM_CREATE_KEYVAL(MPI_Comm_copy_attr_function* comm_copy_attr_fn, MPI_Comm_delete_attr_function* comm_delete_attr_fn, int* comm_keyval, void* extra_state, MPI_Fint *ierr) {
	f_mpi_comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state, ierr);
}
extern void mpi_comm_create_keyval(MPI_Comm_copy_attr_function* comm_copy_attr_fn, MPI_Comm_delete_attr_function* comm_delete_attr_fn, int* comm_keyval, void* extra_state, MPI_Fint *ierr) {
	f_mpi_comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state, ierr);
}
extern void mpi_comm_create_keyval_(MPI_Comm_copy_attr_function* comm_copy_attr_fn, MPI_Comm_delete_attr_function* comm_delete_attr_fn, int* comm_keyval, void* extra_state, MPI_Fint *ierr) {
	f_mpi_comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state, ierr);
}
extern void mpi_comm_create_keyval__(MPI_Comm_copy_attr_function* comm_copy_attr_fn, MPI_Comm_delete_attr_function* comm_delete_attr_fn, int* comm_keyval, void* extra_state, MPI_Fint *ierr) {
	f_mpi_comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state, ierr);
}
int c_MPI_Comm_get_parent(MPI_Comm *parent)
{
	PILGRIM_TRACING_1(int, MPI_Comm_get_parent, (parent));
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, parent);
	void **args = assemble_args_list(1, &obj_id_0);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Comm_get_parent(MPI_Comm *parent) { return c_MPI_Comm_get_parent(parent); }
extern void f_mpi_comm_get_parent(MPI_Fint* parent, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*parent);
	c_MPI_Comm_get_parent(&c_handle_0);
	*parent = PMPI_Comm_c2f(c_handle_0);
}
extern void MPI_COMM_GET_PARENT(MPI_Fint* parent, MPI_Fint *ierr) {
	f_mpi_comm_get_parent(parent, ierr);
}
extern void mpi_comm_get_parent(MPI_Fint* parent, MPI_Fint *ierr) {
	f_mpi_comm_get_parent(parent, ierr);
}
extern void mpi_comm_get_parent_(MPI_Fint* parent, MPI_Fint *ierr) {
	f_mpi_comm_get_parent(parent, ierr);
}
extern void mpi_comm_get_parent__(MPI_Fint* parent, MPI_Fint *ierr) {
	f_mpi_comm_get_parent(parent, ierr);
}
int c_MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle, MPI_T_cvar_handle *handle, int *count)
{
	PILGRIM_TRACING_1(int, MPI_T_cvar_handle_alloc, (cvar_index, obj_handle, handle, count));
	MemPtrAttr mem_attr_0;
	addr2id(obj_handle, &mem_attr_0);
	void **args = assemble_args_list(4, &cvar_index, &mem_attr_0, handle, count);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), 1*sizeof(MPI_T_cvar_handle), 1*sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle, MPI_T_cvar_handle *handle, int *count) { return c_MPI_T_cvar_handle_alloc(cvar_index, obj_handle, handle, count); }
int c_MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Comm_idup, (comm, newcomm, request));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, newcomm);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm, MPI_Request *request) { return c_MPI_Comm_idup(comm, newcomm, request); }
extern void f_mpi_comm_idup(MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*newcomm);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_Comm_idup(c_handle_0, &c_handle_1, &c_handle_2);
	*newcomm = PMPI_Comm_c2f(c_handle_1);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_COMM_IDUP(MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_comm_idup(comm, newcomm, request, ierr);
}
extern void mpi_comm_idup(MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_comm_idup(comm, newcomm, request, ierr);
}
extern void mpi_comm_idup_(MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_comm_idup(comm, newcomm, request, ierr);
}
extern void mpi_comm_idup__(MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_comm_idup(comm, newcomm, request, ierr);
}
int c_MPI_Win_set_name(MPI_Win win, const char *win_name)
{
	PILGRIM_TRACING_1(int, MPI_Win_set_name, (win, win_name));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, win_name);
	int sizes[] = { sizeof(int), strlen(win_name)+1 };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Win_set_name(MPI_Win win, const char *win_name) { return c_MPI_Win_set_name(win, win_name); }
extern void f_mpi_win_set_name(MPI_Fint* win, const char* win_name, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_set_name(c_handle_0, win_name);
	*win = PMPI_Win_c2f(c_handle_0);
}
extern void MPI_WIN_SET_NAME(MPI_Fint* win, const char* win_name, MPI_Fint *ierr) {
	f_mpi_win_set_name(win, win_name, ierr);
}
extern void mpi_win_set_name(MPI_Fint* win, const char* win_name, MPI_Fint *ierr) {
	f_mpi_win_set_name(win, win_name, ierr);
}
extern void mpi_win_set_name_(MPI_Fint* win, const char* win_name, MPI_Fint *ierr) {
	f_mpi_win_set_name(win, win_name, ierr);
}
extern void mpi_win_set_name__(MPI_Fint* win, const char* win_name, MPI_Fint *ierr) {
	f_mpi_win_set_name(win, win_name, ierr);
}
int c_MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_dup, (oldtype, newtype));
	MPI_Datatype obj_0 = oldtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, newtype);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype) { return c_MPI_Type_dup(oldtype, newtype); }
extern void f_mpi_type_dup(MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*oldtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*newtype);
	c_MPI_Type_dup(c_handle_0, &c_handle_1);
	*newtype = PMPI_Type_c2f(c_handle_1);
}
extern void MPI_TYPE_DUP(MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_dup(oldtype, newtype, ierr);
}
extern void mpi_type_dup(MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_dup(oldtype, newtype, ierr);
}
extern void mpi_type_dup_(MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_dup(oldtype, newtype, ierr);
}
extern void mpi_type_dup__(MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_dup(oldtype, newtype, ierr);
}
int c_MPI_T_pvar_get_index(const char *name, int var_class, int *pvar_index)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_get_index, (name, var_class, pvar_index));
	void **args = assemble_args_list(3, name, &var_class, pvar_index);
	int sizes[] = { strlen(name)+1, sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_T_pvar_get_index(const char *name, int var_class, int *pvar_index) { return c_MPI_T_pvar_get_index(name, var_class, pvar_index); }
int c_MPI_Add_error_code(int errorclass, int *errorcode)
{
	PILGRIM_TRACING_1(int, MPI_Add_error_code, (errorclass, errorcode));
	void **args = assemble_args_list(2, &errorclass, errorcode);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Add_error_code(int errorclass, int *errorcode) { return c_MPI_Add_error_code(errorclass, errorcode); }
extern void f_mpi_add_error_code(int* errorclass, int* errorcode, MPI_Fint *ierr) {
	c_MPI_Add_error_code((*errorclass), errorcode);
}
extern void MPI_ADD_ERROR_CODE(int* errorclass, int* errorcode, MPI_Fint *ierr) {
	f_mpi_add_error_code(errorclass, errorcode, ierr);
}
extern void mpi_add_error_code(int* errorclass, int* errorcode, MPI_Fint *ierr) {
	f_mpi_add_error_code(errorclass, errorcode, ierr);
}
extern void mpi_add_error_code_(int* errorclass, int* errorcode, MPI_Fint *ierr) {
	f_mpi_add_error_code(errorclass, errorcode, ierr);
}
extern void mpi_add_error_code__(int* errorclass, int* errorcode, MPI_Fint *ierr) {
	f_mpi_add_error_code(errorclass, errorcode, ierr);
}
int c_MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_resized, (oldtype, lb, extent, newtype));
	MPI_Datatype obj_0 = oldtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, newtype);
	void **args = assemble_args_list(4, &obj_id_0, &lb, &extent, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MPI_Aint), sizeof(MPI_Aint), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent, MPI_Datatype *newtype) { return c_MPI_Type_create_resized(oldtype, lb, extent, newtype); }
extern void f_mpi_type_create_resized(MPI_Fint* oldtype, MPI_Aint lb, MPI_Aint extent, MPI_Fint* newtype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*oldtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*newtype);
	c_MPI_Type_create_resized(c_handle_0, lb, extent, &c_handle_1);
	*newtype = PMPI_Type_c2f(c_handle_1);
}
extern void MPI_TYPE_CREATE_RESIZED(MPI_Fint* oldtype, MPI_Aint lb, MPI_Aint extent, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_resized(oldtype, lb, extent, newtype, ierr);
}
extern void mpi_type_create_resized(MPI_Fint* oldtype, MPI_Aint lb, MPI_Aint extent, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_resized(oldtype, lb, extent, newtype, ierr);
}
extern void mpi_type_create_resized_(MPI_Fint* oldtype, MPI_Aint lb, MPI_Aint extent, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_resized(oldtype, lb, extent, newtype, ierr);
}
extern void mpi_type_create_resized__(MPI_Fint* oldtype, MPI_Aint lb, MPI_Aint extent, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_resized(oldtype, lb, extent, newtype, ierr);
}
int c_MPI_Get_address(const void *location, MPI_Aint *address)
{
	PILGRIM_TRACING_1(int, MPI_Get_address, (location, address));
	MemPtrAttr mem_attr_0;
	addr2id(location, &mem_attr_0);
	void **args = assemble_args_list(2, &mem_attr_0, address);
	int sizes[] = { sizeof(MemPtrAttr), 1*sizeof(MPI_Aint) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Get_address(const void *location, MPI_Aint *address) { return c_MPI_Get_address(location, address); }
extern void f_mpi_get_address(const void* location, MPI_Aint* address, MPI_Fint *ierr) {
	c_MPI_Get_address(location, address);
}
extern void MPI_GET_ADDRESS(const void* location, MPI_Aint* address, MPI_Fint *ierr) {
	f_mpi_get_address(location, address, ierr);
}
extern void mpi_get_address(const void* location, MPI_Aint* address, MPI_Fint *ierr) {
	f_mpi_get_address(location, address, ierr);
}
extern void mpi_get_address_(const void* location, MPI_Aint* address, MPI_Fint *ierr) {
	f_mpi_get_address(location, address, ierr);
}
extern void mpi_get_address__(const void* location, MPI_Aint* address, MPI_Fint *ierr) {
	f_mpi_get_address(location, address, ierr);
}
int c_MPI_Iallgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Iallgather, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(7, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, &recvcount, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Iallgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return c_MPI_Iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request); }
extern void f_mpi_iallgather(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Iallgather(sendbuf, (*sendcount), c_handle_0, recvbuf, (*recvcount), c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_IALLGATHER(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}
extern void mpi_iallgather(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}
extern void mpi_iallgather_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}
extern void mpi_iallgather__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}
int c_MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype, int *count)
{
	PILGRIM_TRACING_1(int, MPI_Get_count, (status, datatype, count));
	int status_arg[2] = {0};
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	void **args = assemble_args_list(3, status_arg, &obj_id_0, count);
	int sizes[] = { sizeof(int)*2, sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype, int *count) { return c_MPI_Get_count(status, datatype, count); }
extern void f_mpi_get_count(MPI_Fint* status, MPI_Fint* datatype, int* count, MPI_Fint *ierr) {
	MPI_Status c_handle_0;
	PMPI_Status_f2c(status, &c_handle_0);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	c_MPI_Get_count(&c_handle_0, c_handle_1, count);
}
extern void MPI_GET_COUNT(MPI_Fint* status, MPI_Fint* datatype, int* count, MPI_Fint *ierr) {
	f_mpi_get_count(status, datatype, count, ierr);
}
extern void mpi_get_count(MPI_Fint* status, MPI_Fint* datatype, int* count, MPI_Fint *ierr) {
	f_mpi_get_count(status, datatype, count, ierr);
}
extern void mpi_get_count_(MPI_Fint* status, MPI_Fint* datatype, int* count, MPI_Fint *ierr) {
	f_mpi_get_count(status, datatype, count, ierr);
}
extern void mpi_get_count__(MPI_Fint* status, MPI_Fint* datatype, int* count, MPI_Fint *ierr) {
	f_mpi_get_count(status, datatype, count, ierr);
}
int c_MPI_Grequest_start(MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn, MPI_Grequest_cancel_function *cancel_fn, void *extra_state, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Grequest_start, (query_fn, free_fn, cancel_fn, extra_state, request));
	MemPtrAttr mem_attr_0;
	addr2id(extra_state, &mem_attr_0);
	void **args = assemble_args_list(4, query_fn, free_fn, cancel_fn, &mem_attr_0);
	int sizes[] = { 1*sizeof(MPI_Grequest_query_function), 1*sizeof(MPI_Grequest_free_function), 1*sizeof(MPI_Grequest_cancel_function), sizeof(MemPtrAttr), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Grequest_start(MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn, MPI_Grequest_cancel_function *cancel_fn, void *extra_state, MPI_Request *request) { return c_MPI_Grequest_start(query_fn, free_fn, cancel_fn, extra_state, request); }
extern void f_mpi_grequest_start(MPI_Grequest_query_function* query_fn, MPI_Grequest_free_function* free_fn, MPI_Grequest_cancel_function* cancel_fn, void* extra_state, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Request c_handle_0;
	c_handle_0 = PMPI_Request_f2c(*request);
	c_MPI_Grequest_start(query_fn, free_fn, cancel_fn, extra_state, &c_handle_0);
	*request = PMPI_Request_c2f(c_handle_0);
}
extern void MPI_GREQUEST_START(MPI_Grequest_query_function* query_fn, MPI_Grequest_free_function* free_fn, MPI_Grequest_cancel_function* cancel_fn, void* extra_state, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_grequest_start(query_fn, free_fn, cancel_fn, extra_state, request, ierr);
}
extern void mpi_grequest_start(MPI_Grequest_query_function* query_fn, MPI_Grequest_free_function* free_fn, MPI_Grequest_cancel_function* cancel_fn, void* extra_state, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_grequest_start(query_fn, free_fn, cancel_fn, extra_state, request, ierr);
}
extern void mpi_grequest_start_(MPI_Grequest_query_function* query_fn, MPI_Grequest_free_function* free_fn, MPI_Grequest_cancel_function* cancel_fn, void* extra_state, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_grequest_start(query_fn, free_fn, cancel_fn, extra_state, request, ierr);
}
extern void mpi_grequest_start__(MPI_Grequest_query_function* query_fn, MPI_Grequest_free_function* free_fn, MPI_Grequest_cancel_function* cancel_fn, void* extra_state, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_grequest_start(query_fn, free_fn, cancel_fn, extra_state, request, ierr);
}
int c_MPI_Cartdim_get(MPI_Comm comm, int *ndims)
{
	PILGRIM_TRACING_1(int, MPI_Cartdim_get, (comm, ndims));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, ndims);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Cartdim_get(MPI_Comm comm, int *ndims) { return c_MPI_Cartdim_get(comm, ndims); }
extern void f_mpi_cartdim_get(MPI_Fint* comm, int* ndims, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Cartdim_get(c_handle_0, ndims);
}
extern void MPI_CARTDIM_GET(MPI_Fint* comm, int* ndims, MPI_Fint *ierr) {
	f_mpi_cartdim_get(comm, ndims, ierr);
}
extern void mpi_cartdim_get(MPI_Fint* comm, int* ndims, MPI_Fint *ierr) {
	f_mpi_cartdim_get(comm, ndims, ierr);
}
extern void mpi_cartdim_get_(MPI_Fint* comm, int* ndims, MPI_Fint *ierr) {
	f_mpi_cartdim_get(comm, ndims, ierr);
}
extern void mpi_cartdim_get__(MPI_Fint* comm, int* ndims, MPI_Fint *ierr) {
	f_mpi_cartdim_get(comm, ndims, ierr);
}
int c_MPI_Allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Allgather, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(7, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, &recvcount, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { return c_MPI_Allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm); }
extern void f_mpi_allgather(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Allgather(sendbuf, (*sendcount), c_handle_0, recvbuf, (*recvcount), c_handle_1, c_handle_2);
}
extern void MPI_ALLGATHER(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}
extern void mpi_allgather(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}
extern void mpi_allgather_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}
extern void mpi_allgather__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}
int c_MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[])
{
	PILGRIM_TRACING_1(int, MPI_Cart_coords, (comm, rank, maxdims, coords));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(4, &obj_id_0, &rank, &maxdims, coords);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), maxdims*sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[]) { return c_MPI_Cart_coords(comm, rank, maxdims, coords); }
extern void f_mpi_cart_coords(MPI_Fint* comm, int* rank, int* maxdims, int coords[], MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Cart_coords(c_handle_0, (*rank), (*maxdims), coords);
}
extern void MPI_CART_COORDS(MPI_Fint* comm, int* rank, int* maxdims, int coords[], MPI_Fint *ierr) {
	f_mpi_cart_coords(comm, rank, maxdims, coords, ierr);
}
extern void mpi_cart_coords(MPI_Fint* comm, int* rank, int* maxdims, int coords[], MPI_Fint *ierr) {
	f_mpi_cart_coords(comm, rank, maxdims, coords, ierr);
}
extern void mpi_cart_coords_(MPI_Fint* comm, int* rank, int* maxdims, int coords[], MPI_Fint *ierr) {
	f_mpi_cart_coords(comm, rank, maxdims, coords, ierr);
}
extern void mpi_cart_coords__(MPI_Fint* comm, int* rank, int* maxdims, int coords[], MPI_Fint *ierr) {
	f_mpi_cart_coords(comm, rank, maxdims, coords, ierr);
}
int c_MPI_Comm_split_type(MPI_Comm comm, int split_type, int key, MPI_Info info, MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_split_type, (comm, split_type, key, info, newcomm));
	generate_intracomm_id(newcomm);
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	MPI_Info obj_1 = info;
	int obj_id_1 = MPI_OBJ_ID(MPI_Info, &obj_1);
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, newcomm);
	void **args = assemble_args_list(5, &obj_id_0, &split_type, &key, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Comm_split_type(MPI_Comm comm, int split_type, int key, MPI_Info info, MPI_Comm *newcomm) { return c_MPI_Comm_split_type(comm, split_type, key, info, newcomm); }
extern void f_mpi_comm_split_type(MPI_Fint* comm, int* split_type, int* key, MPI_Fint* info, MPI_Fint* newcomm, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Info c_handle_1;
	c_handle_1 = PMPI_Info_f2c(*info);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*newcomm);
	c_MPI_Comm_split_type(c_handle_0, (*split_type), (*key), c_handle_1, &c_handle_2);
	*newcomm = PMPI_Comm_c2f(c_handle_2);
}
extern void MPI_COMM_SPLIT_TYPE(MPI_Fint* comm, int* split_type, int* key, MPI_Fint* info, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_split_type(comm, split_type, key, info, newcomm, ierr);
}
extern void mpi_comm_split_type(MPI_Fint* comm, int* split_type, int* key, MPI_Fint* info, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_split_type(comm, split_type, key, info, newcomm, ierr);
}
extern void mpi_comm_split_type_(MPI_Fint* comm, int* split_type, int* key, MPI_Fint* info, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_split_type(comm, split_type, key, info, newcomm, ierr);
}
extern void mpi_comm_split_type__(MPI_Fint* comm, int* split_type, int* key, MPI_Fint* info, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_split_type(comm, split_type, key, info, newcomm, ierr);
}
int c_MPI_Rsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Rsend, (buf, count, datatype, dest, tag, comm));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int dest_rank = g_mpi_rank - dest;
	if(dest == MPI_ANY_SOURCE) dest_rank = PILGRIM_MPI_ANY_SOURCE;
	if(dest == MPI_PROC_NULL) dest_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(6, &mem_attr_0, &count, &obj_id_0, &dest_rank, &my_tag, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Rsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { return c_MPI_Rsend(buf, count, datatype, dest, tag, comm); }
extern void f_mpi_rsend(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	c_MPI_Rsend(buf, (*count), c_handle_0, (*dest), (*tag), c_handle_1);
}
extern void MPI_RSEND(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_rsend(buf, count, datatype, dest, tag, comm, ierr);
}
extern void mpi_rsend(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_rsend(buf, count, datatype, dest, tag, comm, ierr);
}
extern void mpi_rsend_(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_rsend(buf, count, datatype, dest, tag, comm, ierr);
}
extern void mpi_rsend__(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_rsend(buf, count, datatype, dest, tag, comm, ierr);
}
int c_MPI_File_get_amode(MPI_File fh, int *amode)
{
	PILGRIM_TRACING_1(int, MPI_File_get_amode, (fh, amode));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, amode);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_get_amode(MPI_File fh, int *amode) { return c_MPI_File_get_amode(fh, amode); }
extern void f_mpi_file_get_amode(MPI_Fint* fh, int* amode, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	c_MPI_File_get_amode(c_handle_0, amode);
}
extern void MPI_FILE_GET_AMODE(MPI_Fint* fh, int* amode, MPI_Fint *ierr) {
	f_mpi_file_get_amode(fh, amode, ierr);
}
extern void mpi_file_get_amode(MPI_Fint* fh, int* amode, MPI_Fint *ierr) {
	f_mpi_file_get_amode(fh, amode, ierr);
}
extern void mpi_file_get_amode_(MPI_Fint* fh, int* amode, MPI_Fint *ierr) {
	f_mpi_file_get_amode(fh, amode, ierr);
}
extern void mpi_file_get_amode__(MPI_Fint* fh, int* amode, MPI_Fint *ierr) {
	f_mpi_file_get_amode(fh, amode, ierr);
}
int c_MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Neighbor_allgatherv, (sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(8, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, recvcounts, displs, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(8, sizes, args, comm_size);
}
int MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm) { return c_MPI_Neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm); }
extern void f_mpi_neighbor_allgatherv(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Neighbor_allgatherv(sendbuf, (*sendcount), c_handle_0, recvbuf, recvcounts, displs, c_handle_1, c_handle_2);
}
extern void MPI_NEIGHBOR_ALLGATHERV(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}
extern void mpi_neighbor_allgatherv(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}
extern void mpi_neighbor_allgatherv_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}
extern void mpi_neighbor_allgatherv__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}
int c_MPI_Info_create(MPI_Info *info)
{
	PILGRIM_TRACING_1(int, MPI_Info_create, (info));
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, info);
	void **args = assemble_args_list(1, &obj_id_0);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Info_create(MPI_Info *info) { return c_MPI_Info_create(info); }
extern void f_mpi_info_create(MPI_Fint* info, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	c_MPI_Info_create(&c_handle_0);
	*info = PMPI_Info_c2f(c_handle_0);
}
extern void MPI_INFO_CREATE(MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_info_create(info, ierr);
}
extern void mpi_info_create(MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_info_create(info, ierr);
}
extern void mpi_info_create_(MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_info_create(info, ierr);
}
extern void mpi_info_create__(MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_info_create(info, ierr);
}
int c_MPI_Type_create_f90_complex(int p, int r, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_f90_complex, (p, r, newtype));
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, newtype);
	void **args = assemble_args_list(3, &p, &r, &obj_id_0);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Type_create_f90_complex(int p, int r, MPI_Datatype *newtype) { return c_MPI_Type_create_f90_complex(p, r, newtype); }
extern void f_mpi_type_create_f90_complex(int* p, int* r, MPI_Fint* newtype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*newtype);
	c_MPI_Type_create_f90_complex((*p), (*r), &c_handle_0);
	*newtype = PMPI_Type_c2f(c_handle_0);
}
extern void MPI_TYPE_CREATE_F90_COMPLEX(int* p, int* r, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_f90_complex(p, r, newtype, ierr);
}
extern void mpi_type_create_f90_complex(int* p, int* r, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_f90_complex(p, r, newtype, ierr);
}
extern void mpi_type_create_f90_complex_(int* p, int* r, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_f90_complex(p, r, newtype, ierr);
}
extern void mpi_type_create_f90_complex__(int* p, int* r, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_f90_complex(p, r, newtype, ierr);
}
int c_MPI_Status_set_elements_x(MPI_Status *status, MPI_Datatype datatype, MPI_Count count)
{
	PILGRIM_TRACING_1(int, MPI_Status_set_elements_x, (status, datatype, count));
	int status_arg[2] = {0};
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	void **args = assemble_args_list(3, status_arg, &obj_id_0, &count);
	int sizes[] = { sizeof(int)*2, sizeof(int), sizeof(MPI_Count) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Status_set_elements_x(MPI_Status *status, MPI_Datatype datatype, MPI_Count count) { return c_MPI_Status_set_elements_x(status, datatype, count); }
extern void f_mpi_status_set_elements_x(MPI_Fint* status, MPI_Fint* datatype, MPI_Count count, MPI_Fint *ierr) {
	MPI_Status c_handle_0;
	PMPI_Status_f2c(status, &c_handle_0);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	c_MPI_Status_set_elements_x(&c_handle_0, c_handle_1, count);
	PMPI_Status_c2f(&c_handle_0, status);
}
extern void MPI_STATUS_SET_ELEMENTS_X(MPI_Fint* status, MPI_Fint* datatype, MPI_Count count, MPI_Fint *ierr) {
	f_mpi_status_set_elements_x(status, datatype, count, ierr);
}
extern void mpi_status_set_elements_x(MPI_Fint* status, MPI_Fint* datatype, MPI_Count count, MPI_Fint *ierr) {
	f_mpi_status_set_elements_x(status, datatype, count, ierr);
}
extern void mpi_status_set_elements_x_(MPI_Fint* status, MPI_Fint* datatype, MPI_Count count, MPI_Fint *ierr) {
	f_mpi_status_set_elements_x(status, datatype, count, ierr);
}
extern void mpi_status_set_elements_x__(MPI_Fint* status, MPI_Fint* datatype, MPI_Count count, MPI_Fint *ierr) {
	f_mpi_status_set_elements_x(status, datatype, count, ierr);
}
int c_MPI_Comm_set_name(MPI_Comm comm, const char *comm_name)
{
	PILGRIM_TRACING_1(int, MPI_Comm_set_name, (comm, comm_name));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, comm_name);
	int sizes[] = { sizeof(int), strlen(comm_name)+1 };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_set_name(MPI_Comm comm, const char *comm_name) { return c_MPI_Comm_set_name(comm, comm_name); }
extern void f_mpi_comm_set_name(MPI_Fint* comm, const char* comm_name, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Comm_set_name(c_handle_0, comm_name);
	*comm = PMPI_Comm_c2f(c_handle_0);
}
extern void MPI_COMM_SET_NAME(MPI_Fint* comm, const char* comm_name, MPI_Fint *ierr) {
	f_mpi_comm_set_name(comm, comm_name, ierr);
}
extern void mpi_comm_set_name(MPI_Fint* comm, const char* comm_name, MPI_Fint *ierr) {
	f_mpi_comm_set_name(comm, comm_name, ierr);
}
extern void mpi_comm_set_name_(MPI_Fint* comm, const char* comm_name, MPI_Fint *ierr) {
	f_mpi_comm_set_name(comm, comm_name, ierr);
}
extern void mpi_comm_set_name__(MPI_Fint* comm, const char* comm_name, MPI_Fint *ierr) {
	f_mpi_comm_set_name(comm, comm_name, ierr);
}
int c_MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group)
{
	PILGRIM_TRACING_1(int, MPI_Comm_remote_group, (comm, group));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Group, group);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group) { return c_MPI_Comm_remote_group(comm, group); }
extern void f_mpi_comm_remote_group(MPI_Fint* comm, MPI_Fint* group, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Group c_handle_1;
	c_handle_1 = PMPI_Group_f2c(*group);
	c_MPI_Comm_remote_group(c_handle_0, &c_handle_1);
	*group = PMPI_Group_c2f(c_handle_1);
}
extern void MPI_COMM_REMOTE_GROUP(MPI_Fint* comm, MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_comm_remote_group(comm, group, ierr);
}
extern void mpi_comm_remote_group(MPI_Fint* comm, MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_comm_remote_group(comm, group, ierr);
}
extern void mpi_comm_remote_group_(MPI_Fint* comm, MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_comm_remote_group(comm, group, ierr);
}
extern void mpi_comm_remote_group__(MPI_Fint* comm, MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_comm_remote_group(comm, group, ierr);
}
int c_MPI_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest)
{
	PILGRIM_TRACING_1(int, MPI_Cart_shift, (comm, direction, disp, rank_source, rank_dest));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(5, &obj_id_0, &direction, &disp, rank_source, rank_dest);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), 1*sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest) { return c_MPI_Cart_shift(comm, direction, disp, rank_source, rank_dest); }
extern void f_mpi_cart_shift(MPI_Fint* comm, int* direction, int* disp, int* rank_source, int* rank_dest, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Cart_shift(c_handle_0, (*direction), (*disp), rank_source, rank_dest);
}
extern void MPI_CART_SHIFT(MPI_Fint* comm, int* direction, int* disp, int* rank_source, int* rank_dest, MPI_Fint *ierr) {
	f_mpi_cart_shift(comm, direction, disp, rank_source, rank_dest, ierr);
}
extern void mpi_cart_shift(MPI_Fint* comm, int* direction, int* disp, int* rank_source, int* rank_dest, MPI_Fint *ierr) {
	f_mpi_cart_shift(comm, direction, disp, rank_source, rank_dest, ierr);
}
extern void mpi_cart_shift_(MPI_Fint* comm, int* direction, int* disp, int* rank_source, int* rank_dest, MPI_Fint *ierr) {
	f_mpi_cart_shift(comm, direction, disp, rank_source, rank_dest, ierr);
}
extern void mpi_cart_shift__(MPI_Fint* comm, int* direction, int* disp, int* rank_source, int* rank_dest, MPI_Fint *ierr) {
	f_mpi_cart_shift(comm, direction, disp, rank_source, rank_dest, ierr);
}
int c_MPI_Comm_size(MPI_Comm comm, int *size)
{
	PILGRIM_TRACING_1(int, MPI_Comm_size, (comm, size));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, size);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_size(MPI_Comm comm, int *size) { return c_MPI_Comm_size(comm, size); }
extern void f_mpi_comm_size(MPI_Fint* comm, int* size, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Comm_size(c_handle_0, size);
}
extern void MPI_COMM_SIZE(MPI_Fint* comm, int* size, MPI_Fint *ierr) {
	f_mpi_comm_size(comm, size, ierr);
}
extern void mpi_comm_size(MPI_Fint* comm, int* size, MPI_Fint *ierr) {
	f_mpi_comm_size(comm, size, ierr);
}
extern void mpi_comm_size_(MPI_Fint* comm, int* size, MPI_Fint *ierr) {
	f_mpi_comm_size(comm, size, ierr);
}
extern void mpi_comm_size__(MPI_Fint* comm, int* size, MPI_Fint *ierr) {
	f_mpi_comm_size(comm, size, ierr);
}
int c_MPI_T_pvar_get_num(int *num_pvar)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_get_num, (num_pvar));
	void **args = assemble_args_list(1, num_pvar);
	int sizes[] = { 1*sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_T_pvar_get_num(int *num_pvar) { return c_MPI_T_pvar_get_num(num_pvar); }
int c_MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read_all_end, (fh, buf, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	int status_arg[2] = {0};
	void **args = assemble_args_list(3, &obj_id_0, &mem_attr_0, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int)*2 };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status) { return c_MPI_File_read_all_end(fh, buf, status); }
extern void f_mpi_file_read_all_end(MPI_Fint* fh, void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Status c_handle_1;
	PMPI_Status_f2c(status, &c_handle_1);
	c_MPI_File_read_all_end(c_handle_0, buf, &c_handle_1);
	*fh = PMPI_File_c2f(c_handle_0);
	PMPI_Status_c2f(&c_handle_1, status);
}
extern void MPI_FILE_READ_ALL_END(MPI_Fint* fh, void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_all_end(fh, buf, status, ierr);
}
extern void mpi_file_read_all_end(MPI_Fint* fh, void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_all_end(fh, buf, status, ierr);
}
extern void mpi_file_read_all_end_(MPI_Fint* fh, void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_all_end(fh, buf, status, ierr);
}
extern void mpi_file_read_all_end__(MPI_Fint* fh, void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_all_end(fh, buf, status, ierr);
}
int c_MPI_Irsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Irsend, (buf, count, datatype, dest, tag, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int dest_rank = g_mpi_rank - dest;
	if(dest == MPI_ANY_SOURCE) dest_rank = PILGRIM_MPI_ANY_SOURCE;
	if(dest == MPI_PROC_NULL) dest_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(6, &mem_attr_0, &count, &obj_id_0, &dest_rank, &my_tag, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Irsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return c_MPI_Irsend(buf, count, datatype, dest, tag, comm, request); }
extern void f_mpi_irsend(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_Irsend(buf, (*count), c_handle_0, (*dest), (*tag), c_handle_1, &c_handle_2);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_IRSEND(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_irsend(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_irsend(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_irsend(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_irsend_(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_irsend(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_irsend__(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_irsend(buf, count, datatype, dest, tag, comm, request, ierr);
}
int c_MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result)
{
	PILGRIM_TRACING_1(int, MPI_Comm_compare, (comm1, comm2, result));
	MPI_Comm obj_0 = comm1;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	MPI_Comm obj_1 = comm2;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(3, &obj_id_0, &obj_id_1, result);
	int sizes[] = { sizeof(int), sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result) { return c_MPI_Comm_compare(comm1, comm2, result); }
extern void f_mpi_comm_compare(MPI_Fint* comm1, MPI_Fint* comm2, int* result, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm1);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm2);
	c_MPI_Comm_compare(c_handle_0, c_handle_1, result);
}
extern void MPI_COMM_COMPARE(MPI_Fint* comm1, MPI_Fint* comm2, int* result, MPI_Fint *ierr) {
	f_mpi_comm_compare(comm1, comm2, result, ierr);
}
extern void mpi_comm_compare(MPI_Fint* comm1, MPI_Fint* comm2, int* result, MPI_Fint *ierr) {
	f_mpi_comm_compare(comm1, comm2, result, ierr);
}
extern void mpi_comm_compare_(MPI_Fint* comm1, MPI_Fint* comm2, int* result, MPI_Fint *ierr) {
	f_mpi_comm_compare(comm1, comm2, result, ierr);
}
extern void mpi_comm_compare__(MPI_Fint* comm1, MPI_Fint* comm2, int* result, MPI_Fint *ierr) {
	f_mpi_comm_compare(comm1, comm2, result, ierr);
}
int c_MPI_Ineighbor_alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ineighbor_alltoall, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(7, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, &recvcount, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Ineighbor_alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return c_MPI_Ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request); }
extern void f_mpi_ineighbor_alltoall(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Ineighbor_alltoall(sendbuf, (*sendcount), c_handle_0, recvbuf, (*recvcount), c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_INEIGHBOR_ALLTOALL(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}
extern void mpi_ineighbor_alltoall(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}
extern void mpi_ineighbor_alltoall_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}
extern void mpi_ineighbor_alltoall__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}
int c_MPI_Query_thread(int *provided)
{
	PILGRIM_TRACING_1(int, MPI_Query_thread, (provided));
	void **args = assemble_args_list(1, provided);
	int sizes[] = { 1*sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Query_thread(int *provided) { return c_MPI_Query_thread(provided); }
extern void f_mpi_query_thread(int* provided, MPI_Fint *ierr) {
	c_MPI_Query_thread(provided);
}
extern void MPI_QUERY_THREAD(int* provided, MPI_Fint *ierr) {
	f_mpi_query_thread(provided, ierr);
}
extern void mpi_query_thread(int* provided, MPI_Fint *ierr) {
	f_mpi_query_thread(provided, ierr);
}
extern void mpi_query_thread_(int* provided, MPI_Fint *ierr) {
	f_mpi_query_thread(provided, ierr);
}
extern void mpi_query_thread__(int* provided, MPI_Fint *ierr) {
	f_mpi_query_thread(provided, ierr);
}
int c_MPI_T_cvar_get_index(const char *name, int *cvar_index)
{
	PILGRIM_TRACING_1(int, MPI_T_cvar_get_index, (name, cvar_index));
	void **args = assemble_args_list(2, name, cvar_index);
	int sizes[] = { strlen(name)+1, 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_T_cvar_get_index(const char *name, int *cvar_index) { return c_MPI_T_cvar_get_index(name, cvar_index); }
int c_MPI_Allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Allgatherv, (sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(8, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, recvcounts, displs, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(8, sizes, args, comm_size);
}
int MPI_Allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm) { return c_MPI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm); }
extern void f_mpi_allgatherv(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Allgatherv(sendbuf, (*sendcount), c_handle_0, recvbuf, recvcounts, displs, c_handle_1, c_handle_2);
}
extern void MPI_ALLGATHERV(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}
extern void mpi_allgatherv(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}
extern void mpi_allgatherv_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}
extern void mpi_allgatherv__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}
int c_MPI_Neighbor_allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Neighbor_allgather, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(7, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, &recvcount, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Neighbor_allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { return c_MPI_Neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm); }
extern void f_mpi_neighbor_allgather(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Neighbor_allgather(sendbuf, (*sendcount), c_handle_0, recvbuf, (*recvcount), c_handle_1, c_handle_2);
}
extern void MPI_NEIGHBOR_ALLGATHER(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}
extern void mpi_neighbor_allgather(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}
extern void mpi_neighbor_allgather_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}
extern void mpi_neighbor_allgather__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}
int c_MPI_T_category_get_pvars(int cat_index, int len, int indices[])
{
	PILGRIM_TRACING_1(int, MPI_T_category_get_pvars, (cat_index, len, indices));
	void **args = assemble_args_list(3, &cat_index, &len, indices);
	int sizes[] = { sizeof(int), sizeof(int), len*sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_T_category_get_pvars(int cat_index, int len, int indices[]) { return c_MPI_T_category_get_pvars(cat_index, len, indices); }
int c_MPI_Comm_free_keyval(int *comm_keyval)
{
	PILGRIM_TRACING_1(int, MPI_Comm_free_keyval, (comm_keyval));
	void **args = assemble_args_list(1, comm_keyval);
	int sizes[] = { 1*sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Comm_free_keyval(int *comm_keyval) { return c_MPI_Comm_free_keyval(comm_keyval); }
extern void f_mpi_comm_free_keyval(int* comm_keyval, MPI_Fint *ierr) {
	c_MPI_Comm_free_keyval(comm_keyval);
}
extern void MPI_COMM_FREE_KEYVAL(int* comm_keyval, MPI_Fint *ierr) {
	f_mpi_comm_free_keyval(comm_keyval, ierr);
}
extern void mpi_comm_free_keyval(int* comm_keyval, MPI_Fint *ierr) {
	f_mpi_comm_free_keyval(comm_keyval, ierr);
}
extern void mpi_comm_free_keyval_(int* comm_keyval, MPI_Fint *ierr) {
	f_mpi_comm_free_keyval(comm_keyval, ierr);
}
extern void mpi_comm_free_keyval__(int* comm_keyval, MPI_Fint *ierr) {
	f_mpi_comm_free_keyval(comm_keyval, ierr);
}
int c_MPI_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op)
{
	PILGRIM_TRACING_1(int, MPI_Op_create, (user_fn, commute, op));
	int obj_id_0 = MPI_OBJ_ID(MPI_Op, op);
	void **args = assemble_args_list(3, user_fn, &commute, &obj_id_0);
	int sizes[] = { 1*sizeof(MPI_User_function), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op) { return c_MPI_Op_create(user_fn, commute, op); }
extern void f_mpi_op_create(MPI_User_function* user_fn, int* commute, MPI_Fint* op, MPI_Fint *ierr) {
	MPI_Op c_handle_0;
	c_handle_0 = PMPI_Op_f2c(*op);
	c_MPI_Op_create(user_fn, (*commute), &c_handle_0);
	*op = PMPI_Op_c2f(c_handle_0);
}
extern void MPI_OP_CREATE(MPI_User_function* user_fn, int* commute, MPI_Fint* op, MPI_Fint *ierr) {
	f_mpi_op_create(user_fn, commute, op, ierr);
}
extern void mpi_op_create(MPI_User_function* user_fn, int* commute, MPI_Fint* op, MPI_Fint *ierr) {
	f_mpi_op_create(user_fn, commute, op, ierr);
}
extern void mpi_op_create_(MPI_User_function* user_fn, int* commute, MPI_Fint* op, MPI_Fint *ierr) {
	f_mpi_op_create(user_fn, commute, op, ierr);
}
extern void mpi_op_create__(MPI_User_function* user_fn, int* commute, MPI_Fint* op, MPI_Fint *ierr) {
	f_mpi_op_create(user_fn, commute, op, ierr);
}
int c_MPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name, int *name_len)
{
	PILGRIM_TRACING_1(int, MPI_T_enum_get_info, (enumtype, num, name, name_len));
	void **args = assemble_args_list(4, &enumtype, num, name, name_len);
	int sizes[] = { sizeof(MPI_T_enum), 1*sizeof(int), strlen(name)+1, 1*sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name, int *name_len) { return c_MPI_T_enum_get_info(enumtype, num, name, name_len); }
int c_MPI_Ssend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ssend_init, (buf, count, datatype, dest, tag, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int dest_rank = g_mpi_rank - dest;
	if(dest == MPI_ANY_SOURCE) dest_rank = PILGRIM_MPI_ANY_SOURCE;
	if(dest == MPI_PROC_NULL) dest_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(6, &mem_attr_0, &count, &obj_id_0, &dest_rank, &my_tag, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Ssend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return c_MPI_Ssend_init(buf, count, datatype, dest, tag, comm, request); }
extern void f_mpi_ssend_init(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_Ssend_init(buf, (*count), c_handle_0, (*dest), (*tag), c_handle_1, &c_handle_2);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_SSEND_INIT(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ssend_init(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_ssend_init(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ssend_init(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_ssend_init_(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ssend_init(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_ssend_init__(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ssend_init(buf, count, datatype, dest, tag, comm, request, ierr);
}
int c_MPI_Rsend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Rsend_init, (buf, count, datatype, dest, tag, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int dest_rank = g_mpi_rank - dest;
	if(dest == MPI_ANY_SOURCE) dest_rank = PILGRIM_MPI_ANY_SOURCE;
	if(dest == MPI_PROC_NULL) dest_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(6, &mem_attr_0, &count, &obj_id_0, &dest_rank, &my_tag, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Rsend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return c_MPI_Rsend_init(buf, count, datatype, dest, tag, comm, request); }
extern void f_mpi_rsend_init(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_Rsend_init(buf, (*count), c_handle_0, (*dest), (*tag), c_handle_1, &c_handle_2);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_RSEND_INIT(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_rsend_init(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_rsend_init(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_rsend_init(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_rsend_init_(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_rsend_init(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_rsend_init__(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_rsend_init(buf, count, datatype, dest, tag, comm, request, ierr);
}
int c_MPI_Igatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Igatherv, (sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(9, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, recvcounts, displs, &obj_id_1, &root, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args, comm_size);
}
int MPI_Igatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { return c_MPI_Igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request); }
extern void f_mpi_igatherv(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Igatherv(sendbuf, (*sendcount), c_handle_0, recvbuf, recvcounts, displs, c_handle_1, (*root), c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_IGATHERV(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request, ierr);
}
extern void mpi_igatherv(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request, ierr);
}
extern void mpi_igatherv_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request, ierr);
}
extern void mpi_igatherv__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request, ierr);
}
int c_MPI_Mrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Status *status)
{
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Message, message);
	int status_arg[2] = {0};
	void **args = assemble_args_list(5, &mem_attr_0, &count, &obj_id_0, &obj_id_1, status_arg);
	MPI_OBJ_RELEASE(MPI_Message, message);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_1(int, MPI_Mrecv, (buf, count, datatype, message, status));
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Mrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Status *status) { return c_MPI_Mrecv(buf, count, datatype, message, status); }
extern void f_mpi_mrecv(void* buf, int* count, MPI_Fint* datatype, MPI_Fint* message, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Message c_handle_1;
	c_handle_1 = PMPI_Message_f2c(*message);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_Mrecv(buf, (*count), c_handle_0, &c_handle_1, &c_handle_2);
	*message = PMPI_Message_c2f(c_handle_1);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_MRECV(void* buf, int* count, MPI_Fint* datatype, MPI_Fint* message, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_mrecv(buf, count, datatype, message, status, ierr);
}
extern void mpi_mrecv(void* buf, int* count, MPI_Fint* datatype, MPI_Fint* message, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_mrecv(buf, count, datatype, message, status, ierr);
}
extern void mpi_mrecv_(void* buf, int* count, MPI_Fint* datatype, MPI_Fint* message, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_mrecv(buf, count, datatype, message, status, ierr);
}
extern void mpi_mrecv__(void* buf, int* count, MPI_Fint* datatype, MPI_Fint* message, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_mrecv(buf, count, datatype, message, status, ierr);
}
int c_MPI_Group_excl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup)
{
	PILGRIM_TRACING_1(int, MPI_Group_excl, (group, n, ranks, newgroup));
	MPI_Group obj_0 = group;
	int obj_id_0 = MPI_OBJ_ID(MPI_Group, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Group, newgroup);
	void **args = assemble_args_list(4, &obj_id_0, &n, ranks, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), n*sizeof(const int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Group_excl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup) { return c_MPI_Group_excl(group, n, ranks, newgroup); }
extern void f_mpi_group_excl(MPI_Fint* group, int* n, const int ranks[], MPI_Fint* newgroup, MPI_Fint *ierr) {
	MPI_Group c_handle_0;
	c_handle_0 = PMPI_Group_f2c(*group);
	MPI_Group c_handle_1;
	c_handle_1 = PMPI_Group_f2c(*newgroup);
	c_MPI_Group_excl(c_handle_0, (*n), ranks, &c_handle_1);
	*newgroup = PMPI_Group_c2f(c_handle_1);
}
extern void MPI_GROUP_EXCL(MPI_Fint* group, int* n, const int ranks[], MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_excl(group, n, ranks, newgroup, ierr);
}
extern void mpi_group_excl(MPI_Fint* group, int* n, const int ranks[], MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_excl(group, n, ranks, newgroup, ierr);
}
extern void mpi_group_excl_(MPI_Fint* group, int* n, const int ranks[], MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_excl(group, n, ranks, newgroup, ierr);
}
extern void mpi_group_excl__(MPI_Fint* group, int* n, const int ranks[], MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_excl(group, n, ranks, newgroup, ierr);
}
int c_MPI_Comm_test_inter(MPI_Comm comm, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Comm_test_inter, (comm, flag));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, flag);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_test_inter(MPI_Comm comm, int *flag) { return c_MPI_Comm_test_inter(comm, flag); }
extern void f_mpi_comm_test_inter(MPI_Fint* comm, int* flag, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Comm_test_inter(c_handle_0, flag);
}
extern void MPI_COMM_TEST_INTER(MPI_Fint* comm, int* flag, MPI_Fint *ierr) {
	f_mpi_comm_test_inter(comm, flag, ierr);
}
extern void mpi_comm_test_inter(MPI_Fint* comm, int* flag, MPI_Fint *ierr) {
	f_mpi_comm_test_inter(comm, flag, ierr);
}
extern void mpi_comm_test_inter_(MPI_Fint* comm, int* flag, MPI_Fint *ierr) {
	f_mpi_comm_test_inter(comm, flag, ierr);
}
extern void mpi_comm_test_inter__(MPI_Fint* comm, int* flag, MPI_Fint *ierr) {
	f_mpi_comm_test_inter(comm, flag, ierr);
}
int c_MPI_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype)
{
	PILGRIM_TRACING_1(int, MPI_File_read_all_begin, (fh, buf, count, datatype));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(4, &obj_id_0, &mem_attr_0, &count, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype) { return c_MPI_File_read_all_begin(fh, buf, count, datatype); }
extern void f_mpi_file_read_all_begin(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	c_MPI_File_read_all_begin(c_handle_0, buf, (*count), c_handle_1);
	*fh = PMPI_File_c2f(c_handle_0);
}
extern void MPI_FILE_READ_ALL_BEGIN(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_read_all_begin(fh, buf, count, datatype, ierr);
}
extern void mpi_file_read_all_begin(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_read_all_begin(fh, buf, count, datatype, ierr);
}
extern void mpi_file_read_all_begin_(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_read_all_begin(fh, buf, count, datatype, ierr);
}
extern void mpi_file_read_all_begin__(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_read_all_begin(fh, buf, count, datatype, ierr);
}
int c_MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size)
{
	PILGRIM_TRACING_1(int, MPI_Win_attach, (win, base, size));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(base, &mem_attr_0);
	void **args = assemble_args_list(3, &obj_id_0, &mem_attr_0, &size);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(MPI_Aint) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size) { return c_MPI_Win_attach(win, base, size); }
extern void f_mpi_win_attach(MPI_Fint* win, void* base, MPI_Aint size, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_attach(c_handle_0, base, size);
}
extern void MPI_WIN_ATTACH(MPI_Fint* win, void* base, MPI_Aint size, MPI_Fint *ierr) {
	f_mpi_win_attach(win, base, size, ierr);
}
extern void mpi_win_attach(MPI_Fint* win, void* base, MPI_Aint size, MPI_Fint *ierr) {
	f_mpi_win_attach(win, base, size, ierr);
}
extern void mpi_win_attach_(MPI_Fint* win, void* base, MPI_Aint size, MPI_Fint *ierr) {
	f_mpi_win_attach(win, base, size, ierr);
}
extern void mpi_win_attach__(MPI_Fint* win, void* base, MPI_Aint size, MPI_Fint *ierr) {
	f_mpi_win_attach(win, base, size, ierr);
}
int c_MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read_at_all, (fh, offset, buf, count, datatype, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	append_offset(offset);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	int status_arg[2] = {0};
	void **args = assemble_args_list(5, &obj_id_0, &mem_attr_0, &count, &obj_id_1, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return c_MPI_File_read_at_all(fh, offset, buf, count, datatype, status); }
extern void f_mpi_file_read_at_all(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_File_read_at_all(c_handle_0, offset, buf, (*count), c_handle_1, &c_handle_2);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_FILE_READ_AT_ALL(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_at_all(fh, offset, buf, count, datatype, status, ierr);
}
extern void mpi_file_read_at_all(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_at_all(fh, offset, buf, count, datatype, status, ierr);
}
extern void mpi_file_read_at_all_(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_at_all(fh, offset, buf, count, datatype, status, ierr);
}
extern void mpi_file_read_at_all__(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_at_all(fh, offset, buf, count, datatype, status, ierr);
}
int c_MPI_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read_ordered_end, (fh, buf, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	int status_arg[2] = {0};
	void **args = assemble_args_list(3, &obj_id_0, &mem_attr_0, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int)*2 };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status) { return c_MPI_File_read_ordered_end(fh, buf, status); }
extern void f_mpi_file_read_ordered_end(MPI_Fint* fh, void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Status c_handle_1;
	PMPI_Status_f2c(status, &c_handle_1);
	c_MPI_File_read_ordered_end(c_handle_0, buf, &c_handle_1);
	*fh = PMPI_File_c2f(c_handle_0);
	PMPI_Status_c2f(&c_handle_1, status);
}
extern void MPI_FILE_READ_ORDERED_END(MPI_Fint* fh, void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_ordered_end(fh, buf, status, ierr);
}
extern void mpi_file_read_ordered_end(MPI_Fint* fh, void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_ordered_end(fh, buf, status, ierr);
}
extern void mpi_file_read_ordered_end_(MPI_Fint* fh, void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_ordered_end(fh, buf, status, ierr);
}
extern void mpi_file_read_ordered_end__(MPI_Fint* fh, void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_ordered_end(fh, buf, status, ierr);
}
int c_MPI_Type_set_attr(MPI_Datatype datatype, int type_keyval, void *attribute_val)
{
	PILGRIM_TRACING_1(int, MPI_Type_set_attr, (datatype, type_keyval, attribute_val));
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(attribute_val, &mem_attr_0);
	void **args = assemble_args_list(3, &obj_id_0, &type_keyval, &mem_attr_0);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Type_set_attr(MPI_Datatype datatype, int type_keyval, void *attribute_val) { return c_MPI_Type_set_attr(datatype, type_keyval, attribute_val); }
extern void f_mpi_type_set_attr(MPI_Fint* datatype, int* type_keyval, void* attribute_val, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Type_set_attr(c_handle_0, (*type_keyval), attribute_val);
	*datatype = PMPI_Type_c2f(c_handle_0);
}
extern void MPI_TYPE_SET_ATTR(MPI_Fint* datatype, int* type_keyval, void* attribute_val, MPI_Fint *ierr) {
	f_mpi_type_set_attr(datatype, type_keyval, attribute_val, ierr);
}
extern void mpi_type_set_attr(MPI_Fint* datatype, int* type_keyval, void* attribute_val, MPI_Fint *ierr) {
	f_mpi_type_set_attr(datatype, type_keyval, attribute_val, ierr);
}
extern void mpi_type_set_attr_(MPI_Fint* datatype, int* type_keyval, void* attribute_val, MPI_Fint *ierr) {
	f_mpi_type_set_attr(datatype, type_keyval, attribute_val, ierr);
}
extern void mpi_type_set_attr__(MPI_Fint* datatype, int* type_keyval, void* attribute_val, MPI_Fint *ierr) {
	f_mpi_type_set_attr(datatype, type_keyval, attribute_val, ierr);
}
int c_MPI_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup)
{
	PILGRIM_TRACING_1(int, MPI_Group_union, (group1, group2, newgroup));
	MPI_Group obj_0 = group1;
	int obj_id_0 = MPI_OBJ_ID(MPI_Group, &obj_0);
	MPI_Group obj_1 = group2;
	int obj_id_1 = MPI_OBJ_ID(MPI_Group, &obj_1);
	int obj_id_2 = MPI_OBJ_ID(MPI_Group, newgroup);
	void **args = assemble_args_list(3, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup) { return c_MPI_Group_union(group1, group2, newgroup); }
extern void f_mpi_group_union(MPI_Fint* group1, MPI_Fint* group2, MPI_Fint* newgroup, MPI_Fint *ierr) {
	MPI_Group c_handle_0;
	c_handle_0 = PMPI_Group_f2c(*group1);
	MPI_Group c_handle_1;
	c_handle_1 = PMPI_Group_f2c(*group2);
	MPI_Group c_handle_2;
	c_handle_2 = PMPI_Group_f2c(*newgroup);
	c_MPI_Group_union(c_handle_0, c_handle_1, &c_handle_2);
	*newgroup = PMPI_Group_c2f(c_handle_2);
}
extern void MPI_GROUP_UNION(MPI_Fint* group1, MPI_Fint* group2, MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_union(group1, group2, newgroup, ierr);
}
extern void mpi_group_union(MPI_Fint* group1, MPI_Fint* group2, MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_union(group1, group2, newgroup, ierr);
}
extern void mpi_group_union_(MPI_Fint* group1, MPI_Fint* group2, MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_union(group1, group2, newgroup, ierr);
}
extern void mpi_group_union__(MPI_Fint* group1, MPI_Fint* group2, MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_union(group1, group2, newgroup, ierr);
}
int c_MPI_Type_get_contents(MPI_Datatype datatype, int max_integers, int max_addresses, int max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Datatype array_of_datatypes[])
{
	PILGRIM_TRACING_1(int, MPI_Type_get_contents, (datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes));
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int obj_id_1[max_datatypes];
	for(int i=0; i<max_datatypes; i++) obj_id_1[i] = (array_of_datatypes==NULL) ? PILGRIM_INVALID_MPI_OBJECT_ID: MPI_OBJ_ID(MPI_Datatype, &array_of_datatypes[i]);
	void **args = assemble_args_list(7, &obj_id_0, &max_integers, &max_addresses, &max_datatypes, array_of_integers, array_of_addresses, obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(int), max_integers*sizeof(int), max_addresses*sizeof(MPI_Aint), max_datatypes*sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Type_get_contents(MPI_Datatype datatype, int max_integers, int max_addresses, int max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Datatype array_of_datatypes[]) { return c_MPI_Type_get_contents(datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes); }
extern void f_mpi_type_get_contents(MPI_Fint* datatype, int* max_integers, int* max_addresses, int* max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Fint* array_of_datatypes, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Datatype c_handle_1[*max_datatypes];
	for(int i = 0; i < *max_datatypes; i++) c_handle_1[i] = PMPI_Type_f2c(array_of_datatypes[i]);
	c_MPI_Type_get_contents(c_handle_0, (*max_integers), (*max_addresses), (*max_datatypes), array_of_integers, array_of_addresses, c_handle_1);
	for(int i = 0; i < *max_datatypes; i++) array_of_datatypes[i] = PMPI_Type_c2f(c_handle_1[i]);
}
extern void MPI_TYPE_GET_CONTENTS(MPI_Fint* datatype, int* max_integers, int* max_addresses, int* max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Fint* array_of_datatypes, MPI_Fint *ierr) {
	f_mpi_type_get_contents(datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes, ierr);
}
extern void mpi_type_get_contents(MPI_Fint* datatype, int* max_integers, int* max_addresses, int* max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Fint* array_of_datatypes, MPI_Fint *ierr) {
	f_mpi_type_get_contents(datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes, ierr);
}
extern void mpi_type_get_contents_(MPI_Fint* datatype, int* max_integers, int* max_addresses, int* max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Fint* array_of_datatypes, MPI_Fint *ierr) {
	f_mpi_type_get_contents(datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes, ierr);
}
extern void mpi_type_get_contents__(MPI_Fint* datatype, int* max_integers, int* max_addresses, int* max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Fint* array_of_datatypes, MPI_Fint *ierr) {
	f_mpi_type_get_contents(datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes, ierr);
}
int c_MPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_lock, (lock_type, rank, assert, win));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(4, &lock_type, &rank, &assert, &obj_id_0);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win) { return c_MPI_Win_lock(lock_type, rank, assert, win); }
extern void f_mpi_win_lock(int* lock_type, int* rank, int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_lock((*lock_type), (*rank), (*assert), c_handle_0);
}
extern void MPI_WIN_LOCK(int* lock_type, int* rank, int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_lock(lock_type, rank, assert, win, ierr);
}
extern void mpi_win_lock(int* lock_type, int* rank, int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_lock(lock_type, rank, assert, win, ierr);
}
extern void mpi_win_lock_(int* lock_type, int* rank, int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_lock(lock_type, rank, assert, win, ierr);
}
extern void mpi_win_lock__(int* lock_type, int* rank, int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_lock(lock_type, rank, assert, win, ierr);
}
int c_MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size)
{
	PILGRIM_TRACING_1(int, MPI_Type_size_x, (datatype, size));
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, size);
	int sizes[] = { sizeof(int), 1*sizeof(MPI_Count) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size) { return c_MPI_Type_size_x(datatype, size); }
extern void f_mpi_type_size_x(MPI_Fint* datatype, MPI_Count* size, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Type_size_x(c_handle_0, size);
}
extern void MPI_TYPE_SIZE_X(MPI_Fint* datatype, MPI_Count* size, MPI_Fint *ierr) {
	f_mpi_type_size_x(datatype, size, ierr);
}
extern void mpi_type_size_x(MPI_Fint* datatype, MPI_Count* size, MPI_Fint *ierr) {
	f_mpi_type_size_x(datatype, size, ierr);
}
extern void mpi_type_size_x_(MPI_Fint* datatype, MPI_Count* size, MPI_Fint *ierr) {
	f_mpi_type_size_x(datatype, size, ierr);
}
extern void mpi_type_size_x__(MPI_Fint* datatype, MPI_Count* size, MPI_Fint *ierr) {
	f_mpi_type_size_x(datatype, size, ierr);
}
int c_MPI_T_category_changed(int *stamp)
{
	PILGRIM_TRACING_1(int, MPI_T_category_changed, (stamp));
	void **args = assemble_args_list(1, stamp);
	int sizes[] = { 1*sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_T_category_changed(int *stamp) { return c_MPI_T_category_changed(stamp); }
int c_MPI_Comm_set_info(MPI_Comm comm, MPI_Info info)
{
	PILGRIM_TRACING_1(int, MPI_Comm_set_info, (comm, info));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	MPI_Info obj_1 = info;
	int obj_id_1 = MPI_OBJ_ID(MPI_Info, &obj_1);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_set_info(MPI_Comm comm, MPI_Info info) { return c_MPI_Comm_set_info(comm, info); }
extern void f_mpi_comm_set_info(MPI_Fint* comm, MPI_Fint* info, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Info c_handle_1;
	c_handle_1 = PMPI_Info_f2c(*info);
	c_MPI_Comm_set_info(c_handle_0, c_handle_1);
	*comm = PMPI_Comm_c2f(c_handle_0);
}
extern void MPI_COMM_SET_INFO(MPI_Fint* comm, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_comm_set_info(comm, info, ierr);
}
extern void mpi_comm_set_info(MPI_Fint* comm, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_comm_set_info(comm, info, ierr);
}
extern void mpi_comm_set_info_(MPI_Fint* comm, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_comm_set_info(comm, info, ierr);
}
extern void mpi_comm_set_info__(MPI_Fint* comm, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_comm_set_info(comm, info, ierr);
}
int c_MPI_T_pvar_stop(MPI_T_pvar_session session, MPI_T_pvar_handle handle)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_stop, (session, handle));
	void **args = assemble_args_list(2, &session, &handle);
	int sizes[] = { sizeof(MPI_T_pvar_session), sizeof(MPI_T_pvar_handle) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_T_pvar_stop(MPI_T_pvar_session session, MPI_T_pvar_handle handle) { return c_MPI_T_pvar_stop(session, handle); }
int c_MPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner)
{
	PILGRIM_TRACING_1(int, MPI_Type_get_envelope, (datatype, num_integers, num_addresses, num_datatypes, combiner));
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	void **args = assemble_args_list(5, &obj_id_0, num_integers, num_addresses, num_datatypes, combiner);
	int sizes[] = { sizeof(int), 1*sizeof(int), 1*sizeof(int), 1*sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner) { return c_MPI_Type_get_envelope(datatype, num_integers, num_addresses, num_datatypes, combiner); }
extern void f_mpi_type_get_envelope(MPI_Fint* datatype, int* num_integers, int* num_addresses, int* num_datatypes, int* combiner, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Type_get_envelope(c_handle_0, num_integers, num_addresses, num_datatypes, combiner);
}
extern void MPI_TYPE_GET_ENVELOPE(MPI_Fint* datatype, int* num_integers, int* num_addresses, int* num_datatypes, int* combiner, MPI_Fint *ierr) {
	f_mpi_type_get_envelope(datatype, num_integers, num_addresses, num_datatypes, combiner, ierr);
}
extern void mpi_type_get_envelope(MPI_Fint* datatype, int* num_integers, int* num_addresses, int* num_datatypes, int* combiner, MPI_Fint *ierr) {
	f_mpi_type_get_envelope(datatype, num_integers, num_addresses, num_datatypes, combiner, ierr);
}
extern void mpi_type_get_envelope_(MPI_Fint* datatype, int* num_integers, int* num_addresses, int* num_datatypes, int* combiner, MPI_Fint *ierr) {
	f_mpi_type_get_envelope(datatype, num_integers, num_addresses, num_datatypes, combiner, ierr);
}
extern void mpi_type_get_envelope__(MPI_Fint* datatype, int* num_integers, int* num_addresses, int* num_datatypes, int* combiner, MPI_Fint *ierr) {
	f_mpi_type_get_envelope(datatype, num_integers, num_addresses, num_datatypes, combiner, ierr);
}
int c_MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Send, (buf, count, datatype, dest, tag, comm));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int dest_rank = g_mpi_rank - dest;
	if(dest == MPI_ANY_SOURCE) dest_rank = PILGRIM_MPI_ANY_SOURCE;
	if(dest == MPI_PROC_NULL) dest_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(6, &mem_attr_0, &count, &obj_id_0, &dest_rank, &my_tag, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { return c_MPI_Send(buf, count, datatype, dest, tag, comm); }
extern void f_mpi_send(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	c_MPI_Send(buf, (*count), c_handle_0, (*dest), (*tag), c_handle_1);
}
extern void MPI_SEND(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_send(buf, count, datatype, dest, tag, comm, ierr);
}
extern void mpi_send(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_send(buf, count, datatype, dest, tag, comm, ierr);
}
extern void mpi_send_(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_send(buf, count, datatype, dest, tag, comm, ierr);
}
extern void mpi_send__(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_send(buf, count, datatype, dest, tag, comm, ierr);
}
int c_MPI_Win_delete_attr(MPI_Win win, int win_keyval)
{
	PILGRIM_TRACING_1(int, MPI_Win_delete_attr, (win, win_keyval));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, &win_keyval);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Win_delete_attr(MPI_Win win, int win_keyval) { return c_MPI_Win_delete_attr(win, win_keyval); }
extern void f_mpi_win_delete_attr(MPI_Fint* win, int* win_keyval, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_delete_attr(c_handle_0, (*win_keyval));
	*win = PMPI_Win_c2f(c_handle_0);
}
extern void MPI_WIN_DELETE_ATTR(MPI_Fint* win, int* win_keyval, MPI_Fint *ierr) {
	f_mpi_win_delete_attr(win, win_keyval, ierr);
}
extern void mpi_win_delete_attr(MPI_Fint* win, int* win_keyval, MPI_Fint *ierr) {
	f_mpi_win_delete_attr(win, win_keyval, ierr);
}
extern void mpi_win_delete_attr_(MPI_Fint* win, int* win_keyval, MPI_Fint *ierr) {
	f_mpi_win_delete_attr(win, win_keyval, ierr);
}
extern void mpi_win_delete_attr__(MPI_Fint* win, int* win_keyval, MPI_Fint *ierr) {
	f_mpi_win_delete_attr(win, win_keyval, ierr);
}
int c_MPI_Type_create_hindexed_block(int count, int blocklength, const MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_hindexed_block, (count, blocklength, array_of_displacements, oldtype, newtype));
	MPI_Datatype obj_0 = oldtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, newtype);
	void **args = assemble_args_list(5, &count, &blocklength, array_of_displacements, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), count*sizeof(const MPI_Aint), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Type_create_hindexed_block(int count, int blocklength, const MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { return c_MPI_Type_create_hindexed_block(count, blocklength, array_of_displacements, oldtype, newtype); }
extern void f_mpi_type_create_hindexed_block(int* count, int* blocklength, const MPI_Aint array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*oldtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*newtype);
	c_MPI_Type_create_hindexed_block((*count), (*blocklength), array_of_displacements, c_handle_0, &c_handle_1);
	*newtype = PMPI_Type_c2f(c_handle_1);
}
extern void MPI_TYPE_CREATE_HINDEXED_BLOCK(int* count, int* blocklength, const MPI_Aint array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_hindexed_block(count, blocklength, array_of_displacements, oldtype, newtype, ierr);
}
extern void mpi_type_create_hindexed_block(int* count, int* blocklength, const MPI_Aint array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_hindexed_block(count, blocklength, array_of_displacements, oldtype, newtype, ierr);
}
extern void mpi_type_create_hindexed_block_(int* count, int* blocklength, const MPI_Aint array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_hindexed_block(count, blocklength, array_of_displacements, oldtype, newtype, ierr);
}
extern void mpi_type_create_hindexed_block__(int* count, int* blocklength, const MPI_Aint array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_hindexed_block(count, blocklength, array_of_displacements, oldtype, newtype, ierr);
}
int c_MPI_Keyval_free(int *keyval)
{
	PILGRIM_TRACING_1(int, MPI_Keyval_free, (keyval));
	void **args = assemble_args_list(1, keyval);
	int sizes[] = { 1*sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Keyval_free(int *keyval) { return c_MPI_Keyval_free(keyval); }
extern void f_mpi_keyval_free(int* keyval, MPI_Fint *ierr) {
	c_MPI_Keyval_free(keyval);
}
extern void MPI_KEYVAL_FREE(int* keyval, MPI_Fint *ierr) {
	f_mpi_keyval_free(keyval, ierr);
}
extern void mpi_keyval_free(int* keyval, MPI_Fint *ierr) {
	f_mpi_keyval_free(keyval, ierr);
}
extern void mpi_keyval_free_(int* keyval, MPI_Fint *ierr) {
	f_mpi_keyval_free(keyval, ierr);
}
extern void mpi_keyval_free__(int* keyval, MPI_Fint *ierr) {
	f_mpi_keyval_free(keyval, ierr);
}
int c_MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr)
{
	PILGRIM_TRACING_1(int, MPI_Alloc_mem, (size, info, baseptr));
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(baseptr, &mem_attr_0);
	void **args = assemble_args_list(3, &size, &obj_id_0, &mem_attr_0);
	int sizes[] = { sizeof(MPI_Aint), sizeof(int), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr) { return c_MPI_Alloc_mem(size, info, baseptr); }
extern void f_mpi_alloc_mem(MPI_Aint size, MPI_Fint* info, void* baseptr, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	c_MPI_Alloc_mem(size, c_handle_0, baseptr);
}
extern void MPI_ALLOC_MEM(MPI_Aint size, MPI_Fint* info, void* baseptr, MPI_Fint *ierr) {
	f_mpi_alloc_mem(size, info, baseptr, ierr);
}
extern void mpi_alloc_mem(MPI_Aint size, MPI_Fint* info, void* baseptr, MPI_Fint *ierr) {
	f_mpi_alloc_mem(size, info, baseptr, ierr);
}
extern void mpi_alloc_mem_(MPI_Aint size, MPI_Fint* info, void* baseptr, MPI_Fint *ierr) {
	f_mpi_alloc_mem(size, info, baseptr, ierr);
}
extern void mpi_alloc_mem__(MPI_Aint size, MPI_Fint* info, void* baseptr, MPI_Fint *ierr) {
	f_mpi_alloc_mem(size, info, baseptr, ierr);
}
int c_MPI_File_get_atomicity(MPI_File fh, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_File_get_atomicity, (fh, flag));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, flag);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_get_atomicity(MPI_File fh, int *flag) { return c_MPI_File_get_atomicity(fh, flag); }
extern void f_mpi_file_get_atomicity(MPI_Fint* fh, int* flag, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	c_MPI_File_get_atomicity(c_handle_0, flag);
}
extern void MPI_FILE_GET_ATOMICITY(MPI_Fint* fh, int* flag, MPI_Fint *ierr) {
	f_mpi_file_get_atomicity(fh, flag, ierr);
}
extern void mpi_file_get_atomicity(MPI_Fint* fh, int* flag, MPI_Fint *ierr) {
	f_mpi_file_get_atomicity(fh, flag, ierr);
}
extern void mpi_file_get_atomicity_(MPI_Fint* fh, int* flag, MPI_Fint *ierr) {
	f_mpi_file_get_atomicity(fh, flag, ierr);
}
extern void mpi_file_get_atomicity__(MPI_Fint* fh, int* flag, MPI_Fint *ierr) {
	f_mpi_file_get_atomicity(fh, flag, ierr);
}
int c_MPI_Dist_graph_create(MPI_Comm comm_old, int n, const int sources[], const int degrees[], const int destinations[], const int weights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph)
{
	PILGRIM_TRACING_1(int, MPI_Dist_graph_create, (comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph));
	generate_intracomm_id(comm_dist_graph);
	MPI_Comm obj_0 = comm_old;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	MPI_Info obj_1 = info;
	int obj_id_1 = MPI_OBJ_ID(MPI_Info, &obj_1);
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, comm_dist_graph);
	void **args = assemble_args_list(9, &obj_id_0, &n, sources, degrees, destinations, weights, &obj_id_1, &reorder, &obj_id_2);
	int sizes[] = { sizeof(int), sizeof(int), n*sizeof(const int), n*sizeof(const int), 1*sizeof(const int), 1*sizeof(const int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args, -1);
}
int MPI_Dist_graph_create(MPI_Comm comm_old, int n, const int sources[], const int degrees[], const int destinations[], const int weights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph) { return c_MPI_Dist_graph_create(comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph); }
extern void f_mpi_dist_graph_create(MPI_Fint* comm_old, int* n, const int sources[], const int degrees[], const int destinations[], const int weights[], MPI_Fint* info, int* reorder, MPI_Fint* comm_dist_graph, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm_old);
	MPI_Info c_handle_1;
	c_handle_1 = PMPI_Info_f2c(*info);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm_dist_graph);
	c_MPI_Dist_graph_create(c_handle_0, (*n), sources, degrees, destinations, weights, c_handle_1, (*reorder), &c_handle_2);
	*comm_dist_graph = PMPI_Comm_c2f(c_handle_2);
}
extern void MPI_DIST_GRAPH_CREATE(MPI_Fint* comm_old, int* n, const int sources[], const int degrees[], const int destinations[], const int weights[], MPI_Fint* info, int* reorder, MPI_Fint* comm_dist_graph, MPI_Fint *ierr) {
	f_mpi_dist_graph_create(comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph, ierr);
}
extern void mpi_dist_graph_create(MPI_Fint* comm_old, int* n, const int sources[], const int degrees[], const int destinations[], const int weights[], MPI_Fint* info, int* reorder, MPI_Fint* comm_dist_graph, MPI_Fint *ierr) {
	f_mpi_dist_graph_create(comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph, ierr);
}
extern void mpi_dist_graph_create_(MPI_Fint* comm_old, int* n, const int sources[], const int degrees[], const int destinations[], const int weights[], MPI_Fint* info, int* reorder, MPI_Fint* comm_dist_graph, MPI_Fint *ierr) {
	f_mpi_dist_graph_create(comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph, ierr);
}
extern void mpi_dist_graph_create__(MPI_Fint* comm_old, int* n, const int sources[], const int degrees[], const int destinations[], const int weights[], MPI_Fint* info, int* reorder, MPI_Fint* comm_dist_graph, MPI_Fint *ierr) {
	f_mpi_dist_graph_create(comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph, ierr);
}
int c_MPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write_at, (fh, offset, buf, count, datatype, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	append_offset(offset);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	int status_arg[2] = {0};
	void **args = assemble_args_list(5, &obj_id_0, &mem_attr_0, &count, &obj_id_1, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return c_MPI_File_write_at(fh, offset, buf, count, datatype, status); }
extern void f_mpi_file_write_at(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_File_write_at(c_handle_0, offset, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_FILE_WRITE_AT(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_at(fh, offset, buf, count, datatype, status, ierr);
}
extern void mpi_file_write_at(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_at(fh, offset, buf, count, datatype, status, ierr);
}
extern void mpi_file_write_at_(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_at(fh, offset, buf, count, datatype, status, ierr);
}
extern void mpi_file_write_at__(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_at(fh, offset, buf, count, datatype, status, ierr);
}
int c_MPI_File_close(MPI_File *fh)
{
	int obj_id_0 = MPI_OBJ_ID(MPI_File, fh);
	void **args = assemble_args_list(1, &obj_id_0);
	MPI_OBJ_RELEASE(MPI_File, fh);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_1(int, MPI_File_close, (fh));
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_File_close(MPI_File *fh) { return c_MPI_File_close(fh); }
extern void f_mpi_file_close(MPI_Fint* fh, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	c_MPI_File_close(&c_handle_0);
	*fh = PMPI_File_c2f(c_handle_0);
}
extern void MPI_FILE_CLOSE(MPI_Fint* fh, MPI_Fint *ierr) {
	f_mpi_file_close(fh, ierr);
}
extern void mpi_file_close(MPI_Fint* fh, MPI_Fint *ierr) {
	f_mpi_file_close(fh, ierr);
}
extern void mpi_file_close_(MPI_Fint* fh, MPI_Fint *ierr) {
	f_mpi_file_close(fh, ierr);
}
extern void mpi_file_close__(MPI_Fint* fh, MPI_Fint *ierr) {
	f_mpi_file_close(fh, ierr);
}
int c_MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode)
{
	PILGRIM_TRACING_1(int, MPI_Comm_call_errhandler, (comm, errorcode));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, &errorcode);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode) { return c_MPI_Comm_call_errhandler(comm, errorcode); }
extern void f_mpi_comm_call_errhandler(MPI_Fint* comm, int* errorcode, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Comm_call_errhandler(c_handle_0, (*errorcode));
}
extern void MPI_COMM_CALL_ERRHANDLER(MPI_Fint* comm, int* errorcode, MPI_Fint *ierr) {
	f_mpi_comm_call_errhandler(comm, errorcode, ierr);
}
extern void mpi_comm_call_errhandler(MPI_Fint* comm, int* errorcode, MPI_Fint *ierr) {
	f_mpi_comm_call_errhandler(comm, errorcode, ierr);
}
extern void mpi_comm_call_errhandler_(MPI_Fint* comm, int* errorcode, MPI_Fint *ierr) {
	f_mpi_comm_call_errhandler(comm, errorcode, ierr);
}
extern void mpi_comm_call_errhandler__(MPI_Fint* comm, int* errorcode, MPI_Fint *ierr) {
	f_mpi_comm_call_errhandler(comm, errorcode, ierr);
}
int c_MPI_Win_flush_local(int rank, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_flush_local, (rank, win));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(2, &rank, &obj_id_0);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Win_flush_local(int rank, MPI_Win win) { return c_MPI_Win_flush_local(rank, win); }
extern void f_mpi_win_flush_local(int* rank, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_flush_local((*rank), c_handle_0);
}
extern void MPI_WIN_FLUSH_LOCAL(int* rank, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_flush_local(rank, win, ierr);
}
extern void mpi_win_flush_local(int* rank, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_flush_local(rank, win, ierr);
}
extern void mpi_win_flush_local_(int* rank, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_flush_local(rank, win, ierr);
}
extern void mpi_win_flush_local__(int* rank, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_flush_local(rank, win, ierr);
}
int c_MPI_File_create_errhandler(MPI_File_errhandler_function *file_errhandler_fn, MPI_Errhandler *errhandler)
{
	PILGRIM_TRACING_1(int, MPI_File_create_errhandler, (file_errhandler_fn, errhandler));
	int obj_id_0 = MPI_OBJ_ID(MPI_Errhandler, errhandler);
	void **args = assemble_args_list(2, file_errhandler_fn, &obj_id_0);
	int sizes[] = { 1*sizeof(MPI_File_errhandler_function), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_create_errhandler(MPI_File_errhandler_function *file_errhandler_fn, MPI_Errhandler *errhandler) { return c_MPI_File_create_errhandler(file_errhandler_fn, errhandler); }
extern void f_mpi_file_create_errhandler(MPI_File_errhandler_function* file_errhandler_fn, MPI_Fint* errhandler, MPI_Fint *ierr) {
	MPI_Errhandler c_handle_0;
	c_handle_0 = PMPI_Errhandler_f2c(*errhandler);
	c_MPI_File_create_errhandler(file_errhandler_fn, &c_handle_0);
	*errhandler = PMPI_Errhandler_c2f(c_handle_0);
}
extern void MPI_FILE_CREATE_ERRHANDLER(MPI_File_errhandler_function* file_errhandler_fn, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_file_create_errhandler(file_errhandler_fn, errhandler, ierr);
}
extern void mpi_file_create_errhandler(MPI_File_errhandler_function* file_errhandler_fn, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_file_create_errhandler(file_errhandler_fn, errhandler, ierr);
}
extern void mpi_file_create_errhandler_(MPI_File_errhandler_function* file_errhandler_fn, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_file_create_errhandler(file_errhandler_fn, errhandler, ierr);
}
extern void mpi_file_create_errhandler__(MPI_File_errhandler_function* file_errhandler_fn, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_file_create_errhandler(file_errhandler_fn, errhandler, ierr);
}
int c_MPI_Group_free(MPI_Group *group)
{
	int obj_id_0 = MPI_OBJ_ID(MPI_Group, group);
	void **args = assemble_args_list(1, &obj_id_0);
	MPI_OBJ_RELEASE(MPI_Group, group);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_1(int, MPI_Group_free, (group));
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Group_free(MPI_Group *group) { return c_MPI_Group_free(group); }
extern void f_mpi_group_free(MPI_Fint* group, MPI_Fint *ierr) {
	MPI_Group c_handle_0;
	c_handle_0 = PMPI_Group_f2c(*group);
	c_MPI_Group_free(&c_handle_0);
	*group = PMPI_Group_c2f(c_handle_0);
}
extern void MPI_GROUP_FREE(MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_group_free(group, ierr);
}
extern void mpi_group_free(MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_group_free(group, ierr);
}
extern void mpi_group_free_(MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_group_free(group, ierr);
}
extern void mpi_group_free__(MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_group_free(group, ierr);
}
int c_MPI_Ialltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ialltoall, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(7, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, &recvcount, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Ialltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return c_MPI_Ialltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request); }
extern void f_mpi_ialltoall(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Ialltoall(sendbuf, (*sendcount), c_handle_0, recvbuf, (*recvcount), c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_IALLTOALL(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ialltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}
extern void mpi_ialltoall(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ialltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}
extern void mpi_ialltoall_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ialltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}
extern void mpi_ialltoall__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ialltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}
int c_MPI_Comm_rank(MPI_Comm comm, int *rank)
{
	PILGRIM_TRACING_1(int, MPI_Comm_rank, (comm, rank));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, &placeholder);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_rank(MPI_Comm comm, int *rank) { return c_MPI_Comm_rank(comm, rank); }
extern void f_mpi_comm_rank(MPI_Fint* comm, int* rank, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Comm_rank(c_handle_0, rank);
}
extern void MPI_COMM_RANK(MPI_Fint* comm, int* rank, MPI_Fint *ierr) {
	f_mpi_comm_rank(comm, rank, ierr);
}
extern void mpi_comm_rank(MPI_Fint* comm, int* rank, MPI_Fint *ierr) {
	f_mpi_comm_rank(comm, rank, ierr);
}
extern void mpi_comm_rank_(MPI_Fint* comm, int* rank, MPI_Fint *ierr) {
	f_mpi_comm_rank(comm, rank, ierr);
}
extern void mpi_comm_rank__(MPI_Fint* comm, int* rank, MPI_Fint *ierr) {
	f_mpi_comm_rank(comm, rank, ierr);
}
int c_MPI_Cancel(MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Cancel, (request));
	void **args = NULL;
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(0, sizes, args, -1);
}
int MPI_Cancel(MPI_Request *request) { return c_MPI_Cancel(request); }
extern void f_mpi_cancel(MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Request c_handle_0;
	c_handle_0 = PMPI_Request_f2c(*request);
	c_MPI_Cancel(&c_handle_0);
}
extern void MPI_CANCEL(MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_cancel(request, ierr);
}
extern void mpi_cancel(MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_cancel(request, ierr);
}
extern void mpi_cancel_(MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_cancel(request, ierr);
}
extern void mpi_cancel__(MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_cancel(request, ierr);
}
int c_MPI_Win_post(MPI_Group group, int assert, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_post, (group, assert, win));
	MPI_Group obj_0 = group;
	int obj_id_0 = MPI_OBJ_ID(MPI_Group, &obj_0);
	MPI_Win obj_1 = win;
	int obj_id_1 = MPI_OBJ_ID(MPI_Win, &obj_1);
	void **args = assemble_args_list(3, &obj_id_0, &assert, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Win_post(MPI_Group group, int assert, MPI_Win win) { return c_MPI_Win_post(group, assert, win); }
extern void f_mpi_win_post(MPI_Fint* group, int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Group c_handle_0;
	c_handle_0 = PMPI_Group_f2c(*group);
	MPI_Win c_handle_1;
	c_handle_1 = PMPI_Win_f2c(*win);
	c_MPI_Win_post(c_handle_0, (*assert), c_handle_1);
}
extern void MPI_WIN_POST(MPI_Fint* group, int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_post(group, assert, win, ierr);
}
extern void mpi_win_post(MPI_Fint* group, int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_post(group, assert, win, ierr);
}
extern void mpi_win_post_(MPI_Fint* group, int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_post(group, assert, win, ierr);
}
extern void mpi_win_post__(MPI_Fint* group, int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_post(group, assert, win, ierr);
}
int c_MPI_Type_commit(MPI_Datatype *datatype)
{
	PILGRIM_TRACING_1(int, MPI_Type_commit, (datatype));
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, datatype);
	void **args = assemble_args_list(1, &obj_id_0);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Type_commit(MPI_Datatype *datatype) { return c_MPI_Type_commit(datatype); }
extern void f_mpi_type_commit(MPI_Fint* datatype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Type_commit(&c_handle_0);
	*datatype = PMPI_Type_c2f(c_handle_0);
}
extern void MPI_TYPE_COMMIT(MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_type_commit(datatype, ierr);
}
extern void mpi_type_commit(MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_type_commit(datatype, ierr);
}
extern void mpi_type_commit_(MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_type_commit(datatype, ierr);
}
extern void mpi_type_commit__(MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_type_commit(datatype, ierr);
}
int c_MPI_File_iwrite_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iwrite_shared, (fh, buf, count, datatype, request));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(4, &obj_id_0, &mem_attr_0, &count, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_File_iwrite_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return c_MPI_File_iwrite_shared(fh, buf, count, datatype, request); }
extern void f_mpi_file_iwrite_shared(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_File_iwrite_shared(c_handle_0, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_FILE_IWRITE_SHARED(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite_shared(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iwrite_shared(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite_shared(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iwrite_shared_(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite_shared(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iwrite_shared__(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite_shared(fh, buf, count, datatype, request, ierr);
}
int c_MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb, MPI_Count *extent)
{
	PILGRIM_TRACING_1(int, MPI_Type_get_extent_x, (datatype, lb, extent));
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	void **args = assemble_args_list(3, &obj_id_0, lb, extent);
	int sizes[] = { sizeof(int), 1*sizeof(MPI_Count), 1*sizeof(MPI_Count) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb, MPI_Count *extent) { return c_MPI_Type_get_extent_x(datatype, lb, extent); }
extern void f_mpi_type_get_extent_x(MPI_Fint* datatype, MPI_Count* lb, MPI_Count* extent, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Type_get_extent_x(c_handle_0, lb, extent);
}
extern void MPI_TYPE_GET_EXTENT_X(MPI_Fint* datatype, MPI_Count* lb, MPI_Count* extent, MPI_Fint *ierr) {
	f_mpi_type_get_extent_x(datatype, lb, extent, ierr);
}
extern void mpi_type_get_extent_x(MPI_Fint* datatype, MPI_Count* lb, MPI_Count* extent, MPI_Fint *ierr) {
	f_mpi_type_get_extent_x(datatype, lb, extent, ierr);
}
extern void mpi_type_get_extent_x_(MPI_Fint* datatype, MPI_Count* lb, MPI_Count* extent, MPI_Fint *ierr) {
	f_mpi_type_get_extent_x(datatype, lb, extent, ierr);
}
extern void mpi_type_get_extent_x__(MPI_Fint* datatype, MPI_Count* lb, MPI_Count* extent, MPI_Fint *ierr) {
	f_mpi_type_get_extent_x(datatype, lb, extent, ierr);
}
int c_MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Probe, (source, tag, comm, status));
	int source_rank = g_mpi_rank - source;
	if(source == MPI_ANY_SOURCE) source_rank = PILGRIM_MPI_ANY_SOURCE;
	if(source == MPI_PROC_NULL) source_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	int status_arg[2] = {0};
	if(source == MPI_ANY_SOURCE && status && status!=MPI_STATUS_IGNORE) status_arg[0] = status->MPI_SOURCE;
	if(tag == MPI_ANY_TAG && status && status!=MPI_STATUS_IGNORE) status_arg[1] = status->MPI_TAG;
	void **args = assemble_args_list(4, &source_rank, &my_tag, &obj_id_0, status_arg);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status) { return c_MPI_Probe(source, tag, comm, status); }
extern void f_mpi_probe(int* source, int* tag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Status c_handle_1;
	PMPI_Status_f2c(status, &c_handle_1);
	c_MPI_Probe((*source), (*tag), c_handle_0, &c_handle_1);
	PMPI_Status_c2f(&c_handle_1, status);
}
extern void MPI_PROBE(int* source, int* tag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_probe(source, tag, comm, status, ierr);
}
extern void mpi_probe(int* source, int* tag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_probe(source, tag, comm, status, ierr);
}
extern void mpi_probe_(int* source, int* tag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_probe(source, tag, comm, status, ierr);
}
extern void mpi_probe__(int* source, int* tag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_probe(source, tag, comm, status, ierr);
}
int c_MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[])
{
	PILGRIM_TRACING_1(int, MPI_Cart_get, (comm, maxdims, dims, periods, coords));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(5, &obj_id_0, &maxdims, dims, periods, coords);
	int sizes[] = { sizeof(int), sizeof(int), maxdims*sizeof(int), maxdims*sizeof(int), maxdims*sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[]) { return c_MPI_Cart_get(comm, maxdims, dims, periods, coords); }
extern void f_mpi_cart_get(MPI_Fint* comm, int* maxdims, int dims[], int periods[], int coords[], MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Cart_get(c_handle_0, (*maxdims), dims, periods, coords);
}
extern void MPI_CART_GET(MPI_Fint* comm, int* maxdims, int dims[], int periods[], int coords[], MPI_Fint *ierr) {
	f_mpi_cart_get(comm, maxdims, dims, periods, coords, ierr);
}
extern void mpi_cart_get(MPI_Fint* comm, int* maxdims, int dims[], int periods[], int coords[], MPI_Fint *ierr) {
	f_mpi_cart_get(comm, maxdims, dims, periods, coords, ierr);
}
extern void mpi_cart_get_(MPI_Fint* comm, int* maxdims, int dims[], int periods[], int coords[], MPI_Fint *ierr) {
	f_mpi_cart_get(comm, maxdims, dims, periods, coords, ierr);
}
extern void mpi_cart_get__(MPI_Fint* comm, int* maxdims, int dims[], int periods[], int coords[], MPI_Fint *ierr) {
	f_mpi_cart_get(comm, maxdims, dims, periods, coords, ierr);
}
int c_MPI_Win_flush(int rank, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_flush, (rank, win));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(2, &rank, &obj_id_0);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Win_flush(int rank, MPI_Win win) { return c_MPI_Win_flush(rank, win); }
extern void f_mpi_win_flush(int* rank, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_flush((*rank), c_handle_0);
}
extern void MPI_WIN_FLUSH(int* rank, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_flush(rank, win, ierr);
}
extern void mpi_win_flush(int* rank, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_flush(rank, win, ierr);
}
extern void mpi_win_flush_(int* rank, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_flush(rank, win, ierr);
}
extern void mpi_win_flush__(int* rank, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_flush(rank, win, ierr);
}
int c_MPI_Intercomm_create(MPI_Comm local_comm, int local_leader, MPI_Comm peer_comm, int remote_leader, int tag, MPI_Comm *newintercomm)
{
	PILGRIM_TRACING_1(int, MPI_Intercomm_create, (local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm));
	generate_intercomm_id(local_comm, newintercomm, tag);
	MPI_Comm obj_0 = local_comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	MPI_Comm obj_1 = peer_comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, newintercomm);
	void **args = assemble_args_list(6, &obj_id_0, &local_leader, &obj_id_1, &remote_leader, &my_tag, &obj_id_2);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader, MPI_Comm peer_comm, int remote_leader, int tag, MPI_Comm *newintercomm) { return c_MPI_Intercomm_create(local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm); }
extern void f_mpi_intercomm_create(MPI_Fint* local_comm, int* local_leader, MPI_Fint* peer_comm, int* remote_leader, int* tag, MPI_Fint* newintercomm, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*local_comm);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*peer_comm);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*newintercomm);
	c_MPI_Intercomm_create(c_handle_0, (*local_leader), c_handle_1, (*remote_leader), (*tag), &c_handle_2);
	*newintercomm = PMPI_Comm_c2f(c_handle_2);
}
extern void MPI_INTERCOMM_CREATE(MPI_Fint* local_comm, int* local_leader, MPI_Fint* peer_comm, int* remote_leader, int* tag, MPI_Fint* newintercomm, MPI_Fint *ierr) {
	f_mpi_intercomm_create(local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm, ierr);
}
extern void mpi_intercomm_create(MPI_Fint* local_comm, int* local_leader, MPI_Fint* peer_comm, int* remote_leader, int* tag, MPI_Fint* newintercomm, MPI_Fint *ierr) {
	f_mpi_intercomm_create(local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm, ierr);
}
extern void mpi_intercomm_create_(MPI_Fint* local_comm, int* local_leader, MPI_Fint* peer_comm, int* remote_leader, int* tag, MPI_Fint* newintercomm, MPI_Fint *ierr) {
	f_mpi_intercomm_create(local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm, ierr);
}
extern void mpi_intercomm_create__(MPI_Fint* local_comm, int* local_leader, MPI_Fint* peer_comm, int* remote_leader, int* tag, MPI_Fint* newintercomm, MPI_Fint *ierr) {
	f_mpi_intercomm_create(local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm, ierr);
}
int c_MPI_Allreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Allreduce, (sendbuf, recvbuf, count, datatype, op, comm));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Op obj_1 = op;
	int obj_id_1 = MPI_OBJ_ID(MPI_Op, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(6, &mem_attr_0, &mem_attr_1, &count, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { return c_MPI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm); }
extern void f_mpi_allreduce(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Op c_handle_1;
	c_handle_1 = PMPI_Op_f2c(*op);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Allreduce(sendbuf, recvbuf, (*count), c_handle_0, c_handle_1, c_handle_2);
}
extern void MPI_ALLREDUCE(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_allreduce(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}
extern void mpi_allreduce(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_allreduce(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}
extern void mpi_allreduce_(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_allreduce(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}
extern void mpi_allreduce__(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_allreduce(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}
int c_MPI_Type_contiguous(int count, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_contiguous, (count, oldtype, newtype));
	MPI_Datatype obj_0 = oldtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, newtype);
	void **args = assemble_args_list(3, &count, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Type_contiguous(int count, MPI_Datatype oldtype, MPI_Datatype *newtype) { return c_MPI_Type_contiguous(count, oldtype, newtype); }
extern void f_mpi_type_contiguous(int* count, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*oldtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*newtype);
	c_MPI_Type_contiguous((*count), c_handle_0, &c_handle_1);
	*newtype = PMPI_Type_c2f(c_handle_1);
}
extern void MPI_TYPE_CONTIGUOUS(int* count, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_contiguous(count, oldtype, newtype, ierr);
}
extern void mpi_type_contiguous(int* count, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_contiguous(count, oldtype, newtype, ierr);
}
extern void mpi_type_contiguous_(int* count, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_contiguous(count, oldtype, newtype, ierr);
}
extern void mpi_type_contiguous__(int* count, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_contiguous(count, oldtype, newtype, ierr);
}
int c_MPI_Reduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Reduce, (sendbuf, recvbuf, count, datatype, op, root, comm));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Op obj_1 = op;
	int obj_id_1 = MPI_OBJ_ID(MPI_Op, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(7, &mem_attr_0, &mem_attr_1, &count, &obj_id_0, &obj_id_1, &root, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Reduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm) { return c_MPI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm); }
extern void f_mpi_reduce(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Op c_handle_1;
	c_handle_1 = PMPI_Op_f2c(*op);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Reduce(sendbuf, recvbuf, (*count), c_handle_0, c_handle_1, (*root), c_handle_2);
}
extern void MPI_REDUCE(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_reduce(sendbuf, recvbuf, count, datatype, op, root, comm, ierr);
}
extern void mpi_reduce(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_reduce(sendbuf, recvbuf, count, datatype, op, root, comm, ierr);
}
extern void mpi_reduce_(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_reduce(sendbuf, recvbuf, count, datatype, op, root, comm, ierr);
}
extern void mpi_reduce__(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_reduce(sendbuf, recvbuf, count, datatype, op, root, comm, ierr);
}
int c_MPI_File_get_position(MPI_File fh, MPI_Offset *offset)
{
	PILGRIM_TRACING_1(int, MPI_File_get_position, (fh, offset));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, offset);
	int sizes[] = { sizeof(int), 1*sizeof(MPI_Offset) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_get_position(MPI_File fh, MPI_Offset *offset) { return c_MPI_File_get_position(fh, offset); }
extern void f_mpi_file_get_position(MPI_Fint* fh, MPI_Offset* offset, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	c_MPI_File_get_position(c_handle_0, offset);
}
extern void MPI_FILE_GET_POSITION(MPI_Fint* fh, MPI_Offset* offset, MPI_Fint *ierr) {
	f_mpi_file_get_position(fh, offset, ierr);
}
extern void mpi_file_get_position(MPI_Fint* fh, MPI_Offset* offset, MPI_Fint *ierr) {
	f_mpi_file_get_position(fh, offset, ierr);
}
extern void mpi_file_get_position_(MPI_Fint* fh, MPI_Offset* offset, MPI_Fint *ierr) {
	f_mpi_file_get_position(fh, offset, ierr);
}
extern void mpi_file_get_position__(MPI_Fint* fh, MPI_Offset* offset, MPI_Fint *ierr) {
	f_mpi_file_get_position(fh, offset, ierr);
}
int c_MPI_Recv_init(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Recv_init, (buf, count, datatype, source, tag, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int source_rank = g_mpi_rank - source;
	if(source == MPI_ANY_SOURCE) source_rank = PILGRIM_MPI_ANY_SOURCE;
	if(source == MPI_PROC_NULL) source_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	int obj_id_2 = create_request_id(request, false, ID_MPI_Recv_init, source, tag, obj_id_1);
	void **args = assemble_args_list(7, &mem_attr_0, &count, &obj_id_0, &source_rank, &my_tag, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Recv_init(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request) { return c_MPI_Recv_init(buf, count, datatype, source, tag, comm, request); }
extern void f_mpi_recv_init(void* buf, int* count, MPI_Fint* datatype, int* source, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_Recv_init(buf, (*count), c_handle_0, (*source), (*tag), c_handle_1, &c_handle_2);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_RECV_INIT(void* buf, int* count, MPI_Fint* datatype, int* source, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_recv_init(buf, count, datatype, source, tag, comm, request, ierr);
}
extern void mpi_recv_init(void* buf, int* count, MPI_Fint* datatype, int* source, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_recv_init(buf, count, datatype, source, tag, comm, request, ierr);
}
extern void mpi_recv_init_(void* buf, int* count, MPI_Fint* datatype, int* source, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_recv_init(buf, count, datatype, source, tag, comm, request, ierr);
}
extern void mpi_recv_init__(void* buf, int* count, MPI_Fint* datatype, int* source, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_recv_init(buf, count, datatype, source, tag, comm, request, ierr);
}
int c_MPI_Comm_group(MPI_Comm comm, MPI_Group *group)
{
	PILGRIM_TRACING_1(int, MPI_Comm_group, (comm, group));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Group, group);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_group(MPI_Comm comm, MPI_Group *group) { return c_MPI_Comm_group(comm, group); }
extern void f_mpi_comm_group(MPI_Fint* comm, MPI_Fint* group, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Group c_handle_1;
	c_handle_1 = PMPI_Group_f2c(*group);
	c_MPI_Comm_group(c_handle_0, &c_handle_1);
	*group = PMPI_Group_c2f(c_handle_1);
}
extern void MPI_COMM_GROUP(MPI_Fint* comm, MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_comm_group(comm, group, ierr);
}
extern void mpi_comm_group(MPI_Fint* comm, MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_comm_group(comm, group, ierr);
}
extern void mpi_comm_group_(MPI_Fint* comm, MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_comm_group(comm, group, ierr);
}
extern void mpi_comm_group__(MPI_Fint* comm, MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_comm_group(comm, group, ierr);
}
int c_MPI_Is_thread_main(int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Is_thread_main, (flag));
	void **args = assemble_args_list(1, flag);
	int sizes[] = { 1*sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Is_thread_main(int *flag) { return c_MPI_Is_thread_main(flag); }
extern void f_mpi_is_thread_main(int* flag, MPI_Fint *ierr) {
	c_MPI_Is_thread_main(flag);
}
extern void MPI_IS_THREAD_MAIN(int* flag, MPI_Fint *ierr) {
	f_mpi_is_thread_main(flag, ierr);
}
extern void mpi_is_thread_main(int* flag, MPI_Fint *ierr) {
	f_mpi_is_thread_main(flag, ierr);
}
extern void mpi_is_thread_main_(int* flag, MPI_Fint *ierr) {
	f_mpi_is_thread_main(flag, ierr);
}
extern void mpi_is_thread_main__(int* flag, MPI_Fint *ierr) {
	f_mpi_is_thread_main(flag, ierr);
}
int c_MPI_File_iwrite_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iwrite_all, (fh, buf, count, datatype, request));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(4, &obj_id_0, &mem_attr_0, &count, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_File_iwrite_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return c_MPI_File_iwrite_all(fh, buf, count, datatype, request); }
extern void f_mpi_file_iwrite_all(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_File_iwrite_all(c_handle_0, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_FILE_IWRITE_ALL(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite_all(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iwrite_all(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite_all(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iwrite_all_(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite_all(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iwrite_all__(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite_all(fh, buf, count, datatype, request, ierr);
}
int c_MPI_Type_create_indexed_block(int count, int blocklength, const int array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_indexed_block, (count, blocklength, array_of_displacements, oldtype, newtype));
	MPI_Datatype obj_0 = oldtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, newtype);
	void **args = assemble_args_list(5, &count, &blocklength, array_of_displacements, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), count*sizeof(const int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Type_create_indexed_block(int count, int blocklength, const int array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { return c_MPI_Type_create_indexed_block(count, blocklength, array_of_displacements, oldtype, newtype); }
extern void f_mpi_type_create_indexed_block(int* count, int* blocklength, const int array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*oldtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*newtype);
	c_MPI_Type_create_indexed_block((*count), (*blocklength), array_of_displacements, c_handle_0, &c_handle_1);
	*newtype = PMPI_Type_c2f(c_handle_1);
}
extern void MPI_TYPE_CREATE_INDEXED_BLOCK(int* count, int* blocklength, const int array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_indexed_block(count, blocklength, array_of_displacements, oldtype, newtype, ierr);
}
extern void mpi_type_create_indexed_block(int* count, int* blocklength, const int array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_indexed_block(count, blocklength, array_of_displacements, oldtype, newtype, ierr);
}
extern void mpi_type_create_indexed_block_(int* count, int* blocklength, const int array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_indexed_block(count, blocklength, array_of_displacements, oldtype, newtype, ierr);
}
extern void mpi_type_create_indexed_block__(int* count, int* blocklength, const int array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_indexed_block(count, blocklength, array_of_displacements, oldtype, newtype, ierr);
}
int c_MPI_Type_create_hindexed(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_hindexed, (count, array_of_blocklengths, array_of_displacements, oldtype, newtype));
	MPI_Datatype obj_0 = oldtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, newtype);
	void **args = assemble_args_list(5, &count, array_of_blocklengths, array_of_displacements, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), count*sizeof(const int), count*sizeof(const MPI_Aint), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Type_create_hindexed(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { return c_MPI_Type_create_hindexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype); }
extern void f_mpi_type_create_hindexed(int* count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*oldtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*newtype);
	c_MPI_Type_create_hindexed((*count), array_of_blocklengths, array_of_displacements, c_handle_0, &c_handle_1);
	*newtype = PMPI_Type_c2f(c_handle_1);
}
extern void MPI_TYPE_CREATE_HINDEXED(int* count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_hindexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierr);
}
extern void mpi_type_create_hindexed(int* count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_hindexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierr);
}
extern void mpi_type_create_hindexed_(int* count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_hindexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierr);
}
extern void mpi_type_create_hindexed__(int* count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_hindexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierr);
}
int c_MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[], int sourceweights[], int maxoutdegree, int destinations[], int destweights[])
{
	PILGRIM_TRACING_1(int, MPI_Dist_graph_neighbors, (comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(7, &obj_id_0, &maxindegree, sources, sourceweights, &maxoutdegree, destinations, destweights);
	int sizes[] = { sizeof(int), sizeof(int), maxindegree*sizeof(int), comm_size*sizeof(int), sizeof(int), maxoutdegree*sizeof(int), comm_size*sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, comm_size);
}
int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[], int sourceweights[], int maxoutdegree, int destinations[], int destweights[]) { return c_MPI_Dist_graph_neighbors(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights); }
extern void f_mpi_dist_graph_neighbors(MPI_Fint* comm, int* maxindegree, int sources[], int sourceweights[], int* maxoutdegree, int destinations[], int destweights[], MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Dist_graph_neighbors(c_handle_0, (*maxindegree), sources, sourceweights, (*maxoutdegree), destinations, destweights);
}
extern void MPI_DIST_GRAPH_NEIGHBORS(MPI_Fint* comm, int* maxindegree, int sources[], int sourceweights[], int* maxoutdegree, int destinations[], int destweights[], MPI_Fint *ierr) {
	f_mpi_dist_graph_neighbors(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights, ierr);
}
extern void mpi_dist_graph_neighbors(MPI_Fint* comm, int* maxindegree, int sources[], int sourceweights[], int* maxoutdegree, int destinations[], int destweights[], MPI_Fint *ierr) {
	f_mpi_dist_graph_neighbors(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights, ierr);
}
extern void mpi_dist_graph_neighbors_(MPI_Fint* comm, int* maxindegree, int sources[], int sourceweights[], int* maxoutdegree, int destinations[], int destweights[], MPI_Fint *ierr) {
	f_mpi_dist_graph_neighbors(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights, ierr);
}
extern void mpi_dist_graph_neighbors__(MPI_Fint* comm, int* maxindegree, int sources[], int sourceweights[], int* maxoutdegree, int destinations[], int destweights[], MPI_Fint *ierr) {
	f_mpi_dist_graph_neighbors(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights, ierr);
}
int c_MPI_Error_string(int errorcode, char *string, int *resultlen)
{
	PILGRIM_TRACING_1(int, MPI_Error_string, (errorcode, string, resultlen));
	void **args = assemble_args_list(3, &errorcode, string, resultlen);
	int sizes[] = { sizeof(int), strlen(string)+1, 1*sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Error_string(int errorcode, char *string, int *resultlen) { return c_MPI_Error_string(errorcode, string, resultlen); }
extern void f_mpi_error_string(int* errorcode, char* string, int* resultlen, MPI_Fint *ierr) {
	c_MPI_Error_string((*errorcode), string, resultlen);
}
extern void MPI_ERROR_STRING(int* errorcode, char* string, int* resultlen, MPI_Fint *ierr) {
	f_mpi_error_string(errorcode, string, resultlen, ierr);
}
extern void mpi_error_string(int* errorcode, char* string, int* resultlen, MPI_Fint *ierr) {
	f_mpi_error_string(errorcode, string, resultlen, ierr);
}
extern void mpi_error_string_(int* errorcode, char* string, int* resultlen, MPI_Fint *ierr) {
	f_mpi_error_string(errorcode, string, resultlen, ierr);
}
extern void mpi_error_string__(int* errorcode, char* string, int* resultlen, MPI_Fint *ierr) {
	f_mpi_error_string(errorcode, string, resultlen, ierr);
}
int c_MPI_File_sync(MPI_File fh)
{
	PILGRIM_TRACING_1(int, MPI_File_sync, (fh));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	void **args = assemble_args_list(1, &obj_id_0);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_File_sync(MPI_File fh) { return c_MPI_File_sync(fh); }
extern void f_mpi_file_sync(MPI_Fint* fh, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	c_MPI_File_sync(c_handle_0);
	*fh = PMPI_File_c2f(c_handle_0);
}
extern void MPI_FILE_SYNC(MPI_Fint* fh, MPI_Fint *ierr) {
	f_mpi_file_sync(fh, ierr);
}
extern void mpi_file_sync(MPI_Fint* fh, MPI_Fint *ierr) {
	f_mpi_file_sync(fh, ierr);
}
extern void mpi_file_sync_(MPI_Fint* fh, MPI_Fint *ierr) {
	f_mpi_file_sync(fh, ierr);
}
extern void mpi_file_sync__(MPI_Fint* fh, MPI_Fint *ierr) {
	f_mpi_file_sync(fh, ierr);
}
int c_MPI_Ineighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ineighbor_allgatherv, (sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(8, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, recvcounts, displs, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(8, sizes, args, comm_size);
}
int MPI_Ineighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return c_MPI_Ineighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request); }
extern void f_mpi_ineighbor_allgatherv(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Ineighbor_allgatherv(sendbuf, (*sendcount), c_handle_0, recvbuf, recvcounts, displs, c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_INEIGHBOR_ALLGATHERV(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierr);
}
extern void mpi_ineighbor_allgatherv(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierr);
}
extern void mpi_ineighbor_allgatherv_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierr);
}
extern void mpi_ineighbor_allgatherv__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierr);
}
int c_MPI_Compare_and_swap(const void *origin_addr, const void *compare_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Compare_and_swap, (origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win));
	MemPtrAttr mem_attr_0;
	addr2id(origin_addr, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(compare_addr, &mem_attr_1);
	MemPtrAttr mem_attr_2;
	addr2id(result_addr, &mem_attr_2);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Win obj_1 = win;
	int obj_id_1 = MPI_OBJ_ID(MPI_Win, &obj_1);
	void **args = assemble_args_list(7, &mem_attr_0, &mem_attr_1, &mem_attr_2, &obj_id_0, &target_rank, &target_disp, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(MemPtrAttr), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MPI_Aint), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Compare_and_swap(const void *origin_addr, const void *compare_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Win win) { return c_MPI_Compare_and_swap(origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win); }
extern void f_mpi_compare_and_swap(const void* origin_addr, const void* compare_addr, void* result_addr, MPI_Fint* datatype, int* target_rank, MPI_Aint target_disp, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Win c_handle_1;
	c_handle_1 = PMPI_Win_f2c(*win);
	c_MPI_Compare_and_swap(origin_addr, compare_addr, result_addr, c_handle_0, (*target_rank), target_disp, c_handle_1);
}
extern void MPI_COMPARE_AND_SWAP(const void* origin_addr, const void* compare_addr, void* result_addr, MPI_Fint* datatype, int* target_rank, MPI_Aint target_disp, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_compare_and_swap(origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win, ierr);
}
extern void mpi_compare_and_swap(const void* origin_addr, const void* compare_addr, void* result_addr, MPI_Fint* datatype, int* target_rank, MPI_Aint target_disp, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_compare_and_swap(origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win, ierr);
}
extern void mpi_compare_and_swap_(const void* origin_addr, const void* compare_addr, void* result_addr, MPI_Fint* datatype, int* target_rank, MPI_Aint target_disp, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_compare_and_swap(origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win, ierr);
}
extern void mpi_compare_and_swap__(const void* origin_addr, const void* compare_addr, void* result_addr, MPI_Fint* datatype, int* target_rank, MPI_Aint target_disp, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_compare_and_swap(origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win, ierr);
}
int c_MPI_Win_unlock_all(MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_unlock_all, (win));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(1, &obj_id_0);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Win_unlock_all(MPI_Win win) { return c_MPI_Win_unlock_all(win); }
extern void f_mpi_win_unlock_all(MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_unlock_all(c_handle_0);
}
extern void MPI_WIN_UNLOCK_ALL(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_unlock_all(win, ierr);
}
extern void mpi_win_unlock_all(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_unlock_all(win, ierr);
}
extern void mpi_win_unlock_all_(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_unlock_all(win, ierr);
}
extern void mpi_win_unlock_all__(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_unlock_all(win, ierr);
}
int c_MPI_Type_get_attr(MPI_Datatype datatype, int type_keyval, void *attribute_val, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Type_get_attr, (datatype, type_keyval, attribute_val, flag));
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(attribute_val, &mem_attr_0);
	void **args = assemble_args_list(4, &obj_id_0, &type_keyval, &mem_attr_0, flag);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MemPtrAttr), 1*sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Type_get_attr(MPI_Datatype datatype, int type_keyval, void *attribute_val, int *flag) { return c_MPI_Type_get_attr(datatype, type_keyval, attribute_val, flag); }
extern void f_mpi_type_get_attr(MPI_Fint* datatype, int* type_keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Type_get_attr(c_handle_0, (*type_keyval), attribute_val, flag);
}
extern void MPI_TYPE_GET_ATTR(MPI_Fint* datatype, int* type_keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	f_mpi_type_get_attr(datatype, type_keyval, attribute_val, flag, ierr);
}
extern void mpi_type_get_attr(MPI_Fint* datatype, int* type_keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	f_mpi_type_get_attr(datatype, type_keyval, attribute_val, flag, ierr);
}
extern void mpi_type_get_attr_(MPI_Fint* datatype, int* type_keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	f_mpi_type_get_attr(datatype, type_keyval, attribute_val, flag, ierr);
}
extern void mpi_type_get_attr__(MPI_Fint* datatype, int* type_keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	f_mpi_type_get_attr(datatype, type_keyval, attribute_val, flag, ierr);
}
int c_MPI_Comm_disconnect(MPI_Comm *comm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_disconnect, (comm));
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, comm);
	void **args = assemble_args_list(1, &obj_id_0);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Comm_disconnect(MPI_Comm *comm) { return c_MPI_Comm_disconnect(comm); }
extern void f_mpi_comm_disconnect(MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Comm_disconnect(&c_handle_0);
	*comm = PMPI_Comm_c2f(c_handle_0);
}
extern void MPI_COMM_DISCONNECT(MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_comm_disconnect(comm, ierr);
}
extern void mpi_comm_disconnect(MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_comm_disconnect(comm, ierr);
}
extern void mpi_comm_disconnect_(MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_comm_disconnect(comm, ierr);
}
extern void mpi_comm_disconnect__(MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_comm_disconnect(comm, ierr);
}
int c_MPI_T_pvar_readreset(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void *buf)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_readreset, (session, handle, buf));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	void **args = assemble_args_list(3, &session, &handle, &mem_attr_0);
	int sizes[] = { sizeof(MPI_T_pvar_session), sizeof(MPI_T_pvar_handle), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_T_pvar_readreset(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void *buf) { return c_MPI_T_pvar_readreset(session, handle, buf); }
int c_MPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Attr_get, (comm, keyval, attribute_val, flag));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(attribute_val, &mem_attr_0);
	void **args = assemble_args_list(4, &obj_id_0, &keyval, &mem_attr_0, flag);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MemPtrAttr), 1*sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val, int *flag) { return c_MPI_Attr_get(comm, keyval, attribute_val, flag); }
extern void f_mpi_attr_get(MPI_Fint* comm, int* keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Attr_get(c_handle_0, (*keyval), attribute_val, flag);
}
extern void MPI_ATTR_GET(MPI_Fint* comm, int* keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	f_mpi_attr_get(comm, keyval, attribute_val, flag, ierr);
}
extern void mpi_attr_get(MPI_Fint* comm, int* keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	f_mpi_attr_get(comm, keyval, attribute_val, flag, ierr);
}
extern void mpi_attr_get_(MPI_Fint* comm, int* keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	f_mpi_attr_get(comm, keyval, attribute_val, flag, ierr);
}
extern void mpi_attr_get__(MPI_Fint* comm, int* keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	f_mpi_attr_get(comm, keyval, attribute_val, flag, ierr);
}
int c_MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle)
{
	PILGRIM_TRACING_1(int, MPI_T_cvar_handle_free, (handle));
	void **args = assemble_args_list(1, handle);
	int sizes[] = { 1*sizeof(MPI_T_cvar_handle) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle) { return c_MPI_T_cvar_handle_free(handle); }
int c_MPI_T_enum_get_item(MPI_T_enum enumtype, int index, int *value, char *name, int *name_len)
{
	PILGRIM_TRACING_1(int, MPI_T_enum_get_item, (enumtype, index, value, name, name_len));
	void **args = assemble_args_list(5, &enumtype, &index, value, name, name_len);
	int sizes[] = { sizeof(MPI_T_enum), sizeof(int), 1*sizeof(int), strlen(name)+1, 1*sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_T_enum_get_item(MPI_T_enum enumtype, int index, int *value, char *name, int *name_len) { return c_MPI_T_enum_get_item(enumtype, index, value, name, name_len); }
int c_MPI_File_call_errhandler(MPI_File fh, int errorcode)
{
	PILGRIM_TRACING_1(int, MPI_File_call_errhandler, (fh, errorcode));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, &errorcode);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_call_errhandler(MPI_File fh, int errorcode) { return c_MPI_File_call_errhandler(fh, errorcode); }
extern void f_mpi_file_call_errhandler(MPI_Fint* fh, int* errorcode, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	c_MPI_File_call_errhandler(c_handle_0, (*errorcode));
}
extern void MPI_FILE_CALL_ERRHANDLER(MPI_Fint* fh, int* errorcode, MPI_Fint *ierr) {
	f_mpi_file_call_errhandler(fh, errorcode, ierr);
}
extern void mpi_file_call_errhandler(MPI_Fint* fh, int* errorcode, MPI_Fint *ierr) {
	f_mpi_file_call_errhandler(fh, errorcode, ierr);
}
extern void mpi_file_call_errhandler_(MPI_Fint* fh, int* errorcode, MPI_Fint *ierr) {
	f_mpi_file_call_errhandler(fh, errorcode, ierr);
}
extern void mpi_file_call_errhandler__(MPI_Fint* fh, int* errorcode, MPI_Fint *ierr) {
	f_mpi_file_call_errhandler(fh, errorcode, ierr);
}
int c_MPI_Group_compare(MPI_Group group1, MPI_Group group2, int *result)
{
	PILGRIM_TRACING_1(int, MPI_Group_compare, (group1, group2, result));
	MPI_Group obj_0 = group1;
	int obj_id_0 = MPI_OBJ_ID(MPI_Group, &obj_0);
	MPI_Group obj_1 = group2;
	int obj_id_1 = MPI_OBJ_ID(MPI_Group, &obj_1);
	void **args = assemble_args_list(3, &obj_id_0, &obj_id_1, result);
	int sizes[] = { sizeof(int), sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Group_compare(MPI_Group group1, MPI_Group group2, int *result) { return c_MPI_Group_compare(group1, group2, result); }
extern void f_mpi_group_compare(MPI_Fint* group1, MPI_Fint* group2, int* result, MPI_Fint *ierr) {
	MPI_Group c_handle_0;
	c_handle_0 = PMPI_Group_f2c(*group1);
	MPI_Group c_handle_1;
	c_handle_1 = PMPI_Group_f2c(*group2);
	c_MPI_Group_compare(c_handle_0, c_handle_1, result);
}
extern void MPI_GROUP_COMPARE(MPI_Fint* group1, MPI_Fint* group2, int* result, MPI_Fint *ierr) {
	f_mpi_group_compare(group1, group2, result, ierr);
}
extern void mpi_group_compare(MPI_Fint* group1, MPI_Fint* group2, int* result, MPI_Fint *ierr) {
	f_mpi_group_compare(group1, group2, result, ierr);
}
extern void mpi_group_compare_(MPI_Fint* group1, MPI_Fint* group2, int* result, MPI_Fint *ierr) {
	f_mpi_group_compare(group1, group2, result, ierr);
}
extern void mpi_group_compare__(MPI_Fint* group1, MPI_Fint* group2, int* result, MPI_Fint *ierr) {
	f_mpi_group_compare(group1, group2, result, ierr);
}
int c_MPI_Imrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Request *request)
{
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Message, message);
	void **args = assemble_args_list(4, &mem_attr_0, &count, &obj_id_0, &obj_id_1);
	MPI_OBJ_RELEASE(MPI_Message, message);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_1(int, MPI_Imrecv, (buf, count, datatype, message, request));
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Imrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Request *request) { return c_MPI_Imrecv(buf, count, datatype, message, request); }
extern void f_mpi_imrecv(void* buf, int* count, MPI_Fint* datatype, MPI_Fint* message, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Message c_handle_1;
	c_handle_1 = PMPI_Message_f2c(*message);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_Imrecv(buf, (*count), c_handle_0, &c_handle_1, &c_handle_2);
	*message = PMPI_Message_c2f(c_handle_1);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_IMRECV(void* buf, int* count, MPI_Fint* datatype, MPI_Fint* message, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_imrecv(buf, count, datatype, message, request, ierr);
}
extern void mpi_imrecv(void* buf, int* count, MPI_Fint* datatype, MPI_Fint* message, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_imrecv(buf, count, datatype, message, request, ierr);
}
extern void mpi_imrecv_(void* buf, int* count, MPI_Fint* datatype, MPI_Fint* message, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_imrecv(buf, count, datatype, message, request, ierr);
}
extern void mpi_imrecv__(void* buf, int* count, MPI_Fint* datatype, MPI_Fint* message, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_imrecv(buf, count, datatype, message, request, ierr);
}
int c_MPI_T_category_get_index(const char *name, int *cat_index)
{
	PILGRIM_TRACING_1(int, MPI_T_category_get_index, (name, cat_index));
	void **args = assemble_args_list(2, name, cat_index);
	int sizes[] = { strlen(name)+1, 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_T_category_get_index(const char *name, int *cat_index) { return c_MPI_T_category_get_index(name, cat_index); }
int c_MPI_Test_cancelled(const MPI_Status *status, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Test_cancelled, (status, flag));
	int status_arg[2] = {0};
	void **args = assemble_args_list(2, status_arg, flag);
	int sizes[] = { sizeof(int)*2, 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Test_cancelled(const MPI_Status *status, int *flag) { return c_MPI_Test_cancelled(status, flag); }
extern void f_mpi_test_cancelled(MPI_Fint* status, int* flag, MPI_Fint *ierr) {
	MPI_Status c_handle_0;
	PMPI_Status_f2c(status, &c_handle_0);
	c_MPI_Test_cancelled(&c_handle_0, flag);
}
extern void MPI_TEST_CANCELLED(MPI_Fint* status, int* flag, MPI_Fint *ierr) {
	f_mpi_test_cancelled(status, flag, ierr);
}
extern void mpi_test_cancelled(MPI_Fint* status, int* flag, MPI_Fint *ierr) {
	f_mpi_test_cancelled(status, flag, ierr);
}
extern void mpi_test_cancelled_(MPI_Fint* status, int* flag, MPI_Fint *ierr) {
	f_mpi_test_cancelled(status, flag, ierr);
}
extern void mpi_test_cancelled__(MPI_Fint* status, int* flag, MPI_Fint *ierr) {
	f_mpi_test_cancelled(status, flag, ierr);
}
int c_MPI_Buffer_attach(void *buffer, int size)
{
	PILGRIM_TRACING_1(int, MPI_Buffer_attach, (buffer, size));
	MemPtrAttr mem_attr_0;
	addr2id(buffer, &mem_attr_0);
	void **args = assemble_args_list(2, &mem_attr_0, &size);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Buffer_attach(void *buffer, int size) { return c_MPI_Buffer_attach(buffer, size); }
extern void f_mpi_buffer_attach(void* buffer, int* size, MPI_Fint *ierr) {
	c_MPI_Buffer_attach(buffer, (*size));
}
extern void MPI_BUFFER_ATTACH(void* buffer, int* size, MPI_Fint *ierr) {
	f_mpi_buffer_attach(buffer, size, ierr);
}
extern void mpi_buffer_attach(void* buffer, int* size, MPI_Fint *ierr) {
	f_mpi_buffer_attach(buffer, size, ierr);
}
extern void mpi_buffer_attach_(void* buffer, int* size, MPI_Fint *ierr) {
	f_mpi_buffer_attach(buffer, size, ierr);
}
extern void mpi_buffer_attach__(void* buffer, int* size, MPI_Fint *ierr) {
	f_mpi_buffer_attach(buffer, size, ierr);
}
int c_MPI_Win_call_errhandler(MPI_Win win, int errorcode)
{
	PILGRIM_TRACING_1(int, MPI_Win_call_errhandler, (win, errorcode));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, &errorcode);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Win_call_errhandler(MPI_Win win, int errorcode) { return c_MPI_Win_call_errhandler(win, errorcode); }
extern void f_mpi_win_call_errhandler(MPI_Fint* win, int* errorcode, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_call_errhandler(c_handle_0, (*errorcode));
}
extern void MPI_WIN_CALL_ERRHANDLER(MPI_Fint* win, int* errorcode, MPI_Fint *ierr) {
	f_mpi_win_call_errhandler(win, errorcode, ierr);
}
extern void mpi_win_call_errhandler(MPI_Fint* win, int* errorcode, MPI_Fint *ierr) {
	f_mpi_win_call_errhandler(win, errorcode, ierr);
}
extern void mpi_win_call_errhandler_(MPI_Fint* win, int* errorcode, MPI_Fint *ierr) {
	f_mpi_win_call_errhandler(win, errorcode, ierr);
}
extern void mpi_win_call_errhandler__(MPI_Fint* win, int* errorcode, MPI_Fint *ierr) {
	f_mpi_win_call_errhandler(win, errorcode, ierr);
}
int c_MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors)
{
	PILGRIM_TRACING_1(int, MPI_Graph_neighbors_count, (comm, rank, nneighbors));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(3, &obj_id_0, &rank, nneighbors);
	int sizes[] = { sizeof(int), sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors) { return c_MPI_Graph_neighbors_count(comm, rank, nneighbors); }
extern void f_mpi_graph_neighbors_count(MPI_Fint* comm, int* rank, int* nneighbors, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Graph_neighbors_count(c_handle_0, (*rank), nneighbors);
}
extern void MPI_GRAPH_NEIGHBORS_COUNT(MPI_Fint* comm, int* rank, int* nneighbors, MPI_Fint *ierr) {
	f_mpi_graph_neighbors_count(comm, rank, nneighbors, ierr);
}
extern void mpi_graph_neighbors_count(MPI_Fint* comm, int* rank, int* nneighbors, MPI_Fint *ierr) {
	f_mpi_graph_neighbors_count(comm, rank, nneighbors, ierr);
}
extern void mpi_graph_neighbors_count_(MPI_Fint* comm, int* rank, int* nneighbors, MPI_Fint *ierr) {
	f_mpi_graph_neighbors_count(comm, rank, nneighbors, ierr);
}
extern void mpi_graph_neighbors_count__(MPI_Fint* comm, int* rank, int* nneighbors, MPI_Fint *ierr) {
	f_mpi_graph_neighbors_count(comm, rank, nneighbors, ierr);
}
int c_MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset)
{
	PILGRIM_TRACING_1(int, MPI_File_get_position_shared, (fh, offset));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, offset);
	int sizes[] = { sizeof(int), 1*sizeof(MPI_Offset) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset) { return c_MPI_File_get_position_shared(fh, offset); }
extern void f_mpi_file_get_position_shared(MPI_Fint* fh, MPI_Offset* offset, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	c_MPI_File_get_position_shared(c_handle_0, offset);
}
extern void MPI_FILE_GET_POSITION_SHARED(MPI_Fint* fh, MPI_Offset* offset, MPI_Fint *ierr) {
	f_mpi_file_get_position_shared(fh, offset, ierr);
}
extern void mpi_file_get_position_shared(MPI_Fint* fh, MPI_Offset* offset, MPI_Fint *ierr) {
	f_mpi_file_get_position_shared(fh, offset, ierr);
}
extern void mpi_file_get_position_shared_(MPI_Fint* fh, MPI_Offset* offset, MPI_Fint *ierr) {
	f_mpi_file_get_position_shared(fh, offset, ierr);
}
extern void mpi_file_get_position_shared__(MPI_Fint* fh, MPI_Offset* offset, MPI_Fint *ierr) {
	f_mpi_file_get_position_shared(fh, offset, ierr);
}
int c_MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[], const int periods[], int *newrank)
{
	PILGRIM_TRACING_1(int, MPI_Cart_map, (comm, ndims, dims, periods, newrank));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(5, &obj_id_0, &ndims, dims, periods, newrank);
	int sizes[] = { sizeof(int), sizeof(int), ndims*sizeof(const int), ndims*sizeof(const int), 1*sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[], const int periods[], int *newrank) { return c_MPI_Cart_map(comm, ndims, dims, periods, newrank); }
extern void f_mpi_cart_map(MPI_Fint* comm, int* ndims, const int dims[], const int periods[], int* newrank, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Cart_map(c_handle_0, (*ndims), dims, periods, newrank);
}
extern void MPI_CART_MAP(MPI_Fint* comm, int* ndims, const int dims[], const int periods[], int* newrank, MPI_Fint *ierr) {
	f_mpi_cart_map(comm, ndims, dims, periods, newrank, ierr);
}
extern void mpi_cart_map(MPI_Fint* comm, int* ndims, const int dims[], const int periods[], int* newrank, MPI_Fint *ierr) {
	f_mpi_cart_map(comm, ndims, dims, periods, newrank, ierr);
}
extern void mpi_cart_map_(MPI_Fint* comm, int* ndims, const int dims[], const int periods[], int* newrank, MPI_Fint *ierr) {
	f_mpi_cart_map(comm, ndims, dims, periods, newrank, ierr);
}
extern void mpi_cart_map__(MPI_Fint* comm, int* ndims, const int dims[], const int periods[], int* newrank, MPI_Fint *ierr) {
	f_mpi_cart_map(comm, ndims, dims, periods, newrank, ierr);
}
int c_MPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iread, (fh, buf, count, datatype, request));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(4, &obj_id_0, &mem_attr_0, &count, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return c_MPI_File_iread(fh, buf, count, datatype, request); }
extern void f_mpi_file_iread(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_File_iread(c_handle_0, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_FILE_IREAD(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iread(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iread_(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iread__(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread(fh, buf, count, datatype, request, ierr);
}
int c_MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree, int *outdegree, int *weighted)
{
	PILGRIM_TRACING_1(int, MPI_Dist_graph_neighbors_count, (comm, indegree, outdegree, weighted));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(4, &obj_id_0, indegree, outdegree, weighted);
	int sizes[] = { sizeof(int), 1*sizeof(int), 1*sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree, int *outdegree, int *weighted) { return c_MPI_Dist_graph_neighbors_count(comm, indegree, outdegree, weighted); }
extern void f_mpi_dist_graph_neighbors_count(MPI_Fint* comm, int* indegree, int* outdegree, int* weighted, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Dist_graph_neighbors_count(c_handle_0, indegree, outdegree, weighted);
}
extern void MPI_DIST_GRAPH_NEIGHBORS_COUNT(MPI_Fint* comm, int* indegree, int* outdegree, int* weighted, MPI_Fint *ierr) {
	f_mpi_dist_graph_neighbors_count(comm, indegree, outdegree, weighted, ierr);
}
extern void mpi_dist_graph_neighbors_count(MPI_Fint* comm, int* indegree, int* outdegree, int* weighted, MPI_Fint *ierr) {
	f_mpi_dist_graph_neighbors_count(comm, indegree, outdegree, weighted, ierr);
}
extern void mpi_dist_graph_neighbors_count_(MPI_Fint* comm, int* indegree, int* outdegree, int* weighted, MPI_Fint *ierr) {
	f_mpi_dist_graph_neighbors_count(comm, indegree, outdegree, weighted, ierr);
}
extern void mpi_dist_graph_neighbors_count__(MPI_Fint* comm, int* indegree, int* outdegree, int* weighted, MPI_Fint *ierr) {
	f_mpi_dist_graph_neighbors_count(comm, indegree, outdegree, weighted, ierr);
}
int c_MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity, MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind, int *scope)
{
	PILGRIM_TRACING_1(int, MPI_T_cvar_get_info, (cvar_index, name, name_len, verbosity, datatype, enumtype, desc, desc_len, bind, scope));
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, datatype);
	void **args = assemble_args_list(10, &cvar_index, name, name_len, verbosity, &obj_id_0, enumtype, desc, desc_len, bind, scope);
	int sizes[] = { sizeof(int), strlen(name)+1, 1*sizeof(int), 1*sizeof(int), sizeof(int), 1*sizeof(MPI_T_enum), strlen(desc)+1, 1*sizeof(int), 1*sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(10, sizes, args, -1);
}
int MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity, MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind, int *scope) { return c_MPI_T_cvar_get_info(cvar_index, name, name_len, verbosity, datatype, enumtype, desc, desc_len, bind, scope); }
int c_MPI_T_pvar_read(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void *buf)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_read, (session, handle, buf));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	void **args = assemble_args_list(3, &session, &handle, &mem_attr_0);
	int sizes[] = { sizeof(MPI_T_pvar_session), sizeof(MPI_T_pvar_handle), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_T_pvar_read(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void *buf) { return c_MPI_T_pvar_read(session, handle, buf); }
int c_MPI_Type_set_name(MPI_Datatype datatype, const char *type_name)
{
	PILGRIM_TRACING_1(int, MPI_Type_set_name, (datatype, type_name));
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, type_name);
	int sizes[] = { sizeof(int), strlen(type_name)+1 };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Type_set_name(MPI_Datatype datatype, const char *type_name) { return c_MPI_Type_set_name(datatype, type_name); }
extern void f_mpi_type_set_name(MPI_Fint* datatype, const char* type_name, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Type_set_name(c_handle_0, type_name);
	*datatype = PMPI_Type_c2f(c_handle_0);
}
extern void MPI_TYPE_SET_NAME(MPI_Fint* datatype, const char* type_name, MPI_Fint *ierr) {
	f_mpi_type_set_name(datatype, type_name, ierr);
}
extern void mpi_type_set_name(MPI_Fint* datatype, const char* type_name, MPI_Fint *ierr) {
	f_mpi_type_set_name(datatype, type_name, ierr);
}
extern void mpi_type_set_name_(MPI_Fint* datatype, const char* type_name, MPI_Fint *ierr) {
	f_mpi_type_set_name(datatype, type_name, ierr);
}
extern void mpi_type_set_name__(MPI_Fint* datatype, const char* type_name, MPI_Fint *ierr) {
	f_mpi_type_set_name(datatype, type_name, ierr);
}
int c_MPI_Neighbor_alltoallw(const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Neighbor_alltoallw, (sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	int obj_id_0[comm_size];
	for(int i=0; i<comm_size; i++) obj_id_0[i] = (sendtypes==NULL) ? PILGRIM_INVALID_MPI_OBJECT_ID: MPI_OBJ_ID(MPI_Datatype, &sendtypes[i]);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	int obj_id_1[comm_size];
	for(int i=0; i<comm_size; i++) obj_id_1[i] = (recvtypes==NULL) ? PILGRIM_INVALID_MPI_OBJECT_ID: MPI_OBJ_ID(MPI_Datatype, &recvtypes[i]);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(9, &mem_attr_0, sendcounts, sdispls, obj_id_0, &mem_attr_1, recvcounts, rdispls, obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const MPI_Aint), (comm_size)*sizeof(int), sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const MPI_Aint), (comm_size)*sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args, comm_size);
}
int MPI_Neighbor_alltoallw(const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) { return c_MPI_Neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm); }
extern void f_mpi_neighbor_alltoallw(const void* sendbuf, const int sendcounts[], const MPI_Aint sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const MPI_Aint rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0[comm_size];
	for(int i = 0; i < comm_size; i++) c_handle_0[i] = PMPI_Type_f2c(sendtypes[i]);
	MPI_Datatype c_handle_1[comm_size];
	for(int i = 0; i < comm_size; i++) c_handle_1[i] = PMPI_Type_f2c(recvtypes[i]);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Neighbor_alltoallw(sendbuf, sendcounts, sdispls, c_handle_0, recvbuf, recvcounts, rdispls, c_handle_1, c_handle_2);
}
extern void MPI_NEIGHBOR_ALLTOALLW(const void* sendbuf, const int sendcounts[], const MPI_Aint sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const MPI_Aint rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}
extern void mpi_neighbor_alltoallw(const void* sendbuf, const int sendcounts[], const MPI_Aint sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const MPI_Aint rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}
extern void mpi_neighbor_alltoallw_(const void* sendbuf, const int sendcounts[], const MPI_Aint sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const MPI_Aint rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}
extern void mpi_neighbor_alltoallw__(const void* sendbuf, const int sendcounts[], const MPI_Aint sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const MPI_Aint rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}
int c_MPI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Neighbor_alltoallv, (sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(9, &mem_attr_0, sendcounts, sdispls, &obj_id_0, &mem_attr_1, recvcounts, rdispls, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), sizeof(int), sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args, comm_size);
}
int MPI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm) { return c_MPI_Neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm); }
extern void f_mpi_neighbor_alltoallv(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Neighbor_alltoallv(sendbuf, sendcounts, sdispls, c_handle_0, recvbuf, recvcounts, rdispls, c_handle_1, c_handle_2);
}
extern void MPI_NEIGHBOR_ALLTOALLV(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}
extern void mpi_neighbor_alltoallv(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}
extern void mpi_neighbor_alltoallv_(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}
extern void mpi_neighbor_alltoallv__(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}
int c_MPI_Publish_name(const char *service_name, MPI_Info info, const char *port_name)
{
	PILGRIM_TRACING_1(int, MPI_Publish_name, (service_name, info, port_name));
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	void **args = assemble_args_list(3, service_name, &obj_id_0, port_name);
	int sizes[] = { strlen(service_name)+1, sizeof(int), strlen(port_name)+1 };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Publish_name(const char *service_name, MPI_Info info, const char *port_name) { return c_MPI_Publish_name(service_name, info, port_name); }
extern void f_mpi_publish_name(const char* service_name, MPI_Fint* info, const char* port_name, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	c_MPI_Publish_name(service_name, c_handle_0, port_name);
}
extern void MPI_PUBLISH_NAME(const char* service_name, MPI_Fint* info, const char* port_name, MPI_Fint *ierr) {
	f_mpi_publish_name(service_name, info, port_name, ierr);
}
extern void mpi_publish_name(const char* service_name, MPI_Fint* info, const char* port_name, MPI_Fint *ierr) {
	f_mpi_publish_name(service_name, info, port_name, ierr);
}
extern void mpi_publish_name_(const char* service_name, MPI_Fint* info, const char* port_name, MPI_Fint *ierr) {
	f_mpi_publish_name(service_name, info, port_name, ierr);
}
extern void mpi_publish_name__(const char* service_name, MPI_Fint* info, const char* port_name, MPI_Fint *ierr) {
	f_mpi_publish_name(service_name, info, port_name, ierr);
}
int c_MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb, MPI_Aint *extent)
{
	PILGRIM_TRACING_1(int, MPI_Type_get_extent, (datatype, lb, extent));
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	void **args = assemble_args_list(3, &obj_id_0, lb, extent);
	int sizes[] = { sizeof(int), 1*sizeof(MPI_Aint), 1*sizeof(MPI_Aint) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb, MPI_Aint *extent) { return c_MPI_Type_get_extent(datatype, lb, extent); }
extern void f_mpi_type_get_extent(MPI_Fint* datatype, MPI_Aint* lb, MPI_Aint* extent, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Type_get_extent(c_handle_0, lb, extent);
}
extern void MPI_TYPE_GET_EXTENT(MPI_Fint* datatype, MPI_Aint* lb, MPI_Aint* extent, MPI_Fint *ierr) {
	f_mpi_type_get_extent(datatype, lb, extent, ierr);
}
extern void mpi_type_get_extent(MPI_Fint* datatype, MPI_Aint* lb, MPI_Aint* extent, MPI_Fint *ierr) {
	f_mpi_type_get_extent(datatype, lb, extent, ierr);
}
extern void mpi_type_get_extent_(MPI_Fint* datatype, MPI_Aint* lb, MPI_Aint* extent, MPI_Fint *ierr) {
	f_mpi_type_get_extent(datatype, lb, extent, ierr);
}
extern void mpi_type_get_extent__(MPI_Fint* datatype, MPI_Aint* lb, MPI_Aint* extent, MPI_Fint *ierr) {
	f_mpi_type_get_extent(datatype, lb, extent, ierr);
}
int c_MPI_Graph_create(MPI_Comm comm_old, int nnodes, const int index[], const int edges[], int reorder, MPI_Comm *comm_graph)
{
	PILGRIM_TRACING_1(int, MPI_Graph_create, (comm_old, nnodes, index, edges, reorder, comm_graph));
	generate_intracomm_id(comm_graph);
	MPI_Comm obj_0 = comm_old;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, comm_graph);
	void **args = assemble_args_list(6, &obj_id_0, &nnodes, index, edges, &reorder, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), nnodes*sizeof(const int), 1*sizeof(const int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Graph_create(MPI_Comm comm_old, int nnodes, const int index[], const int edges[], int reorder, MPI_Comm *comm_graph) { return c_MPI_Graph_create(comm_old, nnodes, index, edges, reorder, comm_graph); }
extern void f_mpi_graph_create(MPI_Fint* comm_old, int* nnodes, const int index[], const int edges[], int* reorder, MPI_Fint* comm_graph, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm_old);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm_graph);
	c_MPI_Graph_create(c_handle_0, (*nnodes), index, edges, (*reorder), &c_handle_1);
	*comm_graph = PMPI_Comm_c2f(c_handle_1);
}
extern void MPI_GRAPH_CREATE(MPI_Fint* comm_old, int* nnodes, const int index[], const int edges[], int* reorder, MPI_Fint* comm_graph, MPI_Fint *ierr) {
	f_mpi_graph_create(comm_old, nnodes, index, edges, reorder, comm_graph, ierr);
}
extern void mpi_graph_create(MPI_Fint* comm_old, int* nnodes, const int index[], const int edges[], int* reorder, MPI_Fint* comm_graph, MPI_Fint *ierr) {
	f_mpi_graph_create(comm_old, nnodes, index, edges, reorder, comm_graph, ierr);
}
extern void mpi_graph_create_(MPI_Fint* comm_old, int* nnodes, const int index[], const int edges[], int* reorder, MPI_Fint* comm_graph, MPI_Fint *ierr) {
	f_mpi_graph_create(comm_old, nnodes, index, edges, reorder, comm_graph, ierr);
}
extern void mpi_graph_create__(MPI_Fint* comm_old, int* nnodes, const int index[], const int edges[], int* reorder, MPI_Fint* comm_graph, MPI_Fint *ierr) {
	f_mpi_graph_create(comm_old, nnodes, index, edges, reorder, comm_graph, ierr);
}
int c_MPI_Put(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Put, (origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win));
	MemPtrAttr mem_attr_0;
	addr2id(origin_addr, &mem_attr_0);
	MPI_Datatype obj_0 = origin_datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Datatype obj_1 = target_datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Win obj_2 = win;
	int obj_id_2 = MPI_OBJ_ID(MPI_Win, &obj_2);
	void **args = assemble_args_list(8, &mem_attr_0, &origin_count, &obj_id_0, &target_rank, &target_disp, &target_count, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(8, sizes, args, -1);
}
int MPI_Put(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win) { return c_MPI_Put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win); }
extern void f_mpi_put(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*origin_datatype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*target_datatype);
	MPI_Win c_handle_2;
	c_handle_2 = PMPI_Win_f2c(*win);
	c_MPI_Put(origin_addr, (*origin_count), c_handle_0, (*target_rank), target_disp, (*target_count), c_handle_1, c_handle_2);
}
extern void MPI_PUT(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierr);
}
extern void mpi_put(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierr);
}
extern void mpi_put_(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierr);
}
extern void mpi_put__(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierr);
}
int c_MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win)
{
	PILGRIM_TRACING_1(int, MPI_Win_create_dynamic, (info, comm, win));
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	int obj_id_2 = MPI_OBJ_ID(MPI_Win, win);
	void **args = assemble_args_list(3, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win) { return c_MPI_Win_create_dynamic(info, comm, win); }
extern void f_mpi_win_create_dynamic(MPI_Fint* info, MPI_Fint* comm, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Win c_handle_2;
	c_handle_2 = PMPI_Win_f2c(*win);
	c_MPI_Win_create_dynamic(c_handle_0, c_handle_1, &c_handle_2);
	*win = PMPI_Win_c2f(c_handle_2);
}
extern void MPI_WIN_CREATE_DYNAMIC(MPI_Fint* info, MPI_Fint* comm, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_create_dynamic(info, comm, win, ierr);
}
extern void mpi_win_create_dynamic(MPI_Fint* info, MPI_Fint* comm, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_create_dynamic(info, comm, win, ierr);
}
extern void mpi_win_create_dynamic_(MPI_Fint* info, MPI_Fint* comm, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_create_dynamic(info, comm, win, ierr);
}
extern void mpi_win_create_dynamic__(MPI_Fint* info, MPI_Fint* comm, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_create_dynamic(info, comm, win, ierr);
}
int c_MPI_Ibsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ibsend, (buf, count, datatype, dest, tag, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int dest_rank = g_mpi_rank - dest;
	if(dest == MPI_ANY_SOURCE) dest_rank = PILGRIM_MPI_ANY_SOURCE;
	if(dest == MPI_PROC_NULL) dest_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(6, &mem_attr_0, &count, &obj_id_0, &dest_rank, &my_tag, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Ibsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return c_MPI_Ibsend(buf, count, datatype, dest, tag, comm, request); }
extern void f_mpi_ibsend(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_Ibsend(buf, (*count), c_handle_0, (*dest), (*tag), c_handle_1, &c_handle_2);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_IBSEND(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ibsend(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_ibsend(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ibsend(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_ibsend_(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ibsend(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_ibsend__(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ibsend(buf, count, datatype, dest, tag, comm, request, ierr);
}
int c_MPI_Win_complete(MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_complete, (win));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(1, &obj_id_0);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Win_complete(MPI_Win win) { return c_MPI_Win_complete(win); }
extern void f_mpi_win_complete(MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_complete(c_handle_0);
}
extern void MPI_WIN_COMPLETE(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_complete(win, ierr);
}
extern void mpi_win_complete(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_complete(win, ierr);
}
extern void mpi_win_complete_(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_complete(win, ierr);
}
extern void mpi_win_complete__(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_complete(win, ierr);
}
int c_MPI_Graph_map(MPI_Comm comm, int nnodes, const int index[], const int edges[], int *newrank)
{
	PILGRIM_TRACING_1(int, MPI_Graph_map, (comm, nnodes, index, edges, newrank));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(5, &obj_id_0, &nnodes, index, edges, newrank);
	int sizes[] = { sizeof(int), sizeof(int), nnodes*sizeof(const int), comm_size*sizeof(const int), comm_size*sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, comm_size);
}
int MPI_Graph_map(MPI_Comm comm, int nnodes, const int index[], const int edges[], int *newrank) { return c_MPI_Graph_map(comm, nnodes, index, edges, newrank); }
extern void f_mpi_graph_map(MPI_Fint* comm, int* nnodes, const int index[], const int edges[], int* newrank, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Graph_map(c_handle_0, (*nnodes), index, edges, newrank);
}
extern void MPI_GRAPH_MAP(MPI_Fint* comm, int* nnodes, const int index[], const int edges[], int* newrank, MPI_Fint *ierr) {
	f_mpi_graph_map(comm, nnodes, index, edges, newrank, ierr);
}
extern void mpi_graph_map(MPI_Fint* comm, int* nnodes, const int index[], const int edges[], int* newrank, MPI_Fint *ierr) {
	f_mpi_graph_map(comm, nnodes, index, edges, newrank, ierr);
}
extern void mpi_graph_map_(MPI_Fint* comm, int* nnodes, const int index[], const int edges[], int* newrank, MPI_Fint *ierr) {
	f_mpi_graph_map(comm, nnodes, index, edges, newrank, ierr);
}
extern void mpi_graph_map__(MPI_Fint* comm, int* nnodes, const int index[], const int edges[], int* newrank, MPI_Fint *ierr) {
	f_mpi_graph_map(comm, nnodes, index, edges, newrank, ierr);
}
int c_MPI_Info_get_valuelen(MPI_Info info, const char *key, int *valuelen, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Info_get_valuelen, (info, key, valuelen, flag));
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	void **args = assemble_args_list(4, &obj_id_0, key, valuelen, flag);
	int sizes[] = { sizeof(int), strlen(key)+1, 1*sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Info_get_valuelen(MPI_Info info, const char *key, int *valuelen, int *flag) { return c_MPI_Info_get_valuelen(info, key, valuelen, flag); }
extern void f_mpi_info_get_valuelen(MPI_Fint* info, const char* key, int* valuelen, int* flag, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	c_MPI_Info_get_valuelen(c_handle_0, key, valuelen, flag);
}
extern void MPI_INFO_GET_VALUELEN(MPI_Fint* info, const char* key, int* valuelen, int* flag, MPI_Fint *ierr) {
	f_mpi_info_get_valuelen(info, key, valuelen, flag, ierr);
}
extern void mpi_info_get_valuelen(MPI_Fint* info, const char* key, int* valuelen, int* flag, MPI_Fint *ierr) {
	f_mpi_info_get_valuelen(info, key, valuelen, flag, ierr);
}
extern void mpi_info_get_valuelen_(MPI_Fint* info, const char* key, int* valuelen, int* flag, MPI_Fint *ierr) {
	f_mpi_info_get_valuelen(info, key, valuelen, flag, ierr);
}
extern void mpi_info_get_valuelen__(MPI_Fint* info, const char* key, int* valuelen, int* flag, MPI_Fint *ierr) {
	f_mpi_info_get_valuelen(info, key, valuelen, flag, ierr);
}
int c_MPI_Cart_sub(MPI_Comm comm, const int remain_dims[], MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Cart_sub, (comm, remain_dims, newcomm));
	generate_intracomm_id(newcomm);
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, newcomm);
	void **args = assemble_args_list(3, &obj_id_0, remain_dims, &obj_id_1);
	int sizes[] = { sizeof(int), comm_size*sizeof(const int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, comm_size);
}
int MPI_Cart_sub(MPI_Comm comm, const int remain_dims[], MPI_Comm *newcomm) { return c_MPI_Cart_sub(comm, remain_dims, newcomm); }
extern void f_mpi_cart_sub(MPI_Fint* comm, const int remain_dims[], MPI_Fint* newcomm, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*newcomm);
	c_MPI_Cart_sub(c_handle_0, remain_dims, &c_handle_1);
	*newcomm = PMPI_Comm_c2f(c_handle_1);
}
extern void MPI_CART_SUB(MPI_Fint* comm, const int remain_dims[], MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_cart_sub(comm, remain_dims, newcomm, ierr);
}
extern void mpi_cart_sub(MPI_Fint* comm, const int remain_dims[], MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_cart_sub(comm, remain_dims, newcomm, ierr);
}
extern void mpi_cart_sub_(MPI_Fint* comm, const int remain_dims[], MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_cart_sub(comm, remain_dims, newcomm, ierr);
}
extern void mpi_cart_sub__(MPI_Fint* comm, const int remain_dims[], MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_cart_sub(comm, remain_dims, newcomm, ierr);
}
int c_MPI_Info_get(MPI_Info info, const char *key, int valuelen, char *value, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Info_get, (info, key, valuelen, value, flag));
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	void **args = assemble_args_list(5, &obj_id_0, key, &valuelen, value, flag);
	int sizes[] = { sizeof(int), strlen(key)+1, sizeof(int), strlen(value)+1, 1*sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Info_get(MPI_Info info, const char *key, int valuelen, char *value, int *flag) { return c_MPI_Info_get(info, key, valuelen, value, flag); }
extern void f_mpi_info_get(MPI_Fint* info, const char* key, int* valuelen, char* value, int* flag, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	c_MPI_Info_get(c_handle_0, key, (*valuelen), value, flag);
}
extern void MPI_INFO_GET(MPI_Fint* info, const char* key, int* valuelen, char* value, int* flag, MPI_Fint *ierr) {
	f_mpi_info_get(info, key, valuelen, value, flag, ierr);
}
extern void mpi_info_get(MPI_Fint* info, const char* key, int* valuelen, char* value, int* flag, MPI_Fint *ierr) {
	f_mpi_info_get(info, key, valuelen, value, flag, ierr);
}
extern void mpi_info_get_(MPI_Fint* info, const char* key, int* valuelen, char* value, int* flag, MPI_Fint *ierr) {
	f_mpi_info_get(info, key, valuelen, value, flag, ierr);
}
extern void mpi_info_get__(MPI_Fint* info, const char* key, int* valuelen, char* value, int* flag, MPI_Fint *ierr) {
	f_mpi_info_get(info, key, valuelen, value, flag, ierr);
}
int c_MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iwrite_at, (fh, offset, buf, count, datatype, request));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	append_offset(offset);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(4, &obj_id_0, &mem_attr_0, &count, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return c_MPI_File_iwrite_at(fh, offset, buf, count, datatype, request); }
extern void f_mpi_file_iwrite_at(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_File_iwrite_at(c_handle_0, offset, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_FILE_IWRITE_AT(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite_at(fh, offset, buf, count, datatype, request, ierr);
}
extern void mpi_file_iwrite_at(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite_at(fh, offset, buf, count, datatype, request, ierr);
}
extern void mpi_file_iwrite_at_(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite_at(fh, offset, buf, count, datatype, request, ierr);
}
extern void mpi_file_iwrite_at__(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite_at(fh, offset, buf, count, datatype, request, ierr);
}
int c_MPI_Comm_spawn(const char *command, char *argv[], int maxprocs, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
{
	PILGRIM_TRACING_1(int, MPI_Comm_spawn, (command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes));
	generate_intercomm_id(comm, intercomm, 0);
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, intercomm);
	void **args = assemble_args_list(8, command, argv, &maxprocs, &obj_id_0, &root, &obj_id_1, &obj_id_2, array_of_errcodes);
	int sizes[] = { strlen(command)+1, sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), comm_size*sizeof(int) };
	PILGRIM_TRACING_2(8, sizes, args, comm_size);
}
int MPI_Comm_spawn(const char *command, char *argv[], int maxprocs, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[]) { return c_MPI_Comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes); }
extern void f_mpi_comm_spawn(const char* command, char* argv[], int* maxprocs, MPI_Fint* info, int* root, MPI_Fint* comm, MPI_Fint* intercomm, int array_of_errcodes[], MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*intercomm);
	c_MPI_Comm_spawn(command, argv, (*maxprocs), c_handle_0, (*root), c_handle_1, &c_handle_2, array_of_errcodes);
	*intercomm = PMPI_Comm_c2f(c_handle_2);
}
extern void MPI_COMM_SPAWN(const char* command, char* argv[], int* maxprocs, MPI_Fint* info, int* root, MPI_Fint* comm, MPI_Fint* intercomm, int array_of_errcodes[], MPI_Fint *ierr) {
	f_mpi_comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes, ierr);
}
extern void mpi_comm_spawn(const char* command, char* argv[], int* maxprocs, MPI_Fint* info, int* root, MPI_Fint* comm, MPI_Fint* intercomm, int array_of_errcodes[], MPI_Fint *ierr) {
	f_mpi_comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes, ierr);
}
extern void mpi_comm_spawn_(const char* command, char* argv[], int* maxprocs, MPI_Fint* info, int* root, MPI_Fint* comm, MPI_Fint* intercomm, int array_of_errcodes[], MPI_Fint *ierr) {
	f_mpi_comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes, ierr);
}
extern void mpi_comm_spawn__(const char* command, char* argv[], int* maxprocs, MPI_Fint* info, int* root, MPI_Fint* comm, MPI_Fint* intercomm, int array_of_errcodes[], MPI_Fint *ierr) {
	f_mpi_comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes, ierr);
}
int c_MPI_Group_intersection(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup)
{
	PILGRIM_TRACING_1(int, MPI_Group_intersection, (group1, group2, newgroup));
	MPI_Group obj_0 = group1;
	int obj_id_0 = MPI_OBJ_ID(MPI_Group, &obj_0);
	MPI_Group obj_1 = group2;
	int obj_id_1 = MPI_OBJ_ID(MPI_Group, &obj_1);
	int obj_id_2 = MPI_OBJ_ID(MPI_Group, newgroup);
	void **args = assemble_args_list(3, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Group_intersection(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup) { return c_MPI_Group_intersection(group1, group2, newgroup); }
extern void f_mpi_group_intersection(MPI_Fint* group1, MPI_Fint* group2, MPI_Fint* newgroup, MPI_Fint *ierr) {
	MPI_Group c_handle_0;
	c_handle_0 = PMPI_Group_f2c(*group1);
	MPI_Group c_handle_1;
	c_handle_1 = PMPI_Group_f2c(*group2);
	MPI_Group c_handle_2;
	c_handle_2 = PMPI_Group_f2c(*newgroup);
	c_MPI_Group_intersection(c_handle_0, c_handle_1, &c_handle_2);
	*newgroup = PMPI_Group_c2f(c_handle_2);
}
extern void MPI_GROUP_INTERSECTION(MPI_Fint* group1, MPI_Fint* group2, MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_intersection(group1, group2, newgroup, ierr);
}
extern void mpi_group_intersection(MPI_Fint* group1, MPI_Fint* group2, MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_intersection(group1, group2, newgroup, ierr);
}
extern void mpi_group_intersection_(MPI_Fint* group1, MPI_Fint* group2, MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_intersection(group1, group2, newgroup, ierr);
}
extern void mpi_group_intersection__(MPI_Fint* group1, MPI_Fint* group2, MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_intersection(group1, group2, newgroup, ierr);
}
int c_MPI_Iallgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Iallgatherv, (sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(8, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, recvcounts, displs, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(8, sizes, args, comm_size);
}
int MPI_Iallgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return c_MPI_Iallgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request); }
extern void f_mpi_iallgatherv(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Iallgatherv(sendbuf, (*sendcount), c_handle_0, recvbuf, recvcounts, displs, c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_IALLGATHERV(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iallgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierr);
}
extern void mpi_iallgatherv(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iallgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierr);
}
extern void mpi_iallgatherv_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iallgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierr);
}
extern void mpi_iallgatherv__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iallgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierr);
}
int c_MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ibcast, (buffer, count, datatype, root, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(buffer, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(5, &mem_attr_0, &count, &obj_id_0, &root, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Request *request) { return c_MPI_Ibcast(buffer, count, datatype, root, comm, request); }
extern void f_mpi_ibcast(void* buffer, int* count, MPI_Fint* datatype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_Ibcast(buffer, (*count), c_handle_0, (*root), c_handle_1, &c_handle_2);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_IBCAST(void* buffer, int* count, MPI_Fint* datatype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ibcast(buffer, count, datatype, root, comm, request, ierr);
}
extern void mpi_ibcast(void* buffer, int* count, MPI_Fint* datatype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ibcast(buffer, count, datatype, root, comm, request, ierr);
}
extern void mpi_ibcast_(void* buffer, int* count, MPI_Fint* datatype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ibcast(buffer, count, datatype, root, comm, request, ierr);
}
extern void mpi_ibcast__(void* buffer, int* count, MPI_Fint* datatype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ibcast(buffer, count, datatype, root, comm, request, ierr);
}
int c_MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype)
{
	PILGRIM_TRACING_1(int, MPI_File_read_at_all_begin, (fh, offset, buf, count, datatype));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	append_offset(offset);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(4, &obj_id_0, &mem_attr_0, &count, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype) { return c_MPI_File_read_at_all_begin(fh, offset, buf, count, datatype); }
extern void f_mpi_file_read_at_all_begin(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	c_MPI_File_read_at_all_begin(c_handle_0, offset, buf, (*count), c_handle_1);
}
extern void MPI_FILE_READ_AT_ALL_BEGIN(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_read_at_all_begin(fh, offset, buf, count, datatype, ierr);
}
extern void mpi_file_read_at_all_begin(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_read_at_all_begin(fh, offset, buf, count, datatype, ierr);
}
extern void mpi_file_read_at_all_begin_(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_read_at_all_begin(fh, offset, buf, count, datatype, ierr);
}
extern void mpi_file_read_at_all_begin__(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_read_at_all_begin(fh, offset, buf, count, datatype, ierr);
}
int c_MPI_Info_get_nthkey(MPI_Info info, int n, char *key)
{
	PILGRIM_TRACING_1(int, MPI_Info_get_nthkey, (info, n, key));
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	void **args = assemble_args_list(3, &obj_id_0, &n, key);
	int sizes[] = { sizeof(int), sizeof(int), strlen(key)+1 };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Info_get_nthkey(MPI_Info info, int n, char *key) { return c_MPI_Info_get_nthkey(info, n, key); }
extern void f_mpi_info_get_nthkey(MPI_Fint* info, int* n, char* key, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	c_MPI_Info_get_nthkey(c_handle_0, (*n), key);
}
extern void MPI_INFO_GET_NTHKEY(MPI_Fint* info, int* n, char* key, MPI_Fint *ierr) {
	f_mpi_info_get_nthkey(info, n, key, ierr);
}
extern void mpi_info_get_nthkey(MPI_Fint* info, int* n, char* key, MPI_Fint *ierr) {
	f_mpi_info_get_nthkey(info, n, key, ierr);
}
extern void mpi_info_get_nthkey_(MPI_Fint* info, int* n, char* key, MPI_Fint *ierr) {
	f_mpi_info_get_nthkey(info, n, key, ierr);
}
extern void mpi_info_get_nthkey__(MPI_Fint* info, int* n, char* key, MPI_Fint *ierr) {
	f_mpi_info_get_nthkey(info, n, key, ierr);
}
int c_MPI_File_get_size(MPI_File fh, MPI_Offset *size)
{
	PILGRIM_TRACING_1(int, MPI_File_get_size, (fh, size));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, size);
	int sizes[] = { sizeof(int), 1*sizeof(MPI_Offset) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_get_size(MPI_File fh, MPI_Offset *size) { return c_MPI_File_get_size(fh, size); }
extern void f_mpi_file_get_size(MPI_Fint* fh, MPI_Offset* size, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	c_MPI_File_get_size(c_handle_0, size);
}
extern void MPI_FILE_GET_SIZE(MPI_Fint* fh, MPI_Offset* size, MPI_Fint *ierr) {
	f_mpi_file_get_size(fh, size, ierr);
}
extern void mpi_file_get_size(MPI_Fint* fh, MPI_Offset* size, MPI_Fint *ierr) {
	f_mpi_file_get_size(fh, size, ierr);
}
extern void mpi_file_get_size_(MPI_Fint* fh, MPI_Offset* size, MPI_Fint *ierr) {
	f_mpi_file_get_size(fh, size, ierr);
}
extern void mpi_file_get_size__(MPI_Fint* fh, MPI_Offset* size, MPI_Fint *ierr) {
	f_mpi_file_get_size(fh, size, ierr);
}
int c_MPI_Rput(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Rput, (origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request));
	MemPtrAttr mem_attr_0;
	addr2id(origin_addr, &mem_attr_0);
	MPI_Datatype obj_0 = origin_datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Datatype obj_1 = target_datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Win obj_2 = win;
	int obj_id_2 = MPI_OBJ_ID(MPI_Win, &obj_2);
	void **args = assemble_args_list(8, &mem_attr_0, &origin_count, &obj_id_0, &target_rank, &target_disp, &target_count, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(8, sizes, args, -1);
}
int MPI_Rput(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request) { return c_MPI_Rput(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request); }
extern void f_mpi_rput(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*origin_datatype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*target_datatype);
	MPI_Win c_handle_2;
	c_handle_2 = PMPI_Win_f2c(*win);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Rput(origin_addr, (*origin_count), c_handle_0, (*target_rank), target_disp, (*target_count), c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_RPUT(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_rput(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierr);
}
extern void mpi_rput(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_rput(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierr);
}
extern void mpi_rput_(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_rput(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierr);
}
extern void mpi_rput__(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_rput(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierr);
}
int c_MPI_Type_indexed(int count, const int array_of_blocklengths[], const int array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_indexed, (count, array_of_blocklengths, array_of_displacements, oldtype, newtype));
	MPI_Datatype obj_0 = oldtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, newtype);
	void **args = assemble_args_list(5, &count, array_of_blocklengths, array_of_displacements, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), count*sizeof(const int), count*sizeof(const int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Type_indexed(int count, const int array_of_blocklengths[], const int array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { return c_MPI_Type_indexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype); }
extern void f_mpi_type_indexed(int* count, const int array_of_blocklengths[], const int array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*oldtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*newtype);
	c_MPI_Type_indexed((*count), array_of_blocklengths, array_of_displacements, c_handle_0, &c_handle_1);
	*newtype = PMPI_Type_c2f(c_handle_1);
}
extern void MPI_TYPE_INDEXED(int* count, const int array_of_blocklengths[], const int array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_indexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierr);
}
extern void mpi_type_indexed(int* count, const int array_of_blocklengths[], const int array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_indexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierr);
}
extern void mpi_type_indexed_(int* count, const int array_of_blocklengths[], const int array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_indexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierr);
}
extern void mpi_type_indexed__(int* count, const int array_of_blocklengths[], const int array_of_displacements[], MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_indexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierr);
}
int c_MPI_Send_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Send_init, (buf, count, datatype, dest, tag, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int dest_rank = g_mpi_rank - dest;
	if(dest == MPI_ANY_SOURCE) dest_rank = PILGRIM_MPI_ANY_SOURCE;
	if(dest == MPI_PROC_NULL) dest_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(6, &mem_attr_0, &count, &obj_id_0, &dest_rank, &my_tag, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Send_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return c_MPI_Send_init(buf, count, datatype, dest, tag, comm, request); }
extern void f_mpi_send_init(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_Send_init(buf, (*count), c_handle_0, (*dest), (*tag), c_handle_1, &c_handle_2);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_SEND_INIT(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_send_init(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_send_init(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_send_init(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_send_init_(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_send_init(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_send_init__(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_send_init(buf, count, datatype, dest, tag, comm, request, ierr);
}
int c_MPI_File_write(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write, (fh, buf, count, datatype, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	int status_arg[2] = {0};
	void **args = assemble_args_list(5, &obj_id_0, &mem_attr_0, &count, &obj_id_1, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_File_write(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return c_MPI_File_write(fh, buf, count, datatype, status); }
extern void f_mpi_file_write(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_File_write(c_handle_0, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_FILE_WRITE(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_write(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_write_(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_write__(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write(fh, buf, count, datatype, status, ierr);
}
int c_MPI_File_set_info(MPI_File fh, MPI_Info info)
{
	PILGRIM_TRACING_1(int, MPI_File_set_info, (fh, info));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MPI_Info obj_1 = info;
	int obj_id_1 = MPI_OBJ_ID(MPI_Info, &obj_1);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_set_info(MPI_File fh, MPI_Info info) { return c_MPI_File_set_info(fh, info); }
extern void f_mpi_file_set_info(MPI_Fint* fh, MPI_Fint* info, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Info c_handle_1;
	c_handle_1 = PMPI_Info_f2c(*info);
	c_MPI_File_set_info(c_handle_0, c_handle_1);
	*fh = PMPI_File_c2f(c_handle_0);
}
extern void MPI_FILE_SET_INFO(MPI_Fint* fh, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_file_set_info(fh, info, ierr);
}
extern void mpi_file_set_info(MPI_Fint* fh, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_file_set_info(fh, info, ierr);
}
extern void mpi_file_set_info_(MPI_Fint* fh, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_file_set_info(fh, info, ierr);
}
extern void mpi_file_set_info__(MPI_Fint* fh, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_file_set_info(fh, info, ierr);
}
int c_MPI_File_set_atomicity(MPI_File fh, int flag)
{
	PILGRIM_TRACING_1(int, MPI_File_set_atomicity, (fh, flag));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, &flag);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_set_atomicity(MPI_File fh, int flag) { return c_MPI_File_set_atomicity(fh, flag); }
extern void f_mpi_file_set_atomicity(MPI_Fint* fh, int* flag, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	c_MPI_File_set_atomicity(c_handle_0, (*flag));
	*fh = PMPI_File_c2f(c_handle_0);
}
extern void MPI_FILE_SET_ATOMICITY(MPI_Fint* fh, int* flag, MPI_Fint *ierr) {
	f_mpi_file_set_atomicity(fh, flag, ierr);
}
extern void mpi_file_set_atomicity(MPI_Fint* fh, int* flag, MPI_Fint *ierr) {
	f_mpi_file_set_atomicity(fh, flag, ierr);
}
extern void mpi_file_set_atomicity_(MPI_Fint* fh, int* flag, MPI_Fint *ierr) {
	f_mpi_file_set_atomicity(fh, flag, ierr);
}
extern void mpi_file_set_atomicity__(MPI_Fint* fh, int* flag, MPI_Fint *ierr) {
	f_mpi_file_set_atomicity(fh, flag, ierr);
}
int c_MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges, int index[], int edges[])
{
	PILGRIM_TRACING_1(int, MPI_Graph_get, (comm, maxindex, maxedges, index, edges));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(5, &obj_id_0, &maxindex, &maxedges, index, edges);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), maxindex*sizeof(int), maxedges*sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges, int index[], int edges[]) { return c_MPI_Graph_get(comm, maxindex, maxedges, index, edges); }
extern void f_mpi_graph_get(MPI_Fint* comm, int* maxindex, int* maxedges, int index[], int edges[], MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Graph_get(c_handle_0, (*maxindex), (*maxedges), index, edges);
}
extern void MPI_GRAPH_GET(MPI_Fint* comm, int* maxindex, int* maxedges, int index[], int edges[], MPI_Fint *ierr) {
	f_mpi_graph_get(comm, maxindex, maxedges, index, edges, ierr);
}
extern void mpi_graph_get(MPI_Fint* comm, int* maxindex, int* maxedges, int index[], int edges[], MPI_Fint *ierr) {
	f_mpi_graph_get(comm, maxindex, maxedges, index, edges, ierr);
}
extern void mpi_graph_get_(MPI_Fint* comm, int* maxindex, int* maxedges, int index[], int edges[], MPI_Fint *ierr) {
	f_mpi_graph_get(comm, maxindex, maxedges, index, edges, ierr);
}
extern void mpi_graph_get__(MPI_Fint* comm, int* maxindex, int* maxedges, int index[], int edges[], MPI_Fint *ierr) {
	f_mpi_graph_get(comm, maxindex, maxedges, index, edges, ierr);
}
int c_MPI_Pack_external_size(const char datarep[], int incount, MPI_Datatype datatype, MPI_Aint *size)
{
	PILGRIM_TRACING_1(int, MPI_Pack_external_size, (datarep, incount, datatype, size));
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	void **args = assemble_args_list(4, datarep, &incount, &obj_id_0, size);
	int sizes[] = { strlen(datarep)+1, sizeof(int), sizeof(int), 1*sizeof(MPI_Aint) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Pack_external_size(const char datarep[], int incount, MPI_Datatype datatype, MPI_Aint *size) { return c_MPI_Pack_external_size(datarep, incount, datatype, size); }
extern void f_mpi_pack_external_size(const char datarep[], int* incount, MPI_Fint* datatype, MPI_Aint* size, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Pack_external_size(datarep, (*incount), c_handle_0, size);
}
extern void MPI_PACK_EXTERNAL_SIZE(const char datarep[], int* incount, MPI_Fint* datatype, MPI_Aint* size, MPI_Fint *ierr) {
	f_mpi_pack_external_size(datarep, incount, datatype, size, ierr);
}
extern void mpi_pack_external_size(const char datarep[], int* incount, MPI_Fint* datatype, MPI_Aint* size, MPI_Fint *ierr) {
	f_mpi_pack_external_size(datarep, incount, datatype, size, ierr);
}
extern void mpi_pack_external_size_(const char datarep[], int* incount, MPI_Fint* datatype, MPI_Aint* size, MPI_Fint *ierr) {
	f_mpi_pack_external_size(datarep, incount, datatype, size, ierr);
}
extern void mpi_pack_external_size__(const char datarep[], int* incount, MPI_Fint* datatype, MPI_Aint* size, MPI_Fint *ierr) {
	f_mpi_pack_external_size(datarep, incount, datatype, size, ierr);
}
int c_MPI_Type_create_darray(int size, int rank, int ndims, const int array_of_gsizes[], const int array_of_distribs[], const int array_of_dargs[], const int array_of_psizes[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_darray, (size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype));
	MPI_Datatype obj_0 = oldtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, newtype);
	void **args = assemble_args_list(10, &size, &rank, &ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, &order, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), ndims*sizeof(const int), ndims*sizeof(const int), ndims*sizeof(const int), ndims*sizeof(const int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(10, sizes, args, -1);
}
int MPI_Type_create_darray(int size, int rank, int ndims, const int array_of_gsizes[], const int array_of_distribs[], const int array_of_dargs[], const int array_of_psizes[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype) { return c_MPI_Type_create_darray(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype); }
extern void f_mpi_type_create_darray(int* size, int* rank, int* ndims, const int array_of_gsizes[], const int array_of_distribs[], const int array_of_dargs[], const int array_of_psizes[], int* order, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*oldtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*newtype);
	c_MPI_Type_create_darray((*size), (*rank), (*ndims), array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, (*order), c_handle_0, &c_handle_1);
	*newtype = PMPI_Type_c2f(c_handle_1);
}
extern void MPI_TYPE_CREATE_DARRAY(int* size, int* rank, int* ndims, const int array_of_gsizes[], const int array_of_distribs[], const int array_of_dargs[], const int array_of_psizes[], int* order, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_darray(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype, ierr);
}
extern void mpi_type_create_darray(int* size, int* rank, int* ndims, const int array_of_gsizes[], const int array_of_distribs[], const int array_of_dargs[], const int array_of_psizes[], int* order, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_darray(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype, ierr);
}
extern void mpi_type_create_darray_(int* size, int* rank, int* ndims, const int array_of_gsizes[], const int array_of_distribs[], const int array_of_dargs[], const int array_of_psizes[], int* order, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_darray(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype, ierr);
}
extern void mpi_type_create_darray__(int* size, int* rank, int* ndims, const int array_of_gsizes[], const int array_of_distribs[], const int array_of_dargs[], const int array_of_psizes[], int* order, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_darray(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype, ierr);
}
int c_MPI_Win_set_errhandler(MPI_Win win, MPI_Errhandler errhandler)
{
	PILGRIM_TRACING_1(int, MPI_Win_set_errhandler, (win, errhandler));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	MPI_Errhandler obj_1 = errhandler;
	int obj_id_1 = MPI_OBJ_ID(MPI_Errhandler, &obj_1);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Win_set_errhandler(MPI_Win win, MPI_Errhandler errhandler) { return c_MPI_Win_set_errhandler(win, errhandler); }
extern void f_mpi_win_set_errhandler(MPI_Fint* win, MPI_Fint* errhandler, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	MPI_Errhandler c_handle_1;
	c_handle_1 = PMPI_Errhandler_f2c(*errhandler);
	c_MPI_Win_set_errhandler(c_handle_0, c_handle_1);
	*win = PMPI_Win_c2f(c_handle_0);
}
extern void MPI_WIN_SET_ERRHANDLER(MPI_Fint* win, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_win_set_errhandler(win, errhandler, ierr);
}
extern void mpi_win_set_errhandler(MPI_Fint* win, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_win_set_errhandler(win, errhandler, ierr);
}
extern void mpi_win_set_errhandler_(MPI_Fint* win, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_win_set_errhandler(win, errhandler, ierr);
}
extern void mpi_win_set_errhandler__(MPI_Fint* win, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_win_set_errhandler(win, errhandler, ierr);
}
int c_MPI_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn, MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval, void *extra_state)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_keyval, (type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state));
	MemPtrAttr mem_attr_0;
	addr2id(extra_state, &mem_attr_0);
	void **args = assemble_args_list(4, type_copy_attr_fn, type_delete_attr_fn, type_keyval, &mem_attr_0);
	int sizes[] = { 1*sizeof(MPI_Type_copy_attr_function), 1*sizeof(MPI_Type_delete_attr_function), 1*sizeof(int), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn, MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval, void *extra_state) { return c_MPI_Type_create_keyval(type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state); }
extern void f_mpi_type_create_keyval(MPI_Type_copy_attr_function* type_copy_attr_fn, MPI_Type_delete_attr_function* type_delete_attr_fn, int* type_keyval, void* extra_state, MPI_Fint *ierr) {
	c_MPI_Type_create_keyval(type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state);
}
extern void MPI_TYPE_CREATE_KEYVAL(MPI_Type_copy_attr_function* type_copy_attr_fn, MPI_Type_delete_attr_function* type_delete_attr_fn, int* type_keyval, void* extra_state, MPI_Fint *ierr) {
	f_mpi_type_create_keyval(type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state, ierr);
}
extern void mpi_type_create_keyval(MPI_Type_copy_attr_function* type_copy_attr_fn, MPI_Type_delete_attr_function* type_delete_attr_fn, int* type_keyval, void* extra_state, MPI_Fint *ierr) {
	f_mpi_type_create_keyval(type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state, ierr);
}
extern void mpi_type_create_keyval_(MPI_Type_copy_attr_function* type_copy_attr_fn, MPI_Type_delete_attr_function* type_delete_attr_fn, int* type_keyval, void* extra_state, MPI_Fint *ierr) {
	f_mpi_type_create_keyval(type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state, ierr);
}
extern void mpi_type_create_keyval__(MPI_Type_copy_attr_function* type_copy_attr_fn, MPI_Type_delete_attr_function* type_delete_attr_fn, int* type_keyval, void* extra_state, MPI_Fint *ierr) {
	f_mpi_type_create_keyval(type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state, ierr);
}
int c_MPI_Comm_accept(const char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_accept, (port_name, info, root, comm, newcomm));
	generate_intercomm_id(comm, newcomm, 0);
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, newcomm);
	void **args = assemble_args_list(5, port_name, &obj_id_0, &root, &obj_id_1, &obj_id_2);
	int sizes[] = { strlen(port_name)+1, sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Comm_accept(const char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm) { return c_MPI_Comm_accept(port_name, info, root, comm, newcomm); }
extern void f_mpi_comm_accept(const char* port_name, MPI_Fint* info, int* root, MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*newcomm);
	c_MPI_Comm_accept(port_name, c_handle_0, (*root), c_handle_1, &c_handle_2);
	*newcomm = PMPI_Comm_c2f(c_handle_2);
}
extern void MPI_COMM_ACCEPT(const char* port_name, MPI_Fint* info, int* root, MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_accept(port_name, info, root, comm, newcomm, ierr);
}
extern void mpi_comm_accept(const char* port_name, MPI_Fint* info, int* root, MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_accept(port_name, info, root, comm, newcomm, ierr);
}
extern void mpi_comm_accept_(const char* port_name, MPI_Fint* info, int* root, MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_accept(port_name, info, root, comm, newcomm, ierr);
}
extern void mpi_comm_accept__(const char* port_name, MPI_Fint* info, int* root, MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_accept(port_name, info, root, comm, newcomm, ierr);
}
int c_MPI_Type_create_struct(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], const MPI_Datatype array_of_types[], MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_struct, (count, array_of_blocklengths, array_of_displacements, array_of_types, newtype));
	int obj_id_0[count];
	for(int i=0; i<count; i++) obj_id_0[i] = (array_of_types==NULL) ? PILGRIM_INVALID_MPI_OBJECT_ID: MPI_OBJ_ID(MPI_Datatype, &array_of_types[i]);
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, newtype);
	void **args = assemble_args_list(5, &count, array_of_blocklengths, array_of_displacements, obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), count*sizeof(const int), count*sizeof(const MPI_Aint), count*sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Type_create_struct(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], const MPI_Datatype array_of_types[], MPI_Datatype *newtype) { return c_MPI_Type_create_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype); }
extern void f_mpi_type_create_struct(int* count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Fint* array_of_types, MPI_Fint* newtype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0[*count];
	for(int i = 0; i < *count; i++) c_handle_0[i] = PMPI_Type_f2c(array_of_types[i]);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*newtype);
	c_MPI_Type_create_struct((*count), array_of_blocklengths, array_of_displacements, c_handle_0, &c_handle_1);
	*newtype = PMPI_Type_c2f(c_handle_1);
}
extern void MPI_TYPE_CREATE_STRUCT(int* count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Fint* array_of_types, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype, ierr);
}
extern void mpi_type_create_struct(int* count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Fint* array_of_types, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype, ierr);
}
extern void mpi_type_create_struct_(int* count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Fint* array_of_types, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype, ierr);
}
extern void mpi_type_create_struct__(int* count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Fint* array_of_types, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype, ierr);
}
int c_MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Gather, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(8, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, &recvcount, &obj_id_1, &root, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(8, sizes, args, -1);
}
int MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { return c_MPI_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm); }
extern void f_mpi_gather(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Gather(sendbuf, (*sendcount), c_handle_0, recvbuf, (*recvcount), c_handle_1, (*root), c_handle_2);
}
extern void MPI_GATHER(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}
extern void mpi_gather(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}
extern void mpi_gather_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}
extern void mpi_gather__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}
int c_MPI_Close_port(const char *port_name)
{
	PILGRIM_TRACING_1(int, MPI_Close_port, (port_name));
	void **args = assemble_args_list(1, port_name);
	int sizes[] = { strlen(port_name)+1 };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Close_port(const char *port_name) { return c_MPI_Close_port(port_name); }
extern void f_mpi_close_port(const char* port_name, MPI_Fint *ierr) {
	c_MPI_Close_port(port_name);
}
extern void MPI_CLOSE_PORT(const char* port_name, MPI_Fint *ierr) {
	f_mpi_close_port(port_name, ierr);
}
extern void mpi_close_port(const char* port_name, MPI_Fint *ierr) {
	f_mpi_close_port(port_name, ierr);
}
extern void mpi_close_port_(const char* port_name, MPI_Fint *ierr) {
	f_mpi_close_port(port_name, ierr);
}
extern void mpi_close_port__(const char* port_name, MPI_Fint *ierr) {
	f_mpi_close_port(port_name, ierr);
}
int c_MPI_Win_sync(MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_sync, (win));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(1, &obj_id_0);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Win_sync(MPI_Win win) { return c_MPI_Win_sync(win); }
extern void f_mpi_win_sync(MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_sync(c_handle_0);
}
extern void MPI_WIN_SYNC(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_sync(win, ierr);
}
extern void mpi_win_sync(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_sync(win, ierr);
}
extern void mpi_win_sync_(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_sync(win, ierr);
}
extern void mpi_win_sync__(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_sync(win, ierr);
}
int c_MPI_Type_create_subarray(int ndims, const int array_of_sizes[], const int array_of_subsizes[], const int array_of_starts[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_subarray, (ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype));
	MPI_Datatype obj_0 = oldtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, newtype);
	void **args = assemble_args_list(7, &ndims, array_of_sizes, array_of_subsizes, array_of_starts, &order, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), ndims*sizeof(const int), ndims*sizeof(const int), ndims*sizeof(const int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Type_create_subarray(int ndims, const int array_of_sizes[], const int array_of_subsizes[], const int array_of_starts[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype) { return c_MPI_Type_create_subarray(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype); }
extern void f_mpi_type_create_subarray(int* ndims, const int array_of_sizes[], const int array_of_subsizes[], const int array_of_starts[], int* order, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*oldtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*newtype);
	c_MPI_Type_create_subarray((*ndims), array_of_sizes, array_of_subsizes, array_of_starts, (*order), c_handle_0, &c_handle_1);
	*newtype = PMPI_Type_c2f(c_handle_1);
}
extern void MPI_TYPE_CREATE_SUBARRAY(int* ndims, const int array_of_sizes[], const int array_of_subsizes[], const int array_of_starts[], int* order, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_subarray(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype, ierr);
}
extern void mpi_type_create_subarray(int* ndims, const int array_of_sizes[], const int array_of_subsizes[], const int array_of_starts[], int* order, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_subarray(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype, ierr);
}
extern void mpi_type_create_subarray_(int* ndims, const int array_of_sizes[], const int array_of_subsizes[], const int array_of_starts[], int* order, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_subarray(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype, ierr);
}
extern void mpi_type_create_subarray__(int* ndims, const int array_of_sizes[], const int array_of_subsizes[], const int array_of_starts[], int* order, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_subarray(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype, ierr);
}
int c_MPI_Win_free_keyval(int *win_keyval)
{
	PILGRIM_TRACING_1(int, MPI_Win_free_keyval, (win_keyval));
	void **args = assemble_args_list(1, win_keyval);
	int sizes[] = { 1*sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Win_free_keyval(int *win_keyval) { return c_MPI_Win_free_keyval(win_keyval); }
extern void f_mpi_win_free_keyval(int* win_keyval, MPI_Fint *ierr) {
	c_MPI_Win_free_keyval(win_keyval);
}
extern void MPI_WIN_FREE_KEYVAL(int* win_keyval, MPI_Fint *ierr) {
	f_mpi_win_free_keyval(win_keyval, ierr);
}
extern void mpi_win_free_keyval(int* win_keyval, MPI_Fint *ierr) {
	f_mpi_win_free_keyval(win_keyval, ierr);
}
extern void mpi_win_free_keyval_(int* win_keyval, MPI_Fint *ierr) {
	f_mpi_win_free_keyval(win_keyval, ierr);
}
extern void mpi_win_free_keyval__(int* win_keyval, MPI_Fint *ierr) {
	f_mpi_win_free_keyval(win_keyval, ierr);
}
int c_MPI_File_write_at_all_end(MPI_File fh, const void *buf, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write_at_all_end, (fh, buf, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	int status_arg[2] = {0};
	void **args = assemble_args_list(3, &obj_id_0, &mem_attr_0, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int)*2 };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_File_write_at_all_end(MPI_File fh, const void *buf, MPI_Status *status) { return c_MPI_File_write_at_all_end(fh, buf, status); }
extern void f_mpi_file_write_at_all_end(MPI_Fint* fh, const void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Status c_handle_1;
	PMPI_Status_f2c(status, &c_handle_1);
	c_MPI_File_write_at_all_end(c_handle_0, buf, &c_handle_1);
	*fh = PMPI_File_c2f(c_handle_0);
	PMPI_Status_c2f(&c_handle_1, status);
}
extern void MPI_FILE_WRITE_AT_ALL_END(MPI_Fint* fh, const void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_at_all_end(fh, buf, status, ierr);
}
extern void mpi_file_write_at_all_end(MPI_Fint* fh, const void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_at_all_end(fh, buf, status, ierr);
}
extern void mpi_file_write_at_all_end_(MPI_Fint* fh, const void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_at_all_end(fh, buf, status, ierr);
}
extern void mpi_file_write_at_all_end__(MPI_Fint* fh, const void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_at_all_end(fh, buf, status, ierr);
}
int c_MPI_Rget_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Rget_accumulate, (origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request));
	MemPtrAttr mem_attr_0;
	addr2id(origin_addr, &mem_attr_0);
	MPI_Datatype obj_0 = origin_datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(result_addr, &mem_attr_1);
	MPI_Datatype obj_1 = result_datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Datatype obj_2 = target_datatype;
	int obj_id_2 = MPI_OBJ_ID(MPI_Datatype, &obj_2);
	MPI_Op obj_3 = op;
	int obj_id_3 = MPI_OBJ_ID(MPI_Op, &obj_3);
	MPI_Win obj_4 = win;
	int obj_id_4 = MPI_OBJ_ID(MPI_Win, &obj_4);
	void **args = assemble_args_list(12, &mem_attr_0, &origin_count, &obj_id_0, &mem_attr_1, &result_count, &obj_id_1, &target_rank, &target_disp, &target_count, &obj_id_2, &obj_id_3, &obj_id_4);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(12, sizes, args, -1);
}
int MPI_Rget_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request) { return c_MPI_Rget_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request); }
extern void f_mpi_rget_accumulate(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, void* result_addr, int* result_count, MPI_Fint* result_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*origin_datatype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*result_datatype);
	MPI_Datatype c_handle_2;
	c_handle_2 = PMPI_Type_f2c(*target_datatype);
	MPI_Op c_handle_3;
	c_handle_3 = PMPI_Op_f2c(*op);
	MPI_Win c_handle_4;
	c_handle_4 = PMPI_Win_f2c(*win);
	MPI_Request c_handle_5;
	c_handle_5 = PMPI_Request_f2c(*request);
	c_MPI_Rget_accumulate(origin_addr, (*origin_count), c_handle_0, result_addr, (*result_count), c_handle_1, (*target_rank), target_disp, (*target_count), c_handle_2, c_handle_3, c_handle_4, &c_handle_5);
	*request = PMPI_Request_c2f(c_handle_5);
}
extern void MPI_RGET_ACCUMULATE(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, void* result_addr, int* result_count, MPI_Fint* result_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_rget_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierr);
}
extern void mpi_rget_accumulate(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, void* result_addr, int* result_count, MPI_Fint* result_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_rget_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierr);
}
extern void mpi_rget_accumulate_(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, void* result_addr, int* result_count, MPI_Fint* result_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_rget_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierr);
}
extern void mpi_rget_accumulate__(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, void* result_addr, int* result_count, MPI_Fint* result_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_rget_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierr);
}
int c_MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval)
{
	PILGRIM_TRACING_1(int, MPI_Comm_delete_attr, (comm, comm_keyval));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, &comm_keyval);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval) { return c_MPI_Comm_delete_attr(comm, comm_keyval); }
extern void f_mpi_comm_delete_attr(MPI_Fint* comm, int* comm_keyval, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Comm_delete_attr(c_handle_0, (*comm_keyval));
	*comm = PMPI_Comm_c2f(c_handle_0);
}
extern void MPI_COMM_DELETE_ATTR(MPI_Fint* comm, int* comm_keyval, MPI_Fint *ierr) {
	f_mpi_comm_delete_attr(comm, comm_keyval, ierr);
}
extern void mpi_comm_delete_attr(MPI_Fint* comm, int* comm_keyval, MPI_Fint *ierr) {
	f_mpi_comm_delete_attr(comm, comm_keyval, ierr);
}
extern void mpi_comm_delete_attr_(MPI_Fint* comm, int* comm_keyval, MPI_Fint *ierr) {
	f_mpi_comm_delete_attr(comm, comm_keyval, ierr);
}
extern void mpi_comm_delete_attr__(MPI_Fint* comm, int* comm_keyval, MPI_Fint *ierr) {
	f_mpi_comm_delete_attr(comm, comm_keyval, ierr);
}
int c_MPI_Comm_create_errhandler(MPI_Comm_errhandler_function *comm_errhandler_fn, MPI_Errhandler *errhandler)
{
	PILGRIM_TRACING_1(int, MPI_Comm_create_errhandler, (comm_errhandler_fn, errhandler));
	int obj_id_0 = MPI_OBJ_ID(MPI_Errhandler, errhandler);
	void **args = assemble_args_list(2, comm_errhandler_fn, &obj_id_0);
	int sizes[] = { 1*sizeof(MPI_Comm_errhandler_function), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_create_errhandler(MPI_Comm_errhandler_function *comm_errhandler_fn, MPI_Errhandler *errhandler) { return c_MPI_Comm_create_errhandler(comm_errhandler_fn, errhandler); }
extern void f_mpi_comm_create_errhandler(MPI_Comm_errhandler_function* comm_errhandler_fn, MPI_Fint* errhandler, MPI_Fint *ierr) {
	MPI_Errhandler c_handle_0;
	c_handle_0 = PMPI_Errhandler_f2c(*errhandler);
	c_MPI_Comm_create_errhandler(comm_errhandler_fn, &c_handle_0);
	*errhandler = PMPI_Errhandler_c2f(c_handle_0);
}
extern void MPI_COMM_CREATE_ERRHANDLER(MPI_Comm_errhandler_function* comm_errhandler_fn, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_comm_create_errhandler(comm_errhandler_fn, errhandler, ierr);
}
extern void mpi_comm_create_errhandler(MPI_Comm_errhandler_function* comm_errhandler_fn, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_comm_create_errhandler(comm_errhandler_fn, errhandler, ierr);
}
extern void mpi_comm_create_errhandler_(MPI_Comm_errhandler_function* comm_errhandler_fn, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_comm_create_errhandler(comm_errhandler_fn, errhandler, ierr);
}
extern void mpi_comm_create_errhandler__(MPI_Comm_errhandler_function* comm_errhandler_fn, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_comm_create_errhandler(comm_errhandler_fn, errhandler, ierr);
}
int c_MPI_Barrier(MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Barrier, (comm));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(1, &obj_id_0);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Barrier(MPI_Comm comm) { return c_MPI_Barrier(comm); }
extern void f_mpi_barrier(MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Barrier(c_handle_0);
}
extern void MPI_BARRIER(MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_barrier(comm, ierr);
}
extern void mpi_barrier(MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_barrier(comm, ierr);
}
extern void mpi_barrier_(MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_barrier(comm, ierr);
}
extern void mpi_barrier__(MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_barrier(comm, ierr);
}
int c_MPI_Win_get_attr(MPI_Win win, int win_keyval, void *attribute_val, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Win_get_attr, (win, win_keyval, attribute_val, flag));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(attribute_val, &mem_attr_0);
	void **args = assemble_args_list(4, &obj_id_0, &win_keyval, &mem_attr_0, flag);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MemPtrAttr), 1*sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Win_get_attr(MPI_Win win, int win_keyval, void *attribute_val, int *flag) { return c_MPI_Win_get_attr(win, win_keyval, attribute_val, flag); }
extern void f_mpi_win_get_attr(MPI_Fint* win, int* win_keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_get_attr(c_handle_0, (*win_keyval), attribute_val, flag);
}
extern void MPI_WIN_GET_ATTR(MPI_Fint* win, int* win_keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	f_mpi_win_get_attr(win, win_keyval, attribute_val, flag, ierr);
}
extern void mpi_win_get_attr(MPI_Fint* win, int* win_keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	f_mpi_win_get_attr(win, win_keyval, attribute_val, flag, ierr);
}
extern void mpi_win_get_attr_(MPI_Fint* win, int* win_keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	f_mpi_win_get_attr(win, win_keyval, attribute_val, flag, ierr);
}
extern void mpi_win_get_attr__(MPI_Fint* win, int* win_keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	f_mpi_win_get_attr(win, win_keyval, attribute_val, flag, ierr);
}
int c_MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp)
{
	PILGRIM_TRACING_1(int, MPI_File_get_byte_offset, (fh, offset, disp));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	append_offset(offset);
	void **args = assemble_args_list(2, &obj_id_0, disp);
	int sizes[] = { sizeof(int), 1*sizeof(MPI_Offset) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp) { return c_MPI_File_get_byte_offset(fh, offset, disp); }
extern void f_mpi_file_get_byte_offset(MPI_Fint* fh, MPI_Offset offset, MPI_Offset* disp, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	c_MPI_File_get_byte_offset(c_handle_0, offset, disp);
}
extern void MPI_FILE_GET_BYTE_OFFSET(MPI_Fint* fh, MPI_Offset offset, MPI_Offset* disp, MPI_Fint *ierr) {
	f_mpi_file_get_byte_offset(fh, offset, disp, ierr);
}
extern void mpi_file_get_byte_offset(MPI_Fint* fh, MPI_Offset offset, MPI_Offset* disp, MPI_Fint *ierr) {
	f_mpi_file_get_byte_offset(fh, offset, disp, ierr);
}
extern void mpi_file_get_byte_offset_(MPI_Fint* fh, MPI_Offset offset, MPI_Offset* disp, MPI_Fint *ierr) {
	f_mpi_file_get_byte_offset(fh, offset, disp, ierr);
}
extern void mpi_file_get_byte_offset__(MPI_Fint* fh, MPI_Offset offset, MPI_Offset* disp, MPI_Fint *ierr) {
	f_mpi_file_get_byte_offset(fh, offset, disp, ierr);
}
int c_MPI_Win_lock_all(int assert, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_lock_all, (assert, win));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(2, &assert, &obj_id_0);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Win_lock_all(int assert, MPI_Win win) { return c_MPI_Win_lock_all(assert, win); }
extern void f_mpi_win_lock_all(int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_lock_all((*assert), c_handle_0);
}
extern void MPI_WIN_LOCK_ALL(int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_lock_all(assert, win, ierr);
}
extern void mpi_win_lock_all(int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_lock_all(assert, win, ierr);
}
extern void mpi_win_lock_all_(int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_lock_all(assert, win, ierr);
}
extern void mpi_win_lock_all__(int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_lock_all(assert, win, ierr);
}
int c_MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen)
{
	PILGRIM_TRACING_1(int, MPI_Comm_get_name, (comm, comm_name, resultlen));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(3, &obj_id_0, comm_name, resultlen);
	int sizes[] = { sizeof(int), strlen(comm_name)+1, 1*sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen) { return c_MPI_Comm_get_name(comm, comm_name, resultlen); }
extern void f_mpi_comm_get_name(MPI_Fint* comm, char* comm_name, int* resultlen, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Comm_get_name(c_handle_0, comm_name, resultlen);
}
extern void MPI_COMM_GET_NAME(MPI_Fint* comm, char* comm_name, int* resultlen, MPI_Fint *ierr) {
	f_mpi_comm_get_name(comm, comm_name, resultlen, ierr);
}
extern void mpi_comm_get_name(MPI_Fint* comm, char* comm_name, int* resultlen, MPI_Fint *ierr) {
	f_mpi_comm_get_name(comm, comm_name, resultlen, ierr);
}
extern void mpi_comm_get_name_(MPI_Fint* comm, char* comm_name, int* resultlen, MPI_Fint *ierr) {
	f_mpi_comm_get_name(comm, comm_name, resultlen, ierr);
}
extern void mpi_comm_get_name__(MPI_Fint* comm, char* comm_name, int* resultlen, MPI_Fint *ierr) {
	f_mpi_comm_get_name(comm, comm_name, resultlen, ierr);
}
int c_MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup)
{
	PILGRIM_TRACING_1(int, MPI_Group_range_excl, (group, n, ranges, newgroup));
	MPI_Group obj_0 = group;
	int obj_id_0 = MPI_OBJ_ID(MPI_Group, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Group, newgroup);
	void **args = assemble_args_list(4, &obj_id_0, &n, ranges, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), n*3*sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup) { return c_MPI_Group_range_excl(group, n, ranges, newgroup); }
extern void f_mpi_group_range_excl(MPI_Fint* group, int* n, int ranges[][3], MPI_Fint* newgroup, MPI_Fint *ierr) {
	MPI_Group c_handle_0;
	c_handle_0 = PMPI_Group_f2c(*group);
	MPI_Group c_handle_1;
	c_handle_1 = PMPI_Group_f2c(*newgroup);
	c_MPI_Group_range_excl(c_handle_0, (*n), ranges, &c_handle_1);
	*newgroup = PMPI_Group_c2f(c_handle_1);
}
extern void MPI_GROUP_RANGE_EXCL(MPI_Fint* group, int* n, int ranges[][3], MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_range_excl(group, n, ranges, newgroup, ierr);
}
extern void mpi_group_range_excl(MPI_Fint* group, int* n, int ranges[][3], MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_range_excl(group, n, ranges, newgroup, ierr);
}
extern void mpi_group_range_excl_(MPI_Fint* group, int* n, int ranges[][3], MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_range_excl(group, n, ranges, newgroup, ierr);
}
extern void mpi_group_range_excl__(MPI_Fint* group, int* n, int ranges[][3], MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_range_excl(group, n, ranges, newgroup, ierr);
}
int c_MPI_T_pvar_handle_alloc(MPI_T_pvar_session session, int pvar_index, void *obj_handle, MPI_T_pvar_handle *handle, int *count)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_handle_alloc, (session, pvar_index, obj_handle, handle, count));
	MemPtrAttr mem_attr_0;
	addr2id(obj_handle, &mem_attr_0);
	void **args = assemble_args_list(5, &session, &pvar_index, &mem_attr_0, handle, count);
	int sizes[] = { sizeof(MPI_T_pvar_session), sizeof(int), sizeof(MemPtrAttr), 1*sizeof(MPI_T_pvar_handle), 1*sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_T_pvar_handle_alloc(MPI_T_pvar_session session, int pvar_index, void *obj_handle, MPI_T_pvar_handle *handle, int *count) { return c_MPI_T_pvar_handle_alloc(session, pvar_index, obj_handle, handle, count); }
int c_MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype)
{
	PILGRIM_TRACING_1(int, MPI_File_read_ordered_begin, (fh, buf, count, datatype));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(4, &obj_id_0, &mem_attr_0, &count, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype) { return c_MPI_File_read_ordered_begin(fh, buf, count, datatype); }
extern void f_mpi_file_read_ordered_begin(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	c_MPI_File_read_ordered_begin(c_handle_0, buf, (*count), c_handle_1);
	*fh = PMPI_File_c2f(c_handle_0);
}
extern void MPI_FILE_READ_ORDERED_BEGIN(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_read_ordered_begin(fh, buf, count, datatype, ierr);
}
extern void mpi_file_read_ordered_begin(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_read_ordered_begin(fh, buf, count, datatype, ierr);
}
extern void mpi_file_read_ordered_begin_(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_read_ordered_begin(fh, buf, count, datatype, ierr);
}
extern void mpi_file_read_ordered_begin__(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_read_ordered_begin(fh, buf, count, datatype, ierr);
}
int c_MPI_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read_ordered, (fh, buf, count, datatype, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	int status_arg[2] = {0};
	void **args = assemble_args_list(5, &obj_id_0, &mem_attr_0, &count, &obj_id_1, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return c_MPI_File_read_ordered(fh, buf, count, datatype, status); }
extern void f_mpi_file_read_ordered(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_File_read_ordered(c_handle_0, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_FILE_READ_ORDERED(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_ordered(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_read_ordered(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_ordered(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_read_ordered_(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_ordered(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_read_ordered__(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_ordered(fh, buf, count, datatype, status, ierr);
}
int c_MPI_Attr_delete(MPI_Comm comm, int keyval)
{
	PILGRIM_TRACING_1(int, MPI_Attr_delete, (comm, keyval));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, &keyval);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Attr_delete(MPI_Comm comm, int keyval) { return c_MPI_Attr_delete(comm, keyval); }
extern void f_mpi_attr_delete(MPI_Fint* comm, int* keyval, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Attr_delete(c_handle_0, (*keyval));
	*comm = PMPI_Comm_c2f(c_handle_0);
}
extern void MPI_ATTR_DELETE(MPI_Fint* comm, int* keyval, MPI_Fint *ierr) {
	f_mpi_attr_delete(comm, keyval, ierr);
}
extern void mpi_attr_delete(MPI_Fint* comm, int* keyval, MPI_Fint *ierr) {
	f_mpi_attr_delete(comm, keyval, ierr);
}
extern void mpi_attr_delete_(MPI_Fint* comm, int* keyval, MPI_Fint *ierr) {
	f_mpi_attr_delete(comm, keyval, ierr);
}
extern void mpi_attr_delete__(MPI_Fint* comm, int* keyval, MPI_Fint *ierr) {
	f_mpi_attr_delete(comm, keyval, ierr);
}
int c_MPI_Win_get_errhandler(MPI_Win win, MPI_Errhandler *errhandler)
{
	PILGRIM_TRACING_1(int, MPI_Win_get_errhandler, (win, errhandler));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Errhandler, errhandler);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Win_get_errhandler(MPI_Win win, MPI_Errhandler *errhandler) { return c_MPI_Win_get_errhandler(win, errhandler); }
extern void f_mpi_win_get_errhandler(MPI_Fint* win, MPI_Fint* errhandler, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	MPI_Errhandler c_handle_1;
	c_handle_1 = PMPI_Errhandler_f2c(*errhandler);
	c_MPI_Win_get_errhandler(c_handle_0, &c_handle_1);
	*errhandler = PMPI_Errhandler_c2f(c_handle_1);
}
extern void MPI_WIN_GET_ERRHANDLER(MPI_Fint* win, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_win_get_errhandler(win, errhandler, ierr);
}
extern void mpi_win_get_errhandler(MPI_Fint* win, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_win_get_errhandler(win, errhandler, ierr);
}
extern void mpi_win_get_errhandler_(MPI_Fint* win, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_win_get_errhandler(win, errhandler, ierr);
}
extern void mpi_win_get_errhandler__(MPI_Fint* win, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_win_get_errhandler(win, errhandler, ierr);
}
int c_MPI_File_get_info(MPI_File fh, MPI_Info *info_used)
{
	PILGRIM_TRACING_1(int, MPI_File_get_info, (fh, info_used));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Info, info_used);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_get_info(MPI_File fh, MPI_Info *info_used) { return c_MPI_File_get_info(fh, info_used); }
extern void f_mpi_file_get_info(MPI_Fint* fh, MPI_Fint* info_used, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Info c_handle_1;
	c_handle_1 = PMPI_Info_f2c(*info_used);
	c_MPI_File_get_info(c_handle_0, &c_handle_1);
	*info_used = PMPI_Info_c2f(c_handle_1);
}
extern void MPI_FILE_GET_INFO(MPI_Fint* fh, MPI_Fint* info_used, MPI_Fint *ierr) {
	f_mpi_file_get_info(fh, info_used, ierr);
}
extern void mpi_file_get_info(MPI_Fint* fh, MPI_Fint* info_used, MPI_Fint *ierr) {
	f_mpi_file_get_info(fh, info_used, ierr);
}
extern void mpi_file_get_info_(MPI_Fint* fh, MPI_Fint* info_used, MPI_Fint *ierr) {
	f_mpi_file_get_info(fh, info_used, ierr);
}
extern void mpi_file_get_info__(MPI_Fint* fh, MPI_Fint* info_used, MPI_Fint *ierr) {
	f_mpi_file_get_info(fh, info_used, ierr);
}
int c_MPI_Info_dup(MPI_Info info, MPI_Info *newinfo)
{
	PILGRIM_TRACING_1(int, MPI_Info_dup, (info, newinfo));
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Info, newinfo);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Info_dup(MPI_Info info, MPI_Info *newinfo) { return c_MPI_Info_dup(info, newinfo); }
extern void f_mpi_info_dup(MPI_Fint* info, MPI_Fint* newinfo, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	MPI_Info c_handle_1;
	c_handle_1 = PMPI_Info_f2c(*newinfo);
	c_MPI_Info_dup(c_handle_0, &c_handle_1);
	*newinfo = PMPI_Info_c2f(c_handle_1);
}
extern void MPI_INFO_DUP(MPI_Fint* info, MPI_Fint* newinfo, MPI_Fint *ierr) {
	f_mpi_info_dup(info, newinfo, ierr);
}
extern void mpi_info_dup(MPI_Fint* info, MPI_Fint* newinfo, MPI_Fint *ierr) {
	f_mpi_info_dup(info, newinfo, ierr);
}
extern void mpi_info_dup_(MPI_Fint* info, MPI_Fint* newinfo, MPI_Fint *ierr) {
	f_mpi_info_dup(info, newinfo, ierr);
}
extern void mpi_info_dup__(MPI_Fint* info, MPI_Fint* newinfo, MPI_Fint *ierr) {
	f_mpi_info_dup(info, newinfo, ierr);
}
int c_MPI_File_write_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write_shared, (fh, buf, count, datatype, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	int status_arg[2] = {0};
	void **args = assemble_args_list(5, &obj_id_0, &mem_attr_0, &count, &obj_id_1, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_File_write_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return c_MPI_File_write_shared(fh, buf, count, datatype, status); }
extern void f_mpi_file_write_shared(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_File_write_shared(c_handle_0, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_FILE_WRITE_SHARED(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_shared(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_write_shared(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_shared(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_write_shared_(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_shared(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_write_shared__(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_shared(fh, buf, count, datatype, status, ierr);
}
int c_MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iread_at, (fh, offset, buf, count, datatype, request));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	append_offset(offset);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(4, &obj_id_0, &mem_attr_0, &count, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return c_MPI_File_iread_at(fh, offset, buf, count, datatype, request); }
extern void f_mpi_file_iread_at(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_File_iread_at(c_handle_0, offset, buf, (*count), c_handle_1, &c_handle_2);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_FILE_IREAD_AT(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread_at(fh, offset, buf, count, datatype, request, ierr);
}
extern void mpi_file_iread_at(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread_at(fh, offset, buf, count, datatype, request, ierr);
}
extern void mpi_file_iread_at_(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread_at(fh, offset, buf, count, datatype, request, ierr);
}
extern void mpi_file_iread_at__(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread_at(fh, offset, buf, count, datatype, request, ierr);
}
int c_MPI_File_write_all_end(MPI_File fh, const void *buf, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write_all_end, (fh, buf, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	int status_arg[2] = {0};
	void **args = assemble_args_list(3, &obj_id_0, &mem_attr_0, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int)*2 };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_File_write_all_end(MPI_File fh, const void *buf, MPI_Status *status) { return c_MPI_File_write_all_end(fh, buf, status); }
extern void f_mpi_file_write_all_end(MPI_Fint* fh, const void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Status c_handle_1;
	PMPI_Status_f2c(status, &c_handle_1);
	c_MPI_File_write_all_end(c_handle_0, buf, &c_handle_1);
	*fh = PMPI_File_c2f(c_handle_0);
	PMPI_Status_c2f(&c_handle_1, status);
}
extern void MPI_FILE_WRITE_ALL_END(MPI_Fint* fh, const void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_all_end(fh, buf, status, ierr);
}
extern void mpi_file_write_all_end(MPI_Fint* fh, const void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_all_end(fh, buf, status, ierr);
}
extern void mpi_file_write_all_end_(MPI_Fint* fh, const void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_all_end(fh, buf, status, ierr);
}
extern void mpi_file_write_all_end__(MPI_Fint* fh, const void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_all_end(fh, buf, status, ierr);
}
int c_MPI_Comm_remote_size(MPI_Comm comm, int *size)
{
	PILGRIM_TRACING_1(int, MPI_Comm_remote_size, (comm, size));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, size);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_remote_size(MPI_Comm comm, int *size) { return c_MPI_Comm_remote_size(comm, size); }
extern void f_mpi_comm_remote_size(MPI_Fint* comm, int* size, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Comm_remote_size(c_handle_0, size);
}
extern void MPI_COMM_REMOTE_SIZE(MPI_Fint* comm, int* size, MPI_Fint *ierr) {
	f_mpi_comm_remote_size(comm, size, ierr);
}
extern void mpi_comm_remote_size(MPI_Fint* comm, int* size, MPI_Fint *ierr) {
	f_mpi_comm_remote_size(comm, size, ierr);
}
extern void mpi_comm_remote_size_(MPI_Fint* comm, int* size, MPI_Fint *ierr) {
	f_mpi_comm_remote_size(comm, size, ierr);
}
extern void mpi_comm_remote_size__(MPI_Fint* comm, int* size, MPI_Fint *ierr) {
	f_mpi_comm_remote_size(comm, size, ierr);
}
int c_MPI_Type_get_name(MPI_Datatype datatype, char *type_name, int *resultlen)
{
	PILGRIM_TRACING_1(int, MPI_Type_get_name, (datatype, type_name, resultlen));
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	void **args = assemble_args_list(3, &obj_id_0, type_name, resultlen);
	int sizes[] = { sizeof(int), strlen(type_name)+1, 1*sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Type_get_name(MPI_Datatype datatype, char *type_name, int *resultlen) { return c_MPI_Type_get_name(datatype, type_name, resultlen); }
extern void f_mpi_type_get_name(MPI_Fint* datatype, char* type_name, int* resultlen, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Type_get_name(c_handle_0, type_name, resultlen);
}
extern void MPI_TYPE_GET_NAME(MPI_Fint* datatype, char* type_name, int* resultlen, MPI_Fint *ierr) {
	f_mpi_type_get_name(datatype, type_name, resultlen, ierr);
}
extern void mpi_type_get_name(MPI_Fint* datatype, char* type_name, int* resultlen, MPI_Fint *ierr) {
	f_mpi_type_get_name(datatype, type_name, resultlen, ierr);
}
extern void mpi_type_get_name_(MPI_Fint* datatype, char* type_name, int* resultlen, MPI_Fint *ierr) {
	f_mpi_type_get_name(datatype, type_name, resultlen, ierr);
}
extern void mpi_type_get_name__(MPI_Fint* datatype, char* type_name, int* resultlen, MPI_Fint *ierr) {
	f_mpi_type_get_name(datatype, type_name, resultlen, ierr);
}
int c_MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write_at_all, (fh, offset, buf, count, datatype, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	append_offset(offset);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	int status_arg[2] = {0};
	void **args = assemble_args_list(5, &obj_id_0, &mem_attr_0, &count, &obj_id_1, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return c_MPI_File_write_at_all(fh, offset, buf, count, datatype, status); }
extern void f_mpi_file_write_at_all(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_File_write_at_all(c_handle_0, offset, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_FILE_WRITE_AT_ALL(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_at_all(fh, offset, buf, count, datatype, status, ierr);
}
extern void mpi_file_write_at_all(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_at_all(fh, offset, buf, count, datatype, status, ierr);
}
extern void mpi_file_write_at_all_(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_at_all(fh, offset, buf, count, datatype, status, ierr);
}
extern void mpi_file_write_at_all__(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_at_all(fh, offset, buf, count, datatype, status, ierr);
}
int c_MPI_File_get_group(MPI_File fh, MPI_Group *group)
{
	PILGRIM_TRACING_1(int, MPI_File_get_group, (fh, group));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Group, group);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_get_group(MPI_File fh, MPI_Group *group) { return c_MPI_File_get_group(fh, group); }
extern void f_mpi_file_get_group(MPI_Fint* fh, MPI_Fint* group, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Group c_handle_1;
	c_handle_1 = PMPI_Group_f2c(*group);
	c_MPI_File_get_group(c_handle_0, &c_handle_1);
	*group = PMPI_Group_c2f(c_handle_1);
}
extern void MPI_FILE_GET_GROUP(MPI_Fint* fh, MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_file_get_group(fh, group, ierr);
}
extern void mpi_file_get_group(MPI_Fint* fh, MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_file_get_group(fh, group, ierr);
}
extern void mpi_file_get_group_(MPI_Fint* fh, MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_file_get_group(fh, group, ierr);
}
extern void mpi_file_get_group__(MPI_Fint* fh, MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_file_get_group(fh, group, ierr);
}
int c_MPI_File_preallocate(MPI_File fh, MPI_Offset size)
{
	PILGRIM_TRACING_1(int, MPI_File_preallocate, (fh, size));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	append_offset(size);
	void **args = assemble_args_list(1, &obj_id_0);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_File_preallocate(MPI_File fh, MPI_Offset size) { return c_MPI_File_preallocate(fh, size); }
extern void f_mpi_file_preallocate(MPI_Fint* fh, MPI_Offset size, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	c_MPI_File_preallocate(c_handle_0, size);
	*fh = PMPI_File_c2f(c_handle_0);
}
extern void MPI_FILE_PREALLOCATE(MPI_Fint* fh, MPI_Offset size, MPI_Fint *ierr) {
	f_mpi_file_preallocate(fh, size, ierr);
}
extern void mpi_file_preallocate(MPI_Fint* fh, MPI_Offset size, MPI_Fint *ierr) {
	f_mpi_file_preallocate(fh, size, ierr);
}
extern void mpi_file_preallocate_(MPI_Fint* fh, MPI_Offset size, MPI_Fint *ierr) {
	f_mpi_file_preallocate(fh, size, ierr);
}
extern void mpi_file_preallocate__(MPI_Fint* fh, MPI_Offset size, MPI_Fint *ierr) {
	f_mpi_file_preallocate(fh, size, ierr);
}
int c_MPI_File_iread_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iread_all, (fh, buf, count, datatype, request));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(4, &obj_id_0, &mem_attr_0, &count, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_File_iread_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return c_MPI_File_iread_all(fh, buf, count, datatype, request); }
extern void f_mpi_file_iread_all(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_File_iread_all(c_handle_0, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_FILE_IREAD_ALL(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread_all(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iread_all(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread_all(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iread_all_(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread_all(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iread_all__(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread_all(fh, buf, count, datatype, request, ierr);
}
int c_MPI_T_cvar_write(MPI_T_cvar_handle handle, const void *buf)
{
	PILGRIM_TRACING_1(int, MPI_T_cvar_write, (handle, buf));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	void **args = assemble_args_list(2, &handle, &mem_attr_0);
	int sizes[] = { sizeof(MPI_T_cvar_handle), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_T_cvar_write(MPI_T_cvar_handle handle, const void *buf) { return c_MPI_T_cvar_write(handle, buf); }
int c_MPI_Group_translate_ranks(MPI_Group group1, int n, const int ranks1[], MPI_Group group2, int ranks2[])
{
	PILGRIM_TRACING_1(int, MPI_Group_translate_ranks, (group1, n, ranks1, group2, ranks2));
	MPI_Group obj_0 = group1;
	int obj_id_0 = MPI_OBJ_ID(MPI_Group, &obj_0);
	MPI_Group obj_1 = group2;
	int obj_id_1 = MPI_OBJ_ID(MPI_Group, &obj_1);
	void **args = assemble_args_list(5, &obj_id_0, &n, ranks1, &obj_id_1, ranks2);
	int sizes[] = { sizeof(int), sizeof(int), n*sizeof(const int), sizeof(int), n*sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Group_translate_ranks(MPI_Group group1, int n, const int ranks1[], MPI_Group group2, int ranks2[]) { return c_MPI_Group_translate_ranks(group1, n, ranks1, group2, ranks2); }
extern void f_mpi_group_translate_ranks(MPI_Fint* group1, int* n, const int ranks1[], MPI_Fint* group2, int ranks2[], MPI_Fint *ierr) {
	MPI_Group c_handle_0;
	c_handle_0 = PMPI_Group_f2c(*group1);
	MPI_Group c_handle_1;
	c_handle_1 = PMPI_Group_f2c(*group2);
	c_MPI_Group_translate_ranks(c_handle_0, (*n), ranks1, c_handle_1, ranks2);
}
extern void MPI_GROUP_TRANSLATE_RANKS(MPI_Fint* group1, int* n, const int ranks1[], MPI_Fint* group2, int ranks2[], MPI_Fint *ierr) {
	f_mpi_group_translate_ranks(group1, n, ranks1, group2, ranks2, ierr);
}
extern void mpi_group_translate_ranks(MPI_Fint* group1, int* n, const int ranks1[], MPI_Fint* group2, int ranks2[], MPI_Fint *ierr) {
	f_mpi_group_translate_ranks(group1, n, ranks1, group2, ranks2, ierr);
}
extern void mpi_group_translate_ranks_(MPI_Fint* group1, int* n, const int ranks1[], MPI_Fint* group2, int ranks2[], MPI_Fint *ierr) {
	f_mpi_group_translate_ranks(group1, n, ranks1, group2, ranks2, ierr);
}
extern void mpi_group_translate_ranks__(MPI_Fint* group1, int* n, const int ranks1[], MPI_Fint* group2, int ranks2[], MPI_Fint *ierr) {
	f_mpi_group_translate_ranks(group1, n, ranks1, group2, ranks2, ierr);
}
int c_MPI_Type_create_hvector(int count, int blocklength, MPI_Aint stride, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_hvector, (count, blocklength, stride, oldtype, newtype));
	MPI_Datatype obj_0 = oldtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, newtype);
	void **args = assemble_args_list(5, &count, &blocklength, &stride, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Type_create_hvector(int count, int blocklength, MPI_Aint stride, MPI_Datatype oldtype, MPI_Datatype *newtype) { return c_MPI_Type_create_hvector(count, blocklength, stride, oldtype, newtype); }
extern void f_mpi_type_create_hvector(int* count, int* blocklength, MPI_Aint stride, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*oldtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*newtype);
	c_MPI_Type_create_hvector((*count), (*blocklength), stride, c_handle_0, &c_handle_1);
	*newtype = PMPI_Type_c2f(c_handle_1);
}
extern void MPI_TYPE_CREATE_HVECTOR(int* count, int* blocklength, MPI_Aint stride, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_hvector(count, blocklength, stride, oldtype, newtype, ierr);
}
extern void mpi_type_create_hvector(int* count, int* blocklength, MPI_Aint stride, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_hvector(count, blocklength, stride, oldtype, newtype, ierr);
}
extern void mpi_type_create_hvector_(int* count, int* blocklength, MPI_Aint stride, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_hvector(count, blocklength, stride, oldtype, newtype, ierr);
}
extern void mpi_type_create_hvector__(int* count, int* blocklength, MPI_Aint stride, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_hvector(count, blocklength, stride, oldtype, newtype, ierr);
}
int c_MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval, void *attribute_val, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Comm_get_attr, (comm, comm_keyval, attribute_val, flag));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(attribute_val, &mem_attr_0);
	void **args = assemble_args_list(4, &obj_id_0, &comm_keyval, &mem_attr_0, flag);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MemPtrAttr), 1*sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval, void *attribute_val, int *flag) { return c_MPI_Comm_get_attr(comm, comm_keyval, attribute_val, flag); }
extern void f_mpi_comm_get_attr(MPI_Fint* comm, int* comm_keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Comm_get_attr(c_handle_0, (*comm_keyval), attribute_val, flag);
}
extern void MPI_COMM_GET_ATTR(MPI_Fint* comm, int* comm_keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	f_mpi_comm_get_attr(comm, comm_keyval, attribute_val, flag, ierr);
}
extern void mpi_comm_get_attr(MPI_Fint* comm, int* comm_keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	f_mpi_comm_get_attr(comm, comm_keyval, attribute_val, flag, ierr);
}
extern void mpi_comm_get_attr_(MPI_Fint* comm, int* comm_keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	f_mpi_comm_get_attr(comm, comm_keyval, attribute_val, flag, ierr);
}
extern void mpi_comm_get_attr__(MPI_Fint* comm, int* comm_keyval, void* attribute_val, int* flag, MPI_Fint *ierr) {
	f_mpi_comm_get_attr(comm, comm_keyval, attribute_val, flag, ierr);
}
int c_MPI_Initialized(int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Initialized, (flag));
	void **args = assemble_args_list(1, flag);
	int sizes[] = { 1*sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Initialized(int *flag) { return c_MPI_Initialized(flag); }
extern void f_mpi_initialized(int* flag, MPI_Fint *ierr) {
	c_MPI_Initialized(flag);
}
extern void MPI_INITIALIZED(int* flag, MPI_Fint *ierr) {
	f_mpi_initialized(flag, ierr);
}
extern void mpi_initialized(int* flag, MPI_Fint *ierr) {
	f_mpi_initialized(flag, ierr);
}
extern void mpi_initialized_(int* flag, MPI_Fint *ierr) {
	f_mpi_initialized(flag, ierr);
}
extern void mpi_initialized__(int* flag, MPI_Fint *ierr) {
	f_mpi_initialized(flag, ierr);
}
int c_MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag, MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_create_group, (comm, group, tag, newcomm));
	generate_intracomm_id(newcomm);
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	MPI_Group obj_1 = group;
	int obj_id_1 = MPI_OBJ_ID(MPI_Group, &obj_1);
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, newcomm);
	void **args = assemble_args_list(4, &obj_id_0, &obj_id_1, &my_tag, &obj_id_2);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag, MPI_Comm *newcomm) { return c_MPI_Comm_create_group(comm, group, tag, newcomm); }
extern void f_mpi_comm_create_group(MPI_Fint* comm, MPI_Fint* group, int* tag, MPI_Fint* newcomm, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Group c_handle_1;
	c_handle_1 = PMPI_Group_f2c(*group);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*newcomm);
	c_MPI_Comm_create_group(c_handle_0, c_handle_1, (*tag), &c_handle_2);
	*newcomm = PMPI_Comm_c2f(c_handle_2);
}
extern void MPI_COMM_CREATE_GROUP(MPI_Fint* comm, MPI_Fint* group, int* tag, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_create_group(comm, group, tag, newcomm, ierr);
}
extern void mpi_comm_create_group(MPI_Fint* comm, MPI_Fint* group, int* tag, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_create_group(comm, group, tag, newcomm, ierr);
}
extern void mpi_comm_create_group_(MPI_Fint* comm, MPI_Fint* group, int* tag, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_create_group(comm, group, tag, newcomm, ierr);
}
extern void mpi_comm_create_group__(MPI_Fint* comm, MPI_Fint* group, int* tag, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_create_group(comm, group, tag, newcomm, ierr);
}
int c_MPI_Grequest_complete(MPI_Request request)
{
	PILGRIM_TRACING_1(int, MPI_Grequest_complete, (request));
	MPI_Request obj_0 = request;
	int obj_id_0 = MPI_OBJ_ID(MPI_Request, &obj_0);
	void **args = assemble_args_list(1, &obj_id_0);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Grequest_complete(MPI_Request request) { return c_MPI_Grequest_complete(request); }
extern void f_mpi_grequest_complete(MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Request c_handle_0;
	c_handle_0 = PMPI_Request_f2c(*request);
	c_MPI_Grequest_complete(c_handle_0);
	*request = PMPI_Request_c2f(c_handle_0);
}
extern void MPI_GREQUEST_COMPLETE(MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_grequest_complete(request, ierr);
}
extern void mpi_grequest_complete(MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_grequest_complete(request, ierr);
}
extern void mpi_grequest_complete_(MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_grequest_complete(request, ierr);
}
extern void mpi_grequest_complete__(MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_grequest_complete(request, ierr);
}
int c_MPI_Get_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Get_accumulate, (origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win));
	MemPtrAttr mem_attr_0;
	addr2id(origin_addr, &mem_attr_0);
	MPI_Datatype obj_0 = origin_datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(result_addr, &mem_attr_1);
	MPI_Datatype obj_1 = result_datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Datatype obj_2 = target_datatype;
	int obj_id_2 = MPI_OBJ_ID(MPI_Datatype, &obj_2);
	MPI_Op obj_3 = op;
	int obj_id_3 = MPI_OBJ_ID(MPI_Op, &obj_3);
	MPI_Win obj_4 = win;
	int obj_id_4 = MPI_OBJ_ID(MPI_Win, &obj_4);
	void **args = assemble_args_list(12, &mem_attr_0, &origin_count, &obj_id_0, &mem_attr_1, &result_count, &obj_id_1, &target_rank, &target_disp, &target_count, &obj_id_2, &obj_id_3, &obj_id_4);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(12, sizes, args, -1);
}
int MPI_Get_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) { return c_MPI_Get_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win); }
extern void f_mpi_get_accumulate(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, void* result_addr, int* result_count, MPI_Fint* result_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*origin_datatype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*result_datatype);
	MPI_Datatype c_handle_2;
	c_handle_2 = PMPI_Type_f2c(*target_datatype);
	MPI_Op c_handle_3;
	c_handle_3 = PMPI_Op_f2c(*op);
	MPI_Win c_handle_4;
	c_handle_4 = PMPI_Win_f2c(*win);
	c_MPI_Get_accumulate(origin_addr, (*origin_count), c_handle_0, result_addr, (*result_count), c_handle_1, (*target_rank), target_disp, (*target_count), c_handle_2, c_handle_3, c_handle_4);
}
extern void MPI_GET_ACCUMULATE(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, void* result_addr, int* result_count, MPI_Fint* result_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_get_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, ierr);
}
extern void mpi_get_accumulate(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, void* result_addr, int* result_count, MPI_Fint* result_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_get_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, ierr);
}
extern void mpi_get_accumulate_(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, void* result_addr, int* result_count, MPI_Fint* result_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_get_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, ierr);
}
extern void mpi_get_accumulate__(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, void* result_addr, int* result_count, MPI_Fint* result_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_get_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, ierr);
}
int c_MPI_Win_create_errhandler(MPI_Win_errhandler_function *win_errhandler_fn, MPI_Errhandler *errhandler)
{
	PILGRIM_TRACING_1(int, MPI_Win_create_errhandler, (win_errhandler_fn, errhandler));
	int obj_id_0 = MPI_OBJ_ID(MPI_Errhandler, errhandler);
	void **args = assemble_args_list(2, win_errhandler_fn, &obj_id_0);
	int sizes[] = { 1*sizeof(MPI_Win_errhandler_function), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Win_create_errhandler(MPI_Win_errhandler_function *win_errhandler_fn, MPI_Errhandler *errhandler) { return c_MPI_Win_create_errhandler(win_errhandler_fn, errhandler); }
extern void f_mpi_win_create_errhandler(MPI_Win_errhandler_function* win_errhandler_fn, MPI_Fint* errhandler, MPI_Fint *ierr) {
	MPI_Errhandler c_handle_0;
	c_handle_0 = PMPI_Errhandler_f2c(*errhandler);
	c_MPI_Win_create_errhandler(win_errhandler_fn, &c_handle_0);
	*errhandler = PMPI_Errhandler_c2f(c_handle_0);
}
extern void MPI_WIN_CREATE_ERRHANDLER(MPI_Win_errhandler_function* win_errhandler_fn, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_win_create_errhandler(win_errhandler_fn, errhandler, ierr);
}
extern void mpi_win_create_errhandler(MPI_Win_errhandler_function* win_errhandler_fn, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_win_create_errhandler(win_errhandler_fn, errhandler, ierr);
}
extern void mpi_win_create_errhandler_(MPI_Win_errhandler_function* win_errhandler_fn, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_win_create_errhandler(win_errhandler_fn, errhandler, ierr);
}
extern void mpi_win_create_errhandler__(MPI_Win_errhandler_function* win_errhandler_fn, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_win_create_errhandler(win_errhandler_fn, errhandler, ierr);
}
int c_MPI_Win_fence(int assert, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_fence, (assert, win));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(2, &assert, &obj_id_0);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Win_fence(int assert, MPI_Win win) { return c_MPI_Win_fence(assert, win); }
extern void f_mpi_win_fence(int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_fence((*assert), c_handle_0);
}
extern void MPI_WIN_FENCE(int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_fence(assert, win, ierr);
}
extern void mpi_win_fence(int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_fence(assert, win, ierr);
}
extern void mpi_win_fence_(int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_fence(assert, win, ierr);
}
extern void mpi_win_fence__(int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_fence(assert, win, ierr);
}
int c_MPI_T_category_get_info(int cat_index, char *name, int *name_len, char *desc, int *desc_len, int *num_cvars, int *num_pvars, int *num_categories)
{
	PILGRIM_TRACING_1(int, MPI_T_category_get_info, (cat_index, name, name_len, desc, desc_len, num_cvars, num_pvars, num_categories));
	void **args = assemble_args_list(8, &cat_index, name, name_len, desc, desc_len, num_cvars, num_pvars, num_categories);
	int sizes[] = { sizeof(int), strlen(name)+1, 1*sizeof(int), strlen(desc)+1, 1*sizeof(int), 1*sizeof(int), 1*sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(8, sizes, args, -1);
}
int MPI_T_category_get_info(int cat_index, char *name, int *name_len, char *desc, int *desc_len, int *num_cvars, int *num_pvars, int *num_categories) { return c_MPI_T_category_get_info(cat_index, name, name_len, desc, desc_len, num_cvars, num_pvars, num_categories); }
int c_MPI_Group_difference(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup)
{
	PILGRIM_TRACING_1(int, MPI_Group_difference, (group1, group2, newgroup));
	MPI_Group obj_0 = group1;
	int obj_id_0 = MPI_OBJ_ID(MPI_Group, &obj_0);
	MPI_Group obj_1 = group2;
	int obj_id_1 = MPI_OBJ_ID(MPI_Group, &obj_1);
	int obj_id_2 = MPI_OBJ_ID(MPI_Group, newgroup);
	void **args = assemble_args_list(3, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Group_difference(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup) { return c_MPI_Group_difference(group1, group2, newgroup); }
extern void f_mpi_group_difference(MPI_Fint* group1, MPI_Fint* group2, MPI_Fint* newgroup, MPI_Fint *ierr) {
	MPI_Group c_handle_0;
	c_handle_0 = PMPI_Group_f2c(*group1);
	MPI_Group c_handle_1;
	c_handle_1 = PMPI_Group_f2c(*group2);
	MPI_Group c_handle_2;
	c_handle_2 = PMPI_Group_f2c(*newgroup);
	c_MPI_Group_difference(c_handle_0, c_handle_1, &c_handle_2);
	*newgroup = PMPI_Group_c2f(c_handle_2);
}
extern void MPI_GROUP_DIFFERENCE(MPI_Fint* group1, MPI_Fint* group2, MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_difference(group1, group2, newgroup, ierr);
}
extern void mpi_group_difference(MPI_Fint* group1, MPI_Fint* group2, MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_difference(group1, group2, newgroup, ierr);
}
extern void mpi_group_difference_(MPI_Fint* group1, MPI_Fint* group2, MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_difference(group1, group2, newgroup, ierr);
}
extern void mpi_group_difference__(MPI_Fint* group1, MPI_Fint* group2, MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_difference(group1, group2, newgroup, ierr);
}
int c_MPI_T_pvar_start(MPI_T_pvar_session session, MPI_T_pvar_handle handle)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_start, (session, handle));
	void **args = assemble_args_list(2, &session, &handle);
	int sizes[] = { sizeof(MPI_T_pvar_session), sizeof(MPI_T_pvar_handle) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_T_pvar_start(MPI_T_pvar_session session, MPI_T_pvar_handle handle) { return c_MPI_T_pvar_start(session, handle); }
int c_MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen)
{
	PILGRIM_TRACING_1(int, MPI_Win_get_name, (win, win_name, resultlen));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(3, &obj_id_0, win_name, resultlen);
	int sizes[] = { sizeof(int), strlen(win_name)+1, 1*sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen) { return c_MPI_Win_get_name(win, win_name, resultlen); }
extern void f_mpi_win_get_name(MPI_Fint* win, char* win_name, int* resultlen, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_get_name(c_handle_0, win_name, resultlen);
}
extern void MPI_WIN_GET_NAME(MPI_Fint* win, char* win_name, int* resultlen, MPI_Fint *ierr) {
	f_mpi_win_get_name(win, win_name, resultlen, ierr);
}
extern void mpi_win_get_name(MPI_Fint* win, char* win_name, int* resultlen, MPI_Fint *ierr) {
	f_mpi_win_get_name(win, win_name, resultlen, ierr);
}
extern void mpi_win_get_name_(MPI_Fint* win, char* win_name, int* resultlen, MPI_Fint *ierr) {
	f_mpi_win_get_name(win, win_name, resultlen, ierr);
}
extern void mpi_win_get_name__(MPI_Fint* win, char* win_name, int* resultlen, MPI_Fint *ierr) {
	f_mpi_win_get_name(win, win_name, resultlen, ierr);
}
int c_MPI_Win_wait(MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_wait, (win));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(1, &obj_id_0);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Win_wait(MPI_Win win) { return c_MPI_Win_wait(win); }
extern void f_mpi_win_wait(MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_wait(c_handle_0);
}
extern void MPI_WIN_WAIT(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_wait(win, ierr);
}
extern void mpi_win_wait(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_wait(win, ierr);
}
extern void mpi_win_wait_(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_wait(win, ierr);
}
extern void mpi_win_wait__(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_wait(win, ierr);
}
int c_MPI_Scatterv(const void *sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Scatterv, (sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(9, &mem_attr_0, sendcounts, displs, &obj_id_0, &mem_attr_1, &recvcount, &obj_id_1, &root, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args, comm_size);
}
int MPI_Scatterv(const void *sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { return c_MPI_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm); }
extern void f_mpi_scatterv(const void* sendbuf, const int sendcounts[], const int displs[], MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Scatterv(sendbuf, sendcounts, displs, c_handle_0, recvbuf, (*recvcount), c_handle_1, (*root), c_handle_2);
}
extern void MPI_SCATTERV(const void* sendbuf, const int sendcounts[], const int displs[], MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}
extern void mpi_scatterv(const void* sendbuf, const int sendcounts[], const int displs[], MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}
extern void mpi_scatterv_(const void* sendbuf, const int sendcounts[], const int displs[], MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}
extern void mpi_scatterv__(const void* sendbuf, const int sendcounts[], const int displs[], MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}
int c_MPI_File_write_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write_all, (fh, buf, count, datatype, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	int status_arg[2] = {0};
	void **args = assemble_args_list(5, &obj_id_0, &mem_attr_0, &count, &obj_id_1, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_File_write_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return c_MPI_File_write_all(fh, buf, count, datatype, status); }
extern void f_mpi_file_write_all(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_File_write_all(c_handle_0, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_FILE_WRITE_ALL(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_all(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_write_all(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_all(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_write_all_(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_all(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_write_all__(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_all(fh, buf, count, datatype, status, ierr);
}
int c_MPI_Comm_connect(const char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_connect, (port_name, info, root, comm, newcomm));
	generate_intercomm_id(comm, newcomm, 0);
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, newcomm);
	void **args = assemble_args_list(5, port_name, &obj_id_0, &root, &obj_id_1, &obj_id_2);
	int sizes[] = { strlen(port_name)+1, sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Comm_connect(const char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm) { return c_MPI_Comm_connect(port_name, info, root, comm, newcomm); }
extern void f_mpi_comm_connect(const char* port_name, MPI_Fint* info, int* root, MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*newcomm);
	c_MPI_Comm_connect(port_name, c_handle_0, (*root), c_handle_1, &c_handle_2);
	*newcomm = PMPI_Comm_c2f(c_handle_2);
}
extern void MPI_COMM_CONNECT(const char* port_name, MPI_Fint* info, int* root, MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_connect(port_name, info, root, comm, newcomm, ierr);
}
extern void mpi_comm_connect(const char* port_name, MPI_Fint* info, int* root, MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_connect(port_name, info, root, comm, newcomm, ierr);
}
extern void mpi_comm_connect_(const char* port_name, MPI_Fint* info, int* root, MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_connect(port_name, info, root, comm, newcomm, ierr);
}
extern void mpi_comm_connect__(const char* port_name, MPI_Fint* info, int* root, MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_connect(port_name, info, root, comm, newcomm, ierr);
}
int c_MPI_Win_flush_all(MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_flush_all, (win));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(1, &obj_id_0);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Win_flush_all(MPI_Win win) { return c_MPI_Win_flush_all(win); }
extern void f_mpi_win_flush_all(MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_flush_all(c_handle_0);
}
extern void MPI_WIN_FLUSH_ALL(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_flush_all(win, ierr);
}
extern void mpi_win_flush_all(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_flush_all(win, ierr);
}
extern void mpi_win_flush_all_(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_flush_all(win, ierr);
}
extern void mpi_win_flush_all__(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_flush_all(win, ierr);
}
int c_MPI_Win_get_group(MPI_Win win, MPI_Group *group)
{
	PILGRIM_TRACING_1(int, MPI_Win_get_group, (win, group));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Group, group);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Win_get_group(MPI_Win win, MPI_Group *group) { return c_MPI_Win_get_group(win, group); }
extern void f_mpi_win_get_group(MPI_Fint* win, MPI_Fint* group, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	MPI_Group c_handle_1;
	c_handle_1 = PMPI_Group_f2c(*group);
	c_MPI_Win_get_group(c_handle_0, &c_handle_1);
	*group = PMPI_Group_c2f(c_handle_1);
}
extern void MPI_WIN_GET_GROUP(MPI_Fint* win, MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_win_get_group(win, group, ierr);
}
extern void mpi_win_get_group(MPI_Fint* win, MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_win_get_group(win, group, ierr);
}
extern void mpi_win_get_group_(MPI_Fint* win, MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_win_get_group(win, group, ierr);
}
extern void mpi_win_get_group__(MPI_Fint* win, MPI_Fint* group, MPI_Fint *ierr) {
	f_mpi_win_get_group(win, group, ierr);
}
int c_MPI_File_set_size(MPI_File fh, MPI_Offset size)
{
	PILGRIM_TRACING_1(int, MPI_File_set_size, (fh, size));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	append_offset(size);
	void **args = assemble_args_list(1, &obj_id_0);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_File_set_size(MPI_File fh, MPI_Offset size) { return c_MPI_File_set_size(fh, size); }
extern void f_mpi_file_set_size(MPI_Fint* fh, MPI_Offset size, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	c_MPI_File_set_size(c_handle_0, size);
	*fh = PMPI_File_c2f(c_handle_0);
}
extern void MPI_FILE_SET_SIZE(MPI_Fint* fh, MPI_Offset size, MPI_Fint *ierr) {
	f_mpi_file_set_size(fh, size, ierr);
}
extern void mpi_file_set_size(MPI_Fint* fh, MPI_Offset size, MPI_Fint *ierr) {
	f_mpi_file_set_size(fh, size, ierr);
}
extern void mpi_file_set_size_(MPI_Fint* fh, MPI_Offset size, MPI_Fint *ierr) {
	f_mpi_file_set_size(fh, size, ierr);
}
extern void mpi_file_set_size__(MPI_Fint* fh, MPI_Offset size, MPI_Fint *ierr) {
	f_mpi_file_set_size(fh, size, ierr);
}
int c_MPI_Status_set_cancelled(MPI_Status *status, int flag)
{
	PILGRIM_TRACING_1(int, MPI_Status_set_cancelled, (status, flag));
	int status_arg[2] = {0};
	void **args = assemble_args_list(2, status_arg, &flag);
	int sizes[] = { sizeof(int)*2, sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Status_set_cancelled(MPI_Status *status, int flag) { return c_MPI_Status_set_cancelled(status, flag); }
extern void f_mpi_status_set_cancelled(MPI_Fint* status, int* flag, MPI_Fint *ierr) {
	MPI_Status c_handle_0;
	PMPI_Status_f2c(status, &c_handle_0);
	c_MPI_Status_set_cancelled(&c_handle_0, (*flag));
	PMPI_Status_c2f(&c_handle_0, status);
}
extern void MPI_STATUS_SET_CANCELLED(MPI_Fint* status, int* flag, MPI_Fint *ierr) {
	f_mpi_status_set_cancelled(status, flag, ierr);
}
extern void mpi_status_set_cancelled(MPI_Fint* status, int* flag, MPI_Fint *ierr) {
	f_mpi_status_set_cancelled(status, flag, ierr);
}
extern void mpi_status_set_cancelled_(MPI_Fint* status, int* flag, MPI_Fint *ierr) {
	f_mpi_status_set_cancelled(status, flag, ierr);
}
extern void mpi_status_set_cancelled__(MPI_Fint* status, int* flag, MPI_Fint *ierr) {
	f_mpi_status_set_cancelled(status, flag, ierr);
}
int c_MPI_Reduce_local(const void *inbuf, void *inoutbuf, int count, MPI_Datatype datatype, MPI_Op op)
{
	PILGRIM_TRACING_1(int, MPI_Reduce_local, (inbuf, inoutbuf, count, datatype, op));
	MemPtrAttr mem_attr_0;
	addr2id(inbuf, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(inoutbuf, &mem_attr_1);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Op obj_1 = op;
	int obj_id_1 = MPI_OBJ_ID(MPI_Op, &obj_1);
	void **args = assemble_args_list(5, &mem_attr_0, &mem_attr_1, &count, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Reduce_local(const void *inbuf, void *inoutbuf, int count, MPI_Datatype datatype, MPI_Op op) { return c_MPI_Reduce_local(inbuf, inoutbuf, count, datatype, op); }
extern void f_mpi_reduce_local(const void* inbuf, void* inoutbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Op c_handle_1;
	c_handle_1 = PMPI_Op_f2c(*op);
	c_MPI_Reduce_local(inbuf, inoutbuf, (*count), c_handle_0, c_handle_1);
}
extern void MPI_REDUCE_LOCAL(const void* inbuf, void* inoutbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint *ierr) {
	f_mpi_reduce_local(inbuf, inoutbuf, count, datatype, op, ierr);
}
extern void mpi_reduce_local(const void* inbuf, void* inoutbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint *ierr) {
	f_mpi_reduce_local(inbuf, inoutbuf, count, datatype, op, ierr);
}
extern void mpi_reduce_local_(const void* inbuf, void* inoutbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint *ierr) {
	f_mpi_reduce_local(inbuf, inoutbuf, count, datatype, op, ierr);
}
extern void mpi_reduce_local__(const void* inbuf, void* inoutbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint *ierr) {
	f_mpi_reduce_local(inbuf, inoutbuf, count, datatype, op, ierr);
}
int c_MPI_T_pvar_write(MPI_T_pvar_session session, MPI_T_pvar_handle handle, const void *buf)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_write, (session, handle, buf));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	void **args = assemble_args_list(3, &session, &handle, &mem_attr_0);
	int sizes[] = { sizeof(MPI_T_pvar_session), sizeof(MPI_T_pvar_handle), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_T_pvar_write(MPI_T_pvar_session session, MPI_T_pvar_handle handle, const void *buf) { return c_MPI_T_pvar_write(session, handle, buf); }
int c_MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors, int neighbors[])
{
	PILGRIM_TRACING_1(int, MPI_Graph_neighbors, (comm, rank, maxneighbors, neighbors));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(4, &obj_id_0, &rank, &maxneighbors, neighbors);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), maxneighbors*sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors, int neighbors[]) { return c_MPI_Graph_neighbors(comm, rank, maxneighbors, neighbors); }
extern void f_mpi_graph_neighbors(MPI_Fint* comm, int* rank, int* maxneighbors, int neighbors[], MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Graph_neighbors(c_handle_0, (*rank), (*maxneighbors), neighbors);
}
extern void MPI_GRAPH_NEIGHBORS(MPI_Fint* comm, int* rank, int* maxneighbors, int neighbors[], MPI_Fint *ierr) {
	f_mpi_graph_neighbors(comm, rank, maxneighbors, neighbors, ierr);
}
extern void mpi_graph_neighbors(MPI_Fint* comm, int* rank, int* maxneighbors, int neighbors[], MPI_Fint *ierr) {
	f_mpi_graph_neighbors(comm, rank, maxneighbors, neighbors, ierr);
}
extern void mpi_graph_neighbors_(MPI_Fint* comm, int* rank, int* maxneighbors, int neighbors[], MPI_Fint *ierr) {
	f_mpi_graph_neighbors(comm, rank, maxneighbors, neighbors, ierr);
}
extern void mpi_graph_neighbors__(MPI_Fint* comm, int* rank, int* maxneighbors, int neighbors[], MPI_Fint *ierr) {
	f_mpi_graph_neighbors(comm, rank, maxneighbors, neighbors, ierr);
}
int c_MPI_Dims_create(int nnodes, int ndims, int dims[])
{
	PILGRIM_TRACING_1(int, MPI_Dims_create, (nnodes, ndims, dims));
	void **args = assemble_args_list(3, &nnodes, &ndims, dims);
	int sizes[] = { sizeof(int), sizeof(int), ndims*sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Dims_create(int nnodes, int ndims, int dims[]) { return c_MPI_Dims_create(nnodes, ndims, dims); }
extern void f_mpi_dims_create(int* nnodes, int* ndims, int dims[], MPI_Fint *ierr) {
	c_MPI_Dims_create((*nnodes), (*ndims), dims);
}
extern void MPI_DIMS_CREATE(int* nnodes, int* ndims, int dims[], MPI_Fint *ierr) {
	f_mpi_dims_create(nnodes, ndims, dims, ierr);
}
extern void mpi_dims_create(int* nnodes, int* ndims, int dims[], MPI_Fint *ierr) {
	f_mpi_dims_create(nnodes, ndims, dims, ierr);
}
extern void mpi_dims_create_(int* nnodes, int* ndims, int dims[], MPI_Fint *ierr) {
	f_mpi_dims_create(nnodes, ndims, dims, ierr);
}
extern void mpi_dims_create__(int* nnodes, int* ndims, int dims[], MPI_Fint *ierr) {
	f_mpi_dims_create(nnodes, ndims, dims, ierr);
}
int c_MPI_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Scatter, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(8, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, &recvcount, &obj_id_1, &root, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(8, sizes, args, -1);
}
int MPI_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { return c_MPI_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm); }
extern void f_mpi_scatter(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Scatter(sendbuf, (*sendcount), c_handle_0, recvbuf, (*recvcount), c_handle_1, (*root), c_handle_2);
}
extern void MPI_SCATTER(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}
extern void mpi_scatter(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}
extern void mpi_scatter_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}
extern void mpi_scatter__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}
int c_MPI_Ireduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ireduce_scatter_block, (sendbuf, recvbuf, recvcount, datatype, op, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Op obj_1 = op;
	int obj_id_1 = MPI_OBJ_ID(MPI_Op, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(6, &mem_attr_0, &mem_attr_1, &recvcount, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Ireduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { return c_MPI_Ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, request); }
extern void f_mpi_ireduce_scatter_block(const void* sendbuf, void* recvbuf, int* recvcount, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Op c_handle_1;
	c_handle_1 = PMPI_Op_f2c(*op);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Ireduce_scatter_block(sendbuf, recvbuf, (*recvcount), c_handle_0, c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_IREDUCE_SCATTER_BLOCK(const void* sendbuf, void* recvbuf, int* recvcount, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, request, ierr);
}
extern void mpi_ireduce_scatter_block(const void* sendbuf, void* recvbuf, int* recvcount, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, request, ierr);
}
extern void mpi_ireduce_scatter_block_(const void* sendbuf, void* recvbuf, int* recvcount, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, request, ierr);
}
extern void mpi_ireduce_scatter_block__(const void* sendbuf, void* recvbuf, int* recvcount, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, request, ierr);
}
int c_MPI_Ialltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ialltoallw, (sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	int obj_id_0[comm_size];
	for(int i=0; i<comm_size; i++) obj_id_0[i] = (sendtypes==NULL) ? PILGRIM_INVALID_MPI_OBJECT_ID: MPI_OBJ_ID(MPI_Datatype, &sendtypes[i]);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	int obj_id_1[comm_size];
	for(int i=0; i<comm_size; i++) obj_id_1[i] = (recvtypes==NULL) ? PILGRIM_INVALID_MPI_OBJECT_ID: MPI_OBJ_ID(MPI_Datatype, &recvtypes[i]);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(9, &mem_attr_0, sendcounts, sdispls, obj_id_0, &mem_attr_1, recvcounts, rdispls, obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), (comm_size)*sizeof(int), sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), (comm_size)*sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args, comm_size);
}
int MPI_Ialltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request) { return c_MPI_Ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request); }
extern void f_mpi_ialltoallw(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0[comm_size];
	for(int i = 0; i < comm_size; i++) c_handle_0[i] = PMPI_Type_f2c(sendtypes[i]);
	MPI_Datatype c_handle_1[comm_size];
	for(int i = 0; i < comm_size; i++) c_handle_1[i] = PMPI_Type_f2c(recvtypes[i]);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Ialltoallw(sendbuf, sendcounts, sdispls, c_handle_0, recvbuf, recvcounts, rdispls, c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_IALLTOALLW(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierr);
}
extern void mpi_ialltoallw(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierr);
}
extern void mpi_ialltoallw_(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierr);
}
extern void mpi_ialltoallw__(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierr);
}
int c_MPI_Ialltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ialltoallv, (sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(9, &mem_attr_0, sendcounts, sdispls, &obj_id_0, &mem_attr_1, recvcounts, rdispls, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), sizeof(int), sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args, comm_size);
}
int MPI_Ialltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return c_MPI_Ialltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request); }
extern void f_mpi_ialltoallv(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Ialltoallv(sendbuf, sendcounts, sdispls, c_handle_0, recvbuf, recvcounts, rdispls, c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_IALLTOALLV(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ialltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierr);
}
extern void mpi_ialltoallv(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ialltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierr);
}
extern void mpi_ialltoallv_(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ialltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierr);
}
extern void mpi_ialltoallv__(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ialltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierr);
}
int c_MPI_Comm_free(MPI_Comm *comm)
{
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, comm);
	void **args = assemble_args_list(1, &obj_id_0);
	MPI_OBJ_RELEASE(MPI_Comm, comm);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_1(int, MPI_Comm_free, (comm));
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Comm_free(MPI_Comm *comm) { return c_MPI_Comm_free(comm); }
extern void f_mpi_comm_free(MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Comm_free(&c_handle_0);
	*comm = PMPI_Comm_c2f(c_handle_0);
}
extern void MPI_COMM_FREE(MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_comm_free(comm, ierr);
}
extern void mpi_comm_free(MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_comm_free(comm, ierr);
}
extern void mpi_comm_free_(MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_comm_free(comm, ierr);
}
extern void mpi_comm_free__(MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_comm_free(comm, ierr);
}
int c_MPI_T_cvar_read(MPI_T_cvar_handle handle, void *buf)
{
	PILGRIM_TRACING_1(int, MPI_T_cvar_read, (handle, buf));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	void **args = assemble_args_list(2, &handle, &mem_attr_0);
	int sizes[] = { sizeof(MPI_T_cvar_handle), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_T_cvar_read(MPI_T_cvar_handle handle, void *buf) { return c_MPI_T_cvar_read(handle, buf); }
int c_MPI_Neighbor_alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Neighbor_alltoall, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(7, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, &recvcount, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Neighbor_alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { return c_MPI_Neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm); }
extern void f_mpi_neighbor_alltoall(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Neighbor_alltoall(sendbuf, (*sendcount), c_handle_0, recvbuf, (*recvcount), c_handle_1, c_handle_2);
}
extern void MPI_NEIGHBOR_ALLTOALL(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}
extern void mpi_neighbor_alltoall(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}
extern void mpi_neighbor_alltoall_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}
extern void mpi_neighbor_alltoall__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}
int c_MPI_Alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Alltoall, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(7, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, &recvcount, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { return c_MPI_Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm); }
extern void f_mpi_alltoall(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Alltoall(sendbuf, (*sendcount), c_handle_0, recvbuf, (*recvcount), c_handle_1, c_handle_2);
}
extern void MPI_ALLTOALL(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}
extern void mpi_alltoall(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}
extern void mpi_alltoall_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}
extern void mpi_alltoall__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}
int c_MPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[], const int array_of_maxprocs[], const MPI_Info array_of_info[], int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
{
	PILGRIM_TRACING_1(int, MPI_Comm_spawn_multiple, (count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes));
	generate_intercomm_id(comm, intercomm, 0);
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	int obj_id_0[count];
	for(int i=0; i<count; i++) obj_id_0[i] = (array_of_info==NULL) ? PILGRIM_INVALID_MPI_OBJECT_ID: MPI_OBJ_ID(MPI_Info, &array_of_info[i]);
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, intercomm);
	void **args = assemble_args_list(9, &count, array_of_commands, array_of_argv, array_of_maxprocs, obj_id_0, &root, &obj_id_1, &obj_id_2, array_of_errcodes);
	int sizes[] = { sizeof(int), count*sizeof(const int), count*sizeof(int), sizeof(int), sizeof(int), sizeof(int), comm_size*sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args, comm_size);
}
int MPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[], const int array_of_maxprocs[], const MPI_Info array_of_info[], int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[]) { return c_MPI_Comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes); }
extern void f_mpi_comm_spawn_multiple(int* count, char* array_of_commands[], char** array_of_argv[], const int array_of_maxprocs[], MPI_Fint* array_of_info, int* root, MPI_Fint* comm, MPI_Fint* intercomm, int array_of_errcodes[], MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Info c_handle_0[*count];
	for(int i = 0; i < *count; i++) c_handle_0[i] = PMPI_Info_f2c(array_of_info[i]);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*intercomm);
	c_MPI_Comm_spawn_multiple((*count), array_of_commands, array_of_argv, array_of_maxprocs, c_handle_0, (*root), c_handle_1, &c_handle_2, array_of_errcodes);
	*intercomm = PMPI_Comm_c2f(c_handle_2);
}
extern void MPI_COMM_SPAWN_MULTIPLE(int* count, char* array_of_commands[], char** array_of_argv[], const int array_of_maxprocs[], MPI_Fint* array_of_info, int* root, MPI_Fint* comm, MPI_Fint* intercomm, int array_of_errcodes[], MPI_Fint *ierr) {
	f_mpi_comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes, ierr);
}
extern void mpi_comm_spawn_multiple(int* count, char* array_of_commands[], char** array_of_argv[], const int array_of_maxprocs[], MPI_Fint* array_of_info, int* root, MPI_Fint* comm, MPI_Fint* intercomm, int array_of_errcodes[], MPI_Fint *ierr) {
	f_mpi_comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes, ierr);
}
extern void mpi_comm_spawn_multiple_(int* count, char* array_of_commands[], char** array_of_argv[], const int array_of_maxprocs[], MPI_Fint* array_of_info, int* root, MPI_Fint* comm, MPI_Fint* intercomm, int array_of_errcodes[], MPI_Fint *ierr) {
	f_mpi_comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes, ierr);
}
extern void mpi_comm_spawn_multiple__(int* count, char* array_of_commands[], char** array_of_argv[], const int array_of_maxprocs[], MPI_Fint* array_of_info, int* root, MPI_Fint* comm, MPI_Fint* intercomm, int array_of_errcodes[], MPI_Fint *ierr) {
	f_mpi_comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes, ierr);
}
int c_MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info, MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_dup_with_info, (comm, info, newcomm));
	generate_intracomm_id(newcomm);
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	MPI_Info obj_1 = info;
	int obj_id_1 = MPI_OBJ_ID(MPI_Info, &obj_1);
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, newcomm);
	void **args = assemble_args_list(3, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info, MPI_Comm *newcomm) { return c_MPI_Comm_dup_with_info(comm, info, newcomm); }
extern void f_mpi_comm_dup_with_info(MPI_Fint* comm, MPI_Fint* info, MPI_Fint* newcomm, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Info c_handle_1;
	c_handle_1 = PMPI_Info_f2c(*info);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*newcomm);
	c_MPI_Comm_dup_with_info(c_handle_0, c_handle_1, &c_handle_2);
	*newcomm = PMPI_Comm_c2f(c_handle_2);
}
extern void MPI_COMM_DUP_WITH_INFO(MPI_Fint* comm, MPI_Fint* info, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_dup_with_info(comm, info, newcomm, ierr);
}
extern void mpi_comm_dup_with_info(MPI_Fint* comm, MPI_Fint* info, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_dup_with_info(comm, info, newcomm, ierr);
}
extern void mpi_comm_dup_with_info_(MPI_Fint* comm, MPI_Fint* info, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_dup_with_info(comm, info, newcomm, ierr);
}
extern void mpi_comm_dup_with_info__(MPI_Fint* comm, MPI_Fint* info, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_dup_with_info(comm, info, newcomm, ierr);
}
int c_MPI_T_pvar_handle_free(MPI_T_pvar_session session, MPI_T_pvar_handle *handle)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_handle_free, (session, handle));
	void **args = assemble_args_list(2, &session, handle);
	int sizes[] = { sizeof(MPI_T_pvar_session), 1*sizeof(MPI_T_pvar_handle) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_T_pvar_handle_free(MPI_T_pvar_session session, MPI_T_pvar_handle *handle) { return c_MPI_T_pvar_handle_free(session, handle); }
int c_MPI_Type_free(MPI_Datatype *datatype)
{
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, datatype);
	void **args = assemble_args_list(1, &obj_id_0);
	MPI_OBJ_RELEASE(MPI_Datatype, datatype);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_1(int, MPI_Type_free, (datatype));
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Type_free(MPI_Datatype *datatype) { return c_MPI_Type_free(datatype); }
extern void f_mpi_type_free(MPI_Fint* datatype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Type_free(&c_handle_0);
	*datatype = PMPI_Type_c2f(c_handle_0);
}
extern void MPI_TYPE_FREE(MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_type_free(datatype, ierr);
}
extern void mpi_type_free(MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_type_free(datatype, ierr);
}
extern void mpi_type_free_(MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_type_free(datatype, ierr);
}
extern void mpi_type_free__(MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_type_free(datatype, ierr);
}
int c_MPI_Win_test(MPI_Win win, int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Win_test, (win, flag));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, flag);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Win_test(MPI_Win win, int *flag) { return c_MPI_Win_test(win, flag); }
extern void f_mpi_win_test(MPI_Fint* win, int* flag, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_test(c_handle_0, flag);
}
extern void MPI_WIN_TEST(MPI_Fint* win, int* flag, MPI_Fint *ierr) {
	f_mpi_win_test(win, flag, ierr);
}
extern void mpi_win_test(MPI_Fint* win, int* flag, MPI_Fint *ierr) {
	f_mpi_win_test(win, flag, ierr);
}
extern void mpi_win_test_(MPI_Fint* win, int* flag, MPI_Fint *ierr) {
	f_mpi_win_test(win, flag, ierr);
}
extern void mpi_win_test__(MPI_Fint* win, int* flag, MPI_Fint *ierr) {
	f_mpi_win_test(win, flag, ierr);
}
int c_MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype)
{
	PILGRIM_TRACING_1(int, MPI_File_write_at_all_begin, (fh, offset, buf, count, datatype));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	append_offset(offset);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(4, &obj_id_0, &mem_attr_0, &count, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype) { return c_MPI_File_write_at_all_begin(fh, offset, buf, count, datatype); }
extern void f_mpi_file_write_at_all_begin(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	c_MPI_File_write_at_all_begin(c_handle_0, offset, buf, (*count), c_handle_1);
	*fh = PMPI_File_c2f(c_handle_0);
}
extern void MPI_FILE_WRITE_AT_ALL_BEGIN(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_write_at_all_begin(fh, offset, buf, count, datatype, ierr);
}
extern void mpi_file_write_at_all_begin(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_write_at_all_begin(fh, offset, buf, count, datatype, ierr);
}
extern void mpi_file_write_at_all_begin_(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_write_at_all_begin(fh, offset, buf, count, datatype, ierr);
}
extern void mpi_file_write_at_all_begin__(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_write_at_all_begin(fh, offset, buf, count, datatype, ierr);
}
int c_MPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *errhandler)
{
	PILGRIM_TRACING_1(int, MPI_Comm_get_errhandler, (comm, errhandler));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Errhandler, errhandler);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *errhandler) { return c_MPI_Comm_get_errhandler(comm, errhandler); }
extern void f_mpi_comm_get_errhandler(MPI_Fint* comm, MPI_Fint* errhandler, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Errhandler c_handle_1;
	c_handle_1 = PMPI_Errhandler_f2c(*errhandler);
	c_MPI_Comm_get_errhandler(c_handle_0, &c_handle_1);
	*errhandler = PMPI_Errhandler_c2f(c_handle_1);
}
extern void MPI_COMM_GET_ERRHANDLER(MPI_Fint* comm, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_comm_get_errhandler(comm, errhandler, ierr);
}
extern void mpi_comm_get_errhandler(MPI_Fint* comm, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_comm_get_errhandler(comm, errhandler, ierr);
}
extern void mpi_comm_get_errhandler_(MPI_Fint* comm, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_comm_get_errhandler(comm, errhandler, ierr);
}
extern void mpi_comm_get_errhandler__(MPI_Fint* comm, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_comm_get_errhandler(comm, errhandler, ierr);
}
int c_MPI_Mprobe(int source, int tag, MPI_Comm comm, MPI_Message *message, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Mprobe, (source, tag, comm, message, status));
	int source_rank = g_mpi_rank - source;
	if(source == MPI_ANY_SOURCE) source_rank = PILGRIM_MPI_ANY_SOURCE;
	if(source == MPI_PROC_NULL) source_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Message, message);
	int status_arg[2] = {0};
	if(source == MPI_ANY_SOURCE && status && status!=MPI_STATUS_IGNORE) status_arg[0] = status->MPI_SOURCE;
	if(tag == MPI_ANY_TAG && status && status!=MPI_STATUS_IGNORE) status_arg[1] = status->MPI_TAG;
	void **args = assemble_args_list(5, &source_rank, &my_tag, &obj_id_0, &obj_id_1, status_arg);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Mprobe(int source, int tag, MPI_Comm comm, MPI_Message *message, MPI_Status *status) { return c_MPI_Mprobe(source, tag, comm, message, status); }
extern void f_mpi_mprobe(int* source, int* tag, MPI_Fint* comm, MPI_Fint* message, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Message c_handle_1;
	c_handle_1 = PMPI_Message_f2c(*message);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_Mprobe((*source), (*tag), c_handle_0, &c_handle_1, &c_handle_2);
	*message = PMPI_Message_c2f(c_handle_1);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_MPROBE(int* source, int* tag, MPI_Fint* comm, MPI_Fint* message, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_mprobe(source, tag, comm, message, status, ierr);
}
extern void mpi_mprobe(int* source, int* tag, MPI_Fint* comm, MPI_Fint* message, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_mprobe(source, tag, comm, message, status, ierr);
}
extern void mpi_mprobe_(int* source, int* tag, MPI_Fint* comm, MPI_Fint* message, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_mprobe(source, tag, comm, message, status, ierr);
}
extern void mpi_mprobe__(int* source, int* tag, MPI_Fint* comm, MPI_Fint* message, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_mprobe(source, tag, comm, message, status, ierr);
}
int c_MPI_Info_get_nkeys(MPI_Info info, int *nkeys)
{
	PILGRIM_TRACING_1(int, MPI_Info_get_nkeys, (info, nkeys));
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, nkeys);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Info_get_nkeys(MPI_Info info, int *nkeys) { return c_MPI_Info_get_nkeys(info, nkeys); }
extern void f_mpi_info_get_nkeys(MPI_Fint* info, int* nkeys, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	c_MPI_Info_get_nkeys(c_handle_0, nkeys);
}
extern void MPI_INFO_GET_NKEYS(MPI_Fint* info, int* nkeys, MPI_Fint *ierr) {
	f_mpi_info_get_nkeys(info, nkeys, ierr);
}
extern void mpi_info_get_nkeys(MPI_Fint* info, int* nkeys, MPI_Fint *ierr) {
	f_mpi_info_get_nkeys(info, nkeys, ierr);
}
extern void mpi_info_get_nkeys_(MPI_Fint* info, int* nkeys, MPI_Fint *ierr) {
	f_mpi_info_get_nkeys(info, nkeys, ierr);
}
extern void mpi_info_get_nkeys__(MPI_Fint* info, int* nkeys, MPI_Fint *ierr) {
	f_mpi_info_get_nkeys(info, nkeys, ierr);
}
int c_MPI_Finalized(int *flag)
{
	PILGRIM_TRACING_1(int, MPI_Finalized, (flag));
	void **args = assemble_args_list(1, flag);
	int sizes[] = { 1*sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Finalized(int *flag) { return c_MPI_Finalized(flag); }
extern void f_mpi_finalized(int* flag, MPI_Fint *ierr) {
	c_MPI_Finalized(flag);
}
extern void MPI_FINALIZED(int* flag, MPI_Fint *ierr) {
	f_mpi_finalized(flag, ierr);
}
extern void mpi_finalized(int* flag, MPI_Fint *ierr) {
	f_mpi_finalized(flag, ierr);
}
extern void mpi_finalized_(int* flag, MPI_Fint *ierr) {
	f_mpi_finalized(flag, ierr);
}
extern void mpi_finalized__(int* flag, MPI_Fint *ierr) {
	f_mpi_finalized(flag, ierr);
}
int c_MPI_Op_commutative(MPI_Op op, int *commute)
{
	PILGRIM_TRACING_1(int, MPI_Op_commutative, (op, commute));
	MPI_Op obj_0 = op;
	int obj_id_0 = MPI_OBJ_ID(MPI_Op, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, commute);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Op_commutative(MPI_Op op, int *commute) { return c_MPI_Op_commutative(op, commute); }
extern void f_mpi_op_commutative(MPI_Fint* op, int* commute, MPI_Fint *ierr) {
	MPI_Op c_handle_0;
	c_handle_0 = PMPI_Op_f2c(*op);
	c_MPI_Op_commutative(c_handle_0, commute);
}
extern void MPI_OP_COMMUTATIVE(MPI_Fint* op, int* commute, MPI_Fint *ierr) {
	f_mpi_op_commutative(op, commute, ierr);
}
extern void mpi_op_commutative(MPI_Fint* op, int* commute, MPI_Fint *ierr) {
	f_mpi_op_commutative(op, commute, ierr);
}
extern void mpi_op_commutative_(MPI_Fint* op, int* commute, MPI_Fint *ierr) {
	f_mpi_op_commutative(op, commute, ierr);
}
extern void mpi_op_commutative__(MPI_Fint* op, int* commute, MPI_Fint *ierr) {
	f_mpi_op_commutative(op, commute, ierr);
}
int c_MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree, const int sources[], const int sourceweights[], int outdegree, const int destinations[], const int destweights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph)
{
	PILGRIM_TRACING_1(int, MPI_Dist_graph_create_adjacent, (comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph));
	generate_intracomm_id(comm_dist_graph);
	MPI_Comm obj_0 = comm_old;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	MPI_Info obj_1 = info;
	int obj_id_1 = MPI_OBJ_ID(MPI_Info, &obj_1);
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, comm_dist_graph);
	void **args = assemble_args_list(10, &obj_id_0, &indegree, sources, sourceweights, &outdegree, destinations, destweights, &obj_id_1, &reorder, &obj_id_2);
	int sizes[] = { sizeof(int), sizeof(int), indegree*sizeof(const int), 1*sizeof(const int), sizeof(int), outdegree*sizeof(const int), 1*sizeof(const int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(10, sizes, args, -1);
}
int MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree, const int sources[], const int sourceweights[], int outdegree, const int destinations[], const int destweights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph) { return c_MPI_Dist_graph_create_adjacent(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph); }
extern void f_mpi_dist_graph_create_adjacent(MPI_Fint* comm_old, int* indegree, const int sources[], const int sourceweights[], int* outdegree, const int destinations[], const int destweights[], MPI_Fint* info, int* reorder, MPI_Fint* comm_dist_graph, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm_old);
	MPI_Info c_handle_1;
	c_handle_1 = PMPI_Info_f2c(*info);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm_dist_graph);
	c_MPI_Dist_graph_create_adjacent(c_handle_0, (*indegree), sources, sourceweights, (*outdegree), destinations, destweights, c_handle_1, (*reorder), &c_handle_2);
	*comm_dist_graph = PMPI_Comm_c2f(c_handle_2);
}
extern void MPI_DIST_GRAPH_CREATE_ADJACENT(MPI_Fint* comm_old, int* indegree, const int sources[], const int sourceweights[], int* outdegree, const int destinations[], const int destweights[], MPI_Fint* info, int* reorder, MPI_Fint* comm_dist_graph, MPI_Fint *ierr) {
	f_mpi_dist_graph_create_adjacent(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph, ierr);
}
extern void mpi_dist_graph_create_adjacent(MPI_Fint* comm_old, int* indegree, const int sources[], const int sourceweights[], int* outdegree, const int destinations[], const int destweights[], MPI_Fint* info, int* reorder, MPI_Fint* comm_dist_graph, MPI_Fint *ierr) {
	f_mpi_dist_graph_create_adjacent(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph, ierr);
}
extern void mpi_dist_graph_create_adjacent_(MPI_Fint* comm_old, int* indegree, const int sources[], const int sourceweights[], int* outdegree, const int destinations[], const int destweights[], MPI_Fint* info, int* reorder, MPI_Fint* comm_dist_graph, MPI_Fint *ierr) {
	f_mpi_dist_graph_create_adjacent(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph, ierr);
}
extern void mpi_dist_graph_create_adjacent__(MPI_Fint* comm_old, int* indegree, const int sources[], const int sourceweights[], int* outdegree, const int destinations[], const int destweights[], MPI_Fint* info, int* reorder, MPI_Fint* comm_dist_graph, MPI_Fint *ierr) {
	f_mpi_dist_graph_create_adjacent(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph, ierr);
}
int c_MPI_Info_delete(MPI_Info info, const char *key)
{
	PILGRIM_TRACING_1(int, MPI_Info_delete, (info, key));
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, key);
	int sizes[] = { sizeof(int), strlen(key)+1 };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Info_delete(MPI_Info info, const char *key) { return c_MPI_Info_delete(info, key); }
extern void f_mpi_info_delete(MPI_Fint* info, const char* key, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	c_MPI_Info_delete(c_handle_0, key);
	*info = PMPI_Info_c2f(c_handle_0);
}
extern void MPI_INFO_DELETE(MPI_Fint* info, const char* key, MPI_Fint *ierr) {
	f_mpi_info_delete(info, key, ierr);
}
extern void mpi_info_delete(MPI_Fint* info, const char* key, MPI_Fint *ierr) {
	f_mpi_info_delete(info, key, ierr);
}
extern void mpi_info_delete_(MPI_Fint* info, const char* key, MPI_Fint *ierr) {
	f_mpi_info_delete(info, key, ierr);
}
extern void mpi_info_delete__(MPI_Fint* info, const char* key, MPI_Fint *ierr) {
	f_mpi_info_delete(info, key, ierr);
}
int c_MPI_File_iread_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iread_at_all, (fh, offset, buf, count, datatype, request));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	append_offset(offset);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(4, &obj_id_0, &mem_attr_0, &count, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_File_iread_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return c_MPI_File_iread_at_all(fh, offset, buf, count, datatype, request); }
extern void f_mpi_file_iread_at_all(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_File_iread_at_all(c_handle_0, offset, buf, (*count), c_handle_1, &c_handle_2);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_FILE_IREAD_AT_ALL(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread_at_all(fh, offset, buf, count, datatype, request, ierr);
}
extern void mpi_file_iread_at_all(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread_at_all(fh, offset, buf, count, datatype, request, ierr);
}
extern void mpi_file_iread_at_all_(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread_at_all(fh, offset, buf, count, datatype, request, ierr);
}
extern void mpi_file_iread_at_all__(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread_at_all(fh, offset, buf, count, datatype, request, ierr);
}
int c_MPI_Cart_rank(MPI_Comm comm, const int coords[], int *rank)
{
	PILGRIM_TRACING_1(int, MPI_Cart_rank, (comm, coords, rank));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(3, &obj_id_0, coords, rank);
	int sizes[] = { sizeof(int), comm_size*sizeof(const int), comm_size*sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, comm_size);
}
int MPI_Cart_rank(MPI_Comm comm, const int coords[], int *rank) { return c_MPI_Cart_rank(comm, coords, rank); }
extern void f_mpi_cart_rank(MPI_Fint* comm, const int coords[], int* rank, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Cart_rank(c_handle_0, coords, rank);
}
extern void MPI_CART_RANK(MPI_Fint* comm, const int coords[], int* rank, MPI_Fint *ierr) {
	f_mpi_cart_rank(comm, coords, rank, ierr);
}
extern void mpi_cart_rank(MPI_Fint* comm, const int coords[], int* rank, MPI_Fint *ierr) {
	f_mpi_cart_rank(comm, coords, rank, ierr);
}
extern void mpi_cart_rank_(MPI_Fint* comm, const int coords[], int* rank, MPI_Fint *ierr) {
	f_mpi_cart_rank(comm, coords, rank, ierr);
}
extern void mpi_cart_rank__(MPI_Fint* comm, const int coords[], int* rank, MPI_Fint *ierr) {
	f_mpi_cart_rank(comm, coords, rank, ierr);
}
int c_MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read_at, (fh, offset, buf, count, datatype, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	append_offset(offset);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	int status_arg[2] = {0};
	void **args = assemble_args_list(5, &obj_id_0, &mem_attr_0, &count, &obj_id_1, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return c_MPI_File_read_at(fh, offset, buf, count, datatype, status); }
extern void f_mpi_file_read_at(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_File_read_at(c_handle_0, offset, buf, (*count), c_handle_1, &c_handle_2);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_FILE_READ_AT(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_at(fh, offset, buf, count, datatype, status, ierr);
}
extern void mpi_file_read_at(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_at(fh, offset, buf, count, datatype, status, ierr);
}
extern void mpi_file_read_at_(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_at(fh, offset, buf, count, datatype, status, ierr);
}
extern void mpi_file_read_at__(MPI_Fint* fh, MPI_Offset offset, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_at(fh, offset, buf, count, datatype, status, ierr);
}
int c_MPI_Iallreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Iallreduce, (sendbuf, recvbuf, count, datatype, op, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Op obj_1 = op;
	int obj_id_1 = MPI_OBJ_ID(MPI_Op, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(6, &mem_attr_0, &mem_attr_1, &count, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Iallreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { return c_MPI_Iallreduce(sendbuf, recvbuf, count, datatype, op, comm, request); }
extern void f_mpi_iallreduce(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Op c_handle_1;
	c_handle_1 = PMPI_Op_f2c(*op);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Iallreduce(sendbuf, recvbuf, (*count), c_handle_0, c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_IALLREDUCE(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iallreduce(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}
extern void mpi_iallreduce(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iallreduce(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}
extern void mpi_iallreduce_(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iallreduce(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}
extern void mpi_iallreduce__(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iallreduce(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}
int c_MPI_Type_size(MPI_Datatype datatype, int *size)
{
	PILGRIM_TRACING_1(int, MPI_Type_size, (datatype, size));
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, size);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Type_size(MPI_Datatype datatype, int *size) { return c_MPI_Type_size(datatype, size); }
extern void f_mpi_type_size(MPI_Fint* datatype, int* size, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Type_size(c_handle_0, size);
}
extern void MPI_TYPE_SIZE(MPI_Fint* datatype, int* size, MPI_Fint *ierr) {
	f_mpi_type_size(datatype, size, ierr);
}
extern void mpi_type_size(MPI_Fint* datatype, int* size, MPI_Fint *ierr) {
	f_mpi_type_size(datatype, size, ierr);
}
extern void mpi_type_size_(MPI_Fint* datatype, int* size, MPI_Fint *ierr) {
	f_mpi_type_size(datatype, size, ierr);
}
extern void mpi_type_size__(MPI_Fint* datatype, int* size, MPI_Fint *ierr) {
	f_mpi_type_size(datatype, size, ierr);
}
int c_MPI_Fetch_and_op(const void *origin_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Op op, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Fetch_and_op, (origin_addr, result_addr, datatype, target_rank, target_disp, op, win));
	MemPtrAttr mem_attr_0;
	addr2id(origin_addr, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(result_addr, &mem_attr_1);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Op obj_1 = op;
	int obj_id_1 = MPI_OBJ_ID(MPI_Op, &obj_1);
	MPI_Win obj_2 = win;
	int obj_id_2 = MPI_OBJ_ID(MPI_Win, &obj_2);
	void **args = assemble_args_list(7, &mem_attr_0, &mem_attr_1, &obj_id_0, &target_rank, &target_disp, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Fetch_and_op(const void *origin_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Op op, MPI_Win win) { return c_MPI_Fetch_and_op(origin_addr, result_addr, datatype, target_rank, target_disp, op, win); }
extern void f_mpi_fetch_and_op(const void* origin_addr, void* result_addr, MPI_Fint* datatype, int* target_rank, MPI_Aint target_disp, MPI_Fint* op, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Op c_handle_1;
	c_handle_1 = PMPI_Op_f2c(*op);
	MPI_Win c_handle_2;
	c_handle_2 = PMPI_Win_f2c(*win);
	c_MPI_Fetch_and_op(origin_addr, result_addr, c_handle_0, (*target_rank), target_disp, c_handle_1, c_handle_2);
}
extern void MPI_FETCH_AND_OP(const void* origin_addr, void* result_addr, MPI_Fint* datatype, int* target_rank, MPI_Aint target_disp, MPI_Fint* op, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_fetch_and_op(origin_addr, result_addr, datatype, target_rank, target_disp, op, win, ierr);
}
extern void mpi_fetch_and_op(const void* origin_addr, void* result_addr, MPI_Fint* datatype, int* target_rank, MPI_Aint target_disp, MPI_Fint* op, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_fetch_and_op(origin_addr, result_addr, datatype, target_rank, target_disp, op, win, ierr);
}
extern void mpi_fetch_and_op_(const void* origin_addr, void* result_addr, MPI_Fint* datatype, int* target_rank, MPI_Aint target_disp, MPI_Fint* op, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_fetch_and_op(origin_addr, result_addr, datatype, target_rank, target_disp, op, win, ierr);
}
extern void mpi_fetch_and_op__(const void* origin_addr, void* result_addr, MPI_Fint* datatype, int* target_rank, MPI_Aint target_disp, MPI_Fint* op, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_fetch_and_op(origin_addr, result_addr, datatype, target_rank, target_disp, op, win, ierr);
}
int c_MPI_Reduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Reduce_scatter_block, (sendbuf, recvbuf, recvcount, datatype, op, comm));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Op obj_1 = op;
	int obj_id_1 = MPI_OBJ_ID(MPI_Op, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(6, &mem_attr_0, &mem_attr_1, &recvcount, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Reduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { return c_MPI_Reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm); }
extern void f_mpi_reduce_scatter_block(const void* sendbuf, void* recvbuf, int* recvcount, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Op c_handle_1;
	c_handle_1 = PMPI_Op_f2c(*op);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Reduce_scatter_block(sendbuf, recvbuf, (*recvcount), c_handle_0, c_handle_1, c_handle_2);
}
extern void MPI_REDUCE_SCATTER_BLOCK(const void* sendbuf, void* recvbuf, int* recvcount, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, ierr);
}
extern void mpi_reduce_scatter_block(const void* sendbuf, void* recvbuf, int* recvcount, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, ierr);
}
extern void mpi_reduce_scatter_block_(const void* sendbuf, void* recvbuf, int* recvcount, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, ierr);
}
extern void mpi_reduce_scatter_block__(const void* sendbuf, void* recvbuf, int* recvcount, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, ierr);
}
int c_MPI_Rget(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Rget, (origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request));
	MemPtrAttr mem_attr_0;
	addr2id(origin_addr, &mem_attr_0);
	MPI_Datatype obj_0 = origin_datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Datatype obj_1 = target_datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Win obj_2 = win;
	int obj_id_2 = MPI_OBJ_ID(MPI_Win, &obj_2);
	void **args = assemble_args_list(8, &mem_attr_0, &origin_count, &obj_id_0, &target_rank, &target_disp, &target_count, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(8, sizes, args, -1);
}
int MPI_Rget(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request) { return c_MPI_Rget(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request); }
extern void f_mpi_rget(void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*origin_datatype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*target_datatype);
	MPI_Win c_handle_2;
	c_handle_2 = PMPI_Win_f2c(*win);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Rget(origin_addr, (*origin_count), c_handle_0, (*target_rank), target_disp, (*target_count), c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_RGET(void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_rget(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierr);
}
extern void mpi_rget(void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_rget(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierr);
}
extern void mpi_rget_(void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_rget(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierr);
}
extern void mpi_rget__(void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_rget(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierr);
}
int c_MPI_Win_set_attr(MPI_Win win, int win_keyval, void *attribute_val)
{
	PILGRIM_TRACING_1(int, MPI_Win_set_attr, (win, win_keyval, attribute_val));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(attribute_val, &mem_attr_0);
	void **args = assemble_args_list(3, &obj_id_0, &win_keyval, &mem_attr_0);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Win_set_attr(MPI_Win win, int win_keyval, void *attribute_val) { return c_MPI_Win_set_attr(win, win_keyval, attribute_val); }
extern void f_mpi_win_set_attr(MPI_Fint* win, int* win_keyval, void* attribute_val, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_set_attr(c_handle_0, (*win_keyval), attribute_val);
	*win = PMPI_Win_c2f(c_handle_0);
}
extern void MPI_WIN_SET_ATTR(MPI_Fint* win, int* win_keyval, void* attribute_val, MPI_Fint *ierr) {
	f_mpi_win_set_attr(win, win_keyval, attribute_val, ierr);
}
extern void mpi_win_set_attr(MPI_Fint* win, int* win_keyval, void* attribute_val, MPI_Fint *ierr) {
	f_mpi_win_set_attr(win, win_keyval, attribute_val, ierr);
}
extern void mpi_win_set_attr_(MPI_Fint* win, int* win_keyval, void* attribute_val, MPI_Fint *ierr) {
	f_mpi_win_set_attr(win, win_keyval, attribute_val, ierr);
}
extern void mpi_win_set_attr__(MPI_Fint* win, int* win_keyval, void* attribute_val, MPI_Fint *ierr) {
	f_mpi_win_set_attr(win, win_keyval, attribute_val, ierr);
}
int c_MPI_Type_create_f90_integer(int r, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_f90_integer, (r, newtype));
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, newtype);
	void **args = assemble_args_list(2, &r, &obj_id_0);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Type_create_f90_integer(int r, MPI_Datatype *newtype) { return c_MPI_Type_create_f90_integer(r, newtype); }
extern void f_mpi_type_create_f90_integer(int* r, MPI_Fint* newtype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*newtype);
	c_MPI_Type_create_f90_integer((*r), &c_handle_0);
	*newtype = PMPI_Type_c2f(c_handle_0);
}
extern void MPI_TYPE_CREATE_F90_INTEGER(int* r, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_f90_integer(r, newtype, ierr);
}
extern void mpi_type_create_f90_integer(int* r, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_f90_integer(r, newtype, ierr);
}
extern void mpi_type_create_f90_integer_(int* r, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_f90_integer(r, newtype, ierr);
}
extern void mpi_type_create_f90_integer__(int* r, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_f90_integer(r, newtype, ierr);
}
int c_MPI_Iscatterv(const void *sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Iscatterv, (sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(9, &mem_attr_0, sendcounts, displs, &obj_id_0, &mem_attr_1, &recvcount, &obj_id_1, &root, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args, comm_size);
}
int MPI_Iscatterv(const void *sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { return c_MPI_Iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request); }
extern void f_mpi_iscatterv(const void* sendbuf, const int sendcounts[], const int displs[], MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Iscatterv(sendbuf, sendcounts, displs, c_handle_0, recvbuf, (*recvcount), c_handle_1, (*root), c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_ISCATTERV(const void* sendbuf, const int sendcounts[], const int displs[], MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}
extern void mpi_iscatterv(const void* sendbuf, const int sendcounts[], const int displs[], MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}
extern void mpi_iscatterv_(const void* sendbuf, const int sendcounts[], const int displs[], MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}
extern void mpi_iscatterv__(const void* sendbuf, const int sendcounts[], const int displs[], MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}
int c_MPI_File_delete(const char *filename, MPI_Info info)
{
	PILGRIM_TRACING_1(int, MPI_File_delete, (filename, info));
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	void **args = assemble_args_list(2, filename, &obj_id_0);
	int sizes[] = { strlen(filename)+1, sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_delete(const char *filename, MPI_Info info) { return c_MPI_File_delete(filename, info); }
extern void f_mpi_file_delete(const char* filename, MPI_Fint* info, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	c_MPI_File_delete(filename, c_handle_0);
}
extern void MPI_FILE_DELETE(const char* filename, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_file_delete(filename, info, ierr);
}
extern void mpi_file_delete(const char* filename, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_file_delete(filename, info, ierr);
}
extern void mpi_file_delete_(const char* filename, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_file_delete(filename, info, ierr);
}
extern void mpi_file_delete__(const char* filename, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_file_delete(filename, info, ierr);
}
int c_MPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read_all, (fh, buf, count, datatype, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	int status_arg[2] = {0};
	void **args = assemble_args_list(5, &obj_id_0, &mem_attr_0, &count, &obj_id_1, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return c_MPI_File_read_all(fh, buf, count, datatype, status); }
extern void f_mpi_file_read_all(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_File_read_all(c_handle_0, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_FILE_READ_ALL(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_all(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_read_all(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_all(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_read_all_(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_all(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_read_all__(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_all(fh, buf, count, datatype, status, ierr);
}
int c_MPI_Group_size(MPI_Group group, int *size)
{
	PILGRIM_TRACING_1(int, MPI_Group_size, (group, size));
	MPI_Group obj_0 = group;
	int obj_id_0 = MPI_OBJ_ID(MPI_Group, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, size);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Group_size(MPI_Group group, int *size) { return c_MPI_Group_size(group, size); }
extern void f_mpi_group_size(MPI_Fint* group, int* size, MPI_Fint *ierr) {
	MPI_Group c_handle_0;
	c_handle_0 = PMPI_Group_f2c(*group);
	c_MPI_Group_size(c_handle_0, size);
}
extern void MPI_GROUP_SIZE(MPI_Fint* group, int* size, MPI_Fint *ierr) {
	f_mpi_group_size(group, size, ierr);
}
extern void mpi_group_size(MPI_Fint* group, int* size, MPI_Fint *ierr) {
	f_mpi_group_size(group, size, ierr);
}
extern void mpi_group_size_(MPI_Fint* group, int* size, MPI_Fint *ierr) {
	f_mpi_group_size(group, size, ierr);
}
extern void mpi_group_size__(MPI_Fint* group, int* size, MPI_Fint *ierr) {
	f_mpi_group_size(group, size, ierr);
}
int c_MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val)
{
	PILGRIM_TRACING_1(int, MPI_Attr_put, (comm, keyval, attribute_val));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(attribute_val, &mem_attr_0);
	void **args = assemble_args_list(3, &obj_id_0, &keyval, &mem_attr_0);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val) { return c_MPI_Attr_put(comm, keyval, attribute_val); }
extern void f_mpi_attr_put(MPI_Fint* comm, int* keyval, void* attribute_val, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Attr_put(c_handle_0, (*keyval), attribute_val);
	*comm = PMPI_Comm_c2f(c_handle_0);
}
extern void MPI_ATTR_PUT(MPI_Fint* comm, int* keyval, void* attribute_val, MPI_Fint *ierr) {
	f_mpi_attr_put(comm, keyval, attribute_val, ierr);
}
extern void mpi_attr_put(MPI_Fint* comm, int* keyval, void* attribute_val, MPI_Fint *ierr) {
	f_mpi_attr_put(comm, keyval, attribute_val, ierr);
}
extern void mpi_attr_put_(MPI_Fint* comm, int* keyval, void* attribute_val, MPI_Fint *ierr) {
	f_mpi_attr_put(comm, keyval, attribute_val, ierr);
}
extern void mpi_attr_put__(MPI_Fint* comm, int* keyval, void* attribute_val, MPI_Fint *ierr) {
	f_mpi_attr_put(comm, keyval, attribute_val, ierr);
}
int c_MPI_Iscatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Iscatter, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(8, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, &recvcount, &obj_id_1, &root, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(8, sizes, args, -1);
}
int MPI_Iscatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { return c_MPI_Iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request); }
extern void f_mpi_iscatter(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Iscatter(sendbuf, (*sendcount), c_handle_0, recvbuf, (*recvcount), c_handle_1, (*root), c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_ISCATTER(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}
extern void mpi_iscatter(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}
extern void mpi_iscatter_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}
extern void mpi_iscatter__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}
int c_MPI_Win_start(MPI_Group group, int assert, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_start, (group, assert, win));
	MPI_Group obj_0 = group;
	int obj_id_0 = MPI_OBJ_ID(MPI_Group, &obj_0);
	MPI_Win obj_1 = win;
	int obj_id_1 = MPI_OBJ_ID(MPI_Win, &obj_1);
	void **args = assemble_args_list(3, &obj_id_0, &assert, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Win_start(MPI_Group group, int assert, MPI_Win win) { return c_MPI_Win_start(group, assert, win); }
extern void f_mpi_win_start(MPI_Fint* group, int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Group c_handle_0;
	c_handle_0 = PMPI_Group_f2c(*group);
	MPI_Win c_handle_1;
	c_handle_1 = PMPI_Win_f2c(*win);
	c_MPI_Win_start(c_handle_0, (*assert), c_handle_1);
}
extern void MPI_WIN_START(MPI_Fint* group, int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_start(group, assert, win, ierr);
}
extern void mpi_win_start(MPI_Fint* group, int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_start(group, assert, win, ierr);
}
extern void mpi_win_start_(MPI_Fint* group, int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_start(group, assert, win, ierr);
}
extern void mpi_win_start__(MPI_Fint* group, int* assert, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_start(group, assert, win, ierr);
}
int c_MPI_Win_free(MPI_Win *win)
{
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, win);
	void **args = assemble_args_list(1, &obj_id_0);
	MPI_OBJ_RELEASE(MPI_Win, win);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_1(int, MPI_Win_free, (win));
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Win_free(MPI_Win *win) { return c_MPI_Win_free(win); }
extern void f_mpi_win_free(MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_free(&c_handle_0);
	*win = PMPI_Win_c2f(c_handle_0);
}
extern void MPI_WIN_FREE(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_free(win, ierr);
}
extern void mpi_win_free(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_free(win, ierr);
}
extern void mpi_win_free_(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_free(win, ierr);
}
extern void mpi_win_free__(MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_free(win, ierr);
}
int c_MPI_Alltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Alltoallw, (sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	int obj_id_0[comm_size];
	for(int i=0; i<comm_size; i++) obj_id_0[i] = (sendtypes==NULL) ? PILGRIM_INVALID_MPI_OBJECT_ID: MPI_OBJ_ID(MPI_Datatype, &sendtypes[i]);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	int obj_id_1[comm_size];
	for(int i=0; i<comm_size; i++) obj_id_1[i] = (recvtypes==NULL) ? PILGRIM_INVALID_MPI_OBJECT_ID: MPI_OBJ_ID(MPI_Datatype, &recvtypes[i]);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(9, &mem_attr_0, sendcounts, sdispls, obj_id_0, &mem_attr_1, recvcounts, rdispls, obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), (comm_size)*sizeof(int), sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), (comm_size)*sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args, comm_size);
}
int MPI_Alltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) { return c_MPI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm); }
extern void f_mpi_alltoallw(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0[comm_size];
	for(int i = 0; i < comm_size; i++) c_handle_0[i] = PMPI_Type_f2c(sendtypes[i]);
	MPI_Datatype c_handle_1[comm_size];
	for(int i = 0; i < comm_size; i++) c_handle_1[i] = PMPI_Type_f2c(recvtypes[i]);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Alltoallw(sendbuf, sendcounts, sdispls, c_handle_0, recvbuf, recvcounts, rdispls, c_handle_1, c_handle_2);
}
extern void MPI_ALLTOALLW(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}
extern void mpi_alltoallw(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}
extern void mpi_alltoallw_(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}
extern void mpi_alltoallw__(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}
int c_MPI_Alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Alltoallv, (sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(9, &mem_attr_0, sendcounts, sdispls, &obj_id_0, &mem_attr_1, recvcounts, rdispls, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), sizeof(int), sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args, comm_size);
}
int MPI_Alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm) { return c_MPI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm); }
extern void f_mpi_alltoallv(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Alltoallv(sendbuf, sendcounts, sdispls, c_handle_0, recvbuf, recvcounts, rdispls, c_handle_1, c_handle_2);
}
extern void MPI_ALLTOALLV(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}
extern void mpi_alltoallv(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}
extern void mpi_alltoallv_(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}
extern void mpi_alltoallv__(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}
int c_MPI_Exscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Exscan, (sendbuf, recvbuf, count, datatype, op, comm));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Op obj_1 = op;
	int obj_id_1 = MPI_OBJ_ID(MPI_Op, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(6, &mem_attr_0, &mem_attr_1, &count, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Exscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { return c_MPI_Exscan(sendbuf, recvbuf, count, datatype, op, comm); }
extern void f_mpi_exscan(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Op c_handle_1;
	c_handle_1 = PMPI_Op_f2c(*op);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Exscan(sendbuf, recvbuf, (*count), c_handle_0, c_handle_1, c_handle_2);
}
extern void MPI_EXSCAN(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_exscan(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}
extern void mpi_exscan(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_exscan(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}
extern void mpi_exscan_(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_exscan(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}
extern void mpi_exscan__(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_exscan(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}
int c_MPI_Op_free(MPI_Op *op)
{
	int obj_id_0 = MPI_OBJ_ID(MPI_Op, op);
	void **args = assemble_args_list(1, &obj_id_0);
	MPI_OBJ_RELEASE(MPI_Op, op);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_1(int, MPI_Op_free, (op));
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Op_free(MPI_Op *op) { return c_MPI_Op_free(op); }
extern void f_mpi_op_free(MPI_Fint* op, MPI_Fint *ierr) {
	MPI_Op c_handle_0;
	c_handle_0 = PMPI_Op_f2c(*op);
	c_MPI_Op_free(&c_handle_0);
	*op = PMPI_Op_c2f(c_handle_0);
}
extern void MPI_OP_FREE(MPI_Fint* op, MPI_Fint *ierr) {
	f_mpi_op_free(op, ierr);
}
extern void mpi_op_free(MPI_Fint* op, MPI_Fint *ierr) {
	f_mpi_op_free(op, ierr);
}
extern void mpi_op_free_(MPI_Fint* op, MPI_Fint *ierr) {
	f_mpi_op_free(op, ierr);
}
extern void mpi_op_free__(MPI_Fint* op, MPI_Fint *ierr) {
	f_mpi_op_free(op, ierr);
}
int c_MPI_Iscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Iscan, (sendbuf, recvbuf, count, datatype, op, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Op obj_1 = op;
	int obj_id_1 = MPI_OBJ_ID(MPI_Op, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(6, &mem_attr_0, &mem_attr_1, &count, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Iscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { return c_MPI_Iscan(sendbuf, recvbuf, count, datatype, op, comm, request); }
extern void f_mpi_iscan(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Op c_handle_1;
	c_handle_1 = PMPI_Op_f2c(*op);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Iscan(sendbuf, recvbuf, (*count), c_handle_0, c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_ISCAN(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iscan(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}
extern void mpi_iscan(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iscan(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}
extern void mpi_iscan_(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iscan(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}
extern void mpi_iscan__(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iscan(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}
int c_MPI_Keyval_create(MPI_Copy_function *copy_fn, MPI_Delete_function *delete_fn, int *keyval, void *extra_state)
{
	PILGRIM_TRACING_1(int, MPI_Keyval_create, (copy_fn, delete_fn, keyval, extra_state));
	MemPtrAttr mem_attr_0;
	addr2id(extra_state, &mem_attr_0);
	void **args = assemble_args_list(4, copy_fn, delete_fn, keyval, &mem_attr_0);
	int sizes[] = { 1*sizeof(MPI_Copy_function), 1*sizeof(MPI_Delete_function), 1*sizeof(int), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Keyval_create(MPI_Copy_function *copy_fn, MPI_Delete_function *delete_fn, int *keyval, void *extra_state) { return c_MPI_Keyval_create(copy_fn, delete_fn, keyval, extra_state); }
extern void f_mpi_keyval_create(MPI_Copy_function* copy_fn, MPI_Delete_function* delete_fn, int* keyval, void* extra_state, MPI_Fint *ierr) {
	c_MPI_Keyval_create(copy_fn, delete_fn, keyval, extra_state);
}
extern void MPI_KEYVAL_CREATE(MPI_Copy_function* copy_fn, MPI_Delete_function* delete_fn, int* keyval, void* extra_state, MPI_Fint *ierr) {
	f_mpi_keyval_create(copy_fn, delete_fn, keyval, extra_state, ierr);
}
extern void mpi_keyval_create(MPI_Copy_function* copy_fn, MPI_Delete_function* delete_fn, int* keyval, void* extra_state, MPI_Fint *ierr) {
	f_mpi_keyval_create(copy_fn, delete_fn, keyval, extra_state, ierr);
}
extern void mpi_keyval_create_(MPI_Copy_function* copy_fn, MPI_Delete_function* delete_fn, int* keyval, void* extra_state, MPI_Fint *ierr) {
	f_mpi_keyval_create(copy_fn, delete_fn, keyval, extra_state, ierr);
}
extern void mpi_keyval_create__(MPI_Copy_function* copy_fn, MPI_Delete_function* delete_fn, int* keyval, void* extra_state, MPI_Fint *ierr) {
	f_mpi_keyval_create(copy_fn, delete_fn, keyval, extra_state, ierr);
}
int c_MPI_Type_vector(int count, int blocklength, int stride, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_vector, (count, blocklength, stride, oldtype, newtype));
	MPI_Datatype obj_0 = oldtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, newtype);
	void **args = assemble_args_list(5, &count, &blocklength, &stride, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Type_vector(int count, int blocklength, int stride, MPI_Datatype oldtype, MPI_Datatype *newtype) { return c_MPI_Type_vector(count, blocklength, stride, oldtype, newtype); }
extern void f_mpi_type_vector(int* count, int* blocklength, int* stride, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*oldtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*newtype);
	c_MPI_Type_vector((*count), (*blocklength), (*stride), c_handle_0, &c_handle_1);
	*newtype = PMPI_Type_c2f(c_handle_1);
}
extern void MPI_TYPE_VECTOR(int* count, int* blocklength, int* stride, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_vector(count, blocklength, stride, oldtype, newtype, ierr);
}
extern void mpi_type_vector(int* count, int* blocklength, int* stride, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_vector(count, blocklength, stride, oldtype, newtype, ierr);
}
extern void mpi_type_vector_(int* count, int* blocklength, int* stride, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_vector(count, blocklength, stride, oldtype, newtype, ierr);
}
extern void mpi_type_vector__(int* count, int* blocklength, int* stride, MPI_Fint* oldtype, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_vector(count, blocklength, stride, oldtype, newtype, ierr);
}
int c_MPI_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn, MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval, void *extra_state)
{
	PILGRIM_TRACING_1(int, MPI_Win_create_keyval, (win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state));
	MemPtrAttr mem_attr_0;
	addr2id(extra_state, &mem_attr_0);
	void **args = assemble_args_list(4, win_copy_attr_fn, win_delete_attr_fn, win_keyval, &mem_attr_0);
	int sizes[] = { 1*sizeof(MPI_Win_copy_attr_function), 1*sizeof(MPI_Win_delete_attr_function), 1*sizeof(int), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn, MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval, void *extra_state) { return c_MPI_Win_create_keyval(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state); }
extern void f_mpi_win_create_keyval(MPI_Win_copy_attr_function* win_copy_attr_fn, MPI_Win_delete_attr_function* win_delete_attr_fn, int* win_keyval, void* extra_state, MPI_Fint *ierr) {
	c_MPI_Win_create_keyval(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state);
}
extern void MPI_WIN_CREATE_KEYVAL(MPI_Win_copy_attr_function* win_copy_attr_fn, MPI_Win_delete_attr_function* win_delete_attr_fn, int* win_keyval, void* extra_state, MPI_Fint *ierr) {
	f_mpi_win_create_keyval(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state, ierr);
}
extern void mpi_win_create_keyval(MPI_Win_copy_attr_function* win_copy_attr_fn, MPI_Win_delete_attr_function* win_delete_attr_fn, int* win_keyval, void* extra_state, MPI_Fint *ierr) {
	f_mpi_win_create_keyval(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state, ierr);
}
extern void mpi_win_create_keyval_(MPI_Win_copy_attr_function* win_copy_attr_fn, MPI_Win_delete_attr_function* win_delete_attr_fn, int* win_keyval, void* extra_state, MPI_Fint *ierr) {
	f_mpi_win_create_keyval(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state, ierr);
}
extern void mpi_win_create_keyval__(MPI_Win_copy_attr_function* win_copy_attr_fn, MPI_Win_delete_attr_function* win_delete_attr_fn, int* win_keyval, void* extra_state, MPI_Fint *ierr) {
	f_mpi_win_create_keyval(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state, ierr);
}
int c_MPI_Type_match_size(int typeclass, int size, MPI_Datatype *datatype)
{
	PILGRIM_TRACING_1(int, MPI_Type_match_size, (typeclass, size, datatype));
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, datatype);
	void **args = assemble_args_list(3, &typeclass, &size, &obj_id_0);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Type_match_size(int typeclass, int size, MPI_Datatype *datatype) { return c_MPI_Type_match_size(typeclass, size, datatype); }
extern void f_mpi_type_match_size(int* typeclass, int* size, MPI_Fint* datatype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Type_match_size((*typeclass), (*size), &c_handle_0);
	*datatype = PMPI_Type_c2f(c_handle_0);
}
extern void MPI_TYPE_MATCH_SIZE(int* typeclass, int* size, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_type_match_size(typeclass, size, datatype, ierr);
}
extern void mpi_type_match_size(int* typeclass, int* size, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_type_match_size(typeclass, size, datatype, ierr);
}
extern void mpi_type_match_size_(int* typeclass, int* size, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_type_match_size(typeclass, size, datatype, ierr);
}
extern void mpi_type_match_size__(int* typeclass, int* size, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_type_match_size(typeclass, size, datatype, ierr);
}
int c_MPI_Scan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Scan, (sendbuf, recvbuf, count, datatype, op, comm));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Op obj_1 = op;
	int obj_id_1 = MPI_OBJ_ID(MPI_Op, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(6, &mem_attr_0, &mem_attr_1, &count, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Scan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { return c_MPI_Scan(sendbuf, recvbuf, count, datatype, op, comm); }
extern void f_mpi_scan(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Op c_handle_1;
	c_handle_1 = PMPI_Op_f2c(*op);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Scan(sendbuf, recvbuf, (*count), c_handle_0, c_handle_1, c_handle_2);
}
extern void MPI_SCAN(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_scan(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}
extern void mpi_scan(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_scan(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}
extern void mpi_scan_(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_scan(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}
extern void mpi_scan__(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_scan(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}
int c_MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence)
{
	PILGRIM_TRACING_1(int, MPI_File_seek_shared, (fh, offset, whence));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	append_offset(offset);
	void **args = assemble_args_list(2, &obj_id_0, &whence);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence) { return c_MPI_File_seek_shared(fh, offset, whence); }
extern void f_mpi_file_seek_shared(MPI_Fint* fh, MPI_Offset offset, int* whence, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	c_MPI_File_seek_shared(c_handle_0, offset, (*whence));
	*fh = PMPI_File_c2f(c_handle_0);
}
extern void MPI_FILE_SEEK_SHARED(MPI_Fint* fh, MPI_Offset offset, int* whence, MPI_Fint *ierr) {
	f_mpi_file_seek_shared(fh, offset, whence, ierr);
}
extern void mpi_file_seek_shared(MPI_Fint* fh, MPI_Offset offset, int* whence, MPI_Fint *ierr) {
	f_mpi_file_seek_shared(fh, offset, whence, ierr);
}
extern void mpi_file_seek_shared_(MPI_Fint* fh, MPI_Offset offset, int* whence, MPI_Fint *ierr) {
	f_mpi_file_seek_shared(fh, offset, whence, ierr);
}
extern void mpi_file_seek_shared__(MPI_Fint* fh, MPI_Offset offset, int* whence, MPI_Fint *ierr) {
	f_mpi_file_seek_shared(fh, offset, whence, ierr);
}
int c_MPI_Add_error_class(int *errorclass)
{
	PILGRIM_TRACING_1(int, MPI_Add_error_class, (errorclass));
	void **args = assemble_args_list(1, errorclass);
	int sizes[] = { 1*sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Add_error_class(int *errorclass) { return c_MPI_Add_error_class(errorclass); }
extern void f_mpi_add_error_class(int* errorclass, MPI_Fint *ierr) {
	c_MPI_Add_error_class(errorclass);
}
extern void MPI_ADD_ERROR_CLASS(int* errorclass, MPI_Fint *ierr) {
	f_mpi_add_error_class(errorclass, ierr);
}
extern void mpi_add_error_class(int* errorclass, MPI_Fint *ierr) {
	f_mpi_add_error_class(errorclass, ierr);
}
extern void mpi_add_error_class_(int* errorclass, MPI_Fint *ierr) {
	f_mpi_add_error_class(errorclass, ierr);
}
extern void mpi_add_error_class__(int* errorclass, MPI_Fint *ierr) {
	f_mpi_add_error_class(errorclass, ierr);
}
int c_MPI_Igather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Igather, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(8, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, &recvcount, &obj_id_1, &root, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(8, sizes, args, -1);
}
int MPI_Igather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { return c_MPI_Igather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request); }
extern void f_mpi_igather(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Igather(sendbuf, (*sendcount), c_handle_0, recvbuf, (*recvcount), c_handle_1, (*root), c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_IGATHER(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_igather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}
extern void mpi_igather(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_igather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}
extern void mpi_igather_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_igather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}
extern void mpi_igather__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_igather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierr);
}
int c_MPI_Info_free(MPI_Info *info)
{
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, info);
	void **args = assemble_args_list(1, &obj_id_0);
	MPI_OBJ_RELEASE(MPI_Info, info);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_1(int, MPI_Info_free, (info));
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Info_free(MPI_Info *info) { return c_MPI_Info_free(info); }
extern void f_mpi_info_free(MPI_Fint* info, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	c_MPI_Info_free(&c_handle_0);
	*info = PMPI_Info_c2f(c_handle_0);
}
extern void MPI_INFO_FREE(MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_info_free(info, ierr);
}
extern void mpi_info_free(MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_info_free(info, ierr);
}
extern void mpi_info_free_(MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_info_free(info, ierr);
}
extern void mpi_info_free__(MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_info_free(info, ierr);
}
int c_MPI_Open_port(MPI_Info info, char *port_name)
{
	PILGRIM_TRACING_1(int, MPI_Open_port, (info, port_name));
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, port_name);
	int sizes[] = { sizeof(int), strlen(port_name)+1 };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Open_port(MPI_Info info, char *port_name) { return c_MPI_Open_port(info, port_name); }
extern void f_mpi_open_port(MPI_Fint* info, char* port_name, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	c_MPI_Open_port(c_handle_0, port_name);
}
extern void MPI_OPEN_PORT(MPI_Fint* info, char* port_name, MPI_Fint *ierr) {
	f_mpi_open_port(info, port_name, ierr);
}
extern void mpi_open_port(MPI_Fint* info, char* port_name, MPI_Fint *ierr) {
	f_mpi_open_port(info, port_name, ierr);
}
extern void mpi_open_port_(MPI_Fint* info, char* port_name, MPI_Fint *ierr) {
	f_mpi_open_port(info, port_name, ierr);
}
extern void mpi_open_port__(MPI_Fint* info, char* port_name, MPI_Fint *ierr) {
	f_mpi_open_port(info, port_name, ierr);
}
int c_MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win)
{
	PILGRIM_TRACING_1(int, MPI_Win_allocate, (size, disp_unit, info, comm, baseptr, win));
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	MemPtrAttr mem_attr_0;
	addr2id(baseptr, &mem_attr_0);
	int obj_id_2 = MPI_OBJ_ID(MPI_Win, win);
	void **args = assemble_args_list(6, &size, &disp_unit, &obj_id_0, &obj_id_1, &mem_attr_0, &obj_id_2);
	int sizes[] = { sizeof(MPI_Aint), sizeof(int), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win) { return c_MPI_Win_allocate(size, disp_unit, info, comm, baseptr, win); }
extern void f_mpi_win_allocate(MPI_Aint size, int* disp_unit, MPI_Fint* info, MPI_Fint* comm, void* baseptr, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Win c_handle_2;
	c_handle_2 = PMPI_Win_f2c(*win);
	c_MPI_Win_allocate(size, (*disp_unit), c_handle_0, c_handle_1, baseptr, &c_handle_2);
	*win = PMPI_Win_c2f(c_handle_2);
}
extern void MPI_WIN_ALLOCATE(MPI_Aint size, int* disp_unit, MPI_Fint* info, MPI_Fint* comm, void* baseptr, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_allocate(size, disp_unit, info, comm, baseptr, win, ierr);
}
extern void mpi_win_allocate(MPI_Aint size, int* disp_unit, MPI_Fint* info, MPI_Fint* comm, void* baseptr, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_allocate(size, disp_unit, info, comm, baseptr, win, ierr);
}
extern void mpi_win_allocate_(MPI_Aint size, int* disp_unit, MPI_Fint* info, MPI_Fint* comm, void* baseptr, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_allocate(size, disp_unit, info, comm, baseptr, win, ierr);
}
extern void mpi_win_allocate__(MPI_Aint size, int* disp_unit, MPI_Fint* info, MPI_Fint* comm, void* baseptr, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_allocate(size, disp_unit, info, comm, baseptr, win, ierr);
}
int c_MPI_Win_set_info(MPI_Win win, MPI_Info info)
{
	PILGRIM_TRACING_1(int, MPI_Win_set_info, (win, info));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	MPI_Info obj_1 = info;
	int obj_id_1 = MPI_OBJ_ID(MPI_Info, &obj_1);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Win_set_info(MPI_Win win, MPI_Info info) { return c_MPI_Win_set_info(win, info); }
extern void f_mpi_win_set_info(MPI_Fint* win, MPI_Fint* info, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	MPI_Info c_handle_1;
	c_handle_1 = PMPI_Info_f2c(*info);
	c_MPI_Win_set_info(c_handle_0, c_handle_1);
	*win = PMPI_Win_c2f(c_handle_0);
}
extern void MPI_WIN_SET_INFO(MPI_Fint* win, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_win_set_info(win, info, ierr);
}
extern void mpi_win_set_info(MPI_Fint* win, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_win_set_info(win, info, ierr);
}
extern void mpi_win_set_info_(MPI_Fint* win, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_win_set_info(win, info, ierr);
}
extern void mpi_win_set_info__(MPI_Fint* win, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_win_set_info(win, info, ierr);
}
int c_MPI_Unpublish_name(const char *service_name, MPI_Info info, const char *port_name)
{
	PILGRIM_TRACING_1(int, MPI_Unpublish_name, (service_name, info, port_name));
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	void **args = assemble_args_list(3, service_name, &obj_id_0, port_name);
	int sizes[] = { strlen(service_name)+1, sizeof(int), strlen(port_name)+1 };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Unpublish_name(const char *service_name, MPI_Info info, const char *port_name) { return c_MPI_Unpublish_name(service_name, info, port_name); }
extern void f_mpi_unpublish_name(const char* service_name, MPI_Fint* info, const char* port_name, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	c_MPI_Unpublish_name(service_name, c_handle_0, port_name);
}
extern void MPI_UNPUBLISH_NAME(const char* service_name, MPI_Fint* info, const char* port_name, MPI_Fint *ierr) {
	f_mpi_unpublish_name(service_name, info, port_name, ierr);
}
extern void mpi_unpublish_name(const char* service_name, MPI_Fint* info, const char* port_name, MPI_Fint *ierr) {
	f_mpi_unpublish_name(service_name, info, port_name, ierr);
}
extern void mpi_unpublish_name_(const char* service_name, MPI_Fint* info, const char* port_name, MPI_Fint *ierr) {
	f_mpi_unpublish_name(service_name, info, port_name, ierr);
}
extern void mpi_unpublish_name__(const char* service_name, MPI_Fint* info, const char* port_name, MPI_Fint *ierr) {
	f_mpi_unpublish_name(service_name, info, port_name, ierr);
}
int c_MPI_Group_rank(MPI_Group group, int *rank)
{
	PILGRIM_TRACING_1(int, MPI_Group_rank, (group, rank));
	MPI_Group obj_0 = group;
	int obj_id_0 = MPI_OBJ_ID(MPI_Group, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, rank);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Group_rank(MPI_Group group, int *rank) { return c_MPI_Group_rank(group, rank); }
extern void f_mpi_group_rank(MPI_Fint* group, int* rank, MPI_Fint *ierr) {
	MPI_Group c_handle_0;
	c_handle_0 = PMPI_Group_f2c(*group);
	c_MPI_Group_rank(c_handle_0, rank);
}
extern void MPI_GROUP_RANK(MPI_Fint* group, int* rank, MPI_Fint *ierr) {
	f_mpi_group_rank(group, rank, ierr);
}
extern void mpi_group_rank(MPI_Fint* group, int* rank, MPI_Fint *ierr) {
	f_mpi_group_rank(group, rank, ierr);
}
extern void mpi_group_rank_(MPI_Fint* group, int* rank, MPI_Fint *ierr) {
	f_mpi_group_rank(group, rank, ierr);
}
extern void mpi_group_rank__(MPI_Fint* group, int* rank, MPI_Fint *ierr) {
	f_mpi_group_rank(group, rank, ierr);
}
int c_MPI_Lookup_name(const char *service_name, MPI_Info info, char *port_name)
{
	PILGRIM_TRACING_1(int, MPI_Lookup_name, (service_name, info, port_name));
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	void **args = assemble_args_list(3, service_name, &obj_id_0, port_name);
	int sizes[] = { strlen(service_name)+1, sizeof(int), strlen(port_name)+1 };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Lookup_name(const char *service_name, MPI_Info info, char *port_name) { return c_MPI_Lookup_name(service_name, info, port_name); }
extern void f_mpi_lookup_name(const char* service_name, MPI_Fint* info, char* port_name, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	c_MPI_Lookup_name(service_name, c_handle_0, port_name);
}
extern void MPI_LOOKUP_NAME(const char* service_name, MPI_Fint* info, char* port_name, MPI_Fint *ierr) {
	f_mpi_lookup_name(service_name, info, port_name, ierr);
}
extern void mpi_lookup_name(const char* service_name, MPI_Fint* info, char* port_name, MPI_Fint *ierr) {
	f_mpi_lookup_name(service_name, info, port_name, ierr);
}
extern void mpi_lookup_name_(const char* service_name, MPI_Fint* info, char* port_name, MPI_Fint *ierr) {
	f_mpi_lookup_name(service_name, info, port_name, ierr);
}
extern void mpi_lookup_name__(const char* service_name, MPI_Fint* info, char* port_name, MPI_Fint *ierr) {
	f_mpi_lookup_name(service_name, info, port_name, ierr);
}
int c_MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Recv, (buf, count, datatype, source, tag, comm, status));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int source_rank = g_mpi_rank - source;
	if(source == MPI_ANY_SOURCE) source_rank = PILGRIM_MPI_ANY_SOURCE;
	if(source == MPI_PROC_NULL) source_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	int status_arg[2] = {0};
	if(source == MPI_ANY_SOURCE && status && status!=MPI_STATUS_IGNORE) status_arg[0] = status->MPI_SOURCE;
	if(tag == MPI_ANY_TAG && status && status!=MPI_STATUS_IGNORE) status_arg[1] = status->MPI_TAG;
	void **args = assemble_args_list(7, &mem_attr_0, &count, &obj_id_0, &source_rank, &my_tag, &obj_id_1, status_arg);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status) { return c_MPI_Recv(buf, count, datatype, source, tag, comm, status); }
extern void f_mpi_recv(void* buf, int* count, MPI_Fint* datatype, int* source, int* tag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_Recv(buf, (*count), c_handle_0, (*source), (*tag), c_handle_1, &c_handle_2);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_RECV(void* buf, int* count, MPI_Fint* datatype, int* source, int* tag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_recv(buf, count, datatype, source, tag, comm, status, ierr);
}
extern void mpi_recv(void* buf, int* count, MPI_Fint* datatype, int* source, int* tag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_recv(buf, count, datatype, source, tag, comm, status, ierr);
}
extern void mpi_recv_(void* buf, int* count, MPI_Fint* datatype, int* source, int* tag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_recv(buf, count, datatype, source, tag, comm, status, ierr);
}
extern void mpi_recv__(void* buf, int* count, MPI_Fint* datatype, int* source, int* tag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_recv(buf, count, datatype, source, tag, comm, status, ierr);
}
int c_MPI_Type_free_keyval(int *type_keyval)
{
	PILGRIM_TRACING_1(int, MPI_Type_free_keyval, (type_keyval));
	void **args = assemble_args_list(1, type_keyval);
	int sizes[] = { 1*sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Type_free_keyval(int *type_keyval) { return c_MPI_Type_free_keyval(type_keyval); }
extern void f_mpi_type_free_keyval(int* type_keyval, MPI_Fint *ierr) {
	c_MPI_Type_free_keyval(type_keyval);
}
extern void MPI_TYPE_FREE_KEYVAL(int* type_keyval, MPI_Fint *ierr) {
	f_mpi_type_free_keyval(type_keyval, ierr);
}
extern void mpi_type_free_keyval(int* type_keyval, MPI_Fint *ierr) {
	f_mpi_type_free_keyval(type_keyval, ierr);
}
extern void mpi_type_free_keyval_(int* type_keyval, MPI_Fint *ierr) {
	f_mpi_type_free_keyval(type_keyval, ierr);
}
extern void mpi_type_free_keyval__(int* type_keyval, MPI_Fint *ierr) {
	f_mpi_type_free_keyval(type_keyval, ierr);
}
int c_MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used)
{
	PILGRIM_TRACING_1(int, MPI_Comm_get_info, (comm, info_used));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Info, info_used);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used) { return c_MPI_Comm_get_info(comm, info_used); }
extern void f_mpi_comm_get_info(MPI_Fint* comm, MPI_Fint* info_used, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Info c_handle_1;
	c_handle_1 = PMPI_Info_f2c(*info_used);
	c_MPI_Comm_get_info(c_handle_0, &c_handle_1);
	*info_used = PMPI_Info_c2f(c_handle_1);
}
extern void MPI_COMM_GET_INFO(MPI_Fint* comm, MPI_Fint* info_used, MPI_Fint *ierr) {
	f_mpi_comm_get_info(comm, info_used, ierr);
}
extern void mpi_comm_get_info(MPI_Fint* comm, MPI_Fint* info_used, MPI_Fint *ierr) {
	f_mpi_comm_get_info(comm, info_used, ierr);
}
extern void mpi_comm_get_info_(MPI_Fint* comm, MPI_Fint* info_used, MPI_Fint *ierr) {
	f_mpi_comm_get_info(comm, info_used, ierr);
}
extern void mpi_comm_get_info__(MPI_Fint* comm, MPI_Fint* info_used, MPI_Fint *ierr) {
	f_mpi_comm_get_info(comm, info_used, ierr);
}
int c_MPI_T_pvar_session_create(MPI_T_pvar_session *session)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_session_create, (session));
	void **args = assemble_args_list(1, session);
	int sizes[] = { 1*sizeof(MPI_T_pvar_session) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_T_pvar_session_create(MPI_T_pvar_session *session) { return c_MPI_T_pvar_session_create(session); }
int c_MPI_T_init_thread(int required, int *provided)
{
	PILGRIM_TRACING_1(int, MPI_T_init_thread, (required, provided));
	void **args = assemble_args_list(2, &required, provided);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_T_init_thread(int required, int *provided) { return c_MPI_T_init_thread(required, provided); }
int c_MPI_File_open(MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh)
{
	PILGRIM_TRACING_1(int, MPI_File_open, (comm, filename, amode, info, fh));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	MPI_Info obj_1 = info;
	int obj_id_1 = MPI_OBJ_ID(MPI_Info, &obj_1);
	int obj_id_2 = MPI_OBJ_ID(MPI_File, fh);
	void **args = assemble_args_list(5, &obj_id_0, filename, &amode, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(int), strlen(filename)+1, sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_File_open(MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh) { return c_MPI_File_open(comm, filename, amode, info, fh); }
extern void f_mpi_file_open(MPI_Fint* comm, const char* filename, int* amode, MPI_Fint* info, MPI_Fint* fh, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Info c_handle_1;
	c_handle_1 = PMPI_Info_f2c(*info);
	MPI_File c_handle_2;
	c_handle_2 = PMPI_File_f2c(*fh);
	c_MPI_File_open(c_handle_0, filename, (*amode), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_2);
}
extern void MPI_FILE_OPEN(MPI_Fint* comm, const char* filename, int* amode, MPI_Fint* info, MPI_Fint* fh, MPI_Fint *ierr) {
	f_mpi_file_open(comm, filename, amode, info, fh, ierr);
}
extern void mpi_file_open(MPI_Fint* comm, const char* filename, int* amode, MPI_Fint* info, MPI_Fint* fh, MPI_Fint *ierr) {
	f_mpi_file_open(comm, filename, amode, info, fh, ierr);
}
extern void mpi_file_open_(MPI_Fint* comm, const char* filename, int* amode, MPI_Fint* info, MPI_Fint* fh, MPI_Fint *ierr) {
	f_mpi_file_open(comm, filename, amode, info, fh, ierr);
}
extern void mpi_file_open__(MPI_Fint* comm, const char* filename, int* amode, MPI_Fint* info, MPI_Fint* fh, MPI_Fint *ierr) {
	f_mpi_file_open(comm, filename, amode, info, fh, ierr);
}
int c_MPI_Bsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Bsend, (buf, count, datatype, dest, tag, comm));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int dest_rank = g_mpi_rank - dest;
	if(dest == MPI_ANY_SOURCE) dest_rank = PILGRIM_MPI_ANY_SOURCE;
	if(dest == MPI_PROC_NULL) dest_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(6, &mem_attr_0, &count, &obj_id_0, &dest_rank, &my_tag, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Bsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { return c_MPI_Bsend(buf, count, datatype, dest, tag, comm); }
extern void f_mpi_bsend(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	c_MPI_Bsend(buf, (*count), c_handle_0, (*dest), (*tag), c_handle_1);
}
extern void MPI_BSEND(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_bsend(buf, count, datatype, dest, tag, comm, ierr);
}
extern void mpi_bsend(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_bsend(buf, count, datatype, dest, tag, comm, ierr);
}
extern void mpi_bsend_(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_bsend(buf, count, datatype, dest, tag, comm, ierr);
}
extern void mpi_bsend__(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_bsend(buf, count, datatype, dest, tag, comm, ierr);
}
int c_MPI_Ireduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ireduce_scatter, (sendbuf, recvbuf, recvcounts, datatype, op, comm, request));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Op obj_1 = op;
	int obj_id_1 = MPI_OBJ_ID(MPI_Op, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(6, &mem_attr_0, &mem_attr_1, recvcounts, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(MemPtrAttr), comm_size*sizeof(const int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, comm_size);
}
int MPI_Ireduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { return c_MPI_Ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, request); }
extern void f_mpi_ireduce_scatter(const void* sendbuf, void* recvbuf, const int recvcounts[], MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Op c_handle_1;
	c_handle_1 = PMPI_Op_f2c(*op);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Ireduce_scatter(sendbuf, recvbuf, recvcounts, c_handle_0, c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_IREDUCE_SCATTER(const void* sendbuf, void* recvbuf, const int recvcounts[], MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, ierr);
}
extern void mpi_ireduce_scatter(const void* sendbuf, void* recvbuf, const int recvcounts[], MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, ierr);
}
extern void mpi_ireduce_scatter_(const void* sendbuf, void* recvbuf, const int recvcounts[], MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, ierr);
}
extern void mpi_ireduce_scatter__(const void* sendbuf, void* recvbuf, const int recvcounts[], MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, ierr);
}
int c_MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Irecv, (buf, count, datatype, source, tag, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int source_rank = g_mpi_rank - source;
	if(source == MPI_ANY_SOURCE) source_rank = PILGRIM_MPI_ANY_SOURCE;
	if(source == MPI_PROC_NULL) source_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	int obj_id_2 = create_request_id(request, false, ID_MPI_Irecv, source, tag, obj_id_1);
	void **args = assemble_args_list(7, &mem_attr_0, &count, &obj_id_0, &source_rank, &my_tag, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request) { return c_MPI_Irecv(buf, count, datatype, source, tag, comm, request); }
extern void f_mpi_irecv(void* buf, int* count, MPI_Fint* datatype, int* source, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_Irecv(buf, (*count), c_handle_0, (*source), (*tag), c_handle_1, &c_handle_2);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_IRECV(void* buf, int* count, MPI_Fint* datatype, int* source, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_irecv(buf, count, datatype, source, tag, comm, request, ierr);
}
extern void mpi_irecv(void* buf, int* count, MPI_Fint* datatype, int* source, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_irecv(buf, count, datatype, source, tag, comm, request, ierr);
}
extern void mpi_irecv_(void* buf, int* count, MPI_Fint* datatype, int* source, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_irecv(buf, count, datatype, source, tag, comm, request, ierr);
}
extern void mpi_irecv__(void* buf, int* count, MPI_Fint* datatype, int* source, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_irecv(buf, count, datatype, source, tag, comm, request, ierr);
}
int c_MPI_Issend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Issend, (buf, count, datatype, dest, tag, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int dest_rank = g_mpi_rank - dest;
	if(dest == MPI_ANY_SOURCE) dest_rank = PILGRIM_MPI_ANY_SOURCE;
	if(dest == MPI_PROC_NULL) dest_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(6, &mem_attr_0, &count, &obj_id_0, &dest_rank, &my_tag, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Issend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return c_MPI_Issend(buf, count, datatype, dest, tag, comm, request); }
extern void f_mpi_issend(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_Issend(buf, (*count), c_handle_0, (*dest), (*tag), c_handle_1, &c_handle_2);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_ISSEND(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_issend(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_issend(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_issend(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_issend_(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_issend(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_issend__(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_issend(buf, count, datatype, dest, tag, comm, request, ierr);
}
int c_MPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iwrite_at_all, (fh, offset, buf, count, datatype, request));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	append_offset(offset);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(4, &obj_id_0, &mem_attr_0, &count, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return c_MPI_File_iwrite_at_all(fh, offset, buf, count, datatype, request); }
extern void f_mpi_file_iwrite_at_all(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_File_iwrite_at_all(c_handle_0, offset, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_FILE_IWRITE_AT_ALL(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite_at_all(fh, offset, buf, count, datatype, request, ierr);
}
extern void mpi_file_iwrite_at_all(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite_at_all(fh, offset, buf, count, datatype, request, ierr);
}
extern void mpi_file_iwrite_at_all_(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite_at_all(fh, offset, buf, count, datatype, request, ierr);
}
extern void mpi_file_iwrite_at_all__(MPI_Fint* fh, MPI_Offset offset, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite_at_all(fh, offset, buf, count, datatype, request, ierr);
}
int c_MPI_Abort(MPI_Comm comm, int errorcode)
{
	PILGRIM_TRACING_1(int, MPI_Abort, (comm, errorcode));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, &errorcode);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Abort(MPI_Comm comm, int errorcode) { return c_MPI_Abort(comm, errorcode); }
extern void f_mpi_abort(MPI_Fint* comm, int* errorcode, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Abort(c_handle_0, (*errorcode));
}
extern void MPI_ABORT(MPI_Fint* comm, int* errorcode, MPI_Fint *ierr) {
	f_mpi_abort(comm, errorcode, ierr);
}
extern void mpi_abort(MPI_Fint* comm, int* errorcode, MPI_Fint *ierr) {
	f_mpi_abort(comm, errorcode, ierr);
}
extern void mpi_abort_(MPI_Fint* comm, int* errorcode, MPI_Fint *ierr) {
	f_mpi_abort(comm, errorcode, ierr);
}
extern void mpi_abort__(MPI_Fint* comm, int* errorcode, MPI_Fint *ierr) {
	f_mpi_abort(comm, errorcode, ierr);
}
int c_MPI_Pack(const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize, int *position, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Pack, (inbuf, incount, datatype, outbuf, outsize, position, comm));
	MemPtrAttr mem_attr_0;
	addr2id(inbuf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(outbuf, &mem_attr_1);
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(7, &mem_attr_0, &incount, &obj_id_0, &mem_attr_1, &outsize, position, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), 1*sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Pack(const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize, int *position, MPI_Comm comm) { return c_MPI_Pack(inbuf, incount, datatype, outbuf, outsize, position, comm); }
extern void f_mpi_pack(const void* inbuf, int* incount, MPI_Fint* datatype, void* outbuf, int* outsize, int* position, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	c_MPI_Pack(inbuf, (*incount), c_handle_0, outbuf, (*outsize), position, c_handle_1);
}
extern void MPI_PACK(const void* inbuf, int* incount, MPI_Fint* datatype, void* outbuf, int* outsize, int* position, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_pack(inbuf, incount, datatype, outbuf, outsize, position, comm, ierr);
}
extern void mpi_pack(const void* inbuf, int* incount, MPI_Fint* datatype, void* outbuf, int* outsize, int* position, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_pack(inbuf, incount, datatype, outbuf, outsize, position, comm, ierr);
}
extern void mpi_pack_(const void* inbuf, int* incount, MPI_Fint* datatype, void* outbuf, int* outsize, int* position, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_pack(inbuf, incount, datatype, outbuf, outsize, position, comm, ierr);
}
extern void mpi_pack__(const void* inbuf, int* incount, MPI_Fint* datatype, void* outbuf, int* outsize, int* position, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_pack(inbuf, incount, datatype, outbuf, outsize, position, comm, ierr);
}
int c_MPI_File_iwrite(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iwrite, (fh, buf, count, datatype, request));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(4, &obj_id_0, &mem_attr_0, &count, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_File_iwrite(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return c_MPI_File_iwrite(fh, buf, count, datatype, request); }
extern void f_mpi_file_iwrite(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_File_iwrite(c_handle_0, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_FILE_IWRITE(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iwrite(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iwrite_(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iwrite__(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iwrite(fh, buf, count, datatype, request, ierr);
}
int c_MPI_Gatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Gatherv, (sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(9, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, recvcounts, displs, &obj_id_1, &root, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args, comm_size);
}
int MPI_Gatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm) { return c_MPI_Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm); }
extern void f_mpi_gatherv(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Gatherv(sendbuf, (*sendcount), c_handle_0, recvbuf, recvcounts, displs, c_handle_1, (*root), c_handle_2);
}
extern void MPI_GATHERV(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierr);
}
extern void mpi_gatherv(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierr);
}
extern void mpi_gatherv_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierr);
}
extern void mpi_gatherv__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Fint* recvtype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierr);
}
int c_MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_create, (comm, group, newcomm));
	generate_intracomm_id(newcomm);
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	MPI_Group obj_1 = group;
	int obj_id_1 = MPI_OBJ_ID(MPI_Group, &obj_1);
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, newcomm);
	void **args = assemble_args_list(3, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm) { return c_MPI_Comm_create(comm, group, newcomm); }
extern void f_mpi_comm_create(MPI_Fint* comm, MPI_Fint* group, MPI_Fint* newcomm, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Group c_handle_1;
	c_handle_1 = PMPI_Group_f2c(*group);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*newcomm);
	c_MPI_Comm_create(c_handle_0, c_handle_1, &c_handle_2);
	*newcomm = PMPI_Comm_c2f(c_handle_2);
}
extern void MPI_COMM_CREATE(MPI_Fint* comm, MPI_Fint* group, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_create(comm, group, newcomm, ierr);
}
extern void mpi_comm_create(MPI_Fint* comm, MPI_Fint* group, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_create(comm, group, newcomm, ierr);
}
extern void mpi_comm_create_(MPI_Fint* comm, MPI_Fint* group, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_create(comm, group, newcomm, ierr);
}
extern void mpi_comm_create__(MPI_Fint* comm, MPI_Fint* group, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_create(comm, group, newcomm, ierr);
}
int c_MPI_File_write_ordered(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write_ordered, (fh, buf, count, datatype, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	int status_arg[2] = {0};
	void **args = assemble_args_list(5, &obj_id_0, &mem_attr_0, &count, &obj_id_1, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_File_write_ordered(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return c_MPI_File_write_ordered(fh, buf, count, datatype, status); }
extern void f_mpi_file_write_ordered(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_File_write_ordered(c_handle_0, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_FILE_WRITE_ORDERED(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_ordered(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_write_ordered(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_ordered(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_write_ordered_(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_ordered(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_write_ordered__(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_ordered(fh, buf, count, datatype, status, ierr);
}
int c_MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_dup, (comm, newcomm));
	generate_intracomm_id(newcomm);
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, newcomm);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm) { return c_MPI_Comm_dup(comm, newcomm); }
extern void f_mpi_comm_dup(MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*newcomm);
	c_MPI_Comm_dup(c_handle_0, &c_handle_1);
	*newcomm = PMPI_Comm_c2f(c_handle_1);
}
extern void MPI_COMM_DUP(MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_dup(comm, newcomm, ierr);
}
extern void mpi_comm_dup(MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_dup(comm, newcomm, ierr);
}
extern void mpi_comm_dup_(MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_dup(comm, newcomm, ierr);
}
extern void mpi_comm_dup__(MPI_Fint* comm, MPI_Fint* newcomm, MPI_Fint *ierr) {
	f_mpi_comm_dup(comm, newcomm, ierr);
}
int c_MPI_T_finalize(void)
{
	PILGRIM_TRACING_1(int, MPI_T_finalize, ());
	void **args = NULL;
	int* sizes = NULL;
	PILGRIM_TRACING_2(0, sizes, args, -1);
}
int MPI_T_finalize(void) { return c_MPI_T_finalize(); }
int c_MPI_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_File_iread_shared, (fh, buf, count, datatype, request));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(4, &obj_id_0, &mem_attr_0, &count, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return c_MPI_File_iread_shared(fh, buf, count, datatype, request); }
extern void f_mpi_file_iread_shared(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_File_iread_shared(c_handle_0, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_FILE_IREAD_SHARED(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread_shared(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iread_shared(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread_shared(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iread_shared_(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread_shared(fh, buf, count, datatype, request, ierr);
}
extern void mpi_file_iread_shared__(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_file_iread_shared(fh, buf, count, datatype, request, ierr);
}
int c_MPI_File_set_errhandler(MPI_File file, MPI_Errhandler errhandler)
{
	PILGRIM_TRACING_1(int, MPI_File_set_errhandler, (file, errhandler));
	MPI_File obj_0 = file;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MPI_Errhandler obj_1 = errhandler;
	int obj_id_1 = MPI_OBJ_ID(MPI_Errhandler, &obj_1);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_set_errhandler(MPI_File file, MPI_Errhandler errhandler) { return c_MPI_File_set_errhandler(file, errhandler); }
extern void f_mpi_file_set_errhandler(MPI_Fint* file, MPI_Fint* errhandler, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*file);
	MPI_Errhandler c_handle_1;
	c_handle_1 = PMPI_Errhandler_f2c(*errhandler);
	c_MPI_File_set_errhandler(c_handle_0, c_handle_1);
	*file = PMPI_File_c2f(c_handle_0);
}
extern void MPI_FILE_SET_ERRHANDLER(MPI_Fint* file, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_file_set_errhandler(file, errhandler, ierr);
}
extern void mpi_file_set_errhandler(MPI_Fint* file, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_file_set_errhandler(file, errhandler, ierr);
}
extern void mpi_file_set_errhandler_(MPI_Fint* file, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_file_set_errhandler(file, errhandler, ierr);
}
extern void mpi_file_set_errhandler__(MPI_Fint* file, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_file_set_errhandler(file, errhandler, ierr);
}
int c_MPI_Register_datarep(const char *datarep, MPI_Datarep_conversion_function *read_conversion_fn, MPI_Datarep_conversion_function *write_conversion_fn, MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state)
{
	PILGRIM_TRACING_1(int, MPI_Register_datarep, (datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state));
	MemPtrAttr mem_attr_0;
	addr2id(extra_state, &mem_attr_0);
	void **args = assemble_args_list(5, datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, &mem_attr_0);
	int sizes[] = { strlen(datarep)+1, 1*sizeof(MPI_Datarep_conversion_function), 1*sizeof(MPI_Datarep_conversion_function), 1*sizeof(MPI_Datarep_extent_function), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Register_datarep(const char *datarep, MPI_Datarep_conversion_function *read_conversion_fn, MPI_Datarep_conversion_function *write_conversion_fn, MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) { return c_MPI_Register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state); }
extern void f_mpi_register_datarep(const char* datarep, MPI_Datarep_conversion_function* read_conversion_fn, MPI_Datarep_conversion_function* write_conversion_fn, MPI_Datarep_extent_function* dtype_file_extent_fn, void* extra_state, MPI_Fint *ierr) {
	c_MPI_Register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state);
}
extern void MPI_REGISTER_DATAREP(const char* datarep, MPI_Datarep_conversion_function* read_conversion_fn, MPI_Datarep_conversion_function* write_conversion_fn, MPI_Datarep_extent_function* dtype_file_extent_fn, void* extra_state, MPI_Fint *ierr) {
	f_mpi_register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state, ierr);
}
extern void mpi_register_datarep(const char* datarep, MPI_Datarep_conversion_function* read_conversion_fn, MPI_Datarep_conversion_function* write_conversion_fn, MPI_Datarep_extent_function* dtype_file_extent_fn, void* extra_state, MPI_Fint *ierr) {
	f_mpi_register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state, ierr);
}
extern void mpi_register_datarep_(const char* datarep, MPI_Datarep_conversion_function* read_conversion_fn, MPI_Datarep_conversion_function* write_conversion_fn, MPI_Datarep_extent_function* dtype_file_extent_fn, void* extra_state, MPI_Fint *ierr) {
	f_mpi_register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state, ierr);
}
extern void mpi_register_datarep__(const char* datarep, MPI_Datarep_conversion_function* read_conversion_fn, MPI_Datarep_conversion_function* write_conversion_fn, MPI_Datarep_extent_function* dtype_file_extent_fn, void* extra_state, MPI_Fint *ierr) {
	f_mpi_register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state, ierr);
}
int c_MPI_Reduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Reduce_scatter, (sendbuf, recvbuf, recvcounts, datatype, op, comm));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Op obj_1 = op;
	int obj_id_1 = MPI_OBJ_ID(MPI_Op, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(6, &mem_attr_0, &mem_attr_1, recvcounts, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(MemPtrAttr), comm_size*sizeof(const int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, comm_size);
}
int MPI_Reduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { return c_MPI_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm); }
extern void f_mpi_reduce_scatter(const void* sendbuf, void* recvbuf, const int recvcounts[], MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Op c_handle_1;
	c_handle_1 = PMPI_Op_f2c(*op);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	c_MPI_Reduce_scatter(sendbuf, recvbuf, recvcounts, c_handle_0, c_handle_1, c_handle_2);
}
extern void MPI_REDUCE_SCATTER(const void* sendbuf, void* recvbuf, const int recvcounts[], MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierr);
}
extern void mpi_reduce_scatter(const void* sendbuf, void* recvbuf, const int recvcounts[], MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierr);
}
extern void mpi_reduce_scatter_(const void* sendbuf, void* recvbuf, const int recvcounts[], MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierr);
}
extern void mpi_reduce_scatter__(const void* sendbuf, void* recvbuf, const int recvcounts[], MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierr);
}
int c_MPI_Ibarrier(MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ibarrier, (comm, request));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(1, &obj_id_0);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Ibarrier(MPI_Comm comm, MPI_Request *request) { return c_MPI_Ibarrier(comm, request); }
extern void f_mpi_ibarrier(MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_1;
	c_handle_1 = PMPI_Request_f2c(*request);
	c_MPI_Ibarrier(c_handle_0, &c_handle_1);
	*request = PMPI_Request_c2f(c_handle_1);
}
extern void MPI_IBARRIER(MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ibarrier(comm, request, ierr);
}
extern void mpi_ibarrier(MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ibarrier(comm, request, ierr);
}
extern void mpi_ibarrier_(MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ibarrier(comm, request, ierr);
}
extern void mpi_ibarrier__(MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ibarrier(comm, request, ierr);
}
int c_MPI_Type_create_f90_real(int p, int r, MPI_Datatype *newtype)
{
	PILGRIM_TRACING_1(int, MPI_Type_create_f90_real, (p, r, newtype));
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, newtype);
	void **args = assemble_args_list(3, &p, &r, &obj_id_0);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Type_create_f90_real(int p, int r, MPI_Datatype *newtype) { return c_MPI_Type_create_f90_real(p, r, newtype); }
extern void f_mpi_type_create_f90_real(int* p, int* r, MPI_Fint* newtype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*newtype);
	c_MPI_Type_create_f90_real((*p), (*r), &c_handle_0);
	*newtype = PMPI_Type_c2f(c_handle_0);
}
extern void MPI_TYPE_CREATE_F90_REAL(int* p, int* r, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_f90_real(p, r, newtype, ierr);
}
extern void mpi_type_create_f90_real(int* p, int* r, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_f90_real(p, r, newtype, ierr);
}
extern void mpi_type_create_f90_real_(int* p, int* r, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_f90_real(p, r, newtype, ierr);
}
extern void mpi_type_create_f90_real__(int* p, int* r, MPI_Fint* newtype, MPI_Fint *ierr) {
	f_mpi_type_create_f90_real(p, r, newtype, ierr);
}
int c_MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence)
{
	PILGRIM_TRACING_1(int, MPI_File_seek, (fh, offset, whence));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	append_offset(offset);
	void **args = assemble_args_list(2, &obj_id_0, &whence);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence) { return c_MPI_File_seek(fh, offset, whence); }
extern void f_mpi_file_seek(MPI_Fint* fh, MPI_Offset offset, int* whence, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	c_MPI_File_seek(c_handle_0, offset, (*whence));
	*fh = PMPI_File_c2f(c_handle_0);
}
extern void MPI_FILE_SEEK(MPI_Fint* fh, MPI_Offset offset, int* whence, MPI_Fint *ierr) {
	f_mpi_file_seek(fh, offset, whence, ierr);
}
extern void mpi_file_seek(MPI_Fint* fh, MPI_Offset offset, int* whence, MPI_Fint *ierr) {
	f_mpi_file_seek(fh, offset, whence, ierr);
}
extern void mpi_file_seek_(MPI_Fint* fh, MPI_Offset offset, int* whence, MPI_Fint *ierr) {
	f_mpi_file_seek(fh, offset, whence, ierr);
}
extern void mpi_file_seek__(MPI_Fint* fh, MPI_Offset offset, int* whence, MPI_Fint *ierr) {
	f_mpi_file_seek(fh, offset, whence, ierr);
}
int c_MPI_T_cvar_get_num(int *num_cvar)
{
	PILGRIM_TRACING_1(int, MPI_T_cvar_get_num, (num_cvar));
	void **args = assemble_args_list(1, num_cvar);
	int sizes[] = { 1*sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_T_cvar_get_num(int *num_cvar) { return c_MPI_T_cvar_get_num(num_cvar); }
int c_MPI_Group_incl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup)
{
	PILGRIM_TRACING_1(int, MPI_Group_incl, (group, n, ranks, newgroup));
	MPI_Group obj_0 = group;
	int obj_id_0 = MPI_OBJ_ID(MPI_Group, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Group, newgroup);
	void **args = assemble_args_list(4, &obj_id_0, &n, ranks, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), n*sizeof(const int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Group_incl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup) { return c_MPI_Group_incl(group, n, ranks, newgroup); }
extern void f_mpi_group_incl(MPI_Fint* group, int* n, const int ranks[], MPI_Fint* newgroup, MPI_Fint *ierr) {
	MPI_Group c_handle_0;
	c_handle_0 = PMPI_Group_f2c(*group);
	MPI_Group c_handle_1;
	c_handle_1 = PMPI_Group_f2c(*newgroup);
	c_MPI_Group_incl(c_handle_0, (*n), ranks, &c_handle_1);
	*newgroup = PMPI_Group_c2f(c_handle_1);
}
extern void MPI_GROUP_INCL(MPI_Fint* group, int* n, const int ranks[], MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_incl(group, n, ranks, newgroup, ierr);
}
extern void mpi_group_incl(MPI_Fint* group, int* n, const int ranks[], MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_incl(group, n, ranks, newgroup, ierr);
}
extern void mpi_group_incl_(MPI_Fint* group, int* n, const int ranks[], MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_incl(group, n, ranks, newgroup, ierr);
}
extern void mpi_group_incl__(MPI_Fint* group, int* n, const int ranks[], MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_incl(group, n, ranks, newgroup, ierr);
}
int c_MPI_Get_version(int *version, int *subversion)
{
	PILGRIM_TRACING_1(int, MPI_Get_version, (version, subversion));
	void **args = assemble_args_list(2, version, subversion);
	int sizes[] = { 1*sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Get_version(int *version, int *subversion) { return c_MPI_Get_version(version, subversion); }
extern void f_mpi_get_version(int* version, int* subversion, MPI_Fint *ierr) {
	c_MPI_Get_version(version, subversion);
}
extern void MPI_GET_VERSION(int* version, int* subversion, MPI_Fint *ierr) {
	f_mpi_get_version(version, subversion, ierr);
}
extern void mpi_get_version(int* version, int* subversion, MPI_Fint *ierr) {
	f_mpi_get_version(version, subversion, ierr);
}
extern void mpi_get_version_(int* version, int* subversion, MPI_Fint *ierr) {
	f_mpi_get_version(version, subversion, ierr);
}
extern void mpi_get_version__(int* version, int* subversion, MPI_Fint *ierr) {
	f_mpi_get_version(version, subversion, ierr);
}
int c_MPI_Pack_external(const char datarep[], const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, MPI_Aint outsize, MPI_Aint *position)
{
	PILGRIM_TRACING_1(int, MPI_Pack_external, (datarep, inbuf, incount, datatype, outbuf, outsize, position));
	MemPtrAttr mem_attr_0;
	addr2id(inbuf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(outbuf, &mem_attr_1);
	void **args = assemble_args_list(7, datarep, &mem_attr_0, &incount, &obj_id_0, &mem_attr_1, &outsize, position);
	int sizes[] = { strlen(datarep)+1, sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(MPI_Aint), 1*sizeof(MPI_Aint) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Pack_external(const char datarep[], const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, MPI_Aint outsize, MPI_Aint *position) { return c_MPI_Pack_external(datarep, inbuf, incount, datatype, outbuf, outsize, position); }
extern void f_mpi_pack_external(const char datarep[], const void* inbuf, int* incount, MPI_Fint* datatype, void* outbuf, MPI_Aint outsize, MPI_Aint* position, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Pack_external(datarep, inbuf, (*incount), c_handle_0, outbuf, outsize, position);
}
extern void MPI_PACK_EXTERNAL(const char datarep[], const void* inbuf, int* incount, MPI_Fint* datatype, void* outbuf, MPI_Aint outsize, MPI_Aint* position, MPI_Fint *ierr) {
	f_mpi_pack_external(datarep, inbuf, incount, datatype, outbuf, outsize, position, ierr);
}
extern void mpi_pack_external(const char datarep[], const void* inbuf, int* incount, MPI_Fint* datatype, void* outbuf, MPI_Aint outsize, MPI_Aint* position, MPI_Fint *ierr) {
	f_mpi_pack_external(datarep, inbuf, incount, datatype, outbuf, outsize, position, ierr);
}
extern void mpi_pack_external_(const char datarep[], const void* inbuf, int* incount, MPI_Fint* datatype, void* outbuf, MPI_Aint outsize, MPI_Aint* position, MPI_Fint *ierr) {
	f_mpi_pack_external(datarep, inbuf, incount, datatype, outbuf, outsize, position, ierr);
}
extern void mpi_pack_external__(const char datarep[], const void* inbuf, int* incount, MPI_Fint* datatype, void* outbuf, MPI_Aint outsize, MPI_Aint* position, MPI_Fint *ierr) {
	f_mpi_pack_external(datarep, inbuf, incount, datatype, outbuf, outsize, position, ierr);
}
int c_MPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read, (fh, buf, count, datatype, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	int status_arg[2] = {0};
	void **args = assemble_args_list(5, &obj_id_0, &mem_attr_0, &count, &obj_id_1, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return c_MPI_File_read(fh, buf, count, datatype, status); }
extern void f_mpi_file_read(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_File_read(c_handle_0, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_FILE_READ(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_read(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_read_(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_read__(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read(fh, buf, count, datatype, status, ierr);
}
int c_MPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb, MPI_Aint *true_extent)
{
	PILGRIM_TRACING_1(int, MPI_Type_get_true_extent, (datatype, true_lb, true_extent));
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	void **args = assemble_args_list(3, &obj_id_0, true_lb, true_extent);
	int sizes[] = { sizeof(int), 1*sizeof(MPI_Aint), 1*sizeof(MPI_Aint) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb, MPI_Aint *true_extent) { return c_MPI_Type_get_true_extent(datatype, true_lb, true_extent); }
extern void f_mpi_type_get_true_extent(MPI_Fint* datatype, MPI_Aint* true_lb, MPI_Aint* true_extent, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Type_get_true_extent(c_handle_0, true_lb, true_extent);
}
extern void MPI_TYPE_GET_TRUE_EXTENT(MPI_Fint* datatype, MPI_Aint* true_lb, MPI_Aint* true_extent, MPI_Fint *ierr) {
	f_mpi_type_get_true_extent(datatype, true_lb, true_extent, ierr);
}
extern void mpi_type_get_true_extent(MPI_Fint* datatype, MPI_Aint* true_lb, MPI_Aint* true_extent, MPI_Fint *ierr) {
	f_mpi_type_get_true_extent(datatype, true_lb, true_extent, ierr);
}
extern void mpi_type_get_true_extent_(MPI_Fint* datatype, MPI_Aint* true_lb, MPI_Aint* true_extent, MPI_Fint *ierr) {
	f_mpi_type_get_true_extent(datatype, true_lb, true_extent, ierr);
}
extern void mpi_type_get_true_extent__(MPI_Fint* datatype, MPI_Aint* true_lb, MPI_Aint* true_extent, MPI_Fint *ierr) {
	f_mpi_type_get_true_extent(datatype, true_lb, true_extent, ierr);
}
int c_MPI_Cart_create(MPI_Comm comm_old, int ndims, const int dims[], const int periods[], int reorder, MPI_Comm *comm_cart)
{
	PILGRIM_TRACING_1(int, MPI_Cart_create, (comm_old, ndims, dims, periods, reorder, comm_cart));
	generate_intracomm_id(comm_cart);
	MPI_Comm obj_0 = comm_old;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, comm_cart);
	void **args = assemble_args_list(6, &obj_id_0, &ndims, dims, periods, &reorder, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), ndims*sizeof(const int), ndims*sizeof(const int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Cart_create(MPI_Comm comm_old, int ndims, const int dims[], const int periods[], int reorder, MPI_Comm *comm_cart) { return c_MPI_Cart_create(comm_old, ndims, dims, periods, reorder, comm_cart); }
extern void f_mpi_cart_create(MPI_Fint* comm_old, int* ndims, const int dims[], const int periods[], int* reorder, MPI_Fint* comm_cart, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm_old);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm_cart);
	c_MPI_Cart_create(c_handle_0, (*ndims), dims, periods, (*reorder), &c_handle_1);
	*comm_cart = PMPI_Comm_c2f(c_handle_1);
}
extern void MPI_CART_CREATE(MPI_Fint* comm_old, int* ndims, const int dims[], const int periods[], int* reorder, MPI_Fint* comm_cart, MPI_Fint *ierr) {
	f_mpi_cart_create(comm_old, ndims, dims, periods, reorder, comm_cart, ierr);
}
extern void mpi_cart_create(MPI_Fint* comm_old, int* ndims, const int dims[], const int periods[], int* reorder, MPI_Fint* comm_cart, MPI_Fint *ierr) {
	f_mpi_cart_create(comm_old, ndims, dims, periods, reorder, comm_cart, ierr);
}
extern void mpi_cart_create_(MPI_Fint* comm_old, int* ndims, const int dims[], const int periods[], int* reorder, MPI_Fint* comm_cart, MPI_Fint *ierr) {
	f_mpi_cart_create(comm_old, ndims, dims, periods, reorder, comm_cart, ierr);
}
extern void mpi_cart_create__(MPI_Fint* comm_old, int* ndims, const int dims[], const int periods[], int* reorder, MPI_Fint* comm_cart, MPI_Fint *ierr) {
	f_mpi_cart_create(comm_old, ndims, dims, periods, reorder, comm_cart, ierr);
}
int c_MPI_Sendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Sendrecv, (sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int dest_rank = g_mpi_rank - dest;
	if(dest == MPI_ANY_SOURCE) dest_rank = PILGRIM_MPI_ANY_SOURCE;
	if(dest == MPI_PROC_NULL) dest_rank = PILGRIM_MPI_PROC_NULL;
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	int source_rank = g_mpi_rank - source;
	if(source == MPI_ANY_SOURCE) source_rank = PILGRIM_MPI_ANY_SOURCE;
	if(source == MPI_PROC_NULL) source_rank = PILGRIM_MPI_PROC_NULL;
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	int status_arg[2] = {0};
	if(source == MPI_ANY_SOURCE && status && status!=MPI_STATUS_IGNORE) status_arg[0] = status->MPI_SOURCE;
	if(recvtag == MPI_ANY_TAG && status && status!=MPI_STATUS_IGNORE) status_arg[1] = status->MPI_TAG;
	void **args = assemble_args_list(12, &mem_attr_0, &sendcount, &obj_id_0, &dest_rank, &sendtag, &mem_attr_1, &recvcount, &obj_id_1, &source_rank, &recvtag, &obj_id_2, status_arg);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(12, sizes, args, -1);
}
int MPI_Sendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status) { return c_MPI_Sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status); }
extern void f_mpi_sendrecv(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, int* dest, int* sendtag, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* source, int* recvtag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Status c_handle_3;
	PMPI_Status_f2c(status, &c_handle_3);
	c_MPI_Sendrecv(sendbuf, (*sendcount), c_handle_0, (*dest), (*sendtag), recvbuf, (*recvcount), c_handle_1, (*source), (*recvtag), c_handle_2, &c_handle_3);
	PMPI_Status_c2f(&c_handle_3, status);
}
extern void MPI_SENDRECV(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, int* dest, int* sendtag, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* source, int* recvtag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status, ierr);
}
extern void mpi_sendrecv(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, int* dest, int* sendtag, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* source, int* recvtag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status, ierr);
}
extern void mpi_sendrecv_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, int* dest, int* sendtag, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* source, int* recvtag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status, ierr);
}
extern void mpi_sendrecv__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, int* dest, int* sendtag, void* recvbuf, int* recvcount, MPI_Fint* recvtype, int* source, int* recvtag, MPI_Fint* comm, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status, ierr);
}
int c_MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit, void *baseptr)
{
	PILGRIM_TRACING_1(int, MPI_Win_shared_query, (win, rank, size, disp_unit, baseptr));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(baseptr, &mem_attr_0);
	void **args = assemble_args_list(5, &obj_id_0, &rank, size, disp_unit, &mem_attr_0);
	int sizes[] = { sizeof(int), sizeof(int), 1*sizeof(MPI_Aint), 1*sizeof(int), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit, void *baseptr) { return c_MPI_Win_shared_query(win, rank, size, disp_unit, baseptr); }
extern void f_mpi_win_shared_query(MPI_Fint* win, int* rank, MPI_Aint* size, int* disp_unit, void* baseptr, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_shared_query(c_handle_0, (*rank), size, disp_unit, baseptr);
}
extern void MPI_WIN_SHARED_QUERY(MPI_Fint* win, int* rank, MPI_Aint* size, int* disp_unit, void* baseptr, MPI_Fint *ierr) {
	f_mpi_win_shared_query(win, rank, size, disp_unit, baseptr, ierr);
}
extern void mpi_win_shared_query(MPI_Fint* win, int* rank, MPI_Aint* size, int* disp_unit, void* baseptr, MPI_Fint *ierr) {
	f_mpi_win_shared_query(win, rank, size, disp_unit, baseptr, ierr);
}
extern void mpi_win_shared_query_(MPI_Fint* win, int* rank, MPI_Aint* size, int* disp_unit, void* baseptr, MPI_Fint *ierr) {
	f_mpi_win_shared_query(win, rank, size, disp_unit, baseptr, ierr);
}
extern void mpi_win_shared_query__(MPI_Fint* win, int* rank, MPI_Aint* size, int* disp_unit, void* baseptr, MPI_Fint *ierr) {
	f_mpi_win_shared_query(win, rank, size, disp_unit, baseptr, ierr);
}
int c_MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val)
{
	PILGRIM_TRACING_1(int, MPI_Comm_set_attr, (comm, comm_keyval, attribute_val));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(attribute_val, &mem_attr_0);
	void **args = assemble_args_list(3, &obj_id_0, &comm_keyval, &mem_attr_0);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val) { return c_MPI_Comm_set_attr(comm, comm_keyval, attribute_val); }
extern void f_mpi_comm_set_attr(MPI_Fint* comm, int* comm_keyval, void* attribute_val, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Comm_set_attr(c_handle_0, (*comm_keyval), attribute_val);
	*comm = PMPI_Comm_c2f(c_handle_0);
}
extern void MPI_COMM_SET_ATTR(MPI_Fint* comm, int* comm_keyval, void* attribute_val, MPI_Fint *ierr) {
	f_mpi_comm_set_attr(comm, comm_keyval, attribute_val, ierr);
}
extern void mpi_comm_set_attr(MPI_Fint* comm, int* comm_keyval, void* attribute_val, MPI_Fint *ierr) {
	f_mpi_comm_set_attr(comm, comm_keyval, attribute_val, ierr);
}
extern void mpi_comm_set_attr_(MPI_Fint* comm, int* comm_keyval, void* attribute_val, MPI_Fint *ierr) {
	f_mpi_comm_set_attr(comm, comm_keyval, attribute_val, ierr);
}
extern void mpi_comm_set_attr__(MPI_Fint* comm, int* comm_keyval, void* attribute_val, MPI_Fint *ierr) {
	f_mpi_comm_set_attr(comm, comm_keyval, attribute_val, ierr);
}
int c_MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win)
{
	PILGRIM_TRACING_1(int, MPI_Win_allocate_shared, (size, disp_unit, info, comm, baseptr, win));
	MPI_Info obj_0 = info;
	int obj_id_0 = MPI_OBJ_ID(MPI_Info, &obj_0);
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	MemPtrAttr mem_attr_0;
	addr2id(baseptr, &mem_attr_0);
	int obj_id_2 = MPI_OBJ_ID(MPI_Win, win);
	void **args = assemble_args_list(6, &size, &disp_unit, &obj_id_0, &obj_id_1, &mem_attr_0, &obj_id_2);
	int sizes[] = { sizeof(MPI_Aint), sizeof(int), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win) { return c_MPI_Win_allocate_shared(size, disp_unit, info, comm, baseptr, win); }
extern void f_mpi_win_allocate_shared(MPI_Aint size, int* disp_unit, MPI_Fint* info, MPI_Fint* comm, void* baseptr, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Info c_handle_0;
	c_handle_0 = PMPI_Info_f2c(*info);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Win c_handle_2;
	c_handle_2 = PMPI_Win_f2c(*win);
	c_MPI_Win_allocate_shared(size, (*disp_unit), c_handle_0, c_handle_1, baseptr, &c_handle_2);
	*win = PMPI_Win_c2f(c_handle_2);
}
extern void MPI_WIN_ALLOCATE_SHARED(MPI_Aint size, int* disp_unit, MPI_Fint* info, MPI_Fint* comm, void* baseptr, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_allocate_shared(size, disp_unit, info, comm, baseptr, win, ierr);
}
extern void mpi_win_allocate_shared(MPI_Aint size, int* disp_unit, MPI_Fint* info, MPI_Fint* comm, void* baseptr, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_allocate_shared(size, disp_unit, info, comm, baseptr, win, ierr);
}
extern void mpi_win_allocate_shared_(MPI_Aint size, int* disp_unit, MPI_Fint* info, MPI_Fint* comm, void* baseptr, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_allocate_shared(size, disp_unit, info, comm, baseptr, win, ierr);
}
extern void mpi_win_allocate_shared__(MPI_Aint size, int* disp_unit, MPI_Fint* info, MPI_Fint* comm, void* baseptr, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_allocate_shared(size, disp_unit, info, comm, baseptr, win, ierr);
}
int c_MPI_Type_get_true_extent_x(MPI_Datatype datatype, MPI_Count *true_lb, MPI_Count *true_extent)
{
	PILGRIM_TRACING_1(int, MPI_Type_get_true_extent_x, (datatype, true_lb, true_extent));
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	void **args = assemble_args_list(3, &obj_id_0, true_lb, true_extent);
	int sizes[] = { sizeof(int), 1*sizeof(MPI_Count), 1*sizeof(MPI_Count) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Type_get_true_extent_x(MPI_Datatype datatype, MPI_Count *true_lb, MPI_Count *true_extent) { return c_MPI_Type_get_true_extent_x(datatype, true_lb, true_extent); }
extern void f_mpi_type_get_true_extent_x(MPI_Fint* datatype, MPI_Count* true_lb, MPI_Count* true_extent, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Type_get_true_extent_x(c_handle_0, true_lb, true_extent);
}
extern void MPI_TYPE_GET_TRUE_EXTENT_X(MPI_Fint* datatype, MPI_Count* true_lb, MPI_Count* true_extent, MPI_Fint *ierr) {
	f_mpi_type_get_true_extent_x(datatype, true_lb, true_extent, ierr);
}
extern void mpi_type_get_true_extent_x(MPI_Fint* datatype, MPI_Count* true_lb, MPI_Count* true_extent, MPI_Fint *ierr) {
	f_mpi_type_get_true_extent_x(datatype, true_lb, true_extent, ierr);
}
extern void mpi_type_get_true_extent_x_(MPI_Fint* datatype, MPI_Count* true_lb, MPI_Count* true_extent, MPI_Fint *ierr) {
	f_mpi_type_get_true_extent_x(datatype, true_lb, true_extent, ierr);
}
extern void mpi_type_get_true_extent_x__(MPI_Fint* datatype, MPI_Count* true_lb, MPI_Count* true_extent, MPI_Fint *ierr) {
	f_mpi_type_get_true_extent_x(datatype, true_lb, true_extent, ierr);
}
int c_MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Bcast, (buffer, count, datatype, root, comm));
	MemPtrAttr mem_attr_0;
	addr2id(buffer, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(5, &mem_attr_0, &count, &obj_id_0, &root, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm) { return c_MPI_Bcast(buffer, count, datatype, root, comm); }
extern void f_mpi_bcast(void* buffer, int* count, MPI_Fint* datatype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	c_MPI_Bcast(buffer, (*count), c_handle_0, (*root), c_handle_1);
}
extern void MPI_BCAST(void* buffer, int* count, MPI_Fint* datatype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_bcast(buffer, count, datatype, root, comm, ierr);
}
extern void mpi_bcast(void* buffer, int* count, MPI_Fint* datatype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_bcast(buffer, count, datatype, root, comm, ierr);
}
extern void mpi_bcast_(void* buffer, int* count, MPI_Fint* datatype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_bcast(buffer, count, datatype, root, comm, ierr);
}
extern void mpi_bcast__(void* buffer, int* count, MPI_Fint* datatype, int* root, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_bcast(buffer, count, datatype, root, comm, ierr);
}
int c_MPI_Get_processor_name(char *name, int *resultlen)
{
	PILGRIM_TRACING_1(int, MPI_Get_processor_name, (name, resultlen));
	void **args = assemble_args_list(2, name, resultlen);
	int sizes[] = { strlen(name)+1, 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Get_processor_name(char *name, int *resultlen) { return c_MPI_Get_processor_name(name, resultlen); }
extern void f_mpi_get_processor_name(char* name, int* resultlen, MPI_Fint *ierr) {
	c_MPI_Get_processor_name(name, resultlen);
}
extern void MPI_GET_PROCESSOR_NAME(char* name, int* resultlen, MPI_Fint *ierr) {
	f_mpi_get_processor_name(name, resultlen, ierr);
}
extern void mpi_get_processor_name(char* name, int* resultlen, MPI_Fint *ierr) {
	f_mpi_get_processor_name(name, resultlen, ierr);
}
extern void mpi_get_processor_name_(char* name, int* resultlen, MPI_Fint *ierr) {
	f_mpi_get_processor_name(name, resultlen, ierr);
}
extern void mpi_get_processor_name__(char* name, int* resultlen, MPI_Fint *ierr) {
	f_mpi_get_processor_name(name, resultlen, ierr);
}
int c_MPI_Ineighbor_allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ineighbor_allgather, (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(7, &mem_attr_0, &sendcount, &obj_id_0, &mem_attr_1, &recvcount, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Ineighbor_allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return c_MPI_Ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request); }
extern void f_mpi_ineighbor_allgather(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Ineighbor_allgather(sendbuf, (*sendcount), c_handle_0, recvbuf, (*recvcount), c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_INEIGHBOR_ALLGATHER(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}
extern void mpi_ineighbor_allgather(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}
extern void mpi_ineighbor_allgather_(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}
extern void mpi_ineighbor_allgather__(const void* sendbuf, int* sendcount, MPI_Fint* sendtype, void* recvbuf, int* recvcount, MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierr);
}
int c_MPI_Raccumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Raccumulate, (origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request));
	MemPtrAttr mem_attr_0;
	addr2id(origin_addr, &mem_attr_0);
	MPI_Datatype obj_0 = origin_datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Datatype obj_1 = target_datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Op obj_2 = op;
	int obj_id_2 = MPI_OBJ_ID(MPI_Op, &obj_2);
	MPI_Win obj_3 = win;
	int obj_id_3 = MPI_OBJ_ID(MPI_Win, &obj_3);
	void **args = assemble_args_list(9, &mem_attr_0, &origin_count, &obj_id_0, &target_rank, &target_disp, &target_count, &obj_id_1, &obj_id_2, &obj_id_3);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args, -1);
}
int MPI_Raccumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request) { return c_MPI_Raccumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request); }
extern void f_mpi_raccumulate(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*origin_datatype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*target_datatype);
	MPI_Op c_handle_2;
	c_handle_2 = PMPI_Op_f2c(*op);
	MPI_Win c_handle_3;
	c_handle_3 = PMPI_Win_f2c(*win);
	MPI_Request c_handle_4;
	c_handle_4 = PMPI_Request_f2c(*request);
	c_MPI_Raccumulate(origin_addr, (*origin_count), c_handle_0, (*target_rank), target_disp, (*target_count), c_handle_1, c_handle_2, c_handle_3, &c_handle_4);
	*request = PMPI_Request_c2f(c_handle_4);
}
extern void MPI_RACCUMULATE(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_raccumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierr);
}
extern void mpi_raccumulate(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_raccumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierr);
}
extern void mpi_raccumulate_(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_raccumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierr);
}
extern void mpi_raccumulate__(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_raccumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierr);
}
int c_MPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm, int *size)
{
	PILGRIM_TRACING_1(int, MPI_Pack_size, (incount, datatype, comm, size));
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(4, &incount, &obj_id_0, &obj_id_1, size);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm, int *size) { return c_MPI_Pack_size(incount, datatype, comm, size); }
extern void f_mpi_pack_size(int* incount, MPI_Fint* datatype, MPI_Fint* comm, int* size, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	c_MPI_Pack_size((*incount), c_handle_0, c_handle_1, size);
}
extern void MPI_PACK_SIZE(int* incount, MPI_Fint* datatype, MPI_Fint* comm, int* size, MPI_Fint *ierr) {
	f_mpi_pack_size(incount, datatype, comm, size, ierr);
}
extern void mpi_pack_size(int* incount, MPI_Fint* datatype, MPI_Fint* comm, int* size, MPI_Fint *ierr) {
	f_mpi_pack_size(incount, datatype, comm, size, ierr);
}
extern void mpi_pack_size_(int* incount, MPI_Fint* datatype, MPI_Fint* comm, int* size, MPI_Fint *ierr) {
	f_mpi_pack_size(incount, datatype, comm, size, ierr);
}
extern void mpi_pack_size__(int* incount, MPI_Fint* datatype, MPI_Fint* comm, int* size, MPI_Fint *ierr) {
	f_mpi_pack_size(incount, datatype, comm, size, ierr);
}
int c_MPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm)
{
	PILGRIM_TRACING_1(int, MPI_Intercomm_merge, (intercomm, high, newintracomm));
	generate_intracomm_id(newintracomm);
	MPI_Comm obj_0 = intercomm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, newintracomm);
	void **args = assemble_args_list(3, &obj_id_0, &high, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm) { return c_MPI_Intercomm_merge(intercomm, high, newintracomm); }
extern void f_mpi_intercomm_merge(MPI_Fint* intercomm, int* high, MPI_Fint* newintracomm, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*intercomm);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*newintracomm);
	c_MPI_Intercomm_merge(c_handle_0, (*high), &c_handle_1);
	*newintracomm = PMPI_Comm_c2f(c_handle_1);
}
extern void MPI_INTERCOMM_MERGE(MPI_Fint* intercomm, int* high, MPI_Fint* newintracomm, MPI_Fint *ierr) {
	f_mpi_intercomm_merge(intercomm, high, newintracomm, ierr);
}
extern void mpi_intercomm_merge(MPI_Fint* intercomm, int* high, MPI_Fint* newintracomm, MPI_Fint *ierr) {
	f_mpi_intercomm_merge(intercomm, high, newintracomm, ierr);
}
extern void mpi_intercomm_merge_(MPI_Fint* intercomm, int* high, MPI_Fint* newintracomm, MPI_Fint *ierr) {
	f_mpi_intercomm_merge(intercomm, high, newintracomm, ierr);
}
extern void mpi_intercomm_merge__(MPI_Fint* intercomm, int* high, MPI_Fint* newintracomm, MPI_Fint *ierr) {
	f_mpi_intercomm_merge(intercomm, high, newintracomm, ierr);
}
int c_MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent)
{
	PILGRIM_TRACING_1(int, MPI_File_get_type_extent, (fh, datatype, extent));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(3, &obj_id_0, &obj_id_1, extent);
	int sizes[] = { sizeof(int), sizeof(int), 1*sizeof(MPI_Aint) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent) { return c_MPI_File_get_type_extent(fh, datatype, extent); }
extern void f_mpi_file_get_type_extent(MPI_Fint* fh, MPI_Fint* datatype, MPI_Aint* extent, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	c_MPI_File_get_type_extent(c_handle_0, c_handle_1, extent);
}
extern void MPI_FILE_GET_TYPE_EXTENT(MPI_Fint* fh, MPI_Fint* datatype, MPI_Aint* extent, MPI_Fint *ierr) {
	f_mpi_file_get_type_extent(fh, datatype, extent, ierr);
}
extern void mpi_file_get_type_extent(MPI_Fint* fh, MPI_Fint* datatype, MPI_Aint* extent, MPI_Fint *ierr) {
	f_mpi_file_get_type_extent(fh, datatype, extent, ierr);
}
extern void mpi_file_get_type_extent_(MPI_Fint* fh, MPI_Fint* datatype, MPI_Aint* extent, MPI_Fint *ierr) {
	f_mpi_file_get_type_extent(fh, datatype, extent, ierr);
}
extern void mpi_file_get_type_extent__(MPI_Fint* fh, MPI_Fint* datatype, MPI_Aint* extent, MPI_Fint *ierr) {
	f_mpi_file_get_type_extent(fh, datatype, extent, ierr);
}
int c_MPI_Get_library_version(char *version, int *resultlen)
{
	PILGRIM_TRACING_1(int, MPI_Get_library_version, (version, resultlen));
	void **args = assemble_args_list(2, version, resultlen);
	int sizes[] = { strlen(version)+1, 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Get_library_version(char *version, int *resultlen) { return c_MPI_Get_library_version(version, resultlen); }
extern void f_mpi_get_library_version(char* version, int* resultlen, MPI_Fint *ierr) {
	c_MPI_Get_library_version(version, resultlen);
}
extern void MPI_GET_LIBRARY_VERSION(char* version, int* resultlen, MPI_Fint *ierr) {
	f_mpi_get_library_version(version, resultlen, ierr);
}
extern void mpi_get_library_version(char* version, int* resultlen, MPI_Fint *ierr) {
	f_mpi_get_library_version(version, resultlen, ierr);
}
extern void mpi_get_library_version_(char* version, int* resultlen, MPI_Fint *ierr) {
	f_mpi_get_library_version(version, resultlen, ierr);
}
extern void mpi_get_library_version__(char* version, int* resultlen, MPI_Fint *ierr) {
	f_mpi_get_library_version(version, resultlen, ierr);
}
int c_MPI_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Isend, (buf, count, datatype, dest, tag, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int dest_rank = g_mpi_rank - dest;
	if(dest == MPI_ANY_SOURCE) dest_rank = PILGRIM_MPI_ANY_SOURCE;
	if(dest == MPI_PROC_NULL) dest_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	int obj_id_2 = create_request_id(request, false, ID_MPI_Isend, dest, tag, obj_id_1);
	void **args = assemble_args_list(7, &mem_attr_0, &count, &obj_id_0, &dest_rank, &my_tag, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return c_MPI_Isend(buf, count, datatype, dest, tag, comm, request); }
extern void f_mpi_isend(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_Isend(buf, (*count), c_handle_0, (*dest), (*tag), c_handle_1, &c_handle_2);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_ISEND(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_isend(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_isend(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_isend(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_isend_(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_isend(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_isend__(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_isend(buf, count, datatype, dest, tag, comm, request, ierr);
}
int c_MPI_T_pvar_reset(MPI_T_pvar_session session, MPI_T_pvar_handle handle)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_reset, (session, handle));
	void **args = assemble_args_list(2, &session, &handle);
	int sizes[] = { sizeof(MPI_T_pvar_session), sizeof(MPI_T_pvar_handle) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_T_pvar_reset(MPI_T_pvar_session session, MPI_T_pvar_handle handle) { return c_MPI_T_pvar_reset(session, handle); }
int c_MPI_Start(MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Start, (request));
	void **args = NULL;
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_2(0, sizes, args, -1);
}
int MPI_Start(MPI_Request *request) { return c_MPI_Start(request); }
extern void f_mpi_start(MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Request c_handle_0;
	c_handle_0 = PMPI_Request_f2c(*request);
	c_MPI_Start(&c_handle_0);
	*request = PMPI_Request_c2f(c_handle_0);
}
extern void MPI_START(MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_start(request, ierr);
}
extern void mpi_start(MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_start(request, ierr);
}
extern void mpi_start_(MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_start(request, ierr);
}
extern void mpi_start__(MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_start(request, ierr);
}
int c_MPI_Unpack(const void *inbuf, int insize, int *position, void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Unpack, (inbuf, insize, position, outbuf, outcount, datatype, comm));
	MemPtrAttr mem_attr_0;
	addr2id(inbuf, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(outbuf, &mem_attr_1);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(7, &mem_attr_0, &insize, position, &mem_attr_1, &outcount, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), 1*sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Unpack(const void *inbuf, int insize, int *position, void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm) { return c_MPI_Unpack(inbuf, insize, position, outbuf, outcount, datatype, comm); }
extern void f_mpi_unpack(const void* inbuf, int* insize, int* position, void* outbuf, int* outcount, MPI_Fint* datatype, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	c_MPI_Unpack(inbuf, (*insize), position, outbuf, (*outcount), c_handle_0, c_handle_1);
}
extern void MPI_UNPACK(const void* inbuf, int* insize, int* position, void* outbuf, int* outcount, MPI_Fint* datatype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_unpack(inbuf, insize, position, outbuf, outcount, datatype, comm, ierr);
}
extern void mpi_unpack(const void* inbuf, int* insize, int* position, void* outbuf, int* outcount, MPI_Fint* datatype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_unpack(inbuf, insize, position, outbuf, outcount, datatype, comm, ierr);
}
extern void mpi_unpack_(const void* inbuf, int* insize, int* position, void* outbuf, int* outcount, MPI_Fint* datatype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_unpack(inbuf, insize, position, outbuf, outcount, datatype, comm, ierr);
}
extern void mpi_unpack__(const void* inbuf, int* insize, int* position, void* outbuf, int* outcount, MPI_Fint* datatype, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_unpack(inbuf, insize, position, outbuf, outcount, datatype, comm, ierr);
}
int c_MPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype, char *datarep)
{
	PILGRIM_TRACING_1(int, MPI_File_get_view, (fh, disp, etype, filetype, datarep));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, etype);
	int obj_id_2 = MPI_OBJ_ID(MPI_Datatype, filetype);
	void **args = assemble_args_list(5, &obj_id_0, disp, &obj_id_1, &obj_id_2, datarep);
	int sizes[] = { sizeof(int), 1*sizeof(MPI_Offset), sizeof(int), sizeof(int), strlen(datarep)+1 };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype, char *datarep) { return c_MPI_File_get_view(fh, disp, etype, filetype, datarep); }
extern void f_mpi_file_get_view(MPI_Fint* fh, MPI_Offset* disp, MPI_Fint* etype, MPI_Fint* filetype, char* datarep, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*etype);
	MPI_Datatype c_handle_2;
	c_handle_2 = PMPI_Type_f2c(*filetype);
	c_MPI_File_get_view(c_handle_0, disp, &c_handle_1, &c_handle_2, datarep);
	*etype = PMPI_Type_c2f(c_handle_1);
	*filetype = PMPI_Type_c2f(c_handle_2);
}
extern void MPI_FILE_GET_VIEW(MPI_Fint* fh, MPI_Offset* disp, MPI_Fint* etype, MPI_Fint* filetype, char* datarep, MPI_Fint *ierr) {
	f_mpi_file_get_view(fh, disp, etype, filetype, datarep, ierr);
}
extern void mpi_file_get_view(MPI_Fint* fh, MPI_Offset* disp, MPI_Fint* etype, MPI_Fint* filetype, char* datarep, MPI_Fint *ierr) {
	f_mpi_file_get_view(fh, disp, etype, filetype, datarep, ierr);
}
extern void mpi_file_get_view_(MPI_Fint* fh, MPI_Offset* disp, MPI_Fint* etype, MPI_Fint* filetype, char* datarep, MPI_Fint *ierr) {
	f_mpi_file_get_view(fh, disp, etype, filetype, datarep, ierr);
}
extern void mpi_file_get_view__(MPI_Fint* fh, MPI_Offset* disp, MPI_Fint* etype, MPI_Fint* filetype, char* datarep, MPI_Fint *ierr) {
	f_mpi_file_get_view(fh, disp, etype, filetype, datarep, ierr);
}
int c_MPI_T_pvar_session_free(MPI_T_pvar_session *session)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_session_free, (session));
	void **args = assemble_args_list(1, session);
	int sizes[] = { 1*sizeof(MPI_T_pvar_session) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_T_pvar_session_free(MPI_T_pvar_session *session) { return c_MPI_T_pvar_session_free(session); }
int c_MPI_Iexscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Iexscan, (sendbuf, recvbuf, count, datatype, op, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Op obj_1 = op;
	int obj_id_1 = MPI_OBJ_ID(MPI_Op, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(6, &mem_attr_0, &mem_attr_1, &count, &obj_id_0, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Iexscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { return c_MPI_Iexscan(sendbuf, recvbuf, count, datatype, op, comm, request); }
extern void f_mpi_iexscan(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Op c_handle_1;
	c_handle_1 = PMPI_Op_f2c(*op);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Iexscan(sendbuf, recvbuf, (*count), c_handle_0, c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_IEXSCAN(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iexscan(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}
extern void mpi_iexscan(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iexscan(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}
extern void mpi_iexscan_(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iexscan(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}
extern void mpi_iexscan__(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_iexscan(sendbuf, recvbuf, count, datatype, op, comm, request, ierr);
}
int c_MPI_Unpack_external(const char datarep[], const void *inbuf, MPI_Aint insize, MPI_Aint *position, void *outbuf, int outcount, MPI_Datatype datatype)
{
	PILGRIM_TRACING_1(int, MPI_Unpack_external, (datarep, inbuf, insize, position, outbuf, outcount, datatype));
	MemPtrAttr mem_attr_0;
	addr2id(inbuf, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(outbuf, &mem_attr_1);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	void **args = assemble_args_list(7, datarep, &mem_attr_0, &insize, position, &mem_attr_1, &outcount, &obj_id_0);
	int sizes[] = { strlen(datarep)+1, sizeof(MemPtrAttr), sizeof(MPI_Aint), 1*sizeof(MPI_Aint), sizeof(MemPtrAttr), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Unpack_external(const char datarep[], const void *inbuf, MPI_Aint insize, MPI_Aint *position, void *outbuf, int outcount, MPI_Datatype datatype) { return c_MPI_Unpack_external(datarep, inbuf, insize, position, outbuf, outcount, datatype); }
extern void f_mpi_unpack_external(const char datarep[], const void* inbuf, MPI_Aint insize, MPI_Aint* position, void* outbuf, int* outcount, MPI_Fint* datatype, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	c_MPI_Unpack_external(datarep, inbuf, insize, position, outbuf, (*outcount), c_handle_0);
}
extern void MPI_UNPACK_EXTERNAL(const char datarep[], const void* inbuf, MPI_Aint insize, MPI_Aint* position, void* outbuf, int* outcount, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_unpack_external(datarep, inbuf, insize, position, outbuf, outcount, datatype, ierr);
}
extern void mpi_unpack_external(const char datarep[], const void* inbuf, MPI_Aint insize, MPI_Aint* position, void* outbuf, int* outcount, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_unpack_external(datarep, inbuf, insize, position, outbuf, outcount, datatype, ierr);
}
extern void mpi_unpack_external_(const char datarep[], const void* inbuf, MPI_Aint insize, MPI_Aint* position, void* outbuf, int* outcount, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_unpack_external(datarep, inbuf, insize, position, outbuf, outcount, datatype, ierr);
}
extern void mpi_unpack_external__(const char datarep[], const void* inbuf, MPI_Aint insize, MPI_Aint* position, void* outbuf, int* outcount, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_unpack_external(datarep, inbuf, insize, position, outbuf, outcount, datatype, ierr);
}
int c_MPI_Win_unlock(int rank, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Win_unlock, (rank, win));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	void **args = assemble_args_list(2, &rank, &obj_id_0);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Win_unlock(int rank, MPI_Win win) { return c_MPI_Win_unlock(rank, win); }
extern void f_mpi_win_unlock(int* rank, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_unlock((*rank), c_handle_0);
}
extern void MPI_WIN_UNLOCK(int* rank, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_unlock(rank, win, ierr);
}
extern void mpi_win_unlock(int* rank, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_unlock(rank, win, ierr);
}
extern void mpi_win_unlock_(int* rank, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_unlock(rank, win, ierr);
}
extern void mpi_win_unlock__(int* rank, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_win_unlock(rank, win, ierr);
}
int c_MPI_Request_get_status(MPI_Request request, int *flag, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Request_get_status, (request, flag, status));
	MPI_Request obj_0 = request;
	int obj_id_0 = MPI_OBJ_ID(MPI_Request, &obj_0);
	int status_arg[2] = {0};
	void **args = assemble_args_list(3, &obj_id_0, flag, status_arg);
	int sizes[] = { sizeof(int), 1*sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Request_get_status(MPI_Request request, int *flag, MPI_Status *status) { return c_MPI_Request_get_status(request, flag, status); }
extern void f_mpi_request_get_status(MPI_Fint* request, int* flag, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_Request c_handle_0;
	c_handle_0 = PMPI_Request_f2c(*request);
	MPI_Status c_handle_1;
	PMPI_Status_f2c(status, &c_handle_1);
	c_MPI_Request_get_status(c_handle_0, flag, &c_handle_1);
	PMPI_Status_c2f(&c_handle_1, status);
}
extern void MPI_REQUEST_GET_STATUS(MPI_Fint* request, int* flag, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_request_get_status(request, flag, status, ierr);
}
extern void mpi_request_get_status(MPI_Fint* request, int* flag, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_request_get_status(request, flag, status, ierr);
}
extern void mpi_request_get_status_(MPI_Fint* request, int* flag, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_request_get_status(request, flag, status, ierr);
}
extern void mpi_request_get_status__(MPI_Fint* request, int* flag, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_request_get_status(request, flag, status, ierr);
}
int c_MPI_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read_at_all_end, (fh, buf, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	int status_arg[2] = {0};
	void **args = assemble_args_list(3, &obj_id_0, &mem_attr_0, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int)*2 };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status) { return c_MPI_File_read_at_all_end(fh, buf, status); }
extern void f_mpi_file_read_at_all_end(MPI_Fint* fh, void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Status c_handle_1;
	PMPI_Status_f2c(status, &c_handle_1);
	c_MPI_File_read_at_all_end(c_handle_0, buf, &c_handle_1);
	PMPI_Status_c2f(&c_handle_1, status);
}
extern void MPI_FILE_READ_AT_ALL_END(MPI_Fint* fh, void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_at_all_end(fh, buf, status, ierr);
}
extern void mpi_file_read_at_all_end(MPI_Fint* fh, void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_at_all_end(fh, buf, status, ierr);
}
extern void mpi_file_read_at_all_end_(MPI_Fint* fh, void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_at_all_end(fh, buf, status, ierr);
}
extern void mpi_file_read_at_all_end__(MPI_Fint* fh, void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_at_all_end(fh, buf, status, ierr);
}
int c_MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, const char *datarep, MPI_Info info)
{
	PILGRIM_TRACING_1(int, MPI_File_set_view, (fh, disp, etype, filetype, datarep, info));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	append_offset(disp);
	MPI_Datatype obj_1 = etype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Datatype obj_2 = filetype;
	int obj_id_2 = MPI_OBJ_ID(MPI_Datatype, &obj_2);
	MPI_Info obj_3 = info;
	int obj_id_3 = MPI_OBJ_ID(MPI_Info, &obj_3);
	void **args = assemble_args_list(5, &obj_id_0, &obj_id_1, &obj_id_2, datarep, &obj_id_3);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), strlen(datarep)+1, sizeof(int) };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, const char *datarep, MPI_Info info) { return c_MPI_File_set_view(fh, disp, etype, filetype, datarep, info); }
extern void f_mpi_file_set_view(MPI_Fint* fh, MPI_Offset disp, MPI_Fint* etype, MPI_Fint* filetype, const char* datarep, MPI_Fint* info, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*etype);
	MPI_Datatype c_handle_2;
	c_handle_2 = PMPI_Type_f2c(*filetype);
	MPI_Info c_handle_3;
	c_handle_3 = PMPI_Info_f2c(*info);
	c_MPI_File_set_view(c_handle_0, disp, c_handle_1, c_handle_2, datarep, c_handle_3);
	*fh = PMPI_File_c2f(c_handle_0);
}
extern void MPI_FILE_SET_VIEW(MPI_Fint* fh, MPI_Offset disp, MPI_Fint* etype, MPI_Fint* filetype, const char* datarep, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_file_set_view(fh, disp, etype, filetype, datarep, info, ierr);
}
extern void mpi_file_set_view(MPI_Fint* fh, MPI_Offset disp, MPI_Fint* etype, MPI_Fint* filetype, const char* datarep, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_file_set_view(fh, disp, etype, filetype, datarep, info, ierr);
}
extern void mpi_file_set_view_(MPI_Fint* fh, MPI_Offset disp, MPI_Fint* etype, MPI_Fint* filetype, const char* datarep, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_file_set_view(fh, disp, etype, filetype, datarep, info, ierr);
}
extern void mpi_file_set_view__(MPI_Fint* fh, MPI_Offset disp, MPI_Fint* etype, MPI_Fint* filetype, const char* datarep, MPI_Fint* info, MPI_Fint *ierr) {
	f_mpi_file_set_view(fh, disp, etype, filetype, datarep, info, ierr);
}
int c_MPI_Status_set_elements(MPI_Status *status, MPI_Datatype datatype, int count)
{
	PILGRIM_TRACING_1(int, MPI_Status_set_elements, (status, datatype, count));
	int status_arg[2] = {0};
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	void **args = assemble_args_list(3, status_arg, &obj_id_0, &count);
	int sizes[] = { sizeof(int)*2, sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Status_set_elements(MPI_Status *status, MPI_Datatype datatype, int count) { return c_MPI_Status_set_elements(status, datatype, count); }
extern void f_mpi_status_set_elements(MPI_Fint* status, MPI_Fint* datatype, int* count, MPI_Fint *ierr) {
	MPI_Status c_handle_0;
	PMPI_Status_f2c(status, &c_handle_0);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	c_MPI_Status_set_elements(&c_handle_0, c_handle_1, (*count));
	PMPI_Status_c2f(&c_handle_0, status);
}
extern void MPI_STATUS_SET_ELEMENTS(MPI_Fint* status, MPI_Fint* datatype, int* count, MPI_Fint *ierr) {
	f_mpi_status_set_elements(status, datatype, count, ierr);
}
extern void mpi_status_set_elements(MPI_Fint* status, MPI_Fint* datatype, int* count, MPI_Fint *ierr) {
	f_mpi_status_set_elements(status, datatype, count, ierr);
}
extern void mpi_status_set_elements_(MPI_Fint* status, MPI_Fint* datatype, int* count, MPI_Fint *ierr) {
	f_mpi_status_set_elements(status, datatype, count, ierr);
}
extern void mpi_status_set_elements__(MPI_Fint* status, MPI_Fint* datatype, int* count, MPI_Fint *ierr) {
	f_mpi_status_set_elements(status, datatype, count, ierr);
}
int c_MPI_T_category_get_categories(int cat_index, int len, int indices[])
{
	PILGRIM_TRACING_1(int, MPI_T_category_get_categories, (cat_index, len, indices));
	void **args = assemble_args_list(3, &cat_index, &len, indices);
	int sizes[] = { sizeof(int), sizeof(int), len*sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_T_category_get_categories(int cat_index, int len, int indices[]) { return c_MPI_T_category_get_categories(cat_index, len, indices); }
int c_MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup)
{
	PILGRIM_TRACING_1(int, MPI_Group_range_incl, (group, n, ranges, newgroup));
	MPI_Group obj_0 = group;
	int obj_id_0 = MPI_OBJ_ID(MPI_Group, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Group, newgroup);
	void **args = assemble_args_list(4, &obj_id_0, &n, ranges, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int), n*3*sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup) { return c_MPI_Group_range_incl(group, n, ranges, newgroup); }
extern void f_mpi_group_range_incl(MPI_Fint* group, int* n, int ranges[][3], MPI_Fint* newgroup, MPI_Fint *ierr) {
	MPI_Group c_handle_0;
	c_handle_0 = PMPI_Group_f2c(*group);
	MPI_Group c_handle_1;
	c_handle_1 = PMPI_Group_f2c(*newgroup);
	c_MPI_Group_range_incl(c_handle_0, (*n), ranges, &c_handle_1);
	*newgroup = PMPI_Group_c2f(c_handle_1);
}
extern void MPI_GROUP_RANGE_INCL(MPI_Fint* group, int* n, int ranges[][3], MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_range_incl(group, n, ranges, newgroup, ierr);
}
extern void mpi_group_range_incl(MPI_Fint* group, int* n, int ranges[][3], MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_range_incl(group, n, ranges, newgroup, ierr);
}
extern void mpi_group_range_incl_(MPI_Fint* group, int* n, int ranges[][3], MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_range_incl(group, n, ranges, newgroup, ierr);
}
extern void mpi_group_range_incl__(MPI_Fint* group, int* n, int ranges[][3], MPI_Fint* newgroup, MPI_Fint *ierr) {
	f_mpi_group_range_incl(group, n, ranges, newgroup, ierr);
}
int c_MPI_Get(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Get, (origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win));
	MemPtrAttr mem_attr_0;
	addr2id(origin_addr, &mem_attr_0);
	MPI_Datatype obj_0 = origin_datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Datatype obj_1 = target_datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Win obj_2 = win;
	int obj_id_2 = MPI_OBJ_ID(MPI_Win, &obj_2);
	void **args = assemble_args_list(8, &mem_attr_0, &origin_count, &obj_id_0, &target_rank, &target_disp, &target_count, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(8, sizes, args, -1);
}
int MPI_Get(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win) { return c_MPI_Get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win); }
extern void f_mpi_get(void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*origin_datatype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*target_datatype);
	MPI_Win c_handle_2;
	c_handle_2 = PMPI_Win_f2c(*win);
	c_MPI_Get(origin_addr, (*origin_count), c_handle_0, (*target_rank), target_disp, (*target_count), c_handle_1, c_handle_2);
}
extern void MPI_GET(void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierr);
}
extern void mpi_get(void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierr);
}
extern void mpi_get_(void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierr);
}
extern void mpi_get__(void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierr);
}
int c_MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Iprobe, (source, tag, comm, flag, status));
	int source_rank = g_mpi_rank - source;
	if(source == MPI_ANY_SOURCE) source_rank = PILGRIM_MPI_ANY_SOURCE;
	if(source == MPI_PROC_NULL) source_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	int status_arg[2] = {0};
	if(source == MPI_ANY_SOURCE && status && status!=MPI_STATUS_IGNORE) status_arg[0] = status->MPI_SOURCE;
	if(tag == MPI_ANY_TAG && status && status!=MPI_STATUS_IGNORE) status_arg[1] = status->MPI_TAG;
	void **args = assemble_args_list(5, &source_rank, &my_tag, &obj_id_0, flag, status_arg);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), 1*sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag, MPI_Status *status) { return c_MPI_Iprobe(source, tag, comm, flag, status); }
extern void f_mpi_iprobe(int* source, int* tag, MPI_Fint* comm, int* flag, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Status c_handle_1;
	PMPI_Status_f2c(status, &c_handle_1);
	c_MPI_Iprobe((*source), (*tag), c_handle_0, flag, &c_handle_1);
	PMPI_Status_c2f(&c_handle_1, status);
}
extern void MPI_IPROBE(int* source, int* tag, MPI_Fint* comm, int* flag, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_iprobe(source, tag, comm, flag, status, ierr);
}
extern void mpi_iprobe(int* source, int* tag, MPI_Fint* comm, int* flag, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_iprobe(source, tag, comm, flag, status, ierr);
}
extern void mpi_iprobe_(int* source, int* tag, MPI_Fint* comm, int* flag, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_iprobe(source, tag, comm, flag, status, ierr);
}
extern void mpi_iprobe__(int* source, int* tag, MPI_Fint* comm, int* flag, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_iprobe(source, tag, comm, flag, status, ierr);
}
int c_MPI_Comm_join(int fd, MPI_Comm *intercomm)
{
	PILGRIM_TRACING_1(int, MPI_Comm_join, (fd, intercomm));
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, intercomm);
	void **args = assemble_args_list(2, &fd, &obj_id_0);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_join(int fd, MPI_Comm *intercomm) { return c_MPI_Comm_join(fd, intercomm); }
extern void f_mpi_comm_join(int* fd, MPI_Fint* intercomm, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*intercomm);
	c_MPI_Comm_join((*fd), &c_handle_0);
	*intercomm = PMPI_Comm_c2f(c_handle_0);
}
extern void MPI_COMM_JOIN(int* fd, MPI_Fint* intercomm, MPI_Fint *ierr) {
	f_mpi_comm_join(fd, intercomm, ierr);
}
extern void mpi_comm_join(int* fd, MPI_Fint* intercomm, MPI_Fint *ierr) {
	f_mpi_comm_join(fd, intercomm, ierr);
}
extern void mpi_comm_join_(int* fd, MPI_Fint* intercomm, MPI_Fint *ierr) {
	f_mpi_comm_join(fd, intercomm, ierr);
}
extern void mpi_comm_join__(int* fd, MPI_Fint* intercomm, MPI_Fint *ierr) {
	f_mpi_comm_join(fd, intercomm, ierr);
}
int c_MPI_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_read_shared, (fh, buf, count, datatype, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	int status_arg[2] = {0};
	void **args = assemble_args_list(5, &obj_id_0, &mem_attr_0, &count, &obj_id_1, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(5, sizes, args, -1);
}
int MPI_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return c_MPI_File_read_shared(fh, buf, count, datatype, status); }
extern void f_mpi_file_read_shared(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_File_read_shared(c_handle_0, buf, (*count), c_handle_1, &c_handle_2);
	*fh = PMPI_File_c2f(c_handle_0);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_FILE_READ_SHARED(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_shared(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_read_shared(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_shared(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_read_shared_(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_shared(fh, buf, count, datatype, status, ierr);
}
extern void mpi_file_read_shared__(MPI_Fint* fh, void* buf, int* count, MPI_Fint* datatype, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_read_shared(fh, buf, count, datatype, status, ierr);
}
int c_MPI_Win_detach(MPI_Win win, const void *base)
{
	PILGRIM_TRACING_1(int, MPI_Win_detach, (win, base));
	MPI_Win obj_0 = win;
	int obj_id_0 = MPI_OBJ_ID(MPI_Win, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(base, &mem_attr_0);
	void **args = assemble_args_list(2, &obj_id_0, &mem_attr_0);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Win_detach(MPI_Win win, const void *base) { return c_MPI_Win_detach(win, base); }
extern void f_mpi_win_detach(MPI_Fint* win, const void* base, MPI_Fint *ierr) {
	MPI_Win c_handle_0;
	c_handle_0 = PMPI_Win_f2c(*win);
	c_MPI_Win_detach(c_handle_0, base);
}
extern void MPI_WIN_DETACH(MPI_Fint* win, const void* base, MPI_Fint *ierr) {
	f_mpi_win_detach(win, base, ierr);
}
extern void mpi_win_detach(MPI_Fint* win, const void* base, MPI_Fint *ierr) {
	f_mpi_win_detach(win, base, ierr);
}
extern void mpi_win_detach_(MPI_Fint* win, const void* base, MPI_Fint *ierr) {
	f_mpi_win_detach(win, base, ierr);
}
extern void mpi_win_detach__(MPI_Fint* win, const void* base, MPI_Fint *ierr) {
	f_mpi_win_detach(win, base, ierr);
}
int c_MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag, MPI_Message *message, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_Improbe, (source, tag, comm, flag, message, status));
	int source_rank = g_mpi_rank - source;
	if(source == MPI_ANY_SOURCE) source_rank = PILGRIM_MPI_ANY_SOURCE;
	if(source == MPI_PROC_NULL) source_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Message, message);
	int status_arg[2] = {0};
	if(source == MPI_ANY_SOURCE && status && status!=MPI_STATUS_IGNORE) status_arg[0] = status->MPI_SOURCE;
	if(tag == MPI_ANY_TAG && status && status!=MPI_STATUS_IGNORE) status_arg[1] = status->MPI_TAG;
	void **args = assemble_args_list(6, &source_rank, &my_tag, &obj_id_0, flag, &obj_id_1, status_arg);
	int sizes[] = { sizeof(int), sizeof(int), sizeof(int), 1*sizeof(int), sizeof(int), sizeof(int)*2 };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag, MPI_Message *message, MPI_Status *status) { return c_MPI_Improbe(source, tag, comm, flag, message, status); }
extern void f_mpi_improbe(int* source, int* tag, MPI_Fint* comm, int* flag, MPI_Fint* message, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Message c_handle_1;
	c_handle_1 = PMPI_Message_f2c(*message);
	MPI_Status c_handle_2;
	PMPI_Status_f2c(status, &c_handle_2);
	c_MPI_Improbe((*source), (*tag), c_handle_0, flag, &c_handle_1, &c_handle_2);
	*message = PMPI_Message_c2f(c_handle_1);
	PMPI_Status_c2f(&c_handle_2, status);
}
extern void MPI_IMPROBE(int* source, int* tag, MPI_Fint* comm, int* flag, MPI_Fint* message, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_improbe(source, tag, comm, flag, message, status, ierr);
}
extern void mpi_improbe(int* source, int* tag, MPI_Fint* comm, int* flag, MPI_Fint* message, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_improbe(source, tag, comm, flag, message, status, ierr);
}
extern void mpi_improbe_(int* source, int* tag, MPI_Fint* comm, int* flag, MPI_Fint* message, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_improbe(source, tag, comm, flag, message, status, ierr);
}
extern void mpi_improbe__(int* source, int* tag, MPI_Fint* comm, int* flag, MPI_Fint* message, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_improbe(source, tag, comm, flag, message, status, ierr);
}
int c_MPI_Ssend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
	PILGRIM_TRACING_1(int, MPI_Ssend, (buf, count, datatype, dest, tag, comm));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int dest_rank = g_mpi_rank - dest;
	if(dest == MPI_ANY_SOURCE) dest_rank = PILGRIM_MPI_ANY_SOURCE;
	if(dest == MPI_PROC_NULL) dest_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(6, &mem_attr_0, &count, &obj_id_0, &dest_rank, &my_tag, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Ssend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { return c_MPI_Ssend(buf, count, datatype, dest, tag, comm); }
extern void f_mpi_ssend(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	c_MPI_Ssend(buf, (*count), c_handle_0, (*dest), (*tag), c_handle_1);
}
extern void MPI_SSEND(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_ssend(buf, count, datatype, dest, tag, comm, ierr);
}
extern void mpi_ssend(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_ssend(buf, count, datatype, dest, tag, comm, ierr);
}
extern void mpi_ssend_(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_ssend(buf, count, datatype, dest, tag, comm, ierr);
}
extern void mpi_ssend__(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint *ierr) {
	f_mpi_ssend(buf, count, datatype, dest, tag, comm, ierr);
}
int c_MPI_Ineighbor_alltoallw(const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ineighbor_alltoallw, (sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	int obj_id_0[comm_size];
	for(int i=0; i<comm_size; i++) obj_id_0[i] = (sendtypes==NULL) ? PILGRIM_INVALID_MPI_OBJECT_ID: MPI_OBJ_ID(MPI_Datatype, &sendtypes[i]);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	int obj_id_1[comm_size];
	for(int i=0; i<comm_size; i++) obj_id_1[i] = (recvtypes==NULL) ? PILGRIM_INVALID_MPI_OBJECT_ID: MPI_OBJ_ID(MPI_Datatype, &recvtypes[i]);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(9, &mem_attr_0, sendcounts, sdispls, obj_id_0, &mem_attr_1, recvcounts, rdispls, obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const MPI_Aint), (comm_size)*sizeof(int), sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const MPI_Aint), (comm_size)*sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args, comm_size);
}
int MPI_Ineighbor_alltoallw(const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request) { return c_MPI_Ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request); }
extern void f_mpi_ineighbor_alltoallw(const void* sendbuf, const int sendcounts[], const MPI_Aint sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const MPI_Aint rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0[comm_size];
	for(int i = 0; i < comm_size; i++) c_handle_0[i] = PMPI_Type_f2c(sendtypes[i]);
	MPI_Datatype c_handle_1[comm_size];
	for(int i = 0; i < comm_size; i++) c_handle_1[i] = PMPI_Type_f2c(recvtypes[i]);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Ineighbor_alltoallw(sendbuf, sendcounts, sdispls, c_handle_0, recvbuf, recvcounts, rdispls, c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_INEIGHBOR_ALLTOALLW(const void* sendbuf, const int sendcounts[], const MPI_Aint sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const MPI_Aint rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierr);
}
extern void mpi_ineighbor_alltoallw(const void* sendbuf, const int sendcounts[], const MPI_Aint sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const MPI_Aint rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierr);
}
extern void mpi_ineighbor_alltoallw_(const void* sendbuf, const int sendcounts[], const MPI_Aint sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const MPI_Aint rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierr);
}
extern void mpi_ineighbor_alltoallw__(const void* sendbuf, const int sendcounts[], const MPI_Aint sdispls[], MPI_Fint* sendtypes, void* recvbuf, const int recvcounts[], const MPI_Aint rdispls[], MPI_Fint* recvtypes, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierr);
}
int c_MPI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ineighbor_alltoallv, (sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request));
	int comm_size;
	PMPI_Comm_size(comm, &comm_size);
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MPI_Datatype obj_0 = sendtype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_1 = recvtype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(9, &mem_attr_0, sendcounts, sdispls, &obj_id_0, &mem_attr_1, recvcounts, rdispls, &obj_id_1, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), sizeof(int), sizeof(MemPtrAttr), comm_size*sizeof(const int), comm_size*sizeof(const int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args, comm_size);
}
int MPI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return c_MPI_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request); }
extern void f_mpi_ineighbor_alltoallv(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	int comm_size;
	PMPI_Comm_size(PMPI_Comm_f2c(*comm), &comm_size);
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*sendtype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*recvtype);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls, c_handle_0, recvbuf, recvcounts, rdispls, c_handle_1, c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_INEIGHBOR_ALLTOALLV(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierr);
}
extern void mpi_ineighbor_alltoallv(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierr);
}
extern void mpi_ineighbor_alltoallv_(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierr);
}
extern void mpi_ineighbor_alltoallv__(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Fint* sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Fint* recvtype, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierr);
}
int c_MPI_T_category_get_cvars(int cat_index, int len, int indices[])
{
	PILGRIM_TRACING_1(int, MPI_T_category_get_cvars, (cat_index, len, indices));
	void **args = assemble_args_list(3, &cat_index, &len, indices);
	int sizes[] = { sizeof(int), sizeof(int), len*sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_T_category_get_cvars(int cat_index, int len, int indices[]) { return c_MPI_T_category_get_cvars(cat_index, len, indices); }
int c_MPI_Errhandler_free(MPI_Errhandler *errhandler)
{
	int obj_id_0 = MPI_OBJ_ID(MPI_Errhandler, errhandler);
	void **args = assemble_args_list(1, &obj_id_0);
	MPI_OBJ_RELEASE(MPI_Errhandler, errhandler);
	int sizes[] = { sizeof(int) };
	PILGRIM_TRACING_1(int, MPI_Errhandler_free, (errhandler));
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_Errhandler_free(MPI_Errhandler *errhandler) { return c_MPI_Errhandler_free(errhandler); }
extern void f_mpi_errhandler_free(MPI_Fint* errhandler, MPI_Fint *ierr) {
	MPI_Errhandler c_handle_0;
	c_handle_0 = PMPI_Errhandler_f2c(*errhandler);
	c_MPI_Errhandler_free(&c_handle_0);
	*errhandler = PMPI_Errhandler_c2f(c_handle_0);
}
extern void MPI_ERRHANDLER_FREE(MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_errhandler_free(errhandler, ierr);
}
extern void mpi_errhandler_free(MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_errhandler_free(errhandler, ierr);
}
extern void mpi_errhandler_free_(MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_errhandler_free(errhandler, ierr);
}
extern void mpi_errhandler_free__(MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_errhandler_free(errhandler, ierr);
}
int c_MPI_Topo_test(MPI_Comm comm, int *status)
{
	PILGRIM_TRACING_1(int, MPI_Topo_test, (comm, status));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(2, &obj_id_0, status);
	int sizes[] = { sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Topo_test(MPI_Comm comm, int *status) { return c_MPI_Topo_test(comm, status); }
extern void f_mpi_topo_test(MPI_Fint* comm, int* status, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Topo_test(c_handle_0, status);
}
extern void MPI_TOPO_TEST(MPI_Fint* comm, int* status, MPI_Fint *ierr) {
	f_mpi_topo_test(comm, status, ierr);
}
extern void mpi_topo_test(MPI_Fint* comm, int* status, MPI_Fint *ierr) {
	f_mpi_topo_test(comm, status, ierr);
}
extern void mpi_topo_test_(MPI_Fint* comm, int* status, MPI_Fint *ierr) {
	f_mpi_topo_test(comm, status, ierr);
}
extern void mpi_topo_test__(MPI_Fint* comm, int* status, MPI_Fint *ierr) {
	f_mpi_topo_test(comm, status, ierr);
}
int c_MPI_Ireduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Ireduce, (sendbuf, recvbuf, count, datatype, op, root, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(sendbuf, &mem_attr_0);
	MemPtrAttr mem_attr_1;
	addr2id(recvbuf, &mem_attr_1);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Op obj_1 = op;
	int obj_id_1 = MPI_OBJ_ID(MPI_Op, &obj_1);
	MPI_Comm obj_2 = comm;
	int obj_id_2 = MPI_OBJ_ID(MPI_Comm, &obj_2);
	void **args = assemble_args_list(7, &mem_attr_0, &mem_attr_1, &count, &obj_id_0, &obj_id_1, &root, &obj_id_2);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(7, sizes, args, -1);
}
int MPI_Ireduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Request *request) { return c_MPI_Ireduce(sendbuf, recvbuf, count, datatype, op, root, comm, request); }
extern void f_mpi_ireduce(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Op c_handle_1;
	c_handle_1 = PMPI_Op_f2c(*op);
	MPI_Comm c_handle_2;
	c_handle_2 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_3;
	c_handle_3 = PMPI_Request_f2c(*request);
	c_MPI_Ireduce(sendbuf, recvbuf, (*count), c_handle_0, c_handle_1, (*root), c_handle_2, &c_handle_3);
	*request = PMPI_Request_c2f(c_handle_3);
}
extern void MPI_IREDUCE(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ireduce(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierr);
}
extern void mpi_ireduce(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ireduce(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierr);
}
extern void mpi_ireduce_(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ireduce(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierr);
}
extern void mpi_ireduce__(const void* sendbuf, void* recvbuf, int* count, MPI_Fint* datatype, MPI_Fint* op, int* root, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_ireduce(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierr);
}
int c_MPI_File_get_errhandler(MPI_File file, MPI_Errhandler *errhandler)
{
	PILGRIM_TRACING_1(int, MPI_File_get_errhandler, (file, errhandler));
	MPI_File obj_0 = file;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	int obj_id_1 = MPI_OBJ_ID(MPI_Errhandler, errhandler);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_File_get_errhandler(MPI_File file, MPI_Errhandler *errhandler) { return c_MPI_File_get_errhandler(file, errhandler); }
extern void f_mpi_file_get_errhandler(MPI_Fint* file, MPI_Fint* errhandler, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*file);
	MPI_Errhandler c_handle_1;
	c_handle_1 = PMPI_Errhandler_f2c(*errhandler);
	c_MPI_File_get_errhandler(c_handle_0, &c_handle_1);
	*errhandler = PMPI_Errhandler_c2f(c_handle_1);
}
extern void MPI_FILE_GET_ERRHANDLER(MPI_Fint* file, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_file_get_errhandler(file, errhandler, ierr);
}
extern void mpi_file_get_errhandler(MPI_Fint* file, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_file_get_errhandler(file, errhandler, ierr);
}
extern void mpi_file_get_errhandler_(MPI_Fint* file, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_file_get_errhandler(file, errhandler, ierr);
}
extern void mpi_file_get_errhandler__(MPI_Fint* file, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_file_get_errhandler(file, errhandler, ierr);
}
int c_MPI_Bsend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	PILGRIM_TRACING_1(int, MPI_Bsend_init, (buf, count, datatype, dest, tag, comm, request));
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_0 = datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	int dest_rank = g_mpi_rank - dest;
	if(dest == MPI_ANY_SOURCE) dest_rank = PILGRIM_MPI_ANY_SOURCE;
	if(dest == MPI_PROC_NULL) dest_rank = PILGRIM_MPI_PROC_NULL;
	int my_tag = tag;
	if(my_tag == MPI_ANY_TAG) my_tag = PILGRIM_MPI_ANY_TAG;
	MPI_Comm obj_1 = comm;
	int obj_id_1 = MPI_OBJ_ID(MPI_Comm, &obj_1);
	void **args = assemble_args_list(6, &mem_attr_0, &count, &obj_id_0, &dest_rank, &my_tag, &obj_id_1);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(6, sizes, args, -1);
}
int MPI_Bsend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return c_MPI_Bsend_init(buf, count, datatype, dest, tag, comm, request); }
extern void f_mpi_bsend_init(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*datatype);
	MPI_Comm c_handle_1;
	c_handle_1 = PMPI_Comm_f2c(*comm);
	MPI_Request c_handle_2;
	c_handle_2 = PMPI_Request_f2c(*request);
	c_MPI_Bsend_init(buf, (*count), c_handle_0, (*dest), (*tag), c_handle_1, &c_handle_2);
	*request = PMPI_Request_c2f(c_handle_2);
}
extern void MPI_BSEND_INIT(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_bsend_init(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_bsend_init(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_bsend_init(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_bsend_init_(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_bsend_init(buf, count, datatype, dest, tag, comm, request, ierr);
}
extern void mpi_bsend_init__(const void* buf, int* count, MPI_Fint* datatype, int* dest, int* tag, MPI_Fint* comm, MPI_Fint* request, MPI_Fint *ierr) {
	f_mpi_bsend_init(buf, count, datatype, dest, tag, comm, request, ierr);
}
int c_MPI_Add_error_string(int errorcode, const char *string)
{
	PILGRIM_TRACING_1(int, MPI_Add_error_string, (errorcode, string));
	void **args = assemble_args_list(2, &errorcode, string);
	int sizes[] = { sizeof(int), strlen(string)+1 };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Add_error_string(int errorcode, const char *string) { return c_MPI_Add_error_string(errorcode, string); }
extern void f_mpi_add_error_string(int* errorcode, const char* string, MPI_Fint *ierr) {
	c_MPI_Add_error_string((*errorcode), string);
}
extern void MPI_ADD_ERROR_STRING(int* errorcode, const char* string, MPI_Fint *ierr) {
	f_mpi_add_error_string(errorcode, string, ierr);
}
extern void mpi_add_error_string(int* errorcode, const char* string, MPI_Fint *ierr) {
	f_mpi_add_error_string(errorcode, string, ierr);
}
extern void mpi_add_error_string_(int* errorcode, const char* string, MPI_Fint *ierr) {
	f_mpi_add_error_string(errorcode, string, ierr);
}
extern void mpi_add_error_string__(int* errorcode, const char* string, MPI_Fint *ierr) {
	f_mpi_add_error_string(errorcode, string, ierr);
}
int c_MPI_Accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win)
{
	PILGRIM_TRACING_1(int, MPI_Accumulate, (origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win));
	MemPtrAttr mem_attr_0;
	addr2id(origin_addr, &mem_attr_0);
	MPI_Datatype obj_0 = origin_datatype;
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, &obj_0);
	MPI_Datatype obj_1 = target_datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	MPI_Op obj_2 = op;
	int obj_id_2 = MPI_OBJ_ID(MPI_Op, &obj_2);
	MPI_Win obj_3 = win;
	int obj_id_3 = MPI_OBJ_ID(MPI_Win, &obj_3);
	void **args = assemble_args_list(9, &mem_attr_0, &origin_count, &obj_id_0, &target_rank, &target_disp, &target_count, &obj_id_1, &obj_id_2, &obj_id_3);
	int sizes[] = { sizeof(MemPtrAttr), sizeof(int), sizeof(int), sizeof(int), sizeof(MPI_Aint), sizeof(int), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(9, sizes, args, -1);
}
int MPI_Accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) { return c_MPI_Accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win); }
extern void f_mpi_accumulate(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint *ierr) {
	MPI_Datatype c_handle_0;
	c_handle_0 = PMPI_Type_f2c(*origin_datatype);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*target_datatype);
	MPI_Op c_handle_2;
	c_handle_2 = PMPI_Op_f2c(*op);
	MPI_Win c_handle_3;
	c_handle_3 = PMPI_Win_f2c(*win);
	c_MPI_Accumulate(origin_addr, (*origin_count), c_handle_0, (*target_rank), target_disp, (*target_count), c_handle_1, c_handle_2, c_handle_3);
}
extern void MPI_ACCUMULATE(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, ierr);
}
extern void mpi_accumulate(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, ierr);
}
extern void mpi_accumulate_(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, ierr);
}
extern void mpi_accumulate__(const void* origin_addr, int* origin_count, MPI_Fint* origin_datatype, int* target_rank, MPI_Aint target_disp, int* target_count, MPI_Fint* target_datatype, MPI_Fint* op, MPI_Fint* win, MPI_Fint *ierr) {
	f_mpi_accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, ierr);
}
int c_MPI_T_category_get_num(int *num_cat)
{
	PILGRIM_TRACING_1(int, MPI_T_category_get_num, (num_cat));
	void **args = assemble_args_list(1, num_cat);
	int sizes[] = { 1*sizeof(int) };
	PILGRIM_TRACING_2(1, sizes, args, -1);
}
int MPI_T_category_get_num(int *num_cat) { return c_MPI_T_category_get_num(num_cat); }
int c_MPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler)
{
	PILGRIM_TRACING_1(int, MPI_Comm_set_errhandler, (comm, errhandler));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	MPI_Errhandler obj_1 = errhandler;
	int obj_id_1 = MPI_OBJ_ID(MPI_Errhandler, &obj_1);
	void **args = assemble_args_list(2, &obj_id_0, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(2, sizes, args, -1);
}
int MPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler) { return c_MPI_Comm_set_errhandler(comm, errhandler); }
extern void f_mpi_comm_set_errhandler(MPI_Fint* comm, MPI_Fint* errhandler, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	MPI_Errhandler c_handle_1;
	c_handle_1 = PMPI_Errhandler_f2c(*errhandler);
	c_MPI_Comm_set_errhandler(c_handle_0, c_handle_1);
	*comm = PMPI_Comm_c2f(c_handle_0);
}
extern void MPI_COMM_SET_ERRHANDLER(MPI_Fint* comm, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_comm_set_errhandler(comm, errhandler, ierr);
}
extern void mpi_comm_set_errhandler(MPI_Fint* comm, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_comm_set_errhandler(comm, errhandler, ierr);
}
extern void mpi_comm_set_errhandler_(MPI_Fint* comm, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_comm_set_errhandler(comm, errhandler, ierr);
}
extern void mpi_comm_set_errhandler__(MPI_Fint* comm, MPI_Fint* errhandler, MPI_Fint *ierr) {
	f_mpi_comm_set_errhandler(comm, errhandler, ierr);
}
int c_MPI_File_write_ordered_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype)
{
	PILGRIM_TRACING_1(int, MPI_File_write_ordered_begin, (fh, buf, count, datatype));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	MPI_Datatype obj_1 = datatype;
	int obj_id_1 = MPI_OBJ_ID(MPI_Datatype, &obj_1);
	void **args = assemble_args_list(4, &obj_id_0, &mem_attr_0, &count, &obj_id_1);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int), sizeof(int) };
	PILGRIM_TRACING_2(4, sizes, args, -1);
}
int MPI_File_write_ordered_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype) { return c_MPI_File_write_ordered_begin(fh, buf, count, datatype); }
extern void f_mpi_file_write_ordered_begin(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Datatype c_handle_1;
	c_handle_1 = PMPI_Type_f2c(*datatype);
	c_MPI_File_write_ordered_begin(c_handle_0, buf, (*count), c_handle_1);
	*fh = PMPI_File_c2f(c_handle_0);
}
extern void MPI_FILE_WRITE_ORDERED_BEGIN(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_write_ordered_begin(fh, buf, count, datatype, ierr);
}
extern void mpi_file_write_ordered_begin(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_write_ordered_begin(fh, buf, count, datatype, ierr);
}
extern void mpi_file_write_ordered_begin_(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_write_ordered_begin(fh, buf, count, datatype, ierr);
}
extern void mpi_file_write_ordered_begin__(MPI_Fint* fh, const void* buf, int* count, MPI_Fint* datatype, MPI_Fint *ierr) {
	f_mpi_file_write_ordered_begin(fh, buf, count, datatype, ierr);
}
int c_MPI_File_write_ordered_end(MPI_File fh, const void *buf, MPI_Status *status)
{
	PILGRIM_TRACING_1(int, MPI_File_write_ordered_end, (fh, buf, status));
	MPI_File obj_0 = fh;
	int obj_id_0 = MPI_OBJ_ID(MPI_File, &obj_0);
	MemPtrAttr mem_attr_0;
	addr2id(buf, &mem_attr_0);
	int status_arg[2] = {0};
	void **args = assemble_args_list(3, &obj_id_0, &mem_attr_0, status_arg);
	int sizes[] = { sizeof(int), sizeof(MemPtrAttr), sizeof(int)*2 };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_File_write_ordered_end(MPI_File fh, const void *buf, MPI_Status *status) { return c_MPI_File_write_ordered_end(fh, buf, status); }
extern void f_mpi_file_write_ordered_end(MPI_Fint* fh, const void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	MPI_File c_handle_0;
	c_handle_0 = PMPI_File_f2c(*fh);
	MPI_Status c_handle_1;
	PMPI_Status_f2c(status, &c_handle_1);
	c_MPI_File_write_ordered_end(c_handle_0, buf, &c_handle_1);
	*fh = PMPI_File_c2f(c_handle_0);
	PMPI_Status_c2f(&c_handle_1, status);
}
extern void MPI_FILE_WRITE_ORDERED_END(MPI_Fint* fh, const void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_ordered_end(fh, buf, status, ierr);
}
extern void mpi_file_write_ordered_end(MPI_Fint* fh, const void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_ordered_end(fh, buf, status, ierr);
}
extern void mpi_file_write_ordered_end_(MPI_Fint* fh, const void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_ordered_end(fh, buf, status, ierr);
}
extern void mpi_file_write_ordered_end__(MPI_Fint* fh, const void* buf, MPI_Fint* status, MPI_Fint *ierr) {
	f_mpi_file_write_ordered_end(fh, buf, status, ierr);
}
int c_MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges)
{
	PILGRIM_TRACING_1(int, MPI_Graphdims_get, (comm, nnodes, nedges));
	MPI_Comm obj_0 = comm;
	int obj_id_0 = MPI_OBJ_ID(MPI_Comm, &obj_0);
	void **args = assemble_args_list(3, &obj_id_0, nnodes, nedges);
	int sizes[] = { sizeof(int), 1*sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(3, sizes, args, -1);
}
int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges) { return c_MPI_Graphdims_get(comm, nnodes, nedges); }
extern void f_mpi_graphdims_get(MPI_Fint* comm, int* nnodes, int* nedges, MPI_Fint *ierr) {
	MPI_Comm c_handle_0;
	c_handle_0 = PMPI_Comm_f2c(*comm);
	c_MPI_Graphdims_get(c_handle_0, nnodes, nedges);
}
extern void MPI_GRAPHDIMS_GET(MPI_Fint* comm, int* nnodes, int* nedges, MPI_Fint *ierr) {
	f_mpi_graphdims_get(comm, nnodes, nedges, ierr);
}
extern void mpi_graphdims_get(MPI_Fint* comm, int* nnodes, int* nedges, MPI_Fint *ierr) {
	f_mpi_graphdims_get(comm, nnodes, nedges, ierr);
}
extern void mpi_graphdims_get_(MPI_Fint* comm, int* nnodes, int* nedges, MPI_Fint *ierr) {
	f_mpi_graphdims_get(comm, nnodes, nedges, ierr);
}
extern void mpi_graphdims_get__(MPI_Fint* comm, int* nnodes, int* nedges, MPI_Fint *ierr) {
	f_mpi_graphdims_get(comm, nnodes, nedges, ierr);
}
int c_MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *var_class, MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind, int *readonly, int *continuous, int *atomic)
{
	PILGRIM_TRACING_1(int, MPI_T_pvar_get_info, (pvar_index, name, name_len, verbosity, var_class, datatype, enumtype, desc, desc_len, bind, readonly, continuous, atomic));
	int obj_id_0 = MPI_OBJ_ID(MPI_Datatype, datatype);
	void **args = assemble_args_list(13, &pvar_index, name, name_len, verbosity, var_class, &obj_id_0, enumtype, desc, desc_len, bind, readonly, continuous, atomic);
	int sizes[] = { sizeof(int), strlen(name)+1, 1*sizeof(int), 1*sizeof(int), 1*sizeof(int), sizeof(int), 1*sizeof(MPI_T_enum), strlen(desc)+1, 1*sizeof(int), 1*sizeof(int), 1*sizeof(int), 1*sizeof(int), 1*sizeof(int) };
	PILGRIM_TRACING_2(13, sizes, args, -1);
}
int MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *var_class, MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind, int *readonly, int *continuous, int *atomic) { return c_MPI_T_pvar_get_info(pvar_index, name, name_len, verbosity, var_class, datatype, enumtype, desc, desc_len, bind, readonly, continuous, atomic); }
