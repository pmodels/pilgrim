#include <mpi.h>
#include "pilgrim.h"
int MPI_Send(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
	void **args = assemble_args_list(6, &buf, &count, &datatype, &dest, &tag, &comm);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(dest), sizeof(tag), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Send, PMPI_Send(buf, count, datatype, dest, tag, comm), 6, sizes, args);
}
int MPI_Recv(void* buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status)
{
	void **args = assemble_args_list(7, &buf, &count, &datatype, &source, &tag, &comm, &status);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(source), sizeof(tag), sizeof(comm), sizeof(status) };
	PILGRIM_TRACING(int, MPI_Recv, PMPI_Recv(buf, count, datatype, source, tag, comm, status), 7, sizes, args);
}
int MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype, int *count)
{
	void **args = assemble_args_list(3, &status, &datatype, &count);
	int sizes[] = { sizeof(status), sizeof(datatype), sizeof(count) };
	PILGRIM_TRACING(int, MPI_Get_count, PMPI_Get_count(status, datatype, count), 3, sizes, args);
}
int MPI_Bsend(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
	void **args = assemble_args_list(6, &buf, &count, &datatype, &dest, &tag, &comm);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(dest), sizeof(tag), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Bsend, PMPI_Bsend(buf, count, datatype, dest, tag, comm), 6, sizes, args);
}
int MPI_Ssend(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
	void **args = assemble_args_list(6, &buf, &count, &datatype, &dest, &tag, &comm);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(dest), sizeof(tag), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Ssend, PMPI_Ssend(buf, count, datatype, dest, tag, comm), 6, sizes, args);
}
int MPI_Rsend(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
	void **args = assemble_args_list(6, &buf, &count, &datatype, &dest, &tag, &comm);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(dest), sizeof(tag), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Rsend, PMPI_Rsend(buf, count, datatype, dest, tag, comm), 6, sizes, args);
}
int MPI_Buffer_attach(void* buffer, int size)
{
	void **args = assemble_args_list(2, &buffer, &size);
	int sizes[] = { sizeof(buffer), sizeof(size) };
	PILGRIM_TRACING(int, MPI_Buffer_attach, PMPI_Buffer_attach(buffer, size), 2, sizes, args);
}
int MPI_Buffer_detach(void* buffer_addr, int* size)
{
	void **args = assemble_args_list(2, &buffer_addr, &size);
	int sizes[] = { sizeof(buffer_addr), sizeof(size) };
	PILGRIM_TRACING(int, MPI_Buffer_detach, PMPI_Buffer_detach(buffer_addr, size), 2, sizes, args);
}
int MPI_Isend(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(7, &buf, &count, &datatype, &dest, &tag, &comm, &request);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(dest), sizeof(tag), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Isend, PMPI_Isend(buf, count, datatype, dest, tag, comm, request), 7, sizes, args);
}
int MPI_Ibsend(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(7, &buf, &count, &datatype, &dest, &tag, &comm, &request);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(dest), sizeof(tag), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Ibsend, PMPI_Ibsend(buf, count, datatype, dest, tag, comm, request), 7, sizes, args);
}
int MPI_Issend(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(7, &buf, &count, &datatype, &dest, &tag, &comm, &request);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(dest), sizeof(tag), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Issend, PMPI_Issend(buf, count, datatype, dest, tag, comm, request), 7, sizes, args);
}
int MPI_Irsend(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(7, &buf, &count, &datatype, &dest, &tag, &comm, &request);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(dest), sizeof(tag), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Irsend, PMPI_Irsend(buf, count, datatype, dest, tag, comm, request), 7, sizes, args);
}
int MPI_Irecv(void* buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(7, &buf, &count, &datatype, &source, &tag, &comm, &request);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(source), sizeof(tag), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Irecv, PMPI_Irecv(buf, count, datatype, source, tag, comm, request), 7, sizes, args);
}
int MPI_Wait(MPI_Request *request, MPI_Status *status)
{
	void **args = assemble_args_list(2, &request, &status);
	int sizes[] = { sizeof(request), sizeof(status) };
	PILGRIM_TRACING(int, MPI_Wait, PMPI_Wait(request, status), 2, sizes, args);
}
int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status)
{
	void **args = assemble_args_list(3, &request, &flag, &status);
	int sizes[] = { sizeof(request), sizeof(flag), sizeof(status) };
	PILGRIM_TRACING(int, MPI_Test, PMPI_Test(request, flag, status), 3, sizes, args);
}
int MPI_Request_free(MPI_Request *request)
{
	void **args = assemble_args_list(1, &request);
	int sizes[] = { sizeof(request) };
	PILGRIM_TRACING(int, MPI_Request_free, PMPI_Request_free(request), 1, sizes, args);
}
int MPI_Waitany(int count, MPI_Request array_of_requests[], int *index, MPI_Status *status)
{
	void **args = assemble_args_list(4, &count, &array_of_requests, &index, &status);
	int sizes[] = { sizeof(count), sizeof(MPI_Request), sizeof(index), sizeof(status) };
	PILGRIM_TRACING(int, MPI_Waitany, PMPI_Waitany(count, array_of_requests, index, status), 4, sizes, args);
}
int MPI_Testany(int count, MPI_Request array_of_requests[], int *index, int *flag, MPI_Status *status)
{
	void **args = assemble_args_list(5, &count, &array_of_requests, &index, &flag, &status);
	int sizes[] = { sizeof(count), sizeof(MPI_Request), sizeof(index), sizeof(flag), sizeof(status) };
	PILGRIM_TRACING(int, MPI_Testany, PMPI_Testany(count, array_of_requests, index, flag, status), 5, sizes, args);
}
int MPI_Waitall(int count, MPI_Request array_of_requests[], MPI_Status array_of_statuses[])
{
	void **args = assemble_args_list(3, &count, &array_of_requests, &array_of_statuses);
	int sizes[] = { sizeof(count), sizeof(MPI_Request), sizeof(MPI_Status) };
	PILGRIM_TRACING(int, MPI_Waitall, PMPI_Waitall(count, array_of_requests, array_of_statuses), 3, sizes, args);
}
int MPI_Testall(int count, MPI_Request array_of_requests[], int *flag, MPI_Status array_of_statuses[])
{
	void **args = assemble_args_list(4, &count, &array_of_requests, &flag, &array_of_statuses);
	int sizes[] = { sizeof(count), sizeof(MPI_Request), sizeof(flag), sizeof(MPI_Status) };
	PILGRIM_TRACING(int, MPI_Testall, PMPI_Testall(count, array_of_requests, flag, array_of_statuses), 4, sizes, args);
}
int MPI_Waitsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status array_of_statuses[])
{
	void **args = assemble_args_list(5, &incount, &array_of_requests, &outcount, &array_of_indices, &array_of_statuses);
	int sizes[] = { sizeof(incount), sizeof(MPI_Request), sizeof(outcount), sizeof(int), sizeof(MPI_Status) };
	PILGRIM_TRACING(int, MPI_Waitsome, PMPI_Waitsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses), 5, sizes, args);
}
int MPI_Testsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status array_of_statuses[])
{
	void **args = assemble_args_list(5, &incount, &array_of_requests, &outcount, &array_of_indices, &array_of_statuses);
	int sizes[] = { sizeof(incount), sizeof(MPI_Request), sizeof(outcount), sizeof(int), sizeof(MPI_Status) };
	PILGRIM_TRACING(int, MPI_Testsome, PMPI_Testsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses), 5, sizes, args);
}
int MPI_Request_get_status(MPI_Request request, int *flag, MPI_Status *status)
{
	void **args = assemble_args_list(3, &request, &flag, &status);
	int sizes[] = { sizeof(request), sizeof(flag), sizeof(status) };
	PILGRIM_TRACING(int, MPI_Request_get_status, PMPI_Request_get_status(request, flag, status), 3, sizes, args);
}
int MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag, MPI_Status *status)
{
	void **args = assemble_args_list(5, &source, &tag, &comm, &flag, &status);
	int sizes[] = { sizeof(source), sizeof(tag), sizeof(comm), sizeof(flag), sizeof(status) };
	PILGRIM_TRACING(int, MPI_Iprobe, PMPI_Iprobe(source, tag, comm, flag, status), 5, sizes, args);
}
int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status)
{
	void **args = assemble_args_list(4, &source, &tag, &comm, &status);
	int sizes[] = { sizeof(source), sizeof(tag), sizeof(comm), sizeof(status) };
	PILGRIM_TRACING(int, MPI_Probe, PMPI_Probe(source, tag, comm, status), 4, sizes, args);
}
int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag, MPI_Message *message, MPI_Status *status)
{
	void **args = assemble_args_list(6, &source, &tag, &comm, &flag, &message, &status);
	int sizes[] = { sizeof(source), sizeof(tag), sizeof(comm), sizeof(flag), sizeof(message), sizeof(status) };
	PILGRIM_TRACING(int, MPI_Improbe, PMPI_Improbe(source, tag, comm, flag, message, status), 6, sizes, args);
}
int MPI_Mprobe(int source, int tag, MPI_Comm comm, MPI_Message *message, MPI_Status *status)
{
	void **args = assemble_args_list(5, &source, &tag, &comm, &message, &status);
	int sizes[] = { sizeof(source), sizeof(tag), sizeof(comm), sizeof(message), sizeof(status) };
	PILGRIM_TRACING(int, MPI_Mprobe, PMPI_Mprobe(source, tag, comm, message, status), 5, sizes, args);
}
int MPI_Mrecv(void* buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Status *status)
{
	void **args = assemble_args_list(5, &buf, &count, &datatype, &message, &status);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(message), sizeof(status) };
	PILGRIM_TRACING(int, MPI_Mrecv, PMPI_Mrecv(buf, count, datatype, message, status), 5, sizes, args);
}
int MPI_Imrecv(void* buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Request *request)
{
	void **args = assemble_args_list(5, &buf, &count, &datatype, &message, &request);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(message), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Imrecv, PMPI_Imrecv(buf, count, datatype, message, request), 5, sizes, args);
}
int MPI_Cancel(MPI_Request *request)
{
	void **args = assemble_args_list(1, &request);
	int sizes[] = { sizeof(request) };
	PILGRIM_TRACING(int, MPI_Cancel, PMPI_Cancel(request), 1, sizes, args);
}
int MPI_Test_cancelled(const MPI_Status *status, int *flag)
{
	void **args = assemble_args_list(2, &status, &flag);
	int sizes[] = { sizeof(status), sizeof(flag) };
	PILGRIM_TRACING(int, MPI_Test_cancelled, PMPI_Test_cancelled(status, flag), 2, sizes, args);
}
int MPI_Send_init(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(7, &buf, &count, &datatype, &dest, &tag, &comm, &request);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(dest), sizeof(tag), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Send_init, PMPI_Send_init(buf, count, datatype, dest, tag, comm, request), 7, sizes, args);
}
int MPI_Bsend_init(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(7, &buf, &count, &datatype, &dest, &tag, &comm, &request);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(dest), sizeof(tag), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Bsend_init, PMPI_Bsend_init(buf, count, datatype, dest, tag, comm, request), 7, sizes, args);
}
int MPI_Ssend_init(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(7, &buf, &count, &datatype, &dest, &tag, &comm, &request);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(dest), sizeof(tag), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Ssend_init, PMPI_Ssend_init(buf, count, datatype, dest, tag, comm, request), 7, sizes, args);
}
int MPI_Rsend_init(const void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(7, &buf, &count, &datatype, &dest, &tag, &comm, &request);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(dest), sizeof(tag), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Rsend_init, PMPI_Rsend_init(buf, count, datatype, dest, tag, comm, request), 7, sizes, args);
}
int MPI_Recv_init(void* buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(7, &buf, &count, &datatype, &source, &tag, &comm, &request);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(source), sizeof(tag), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Recv_init, PMPI_Recv_init(buf, count, datatype, source, tag, comm, request), 7, sizes, args);
}
int MPI_Start(MPI_Request *request)
{
	void **args = assemble_args_list(1, &request);
	int sizes[] = { sizeof(request) };
	PILGRIM_TRACING(int, MPI_Start, PMPI_Start(request), 1, sizes, args);
}
int MPI_Startall(int count, MPI_Request array_of_requests[])
{
	void **args = assemble_args_list(2, &count, &array_of_requests);
	int sizes[] = { sizeof(count), sizeof(MPI_Request) };
	PILGRIM_TRACING(int, MPI_Startall, PMPI_Startall(count, array_of_requests), 2, sizes, args);
}
int MPI_Sendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status)
{
	void **args = assemble_args_list(12, &sendbuf, &sendcount, &sendtype, &dest, &sendtag, &recvbuf, &recvcount, &recvtype, &source, &recvtag, &comm, &status);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(dest), sizeof(sendtag), sizeof(recvbuf), sizeof(recvcount), sizeof(recvtype), sizeof(source), sizeof(recvtag), sizeof(comm), sizeof(status) };
	PILGRIM_TRACING(int, MPI_Sendrecv, PMPI_Sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status), 12, sizes, args);
}
int MPI_Sendrecv_replace(void* buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status *status)
{
	void **args = assemble_args_list(9, &buf, &count, &datatype, &dest, &sendtag, &source, &recvtag, &comm, &status);
	int sizes[] = { sizeof(buf), sizeof(count), sizeof(datatype), sizeof(dest), sizeof(sendtag), sizeof(source), sizeof(recvtag), sizeof(comm), sizeof(status) };
	PILGRIM_TRACING(int, MPI_Sendrecv_replace, PMPI_Sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status), 9, sizes, args);
}
int MPI_Type_contiguous(int count, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	void **args = assemble_args_list(3, &count, &oldtype, &newtype);
	int sizes[] = { sizeof(count), sizeof(oldtype), sizeof(newtype) };
	PILGRIM_TRACING(int, MPI_Type_contiguous, PMPI_Type_contiguous(count, oldtype, newtype), 3, sizes, args);
}
int MPI_Type_vector(int count, int blocklength, int stride, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	void **args = assemble_args_list(5, &count, &blocklength, &stride, &oldtype, &newtype);
	int sizes[] = { sizeof(count), sizeof(blocklength), sizeof(stride), sizeof(oldtype), sizeof(newtype) };
	PILGRIM_TRACING(int, MPI_Type_vector, PMPI_Type_vector(count, blocklength, stride, oldtype, newtype), 5, sizes, args);
}
int MPI_Type_create_hvector(int count, int blocklength, MPI_Aint stride, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	void **args = assemble_args_list(5, &count, &blocklength, &stride, &oldtype, &newtype);
	int sizes[] = { sizeof(count), sizeof(blocklength), sizeof(stride), sizeof(oldtype), sizeof(newtype) };
	PILGRIM_TRACING(int, MPI_Type_create_hvector, PMPI_Type_create_hvector(count, blocklength, stride, oldtype, newtype), 5, sizes, args);
}
int MPI_Type_indexed(int count, const int array_of_blocklengths[], const int array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	void **args = assemble_args_list(5, &count, &array_of_blocklengths, &array_of_displacements, &oldtype, &newtype);
	int sizes[] = { sizeof(count), sizeof(const int), sizeof(const int), sizeof(oldtype), sizeof(newtype) };
	PILGRIM_TRACING(int, MPI_Type_indexed, PMPI_Type_indexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype), 5, sizes, args);
}
int MPI_Type_create_hindexed(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	void **args = assemble_args_list(5, &count, &array_of_blocklengths, &array_of_displacements, &oldtype, &newtype);
	int sizes[] = { sizeof(count), sizeof(const int), sizeof(const MPI_Aint), sizeof(oldtype), sizeof(newtype) };
	PILGRIM_TRACING(int, MPI_Type_create_hindexed, PMPI_Type_create_hindexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype), 5, sizes, args);
}
int MPI_Type_create_indexed_block(int count, int blocklength, const int array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	void **args = assemble_args_list(5, &count, &blocklength, &array_of_displacements, &oldtype, &newtype);
	int sizes[] = { sizeof(count), sizeof(blocklength), sizeof(const int), sizeof(oldtype), sizeof(newtype) };
	PILGRIM_TRACING(int, MPI_Type_create_indexed_block, PMPI_Type_create_indexed_block(count, blocklength, array_of_displacements, oldtype, newtype), 5, sizes, args);
}
int MPI_Type_create_hindexed_block(int count, int blocklength, const MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	void **args = assemble_args_list(5, &count, &blocklength, &array_of_displacements, &oldtype, &newtype);
	int sizes[] = { sizeof(count), sizeof(blocklength), sizeof(const MPI_Aint), sizeof(oldtype), sizeof(newtype) };
	PILGRIM_TRACING(int, MPI_Type_create_hindexed_block, PMPI_Type_create_hindexed_block(count, blocklength, array_of_displacements, oldtype, newtype), 5, sizes, args);
}
int MPI_Type_create_struct(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], const MPI_Datatype array_of_types[], MPI_Datatype *newtype)
{
	void **args = assemble_args_list(5, &count, &array_of_blocklengths, &array_of_displacements, &array_of_types, &newtype);
	int sizes[] = { sizeof(count), sizeof(const int), sizeof(const MPI_Aint), sizeof(const MPI_Datatype), sizeof(newtype) };
	PILGRIM_TRACING(int, MPI_Type_create_struct, PMPI_Type_create_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype), 5, sizes, args);
}
int MPI_Type_create_subarray(int ndims, const int array_of_sizes[], const int array_of_subsizes[], const int array_of_starts[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	void **args = assemble_args_list(7, &ndims, &array_of_sizes, &array_of_subsizes, &array_of_starts, &order, &oldtype, &newtype);
	int sizes[] = { sizeof(ndims), sizeof(const int), sizeof(const int), sizeof(const int), sizeof(order), sizeof(oldtype), sizeof(newtype) };
	PILGRIM_TRACING(int, MPI_Type_create_subarray, PMPI_Type_create_subarray(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype), 7, sizes, args);
}
int MPI_Type_create_darray(int size, int rank, int ndims, const int array_of_gsizes[], const int array_of_distribs[], const int array_of_dargs[], const int array_of_psizes[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	void **args = assemble_args_list(10, &size, &rank, &ndims, &array_of_gsizes, &array_of_distribs, &array_of_dargs, &array_of_psizes, &order, &oldtype, &newtype);
	int sizes[] = { sizeof(size), sizeof(rank), sizeof(ndims), sizeof(const int), sizeof(const int), sizeof(const int), sizeof(const int), sizeof(order), sizeof(oldtype), sizeof(newtype) };
	PILGRIM_TRACING(int, MPI_Type_create_darray, PMPI_Type_create_darray(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype), 10, sizes, args);
}
int MPI_Get_address(const void *location, MPI_Aint *address)
{
	void **args = assemble_args_list(2, &location, &address);
	int sizes[] = { sizeof(location), sizeof(address) };
	PILGRIM_TRACING(int, MPI_Get_address, PMPI_Get_address(location, address), 2, sizes, args);
}
MPI_Aint MPI_Aint_add(MPI_Aint base, MPI_Aint disp)
{
	void **args = assemble_args_list(2, &base, &disp);
	int sizes[] = { sizeof(base), sizeof(disp) };
	PILGRIM_TRACING(MPI_Aint, MPI_Aint_add, PMPI_Aint_add(base, disp), 2, sizes, args);
}
MPI_Aint MPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2)
{
	void **args = assemble_args_list(2, &addr1, &addr2);
	int sizes[] = { sizeof(addr1), sizeof(addr2) };
	PILGRIM_TRACING(MPI_Aint, MPI_Aint_diff, PMPI_Aint_diff(addr1, addr2), 2, sizes, args);
}
int MPI_Type_size(MPI_Datatype datatype, int *size)
{
	void **args = assemble_args_list(2, &datatype, &size);
	int sizes[] = { sizeof(datatype), sizeof(size) };
	PILGRIM_TRACING(int, MPI_Type_size, PMPI_Type_size(datatype, size), 2, sizes, args);
}
int MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size)
{
	void **args = assemble_args_list(2, &datatype, &size);
	int sizes[] = { sizeof(datatype), sizeof(size) };
	PILGRIM_TRACING(int, MPI_Type_size_x, PMPI_Type_size_x(datatype, size), 2, sizes, args);
}
int MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb, MPI_Aint *extent)
{
	void **args = assemble_args_list(3, &datatype, &lb, &extent);
	int sizes[] = { sizeof(datatype), sizeof(lb), sizeof(extent) };
	PILGRIM_TRACING(int, MPI_Type_get_extent, PMPI_Type_get_extent(datatype, lb, extent), 3, sizes, args);
}
int MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb, MPI_Count *extent)
{
	void **args = assemble_args_list(3, &datatype, &lb, &extent);
	int sizes[] = { sizeof(datatype), sizeof(lb), sizeof(extent) };
	PILGRIM_TRACING(int, MPI_Type_get_extent_x, PMPI_Type_get_extent_x(datatype, lb, extent), 3, sizes, args);
}
int MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent, MPI_Datatype *newtype)
{
	void **args = assemble_args_list(4, &oldtype, &lb, &extent, &newtype);
	int sizes[] = { sizeof(oldtype), sizeof(lb), sizeof(extent), sizeof(newtype) };
	PILGRIM_TRACING(int, MPI_Type_create_resized, PMPI_Type_create_resized(oldtype, lb, extent, newtype), 4, sizes, args);
}
int MPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb, MPI_Aint *true_extent)
{
	void **args = assemble_args_list(3, &datatype, &true_lb, &true_extent);
	int sizes[] = { sizeof(datatype), sizeof(true_lb), sizeof(true_extent) };
	PILGRIM_TRACING(int, MPI_Type_get_true_extent, PMPI_Type_get_true_extent(datatype, true_lb, true_extent), 3, sizes, args);
}
int MPI_Type_get_true_extent_x(MPI_Datatype datatype, MPI_Count *true_lb, MPI_Count *true_extent)
{
	void **args = assemble_args_list(3, &datatype, &true_lb, &true_extent);
	int sizes[] = { sizeof(datatype), sizeof(true_lb), sizeof(true_extent) };
	PILGRIM_TRACING(int, MPI_Type_get_true_extent_x, PMPI_Type_get_true_extent_x(datatype, true_lb, true_extent), 3, sizes, args);
}
int MPI_Type_commit(MPI_Datatype *datatype)
{
	void **args = assemble_args_list(1, &datatype);
	int sizes[] = { sizeof(datatype) };
	PILGRIM_TRACING(int, MPI_Type_commit, PMPI_Type_commit(datatype), 1, sizes, args);
}
int MPI_Type_free(MPI_Datatype *datatype)
{
	void **args = assemble_args_list(1, &datatype);
	int sizes[] = { sizeof(datatype) };
	PILGRIM_TRACING(int, MPI_Type_free, PMPI_Type_free(datatype), 1, sizes, args);
}
int MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype)
{
	void **args = assemble_args_list(2, &oldtype, &newtype);
	int sizes[] = { sizeof(oldtype), sizeof(newtype) };
	PILGRIM_TRACING(int, MPI_Type_dup, PMPI_Type_dup(oldtype, newtype), 2, sizes, args);
}
int MPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype, int *count)
{
	void **args = assemble_args_list(3, &status, &datatype, &count);
	int sizes[] = { sizeof(status), sizeof(datatype), sizeof(count) };
	PILGRIM_TRACING(int, MPI_Get_elements, PMPI_Get_elements(status, datatype, count), 3, sizes, args);
}
int MPI_Get_elements_x(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count)
{
	void **args = assemble_args_list(3, &status, &datatype, &count);
	int sizes[] = { sizeof(status), sizeof(datatype), sizeof(count) };
	PILGRIM_TRACING(int, MPI_Get_elements_x, PMPI_Get_elements_x(status, datatype, count), 3, sizes, args);
}
int MPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner)
{
	void **args = assemble_args_list(5, &datatype, &num_integers, &num_addresses, &num_datatypes, &combiner);
	int sizes[] = { sizeof(datatype), sizeof(num_integers), sizeof(num_addresses), sizeof(num_datatypes), sizeof(combiner) };
	PILGRIM_TRACING(int, MPI_Type_get_envelope, PMPI_Type_get_envelope(datatype, num_integers, num_addresses, num_datatypes, combiner), 5, sizes, args);
}
int MPI_Type_get_contents(MPI_Datatype datatype, int max_integers, int max_addresses, int max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Datatype array_of_datatypes[])
{
	void **args = assemble_args_list(7, &datatype, &max_integers, &max_addresses, &max_datatypes, &array_of_integers, &array_of_addresses, &array_of_datatypes);
	int sizes[] = { sizeof(datatype), sizeof(max_integers), sizeof(max_addresses), sizeof(max_datatypes), sizeof(int), sizeof(MPI_Aint), sizeof(MPI_Datatype) };
	PILGRIM_TRACING(int, MPI_Type_get_contents, PMPI_Type_get_contents(datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes), 7, sizes, args);
}
int MPI_Pack(const void* inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize, int *position, MPI_Comm comm)
{
	void **args = assemble_args_list(7, &inbuf, &incount, &datatype, &outbuf, &outsize, &position, &comm);
	int sizes[] = { sizeof(inbuf), sizeof(incount), sizeof(datatype), sizeof(outbuf), sizeof(outsize), sizeof(position), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Pack, PMPI_Pack(inbuf, incount, datatype, outbuf, outsize, position, comm), 7, sizes, args);
}
int MPI_Unpack(const void* inbuf, int insize, int *position, void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm)
{
	void **args = assemble_args_list(7, &inbuf, &insize, &position, &outbuf, &outcount, &datatype, &comm);
	int sizes[] = { sizeof(inbuf), sizeof(insize), sizeof(position), sizeof(outbuf), sizeof(outcount), sizeof(datatype), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Unpack, PMPI_Unpack(inbuf, insize, position, outbuf, outcount, datatype, comm), 7, sizes, args);
}
int MPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm, int *size)
{
	void **args = assemble_args_list(4, &incount, &datatype, &comm, &size);
	int sizes[] = { sizeof(incount), sizeof(datatype), sizeof(comm), sizeof(size) };
	PILGRIM_TRACING(int, MPI_Pack_size, PMPI_Pack_size(incount, datatype, comm, size), 4, sizes, args);
}
int MPI_Pack_external(const char datarep[], const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, MPI_Aint outsize, MPI_Aint *position)
{
	void **args = assemble_args_list(7, &datarep, &inbuf, &incount, &datatype, &outbuf, &outsize, &position);
	int sizes[] = { sizeof(const char), sizeof(inbuf), sizeof(incount), sizeof(datatype), sizeof(outbuf), sizeof(outsize), sizeof(position) };
	PILGRIM_TRACING(int, MPI_Pack_external, PMPI_Pack_external(datarep, inbuf, incount, datatype, outbuf, outsize, position), 7, sizes, args);
}
int MPI_Unpack_external(const char datarep[], const void *inbuf, MPI_Aint insize, MPI_Aint *position, void *outbuf, int outcount, MPI_Datatype datatype)
{
	void **args = assemble_args_list(7, &datarep, &inbuf, &insize, &position, &outbuf, &outcount, &datatype);
	int sizes[] = { sizeof(const char), sizeof(inbuf), sizeof(insize), sizeof(position), sizeof(outbuf), sizeof(outcount), sizeof(datatype) };
	PILGRIM_TRACING(int, MPI_Unpack_external, PMPI_Unpack_external(datarep, inbuf, insize, position, outbuf, outcount, datatype), 7, sizes, args);
}
int MPI_Pack_external_size(const char datarep[], int incount, MPI_Datatype datatype, MPI_Aint *size)
{
	void **args = assemble_args_list(4, &datarep, &incount, &datatype, &size);
	int sizes[] = { sizeof(const char), sizeof(incount), sizeof(datatype), sizeof(size) };
	PILGRIM_TRACING(int, MPI_Pack_external_size, PMPI_Pack_external_size(datarep, incount, datatype, size), 4, sizes, args);
}
int MPI_Barrier(MPI_Comm comm)
{
	void **args = assemble_args_list(1, &comm);
	int sizes[] = { sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Barrier, PMPI_Barrier(comm), 1, sizes, args);
}
int MPI_Bcast(void* buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm)
{
	void **args = assemble_args_list(5, &buffer, &count, &datatype, &root, &comm);
	int sizes[] = { sizeof(buffer), sizeof(count), sizeof(datatype), sizeof(root), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Bcast, PMPI_Bcast(buffer, count, datatype, root, comm), 5, sizes, args);
}
int MPI_Gather(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
	void **args = assemble_args_list(8, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcount, &recvtype, &root, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(recvcount), sizeof(recvtype), sizeof(root), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Gather, PMPI_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm), 8, sizes, args);
}
int MPI_Gatherv(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm)
{
	void **args = assemble_args_list(9, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcounts, &displs, &recvtype, &root, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(const int), sizeof(const int), sizeof(recvtype), sizeof(root), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Gatherv, PMPI_Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm), 9, sizes, args);
}
int MPI_Scatter(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
	void **args = assemble_args_list(8, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcount, &recvtype, &root, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(recvcount), sizeof(recvtype), sizeof(root), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Scatter, PMPI_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm), 8, sizes, args);
}
int MPI_Scatterv(const void* sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
	void **args = assemble_args_list(9, &sendbuf, &sendcounts, &displs, &sendtype, &recvbuf, &recvcount, &recvtype, &root, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(const int), sizeof(const int), sizeof(sendtype), sizeof(recvbuf), sizeof(recvcount), sizeof(recvtype), sizeof(root), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Scatterv, PMPI_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm), 9, sizes, args);
}
int MPI_Allgather(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
	void **args = assemble_args_list(7, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcount, &recvtype, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(recvcount), sizeof(recvtype), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Allgather, PMPI_Allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm), 7, sizes, args);
}
int MPI_Allgatherv(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm)
{
	void **args = assemble_args_list(8, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcounts, &displs, &recvtype, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(const int), sizeof(const int), sizeof(recvtype), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Allgatherv, PMPI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm), 8, sizes, args);
}
int MPI_Alltoall(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
	void **args = assemble_args_list(7, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcount, &recvtype, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(recvcount), sizeof(recvtype), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Alltoall, PMPI_Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm), 7, sizes, args);
}
int MPI_Alltoallv(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm)
{
	void **args = assemble_args_list(9, &sendbuf, &sendcounts, &sdispls, &sendtype, &recvbuf, &recvcounts, &rdispls, &recvtype, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(const int), sizeof(const int), sizeof(sendtype), sizeof(recvbuf), sizeof(const int), sizeof(const int), sizeof(recvtype), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Alltoallv, PMPI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm), 9, sizes, args);
}
int MPI_Alltoallw(const void* sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void* recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm)
{
	void **args = assemble_args_list(9, &sendbuf, &sendcounts, &sdispls, &sendtypes, &recvbuf, &recvcounts, &rdispls, &recvtypes, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(const int), sizeof(const int), sizeof(const MPI_Datatype), sizeof(recvbuf), sizeof(const int), sizeof(const int), sizeof(const MPI_Datatype), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Alltoallw, PMPI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm), 9, sizes, args);
}
int MPI_Reduce(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm)
{
	void **args = assemble_args_list(7, &sendbuf, &recvbuf, &count, &datatype, &op, &root, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(recvbuf), sizeof(count), sizeof(datatype), sizeof(op), sizeof(root), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Reduce, PMPI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm), 7, sizes, args);
}
int MPI_Op_create(MPI_User_function* user_fn, int commute, MPI_Op* op)
{
	void **args = assemble_args_list(3, &user_fn, &commute, &op);
	int sizes[] = { sizeof(user_fn), sizeof(commute), sizeof(op) };
	PILGRIM_TRACING(int, MPI_Op_create, PMPI_Op_create(user_fn, commute, op), 3, sizes, args);
}
int MPI_Op_free(MPI_Op *op)
{
	void **args = assemble_args_list(1, &op);
	int sizes[] = { sizeof(op) };
	PILGRIM_TRACING(int, MPI_Op_free, PMPI_Op_free(op), 1, sizes, args);
}
int MPI_Allreduce(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	void **args = assemble_args_list(6, &sendbuf, &recvbuf, &count, &datatype, &op, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(recvbuf), sizeof(count), sizeof(datatype), sizeof(op), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Allreduce, PMPI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm), 6, sizes, args);
}
int MPI_Reduce_local(const void* inbuf, void* inoutbuf, int count, MPI_Datatype datatype, MPI_Op op)
{
	void **args = assemble_args_list(5, &inbuf, &inoutbuf, &count, &datatype, &op);
	int sizes[] = { sizeof(inbuf), sizeof(inoutbuf), sizeof(count), sizeof(datatype), sizeof(op) };
	PILGRIM_TRACING(int, MPI_Reduce_local, PMPI_Reduce_local(inbuf, inoutbuf, count, datatype, op), 5, sizes, args);
}
int MPI_Op_commutative(MPI_Op op, int *commute)
{
	void **args = assemble_args_list(2, &op, &commute);
	int sizes[] = { sizeof(op), sizeof(commute) };
	PILGRIM_TRACING(int, MPI_Op_commutative, PMPI_Op_commutative(op, commute), 2, sizes, args);
}
int MPI_Reduce_scatter_block(const void* sendbuf, void* recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	void **args = assemble_args_list(6, &sendbuf, &recvbuf, &recvcount, &datatype, &op, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(recvbuf), sizeof(recvcount), sizeof(datatype), sizeof(op), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Reduce_scatter_block, PMPI_Reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm), 6, sizes, args);
}
int MPI_Reduce_scatter(const void* sendbuf, void* recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	void **args = assemble_args_list(6, &sendbuf, &recvbuf, &recvcounts, &datatype, &op, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(recvbuf), sizeof(const int), sizeof(datatype), sizeof(op), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Reduce_scatter, PMPI_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm), 6, sizes, args);
}
int MPI_Scan(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	void **args = assemble_args_list(6, &sendbuf, &recvbuf, &count, &datatype, &op, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(recvbuf), sizeof(count), sizeof(datatype), sizeof(op), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Scan, PMPI_Scan(sendbuf, recvbuf, count, datatype, op, comm), 6, sizes, args);
}
int MPI_Exscan(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
	void **args = assemble_args_list(6, &sendbuf, &recvbuf, &count, &datatype, &op, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(recvbuf), sizeof(count), sizeof(datatype), sizeof(op), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Exscan, PMPI_Exscan(sendbuf, recvbuf, count, datatype, op, comm), 6, sizes, args);
}
int MPI_Ibarrier(MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(2, &comm, &request);
	int sizes[] = { sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Ibarrier, PMPI_Ibarrier(comm, request), 2, sizes, args);
}
int MPI_Ibcast(void* buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(6, &buffer, &count, &datatype, &root, &comm, &request);
	int sizes[] = { sizeof(buffer), sizeof(count), sizeof(datatype), sizeof(root), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Ibcast, PMPI_Ibcast(buffer, count, datatype, root, comm, request), 6, sizes, args);
}
int MPI_Igather(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(9, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcount, &recvtype, &root, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(recvcount), sizeof(recvtype), sizeof(root), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Igather, PMPI_Igather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request), 9, sizes, args);
}
int MPI_Igatherv(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(10, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcounts, &displs, &recvtype, &root, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(const int), sizeof(const int), sizeof(recvtype), sizeof(root), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Igatherv, PMPI_Igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request), 10, sizes, args);
}
int MPI_Iscatter(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(9, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcount, &recvtype, &root, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(recvcount), sizeof(recvtype), sizeof(root), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Iscatter, PMPI_Iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request), 9, sizes, args);
}
int MPI_Iscatterv(const void* sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(10, &sendbuf, &sendcounts, &displs, &sendtype, &recvbuf, &recvcount, &recvtype, &root, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(const int), sizeof(const int), sizeof(sendtype), sizeof(recvbuf), sizeof(recvcount), sizeof(recvtype), sizeof(root), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Iscatterv, PMPI_Iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request), 10, sizes, args);
}
int MPI_Iallgather(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(8, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcount, &recvtype, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(recvcount), sizeof(recvtype), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Iallgather, PMPI_Iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request), 8, sizes, args);
}
int MPI_Iallgatherv(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request* request)
{
	void **args = assemble_args_list(9, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcounts, &displs, &recvtype, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(const int), sizeof(const int), sizeof(recvtype), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Iallgatherv, PMPI_Iallgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request), 9, sizes, args);
}
int MPI_Ialltoall(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(8, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcount, &recvtype, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(recvcount), sizeof(recvtype), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Ialltoall, PMPI_Ialltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request), 8, sizes, args);
}
int MPI_Ialltoallv(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(10, &sendbuf, &sendcounts, &sdispls, &sendtype, &recvbuf, &recvcounts, &rdispls, &recvtype, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(const int), sizeof(const int), sizeof(sendtype), sizeof(recvbuf), sizeof(const int), sizeof(const int), sizeof(recvtype), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Ialltoallv, PMPI_Ialltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request), 10, sizes, args);
}
int MPI_Ialltoallw(const void* sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void* recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(10, &sendbuf, &sendcounts, &sdispls, &sendtypes, &recvbuf, &recvcounts, &rdispls, &recvtypes, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(const int), sizeof(const int), sizeof(const MPI_Datatype), sizeof(recvbuf), sizeof(const int), sizeof(const int), sizeof(const MPI_Datatype), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Ialltoallw, PMPI_Ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request), 10, sizes, args);
}
int MPI_Ireduce(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(8, &sendbuf, &recvbuf, &count, &datatype, &op, &root, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(recvbuf), sizeof(count), sizeof(datatype), sizeof(op), sizeof(root), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Ireduce, PMPI_Ireduce(sendbuf, recvbuf, count, datatype, op, root, comm, request), 8, sizes, args);
}
int MPI_Iallreduce(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(7, &sendbuf, &recvbuf, &count, &datatype, &op, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(recvbuf), sizeof(count), sizeof(datatype), sizeof(op), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Iallreduce, PMPI_Iallreduce(sendbuf, recvbuf, count, datatype, op, comm, request), 7, sizes, args);
}
int MPI_Ireduce_scatter_block(const void* sendbuf, void* recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(7, &sendbuf, &recvbuf, &recvcount, &datatype, &op, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(recvbuf), sizeof(recvcount), sizeof(datatype), sizeof(op), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Ireduce_scatter_block, PMPI_Ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, request), 7, sizes, args);
}
int MPI_Ireduce_scatter(const void* sendbuf, void* recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(7, &sendbuf, &recvbuf, &recvcounts, &datatype, &op, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(recvbuf), sizeof(const int), sizeof(datatype), sizeof(op), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Ireduce_scatter, PMPI_Ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, request), 7, sizes, args);
}
int MPI_Iscan(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(7, &sendbuf, &recvbuf, &count, &datatype, &op, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(recvbuf), sizeof(count), sizeof(datatype), sizeof(op), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Iscan, PMPI_Iscan(sendbuf, recvbuf, count, datatype, op, comm, request), 7, sizes, args);
}
int MPI_Iexscan(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(7, &sendbuf, &recvbuf, &count, &datatype, &op, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(recvbuf), sizeof(count), sizeof(datatype), sizeof(op), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Iexscan, PMPI_Iexscan(sendbuf, recvbuf, count, datatype, op, comm, request), 7, sizes, args);
}
int MPI_Group_size(MPI_Group group, int *size)
{
	void **args = assemble_args_list(2, &group, &size);
	int sizes[] = { sizeof(group), sizeof(size) };
	PILGRIM_TRACING(int, MPI_Group_size, PMPI_Group_size(group, size), 2, sizes, args);
}
int MPI_Group_rank(MPI_Group group, int *rank)
{
	void **args = assemble_args_list(2, &group, &rank);
	int sizes[] = { sizeof(group), sizeof(rank) };
	PILGRIM_TRACING(int, MPI_Group_rank, PMPI_Group_rank(group, rank), 2, sizes, args);
}
int MPI_Group_translate_ranks(MPI_Group group1, int n, const int ranks1[], MPI_Group group2, int ranks2[])
{
	void **args = assemble_args_list(5, &group1, &n, &ranks1, &group2, &ranks2);
	int sizes[] = { sizeof(group1), sizeof(n), sizeof(const int), sizeof(group2), sizeof(int) };
	PILGRIM_TRACING(int, MPI_Group_translate_ranks, PMPI_Group_translate_ranks(group1, n, ranks1, group2, ranks2), 5, sizes, args);
}
int MPI_Group_compare(MPI_Group group1,MPI_Group group2, int *result)
{
	void **args = assemble_args_list(3, &group1, &group2, &result);
	int sizes[] = { sizeof(group1), sizeof(group2), sizeof(result) };
	PILGRIM_TRACING(int, MPI_Group_compare, PMPI_Group_compare(group1, group2, result), 3, sizes, args);
}
int MPI_Comm_group(MPI_Comm comm, MPI_Group *group)
{
	void **args = assemble_args_list(2, &comm, &group);
	int sizes[] = { sizeof(comm), sizeof(group) };
	PILGRIM_TRACING(int, MPI_Comm_group, PMPI_Comm_group(comm, group), 2, sizes, args);
}
int MPI_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup)
{
	void **args = assemble_args_list(3, &group1, &group2, &newgroup);
	int sizes[] = { sizeof(group1), sizeof(group2), sizeof(newgroup) };
	PILGRIM_TRACING(int, MPI_Group_union, PMPI_Group_union(group1, group2, newgroup), 3, sizes, args);
}
int MPI_Group_intersection(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup)
{
	void **args = assemble_args_list(3, &group1, &group2, &newgroup);
	int sizes[] = { sizeof(group1), sizeof(group2), sizeof(newgroup) };
	PILGRIM_TRACING(int, MPI_Group_intersection, PMPI_Group_intersection(group1, group2, newgroup), 3, sizes, args);
}
int MPI_Group_difference(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup)
{
	void **args = assemble_args_list(3, &group1, &group2, &newgroup);
	int sizes[] = { sizeof(group1), sizeof(group2), sizeof(newgroup) };
	PILGRIM_TRACING(int, MPI_Group_difference, PMPI_Group_difference(group1, group2, newgroup), 3, sizes, args);
}
int MPI_Group_incl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup)
{
	void **args = assemble_args_list(4, &group, &n, &ranks, &newgroup);
	int sizes[] = { sizeof(group), sizeof(n), sizeof(const int), sizeof(newgroup) };
	PILGRIM_TRACING(int, MPI_Group_incl, PMPI_Group_incl(group, n, ranks, newgroup), 4, sizes, args);
}
int MPI_Group_excl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup)
{
	void **args = assemble_args_list(4, &group, &n, &ranks, &newgroup);
	int sizes[] = { sizeof(group), sizeof(n), sizeof(const int), sizeof(newgroup) };
	PILGRIM_TRACING(int, MPI_Group_excl, PMPI_Group_excl(group, n, ranks, newgroup), 4, sizes, args);
}
int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup)
{
	void **args = assemble_args_list(4, &group, &n, &ranges, &newgroup);
	int sizes[] = { sizeof(group), sizeof(n), sizeof(int), sizeof(newgroup) };
	PILGRIM_TRACING(int, MPI_Group_range_incl, PMPI_Group_range_incl(group, n, ranges, newgroup), 4, sizes, args);
}
int MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup)
{
	void **args = assemble_args_list(4, &group, &n, &ranges, &newgroup);
	int sizes[] = { sizeof(group), sizeof(n), sizeof(int), sizeof(newgroup) };
	PILGRIM_TRACING(int, MPI_Group_range_excl, PMPI_Group_range_excl(group, n, ranges, newgroup), 4, sizes, args);
}
int MPI_Group_free(MPI_Group *group)
{
	void **args = assemble_args_list(1, &group);
	int sizes[] = { sizeof(group) };
	PILGRIM_TRACING(int, MPI_Group_free, PMPI_Group_free(group), 1, sizes, args);
}
int MPI_Comm_size(MPI_Comm comm, int *size)
{
	void **args = assemble_args_list(2, &comm, &size);
	int sizes[] = { sizeof(comm), sizeof(size) };
	PILGRIM_TRACING(int, MPI_Comm_size, PMPI_Comm_size(comm, size), 2, sizes, args);
}
int MPI_Comm_rank(MPI_Comm comm, int *rank)
{
	void **args = assemble_args_list(2, &comm, &rank);
	int sizes[] = { sizeof(comm), sizeof(rank) };
	PILGRIM_TRACING(int, MPI_Comm_rank, PMPI_Comm_rank(comm, rank), 2, sizes, args);
}
int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result)
{
	void **args = assemble_args_list(3, &comm1, &comm2, &result);
	int sizes[] = { sizeof(comm1), sizeof(comm2), sizeof(result) };
	PILGRIM_TRACING(int, MPI_Comm_compare, PMPI_Comm_compare(comm1, comm2, result), 3, sizes, args);
}
int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm)
{
	void **args = assemble_args_list(2, &comm, &newcomm);
	int sizes[] = { sizeof(comm), sizeof(newcomm) };
	PILGRIM_TRACING(int, MPI_Comm_dup, PMPI_Comm_dup(comm, newcomm), 2, sizes, args);
}
int MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info, MPI_Comm *newcomm)
{
	void **args = assemble_args_list(3, &comm, &info, &newcomm);
	int sizes[] = { sizeof(comm), sizeof(info), sizeof(newcomm) };
	PILGRIM_TRACING(int, MPI_Comm_dup_with_info, PMPI_Comm_dup_with_info(comm, info, newcomm), 3, sizes, args);
}
int MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm, MPI_Request *request)
{
	void **args = assemble_args_list(3, &comm, &newcomm, &request);
	int sizes[] = { sizeof(comm), sizeof(newcomm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Comm_idup, PMPI_Comm_idup(comm, newcomm, request), 3, sizes, args);
}
int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm)
{
	void **args = assemble_args_list(3, &comm, &group, &newcomm);
	int sizes[] = { sizeof(comm), sizeof(group), sizeof(newcomm) };
	PILGRIM_TRACING(int, MPI_Comm_create, PMPI_Comm_create(comm, group, newcomm), 3, sizes, args);
}
int MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag, MPI_Comm *newcomm)
{
	void **args = assemble_args_list(4, &comm, &group, &tag, &newcomm);
	int sizes[] = { sizeof(comm), sizeof(group), sizeof(tag), sizeof(newcomm) };
	PILGRIM_TRACING(int, MPI_Comm_create_group, PMPI_Comm_create_group(comm, group, tag, newcomm), 4, sizes, args);
}
int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm)
{
	void **args = assemble_args_list(4, &comm, &color, &key, &newcomm);
	int sizes[] = { sizeof(comm), sizeof(color), sizeof(key), sizeof(newcomm) };
	PILGRIM_TRACING(int, MPI_Comm_split, PMPI_Comm_split(comm, color, key, newcomm), 4, sizes, args);
}
int MPI_Comm_split_type(MPI_Comm comm, int split_type, int key, MPI_Info info, MPI_Comm *newcomm)
{
	void **args = assemble_args_list(5, &comm, &split_type, &key, &info, &newcomm);
	int sizes[] = { sizeof(comm), sizeof(split_type), sizeof(key), sizeof(info), sizeof(newcomm) };
	PILGRIM_TRACING(int, MPI_Comm_split_type, PMPI_Comm_split_type(comm, split_type, key, info, newcomm), 5, sizes, args);
}
int MPI_Comm_free(MPI_Comm *comm)
{
	void **args = assemble_args_list(1, &comm);
	int sizes[] = { sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Comm_free, PMPI_Comm_free(comm), 1, sizes, args);
}
int MPI_Comm_set_info(MPI_Comm comm, MPI_Info info)
{
	void **args = assemble_args_list(2, &comm, &info);
	int sizes[] = { sizeof(comm), sizeof(info) };
	PILGRIM_TRACING(int, MPI_Comm_set_info, PMPI_Comm_set_info(comm, info), 2, sizes, args);
}
int MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used)
{
	void **args = assemble_args_list(2, &comm, &info_used);
	int sizes[] = { sizeof(comm), sizeof(info_used) };
	PILGRIM_TRACING(int, MPI_Comm_get_info, PMPI_Comm_get_info(comm, info_used), 2, sizes, args);
}
int MPI_Comm_test_inter(MPI_Comm comm, int *flag)
{
	void **args = assemble_args_list(2, &comm, &flag);
	int sizes[] = { sizeof(comm), sizeof(flag) };
	PILGRIM_TRACING(int, MPI_Comm_test_inter, PMPI_Comm_test_inter(comm, flag), 2, sizes, args);
}
int MPI_Comm_remote_size(MPI_Comm comm, int *size)
{
	void **args = assemble_args_list(2, &comm, &size);
	int sizes[] = { sizeof(comm), sizeof(size) };
	PILGRIM_TRACING(int, MPI_Comm_remote_size, PMPI_Comm_remote_size(comm, size), 2, sizes, args);
}
int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group)
{
	void **args = assemble_args_list(2, &comm, &group);
	int sizes[] = { sizeof(comm), sizeof(group) };
	PILGRIM_TRACING(int, MPI_Comm_remote_group, PMPI_Comm_remote_group(comm, group), 2, sizes, args);
}
int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader, MPI_Comm peer_comm, int remote_leader, int tag, MPI_Comm *newintercomm)
{
	void **args = assemble_args_list(6, &local_comm, &local_leader, &peer_comm, &remote_leader, &tag, &newintercomm);
	int sizes[] = { sizeof(local_comm), sizeof(local_leader), sizeof(peer_comm), sizeof(remote_leader), sizeof(tag), sizeof(newintercomm) };
	PILGRIM_TRACING(int, MPI_Intercomm_create, PMPI_Intercomm_create(local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm), 6, sizes, args);
}
int MPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm)
{
	void **args = assemble_args_list(3, &intercomm, &high, &newintracomm);
	int sizes[] = { sizeof(intercomm), sizeof(high), sizeof(newintracomm) };
	PILGRIM_TRACING(int, MPI_Intercomm_merge, PMPI_Intercomm_merge(intercomm, high, newintracomm), 3, sizes, args);
}
int MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn, MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval, void *extra_state)
{
	void **args = assemble_args_list(4, &comm_copy_attr_fn, &comm_delete_attr_fn, &comm_keyval, &extra_state);
	int sizes[] = { sizeof(comm_copy_attr_fn), sizeof(comm_delete_attr_fn), sizeof(comm_keyval), sizeof(extra_state) };
	PILGRIM_TRACING(int, MPI_Comm_create_keyval, PMPI_Comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state), 4, sizes, args);
}
int MPI_Comm_free_keyval(int *comm_keyval)
{
	void **args = assemble_args_list(1, &comm_keyval);
	int sizes[] = { sizeof(comm_keyval) };
	PILGRIM_TRACING(int, MPI_Comm_free_keyval, PMPI_Comm_free_keyval(comm_keyval), 1, sizes, args);
}
int MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val)
{
	void **args = assemble_args_list(3, &comm, &comm_keyval, &attribute_val);
	int sizes[] = { sizeof(comm), sizeof(comm_keyval), sizeof(attribute_val) };
	PILGRIM_TRACING(int, MPI_Comm_set_attr, PMPI_Comm_set_attr(comm, comm_keyval, attribute_val), 3, sizes, args);
}
int MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval, void *attribute_val, int *flag)
{
	void **args = assemble_args_list(4, &comm, &comm_keyval, &attribute_val, &flag);
	int sizes[] = { sizeof(comm), sizeof(comm_keyval), sizeof(attribute_val), sizeof(flag) };
	PILGRIM_TRACING(int, MPI_Comm_get_attr, PMPI_Comm_get_attr(comm, comm_keyval, attribute_val, flag), 4, sizes, args);
}
int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval)
{
	void **args = assemble_args_list(2, &comm, &comm_keyval);
	int sizes[] = { sizeof(comm), sizeof(comm_keyval) };
	PILGRIM_TRACING(int, MPI_Comm_delete_attr, PMPI_Comm_delete_attr(comm, comm_keyval), 2, sizes, args);
}
int MPI_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn, MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval, void *extra_state)
{
	void **args = assemble_args_list(4, &win_copy_attr_fn, &win_delete_attr_fn, &win_keyval, &extra_state);
	int sizes[] = { sizeof(win_copy_attr_fn), sizeof(win_delete_attr_fn), sizeof(win_keyval), sizeof(extra_state) };
	PILGRIM_TRACING(int, MPI_Win_create_keyval, PMPI_Win_create_keyval(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state), 4, sizes, args);
}
int MPI_Win_free_keyval(int *win_keyval)
{
	void **args = assemble_args_list(1, &win_keyval);
	int sizes[] = { sizeof(win_keyval) };
	PILGRIM_TRACING(int, MPI_Win_free_keyval, PMPI_Win_free_keyval(win_keyval), 1, sizes, args);
}
int MPI_Win_set_attr(MPI_Win win, int win_keyval, void *attribute_val)
{
	void **args = assemble_args_list(3, &win, &win_keyval, &attribute_val);
	int sizes[] = { sizeof(win), sizeof(win_keyval), sizeof(attribute_val) };
	PILGRIM_TRACING(int, MPI_Win_set_attr, PMPI_Win_set_attr(win, win_keyval, attribute_val), 3, sizes, args);
}
int MPI_Win_get_attr(MPI_Win win, int win_keyval, void *attribute_val, int *flag)
{
	void **args = assemble_args_list(4, &win, &win_keyval, &attribute_val, &flag);
	int sizes[] = { sizeof(win), sizeof(win_keyval), sizeof(attribute_val), sizeof(flag) };
	PILGRIM_TRACING(int, MPI_Win_get_attr, PMPI_Win_get_attr(win, win_keyval, attribute_val, flag), 4, sizes, args);
}
int MPI_Win_delete_attr(MPI_Win win, int win_keyval)
{
	void **args = assemble_args_list(2, &win, &win_keyval);
	int sizes[] = { sizeof(win), sizeof(win_keyval) };
	PILGRIM_TRACING(int, MPI_Win_delete_attr, PMPI_Win_delete_attr(win, win_keyval), 2, sizes, args);
}
int MPI_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn, MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval, void *extra_state)
{
	void **args = assemble_args_list(4, &type_copy_attr_fn, &type_delete_attr_fn, &type_keyval, &extra_state);
	int sizes[] = { sizeof(type_copy_attr_fn), sizeof(type_delete_attr_fn), sizeof(type_keyval), sizeof(extra_state) };
	PILGRIM_TRACING(int, MPI_Type_create_keyval, PMPI_Type_create_keyval(type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state), 4, sizes, args);
}
int MPI_Type_free_keyval(int *type_keyval)
{
	void **args = assemble_args_list(1, &type_keyval);
	int sizes[] = { sizeof(type_keyval) };
	PILGRIM_TRACING(int, MPI_Type_free_keyval, PMPI_Type_free_keyval(type_keyval), 1, sizes, args);
}
int MPI_Type_set_attr(MPI_Datatype datatype, int type_keyval, void *attribute_val)
{
	void **args = assemble_args_list(3, &datatype, &type_keyval, &attribute_val);
	int sizes[] = { sizeof(datatype), sizeof(type_keyval), sizeof(attribute_val) };
	PILGRIM_TRACING(int, MPI_Type_set_attr, PMPI_Type_set_attr(datatype, type_keyval, attribute_val), 3, sizes, args);
}
int MPI_Type_get_attr(MPI_Datatype datatype, int type_keyval, void *attribute_val, int *flag)
{
	void **args = assemble_args_list(4, &datatype, &type_keyval, &attribute_val, &flag);
	int sizes[] = { sizeof(datatype), sizeof(type_keyval), sizeof(attribute_val), sizeof(flag) };
	PILGRIM_TRACING(int, MPI_Type_get_attr, PMPI_Type_get_attr(datatype, type_keyval, attribute_val, flag), 4, sizes, args);
}
int MPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval)
{
	void **args = assemble_args_list(2, &datatype, &type_keyval);
	int sizes[] = { sizeof(datatype), sizeof(type_keyval) };
	PILGRIM_TRACING(int, MPI_Type_delete_attr, PMPI_Type_delete_attr(datatype, type_keyval), 2, sizes, args);
}
int MPI_Comm_set_name(MPI_Comm comm, const char *comm_name)
{
	void **args = assemble_args_list(2, &comm, &comm_name);
	int sizes[] = { sizeof(comm), sizeof(comm_name) };
	PILGRIM_TRACING(int, MPI_Comm_set_name, PMPI_Comm_set_name(comm, comm_name), 2, sizes, args);
}
int MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen)
{
	void **args = assemble_args_list(3, &comm, &comm_name, &resultlen);
	int sizes[] = { sizeof(comm), sizeof(comm_name), sizeof(resultlen) };
	PILGRIM_TRACING(int, MPI_Comm_get_name, PMPI_Comm_get_name(comm, comm_name, resultlen), 3, sizes, args);
}
int MPI_Type_set_name(MPI_Datatype datatype, const char *type_name)
{
	void **args = assemble_args_list(2, &datatype, &type_name);
	int sizes[] = { sizeof(datatype), sizeof(type_name) };
	PILGRIM_TRACING(int, MPI_Type_set_name, PMPI_Type_set_name(datatype, type_name), 2, sizes, args);
}
int MPI_Type_get_name(MPI_Datatype datatype, char *type_name, int *resultlen)
{
	void **args = assemble_args_list(3, &datatype, &type_name, &resultlen);
	int sizes[] = { sizeof(datatype), sizeof(type_name), sizeof(resultlen) };
	PILGRIM_TRACING(int, MPI_Type_get_name, PMPI_Type_get_name(datatype, type_name, resultlen), 3, sizes, args);
}
int MPI_Win_set_name(MPI_Win win, const char *win_name)
{
	void **args = assemble_args_list(2, &win, &win_name);
	int sizes[] = { sizeof(win), sizeof(win_name) };
	PILGRIM_TRACING(int, MPI_Win_set_name, PMPI_Win_set_name(win, win_name), 2, sizes, args);
}
int MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen)
{
	void **args = assemble_args_list(3, &win, &win_name, &resultlen);
	int sizes[] = { sizeof(win), sizeof(win_name), sizeof(resultlen) };
	PILGRIM_TRACING(int, MPI_Win_get_name, PMPI_Win_get_name(win, win_name, resultlen), 3, sizes, args);
}
int MPI_Cart_create(MPI_Comm comm_old, int ndims, const int dims[], const int periods[], int reorder, MPI_Comm *comm_cart)
{
	void **args = assemble_args_list(6, &comm_old, &ndims, &dims, &periods, &reorder, &comm_cart);
	int sizes[] = { sizeof(comm_old), sizeof(ndims), sizeof(const int), sizeof(const int), sizeof(reorder), sizeof(comm_cart) };
	PILGRIM_TRACING(int, MPI_Cart_create, PMPI_Cart_create(comm_old, ndims, dims, periods, reorder, comm_cart), 6, sizes, args);
}
int MPI_Dims_create(int nnodes, int ndims, int dims[])
{
	void **args = assemble_args_list(3, &nnodes, &ndims, &dims);
	int sizes[] = { sizeof(nnodes), sizeof(ndims), sizeof(int) };
	PILGRIM_TRACING(int, MPI_Dims_create, PMPI_Dims_create(nnodes, ndims, dims), 3, sizes, args);
}
int MPI_Graph_create(MPI_Comm comm_old, int nnodes, const int index[], const int edges[], int reorder, MPI_Comm *comm_graph)
{
	void **args = assemble_args_list(6, &comm_old, &nnodes, &index, &edges, &reorder, &comm_graph);
	int sizes[] = { sizeof(comm_old), sizeof(nnodes), sizeof(const int), sizeof(const int), sizeof(reorder), sizeof(comm_graph) };
	PILGRIM_TRACING(int, MPI_Graph_create, PMPI_Graph_create(comm_old, nnodes, index, edges, reorder, comm_graph), 6, sizes, args);
}
int MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree, const int sources[], const int sourceweights[], int outdegree, const int destinations[], const int destweights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph)
{
	void **args = assemble_args_list(10, &comm_old, &indegree, &sources, &sourceweights, &outdegree, &destinations, &destweights, &info, &reorder, &comm_dist_graph);
	int sizes[] = { sizeof(comm_old), sizeof(indegree), sizeof(const int), sizeof(const int), sizeof(outdegree), sizeof(const int), sizeof(const int), sizeof(info), sizeof(reorder), sizeof(comm_dist_graph) };
	PILGRIM_TRACING(int, MPI_Dist_graph_create_adjacent, PMPI_Dist_graph_create_adjacent(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph), 10, sizes, args);
}
int MPI_Dist_graph_create(MPI_Comm comm_old, int n, const int sources[], const int degrees[], const int destinations[], const int weights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph)
{
	void **args = assemble_args_list(9, &comm_old, &n, &sources, &degrees, &destinations, &weights, &info, &reorder, &comm_dist_graph);
	int sizes[] = { sizeof(comm_old), sizeof(n), sizeof(const int), sizeof(const int), sizeof(const int), sizeof(const int), sizeof(info), sizeof(reorder), sizeof(comm_dist_graph) };
	PILGRIM_TRACING(int, MPI_Dist_graph_create, PMPI_Dist_graph_create(comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph), 9, sizes, args);
}
int MPI_Topo_test(MPI_Comm comm, int *status)
{
	void **args = assemble_args_list(2, &comm, &status);
	int sizes[] = { sizeof(comm), sizeof(status) };
	PILGRIM_TRACING(int, MPI_Topo_test, PMPI_Topo_test(comm, status), 2, sizes, args);
}
int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges)
{
	void **args = assemble_args_list(3, &comm, &nnodes, &nedges);
	int sizes[] = { sizeof(comm), sizeof(nnodes), sizeof(nedges) };
	PILGRIM_TRACING(int, MPI_Graphdims_get, PMPI_Graphdims_get(comm, nnodes, nedges), 3, sizes, args);
}
int MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges, int index[], int edges[])
{
	void **args = assemble_args_list(5, &comm, &maxindex, &maxedges, &index, &edges);
	int sizes[] = { sizeof(comm), sizeof(maxindex), sizeof(maxedges), sizeof(int), sizeof(int) };
	PILGRIM_TRACING(int, MPI_Graph_get, PMPI_Graph_get(comm, maxindex, maxedges, index, edges), 5, sizes, args);
}
int MPI_Cartdim_get(MPI_Comm comm, int *ndims)
{
	void **args = assemble_args_list(2, &comm, &ndims);
	int sizes[] = { sizeof(comm), sizeof(ndims) };
	PILGRIM_TRACING(int, MPI_Cartdim_get, PMPI_Cartdim_get(comm, ndims), 2, sizes, args);
}
int MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[])
{
	void **args = assemble_args_list(5, &comm, &maxdims, &dims, &periods, &coords);
	int sizes[] = { sizeof(comm), sizeof(maxdims), sizeof(int), sizeof(int), sizeof(int) };
	PILGRIM_TRACING(int, MPI_Cart_get, PMPI_Cart_get(comm, maxdims, dims, periods, coords), 5, sizes, args);
}
int MPI_Cart_rank(MPI_Comm comm, const int coords[], int *rank)
{
	void **args = assemble_args_list(3, &comm, &coords, &rank);
	int sizes[] = { sizeof(comm), sizeof(const int), sizeof(rank) };
	PILGRIM_TRACING(int, MPI_Cart_rank, PMPI_Cart_rank(comm, coords, rank), 3, sizes, args);
}
int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[])
{
	void **args = assemble_args_list(4, &comm, &rank, &maxdims, &coords);
	int sizes[] = { sizeof(comm), sizeof(rank), sizeof(maxdims), sizeof(int) };
	PILGRIM_TRACING(int, MPI_Cart_coords, PMPI_Cart_coords(comm, rank, maxdims, coords), 4, sizes, args);
}
int MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors)
{
	void **args = assemble_args_list(3, &comm, &rank, &nneighbors);
	int sizes[] = { sizeof(comm), sizeof(rank), sizeof(nneighbors) };
	PILGRIM_TRACING(int, MPI_Graph_neighbors_count, PMPI_Graph_neighbors_count(comm, rank, nneighbors), 3, sizes, args);
}
int MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors, int neighbors[])
{
	void **args = assemble_args_list(4, &comm, &rank, &maxneighbors, &neighbors);
	int sizes[] = { sizeof(comm), sizeof(rank), sizeof(maxneighbors), sizeof(int) };
	PILGRIM_TRACING(int, MPI_Graph_neighbors, PMPI_Graph_neighbors(comm, rank, maxneighbors, neighbors), 4, sizes, args);
}
int MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree, int *outdegree, int *weighted)
{
	void **args = assemble_args_list(4, &comm, &indegree, &outdegree, &weighted);
	int sizes[] = { sizeof(comm), sizeof(indegree), sizeof(outdegree), sizeof(weighted) };
	PILGRIM_TRACING(int, MPI_Dist_graph_neighbors_count, PMPI_Dist_graph_neighbors_count(comm, indegree, outdegree, weighted), 4, sizes, args);
}
int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[], int sourceweights[], int maxoutdegree, int destinations[], int destweights[])
{
	void **args = assemble_args_list(7, &comm, &maxindegree, &sources, &sourceweights, &maxoutdegree, &destinations, &destweights);
	int sizes[] = { sizeof(comm), sizeof(maxindegree), sizeof(int), sizeof(int), sizeof(maxoutdegree), sizeof(int), sizeof(int) };
	PILGRIM_TRACING(int, MPI_Dist_graph_neighbors, PMPI_Dist_graph_neighbors(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights), 7, sizes, args);
}
int MPI_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest)
{
	void **args = assemble_args_list(5, &comm, &direction, &disp, &rank_source, &rank_dest);
	int sizes[] = { sizeof(comm), sizeof(direction), sizeof(disp), sizeof(rank_source), sizeof(rank_dest) };
	PILGRIM_TRACING(int, MPI_Cart_shift, PMPI_Cart_shift(comm, direction, disp, rank_source, rank_dest), 5, sizes, args);
}
int MPI_Cart_sub(MPI_Comm comm, const int remain_dims[], MPI_Comm *newcomm)
{
	void **args = assemble_args_list(3, &comm, &remain_dims, &newcomm);
	int sizes[] = { sizeof(comm), sizeof(const int), sizeof(newcomm) };
	PILGRIM_TRACING(int, MPI_Cart_sub, PMPI_Cart_sub(comm, remain_dims, newcomm), 3, sizes, args);
}
int MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[], const int periods[], int *newrank)
{
	void **args = assemble_args_list(5, &comm, &ndims, &dims, &periods, &newrank);
	int sizes[] = { sizeof(comm), sizeof(ndims), sizeof(const int), sizeof(const int), sizeof(newrank) };
	PILGRIM_TRACING(int, MPI_Cart_map, PMPI_Cart_map(comm, ndims, dims, periods, newrank), 5, sizes, args);
}
int MPI_Graph_map(MPI_Comm comm, int nnodes, const int index[], const int edges[], int *newrank)
{
	void **args = assemble_args_list(5, &comm, &nnodes, &index, &edges, &newrank);
	int sizes[] = { sizeof(comm), sizeof(nnodes), sizeof(const int), sizeof(const int), sizeof(newrank) };
	PILGRIM_TRACING(int, MPI_Graph_map, PMPI_Graph_map(comm, nnodes, index, edges, newrank), 5, sizes, args);
}
int MPI_Neighbor_allgather(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
	void **args = assemble_args_list(7, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcount, &recvtype, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(recvcount), sizeof(recvtype), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Neighbor_allgather, PMPI_Neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm), 7, sizes, args);
}
int MPI_Neighbor_allgatherv(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm)
{
	void **args = assemble_args_list(8, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcounts, &displs, &recvtype, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(const int), sizeof(const int), sizeof(recvtype), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Neighbor_allgatherv, PMPI_Neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm), 8, sizes, args);
}
int MPI_Neighbor_alltoall(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
	void **args = assemble_args_list(7, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcount, &recvtype, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(recvcount), sizeof(recvtype), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Neighbor_alltoall, PMPI_Neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm), 7, sizes, args);
}
int MPI_Neighbor_alltoallv(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm)
{
	void **args = assemble_args_list(9, &sendbuf, &sendcounts, &sdispls, &sendtype, &recvbuf, &recvcounts, &rdispls, &recvtype, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(const int), sizeof(const int), sizeof(sendtype), sizeof(recvbuf), sizeof(const int), sizeof(const int), sizeof(recvtype), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Neighbor_alltoallv, PMPI_Neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm), 9, sizes, args);
}
int MPI_Neighbor_alltoallw(const void* sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void* recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm)
{
	void **args = assemble_args_list(9, &sendbuf, &sendcounts, &sdispls, &sendtypes, &recvbuf, &recvcounts, &rdispls, &recvtypes, &comm);
	int sizes[] = { sizeof(sendbuf), sizeof(const int), sizeof(const MPI_Aint), sizeof(const MPI_Datatype), sizeof(recvbuf), sizeof(const int), sizeof(const MPI_Aint), sizeof(const MPI_Datatype), sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Neighbor_alltoallw, PMPI_Neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm), 9, sizes, args);
}
int MPI_Ineighbor_allgather(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(8, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcount, &recvtype, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(recvcount), sizeof(recvtype), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Ineighbor_allgather, PMPI_Ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request), 8, sizes, args);
}
int MPI_Ineighbor_allgatherv(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(9, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcounts, &displs, &recvtype, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(const int), sizeof(const int), sizeof(recvtype), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Ineighbor_allgatherv, PMPI_Ineighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request), 9, sizes, args);
}
int MPI_Ineighbor_alltoall(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(8, &sendbuf, &sendcount, &sendtype, &recvbuf, &recvcount, &recvtype, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(sendcount), sizeof(sendtype), sizeof(recvbuf), sizeof(recvcount), sizeof(recvtype), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Ineighbor_alltoall, PMPI_Ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request), 8, sizes, args);
}
int MPI_Ineighbor_alltoallv(const void* sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void* recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(10, &sendbuf, &sendcounts, &sdispls, &sendtype, &recvbuf, &recvcounts, &rdispls, &recvtype, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(const int), sizeof(const int), sizeof(sendtype), sizeof(recvbuf), sizeof(const int), sizeof(const int), sizeof(recvtype), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Ineighbor_alltoallv, PMPI_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request), 10, sizes, args);
}
int MPI_Ineighbor_alltoallw(const void* sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void* recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request)
{
	void **args = assemble_args_list(10, &sendbuf, &sendcounts, &sdispls, &sendtypes, &recvbuf, &recvcounts, &rdispls, &recvtypes, &comm, &request);
	int sizes[] = { sizeof(sendbuf), sizeof(const int), sizeof(const MPI_Aint), sizeof(const MPI_Datatype), sizeof(recvbuf), sizeof(const int), sizeof(const MPI_Aint), sizeof(const MPI_Datatype), sizeof(comm), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Ineighbor_alltoallw, PMPI_Ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request), 10, sizes, args);
}
int MPI_Get_version(int *version, int *subversion)
{
	void **args = assemble_args_list(2, &version, &subversion);
	int sizes[] = { sizeof(version), sizeof(subversion) };
	PILGRIM_TRACING(int, MPI_Get_version, PMPI_Get_version(version, subversion), 2, sizes, args);
}
int MPI_Get_library_version(char *version, int *resultlen)
{
	void **args = assemble_args_list(2, &version, &resultlen);
	int sizes[] = { sizeof(version), sizeof(resultlen) };
	PILGRIM_TRACING(int, MPI_Get_library_version, PMPI_Get_library_version(version, resultlen), 2, sizes, args);
}
int MPI_Get_processor_name(char *name, int *resultlen)
{
	void **args = assemble_args_list(2, &name, &resultlen);
	int sizes[] = { sizeof(name), sizeof(resultlen) };
	PILGRIM_TRACING(int, MPI_Get_processor_name, PMPI_Get_processor_name(name, resultlen), 2, sizes, args);
}
int MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr)
{
	void **args = assemble_args_list(3, &size, &info, &baseptr);
	int sizes[] = { sizeof(size), sizeof(info), sizeof(baseptr) };
	PILGRIM_TRACING(int, MPI_Alloc_mem, PMPI_Alloc_mem(size, info, baseptr), 3, sizes, args);
}
int MPI_Free_mem(void *base)
{
	void **args = assemble_args_list(1, &base);
	int sizes[] = { sizeof(base) };
	PILGRIM_TRACING(int, MPI_Free_mem, PMPI_Free_mem(base), 1, sizes, args);
}
int MPI_Comm_create_errhandler(MPI_Comm_errhandler_function *comm_errhandler_fn, MPI_Errhandler *errhandler)
{
	void **args = assemble_args_list(2, &comm_errhandler_fn, &errhandler);
	int sizes[] = { sizeof(comm_errhandler_fn), sizeof(errhandler) };
	PILGRIM_TRACING(int, MPI_Comm_create_errhandler, PMPI_Comm_create_errhandler(comm_errhandler_fn, errhandler), 2, sizes, args);
}
int MPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler)
{
	void **args = assemble_args_list(2, &comm, &errhandler);
	int sizes[] = { sizeof(comm), sizeof(errhandler) };
	PILGRIM_TRACING(int, MPI_Comm_set_errhandler, PMPI_Comm_set_errhandler(comm, errhandler), 2, sizes, args);
}
int MPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *errhandler)
{
	void **args = assemble_args_list(2, &comm, &errhandler);
	int sizes[] = { sizeof(comm), sizeof(errhandler) };
	PILGRIM_TRACING(int, MPI_Comm_get_errhandler, PMPI_Comm_get_errhandler(comm, errhandler), 2, sizes, args);
}
int MPI_Win_create_errhandler(MPI_Win_errhandler_function *win_errhandler_fn, MPI_Errhandler *errhandler)
{
	void **args = assemble_args_list(2, &win_errhandler_fn, &errhandler);
	int sizes[] = { sizeof(win_errhandler_fn), sizeof(errhandler) };
	PILGRIM_TRACING(int, MPI_Win_create_errhandler, PMPI_Win_create_errhandler(win_errhandler_fn, errhandler), 2, sizes, args);
}
int MPI_Win_set_errhandler(MPI_Win win, MPI_Errhandler errhandler)
{
	void **args = assemble_args_list(2, &win, &errhandler);
	int sizes[] = { sizeof(win), sizeof(errhandler) };
	PILGRIM_TRACING(int, MPI_Win_set_errhandler, PMPI_Win_set_errhandler(win, errhandler), 2, sizes, args);
}
int MPI_Win_get_errhandler(MPI_Win win, MPI_Errhandler *errhandler)
{
	void **args = assemble_args_list(2, &win, &errhandler);
	int sizes[] = { sizeof(win), sizeof(errhandler) };
	PILGRIM_TRACING(int, MPI_Win_get_errhandler, PMPI_Win_get_errhandler(win, errhandler), 2, sizes, args);
}
int MPI_File_create_errhandler(MPI_File_errhandler_function *file_errhandler_fn, MPI_Errhandler *errhandler)
{
	void **args = assemble_args_list(2, &file_errhandler_fn, &errhandler);
	int sizes[] = { sizeof(file_errhandler_fn), sizeof(errhandler) };
	PILGRIM_TRACING(int, MPI_File_create_errhandler, PMPI_File_create_errhandler(file_errhandler_fn, errhandler), 2, sizes, args);
}
int MPI_File_set_errhandler(MPI_File file, MPI_Errhandler errhandler)
{
	void **args = assemble_args_list(2, &file, &errhandler);
	int sizes[] = { sizeof(file), sizeof(errhandler) };
	PILGRIM_TRACING(int, MPI_File_set_errhandler, PMPI_File_set_errhandler(file, errhandler), 2, sizes, args);
}
int MPI_File_get_errhandler(MPI_File file, MPI_Errhandler *errhandler)
{
	void **args = assemble_args_list(2, &file, &errhandler);
	int sizes[] = { sizeof(file), sizeof(errhandler) };
	PILGRIM_TRACING(int, MPI_File_get_errhandler, PMPI_File_get_errhandler(file, errhandler), 2, sizes, args);
}
int MPI_Errhandler_free(MPI_Errhandler *errhandler)
{
	void **args = assemble_args_list(1, &errhandler);
	int sizes[] = { sizeof(errhandler) };
	PILGRIM_TRACING(int, MPI_Errhandler_free, PMPI_Errhandler_free(errhandler), 1, sizes, args);
}
int MPI_Error_string(int errorcode, char *string, int *resultlen)
{
	void **args = assemble_args_list(3, &errorcode, &string, &resultlen);
	int sizes[] = { sizeof(errorcode), sizeof(string), sizeof(resultlen) };
	PILGRIM_TRACING(int, MPI_Error_string, PMPI_Error_string(errorcode, string, resultlen), 3, sizes, args);
}
int MPI_Error_class(int errorcode, int *errorclass)
{
	void **args = assemble_args_list(2, &errorcode, &errorclass);
	int sizes[] = { sizeof(errorcode), sizeof(errorclass) };
	PILGRIM_TRACING(int, MPI_Error_class, PMPI_Error_class(errorcode, errorclass), 2, sizes, args);
}
int MPI_Add_error_class(int *errorclass)
{
	void **args = assemble_args_list(1, &errorclass);
	int sizes[] = { sizeof(errorclass) };
	PILGRIM_TRACING(int, MPI_Add_error_class, PMPI_Add_error_class(errorclass), 1, sizes, args);
}
int MPI_Add_error_code(int errorclass, int *errorcode)
{
	void **args = assemble_args_list(2, &errorclass, &errorcode);
	int sizes[] = { sizeof(errorclass), sizeof(errorcode) };
	PILGRIM_TRACING(int, MPI_Add_error_code, PMPI_Add_error_code(errorclass, errorcode), 2, sizes, args);
}
int MPI_Add_error_string(int errorcode, const char *string)
{
	void **args = assemble_args_list(2, &errorcode, &string);
	int sizes[] = { sizeof(errorcode), sizeof(string) };
	PILGRIM_TRACING(int, MPI_Add_error_string, PMPI_Add_error_string(errorcode, string), 2, sizes, args);
}
int MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode)
{
	void **args = assemble_args_list(2, &comm, &errorcode);
	int sizes[] = { sizeof(comm), sizeof(errorcode) };
	PILGRIM_TRACING(int, MPI_Comm_call_errhandler, PMPI_Comm_call_errhandler(comm, errorcode), 2, sizes, args);
}
int MPI_Win_call_errhandler(MPI_Win win, int errorcode)
{
	void **args = assemble_args_list(2, &win, &errorcode);
	int sizes[] = { sizeof(win), sizeof(errorcode) };
	PILGRIM_TRACING(int, MPI_Win_call_errhandler, PMPI_Win_call_errhandler(win, errorcode), 2, sizes, args);
}
int MPI_File_call_errhandler(MPI_File fh, int errorcode)
{
	void **args = assemble_args_list(2, &fh, &errorcode);
	int sizes[] = { sizeof(fh), sizeof(errorcode) };
	PILGRIM_TRACING(int, MPI_File_call_errhandler, PMPI_File_call_errhandler(fh, errorcode), 2, sizes, args);
}
double MPI_Wtime(void)
{
	void **args = NULL;
	int* sizes = NULL;
	PILGRIM_TRACING(double, MPI_Wtime, PMPI_Wtime(), 0, sizes, args);
}
double MPI_Wtick(void)
{
	void **args = NULL;
	int* sizes = NULL;
	PILGRIM_TRACING(double, MPI_Wtick, PMPI_Wtick(), 0, sizes, args);
}
int MPI_Initialized(int *flag)
{
	void **args = assemble_args_list(1, &flag);
	int sizes[] = { sizeof(flag) };
	PILGRIM_TRACING(int, MPI_Initialized, PMPI_Initialized(flag), 1, sizes, args);
}
int MPI_Abort(MPI_Comm comm, int errorcode)
{
	void **args = assemble_args_list(2, &comm, &errorcode);
	int sizes[] = { sizeof(comm), sizeof(errorcode) };
	PILGRIM_TRACING(int, MPI_Abort, PMPI_Abort(comm, errorcode), 2, sizes, args);
}
int MPI_Finalized(int *flag)
{
	void **args = assemble_args_list(1, &flag);
	int sizes[] = { sizeof(flag) };
	PILGRIM_TRACING(int, MPI_Finalized, PMPI_Finalized(flag), 1, sizes, args);
}
int MPI_Info_create(MPI_Info *info)
{
	void **args = assemble_args_list(1, &info);
	int sizes[] = { sizeof(info) };
	PILGRIM_TRACING(int, MPI_Info_create, PMPI_Info_create(info), 1, sizes, args);
}
int MPI_Info_set(MPI_Info info, const char *key, const char *value)
{
	void **args = assemble_args_list(3, &info, &key, &value);
	int sizes[] = { sizeof(info), sizeof(key), sizeof(value) };
	PILGRIM_TRACING(int, MPI_Info_set, PMPI_Info_set(info, key, value), 3, sizes, args);
}
int MPI_Info_delete(MPI_Info info, const char *key)
{
	void **args = assemble_args_list(2, &info, &key);
	int sizes[] = { sizeof(info), sizeof(key) };
	PILGRIM_TRACING(int, MPI_Info_delete, PMPI_Info_delete(info, key), 2, sizes, args);
}
int MPI_Info_get(MPI_Info info, const char *key, int valuelen, char *value, int *flag)
{
	void **args = assemble_args_list(5, &info, &key, &valuelen, &value, &flag);
	int sizes[] = { sizeof(info), sizeof(key), sizeof(valuelen), sizeof(value), sizeof(flag) };
	PILGRIM_TRACING(int, MPI_Info_get, PMPI_Info_get(info, key, valuelen, value, flag), 5, sizes, args);
}
int MPI_Info_get_valuelen(MPI_Info info, const char *key, int *valuelen, int *flag)
{
	void **args = assemble_args_list(4, &info, &key, &valuelen, &flag);
	int sizes[] = { sizeof(info), sizeof(key), sizeof(valuelen), sizeof(flag) };
	PILGRIM_TRACING(int, MPI_Info_get_valuelen, PMPI_Info_get_valuelen(info, key, valuelen, flag), 4, sizes, args);
}
int MPI_Info_get_nkeys(MPI_Info info, int *nkeys)
{
	void **args = assemble_args_list(2, &info, &nkeys);
	int sizes[] = { sizeof(info), sizeof(nkeys) };
	PILGRIM_TRACING(int, MPI_Info_get_nkeys, PMPI_Info_get_nkeys(info, nkeys), 2, sizes, args);
}
int MPI_Info_get_nthkey(MPI_Info info, int n, char *key)
{
	void **args = assemble_args_list(3, &info, &n, &key);
	int sizes[] = { sizeof(info), sizeof(n), sizeof(key) };
	PILGRIM_TRACING(int, MPI_Info_get_nthkey, PMPI_Info_get_nthkey(info, n, key), 3, sizes, args);
}
int MPI_Info_dup(MPI_Info info, MPI_Info *newinfo)
{
	void **args = assemble_args_list(2, &info, &newinfo);
	int sizes[] = { sizeof(info), sizeof(newinfo) };
	PILGRIM_TRACING(int, MPI_Info_dup, PMPI_Info_dup(info, newinfo), 2, sizes, args);
}
int MPI_Info_free(MPI_Info *info)
{
	void **args = assemble_args_list(1, &info);
	int sizes[] = { sizeof(info) };
	PILGRIM_TRACING(int, MPI_Info_free, PMPI_Info_free(info), 1, sizes, args);
}
int MPI_Comm_spawn(const char *command, char *argv[], int maxprocs, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
{
	void **args = assemble_args_list(8, &command, &argv, &maxprocs, &info, &root, &comm, &intercomm, &array_of_errcodes);
	int sizes[] = { sizeof(command), sizeof(char*), sizeof(maxprocs), sizeof(info), sizeof(root), sizeof(comm), sizeof(intercomm), sizeof(int) };
	PILGRIM_TRACING(int, MPI_Comm_spawn, PMPI_Comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes), 8, sizes, args);
}
int MPI_Comm_get_parent(MPI_Comm *parent)
{
	void **args = assemble_args_list(1, &parent);
	int sizes[] = { sizeof(parent) };
	PILGRIM_TRACING(int, MPI_Comm_get_parent, PMPI_Comm_get_parent(parent), 1, sizes, args);
}
int MPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[], const int array_of_maxprocs[], const MPI_Info array_of_info[], int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
{
	void **args = assemble_args_list(9, &count, &array_of_commands, &array_of_argv, &array_of_maxprocs, &array_of_info, &root, &comm, &intercomm, &array_of_errcodes);
	int sizes[] = { sizeof(count), sizeof(char*), sizeof(char*), sizeof(const int), sizeof(const MPI_Info), sizeof(root), sizeof(comm), sizeof(intercomm), sizeof(int) };
	PILGRIM_TRACING(int, MPI_Comm_spawn_multiple, PMPI_Comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes), 9, sizes, args);
}
int MPI_Open_port(MPI_Info info, char *port_name)
{
	void **args = assemble_args_list(2, &info, &port_name);
	int sizes[] = { sizeof(info), sizeof(port_name) };
	PILGRIM_TRACING(int, MPI_Open_port, PMPI_Open_port(info, port_name), 2, sizes, args);
}
int MPI_Close_port(const char *port_name)
{
	void **args = assemble_args_list(1, &port_name);
	int sizes[] = { sizeof(port_name) };
	PILGRIM_TRACING(int, MPI_Close_port, PMPI_Close_port(port_name), 1, sizes, args);
}
int MPI_Comm_accept(const char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm)
{
	void **args = assemble_args_list(5, &port_name, &info, &root, &comm, &newcomm);
	int sizes[] = { sizeof(port_name), sizeof(info), sizeof(root), sizeof(comm), sizeof(newcomm) };
	PILGRIM_TRACING(int, MPI_Comm_accept, PMPI_Comm_accept(port_name, info, root, comm, newcomm), 5, sizes, args);
}
int MPI_Comm_connect(const char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm)
{
	void **args = assemble_args_list(5, &port_name, &info, &root, &comm, &newcomm);
	int sizes[] = { sizeof(port_name), sizeof(info), sizeof(root), sizeof(comm), sizeof(newcomm) };
	PILGRIM_TRACING(int, MPI_Comm_connect, PMPI_Comm_connect(port_name, info, root, comm, newcomm), 5, sizes, args);
}
int MPI_Publish_name(const char *service_name, MPI_Info info, const char *port_name)
{
	void **args = assemble_args_list(3, &service_name, &info, &port_name);
	int sizes[] = { sizeof(service_name), sizeof(info), sizeof(port_name) };
	PILGRIM_TRACING(int, MPI_Publish_name, PMPI_Publish_name(service_name, info, port_name), 3, sizes, args);
}
int MPI_Unpublish_name(const char *service_name, MPI_Info info, const char *port_name)
{
	void **args = assemble_args_list(3, &service_name, &info, &port_name);
	int sizes[] = { sizeof(service_name), sizeof(info), sizeof(port_name) };
	PILGRIM_TRACING(int, MPI_Unpublish_name, PMPI_Unpublish_name(service_name, info, port_name), 3, sizes, args);
}
int MPI_Lookup_name(const char *service_name, MPI_Info info, char *port_name)
{
	void **args = assemble_args_list(3, &service_name, &info, &port_name);
	int sizes[] = { sizeof(service_name), sizeof(info), sizeof(port_name) };
	PILGRIM_TRACING(int, MPI_Lookup_name, PMPI_Lookup_name(service_name, info, port_name), 3, sizes, args);
}
int MPI_Comm_disconnect(MPI_Comm *comm)
{
	void **args = assemble_args_list(1, &comm);
	int sizes[] = { sizeof(comm) };
	PILGRIM_TRACING(int, MPI_Comm_disconnect, PMPI_Comm_disconnect(comm), 1, sizes, args);
}
int MPI_Comm_join(int fd, MPI_Comm *intercomm)
{
	void **args = assemble_args_list(2, &fd, &intercomm);
	int sizes[] = { sizeof(fd), sizeof(intercomm) };
	PILGRIM_TRACING(int, MPI_Comm_join, PMPI_Comm_join(fd, intercomm), 2, sizes, args);
}
int MPI_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win)
{
	void **args = assemble_args_list(6, &base, &size, &disp_unit, &info, &comm, &win);
	int sizes[] = { sizeof(base), sizeof(size), sizeof(disp_unit), sizeof(info), sizeof(comm), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_create, PMPI_Win_create(base, size, disp_unit, info, comm, win), 6, sizes, args);
}
int MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win)
{
	void **args = assemble_args_list(6, &size, &disp_unit, &info, &comm, &baseptr, &win);
	int sizes[] = { sizeof(size), sizeof(disp_unit), sizeof(info), sizeof(comm), sizeof(baseptr), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_allocate, PMPI_Win_allocate(size, disp_unit, info, comm, baseptr, win), 6, sizes, args);
}
int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win)
{
	void **args = assemble_args_list(6, &size, &disp_unit, &info, &comm, &baseptr, &win);
	int sizes[] = { sizeof(size), sizeof(disp_unit), sizeof(info), sizeof(comm), sizeof(baseptr), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_allocate_shared, PMPI_Win_allocate_shared(size, disp_unit, info, comm, baseptr, win), 6, sizes, args);
}
int MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit, void *baseptr)
{
	void **args = assemble_args_list(5, &win, &rank, &size, &disp_unit, &baseptr);
	int sizes[] = { sizeof(win), sizeof(rank), sizeof(size), sizeof(disp_unit), sizeof(baseptr) };
	PILGRIM_TRACING(int, MPI_Win_shared_query, PMPI_Win_shared_query(win, rank, size, disp_unit, baseptr), 5, sizes, args);
}
int MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win)
{
	void **args = assemble_args_list(3, &info, &comm, &win);
	int sizes[] = { sizeof(info), sizeof(comm), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_create_dynamic, PMPI_Win_create_dynamic(info, comm, win), 3, sizes, args);
}
int MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size)
{
	void **args = assemble_args_list(3, &win, &base, &size);
	int sizes[] = { sizeof(win), sizeof(base), sizeof(size) };
	PILGRIM_TRACING(int, MPI_Win_attach, PMPI_Win_attach(win, base, size), 3, sizes, args);
}
int MPI_Win_detach(MPI_Win win, const void *base)
{
	void **args = assemble_args_list(2, &win, &base);
	int sizes[] = { sizeof(win), sizeof(base) };
	PILGRIM_TRACING(int, MPI_Win_detach, PMPI_Win_detach(win, base), 2, sizes, args);
}
int MPI_Win_free(MPI_Win *win)
{
	void **args = assemble_args_list(1, &win);
	int sizes[] = { sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_free, PMPI_Win_free(win), 1, sizes, args);
}
int MPI_Win_get_group(MPI_Win win, MPI_Group *group)
{
	void **args = assemble_args_list(2, &win, &group);
	int sizes[] = { sizeof(win), sizeof(group) };
	PILGRIM_TRACING(int, MPI_Win_get_group, PMPI_Win_get_group(win, group), 2, sizes, args);
}
int MPI_Win_set_info(MPI_Win win, MPI_Info info)
{
	void **args = assemble_args_list(2, &win, &info);
	int sizes[] = { sizeof(win), sizeof(info) };
	PILGRIM_TRACING(int, MPI_Win_set_info, PMPI_Win_set_info(win, info), 2, sizes, args);
}
int MPI_Win_get_info(MPI_Win win, MPI_Info *info_used)
{
	void **args = assemble_args_list(2, &win, &info_used);
	int sizes[] = { sizeof(win), sizeof(info_used) };
	PILGRIM_TRACING(int, MPI_Win_get_info, PMPI_Win_get_info(win, info_used), 2, sizes, args);
}
int MPI_Put(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win)
{
	void **args = assemble_args_list(8, &origin_addr, &origin_count, &origin_datatype, &target_rank, &target_disp, &target_count, &target_datatype, &win);
	int sizes[] = { sizeof(origin_addr), sizeof(origin_count), sizeof(origin_datatype), sizeof(target_rank), sizeof(target_disp), sizeof(target_count), sizeof(target_datatype), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Put, PMPI_Put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win), 8, sizes, args);
}
int MPI_Get(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win)
{
	void **args = assemble_args_list(8, &origin_addr, &origin_count, &origin_datatype, &target_rank, &target_disp, &target_count, &target_datatype, &win);
	int sizes[] = { sizeof(origin_addr), sizeof(origin_count), sizeof(origin_datatype), sizeof(target_rank), sizeof(target_disp), sizeof(target_count), sizeof(target_datatype), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Get, PMPI_Get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win), 8, sizes, args);
}
int MPI_Accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win)
{
	void **args = assemble_args_list(9, &origin_addr, &origin_count, &origin_datatype, &target_rank, &target_disp, &target_count, &target_datatype, &op, &win);
	int sizes[] = { sizeof(origin_addr), sizeof(origin_count), sizeof(origin_datatype), sizeof(target_rank), sizeof(target_disp), sizeof(target_count), sizeof(target_datatype), sizeof(op), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Accumulate, PMPI_Accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win), 9, sizes, args);
}
int MPI_Get_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win)
{
	void **args = assemble_args_list(12, &origin_addr, &origin_count, &origin_datatype, &result_addr, &result_count, &result_datatype, &target_rank, &target_disp, &target_count, &target_datatype, &op, &win);
	int sizes[] = { sizeof(origin_addr), sizeof(origin_count), sizeof(origin_datatype), sizeof(result_addr), sizeof(result_count), sizeof(result_datatype), sizeof(target_rank), sizeof(target_disp), sizeof(target_count), sizeof(target_datatype), sizeof(op), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Get_accumulate, PMPI_Get_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win), 12, sizes, args);
}
int MPI_Fetch_and_op(const void *origin_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Op op, MPI_Win win)
{
	void **args = assemble_args_list(7, &origin_addr, &result_addr, &datatype, &target_rank, &target_disp, &op, &win);
	int sizes[] = { sizeof(origin_addr), sizeof(result_addr), sizeof(datatype), sizeof(target_rank), sizeof(target_disp), sizeof(op), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Fetch_and_op, PMPI_Fetch_and_op(origin_addr, result_addr, datatype, target_rank, target_disp, op, win), 7, sizes, args);
}
int MPI_Compare_and_swap(const void *origin_addr, const void *compare_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Win win)
{
	void **args = assemble_args_list(7, &origin_addr, &compare_addr, &result_addr, &datatype, &target_rank, &target_disp, &win);
	int sizes[] = { sizeof(origin_addr), sizeof(compare_addr), sizeof(result_addr), sizeof(datatype), sizeof(target_rank), sizeof(target_disp), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Compare_and_swap, PMPI_Compare_and_swap(origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win), 7, sizes, args);
}
int MPI_Rput(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request)
{
	void **args = assemble_args_list(9, &origin_addr, &origin_count, &origin_datatype, &target_rank, &target_disp, &target_count, &target_datatype, &win, &request);
	int sizes[] = { sizeof(origin_addr), sizeof(origin_count), sizeof(origin_datatype), sizeof(target_rank), sizeof(target_disp), sizeof(target_count), sizeof(target_datatype), sizeof(win), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Rput, PMPI_Rput(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request), 9, sizes, args);
}
int MPI_Rget(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request)
{
	void **args = assemble_args_list(9, &origin_addr, &origin_count, &origin_datatype, &target_rank, &target_disp, &target_count, &target_datatype, &win, &request);
	int sizes[] = { sizeof(origin_addr), sizeof(origin_count), sizeof(origin_datatype), sizeof(target_rank), sizeof(target_disp), sizeof(target_count), sizeof(target_datatype), sizeof(win), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Rget, PMPI_Rget(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request), 9, sizes, args);
}
int MPI_Raccumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request)
{
	void **args = assemble_args_list(10, &origin_addr, &origin_count, &origin_datatype, &target_rank, &target_disp, &target_count, &target_datatype, &op, &win, &request);
	int sizes[] = { sizeof(origin_addr), sizeof(origin_count), sizeof(origin_datatype), sizeof(target_rank), sizeof(target_disp), sizeof(target_count), sizeof(target_datatype), sizeof(op), sizeof(win), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Raccumulate, PMPI_Raccumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request), 10, sizes, args);
}
int MPI_Rget_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request)
{
	void **args = assemble_args_list(13, &origin_addr, &origin_count, &origin_datatype, &result_addr, &result_count, &result_datatype, &target_rank, &target_disp, &target_count, &target_datatype, &op, &win, &request);
	int sizes[] = { sizeof(origin_addr), sizeof(origin_count), sizeof(origin_datatype), sizeof(result_addr), sizeof(result_count), sizeof(result_datatype), sizeof(target_rank), sizeof(target_disp), sizeof(target_count), sizeof(target_datatype), sizeof(op), sizeof(win), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Rget_accumulate, PMPI_Rget_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request), 13, sizes, args);
}
int MPI_Win_fence(int assert, MPI_Win win)
{
	void **args = assemble_args_list(2, &assert, &win);
	int sizes[] = { sizeof(assert), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_fence, PMPI_Win_fence(assert, win), 2, sizes, args);
}
int MPI_Win_start(MPI_Group group, int assert, MPI_Win win)
{
	void **args = assemble_args_list(3, &group, &assert, &win);
	int sizes[] = { sizeof(group), sizeof(assert), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_start, PMPI_Win_start(group, assert, win), 3, sizes, args);
}
int MPI_Win_complete(MPI_Win win)
{
	void **args = assemble_args_list(1, &win);
	int sizes[] = { sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_complete, PMPI_Win_complete(win), 1, sizes, args);
}
int MPI_Win_post(MPI_Group group, int assert, MPI_Win win)
{
	void **args = assemble_args_list(3, &group, &assert, &win);
	int sizes[] = { sizeof(group), sizeof(assert), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_post, PMPI_Win_post(group, assert, win), 3, sizes, args);
}
int MPI_Win_wait(MPI_Win win)
{
	void **args = assemble_args_list(1, &win);
	int sizes[] = { sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_wait, PMPI_Win_wait(win), 1, sizes, args);
}
int MPI_Win_test(MPI_Win win, int *flag)
{
	void **args = assemble_args_list(2, &win, &flag);
	int sizes[] = { sizeof(win), sizeof(flag) };
	PILGRIM_TRACING(int, MPI_Win_test, PMPI_Win_test(win, flag), 2, sizes, args);
}
int MPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win)
{
	void **args = assemble_args_list(4, &lock_type, &rank, &assert, &win);
	int sizes[] = { sizeof(lock_type), sizeof(rank), sizeof(assert), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_lock, PMPI_Win_lock(lock_type, rank, assert, win), 4, sizes, args);
}
int MPI_Win_lock_all(int assert, MPI_Win win)
{
	void **args = assemble_args_list(2, &assert, &win);
	int sizes[] = { sizeof(assert), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_lock_all, PMPI_Win_lock_all(assert, win), 2, sizes, args);
}
int MPI_Win_unlock(int rank, MPI_Win win)
{
	void **args = assemble_args_list(2, &rank, &win);
	int sizes[] = { sizeof(rank), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_unlock, PMPI_Win_unlock(rank, win), 2, sizes, args);
}
int MPI_Win_unlock_all(MPI_Win win)
{
	void **args = assemble_args_list(1, &win);
	int sizes[] = { sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_unlock_all, PMPI_Win_unlock_all(win), 1, sizes, args);
}
int MPI_Win_flush(int rank, MPI_Win win)
{
	void **args = assemble_args_list(2, &rank, &win);
	int sizes[] = { sizeof(rank), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_flush, PMPI_Win_flush(rank, win), 2, sizes, args);
}
int MPI_Win_flush_all(MPI_Win win)
{
	void **args = assemble_args_list(1, &win);
	int sizes[] = { sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_flush_all, PMPI_Win_flush_all(win), 1, sizes, args);
}
int MPI_Win_flush_local(int rank, MPI_Win win)
{
	void **args = assemble_args_list(2, &rank, &win);
	int sizes[] = { sizeof(rank), sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_flush_local, PMPI_Win_flush_local(rank, win), 2, sizes, args);
}
int MPI_Win_flush_local_all(MPI_Win win)
{
	void **args = assemble_args_list(1, &win);
	int sizes[] = { sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_flush_local_all, PMPI_Win_flush_local_all(win), 1, sizes, args);
}
int MPI_Win_sync(MPI_Win win)
{
	void **args = assemble_args_list(1, &win);
	int sizes[] = { sizeof(win) };
	PILGRIM_TRACING(int, MPI_Win_sync, PMPI_Win_sync(win), 1, sizes, args);
}
int MPI_Grequest_start(MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn, MPI_Grequest_cancel_function *cancel_fn, void *extra_state, MPI_Request *request)
{
	void **args = assemble_args_list(5, &query_fn, &free_fn, &cancel_fn, &extra_state, &request);
	int sizes[] = { sizeof(query_fn), sizeof(free_fn), sizeof(cancel_fn), sizeof(extra_state), sizeof(request) };
	PILGRIM_TRACING(int, MPI_Grequest_start, PMPI_Grequest_start(query_fn, free_fn, cancel_fn, extra_state, request), 5, sizes, args);
}
int MPI_Grequest_complete(MPI_Request request)
{
	void **args = assemble_args_list(1, &request);
	int sizes[] = { sizeof(request) };
	PILGRIM_TRACING(int, MPI_Grequest_complete, PMPI_Grequest_complete(request), 1, sizes, args);
}
int MPI_Status_set_elements(MPI_Status *status, MPI_Datatype datatype, int count)
{
	void **args = assemble_args_list(3, &status, &datatype, &count);
	int sizes[] = { sizeof(status), sizeof(datatype), sizeof(count) };
	PILGRIM_TRACING(int, MPI_Status_set_elements, PMPI_Status_set_elements(status, datatype, count), 3, sizes, args);
}
int MPI_Status_set_elements_x(MPI_Status *status, MPI_Datatype datatype, MPI_Count count)
{
	void **args = assemble_args_list(3, &status, &datatype, &count);
	int sizes[] = { sizeof(status), sizeof(datatype), sizeof(count) };
	PILGRIM_TRACING(int, MPI_Status_set_elements_x, PMPI_Status_set_elements_x(status, datatype, count), 3, sizes, args);
}
int MPI_Status_set_cancelled(MPI_Status *status, int flag)
{
	void **args = assemble_args_list(2, &status, &flag);
	int sizes[] = { sizeof(status), sizeof(flag) };
	PILGRIM_TRACING(int, MPI_Status_set_cancelled, PMPI_Status_set_cancelled(status, flag), 2, sizes, args);
}
int MPI_Query_thread(int *provided)
{
	void **args = assemble_args_list(1, &provided);
	int sizes[] = { sizeof(provided) };
	PILGRIM_TRACING(int, MPI_Query_thread, PMPI_Query_thread(provided), 1, sizes, args);
}
int MPI_Is_thread_main(int *flag)
{
	void **args = assemble_args_list(1, &flag);
	int sizes[] = { sizeof(flag) };
	PILGRIM_TRACING(int, MPI_Is_thread_main, PMPI_Is_thread_main(flag), 1, sizes, args);
}
int MPI_File_open(MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh)
{
	void **args = assemble_args_list(5, &comm, &filename, &amode, &info, &fh);
	int sizes[] = { sizeof(comm), sizeof(filename), sizeof(amode), sizeof(info), sizeof(fh) };
	PILGRIM_TRACING(int, MPI_File_open, PMPI_File_open(comm, filename, amode, info, fh), 5, sizes, args);
}
int MPI_File_close(MPI_File *fh)
{
	void **args = assemble_args_list(1, &fh);
	int sizes[] = { sizeof(fh) };
	PILGRIM_TRACING(int, MPI_File_close, PMPI_File_close(fh), 1, sizes, args);
}
int MPI_File_delete(const char *filename, MPI_Info info)
{
	void **args = assemble_args_list(2, &filename, &info);
	int sizes[] = { sizeof(filename), sizeof(info) };
	PILGRIM_TRACING(int, MPI_File_delete, PMPI_File_delete(filename, info), 2, sizes, args);
}
int MPI_File_set_size(MPI_File fh, MPI_Offset size)
{
	void **args = assemble_args_list(2, &fh, &size);
	int sizes[] = { sizeof(fh), sizeof(size) };
	PILGRIM_TRACING(int, MPI_File_set_size, PMPI_File_set_size(fh, size), 2, sizes, args);
}
int MPI_File_preallocate(MPI_File fh, MPI_Offset size)
{
	void **args = assemble_args_list(2, &fh, &size);
	int sizes[] = { sizeof(fh), sizeof(size) };
	PILGRIM_TRACING(int, MPI_File_preallocate, PMPI_File_preallocate(fh, size), 2, sizes, args);
}
int MPI_File_get_size(MPI_File fh, MPI_Offset *size)
{
	void **args = assemble_args_list(2, &fh, &size);
	int sizes[] = { sizeof(fh), sizeof(size) };
	PILGRIM_TRACING(int, MPI_File_get_size, PMPI_File_get_size(fh, size), 2, sizes, args);
}
int MPI_File_get_group(MPI_File fh, MPI_Group *group)
{
	void **args = assemble_args_list(2, &fh, &group);
	int sizes[] = { sizeof(fh), sizeof(group) };
	PILGRIM_TRACING(int, MPI_File_get_group, PMPI_File_get_group(fh, group), 2, sizes, args);
}
int MPI_File_get_amode(MPI_File fh, int *amode)
{
	void **args = assemble_args_list(2, &fh, &amode);
	int sizes[] = { sizeof(fh), sizeof(amode) };
	PILGRIM_TRACING(int, MPI_File_get_amode, PMPI_File_get_amode(fh, amode), 2, sizes, args);
}
int MPI_File_set_info(MPI_File fh, MPI_Info info)
{
	void **args = assemble_args_list(2, &fh, &info);
	int sizes[] = { sizeof(fh), sizeof(info) };
	PILGRIM_TRACING(int, MPI_File_set_info, PMPI_File_set_info(fh, info), 2, sizes, args);
}
int MPI_File_get_info(MPI_File fh, MPI_Info *info_used)
{
	void **args = assemble_args_list(2, &fh, &info_used);
	int sizes[] = { sizeof(fh), sizeof(info_used) };
	PILGRIM_TRACING(int, MPI_File_get_info, PMPI_File_get_info(fh, info_used), 2, sizes, args);
}
int MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, const char *datarep, MPI_Info info)
{
	void **args = assemble_args_list(6, &fh, &disp, &etype, &filetype, &datarep, &info);
	int sizes[] = { sizeof(fh), sizeof(disp), sizeof(etype), sizeof(filetype), sizeof(datarep), sizeof(info) };
	PILGRIM_TRACING(int, MPI_File_set_view, PMPI_File_set_view(fh, disp, etype, filetype, datarep, info), 6, sizes, args);
}
int MPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype, char *datarep)
{
	void **args = assemble_args_list(5, &fh, &disp, &etype, &filetype, &datarep);
	int sizes[] = { sizeof(fh), sizeof(disp), sizeof(etype), sizeof(filetype), sizeof(datarep) };
	PILGRIM_TRACING(int, MPI_File_get_view, PMPI_File_get_view(fh, disp, etype, filetype, datarep), 5, sizes, args);
}
int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	void **args = assemble_args_list(6, &fh, &offset, &buf, &count, &datatype, &status);
	int sizes[] = { sizeof(fh), sizeof(offset), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_read_at, PMPI_File_read_at(fh, offset, buf, count, datatype, status), 6, sizes, args);
}
int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	void **args = assemble_args_list(6, &fh, &offset, &buf, &count, &datatype, &status);
	int sizes[] = { sizeof(fh), sizeof(offset), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_read_at_all, PMPI_File_read_at_all(fh, offset, buf, count, datatype, status), 6, sizes, args);
}
int MPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	void **args = assemble_args_list(6, &fh, &offset, &buf, &count, &datatype, &status);
	int sizes[] = { sizeof(fh), sizeof(offset), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_write_at, PMPI_File_write_at(fh, offset, buf, count, datatype, status), 6, sizes, args);
}
int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	void **args = assemble_args_list(6, &fh, &offset, &buf, &count, &datatype, &status);
	int sizes[] = { sizeof(fh), sizeof(offset), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_write_at_all, PMPI_File_write_at_all(fh, offset, buf, count, datatype, status), 6, sizes, args);
}
int MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	void **args = assemble_args_list(6, &fh, &offset, &buf, &count, &datatype, &request);
	int sizes[] = { sizeof(fh), sizeof(offset), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(request) };
	PILGRIM_TRACING(int, MPI_File_iread_at, PMPI_File_iread_at(fh, offset, buf, count, datatype, request), 6, sizes, args);
}
int MPI_File_iread_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	void **args = assemble_args_list(6, &fh, &offset, &buf, &count, &datatype, &request);
	int sizes[] = { sizeof(fh), sizeof(offset), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(request) };
	PILGRIM_TRACING(int, MPI_File_iread_at_all, PMPI_File_iread_at_all(fh, offset, buf, count, datatype, request), 6, sizes, args);
}
int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	void **args = assemble_args_list(6, &fh, &offset, &buf, &count, &datatype, &request);
	int sizes[] = { sizeof(fh), sizeof(offset), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(request) };
	PILGRIM_TRACING(int, MPI_File_iwrite_at, PMPI_File_iwrite_at(fh, offset, buf, count, datatype, request), 6, sizes, args);
}
int MPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	void **args = assemble_args_list(6, &fh, &offset, &buf, &count, &datatype, &request);
	int sizes[] = { sizeof(fh), sizeof(offset), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(request) };
	PILGRIM_TRACING(int, MPI_File_iwrite_at_all, PMPI_File_iwrite_at_all(fh, offset, buf, count, datatype, request), 6, sizes, args);
}
int MPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	void **args = assemble_args_list(5, &fh, &buf, &count, &datatype, &status);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_read, PMPI_File_read(fh, buf, count, datatype, status), 5, sizes, args);
}
int MPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	void **args = assemble_args_list(5, &fh, &buf, &count, &datatype, &status);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_read_all, PMPI_File_read_all(fh, buf, count, datatype, status), 5, sizes, args);
}
int MPI_File_write(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	void **args = assemble_args_list(5, &fh, &buf, &count, &datatype, &status);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_write, PMPI_File_write(fh, buf, count, datatype, status), 5, sizes, args);
}
int MPI_File_write_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	void **args = assemble_args_list(5, &fh, &buf, &count, &datatype, &status);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_write_all, PMPI_File_write_all(fh, buf, count, datatype, status), 5, sizes, args);
}
int MPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	void **args = assemble_args_list(5, &fh, &buf, &count, &datatype, &request);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(request) };
	PILGRIM_TRACING(int, MPI_File_iread, PMPI_File_iread(fh, buf, count, datatype, request), 5, sizes, args);
}
int MPI_File_iread_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	void **args = assemble_args_list(5, &fh, &buf, &count, &datatype, &request);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(request) };
	PILGRIM_TRACING(int, MPI_File_iread_all, PMPI_File_iread_all(fh, buf, count, datatype, request), 5, sizes, args);
}
int MPI_File_iwrite(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	void **args = assemble_args_list(5, &fh, &buf, &count, &datatype, &request);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(request) };
	PILGRIM_TRACING(int, MPI_File_iwrite, PMPI_File_iwrite(fh, buf, count, datatype, request), 5, sizes, args);
}
int MPI_File_iwrite_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	void **args = assemble_args_list(5, &fh, &buf, &count, &datatype, &request);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(request) };
	PILGRIM_TRACING(int, MPI_File_iwrite_all, PMPI_File_iwrite_all(fh, buf, count, datatype, request), 5, sizes, args);
}
int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence)
{
	void **args = assemble_args_list(3, &fh, &offset, &whence);
	int sizes[] = { sizeof(fh), sizeof(offset), sizeof(whence) };
	PILGRIM_TRACING(int, MPI_File_seek, PMPI_File_seek(fh, offset, whence), 3, sizes, args);
}
int MPI_File_get_position(MPI_File fh, MPI_Offset *offset)
{
	void **args = assemble_args_list(2, &fh, &offset);
	int sizes[] = { sizeof(fh), sizeof(offset) };
	PILGRIM_TRACING(int, MPI_File_get_position, PMPI_File_get_position(fh, offset), 2, sizes, args);
}
int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp)
{
	void **args = assemble_args_list(3, &fh, &offset, &disp);
	int sizes[] = { sizeof(fh), sizeof(offset), sizeof(disp) };
	PILGRIM_TRACING(int, MPI_File_get_byte_offset, PMPI_File_get_byte_offset(fh, offset, disp), 3, sizes, args);
}
int MPI_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	void **args = assemble_args_list(5, &fh, &buf, &count, &datatype, &status);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_read_shared, PMPI_File_read_shared(fh, buf, count, datatype, status), 5, sizes, args);
}
int MPI_File_write_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	void **args = assemble_args_list(5, &fh, &buf, &count, &datatype, &status);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_write_shared, PMPI_File_write_shared(fh, buf, count, datatype, status), 5, sizes, args);
}
int MPI_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	void **args = assemble_args_list(5, &fh, &buf, &count, &datatype, &request);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(request) };
	PILGRIM_TRACING(int, MPI_File_iread_shared, PMPI_File_iread_shared(fh, buf, count, datatype, request), 5, sizes, args);
}
int MPI_File_iwrite_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
	void **args = assemble_args_list(5, &fh, &buf, &count, &datatype, &request);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(request) };
	PILGRIM_TRACING(int, MPI_File_iwrite_shared, PMPI_File_iwrite_shared(fh, buf, count, datatype, request), 5, sizes, args);
}
int MPI_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	void **args = assemble_args_list(5, &fh, &buf, &count, &datatype, &status);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_read_ordered, PMPI_File_read_ordered(fh, buf, count, datatype, status), 5, sizes, args);
}
int MPI_File_write_ordered(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
	void **args = assemble_args_list(5, &fh, &buf, &count, &datatype, &status);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_write_ordered, PMPI_File_write_ordered(fh, buf, count, datatype, status), 5, sizes, args);
}
int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence)
{
	void **args = assemble_args_list(3, &fh, &offset, &whence);
	int sizes[] = { sizeof(fh), sizeof(offset), sizeof(whence) };
	PILGRIM_TRACING(int, MPI_File_seek_shared, PMPI_File_seek_shared(fh, offset, whence), 3, sizes, args);
}
int MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset)
{
	void **args = assemble_args_list(2, &fh, &offset);
	int sizes[] = { sizeof(fh), sizeof(offset) };
	PILGRIM_TRACING(int, MPI_File_get_position_shared, PMPI_File_get_position_shared(fh, offset), 2, sizes, args);
}
int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype)
{
	void **args = assemble_args_list(5, &fh, &offset, &buf, &count, &datatype);
	int sizes[] = { sizeof(fh), sizeof(offset), sizeof(buf), sizeof(count), sizeof(datatype) };
	PILGRIM_TRACING(int, MPI_File_read_at_all_begin, PMPI_File_read_at_all_begin(fh, offset, buf, count, datatype), 5, sizes, args);
}
int MPI_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status)
{
	void **args = assemble_args_list(3, &fh, &buf, &status);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_read_at_all_end, PMPI_File_read_at_all_end(fh, buf, status), 3, sizes, args);
}
int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype)
{
	void **args = assemble_args_list(5, &fh, &offset, &buf, &count, &datatype);
	int sizes[] = { sizeof(fh), sizeof(offset), sizeof(buf), sizeof(count), sizeof(datatype) };
	PILGRIM_TRACING(int, MPI_File_write_at_all_begin, PMPI_File_write_at_all_begin(fh, offset, buf, count, datatype), 5, sizes, args);
}
int MPI_File_write_at_all_end(MPI_File fh, const void *buf, MPI_Status *status)
{
	void **args = assemble_args_list(3, &fh, &buf, &status);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_write_at_all_end, PMPI_File_write_at_all_end(fh, buf, status), 3, sizes, args);
}
int MPI_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype)
{
	void **args = assemble_args_list(4, &fh, &buf, &count, &datatype);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype) };
	PILGRIM_TRACING(int, MPI_File_read_all_begin, PMPI_File_read_all_begin(fh, buf, count, datatype), 4, sizes, args);
}
int MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status)
{
	void **args = assemble_args_list(3, &fh, &buf, &status);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_read_all_end, PMPI_File_read_all_end(fh, buf, status), 3, sizes, args);
}
int MPI_File_write_all_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype)
{
	void **args = assemble_args_list(4, &fh, &buf, &count, &datatype);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype) };
	PILGRIM_TRACING(int, MPI_File_write_all_begin, PMPI_File_write_all_begin(fh, buf, count, datatype), 4, sizes, args);
}
int MPI_File_write_all_end(MPI_File fh, const void *buf, MPI_Status *status)
{
	void **args = assemble_args_list(3, &fh, &buf, &status);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_write_all_end, PMPI_File_write_all_end(fh, buf, status), 3, sizes, args);
}
int MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype)
{
	void **args = assemble_args_list(4, &fh, &buf, &count, &datatype);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype) };
	PILGRIM_TRACING(int, MPI_File_read_ordered_begin, PMPI_File_read_ordered_begin(fh, buf, count, datatype), 4, sizes, args);
}
int MPI_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status)
{
	void **args = assemble_args_list(3, &fh, &buf, &status);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_read_ordered_end, PMPI_File_read_ordered_end(fh, buf, status), 3, sizes, args);
}
int MPI_File_write_ordered_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype)
{
	void **args = assemble_args_list(4, &fh, &buf, &count, &datatype);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(count), sizeof(datatype) };
	PILGRIM_TRACING(int, MPI_File_write_ordered_begin, PMPI_File_write_ordered_begin(fh, buf, count, datatype), 4, sizes, args);
}
int MPI_File_write_ordered_end(MPI_File fh, const void *buf, MPI_Status *status)
{
	void **args = assemble_args_list(3, &fh, &buf, &status);
	int sizes[] = { sizeof(fh), sizeof(buf), sizeof(status) };
	PILGRIM_TRACING(int, MPI_File_write_ordered_end, PMPI_File_write_ordered_end(fh, buf, status), 3, sizes, args);
}
int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent)
{
	void **args = assemble_args_list(3, &fh, &datatype, &extent);
	int sizes[] = { sizeof(fh), sizeof(datatype), sizeof(extent) };
	PILGRIM_TRACING(int, MPI_File_get_type_extent, PMPI_File_get_type_extent(fh, datatype, extent), 3, sizes, args);
}
int MPI_Register_datarep(const char *datarep, MPI_Datarep_conversion_function *read_conversion_fn, MPI_Datarep_conversion_function *write_conversion_fn, MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state)
{
	void **args = assemble_args_list(5, &datarep, &read_conversion_fn, &write_conversion_fn, &dtype_file_extent_fn, &extra_state);
	int sizes[] = { sizeof(datarep), sizeof(read_conversion_fn), sizeof(write_conversion_fn), sizeof(dtype_file_extent_fn), sizeof(extra_state) };
	PILGRIM_TRACING(int, MPI_Register_datarep, PMPI_Register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state), 5, sizes, args);
}
int MPI_File_set_atomicity(MPI_File fh, int flag)
{
	void **args = assemble_args_list(2, &fh, &flag);
	int sizes[] = { sizeof(fh), sizeof(flag) };
	PILGRIM_TRACING(int, MPI_File_set_atomicity, PMPI_File_set_atomicity(fh, flag), 2, sizes, args);
}
int MPI_File_get_atomicity(MPI_File fh, int *flag)
{
	void **args = assemble_args_list(2, &fh, &flag);
	int sizes[] = { sizeof(fh), sizeof(flag) };
	PILGRIM_TRACING(int, MPI_File_get_atomicity, PMPI_File_get_atomicity(fh, flag), 2, sizes, args);
}
int MPI_File_sync(MPI_File fh)
{
	void **args = assemble_args_list(1, &fh);
	int sizes[] = { sizeof(fh) };
	PILGRIM_TRACING(int, MPI_File_sync, PMPI_File_sync(fh), 1, sizes, args);
}
int MPI_Type_create_f90_real(int p, int r, MPI_Datatype *newtype)
{
	void **args = assemble_args_list(3, &p, &r, &newtype);
	int sizes[] = { sizeof(p), sizeof(r), sizeof(newtype) };
	PILGRIM_TRACING(int, MPI_Type_create_f90_real, PMPI_Type_create_f90_real(p, r, newtype), 3, sizes, args);
}
int MPI_Type_create_f90_complex(int p, int r, MPI_Datatype *newtype)
{
	void **args = assemble_args_list(3, &p, &r, &newtype);
	int sizes[] = { sizeof(p), sizeof(r), sizeof(newtype) };
	PILGRIM_TRACING(int, MPI_Type_create_f90_complex, PMPI_Type_create_f90_complex(p, r, newtype), 3, sizes, args);
}
int MPI_Type_create_f90_integer(int r, MPI_Datatype *newtype)
{
	void **args = assemble_args_list(2, &r, &newtype);
	int sizes[] = { sizeof(r), sizeof(newtype) };
	PILGRIM_TRACING(int, MPI_Type_create_f90_integer, PMPI_Type_create_f90_integer(r, newtype), 2, sizes, args);
}
int MPI_Type_match_size(int typeclass, int size, MPI_Datatype *datatype)
{
	void **args = assemble_args_list(3, &typeclass, &size, &datatype);
	int sizes[] = { sizeof(typeclass), sizeof(size), sizeof(datatype) };
	PILGRIM_TRACING(int, MPI_Type_match_size, PMPI_Type_match_size(typeclass, size, datatype), 3, sizes, args);
}
int MPI_Pcontrol(const int level, ...)
{
	void **args = assemble_args_list(1, &level);
	int sizes[] = { sizeof(level) };
	PILGRIM_TRACING(int, MPI_Pcontrol, PMPI_Pcontrol(level), 1, sizes, args);
}
int MPI_T_init_thread(int required, int *provided)
{
	void **args = assemble_args_list(2, &required, &provided);
	int sizes[] = { sizeof(required), sizeof(provided) };
	PILGRIM_TRACING(int, MPI_T_init_thread, PMPI_T_init_thread(required, provided), 2, sizes, args);
}
int MPI_T_finalize(void)
{
	void **args = NULL;
	int* sizes = NULL;
	PILGRIM_TRACING(int, MPI_T_finalize, PMPI_T_finalize(), 0, sizes, args);
}
int MPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name, int *name_len)
{
	void **args = assemble_args_list(4, &enumtype, &num, &name, &name_len);
	int sizes[] = { sizeof(enumtype), sizeof(num), sizeof(name), sizeof(name_len) };
	PILGRIM_TRACING(int, MPI_T_enum_get_info, PMPI_T_enum_get_info(enumtype, num, name, name_len), 4, sizes, args);
}
int MPI_T_enum_get_item(MPI_T_enum enumtype, int index, int *value, char *name, int *name_len)
{
	void **args = assemble_args_list(5, &enumtype, &index, &value, &name, &name_len);
	int sizes[] = { sizeof(enumtype), sizeof(index), sizeof(value), sizeof(name), sizeof(name_len) };
	PILGRIM_TRACING(int, MPI_T_enum_get_item, PMPI_T_enum_get_item(enumtype, index, value, name, name_len), 5, sizes, args);
}
int MPI_T_cvar_get_num(int *num_cvar)
{
	void **args = assemble_args_list(1, &num_cvar);
	int sizes[] = { sizeof(num_cvar) };
	PILGRIM_TRACING(int, MPI_T_cvar_get_num, PMPI_T_cvar_get_num(num_cvar), 1, sizes, args);
}
int MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity, MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind, int *scope)
{
	void **args = assemble_args_list(10, &cvar_index, &name, &name_len, &verbosity, &datatype, &enumtype, &desc, &desc_len, &bind, &scope);
	int sizes[] = { sizeof(cvar_index), sizeof(name), sizeof(name_len), sizeof(verbosity), sizeof(datatype), sizeof(enumtype), sizeof(desc), sizeof(desc_len), sizeof(bind), sizeof(scope) };
	PILGRIM_TRACING(int, MPI_T_cvar_get_info, PMPI_T_cvar_get_info(cvar_index, name, name_len, verbosity, datatype, enumtype, desc, desc_len, bind, scope), 10, sizes, args);
}
int MPI_T_cvar_get_index(const char *name, int *cvar_index)
{
	void **args = assemble_args_list(2, &name, &cvar_index);
	int sizes[] = { sizeof(name), sizeof(cvar_index) };
	PILGRIM_TRACING(int, MPI_T_cvar_get_index, PMPI_T_cvar_get_index(name, cvar_index), 2, sizes, args);
}
int MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle, MPI_T_cvar_handle *handle, int *count)
{
	void **args = assemble_args_list(4, &cvar_index, &obj_handle, &handle, &count);
	int sizes[] = { sizeof(cvar_index), sizeof(obj_handle), sizeof(handle), sizeof(count) };
	PILGRIM_TRACING(int, MPI_T_cvar_handle_alloc, PMPI_T_cvar_handle_alloc(cvar_index, obj_handle, handle, count), 4, sizes, args);
}
int MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle)
{
	void **args = assemble_args_list(1, &handle);
	int sizes[] = { sizeof(handle) };
	PILGRIM_TRACING(int, MPI_T_cvar_handle_free, PMPI_T_cvar_handle_free(handle), 1, sizes, args);
}
int MPI_T_cvar_read(MPI_T_cvar_handle handle, void* buf)
{
	void **args = assemble_args_list(2, &handle, &buf);
	int sizes[] = { sizeof(handle), sizeof(buf) };
	PILGRIM_TRACING(int, MPI_T_cvar_read, PMPI_T_cvar_read(handle, buf), 2, sizes, args);
}
int MPI_T_cvar_write(MPI_T_cvar_handle handle, const void* buf)
{
	void **args = assemble_args_list(2, &handle, &buf);
	int sizes[] = { sizeof(handle), sizeof(buf) };
	PILGRIM_TRACING(int, MPI_T_cvar_write, PMPI_T_cvar_write(handle, buf), 2, sizes, args);
}
int MPI_T_pvar_get_num(int *num_pvar)
{
	void **args = assemble_args_list(1, &num_pvar);
	int sizes[] = { sizeof(num_pvar) };
	PILGRIM_TRACING(int, MPI_T_pvar_get_num, PMPI_T_pvar_get_num(num_pvar), 1, sizes, args);
}
int MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *var_class, MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind, int *readonly, int *continuous, int *atomic)
{
	void **args = assemble_args_list(13, &pvar_index, &name, &name_len, &verbosity, &var_class, &datatype, &enumtype, &desc, &desc_len, &bind, &readonly, &continuous, &atomic);
	int sizes[] = { sizeof(pvar_index), sizeof(name), sizeof(name_len), sizeof(verbosity), sizeof(var_class), sizeof(datatype), sizeof(enumtype), sizeof(desc), sizeof(desc_len), sizeof(bind), sizeof(readonly), sizeof(continuous), sizeof(atomic) };
	PILGRIM_TRACING(int, MPI_T_pvar_get_info, PMPI_T_pvar_get_info(pvar_index, name, name_len, verbosity, var_class, datatype, enumtype, desc, desc_len, bind, readonly, continuous, atomic), 13, sizes, args);
}
int MPI_T_pvar_get_index(const char *name, int var_class, int *pvar_index)
{
	void **args = assemble_args_list(3, &name, &var_class, &pvar_index);
	int sizes[] = { sizeof(name), sizeof(var_class), sizeof(pvar_index) };
	PILGRIM_TRACING(int, MPI_T_pvar_get_index, PMPI_T_pvar_get_index(name, var_class, pvar_index), 3, sizes, args);
}
int MPI_T_pvar_session_create(MPI_T_pvar_session *session)
{
	void **args = assemble_args_list(1, &session);
	int sizes[] = { sizeof(session) };
	PILGRIM_TRACING(int, MPI_T_pvar_session_create, PMPI_T_pvar_session_create(session), 1, sizes, args);
}
int MPI_T_pvar_session_free(MPI_T_pvar_session *session)
{
	void **args = assemble_args_list(1, &session);
	int sizes[] = { sizeof(session) };
	PILGRIM_TRACING(int, MPI_T_pvar_session_free, PMPI_T_pvar_session_free(session), 1, sizes, args);
}
int MPI_T_pvar_handle_alloc(MPI_T_pvar_session session, int pvar_index, void *obj_handle, MPI_T_pvar_handle *handle, int *count)
{
	void **args = assemble_args_list(5, &session, &pvar_index, &obj_handle, &handle, &count);
	int sizes[] = { sizeof(session), sizeof(pvar_index), sizeof(obj_handle), sizeof(handle), sizeof(count) };
	PILGRIM_TRACING(int, MPI_T_pvar_handle_alloc, PMPI_T_pvar_handle_alloc(session, pvar_index, obj_handle, handle, count), 5, sizes, args);
}
int MPI_T_pvar_handle_free(MPI_T_pvar_session session, MPI_T_pvar_handle *handle)
{
	void **args = assemble_args_list(2, &session, &handle);
	int sizes[] = { sizeof(session), sizeof(handle) };
	PILGRIM_TRACING(int, MPI_T_pvar_handle_free, PMPI_T_pvar_handle_free(session, handle), 2, sizes, args);
}
int MPI_T_pvar_start(MPI_T_pvar_session session, MPI_T_pvar_handle handle)
{
	void **args = assemble_args_list(2, &session, &handle);
	int sizes[] = { sizeof(session), sizeof(handle) };
	PILGRIM_TRACING(int, MPI_T_pvar_start, PMPI_T_pvar_start(session, handle), 2, sizes, args);
}
int MPI_T_pvar_stop(MPI_T_pvar_session session, MPI_T_pvar_handle handle)
{
	void **args = assemble_args_list(2, &session, &handle);
	int sizes[] = { sizeof(session), sizeof(handle) };
	PILGRIM_TRACING(int, MPI_T_pvar_stop, PMPI_T_pvar_stop(session, handle), 2, sizes, args);
}
int MPI_T_pvar_read(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void* buf)
{
	void **args = assemble_args_list(3, &session, &handle, &buf);
	int sizes[] = { sizeof(session), sizeof(handle), sizeof(buf) };
	PILGRIM_TRACING(int, MPI_T_pvar_read, PMPI_T_pvar_read(session, handle, buf), 3, sizes, args);
}
int MPI_T_pvar_write(MPI_T_pvar_session session, MPI_T_pvar_handle handle, const void* buf)
{
	void **args = assemble_args_list(3, &session, &handle, &buf);
	int sizes[] = { sizeof(session), sizeof(handle), sizeof(buf) };
	PILGRIM_TRACING(int, MPI_T_pvar_write, PMPI_T_pvar_write(session, handle, buf), 3, sizes, args);
}
int MPI_T_pvar_reset(MPI_T_pvar_session session, MPI_T_pvar_handle handle)
{
	void **args = assemble_args_list(2, &session, &handle);
	int sizes[] = { sizeof(session), sizeof(handle) };
	PILGRIM_TRACING(int, MPI_T_pvar_reset, PMPI_T_pvar_reset(session, handle), 2, sizes, args);
}
int MPI_T_pvar_readreset(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void* buf)
{
	void **args = assemble_args_list(3, &session, &handle, &buf);
	int sizes[] = { sizeof(session), sizeof(handle), sizeof(buf) };
	PILGRIM_TRACING(int, MPI_T_pvar_readreset, PMPI_T_pvar_readreset(session, handle, buf), 3, sizes, args);
}
int MPI_T_category_get_num(int *num_cat)
{
	void **args = assemble_args_list(1, &num_cat);
	int sizes[] = { sizeof(num_cat) };
	PILGRIM_TRACING(int, MPI_T_category_get_num, PMPI_T_category_get_num(num_cat), 1, sizes, args);
}
int MPI_T_category_get_info(int cat_index, char *name, int *name_len, char *desc, int *desc_len, int *num_cvars, int *num_pvars, int *num_categories)
{
	void **args = assemble_args_list(8, &cat_index, &name, &name_len, &desc, &desc_len, &num_cvars, &num_pvars, &num_categories);
	int sizes[] = { sizeof(cat_index), sizeof(name), sizeof(name_len), sizeof(desc), sizeof(desc_len), sizeof(num_cvars), sizeof(num_pvars), sizeof(num_categories) };
	PILGRIM_TRACING(int, MPI_T_category_get_info, PMPI_T_category_get_info(cat_index, name, name_len, desc, desc_len, num_cvars, num_pvars, num_categories), 8, sizes, args);
}
int MPI_T_category_get_index(const char *name, int *cat_index)
{
	void **args = assemble_args_list(2, &name, &cat_index);
	int sizes[] = { sizeof(name), sizeof(cat_index) };
	PILGRIM_TRACING(int, MPI_T_category_get_index, PMPI_T_category_get_index(name, cat_index), 2, sizes, args);
}
int MPI_T_category_get_cvars(int cat_index, int len, int indices[])
{
	void **args = assemble_args_list(3, &cat_index, &len, &indices);
	int sizes[] = { sizeof(cat_index), sizeof(len), sizeof(int) };
	PILGRIM_TRACING(int, MPI_T_category_get_cvars, PMPI_T_category_get_cvars(cat_index, len, indices), 3, sizes, args);
}
int MPI_T_category_get_pvars(int cat_index, int len, int indices[])
{
	void **args = assemble_args_list(3, &cat_index, &len, &indices);
	int sizes[] = { sizeof(cat_index), sizeof(len), sizeof(int) };
	PILGRIM_TRACING(int, MPI_T_category_get_pvars, PMPI_T_category_get_pvars(cat_index, len, indices), 3, sizes, args);
}
int MPI_T_category_get_categories(int cat_index, int len, int indices[])
{
	void **args = assemble_args_list(3, &cat_index, &len, &indices);
	int sizes[] = { sizeof(cat_index), sizeof(len), sizeof(int) };
	PILGRIM_TRACING(int, MPI_T_category_get_categories, PMPI_T_category_get_categories(cat_index, len, indices), 3, sizes, args);
}
int MPI_T_category_changed(int *stamp)
{
	void **args = assemble_args_list(1, &stamp);
	int sizes[] = { sizeof(stamp) };
	PILGRIM_TRACING(int, MPI_T_category_changed, PMPI_T_category_changed(stamp), 1, sizes, args);
}
int MPI_Keyval_create(MPI_Copy_function *copy_fn, MPI_Delete_function *delete_fn, int *keyval, void* extra_state)
{
	void **args = assemble_args_list(4, &copy_fn, &delete_fn, &keyval, &extra_state);
	int sizes[] = { sizeof(copy_fn), sizeof(delete_fn), sizeof(keyval), sizeof(extra_state) };
	PILGRIM_TRACING(int, MPI_Keyval_create, PMPI_Keyval_create(copy_fn, delete_fn, keyval, extra_state), 4, sizes, args);
}
int MPI_Keyval_free(int *keyval)
{
	void **args = assemble_args_list(1, &keyval);
	int sizes[] = { sizeof(keyval) };
	PILGRIM_TRACING(int, MPI_Keyval_free, PMPI_Keyval_free(keyval), 1, sizes, args);
}
int MPI_Attr_put(MPI_Comm comm, int keyval, void* attribute_val)
{
	void **args = assemble_args_list(3, &comm, &keyval, &attribute_val);
	int sizes[] = { sizeof(comm), sizeof(keyval), sizeof(attribute_val) };
	PILGRIM_TRACING(int, MPI_Attr_put, PMPI_Attr_put(comm, keyval, attribute_val), 3, sizes, args);
}
int MPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val, int *flag)
{
	void **args = assemble_args_list(4, &comm, &keyval, &attribute_val, &flag);
	int sizes[] = { sizeof(comm), sizeof(keyval), sizeof(attribute_val), sizeof(flag) };
	PILGRIM_TRACING(int, MPI_Attr_get, PMPI_Attr_get(comm, keyval, attribute_val, flag), 4, sizes, args);
}
int MPI_Attr_delete(MPI_Comm comm, int keyval)
{
	void **args = assemble_args_list(2, &comm, &keyval);
	int sizes[] = { sizeof(comm), sizeof(keyval) };
	PILGRIM_TRACING(int, MPI_Attr_delete, PMPI_Attr_delete(comm, keyval), 2, sizes, args);
}
