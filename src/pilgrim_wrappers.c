#include <mpi.h>
#include "pilgrim.h"
int MPI_Send(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
	char **args = assemble_args_list(6, ptoa(buf), itoa(count), ptoa(&datatype), itoa(dest), itoa(tag), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Send, PMPI_Send(buf, count, datatype, dest, tag, comm), 6, args);
}
int MPI_Recv(void* buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status)
{
	char **args = assemble_args_list(7, ptoa(buf), itoa(count), ptoa(&datatype), itoa(source), itoa(tag), ptoa(&comm), ptoa(status));
	PILGRIM_TRACING(int, MPI_Recv, PMPI_Recv(buf, count, datatype, source, tag, comm, status), 7, args);
}
int MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype, int *count)
{
	char **args = assemble_args_list(3, ptoa(status), ptoa(&datatype), ptoa(count));
	PILGRIM_TRACING(int, MPI_Get_count, PMPI_Get_count(status, datatype, count), 3, args);
}
int MPI_Bsend(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
	char **args = assemble_args_list(6, ptoa(buf), itoa(count), ptoa(&datatype), itoa(dest), itoa(tag), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Bsend, PMPI_Bsend(buf, count, datatype, dest, tag, comm), 6, args);
}
int MPI_Ssend(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
	char **args = assemble_args_list(6, ptoa(buf), itoa(count), ptoa(&datatype), itoa(dest), itoa(tag), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Ssend, PMPI_Ssend(buf, count, datatype, dest, tag, comm), 6, args);
}
int MPI_Rsend(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
	char **args = assemble_args_list(6, ptoa(buf), itoa(count), ptoa(&datatype), itoa(dest), itoa(tag), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Rsend, PMPI_Rsend(buf, count, datatype, dest, tag, comm), 6, args);
}
int MPI_Buffer_attach(void* buffer, int size)
{
	char **args = assemble_args_list(2, ptoa(buffer), itoa(size));
	PILGRIM_TRACING(int, MPI_Buffer_attach, PMPI_Buffer_attach(buffer, size), 2, args);
}
int MPI_Buffer_detach(void* buffer_addr, int* size)
{
	char **args = assemble_args_list(2, ptoa(buffer_addr), ptoa(size));
	PILGRIM_TRACING(int, MPI_Buffer_detach, PMPI_Buffer_detach(buffer_addr, size), 2, args);
}
int MPI_Isend(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(7, ptoa(buf), itoa(count), ptoa(&datatype), itoa(dest), itoa(tag), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Isend, PMPI_Isend(buf, count, datatype, dest, tag, comm, request), 7, args);
}
int MPI_Ibsend(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(7, ptoa(buf), itoa(count), ptoa(&datatype), itoa(dest), itoa(tag), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Ibsend, PMPI_Ibsend(buf, count, datatype, dest, tag, comm, request), 7, args);
}
int MPI_Issend(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(7, ptoa(buf), itoa(count), ptoa(&datatype), itoa(dest), itoa(tag), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Issend, PMPI_Issend(buf, count, datatype, dest, tag, comm, request), 7, args);
}
int MPI_Irsend(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(7, ptoa(buf), itoa(count), ptoa(&datatype), itoa(dest), itoa(tag), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Irsend, PMPI_Irsend(buf, count, datatype, dest, tag, comm, request), 7, args);
}
int MPI_Irecv(void* buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(7, ptoa(buf), itoa(count), ptoa(&datatype), itoa(source), itoa(tag), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Irecv, PMPI_Irecv(buf, count, datatype, source, tag, comm, request), 7, args);
}
int MPI_Wait(MPI_Request *request, MPI_Status *status)
{
	char **args = assemble_args_list(2, ptoa(request), ptoa(status));
	PILGRIM_TRACING(int, MPI_Wait, PMPI_Wait(request, status), 2, args);
}
int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status)
{
	char **args = assemble_args_list(3, ptoa(request), ptoa(flag), ptoa(status));
	PILGRIM_TRACING(int, MPI_Test, PMPI_Test(request, flag, status), 3, args);
}
int MPI_Request_free(MPI_Request *request)
{
	char **args = assemble_args_list(1, ptoa(request));
	PILGRIM_TRACING(int, MPI_Request_free, PMPI_Request_free(request), 1, args);
}
int MPI_Waitany(int count, MPI_Request array_of_requests[], int *index, MPI_Status *status)
{
	char **args = assemble_args_list(4, itoa(count), ptoa(array_of_requests), ptoa(index), ptoa(status));
	PILGRIM_TRACING(int, MPI_Waitany, PMPI_Waitany(count, array_of_requests, index, status), 4, args);
}
int MPI_Testany(int count, MPI_Request array_of_requests[], int *index, int *flag, MPI_Status *status)
{
	char **args = assemble_args_list(5, itoa(count), ptoa(array_of_requests), ptoa(index), ptoa(flag), ptoa(status));
	PILGRIM_TRACING(int, MPI_Testany, PMPI_Testany(count, array_of_requests, index, flag, status), 5, args);
}
int MPI_Waitall(int count, MPI_Request array_of_requests[], MPI_Status array_of_statuses[])
{
	char **args = assemble_args_list(3, itoa(count), ptoa(array_of_requests), ptoa(array_of_statuses));
	PILGRIM_TRACING(int, MPI_Waitall, PMPI_Waitall(count, array_of_requests, array_of_statuses), 3, args);
}
int MPI_Testall(int count, MPI_Request array_of_requests[], int *flag, MPI_Status array_of_statuses[])
{
	char **args = assemble_args_list(4, itoa(count), ptoa(array_of_requests), ptoa(flag), ptoa(array_of_statuses));
	PILGRIM_TRACING(int, MPI_Testall, PMPI_Testall(count, array_of_requests, flag, array_of_statuses), 4, args);
}
int MPI_Waitsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status array_of_statuses[])
{
	char **args = assemble_args_list(5, itoa(incount), ptoa(array_of_requests), ptoa(outcount), ptoa(array_of_indices), ptoa(array_of_statuses));
	PILGRIM_TRACING(int, MPI_Waitsome, PMPI_Waitsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses), 5, args);
}
int MPI_Testsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status array_of_statuses[])
{
	char **args = assemble_args_list(5, itoa(incount), ptoa(array_of_requests), ptoa(outcount), ptoa(array_of_indices), ptoa(array_of_statuses));
	PILGRIM_TRACING(int, MPI_Testsome, PMPI_Testsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses), 5, args);
}
int MPI_Request_get_status(MPI_Request request, int *flag, MPI_Status *status)
{
	char **args = assemble_args_list(3, ptoa(&request), ptoa(flag), ptoa(status));
	PILGRIM_TRACING(int, MPI_Request_get_status, PMPI_Request_get_status(request, flag, status), 3, args);
}
int MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag, MPI_Status *status)
{
	char **args = assemble_args_list(5, itoa(source), itoa(tag), ptoa(&comm), ptoa(flag), ptoa(status));
	PILGRIM_TRACING(int, MPI_Iprobe, PMPI_Iprobe(source, tag, comm, flag, status), 5, args);
}
int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status)
{
	char **args = assemble_args_list(4, itoa(source), itoa(tag), ptoa(&comm), ptoa(status));
	PILGRIM_TRACING(int, MPI_Probe, PMPI_Probe(source, tag, comm, status), 4, args);
}
int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag, MPI_Message *message, MPI_Status *status)
{
	char **args = assemble_args_list(6, itoa(source), itoa(tag), ptoa(&comm), ptoa(flag), ptoa(message), ptoa(status));
	PILGRIM_TRACING(int, MPI_Improbe, PMPI_Improbe(source, tag, comm, flag, message, status), 6, args);
}
int MPI_Mprobe(int source, int tag, MPI_Comm comm, MPI_Message *message, MPI_Status *status)
{
	char **args = assemble_args_list(5, itoa(source), itoa(tag), ptoa(&comm), ptoa(message), ptoa(status));
	PILGRIM_TRACING(int, MPI_Mprobe, PMPI_Mprobe(source, tag, comm, message, status), 5, args);
}
int MPI_Mrecv(void* buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Status *status)
{
	char **args = assemble_args_list(5, ptoa(buf), itoa(count), ptoa(&datatype), ptoa(message), ptoa(status));
	PILGRIM_TRACING(int, MPI_Mrecv, PMPI_Mrecv(buf, count, datatype, message, status), 5, args);
}
int MPI_Imrecv(void* buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Request *request)
{
	char **args = assemble_args_list(5, ptoa(buf), itoa(count), ptoa(&datatype), ptoa(message), ptoa(request));
	PILGRIM_TRACING(int, MPI_Imrecv, PMPI_Imrecv(buf, count, datatype, message, request), 5, args);
}
int MPI_Cancel(MPI_Request *request)
{
	char **args = assemble_args_list(1, ptoa(request));
	PILGRIM_TRACING(int, MPI_Cancel, PMPI_Cancel(request), 1, args);
}
int MPI_Test_cancelled(const MPI_Status *status, int *flag)
{
	char **args = assemble_args_list(2, ptoa(status), ptoa(flag));
	PILGRIM_TRACING(int, MPI_Test_cancelled, PMPI_Test_cancelled(status, flag), 2, args);
}
int MPI_Send_init(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(7, ptoa(buf), itoa(count), ptoa(&datatype), itoa(dest), itoa(tag), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Send_init, PMPI_Send_init(buf, count, datatype, dest, tag, comm, request), 7, args);
}
int MPI_Bsend_init(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(7, ptoa(buf), itoa(count), ptoa(&datatype), itoa(dest), itoa(tag), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Bsend_init, PMPI_Bsend_init(buf, count, datatype, dest, tag, comm, request), 7, args);
}
int MPI_Ssend_init(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(7, ptoa(buf), itoa(count), ptoa(&datatype), itoa(dest), itoa(tag), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Ssend_init, PMPI_Ssend_init(buf, count, datatype, dest, tag, comm, request), 7, args);
}
int MPI_Rsend_init(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(7, ptoa(buf), itoa(count), ptoa(&datatype), itoa(dest), itoa(tag), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Rsend_init, PMPI_Rsend_init(buf, count, datatype, dest, tag, comm, request), 7, args);
}
int MPI_Recv_init(void* buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(7, ptoa(buf), itoa(count), ptoa(&datatype), itoa(source), itoa(tag), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Recv_init, PMPI_Recv_init(buf, count, datatype, source, tag, comm, request), 7, args);
}
int MPI_Start(MPI_Request *request)
{
	char **args = assemble_args_list(1, ptoa(request));
	PILGRIM_TRACING(int, MPI_Start, PMPI_Start(request), 1, args);
}
int MPI_Startall(int count, MPI_Request array_of_requests[])
{
	char **args = assemble_args_list(2, itoa(count), ptoa(array_of_requests));
	PILGRIM_TRACING(int, MPI_Startall, PMPI_Startall(count, array_of_requests), 2, args);
}
int MPI_Sendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status)
{
	char **args = assemble_args_list(12, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), itoa(dest), itoa(sendtag), ptoa(recvbuf), itoa(recvcount), ptoa(&recvtype), itoa(source), itoa(recvtag), ptoa(&comm), ptoa(status));
	PILGRIM_TRACING(int, MPI_Sendrecv, PMPI_Sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status), 12, args);
}
int MPI_Sendrecv_replace(void* buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status *status)
{
	char **args = assemble_args_list(9, ptoa(buf), itoa(count), ptoa(&datatype), itoa(dest), itoa(sendtag), itoa(source), itoa(recvtag), ptoa(&comm), ptoa(status));
	PILGRIM_TRACING(int, MPI_Sendrecv_replace, PMPI_Sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status), 9, args);
}
int MPI_Type_contiguous(int count, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	char **args = assemble_args_list(3, itoa(count), ptoa(&oldtype), ptoa(newtype));
	PILGRIM_TRACING(int, MPI_Type_contiguous, PMPI_Type_contiguous(count, oldtype, newtype), 3, args);
}
int MPI_Type_vector(int count, int blocklength, int stride, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	char **args = assemble_args_list(5, itoa(count), itoa(blocklength), itoa(stride), ptoa(&oldtype), ptoa(newtype));
	PILGRIM_TRACING(int, MPI_Type_vector, PMPI_Type_vector(count, blocklength, stride, oldtype, newtype), 5, args);
}
int MPI_Type_create_hvector(int count, int blocklength, MPI_Aint stride, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	char **args = assemble_args_list(5, itoa(count), itoa(blocklength), ptoa(&stride), ptoa(&oldtype), ptoa(newtype));
	PILGRIM_TRACING(int, MPI_Type_create_hvector, PMPI_Type_create_hvector(count, blocklength, stride, oldtype, newtype), 5, args);
}
int MPI_Type_indexed(int count, const int array_of_blocklengths[], const int array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	char **args = assemble_args_list(5, itoa(count), ptoa(array_of_blocklengths), ptoa(array_of_displacements), ptoa(&oldtype), ptoa(newtype));
	PILGRIM_TRACING(int, MPI_Type_indexed, PMPI_Type_indexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype), 5, args);
}
int MPI_Type_create_hindexed(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	char **args = assemble_args_list(5, itoa(count), ptoa(array_of_blocklengths), ptoa(array_of_displacements), ptoa(&oldtype), ptoa(newtype));
	PILGRIM_TRACING(int, MPI_Type_create_hindexed, PMPI_Type_create_hindexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype), 5, args);
}
int MPI_Type_create_indexed_block(int count, int blocklength, const int array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	char **args = assemble_args_list(5, itoa(count), itoa(blocklength), ptoa(array_of_displacements), ptoa(&oldtype), ptoa(newtype));
	PILGRIM_TRACING(int, MPI_Type_create_indexed_block, PMPI_Type_create_indexed_block(count, blocklength, array_of_displacements, oldtype, newtype), 5, args);
}
int MPI_Type_create_hindexed_block(int count, int blocklength, const MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	char **args = assemble_args_list(5, itoa(count), itoa(blocklength), ptoa(array_of_displacements), ptoa(&oldtype), ptoa(newtype));
	PILGRIM_TRACING(int, MPI_Type_create_hindexed_block, PMPI_Type_create_hindexed_block(count, blocklength, array_of_displacements, oldtype, newtype), 5, args);
}
int MPI_Type_create_struct(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], const MPI_Datatype array_of_types[], MPI_Datatype *newtype)
{
	char **args = assemble_args_list(5, itoa(count), ptoa(array_of_blocklengths), ptoa(array_of_displacements), ptoa(array_of_types), ptoa(newtype));
	PILGRIM_TRACING(int, MPI_Type_create_struct, PMPI_Type_create_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype), 5, args);
}
int MPI_Type_create_subarray(int ndims, const int array_of_sizes[], const int array_of_subsizes[], const int array_of_starts[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	char **args = assemble_args_list(7, itoa(ndims), ptoa(array_of_sizes), ptoa(array_of_subsizes), ptoa(array_of_starts), itoa(order), ptoa(&oldtype), ptoa(newtype));
	PILGRIM_TRACING(int, MPI_Type_create_subarray, PMPI_Type_create_subarray(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype), 7, args);
}
int MPI_Type_create_darray(int size, int rank, int ndims, const int array_of_gsizes[], const int array_of_distribs[], const int array_of_dargs[], const int array_of_psizes[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	char **args = assemble_args_list(10, itoa(size), itoa(rank), itoa(ndims), ptoa(array_of_gsizes), ptoa(array_of_distribs), ptoa(array_of_dargs), ptoa(array_of_psizes), itoa(order), ptoa(&oldtype), ptoa(newtype));
	PILGRIM_TRACING(int, MPI_Type_create_darray, PMPI_Type_create_darray(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype), 10, args);
}
int MPI_Get_address(const void *location, MPI_Aint *address)
{
	char **args = assemble_args_list(2, ptoa(location), ptoa(address));
	PILGRIM_TRACING(int, MPI_Get_address, PMPI_Get_address(location, address), 2, args);
}
MPI_Aint MPI_Aint_add(MPI_Aint base, MPI_Aint disp)
{
	char **args = assemble_args_list(2, ptoa(&base), ptoa(&disp));
	PILGRIM_TRACING(MPI_Aint, MPI_Aint_add, PMPI_Aint_add(base, disp), 2, args);
}
MPI_Aint MPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2)
{
	char **args = assemble_args_list(2, ptoa(&addr1), ptoa(&addr2));
	PILGRIM_TRACING(MPI_Aint, MPI_Aint_diff, PMPI_Aint_diff(addr1, addr2), 2, args);
}
int MPI_Type_size(MPI_Datatype datatype, int *size)
{
	char **args = assemble_args_list(2, ptoa(&datatype), ptoa(size));
	PILGRIM_TRACING(int, MPI_Type_size, PMPI_Type_size(datatype, size), 2, args);
}
int MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size)
{
	char **args = assemble_args_list(2, ptoa(&datatype), ptoa(size));
	PILGRIM_TRACING(int, MPI_Type_size_x, PMPI_Type_size_x(datatype, size), 2, args);
}
int MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb, MPI_Aint *extent)
{
	char **args = assemble_args_list(3, ptoa(&datatype), ptoa(lb), ptoa(extent));
	PILGRIM_TRACING(int, MPI_Type_get_extent, PMPI_Type_get_extent(datatype, lb, extent), 3, args);
}
int MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb, MPI_Count *extent)
{
	char **args = assemble_args_list(3, ptoa(&datatype), ptoa(lb), ptoa(extent));
	PILGRIM_TRACING(int, MPI_Type_get_extent_x, PMPI_Type_get_extent_x(datatype, lb, extent), 3, args);
}
int MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent, MPI_Datatype *newtype)
{
	char **args = assemble_args_list(4, ptoa(&oldtype), ptoa(&lb), ptoa(&extent), ptoa(newtype));
	PILGRIM_TRACING(int, MPI_Type_create_resized, PMPI_Type_create_resized(oldtype, lb, extent, newtype), 4, args);
}
int MPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb, MPI_Aint *true_extent)
{
	char **args = assemble_args_list(3, ptoa(&datatype), ptoa(true_lb), ptoa(true_extent));
	PILGRIM_TRACING(int, MPI_Type_get_true_extent, PMPI_Type_get_true_extent(datatype, true_lb, true_extent), 3, args);
}
int MPI_Type_get_true_extent_x(MPI_Datatype datatype, MPI_Count *true_lb, MPI_Count *true_extent)
{
	char **args = assemble_args_list(3, ptoa(&datatype), ptoa(true_lb), ptoa(true_extent));
	PILGRIM_TRACING(int, MPI_Type_get_true_extent_x, PMPI_Type_get_true_extent_x(datatype, true_lb, true_extent), 3, args);
}
int MPI_Type_commit(MPI_Datatype *datatype)
{
	char **args = assemble_args_list(1, ptoa(datatype));
	PILGRIM_TRACING(int, MPI_Type_commit, PMPI_Type_commit(datatype), 1, args);
}
int MPI_Type_free(MPI_Datatype *datatype)
{
	char **args = assemble_args_list(1, ptoa(datatype));
	PILGRIM_TRACING(int, MPI_Type_free, PMPI_Type_free(datatype), 1, args);
}
int MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	char **args = assemble_args_list(2, ptoa(&oldtype), ptoa(newtype));
	PILGRIM_TRACING(int, MPI_Type_dup, PMPI_Type_dup(oldtype, newtype), 2, args);
}
int MPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype, int *count)
{
	char **args = assemble_args_list(3, ptoa(status), ptoa(&datatype), ptoa(count));
	PILGRIM_TRACING(int, MPI_Get_elements, PMPI_Get_elements(status, datatype, count), 3, args);
}
int MPI_Get_elements_x(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count)
{
	char **args = assemble_args_list(3, ptoa(status), ptoa(&datatype), ptoa(count));
	PILGRIM_TRACING(int, MPI_Get_elements_x, PMPI_Get_elements_x(status, datatype, count), 3, args);
}
int MPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner)
{
	char **args = assemble_args_list(5, ptoa(&datatype), ptoa(num_integers), ptoa(num_addresses), ptoa(num_datatypes), ptoa(combiner));
	PILGRIM_TRACING(int, MPI_Type_get_envelope, PMPI_Type_get_envelope(datatype, num_integers, num_addresses, num_datatypes, combiner), 5, args);
}
int MPI_Type_get_contents(MPI_Datatype datatype, int max_integers, int max_addresses, int max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Datatype array_of_datatypes[])
{
	char **args = assemble_args_list(7, ptoa(&datatype), itoa(max_integers), itoa(max_addresses), itoa(max_datatypes), ptoa(array_of_integers), ptoa(array_of_addresses), ptoa(array_of_datatypes));
	PILGRIM_TRACING(int, MPI_Type_get_contents, PMPI_Type_get_contents(datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes), 7, args);
}
int MPI_Pack(const void* inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize, int *position, MPI_Comm comm)
{
	char **args = assemble_args_list(7, ptoa(inbuf), itoa(incount), ptoa(&datatype), ptoa(outbuf), itoa(outsize), ptoa(position), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Pack, PMPI_Pack(inbuf, incount, datatype, outbuf, outsize, position, comm), 7, args);
}
int MPI_Unpack(const void* inbuf, int insize, int *position, void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm)
{
	char **args = assemble_args_list(7, ptoa(inbuf), itoa(insize), ptoa(position), ptoa(outbuf), itoa(outcount), ptoa(&datatype), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Unpack, PMPI_Unpack(inbuf, insize, position, outbuf, outcount, datatype, comm), 7, args);
}
int MPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm, int *size)
{
	char **args = assemble_args_list(4, itoa(incount), ptoa(&datatype), ptoa(&comm), ptoa(size));
	PILGRIM_TRACING(int, MPI_Pack_size, PMPI_Pack_size(incount, datatype, comm, size), 4, args);
}
int MPI_Pack_external(const char datarep[], const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, MPI_Aint outsize, MPI_Aint *position)
{
	char **args = assemble_args_list(7, ptoa(datarep), ptoa(inbuf), itoa(incount), ptoa(&datatype), ptoa(outbuf), ptoa(&outsize), ptoa(position));
	PILGRIM_TRACING(int, MPI_Pack_external, PMPI_Pack_external(datarep, inbuf, incount, datatype, outbuf, outsize, position), 7, args);
}
int MPI_Unpack_external(const char datarep[], const void *inbuf, MPI_Aint insize, MPI_Aint *position, void *outbuf, int outcount, MPI_Datatype datatype)
{
	char **args = assemble_args_list(7, ptoa(datarep), ptoa(inbuf), ptoa(&insize), ptoa(position), ptoa(outbuf), itoa(outcount), ptoa(&datatype));
	PILGRIM_TRACING(int, MPI_Unpack_external, PMPI_Unpack_external(datarep, inbuf, insize, position, outbuf, outcount, datatype), 7, args);
}
int MPI_Pack_external_size(const char datarep[], int incount, MPI_Datatype datatype, MPI_Aint *size)
{
	char **args = assemble_args_list(4, ptoa(datarep), itoa(incount), ptoa(&datatype), ptoa(size));
	PILGRIM_TRACING(int, MPI_Pack_external_size, PMPI_Pack_external_size(datarep, incount, datatype, size), 4, args);
}
int MPI_Barrier(MPI_Comm comm)
{
	char **args = assemble_args_list(1, ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Barrier, PMPI_Barrier(comm), 1, args);
}
int MPI_Bcast(void* buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm)
{
	char **args = assemble_args_list(5, ptoa(buffer), itoa(count), ptoa(&datatype), itoa(root), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Bcast, PMPI_Bcast(buffer, count, datatype, root, comm), 5, args);
}
int MPI_Gather(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
	char **args = assemble_args_list(8, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), itoa(recvcount), ptoa(&recvtype), itoa(root), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Gather, PMPI_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm), 8, args);
}
int MPI_Gatherv(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm)
{
	char **args = assemble_args_list(9, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), ptoa(recvcounts), ptoa(displs), ptoa(&recvtype), itoa(root), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Gatherv, PMPI_Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm), 9, args);
}
int MPI_Scatter(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
	char **args = assemble_args_list(8, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), itoa(recvcount), ptoa(&recvtype), itoa(root), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Scatter, PMPI_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm), 8, args);
}
int MPI_Scatterv(const void* sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
	char **args = assemble_args_list(9, ptoa(sendbuf), ptoa(sendcounts), ptoa(displs), ptoa(&sendtype), ptoa(recvbuf), itoa(recvcount), ptoa(&recvtype), itoa(root), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Scatterv, PMPI_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm), 9, args);
}
int MPI_Allgather(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
	char **args = assemble_args_list(7, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), itoa(recvcount), ptoa(&recvtype), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Allgather, PMPI_Allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm), 7, args);
}
int MPI_Allgatherv(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm)
{
	char **args = assemble_args_list(8, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), ptoa(recvcounts), ptoa(displs), ptoa(&recvtype), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Allgatherv, PMPI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm), 8, args);
}
int MPI_Alltoall(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
	char **args = assemble_args_list(7, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), itoa(recvcount), ptoa(&recvtype), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Alltoall, PMPI_Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm), 7, args);
}
int MPI_Alltoallv(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm)
{
	char **args = assemble_args_list(9, ptoa(sendbuf), ptoa(sendcounts), ptoa(sdispls), ptoa(&sendtype), ptoa(recvbuf), ptoa(recvcounts), ptoa(rdispls), ptoa(&recvtype), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Alltoallv, PMPI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm), 9, args);
}
int MPI_Alltoallw(const void* sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void* recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm)
{
	char **args = assemble_args_list(9, ptoa(sendbuf), ptoa(sendcounts), ptoa(sdispls), ptoa(sendtypes), ptoa(recvbuf), ptoa(recvcounts), ptoa(rdispls), ptoa(recvtypes), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Alltoallw, PMPI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm), 9, args);
}
int MPI_Reduce(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm)
{
	char **args = assemble_args_list(7, ptoa(sendbuf), ptoa(recvbuf), itoa(count), ptoa(&datatype), ptoa(&op), itoa(root), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Reduce, PMPI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm), 7, args);
}
int MPI_Op_create(MPI_User_function* user_fn, int commute, MPI_Op* op)
{
	char **args = assemble_args_list(3, ptoa(user_fn), itoa(commute), ptoa(op));
	PILGRIM_TRACING(int, MPI_Op_create, PMPI_Op_create(user_fn, commute, op), 3, args);
}
int MPI_Op_free(MPI_Op *op)
{
	char **args = assemble_args_list(1, ptoa(op));
	PILGRIM_TRACING(int, MPI_Op_free, PMPI_Op_free(op), 1, args);
}
int MPI_Allreduce(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	char **args = assemble_args_list(6, ptoa(sendbuf), ptoa(recvbuf), itoa(count), ptoa(&datatype), ptoa(&op), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Allreduce, PMPI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm), 6, args);
}
int MPI_Reduce_local(const void* inbuf, void* inoutbuf, int count, MPI_Datatype datatype, MPI_Op op)
{
	char **args = assemble_args_list(5, ptoa(inbuf), ptoa(inoutbuf), itoa(count), ptoa(&datatype), ptoa(&op));
	PILGRIM_TRACING(int, MPI_Reduce_local, PMPI_Reduce_local(inbuf, inoutbuf, count, datatype, op), 5, args);
}
int MPI_Op_commutative(MPI_Op op, int *commute)
{
	char **args = assemble_args_list(2, ptoa(&op), ptoa(commute));
	PILGRIM_TRACING(int, MPI_Op_commutative, PMPI_Op_commutative(op, commute), 2, args);
}
int MPI_Reduce_scatter_block(const void* sendbuf, void* recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	char **args = assemble_args_list(6, ptoa(sendbuf), ptoa(recvbuf), itoa(recvcount), ptoa(&datatype), ptoa(&op), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Reduce_scatter_block, PMPI_Reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm), 6, args);
}
int MPI_Reduce_scatter(const void* sendbuf, void* recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	char **args = assemble_args_list(6, ptoa(sendbuf), ptoa(recvbuf), ptoa(recvcounts), ptoa(&datatype), ptoa(&op), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Reduce_scatter, PMPI_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm), 6, args);
}
int MPI_Scan(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	char **args = assemble_args_list(6, ptoa(sendbuf), ptoa(recvbuf), itoa(count), ptoa(&datatype), ptoa(&op), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Scan, PMPI_Scan(sendbuf, recvbuf, count, datatype, op, comm), 6, args);
}
int MPI_Exscan(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	char **args = assemble_args_list(6, ptoa(sendbuf), ptoa(recvbuf), itoa(count), ptoa(&datatype), ptoa(&op), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Exscan, PMPI_Exscan(sendbuf, recvbuf, count, datatype, op, comm), 6, args);
}
int MPI_Ibarrier(MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(2, ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Ibarrier, PMPI_Ibarrier(comm, request), 2, args);
}
int MPI_Ibcast(void* buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(6, ptoa(buffer), itoa(count), ptoa(&datatype), itoa(root), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Ibcast, PMPI_Ibcast(buffer, count, datatype, root, comm, request), 6, args);
}
int MPI_Igather(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(9, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), itoa(recvcount), ptoa(&recvtype), itoa(root), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Igather, PMPI_Igather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request), 9, args);
}
int MPI_Igatherv(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(10, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), ptoa(recvcounts), ptoa(displs), ptoa(&recvtype), itoa(root), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Igatherv, PMPI_Igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request), 10, args);
}
int MPI_Iscatter(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(9, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), itoa(recvcount), ptoa(&recvtype), itoa(root), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Iscatter, PMPI_Iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request), 9, args);
}
int MPI_Iscatterv(const void* sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(10, ptoa(sendbuf), ptoa(sendcounts), ptoa(displs), ptoa(&sendtype), ptoa(recvbuf), itoa(recvcount), ptoa(&recvtype), itoa(root), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Iscatterv, PMPI_Iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request), 10, args);
}
int MPI_Iallgather(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(8, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), itoa(recvcount), ptoa(&recvtype), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Iallgather, PMPI_Iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request), 8, args);
}
int MPI_Iallgatherv(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request* request)
{
	char **args = assemble_args_list(9, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), ptoa(recvcounts), ptoa(displs), ptoa(&recvtype), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Iallgatherv, PMPI_Iallgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request), 9, args);
}
int MPI_Ialltoall(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(8, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), itoa(recvcount), ptoa(&recvtype), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Ialltoall, PMPI_Ialltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request), 8, args);
}
int MPI_Ialltoallv(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(10, ptoa(sendbuf), ptoa(sendcounts), ptoa(sdispls), ptoa(&sendtype), ptoa(recvbuf), ptoa(recvcounts), ptoa(rdispls), ptoa(&recvtype), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Ialltoallv, PMPI_Ialltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request), 10, args);
}
int MPI_Ialltoallw(const void* sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void* recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(10, ptoa(sendbuf), ptoa(sendcounts), ptoa(sdispls), ptoa(sendtypes), ptoa(recvbuf), ptoa(recvcounts), ptoa(rdispls), ptoa(recvtypes), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Ialltoallw, PMPI_Ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request), 10, args);
}
int MPI_Ireduce(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(8, ptoa(sendbuf), ptoa(recvbuf), itoa(count), ptoa(&datatype), ptoa(&op), itoa(root), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Ireduce, PMPI_Ireduce(sendbuf, recvbuf, count, datatype, op, root, comm, request), 8, args);
}
int MPI_Iallreduce(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(7, ptoa(sendbuf), ptoa(recvbuf), itoa(count), ptoa(&datatype), ptoa(&op), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Iallreduce, PMPI_Iallreduce(sendbuf, recvbuf, count, datatype, op, comm, request), 7, args);
}
int MPI_Ireduce_scatter_block(const void* sendbuf, void* recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(7, ptoa(sendbuf), ptoa(recvbuf), itoa(recvcount), ptoa(&datatype), ptoa(&op), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Ireduce_scatter_block, PMPI_Ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, request), 7, args);
}
int MPI_Ireduce_scatter(const void* sendbuf, void* recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(7, ptoa(sendbuf), ptoa(recvbuf), ptoa(recvcounts), ptoa(&datatype), ptoa(&op), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Ireduce_scatter, PMPI_Ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, request), 7, args);
}
int MPI_Iscan(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(7, ptoa(sendbuf), ptoa(recvbuf), itoa(count), ptoa(&datatype), ptoa(&op), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Iscan, PMPI_Iscan(sendbuf, recvbuf, count, datatype, op, comm, request), 7, args);
}
int MPI_Iexscan(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(7, ptoa(sendbuf), ptoa(recvbuf), itoa(count), ptoa(&datatype), ptoa(&op), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Iexscan, PMPI_Iexscan(sendbuf, recvbuf, count, datatype, op, comm, request), 7, args);
}
int MPI_Group_size(MPI_Group group, int *size)
{
	char **args = assemble_args_list(2, ptoa(&group), ptoa(size));
	PILGRIM_TRACING(int, MPI_Group_size, PMPI_Group_size(group, size), 2, args);
}
int MPI_Group_rank(MPI_Group group, int *rank)
{
	char **args = assemble_args_list(2, ptoa(&group), ptoa(rank));
	PILGRIM_TRACING(int, MPI_Group_rank, PMPI_Group_rank(group, rank), 2, args);
}
int MPI_Group_translate_ranks(MPI_Group group1, int n, const int ranks1[], MPI_Group group2, int ranks2[])
{
	char **args = assemble_args_list(5, ptoa(&group1), itoa(n), ptoa(ranks1), ptoa(&group2), ptoa(ranks2));
	PILGRIM_TRACING(int, MPI_Group_translate_ranks, PMPI_Group_translate_ranks(group1, n, ranks1, group2, ranks2), 5, args);
}
int MPI_Group_compare(MPI_Group group1,MPI_Group group2, int *result)
{
	char **args = assemble_args_list(3, ptoa(&group1), ptoa(&group2), ptoa(result));
	PILGRIM_TRACING(int, MPI_Group_compare, PMPI_Group_compare(group1, group2, result), 3, args);
}
int MPI_Comm_group(MPI_Comm comm, MPI_Group *group)
{
	char **args = assemble_args_list(2, ptoa(&comm), ptoa(group));
	PILGRIM_TRACING(int, MPI_Comm_group, PMPI_Comm_group(comm, group), 2, args);
}
int MPI_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup)
{
	char **args = assemble_args_list(3, ptoa(&group1), ptoa(&group2), ptoa(newgroup));
	PILGRIM_TRACING(int, MPI_Group_union, PMPI_Group_union(group1, group2, newgroup), 3, args);
}
int MPI_Group_intersection(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup)
{
	char **args = assemble_args_list(3, ptoa(&group1), ptoa(&group2), ptoa(newgroup));
	PILGRIM_TRACING(int, MPI_Group_intersection, PMPI_Group_intersection(group1, group2, newgroup), 3, args);
}
int MPI_Group_difference(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup)
{
	char **args = assemble_args_list(3, ptoa(&group1), ptoa(&group2), ptoa(newgroup));
	PILGRIM_TRACING(int, MPI_Group_difference, PMPI_Group_difference(group1, group2, newgroup), 3, args);
}
int MPI_Group_incl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup)
{
	char **args = assemble_args_list(4, ptoa(&group), itoa(n), ptoa(ranks), ptoa(newgroup));
	PILGRIM_TRACING(int, MPI_Group_incl, PMPI_Group_incl(group, n, ranks, newgroup), 4, args);
}
int MPI_Group_excl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup)
{
	char **args = assemble_args_list(4, ptoa(&group), itoa(n), ptoa(ranks), ptoa(newgroup));
	PILGRIM_TRACING(int, MPI_Group_excl, PMPI_Group_excl(group, n, ranks, newgroup), 4, args);
}
int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup)
{
	char **args = assemble_args_list(4, ptoa(&group), itoa(n), ptoa(ranges), ptoa(newgroup));
	PILGRIM_TRACING(int, MPI_Group_range_incl, PMPI_Group_range_incl(group, n, ranges, newgroup), 4, args);
}
int MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup)
{
	char **args = assemble_args_list(4, ptoa(&group), itoa(n), ptoa(ranges), ptoa(newgroup));
	PILGRIM_TRACING(int, MPI_Group_range_excl, PMPI_Group_range_excl(group, n, ranges, newgroup), 4, args);
}
int MPI_Group_free(MPI_Group *group)
{
	char **args = assemble_args_list(1, ptoa(group));
	PILGRIM_TRACING(int, MPI_Group_free, PMPI_Group_free(group), 1, args);
}
int MPI_Comm_size(MPI_Comm comm, int *size)
{
	char **args = assemble_args_list(2, ptoa(&comm), ptoa(size));
	PILGRIM_TRACING(int, MPI_Comm_size, PMPI_Comm_size(comm, size), 2, args);
}
int MPI_Comm_rank(MPI_Comm comm, int *rank)
{
	char **args = assemble_args_list(2, ptoa(&comm), ptoa(rank));
	PILGRIM_TRACING(int, MPI_Comm_rank, PMPI_Comm_rank(comm, rank), 2, args);
}
int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result)
{
	char **args = assemble_args_list(3, ptoa(&comm1), ptoa(&comm2), ptoa(result));
	PILGRIM_TRACING(int, MPI_Comm_compare, PMPI_Comm_compare(comm1, comm2, result), 3, args);
}
int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm)
{
	char **args = assemble_args_list(2, ptoa(&comm), ptoa(newcomm));
	PILGRIM_TRACING(int, MPI_Comm_dup, PMPI_Comm_dup(comm, newcomm), 2, args);
}
int MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info, MPI_Comm *newcomm)
{
	char **args = assemble_args_list(3, ptoa(&comm), ptoa(&info), ptoa(newcomm));
	PILGRIM_TRACING(int, MPI_Comm_dup_with_info, PMPI_Comm_dup_with_info(comm, info, newcomm), 3, args);
}
int MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm, MPI_Request *request)
{
	char **args = assemble_args_list(3, ptoa(&comm), ptoa(newcomm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Comm_idup, PMPI_Comm_idup(comm, newcomm, request), 3, args);
}
int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm)
{
	char **args = assemble_args_list(3, ptoa(&comm), ptoa(&group), ptoa(newcomm));
	PILGRIM_TRACING(int, MPI_Comm_create, PMPI_Comm_create(comm, group, newcomm), 3, args);
}
int MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag, MPI_Comm *newcomm)
{
	char **args = assemble_args_list(4, ptoa(&comm), ptoa(&group), itoa(tag), ptoa(newcomm));
	PILGRIM_TRACING(int, MPI_Comm_create_group, PMPI_Comm_create_group(comm, group, tag, newcomm), 4, args);
}
int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm)
{
	char **args = assemble_args_list(4, ptoa(&comm), itoa(color), itoa(key), ptoa(newcomm));
	PILGRIM_TRACING(int, MPI_Comm_split, PMPI_Comm_split(comm, color, key, newcomm), 4, args);
}
int MPI_Comm_split_type(MPI_Comm comm, int split_type, int key, MPI_Info info, MPI_Comm *newcomm)
{
	char **args = assemble_args_list(5, ptoa(&comm), itoa(split_type), itoa(key), ptoa(&info), ptoa(newcomm));
	PILGRIM_TRACING(int, MPI_Comm_split_type, PMPI_Comm_split_type(comm, split_type, key, info, newcomm), 5, args);
}
int MPI_Comm_free(MPI_Comm *comm)
{
	char **args = assemble_args_list(1, ptoa(comm));
	PILGRIM_TRACING(int, MPI_Comm_free, PMPI_Comm_free(comm), 1, args);
}
int MPI_Comm_set_info(MPI_Comm comm, MPI_Info info)
{
	char **args = assemble_args_list(2, ptoa(&comm), ptoa(&info));
	PILGRIM_TRACING(int, MPI_Comm_set_info, PMPI_Comm_set_info(comm, info), 2, args);
}
int MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used)
{
	char **args = assemble_args_list(2, ptoa(&comm), ptoa(info_used));
	PILGRIM_TRACING(int, MPI_Comm_get_info, PMPI_Comm_get_info(comm, info_used), 2, args);
}
int MPI_Comm_test_inter(MPI_Comm comm, int *flag)
{
	char **args = assemble_args_list(2, ptoa(&comm), ptoa(flag));
	PILGRIM_TRACING(int, MPI_Comm_test_inter, PMPI_Comm_test_inter(comm, flag), 2, args);
}
int MPI_Comm_remote_size(MPI_Comm comm, int *size)
{
	char **args = assemble_args_list(2, ptoa(&comm), ptoa(size));
	PILGRIM_TRACING(int, MPI_Comm_remote_size, PMPI_Comm_remote_size(comm, size), 2, args);
}
int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group)
{
	char **args = assemble_args_list(2, ptoa(&comm), ptoa(group));
	PILGRIM_TRACING(int, MPI_Comm_remote_group, PMPI_Comm_remote_group(comm, group), 2, args);
}
int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader, MPI_Comm peer_comm, int remote_leader, int tag, MPI_Comm *newintercomm)
{
	char **args = assemble_args_list(6, ptoa(&local_comm), itoa(local_leader), ptoa(&peer_comm), itoa(remote_leader), itoa(tag), ptoa(newintercomm));
	PILGRIM_TRACING(int, MPI_Intercomm_create, PMPI_Intercomm_create(local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm), 6, args);
}
int MPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm)
{
	char **args = assemble_args_list(3, ptoa(&intercomm), itoa(high), ptoa(newintracomm));
	PILGRIM_TRACING(int, MPI_Intercomm_merge, PMPI_Intercomm_merge(intercomm, high, newintracomm), 3, args);
}
int MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn, MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval, void *extra_state)
{
	char **args = assemble_args_list(4, ptoa(comm_copy_attr_fn), ptoa(comm_delete_attr_fn), ptoa(comm_keyval), ptoa(extra_state));
	PILGRIM_TRACING(int, MPI_Comm_create_keyval, PMPI_Comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state), 4, args);
}
int MPI_Comm_free_keyval(int *comm_keyval)
{
	char **args = assemble_args_list(1, ptoa(comm_keyval));
	PILGRIM_TRACING(int, MPI_Comm_free_keyval, PMPI_Comm_free_keyval(comm_keyval), 1, args);
}
int MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val)
{
	char **args = assemble_args_list(3, ptoa(&comm), itoa(comm_keyval), ptoa(attribute_val));
	PILGRIM_TRACING(int, MPI_Comm_set_attr, PMPI_Comm_set_attr(comm, comm_keyval, attribute_val), 3, args);
}
int MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval, void *attribute_val, int *flag)
{
	char **args = assemble_args_list(4, ptoa(&comm), itoa(comm_keyval), ptoa(attribute_val), ptoa(flag));
	PILGRIM_TRACING(int, MPI_Comm_get_attr, PMPI_Comm_get_attr(comm, comm_keyval, attribute_val, flag), 4, args);
}
int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval)
{
	char **args = assemble_args_list(2, ptoa(&comm), itoa(comm_keyval));
	PILGRIM_TRACING(int, MPI_Comm_delete_attr, PMPI_Comm_delete_attr(comm, comm_keyval), 2, args);
}
int MPI_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn, MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval, void *extra_state)
{
	char **args = assemble_args_list(4, ptoa(win_copy_attr_fn), ptoa(win_delete_attr_fn), ptoa(win_keyval), ptoa(extra_state));
	PILGRIM_TRACING(int, MPI_Win_create_keyval, PMPI_Win_create_keyval(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state), 4, args);
}
int MPI_Win_free_keyval(int *win_keyval)
{
	char **args = assemble_args_list(1, ptoa(win_keyval));
	PILGRIM_TRACING(int, MPI_Win_free_keyval, PMPI_Win_free_keyval(win_keyval), 1, args);
}
int MPI_Win_set_attr(MPI_Win win, int win_keyval, void *attribute_val)
{
	char **args = assemble_args_list(3, ptoa(&win), itoa(win_keyval), ptoa(attribute_val));
	PILGRIM_TRACING(int, MPI_Win_set_attr, PMPI_Win_set_attr(win, win_keyval, attribute_val), 3, args);
}
int MPI_Win_get_attr(MPI_Win win, int win_keyval, void *attribute_val, int *flag)
{
	char **args = assemble_args_list(4, ptoa(&win), itoa(win_keyval), ptoa(attribute_val), ptoa(flag));
	PILGRIM_TRACING(int, MPI_Win_get_attr, PMPI_Win_get_attr(win, win_keyval, attribute_val, flag), 4, args);
}
int MPI_Win_delete_attr(MPI_Win win, int win_keyval)
{
	char **args = assemble_args_list(2, ptoa(&win), itoa(win_keyval));
	PILGRIM_TRACING(int, MPI_Win_delete_attr, PMPI_Win_delete_attr(win, win_keyval), 2, args);
}
int MPI_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn, MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval, void *extra_state)
{
	char **args = assemble_args_list(4, ptoa(type_copy_attr_fn), ptoa(type_delete_attr_fn), ptoa(type_keyval), ptoa(extra_state));
	PILGRIM_TRACING(int, MPI_Type_create_keyval, PMPI_Type_create_keyval(type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state), 4, args);
}
int MPI_Type_free_keyval(int *type_keyval)
{
	char **args = assemble_args_list(1, ptoa(type_keyval));
	PILGRIM_TRACING(int, MPI_Type_free_keyval, PMPI_Type_free_keyval(type_keyval), 1, args);
}
int MPI_Type_set_attr(MPI_Datatype datatype, int type_keyval, void *attribute_val)
{
	char **args = assemble_args_list(3, ptoa(&datatype), itoa(type_keyval), ptoa(attribute_val));
	PILGRIM_TRACING(int, MPI_Type_set_attr, PMPI_Type_set_attr(datatype, type_keyval, attribute_val), 3, args);
}
int MPI_Type_get_attr(MPI_Datatype datatype, int type_keyval, void *attribute_val, int *flag)
{
	char **args = assemble_args_list(4, ptoa(&datatype), itoa(type_keyval), ptoa(attribute_val), ptoa(flag));
	PILGRIM_TRACING(int, MPI_Type_get_attr, PMPI_Type_get_attr(datatype, type_keyval, attribute_val, flag), 4, args);
}
int MPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval)
{
	char **args = assemble_args_list(2, ptoa(&datatype), itoa(type_keyval));
	PILGRIM_TRACING(int, MPI_Type_delete_attr, PMPI_Type_delete_attr(datatype, type_keyval), 2, args);
}
int MPI_Comm_set_name(MPI_Comm comm, const char *comm_name)
{
	char **args = assemble_args_list(2, ptoa(&comm), ptoa(comm_name));
	PILGRIM_TRACING(int, MPI_Comm_set_name, PMPI_Comm_set_name(comm, comm_name), 2, args);
}
int MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen)
{
	char **args = assemble_args_list(3, ptoa(&comm), ptoa(comm_name), ptoa(resultlen));
	PILGRIM_TRACING(int, MPI_Comm_get_name, PMPI_Comm_get_name(comm, comm_name, resultlen), 3, args);
}
int MPI_Type_set_name(MPI_Datatype datatype, const char *type_name)
{
	char **args = assemble_args_list(2, ptoa(&datatype), ptoa(type_name));
	PILGRIM_TRACING(int, MPI_Type_set_name, PMPI_Type_set_name(datatype, type_name), 2, args);
}
int MPI_Type_get_name(MPI_Datatype datatype, char *type_name, int *resultlen)
{
	char **args = assemble_args_list(3, ptoa(&datatype), ptoa(type_name), ptoa(resultlen));
	PILGRIM_TRACING(int, MPI_Type_get_name, PMPI_Type_get_name(datatype, type_name, resultlen), 3, args);
}
int MPI_Win_set_name(MPI_Win win, const char *win_name)
{
	char **args = assemble_args_list(2, ptoa(&win), ptoa(win_name));
	PILGRIM_TRACING(int, MPI_Win_set_name, PMPI_Win_set_name(win, win_name), 2, args);
}
int MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen)
{
	char **args = assemble_args_list(3, ptoa(&win), ptoa(win_name), ptoa(resultlen));
	PILGRIM_TRACING(int, MPI_Win_get_name, PMPI_Win_get_name(win, win_name, resultlen), 3, args);
}
int MPI_Cart_create(MPI_Comm comm_old, int ndims, const int dims[], const int periods[], int reorder, MPI_Comm *comm_cart)
{
	char **args = assemble_args_list(6, ptoa(&comm_old), itoa(ndims), ptoa(dims), ptoa(periods), itoa(reorder), ptoa(comm_cart));
	PILGRIM_TRACING(int, MPI_Cart_create, PMPI_Cart_create(comm_old, ndims, dims, periods, reorder, comm_cart), 6, args);
}
int MPI_Dims_create(int nnodes, int ndims, int dims[])
{
	char **args = assemble_args_list(3, itoa(nnodes), itoa(ndims), ptoa(dims));
	PILGRIM_TRACING(int, MPI_Dims_create, PMPI_Dims_create(nnodes, ndims, dims), 3, args);
}
int MPI_Graph_create(MPI_Comm comm_old, int nnodes, const int index[], const int edges[], int reorder, MPI_Comm *comm_graph)
{
	char **args = assemble_args_list(6, ptoa(&comm_old), itoa(nnodes), ptoa(index), ptoa(edges), itoa(reorder), ptoa(comm_graph));
	PILGRIM_TRACING(int, MPI_Graph_create, PMPI_Graph_create(comm_old, nnodes, index, edges, reorder, comm_graph), 6, args);
}
int MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree, const int sources[], const int sourceweights[], int outdegree, const int destinations[], const int destweights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph)
{
	char **args = assemble_args_list(10, ptoa(&comm_old), itoa(indegree), ptoa(sources), ptoa(sourceweights), itoa(outdegree), ptoa(destinations), ptoa(destweights), ptoa(&info), itoa(reorder), ptoa(comm_dist_graph));
	PILGRIM_TRACING(int, MPI_Dist_graph_create_adjacent, PMPI_Dist_graph_create_adjacent(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph), 10, args);
}
int MPI_Dist_graph_create(MPI_Comm comm_old, int n, const int sources[], const int degrees[], const int destinations[], const int weights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph)
{
	char **args = assemble_args_list(9, ptoa(&comm_old), itoa(n), ptoa(sources), ptoa(degrees), ptoa(destinations), ptoa(weights), ptoa(&info), itoa(reorder), ptoa(comm_dist_graph));
	PILGRIM_TRACING(int, MPI_Dist_graph_create, PMPI_Dist_graph_create(comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph), 9, args);
}
int MPI_Topo_test(MPI_Comm comm, int *status)
{
	char **args = assemble_args_list(2, ptoa(&comm), ptoa(status));
	PILGRIM_TRACING(int, MPI_Topo_test, PMPI_Topo_test(comm, status), 2, args);
}
int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges)
{
	char **args = assemble_args_list(3, ptoa(&comm), ptoa(nnodes), ptoa(nedges));
	PILGRIM_TRACING(int, MPI_Graphdims_get, PMPI_Graphdims_get(comm, nnodes, nedges), 3, args);
}
int MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges, int index[], int edges[])
{
	char **args = assemble_args_list(5, ptoa(&comm), itoa(maxindex), itoa(maxedges), ptoa(index), ptoa(edges));
	PILGRIM_TRACING(int, MPI_Graph_get, PMPI_Graph_get(comm, maxindex, maxedges, index, edges), 5, args);
}
int MPI_Cartdim_get(MPI_Comm comm, int *ndims)
{
	char **args = assemble_args_list(2, ptoa(&comm), ptoa(ndims));
	PILGRIM_TRACING(int, MPI_Cartdim_get, PMPI_Cartdim_get(comm, ndims), 2, args);
}
int MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[])
{
	char **args = assemble_args_list(5, ptoa(&comm), itoa(maxdims), ptoa(dims), ptoa(periods), ptoa(coords));
	PILGRIM_TRACING(int, MPI_Cart_get, PMPI_Cart_get(comm, maxdims, dims, periods, coords), 5, args);
}
int MPI_Cart_rank(MPI_Comm comm, const int coords[], int *rank)
{
	char **args = assemble_args_list(3, ptoa(&comm), ptoa(coords), ptoa(rank));
	PILGRIM_TRACING(int, MPI_Cart_rank, PMPI_Cart_rank(comm, coords, rank), 3, args);
}
int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[])
{
	char **args = assemble_args_list(4, ptoa(&comm), itoa(rank), itoa(maxdims), ptoa(coords));
	PILGRIM_TRACING(int, MPI_Cart_coords, PMPI_Cart_coords(comm, rank, maxdims, coords), 4, args);
}
int MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors)
{
	char **args = assemble_args_list(3, ptoa(&comm), itoa(rank), ptoa(nneighbors));
	PILGRIM_TRACING(int, MPI_Graph_neighbors_count, PMPI_Graph_neighbors_count(comm, rank, nneighbors), 3, args);
}
int MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors, int neighbors[])
{
	char **args = assemble_args_list(4, ptoa(&comm), itoa(rank), itoa(maxneighbors), ptoa(neighbors));
	PILGRIM_TRACING(int, MPI_Graph_neighbors, PMPI_Graph_neighbors(comm, rank, maxneighbors, neighbors), 4, args);
}
int MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree, int *outdegree, int *weighted)
{
	char **args = assemble_args_list(4, ptoa(&comm), ptoa(indegree), ptoa(outdegree), ptoa(weighted));
	PILGRIM_TRACING(int, MPI_Dist_graph_neighbors_count, PMPI_Dist_graph_neighbors_count(comm, indegree, outdegree, weighted), 4, args);
}
int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[], int sourceweights[], int maxoutdegree, int destinations[], int destweights[])
{
	char **args = assemble_args_list(7, ptoa(&comm), itoa(maxindegree), ptoa(sources), ptoa(sourceweights), itoa(maxoutdegree), ptoa(destinations), ptoa(destweights));
	PILGRIM_TRACING(int, MPI_Dist_graph_neighbors, PMPI_Dist_graph_neighbors(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights), 7, args);
}
int MPI_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest)
{
	char **args = assemble_args_list(5, ptoa(&comm), itoa(direction), itoa(disp), ptoa(rank_source), ptoa(rank_dest));
	PILGRIM_TRACING(int, MPI_Cart_shift, PMPI_Cart_shift(comm, direction, disp, rank_source, rank_dest), 5, args);
}
int MPI_Cart_sub(MPI_Comm comm, const int remain_dims[], MPI_Comm *newcomm)
{
	char **args = assemble_args_list(3, ptoa(&comm), ptoa(remain_dims), ptoa(newcomm));
	PILGRIM_TRACING(int, MPI_Cart_sub, PMPI_Cart_sub(comm, remain_dims, newcomm), 3, args);
}
int MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[], const int periods[], int *newrank)
{
	char **args = assemble_args_list(5, ptoa(&comm), itoa(ndims), ptoa(dims), ptoa(periods), ptoa(newrank));
	PILGRIM_TRACING(int, MPI_Cart_map, PMPI_Cart_map(comm, ndims, dims, periods, newrank), 5, args);
}
int MPI_Graph_map(MPI_Comm comm, int nnodes, const int index[], const int edges[], int *newrank)
{
	char **args = assemble_args_list(5, ptoa(&comm), itoa(nnodes), ptoa(index), ptoa(edges), ptoa(newrank));
	PILGRIM_TRACING(int, MPI_Graph_map, PMPI_Graph_map(comm, nnodes, index, edges, newrank), 5, args);
}
int MPI_Neighbor_allgather(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
	char **args = assemble_args_list(7, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), itoa(recvcount), ptoa(&recvtype), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Neighbor_allgather, PMPI_Neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm), 7, args);
}
int MPI_Neighbor_allgatherv(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm)
{
	char **args = assemble_args_list(8, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), ptoa(recvcounts), ptoa(displs), ptoa(&recvtype), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Neighbor_allgatherv, PMPI_Neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm), 8, args);
}
int MPI_Neighbor_alltoall(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
	char **args = assemble_args_list(7, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), itoa(recvcount), ptoa(&recvtype), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Neighbor_alltoall, PMPI_Neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm), 7, args);
}
int MPI_Neighbor_alltoallv(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm)
{
	char **args = assemble_args_list(9, ptoa(sendbuf), ptoa(sendcounts), ptoa(sdispls), ptoa(&sendtype), ptoa(recvbuf), ptoa(recvcounts), ptoa(rdispls), ptoa(&recvtype), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Neighbor_alltoallv, PMPI_Neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm), 9, args);
}
int MPI_Neighbor_alltoallw(const void* sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void* recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm)
{
	char **args = assemble_args_list(9, ptoa(sendbuf), ptoa(sendcounts), ptoa(sdispls), ptoa(sendtypes), ptoa(recvbuf), ptoa(recvcounts), ptoa(rdispls), ptoa(recvtypes), ptoa(&comm));
	PILGRIM_TRACING(int, MPI_Neighbor_alltoallw, PMPI_Neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm), 9, args);
}
int MPI_Ineighbor_allgather(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(8, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), itoa(recvcount), ptoa(&recvtype), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Ineighbor_allgather, PMPI_Ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request), 8, args);
}
int MPI_Ineighbor_allgatherv(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(9, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), ptoa(recvcounts), ptoa(displs), ptoa(&recvtype), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Ineighbor_allgatherv, PMPI_Ineighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request), 9, args);
}
int MPI_Ineighbor_alltoall(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(8, ptoa(sendbuf), itoa(sendcount), ptoa(&sendtype), ptoa(recvbuf), itoa(recvcount), ptoa(&recvtype), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Ineighbor_alltoall, PMPI_Ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request), 8, args);
}
int MPI_Ineighbor_alltoallv(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(10, ptoa(sendbuf), ptoa(sendcounts), ptoa(sdispls), ptoa(&sendtype), ptoa(recvbuf), ptoa(recvcounts), ptoa(rdispls), ptoa(&recvtype), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Ineighbor_alltoallv, PMPI_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request), 10, args);
}
int MPI_Ineighbor_alltoallw(const void* sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void* recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request)
{
	char **args = assemble_args_list(10, ptoa(sendbuf), ptoa(sendcounts), ptoa(sdispls), ptoa(sendtypes), ptoa(recvbuf), ptoa(recvcounts), ptoa(rdispls), ptoa(recvtypes), ptoa(&comm), ptoa(request));
	PILGRIM_TRACING(int, MPI_Ineighbor_alltoallw, PMPI_Ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request), 10, args);
}
int MPI_Get_version(int *version, int *subversion)
{
	char **args = assemble_args_list(2, ptoa(version), ptoa(subversion));
	PILGRIM_TRACING(int, MPI_Get_version, PMPI_Get_version(version, subversion), 2, args);
}
int MPI_Get_library_version(char *version, int *resultlen)
{
	char **args = assemble_args_list(2, ptoa(version), ptoa(resultlen));
	PILGRIM_TRACING(int, MPI_Get_library_version, PMPI_Get_library_version(version, resultlen), 2, args);
}
int MPI_Get_processor_name(char *name, int *resultlen)
{
	char **args = assemble_args_list(2, ptoa(name), ptoa(resultlen));
	PILGRIM_TRACING(int, MPI_Get_processor_name, PMPI_Get_processor_name(name, resultlen), 2, args);
}
int MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr)
{
	char **args = assemble_args_list(3, ptoa(&size), ptoa(&info), ptoa(baseptr));
	PILGRIM_TRACING(int, MPI_Alloc_mem, PMPI_Alloc_mem(size, info, baseptr), 3, args);
}
int MPI_Free_mem(void *base)
{
	char **args = assemble_args_list(1, ptoa(base));
	PILGRIM_TRACING(int, MPI_Free_mem, PMPI_Free_mem(base), 1, args);
}
int MPI_Comm_create_errhandler(MPI_Comm_errhandler_function *comm_errhandler_fn, MPI_Errhandler *errhandler)
{
	char **args = assemble_args_list(2, ptoa(comm_errhandler_fn), ptoa(errhandler));
	PILGRIM_TRACING(int, MPI_Comm_create_errhandler, PMPI_Comm_create_errhandler(comm_errhandler_fn, errhandler), 2, args);
}
int MPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler)
{
	char **args = assemble_args_list(2, ptoa(&comm), ptoa(&errhandler));
	PILGRIM_TRACING(int, MPI_Comm_set_errhandler, PMPI_Comm_set_errhandler(comm, errhandler), 2, args);
}
int MPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *errhandler)
{
	char **args = assemble_args_list(2, ptoa(&comm), ptoa(errhandler));
	PILGRIM_TRACING(int, MPI_Comm_get_errhandler, PMPI_Comm_get_errhandler(comm, errhandler), 2, args);
}
int MPI_Win_create_errhandler(MPI_Win_errhandler_function *win_errhandler_fn, MPI_Errhandler *errhandler)
{
	char **args = assemble_args_list(2, ptoa(win_errhandler_fn), ptoa(errhandler));
	PILGRIM_TRACING(int, MPI_Win_create_errhandler, PMPI_Win_create_errhandler(win_errhandler_fn, errhandler), 2, args);
}
int MPI_Win_set_errhandler(MPI_Win win, MPI_Errhandler errhandler)
{
	char **args = assemble_args_list(2, ptoa(&win), ptoa(&errhandler));
	PILGRIM_TRACING(int, MPI_Win_set_errhandler, PMPI_Win_set_errhandler(win, errhandler), 2, args);
}
int MPI_Win_get_errhandler(MPI_Win win, MPI_Errhandler *errhandler)
{
	char **args = assemble_args_list(2, ptoa(&win), ptoa(errhandler));
	PILGRIM_TRACING(int, MPI_Win_get_errhandler, PMPI_Win_get_errhandler(win, errhandler), 2, args);
}
int MPI_File_create_errhandler(MPI_File_errhandler_function *file_errhandler_fn, MPI_Errhandler *errhandler)
{
	char **args = assemble_args_list(2, ptoa(file_errhandler_fn), ptoa(errhandler));
	PILGRIM_TRACING(int, MPI_File_create_errhandler, PMPI_File_create_errhandler(file_errhandler_fn, errhandler), 2, args);
}
int MPI_File_set_errhandler(MPI_File file, MPI_Errhandler errhandler)
{
	char **args = assemble_args_list(2, ptoa(&file), ptoa(&errhandler));
	PILGRIM_TRACING(int, MPI_File_set_errhandler, PMPI_File_set_errhandler(file, errhandler), 2, args);
}
int MPI_File_get_errhandler(MPI_File file, MPI_Errhandler *errhandler)
{
	char **args = assemble_args_list(2, ptoa(&file), ptoa(errhandler));
	PILGRIM_TRACING(int, MPI_File_get_errhandler, PMPI_File_get_errhandler(file, errhandler), 2, args);
}
int MPI_Errhandler_free(MPI_Errhandler *errhandler)
{
	char **args = assemble_args_list(1, ptoa(errhandler));
	PILGRIM_TRACING(int, MPI_Errhandler_free, PMPI_Errhandler_free(errhandler), 1, args);
}
int MPI_Error_string(int errorcode, char *string, int *resultlen)
{
	char **args = assemble_args_list(3, itoa(errorcode), ptoa(string), ptoa(resultlen));
	PILGRIM_TRACING(int, MPI_Error_string, PMPI_Error_string(errorcode, string, resultlen), 3, args);
}
int MPI_Error_class(int errorcode, int *errorclass)
{
	char **args = assemble_args_list(2, itoa(errorcode), ptoa(errorclass));
	PILGRIM_TRACING(int, MPI_Error_class, PMPI_Error_class(errorcode, errorclass), 2, args);
}
int MPI_Add_error_class(int *errorclass)
{
	char **args = assemble_args_list(1, ptoa(errorclass));
	PILGRIM_TRACING(int, MPI_Add_error_class, PMPI_Add_error_class(errorclass), 1, args);
}
int MPI_Add_error_code(int errorclass, int *errorcode)
{
	char **args = assemble_args_list(2, itoa(errorclass), ptoa(errorcode));
	PILGRIM_TRACING(int, MPI_Add_error_code, PMPI_Add_error_code(errorclass, errorcode), 2, args);
}
int MPI_Add_error_string(int errorcode, const char *string)
{
	char **args = assemble_args_list(2, itoa(errorcode), ptoa(string));
	PILGRIM_TRACING(int, MPI_Add_error_string, PMPI_Add_error_string(errorcode, string), 2, args);
}
int MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode)
{
	char **args = assemble_args_list(2, ptoa(&comm), itoa(errorcode));
	PILGRIM_TRACING(int, MPI_Comm_call_errhandler, PMPI_Comm_call_errhandler(comm, errorcode), 2, args);
}
int MPI_Win_call_errhandler(MPI_Win win, int errorcode)
{
	char **args = assemble_args_list(2, ptoa(&win), itoa(errorcode));
	PILGRIM_TRACING(int, MPI_Win_call_errhandler, PMPI_Win_call_errhandler(win, errorcode), 2, args);
}
int MPI_File_call_errhandler(MPI_File fh, int errorcode)
{
	char **args = assemble_args_list(2, ptoa(&fh), itoa(errorcode));
	PILGRIM_TRACING(int, MPI_File_call_errhandler, PMPI_File_call_errhandler(fh, errorcode), 2, args);
}
double MPI_Wtime(void)
{
	char **args = NULL;
	PILGRIM_TRACING(double, MPI_Wtime, PMPI_Wtime(), 0, args);
}
double MPI_Wtick(void)
{
	char **args = NULL;
	PILGRIM_TRACING(double, MPI_Wtick, PMPI_Wtick(), 0, args);
}
int MPI_Initialized(int *flag)
{
	char **args = assemble_args_list(1, ptoa(flag));
	PILGRIM_TRACING(int, MPI_Initialized, PMPI_Initialized(flag), 1, args);
}
int MPI_Abort(MPI_Comm comm, int errorcode)
{
	char **args = assemble_args_list(2, ptoa(&comm), itoa(errorcode));
	PILGRIM_TRACING(int, MPI_Abort, PMPI_Abort(comm, errorcode), 2, args);
}
int MPI_Finalized(int *flag)
{
	char **args = assemble_args_list(1, ptoa(flag));
	PILGRIM_TRACING(int, MPI_Finalized, PMPI_Finalized(flag), 1, args);
}
int MPI_Info_create(MPI_Info *info)
{
	char **args = assemble_args_list(1, ptoa(info));
	PILGRIM_TRACING(int, MPI_Info_create, PMPI_Info_create(info), 1, args);
}
int MPI_Info_set(MPI_Info info, const char *key, const char *value)
{
	char **args = assemble_args_list(3, ptoa(&info), ptoa(key), ptoa(value));
	PILGRIM_TRACING(int, MPI_Info_set, PMPI_Info_set(info, key, value), 3, args);
}
int MPI_Info_delete(MPI_Info info, const char *key)
{
	char **args = assemble_args_list(2, ptoa(&info), ptoa(key));
	PILGRIM_TRACING(int, MPI_Info_delete, PMPI_Info_delete(info, key), 2, args);
}
int MPI_Info_get(MPI_Info info, const char *key, int valuelen, char *value, int *flag)
{
	char **args = assemble_args_list(5, ptoa(&info), ptoa(key), itoa(valuelen), ptoa(value), ptoa(flag));
	PILGRIM_TRACING(int, MPI_Info_get, PMPI_Info_get(info, key, valuelen, value, flag), 5, args);
}
int MPI_Info_get_valuelen(MPI_Info info, const char *key, int *valuelen, int *flag)
{
	char **args = assemble_args_list(4, ptoa(&info), ptoa(key), ptoa(valuelen), ptoa(flag));
	PILGRIM_TRACING(int, MPI_Info_get_valuelen, PMPI_Info_get_valuelen(info, key, valuelen, flag), 4, args);
}
int MPI_Info_get_nkeys(MPI_Info info, int *nkeys)
{
	char **args = assemble_args_list(2, ptoa(&info), ptoa(nkeys));
	PILGRIM_TRACING(int, MPI_Info_get_nkeys, PMPI_Info_get_nkeys(info, nkeys), 2, args);
}
int MPI_Info_get_nthkey(MPI_Info info, int n, char *key)
{
	char **args = assemble_args_list(3, ptoa(&info), itoa(n), ptoa(key));
	PILGRIM_TRACING(int, MPI_Info_get_nthkey, PMPI_Info_get_nthkey(info, n, key), 3, args);
}
int MPI_Info_dup(MPI_Info info, MPI_Info *newinfo)
{
	char **args = assemble_args_list(2, ptoa(&info), ptoa(newinfo));
	PILGRIM_TRACING(int, MPI_Info_dup, PMPI_Info_dup(info, newinfo), 2, args);
}
int MPI_Info_free(MPI_Info *info)
{
	char **args = assemble_args_list(1, ptoa(info));
	PILGRIM_TRACING(int, MPI_Info_free, PMPI_Info_free(info), 1, args);
}
int MPI_Comm_spawn(const char *command, char *argv[], int maxprocs, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
{
	char **args = assemble_args_list(8, ptoa(command), ptoa(argv), itoa(maxprocs), ptoa(&info), itoa(root), ptoa(&comm), ptoa(intercomm), ptoa(array_of_errcodes));
	PILGRIM_TRACING(int, MPI_Comm_spawn, PMPI_Comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes), 8, args);
}
int MPI_Comm_get_parent(MPI_Comm *parent)
{
	char **args = assemble_args_list(1, ptoa(parent));
	PILGRIM_TRACING(int, MPI_Comm_get_parent, PMPI_Comm_get_parent(parent), 1, args);
}
int MPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[], const int array_of_maxprocs[], const MPI_Info array_of_info[], int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
{
	char **args = assemble_args_list(9, itoa(count), ptoa(array_of_commands), ptoa(array_of_argv), ptoa(array_of_maxprocs), ptoa(array_of_info), itoa(root), ptoa(&comm), ptoa(intercomm), ptoa(array_of_errcodes));
	PILGRIM_TRACING(int, MPI_Comm_spawn_multiple, PMPI_Comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes), 9, args);
}
int MPI_Open_port(MPI_Info info, char *port_name)
{
	char **args = assemble_args_list(2, ptoa(&info), ptoa(port_name));
	PILGRIM_TRACING(int, MPI_Open_port, PMPI_Open_port(info, port_name), 2, args);
}
int MPI_Close_port(const char *port_name)
{
	char **args = assemble_args_list(1, ptoa(port_name));
	PILGRIM_TRACING(int, MPI_Close_port, PMPI_Close_port(port_name), 1, args);
}
int MPI_Comm_accept(const char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm)
{
	char **args = assemble_args_list(5, ptoa(port_name), ptoa(&info), itoa(root), ptoa(&comm), ptoa(newcomm));
	PILGRIM_TRACING(int, MPI_Comm_accept, PMPI_Comm_accept(port_name, info, root, comm, newcomm), 5, args);
}
int MPI_Comm_connect(const char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm)
{
	char **args = assemble_args_list(5, ptoa(port_name), ptoa(&info), itoa(root), ptoa(&comm), ptoa(newcomm));
	PILGRIM_TRACING(int, MPI_Comm_connect, PMPI_Comm_connect(port_name, info, root, comm, newcomm), 5, args);
}
int MPI_Publish_name(const char *service_name, MPI_Info info, const char *port_name)
{
	char **args = assemble_args_list(3, ptoa(service_name), ptoa(&info), ptoa(port_name));
	PILGRIM_TRACING(int, MPI_Publish_name, PMPI_Publish_name(service_name, info, port_name), 3, args);
}
int MPI_Unpublish_name(const char *service_name, MPI_Info info, const char *port_name)
{
	char **args = assemble_args_list(3, ptoa(service_name), ptoa(&info), ptoa(port_name));
	PILGRIM_TRACING(int, MPI_Unpublish_name, PMPI_Unpublish_name(service_name, info, port_name), 3, args);
}
int MPI_Lookup_name(const char *service_name, MPI_Info info, char *port_name)
{
	char **args = assemble_args_list(3, ptoa(service_name), ptoa(&info), ptoa(port_name));
	PILGRIM_TRACING(int, MPI_Lookup_name, PMPI_Lookup_name(service_name, info, port_name), 3, args);
}
int MPI_Comm_disconnect(MPI_Comm *comm)
{
	char **args = assemble_args_list(1, ptoa(comm));
	PILGRIM_TRACING(int, MPI_Comm_disconnect, PMPI_Comm_disconnect(comm), 1, args);
}
int MPI_Comm_join(int fd, MPI_Comm *intercomm)
{
	char **args = assemble_args_list(2, itoa(fd), ptoa(intercomm));
	PILGRIM_TRACING(int, MPI_Comm_join, PMPI_Comm_join(fd, intercomm), 2, args);
}
int MPI_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win)
{
	char **args = assemble_args_list(6, ptoa(base), ptoa(&size), itoa(disp_unit), ptoa(&info), ptoa(&comm), ptoa(win));
	PILGRIM_TRACING(int, MPI_Win_create, PMPI_Win_create(base, size, disp_unit, info, comm, win), 6, args);
}
int MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win)
{
	char **args = assemble_args_list(6, ptoa(&size), itoa(disp_unit), ptoa(&info), ptoa(&comm), ptoa(baseptr), ptoa(win));
	PILGRIM_TRACING(int, MPI_Win_allocate, PMPI_Win_allocate(size, disp_unit, info, comm, baseptr, win), 6, args);
}
int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win)
{
	char **args = assemble_args_list(6, ptoa(&size), itoa(disp_unit), ptoa(&info), ptoa(&comm), ptoa(baseptr), ptoa(win));
	PILGRIM_TRACING(int, MPI_Win_allocate_shared, PMPI_Win_allocate_shared(size, disp_unit, info, comm, baseptr, win), 6, args);
}
int MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit, void *baseptr)
{
	char **args = assemble_args_list(5, ptoa(&win), itoa(rank), ptoa(size), ptoa(disp_unit), ptoa(baseptr));
	PILGRIM_TRACING(int, MPI_Win_shared_query, PMPI_Win_shared_query(win, rank, size, disp_unit, baseptr), 5, args);
}
int MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win)
{
	char **args = assemble_args_list(3, ptoa(&info), ptoa(&comm), ptoa(win));
	PILGRIM_TRACING(int, MPI_Win_create_dynamic, PMPI_Win_create_dynamic(info, comm, win), 3, args);
}
int MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size)
{
	char **args = assemble_args_list(3, ptoa(&win), ptoa(base), ptoa(&size));
	PILGRIM_TRACING(int, MPI_Win_attach, PMPI_Win_attach(win, base, size), 3, args);
}
int MPI_Win_detach(MPI_Win win, const void *base)
{
	char **args = assemble_args_list(2, ptoa(&win), ptoa(base));
	PILGRIM_TRACING(int, MPI_Win_detach, PMPI_Win_detach(win, base), 2, args);
}
int MPI_Win_free(MPI_Win *win)
{
	char **args = assemble_args_list(1, ptoa(win));
	PILGRIM_TRACING(int, MPI_Win_free, PMPI_Win_free(win), 1, args);
}
int MPI_Win_get_group(MPI_Win win, MPI_Group *group)
{
	char **args = assemble_args_list(2, ptoa(&win), ptoa(group));
	PILGRIM_TRACING(int, MPI_Win_get_group, PMPI_Win_get_group(win, group), 2, args);
}
int MPI_Win_set_info(MPI_Win win, MPI_Info info)
{
	char **args = assemble_args_list(2, ptoa(&win), ptoa(&info));
	PILGRIM_TRACING(int, MPI_Win_set_info, PMPI_Win_set_info(win, info), 2, args);
}
int MPI_Win_get_info(MPI_Win win, MPI_Info *info_used)
{
	char **args = assemble_args_list(2, ptoa(&win), ptoa(info_used));
	PILGRIM_TRACING(int, MPI_Win_get_info, PMPI_Win_get_info(win, info_used), 2, args);
}
int MPI_Put(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win)
{
	char **args = assemble_args_list(8, ptoa(origin_addr), itoa(origin_count), ptoa(&origin_datatype), itoa(target_rank), ptoa(&target_disp), itoa(target_count), ptoa(&target_datatype), ptoa(&win));
	PILGRIM_TRACING(int, MPI_Put, PMPI_Put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win), 8, args);
}
int MPI_Get(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win)
{
	char **args = assemble_args_list(8, ptoa(origin_addr), itoa(origin_count), ptoa(&origin_datatype), itoa(target_rank), ptoa(&target_disp), itoa(target_count), ptoa(&target_datatype), ptoa(&win));
	PILGRIM_TRACING(int, MPI_Get, PMPI_Get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win), 8, args);
}
int MPI_Accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win)
{
	char **args = assemble_args_list(9, ptoa(origin_addr), itoa(origin_count), ptoa(&origin_datatype), itoa(target_rank), ptoa(&target_disp), itoa(target_count), ptoa(&target_datatype), ptoa(&op), ptoa(&win));
	PILGRIM_TRACING(int, MPI_Accumulate, PMPI_Accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win), 9, args);
}
int MPI_Get_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win)
{
	char **args = assemble_args_list(12, ptoa(origin_addr), itoa(origin_count), ptoa(&origin_datatype), ptoa(result_addr), itoa(result_count), ptoa(&result_datatype), itoa(target_rank), ptoa(&target_disp), itoa(target_count), ptoa(&target_datatype), ptoa(&op), ptoa(&win));
	PILGRIM_TRACING(int, MPI_Get_accumulate, PMPI_Get_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win), 12, args);
}
int MPI_Fetch_and_op(const void *origin_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Op op, MPI_Win win)
{
	char **args = assemble_args_list(7, ptoa(origin_addr), ptoa(result_addr), ptoa(&datatype), itoa(target_rank), ptoa(&target_disp), ptoa(&op), ptoa(&win));
	PILGRIM_TRACING(int, MPI_Fetch_and_op, PMPI_Fetch_and_op(origin_addr, result_addr, datatype, target_rank, target_disp, op, win), 7, args);
}
int MPI_Compare_and_swap(const void *origin_addr, const void *compare_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Win win)
{
	char **args = assemble_args_list(7, ptoa(origin_addr), ptoa(compare_addr), ptoa(result_addr), ptoa(&datatype), itoa(target_rank), ptoa(&target_disp), ptoa(&win));
	PILGRIM_TRACING(int, MPI_Compare_and_swap, PMPI_Compare_and_swap(origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win), 7, args);
}
int MPI_Rput(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request)
{
	char **args = assemble_args_list(9, ptoa(origin_addr), itoa(origin_count), ptoa(&origin_datatype), itoa(target_rank), ptoa(&target_disp), itoa(target_count), ptoa(&target_datatype), ptoa(&win), ptoa(request));
	PILGRIM_TRACING(int, MPI_Rput, PMPI_Rput(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request), 9, args);
}
int MPI_Rget(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request)
{
	char **args = assemble_args_list(9, ptoa(origin_addr), itoa(origin_count), ptoa(&origin_datatype), itoa(target_rank), ptoa(&target_disp), itoa(target_count), ptoa(&target_datatype), ptoa(&win), ptoa(request));
	PILGRIM_TRACING(int, MPI_Rget, PMPI_Rget(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request), 9, args);
}
int MPI_Raccumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request)
{
	char **args = assemble_args_list(10, ptoa(origin_addr), itoa(origin_count), ptoa(&origin_datatype), itoa(target_rank), ptoa(&target_disp), itoa(target_count), ptoa(&target_datatype), ptoa(&op), ptoa(&win), ptoa(request));
	PILGRIM_TRACING(int, MPI_Raccumulate, PMPI_Raccumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request), 10, args);
}
int MPI_Rget_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request)
{
	char **args = assemble_args_list(13, ptoa(origin_addr), itoa(origin_count), ptoa(&origin_datatype), ptoa(result_addr), itoa(result_count), ptoa(&result_datatype), itoa(target_rank), ptoa(&target_disp), itoa(target_count), ptoa(&target_datatype), ptoa(&op), ptoa(&win), ptoa(request));
	PILGRIM_TRACING(int, MPI_Rget_accumulate, PMPI_Rget_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request), 13, args);
}
int MPI_Win_fence(int assert, MPI_Win win)
{
	char **args = assemble_args_list(2, itoa(assert), ptoa(&win));
	PILGRIM_TRACING(int, MPI_Win_fence, PMPI_Win_fence(assert, win), 2, args);
}
int MPI_Win_start(MPI_Group group, int assert, MPI_Win win)
{
	char **args = assemble_args_list(3, ptoa(&group), itoa(assert), ptoa(&win));
	PILGRIM_TRACING(int, MPI_Win_start, PMPI_Win_start(group, assert, win), 3, args);
}
int MPI_Win_complete(MPI_Win win)
{
	char **args = assemble_args_list(1, ptoa(&win));
	PILGRIM_TRACING(int, MPI_Win_complete, PMPI_Win_complete(win), 1, args);
}
int MPI_Win_post(MPI_Group group, int assert, MPI_Win win)
{
	char **args = assemble_args_list(3, ptoa(&group), itoa(assert), ptoa(&win));
	PILGRIM_TRACING(int, MPI_Win_post, PMPI_Win_post(group, assert, win), 3, args);
}
int MPI_Win_wait(MPI_Win win)
{
	char **args = assemble_args_list(1, ptoa(&win));
	PILGRIM_TRACING(int, MPI_Win_wait, PMPI_Win_wait(win), 1, args);
}
int MPI_Win_test(MPI_Win win, int *flag)
{
	char **args = assemble_args_list(2, ptoa(&win), ptoa(flag));
	PILGRIM_TRACING(int, MPI_Win_test, PMPI_Win_test(win, flag), 2, args);
}
int MPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win)
{
	char **args = assemble_args_list(4, itoa(lock_type), itoa(rank), itoa(assert), ptoa(&win));
	PILGRIM_TRACING(int, MPI_Win_lock, PMPI_Win_lock(lock_type, rank, assert, win), 4, args);
}
int MPI_Win_lock_all(int assert, MPI_Win win)
{
	char **args = assemble_args_list(2, itoa(assert), ptoa(&win));
	PILGRIM_TRACING(int, MPI_Win_lock_all, PMPI_Win_lock_all(assert, win), 2, args);
}
int MPI_Win_unlock(int rank, MPI_Win win)
{
	char **args = assemble_args_list(2, itoa(rank), ptoa(&win));
	PILGRIM_TRACING(int, MPI_Win_unlock, PMPI_Win_unlock(rank, win), 2, args);
}
int MPI_Win_unlock_all(MPI_Win win)
{
	char **args = assemble_args_list(1, ptoa(&win));
	PILGRIM_TRACING(int, MPI_Win_unlock_all, PMPI_Win_unlock_all(win), 1, args);
}
int MPI_Win_flush(int rank, MPI_Win win)
{
	char **args = assemble_args_list(2, itoa(rank), ptoa(&win));
	PILGRIM_TRACING(int, MPI_Win_flush, PMPI_Win_flush(rank, win), 2, args);
}
int MPI_Win_flush_all(MPI_Win win)
{
	char **args = assemble_args_list(1, ptoa(&win));
	PILGRIM_TRACING(int, MPI_Win_flush_all, PMPI_Win_flush_all(win), 1, args);
}
int MPI_Win_flush_local(int rank, MPI_Win win)
{
	char **args = assemble_args_list(2, itoa(rank), ptoa(&win));
	PILGRIM_TRACING(int, MPI_Win_flush_local, PMPI_Win_flush_local(rank, win), 2, args);
}
int MPI_Win_flush_local_all(MPI_Win win)
{
	char **args = assemble_args_list(1, ptoa(&win));
	PILGRIM_TRACING(int, MPI_Win_flush_local_all, PMPI_Win_flush_local_all(win), 1, args);
}
int MPI_Win_sync(MPI_Win win)
{
	char **args = assemble_args_list(1, ptoa(&win));
	PILGRIM_TRACING(int, MPI_Win_sync, PMPI_Win_sync(win), 1, args);
}
int MPI_Grequest_start(MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn, MPI_Grequest_cancel_function *cancel_fn, void *extra_state, MPI_Request *request)
{
	char **args = assemble_args_list(5, ptoa(query_fn), ptoa(free_fn), ptoa(cancel_fn), ptoa(extra_state), ptoa(request));
	PILGRIM_TRACING(int, MPI_Grequest_start, PMPI_Grequest_start(query_fn, free_fn, cancel_fn, extra_state, request), 5, args);
}
int MPI_Grequest_complete(MPI_Request request)
{
	char **args = assemble_args_list(1, ptoa(&request));
	PILGRIM_TRACING(int, MPI_Grequest_complete, PMPI_Grequest_complete(request), 1, args);
}
int MPI_Status_set_elements(MPI_Status *status, MPI_Datatype datatype, int count)
{
	char **args = assemble_args_list(3, ptoa(status), ptoa(&datatype), itoa(count));
	PILGRIM_TRACING(int, MPI_Status_set_elements, PMPI_Status_set_elements(status, datatype, count), 3, args);
}
int MPI_Status_set_elements_x(MPI_Status *status, MPI_Datatype datatype, MPI_Count count)
{
	char **args = assemble_args_list(3, ptoa(status), ptoa(&datatype), ptoa(&count));
	PILGRIM_TRACING(int, MPI_Status_set_elements_x, PMPI_Status_set_elements_x(status, datatype, count), 3, args);
}
int MPI_Status_set_cancelled(MPI_Status *status, int flag)
{
	char **args = assemble_args_list(2, ptoa(status), itoa(flag));
	PILGRIM_TRACING(int, MPI_Status_set_cancelled, PMPI_Status_set_cancelled(status, flag), 2, args);
}
int MPI_Query_thread(int *provided)
{
	char **args = assemble_args_list(1, ptoa(provided));
	PILGRIM_TRACING(int, MPI_Query_thread, PMPI_Query_thread(provided), 1, args);
}
int MPI_Is_thread_main(int *flag)
{
	char **args = assemble_args_list(1, ptoa(flag));
	PILGRIM_TRACING(int, MPI_Is_thread_main, PMPI_Is_thread_main(flag), 1, args);
}
int MPI_Type_create_f90_real(int p, int r, MPI_Datatype *newtype)
{
	char **args = assemble_args_list(3, itoa(p), itoa(r), ptoa(newtype));
	PILGRIM_TRACING(int, MPI_Type_create_f90_real, PMPI_Type_create_f90_real(p, r, newtype), 3, args);
}
int MPI_Type_create_f90_complex(int p, int r, MPI_Datatype *newtype)
{
	char **args = assemble_args_list(3, itoa(p), itoa(r), ptoa(newtype));
	PILGRIM_TRACING(int, MPI_Type_create_f90_complex, PMPI_Type_create_f90_complex(p, r, newtype), 3, args);
}
int MPI_Type_create_f90_integer(int r, MPI_Datatype *newtype)
{
	char **args = assemble_args_list(2, itoa(r), ptoa(newtype));
	PILGRIM_TRACING(int, MPI_Type_create_f90_integer, PMPI_Type_create_f90_integer(r, newtype), 2, args);
}
int MPI_Type_match_size(int typeclass, int size, MPI_Datatype *datatype)
{
	char **args = assemble_args_list(3, itoa(typeclass), itoa(size), ptoa(datatype));
	PILGRIM_TRACING(int, MPI_Type_match_size, PMPI_Type_match_size(typeclass, size, datatype), 3, args);
}
int MPI_Pcontrol(const int level, ...)
{
	char **args = assemble_args_list(1, ptoa(&level));
	PILGRIM_TRACING(int, MPI_Pcontrol, PMPI_Pcontrol(level), 1, args);
}
int MPI_T_init_thread(int required, int *provided)
{
	char **args = assemble_args_list(2, itoa(required), ptoa(provided));
	PILGRIM_TRACING(int, MPI_T_init_thread, PMPI_T_init_thread(required, provided), 2, args);
}
int MPI_T_finalize(void)
{
	char **args = NULL;
	PILGRIM_TRACING(int, MPI_T_finalize, PMPI_T_finalize(), 0, args);
}
int MPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name, int *name_len)
{
	char **args = assemble_args_list(4, ptoa(&enumtype), ptoa(num), ptoa(name), ptoa(name_len));
	PILGRIM_TRACING(int, MPI_T_enum_get_info, PMPI_T_enum_get_info(enumtype, num, name, name_len), 4, args);
}
int MPI_T_enum_get_item(MPI_T_enum enumtype, int index, int *value, char *name, int *name_len)
{
	char **args = assemble_args_list(5, ptoa(&enumtype), itoa(index), ptoa(value), ptoa(name), ptoa(name_len));
	PILGRIM_TRACING(int, MPI_T_enum_get_item, PMPI_T_enum_get_item(enumtype, index, value, name, name_len), 5, args);
}
int MPI_T_cvar_get_num(int *num_cvar)
{
	char **args = assemble_args_list(1, ptoa(num_cvar));
	PILGRIM_TRACING(int, MPI_T_cvar_get_num, PMPI_T_cvar_get_num(num_cvar), 1, args);
}
int MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity, MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind, int *scope)
{
	char **args = assemble_args_list(10, itoa(cvar_index), ptoa(name), ptoa(name_len), ptoa(verbosity), ptoa(datatype), ptoa(enumtype), ptoa(desc), ptoa(desc_len), ptoa(bind), ptoa(scope));
	PILGRIM_TRACING(int, MPI_T_cvar_get_info, PMPI_T_cvar_get_info(cvar_index, name, name_len, verbosity, datatype, enumtype, desc, desc_len, bind, scope), 10, args);
}
int MPI_T_cvar_get_index(const char *name, int *cvar_index)
{
	char **args = assemble_args_list(2, ptoa(name), ptoa(cvar_index));
	PILGRIM_TRACING(int, MPI_T_cvar_get_index, PMPI_T_cvar_get_index(name, cvar_index), 2, args);
}
int MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle, MPI_T_cvar_handle *handle, int *count)
{
	char **args = assemble_args_list(4, itoa(cvar_index), ptoa(obj_handle), ptoa(handle), ptoa(count));
	PILGRIM_TRACING(int, MPI_T_cvar_handle_alloc, PMPI_T_cvar_handle_alloc(cvar_index, obj_handle, handle, count), 4, args);
}
int MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle)
{
	char **args = assemble_args_list(1, ptoa(handle));
	PILGRIM_TRACING(int, MPI_T_cvar_handle_free, PMPI_T_cvar_handle_free(handle), 1, args);
}
int MPI_T_cvar_read(MPI_T_cvar_handle handle, void* buf)
{
	char **args = assemble_args_list(2, ptoa(&handle), ptoa(buf));
	PILGRIM_TRACING(int, MPI_T_cvar_read, PMPI_T_cvar_read(handle, buf), 2, args);
}
int MPI_T_cvar_write(MPI_T_cvar_handle handle, const void* buf)
{
	char **args = assemble_args_list(2, ptoa(&handle), ptoa(buf));
	PILGRIM_TRACING(int, MPI_T_cvar_write, PMPI_T_cvar_write(handle, buf), 2, args);
}
int MPI_T_pvar_get_num(int *num_pvar)
{
	char **args = assemble_args_list(1, ptoa(num_pvar));
	PILGRIM_TRACING(int, MPI_T_pvar_get_num, PMPI_T_pvar_get_num(num_pvar), 1, args);
}
int MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *var_class, MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind, int *readonly, int *continuous, int *atomic)
{
	char **args = assemble_args_list(13, itoa(pvar_index), ptoa(name), ptoa(name_len), ptoa(verbosity), ptoa(var_class), ptoa(datatype), ptoa(enumtype), ptoa(desc), ptoa(desc_len), ptoa(bind), ptoa(readonly), ptoa(continuous), ptoa(atomic));
	PILGRIM_TRACING(int, MPI_T_pvar_get_info, PMPI_T_pvar_get_info(pvar_index, name, name_len, verbosity, var_class, datatype, enumtype, desc, desc_len, bind, readonly, continuous, atomic), 13, args);
}
int MPI_T_pvar_get_index(const char *name, int var_class, int *pvar_index)
{
	char **args = assemble_args_list(3, ptoa(name), itoa(var_class), ptoa(pvar_index));
	PILGRIM_TRACING(int, MPI_T_pvar_get_index, PMPI_T_pvar_get_index(name, var_class, pvar_index), 3, args);
}
int MPI_T_pvar_session_create(MPI_T_pvar_session *session)
{
	char **args = assemble_args_list(1, ptoa(session));
	PILGRIM_TRACING(int, MPI_T_pvar_session_create, PMPI_T_pvar_session_create(session), 1, args);
}
int MPI_T_pvar_session_free(MPI_T_pvar_session *session)
{
	char **args = assemble_args_list(1, ptoa(session));
	PILGRIM_TRACING(int, MPI_T_pvar_session_free, PMPI_T_pvar_session_free(session), 1, args);
}
int MPI_T_pvar_handle_alloc(MPI_T_pvar_session session, int pvar_index, void *obj_handle, MPI_T_pvar_handle *handle, int *count)
{
	char **args = assemble_args_list(5, ptoa(&session), itoa(pvar_index), ptoa(obj_handle), ptoa(handle), ptoa(count));
	PILGRIM_TRACING(int, MPI_T_pvar_handle_alloc, PMPI_T_pvar_handle_alloc(session, pvar_index, obj_handle, handle, count), 5, args);
}
int MPI_T_pvar_handle_free(MPI_T_pvar_session session, MPI_T_pvar_handle *handle)
{
	char **args = assemble_args_list(2, ptoa(&session), ptoa(handle));
	PILGRIM_TRACING(int, MPI_T_pvar_handle_free, PMPI_T_pvar_handle_free(session, handle), 2, args);
}
int MPI_T_pvar_start(MPI_T_pvar_session session, MPI_T_pvar_handle handle)
{
	char **args = assemble_args_list(2, ptoa(&session), ptoa(&handle));
	PILGRIM_TRACING(int, MPI_T_pvar_start, PMPI_T_pvar_start(session, handle), 2, args);
}
int MPI_T_pvar_stop(MPI_T_pvar_session session, MPI_T_pvar_handle handle)
{
	char **args = assemble_args_list(2, ptoa(&session), ptoa(&handle));
	PILGRIM_TRACING(int, MPI_T_pvar_stop, PMPI_T_pvar_stop(session, handle), 2, args);
}
int MPI_T_pvar_read(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void* buf)
{
	char **args = assemble_args_list(3, ptoa(&session), ptoa(&handle), ptoa(buf));
	PILGRIM_TRACING(int, MPI_T_pvar_read, PMPI_T_pvar_read(session, handle, buf), 3, args);
}
int MPI_T_pvar_write(MPI_T_pvar_session session, MPI_T_pvar_handle handle, const void* buf)
{
	char **args = assemble_args_list(3, ptoa(&session), ptoa(&handle), ptoa(buf));
	PILGRIM_TRACING(int, MPI_T_pvar_write, PMPI_T_pvar_write(session, handle, buf), 3, args);
}
int MPI_T_pvar_reset(MPI_T_pvar_session session, MPI_T_pvar_handle handle)
{
	char **args = assemble_args_list(2, ptoa(&session), ptoa(&handle));
	PILGRIM_TRACING(int, MPI_T_pvar_reset, PMPI_T_pvar_reset(session, handle), 2, args);
}
int MPI_T_pvar_readreset(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void* buf)
{
	char **args = assemble_args_list(3, ptoa(&session), ptoa(&handle), ptoa(buf));
	PILGRIM_TRACING(int, MPI_T_pvar_readreset, PMPI_T_pvar_readreset(session, handle, buf), 3, args);
}
int MPI_T_category_get_num(int *num_cat)
{
	char **args = assemble_args_list(1, ptoa(num_cat));
	PILGRIM_TRACING(int, MPI_T_category_get_num, PMPI_T_category_get_num(num_cat), 1, args);
}
int MPI_T_category_get_info(int cat_index, char *name, int *name_len, char *desc, int *desc_len, int *num_cvars, int *num_pvars, int *num_categories)
{
	char **args = assemble_args_list(8, itoa(cat_index), ptoa(name), ptoa(name_len), ptoa(desc), ptoa(desc_len), ptoa(num_cvars), ptoa(num_pvars), ptoa(num_categories));
	PILGRIM_TRACING(int, MPI_T_category_get_info, PMPI_T_category_get_info(cat_index, name, name_len, desc, desc_len, num_cvars, num_pvars, num_categories), 8, args);
}
int MPI_T_category_get_index(const char *name, int *cat_index)
{
	char **args = assemble_args_list(2, ptoa(name), ptoa(cat_index));
	PILGRIM_TRACING(int, MPI_T_category_get_index, PMPI_T_category_get_index(name, cat_index), 2, args);
}
int MPI_T_category_get_cvars(int cat_index, int len, int indices[])
{
	char **args = assemble_args_list(3, itoa(cat_index), itoa(len), ptoa(indices));
	PILGRIM_TRACING(int, MPI_T_category_get_cvars, PMPI_T_category_get_cvars(cat_index, len, indices), 3, args);
}
int MPI_T_category_get_pvars(int cat_index, int len, int indices[])
{
	char **args = assemble_args_list(3, itoa(cat_index), itoa(len), ptoa(indices));
	PILGRIM_TRACING(int, MPI_T_category_get_pvars, PMPI_T_category_get_pvars(cat_index, len, indices), 3, args);
}
int MPI_T_category_get_categories(int cat_index, int len, int indices[])
{
	char **args = assemble_args_list(3, itoa(cat_index), itoa(len), ptoa(indices));
	PILGRIM_TRACING(int, MPI_T_category_get_categories, PMPI_T_category_get_categories(cat_index, len, indices), 3, args);
}
int MPI_T_category_changed(int *stamp)
{
	char **args = assemble_args_list(1, ptoa(stamp));
	PILGRIM_TRACING(int, MPI_T_category_changed, PMPI_T_category_changed(stamp), 1, args);
}
int MPI_Keyval_create(MPI_Copy_function *copy_fn, MPI_Delete_function *delete_fn, int *keyval, void* extra_state)
{
	char **args = assemble_args_list(4, ptoa(copy_fn), ptoa(delete_fn), ptoa(keyval), ptoa(extra_state));
	PILGRIM_TRACING(int, MPI_Keyval_create, PMPI_Keyval_create(copy_fn, delete_fn, keyval, extra_state), 4, args);
}
int MPI_Keyval_free(int *keyval)
{
	char **args = assemble_args_list(1, ptoa(keyval));
	PILGRIM_TRACING(int, MPI_Keyval_free, PMPI_Keyval_free(keyval), 1, args);
}
int MPI_Attr_put(MPI_Comm comm, int keyval, void* attribute_val)
{
	char **args = assemble_args_list(3, ptoa(&comm), itoa(keyval), ptoa(attribute_val));
	PILGRIM_TRACING(int, MPI_Attr_put, PMPI_Attr_put(comm, keyval, attribute_val), 3, args);
}
int MPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val, int *flag)
{
	char **args = assemble_args_list(4, ptoa(&comm), itoa(keyval), ptoa(attribute_val), ptoa(flag));
	PILGRIM_TRACING(int, MPI_Attr_get, PMPI_Attr_get(comm, keyval, attribute_val, flag), 4, args);
}
int MPI_Attr_delete(MPI_Comm comm, int keyval)
{
	char **args = assemble_args_list(2, ptoa(&comm), itoa(keyval));
	PILGRIM_TRACING(int, MPI_Attr_delete, PMPI_Attr_delete(comm, keyval), 2, args);
}
