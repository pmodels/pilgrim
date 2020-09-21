#include <mpi.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "pilgrim.h"
#include "dlmalloc-2.8.6.h"

#define GET_STATUS_INFO(req, status)                                \
    RequestHash* entry = NULL;                                      \
    entry = request_hash_entry(req);                                \
    int status_info[] = {0, 0};                                     \
    if(entry) {                                                     \
        if(entry->any_source)                                       \
            status_info[0] = status->MPI_SOURCE;                    \
        if(entry->any_tag)                                          \
            status_info[1] = status->MPI_TAG;                       \
    }


#define GET_STATUSES_INFO(outcount, indices, statuses)                                              \
    int iidx;                                                                                       \
    int statuses_info[outcount*2];                                                                  \
    memset(statuses, 0, sizeof(int)*2*outcount);                                                    \
    for(idx = 0; idx < outcount; idx++) {                                                           \
        iidx = indices[idx];                                                                        \
        if(old_reqs[iidx] != MPI_REQUEST_NULL && array_of_requests[iidx] == MPI_REQUEST_NULL) {     \
            RequestHash* entry = NULL;                                                              \
            entry = request_hash_entry(&old_reqs[iidx]);                                            \
            if(entry) {                                                                             \
                if(entry->any_source)                                                               \
                    statuses_info[idx*2+0] = statuses[iidx].MPI_SOURCE;                             \
                if(entry->any_tag)                                                                  \
                    statuses_info[idx*2+1] = statuses[iidx].MPI_TAG;                                \
            }                                                                                       \
            free_request(&(old_reqs[iidx]));                                                        \
        }                                                                                           \
    }

int* get_request_id(MPI_Request* req) {
    // 2nd and 3rd arguments do not matter if the request is already existed.
    return request2id(req, 0, 0);
}


int MPI_Pcontrol(const int level, ...)
{
	void **args = assemble_args_list(1, &level);
	int sizes[] = { sizeof(level) };
	va_list pcontrol_args;
	va_start(pcontrol_args, level);
	PILGRIM_TRACING(int, MPI_Pcontrol, (level, pcontrol_args), 1, sizes, args);
	va_end(pcontrol_args);
}

int MPI_Wait(MPI_Request *request, MPI_Status *status)
{
    GET_STATUS_INFO(request, status);
    int sizes[] = {sizeof(int), sizeof(status_info)};
    void **args = assemble_args_list(2, get_request_id(request), status_info);

    PILGRIM_TRACING_1(int, MPI_Wait, (request, status));
    PILGRIM_TRACING_2(2, sizes, args);

    free_request(request);
}

int MPI_Waitany(int count, MPI_Request array_of_requests[], int *index, MPI_Status *status)
{
    int ids[count];
    int idx;
    MPI_Request old_reqs[count];
    for(idx = 0; idx < count; idx++) {
        ids[idx] = *( get_request_id( &(array_of_requests[idx]) ) );
        old_reqs[idx] = array_of_requests[idx];
    }

    PILGRIM_TRACING_1(int, MPI_Waitany, (count, array_of_requests, index, status));

    GET_STATUS_INFO(&old_reqs[*index], status);
    void **args = assemble_args_list(4, &count, ids, index, status_info);
    int sizes[] = { sizeof(int), sizeof(int)*count, sizeof(int), sizeof(status_info) };

    PILGRIM_TRACING_2(4, sizes, args);
    free_request(&old_reqs[*index]);
}

int MPI_Waitsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status array_of_statuses[])
{
    int ids[incount];
    int idx;
    MPI_Request old_reqs[incount];
    for(idx = 0; idx < incount; idx++) {
        ids[idx] = *( get_request_id( &(array_of_requests[idx]) ) );
        old_reqs[idx] = array_of_requests[idx];
    }

    // Call the original function first, so we know the correct value for output arguments
	PILGRIM_TRACING_1(int, MPI_Waitsome, (incount, array_of_requests, outcount, array_of_indices, array_of_statuses));

    GET_STATUSES_INFO(*outcount, array_of_indices, array_of_statuses);

    //TODO include status argument
    void **args = assemble_args_list(5, &incount, ids, outcount, array_of_indices, statuses_info);
    int sizes[] = { sizeof(incount), sizeof(int)*incount, sizeof(int), (*outcount)*sizeof(int), sizeof(statuses_info) };
    PILGRIM_TRACING_2(5, sizes, args);
}


int MPI_Waitall(int count, MPI_Request array_of_requests[], MPI_Status array_of_statuses[])
{
    // TODO: Without the next non-op line, Chombo will crash, no idea why.
    MPI_Request old_reqs[count];

    int ids[count];
    int idx;
    for(idx = 0; idx < count; idx++) {
        ids[idx] = *( get_request_id( &(array_of_requests[idx]) ) );
        old_reqs[idx] = array_of_requests[idx];
    }

    PILGRIM_TRACING_1(int, MPI_Waitall, (count, array_of_requests, array_of_statuses));

    int indices[count];
    for(idx = 0; idx < count; idx++) indices[idx] = idx;
    GET_STATUSES_INFO(count, indices, array_of_statuses);
    void **args = assemble_args_list(3, &count, ids, statuses_info);
    int sizes[] = { sizeof(count), count*sizeof(int), sizeof(statuses_info)};

    PILGRIM_TRACING_2(3, sizes, args);
}

int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status)
{

    GET_STATUS_INFO(request, status);
    void **args = assemble_args_list(3, get_request_id(request), flag, status_info);
    int sizes[] = { sizeof(int), sizeof(int), sizeof(status_info)};

    PILGRIM_TRACING_1(int, MPI_Test, (request, flag, status));
    PILGRIM_TRACING_2(3, sizes, args);

    if(*request == MPI_REQUEST_NULL)
        free_request(request);
}

int MPI_Testany(int count, MPI_Request array_of_requests[], int *index, int *flag, MPI_Status *status)
{
    int ids[count];
    int idx;
    MPI_Request old_reqs[count];
    for(idx = 0; idx < count; idx++) {
        ids[idx] = *( get_request_id( &(array_of_requests[idx]) ) );
        old_reqs[idx] = array_of_requests[idx];
    }

    PILGRIM_TRACING_1(int, MPI_Testany, (count, array_of_requests, index, flag, status));

    GET_STATUS_INFO(&old_reqs[*index],  status);
    void **args = assemble_args_list(5, &count, ids, index, flag, status_info);
    int sizes[] = { sizeof(int), sizeof(int)*count, sizeof(int), sizeof(int), sizeof(status_info) };
    PILGRIM_TRACING_2(5, sizes, args);

    free_request(&old_reqs[*index]);
}

int MPI_Testall(int count, MPI_Request array_of_requests[], int *flag, MPI_Status array_of_statuses[])
{
    void *tmp = array_of_statuses;
    if(array_of_statuses == MPI_STATUSES_IGNORE)
        tmp = dlcalloc( count, sizeof(MPI_Status) );

    int ids[count];
    int idx;
    MPI_Request old_reqs[count];
    for(idx = 0; idx < count; idx++) {
        ids[idx] = *( get_request_id( &(array_of_requests[idx]) ) );
        old_reqs[idx] = array_of_requests[idx];
    }

    PILGRIM_TRACING_1(int, MPI_Testall, (count, array_of_requests, flag, array_of_statuses));

    int indices[count];
    for(idx = 0; idx < count; idx++) indices[idx] = idx;
    GET_STATUSES_INFO(count, indices, array_of_statuses);
    void **args = assemble_args_list(3, &count, ids, flag);
    int sizes[] = { sizeof(count), count*sizeof(int), sizeof(int) };

    PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Testsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status array_of_statuses[])
{
    int ids[incount];
    int idx;
    MPI_Request old_reqs[incount];
    for(idx = 0; idx < incount; idx++) {
        ids[idx] = *( get_request_id( &(array_of_requests[idx]) ) );
        old_reqs[idx] = array_of_requests[idx];
    }

	PILGRIM_TRACING_1(int, MPI_Testsome, (incount, array_of_requests, outcount, array_of_indices, array_of_statuses))

    GET_STATUSES_INFO(*outcount, array_of_indices, array_of_statuses);
    void **args = assemble_args_list(5, &incount, ids, outcount, array_of_indices, statuses_info);
    int sizes[] = { sizeof(incount), sizeof(int)*incount, sizeof(outcount), (*outcount) * sizeof(int), sizeof(statuses_info) };

    PILGRIM_TRACING_2(5, sizes, args);
}

int MPI_Request_free(MPI_Request *request)
{
    PILGRIM_TRACING_1(int, MPI_Request_free, (request));

    void **args = assemble_args_list(1, get_request_id(request));
    int sizes[] = {sizeof(int)};

    PILGRIM_TRACING_2(1, sizes, args);

    free_request(request);
}

int MPI_Startall(int count, MPI_Request array_of_requests[])
{
    int ids[count];
    int idx;
    for (idx = 0; idx < count; idx++)
        ids[idx] = *( get_request_id(&array_of_requests[idx]) );

    PILGRIM_TRACING_1(int, MPI_Startall, (count, array_of_requests));

    void **args = assemble_args_list(2, &count, ids);
    int sizes[] = { sizeof(int), count*sizeof(int) };

    PILGRIM_TRACING_2(1, sizes, args);
}
