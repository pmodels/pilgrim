#include <mpi.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "pilgrim.h"
#include "dlmalloc-2.8.6.h"

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
    append_request(request);
    free_request(request);
    void **args = NULL;
    int sizes[] = {};

    PILGRIM_TRACING_1(int, MPI_Wait, (request, status));
    PILGRIM_TRACING_2(0, sizes, args);
}
int MPI_Waitany(int count, MPI_Request array_of_requests[], int *index, MPI_Status *status)
{
    int idx;
    MPI_Request old_reqs[count];
    for(idx = 0; idx < count; idx++) {
        append_request( &(array_of_requests[idx]) );
        old_reqs[idx] = array_of_requests[idx];
    }

    void **args = assemble_args_list(2, &count, index);
    int sizes[] = { sizeof(int), sizeof(int) };

    PILGRIM_TRACING_1(int, MPI_Waitany, (count, array_of_requests, index, status));
    free_request(&old_reqs[*index]);
    PILGRIM_TRACING_2(2, sizes, args);
}

int MPI_Waitsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status array_of_statuses[])
{
    void *tmp = array_of_statuses;
    if(array_of_statuses == MPI_STATUSES_IGNORE)
        tmp = dlcalloc((*outcount), sizeof(MPI_Status) );

    int idx;
    MPI_Request old_reqs[incount];
    for(idx = 0; idx < incount; idx++) {
        append_request( &(array_of_requests[idx]) );
        old_reqs[idx] = array_of_requests[idx];
    }

    // Call the original function first, so we know the correct value for output arguments
	PILGRIM_TRACING_1(int, MPI_Waitsome, (incount, array_of_requests, outcount, array_of_indices, array_of_statuses))

    for(idx = 0; idx < incount; idx++) {
        if(old_reqs[idx] != MPI_REQUEST_NULL && array_of_requests[idx] == MPI_REQUEST_NULL)
            free_request(&(old_reqs[idx]));
    }

    //TODO include status argument
    void **args = assemble_args_list(3, &incount, outcount, array_of_indices);
    int sizes[] = { sizeof(incount), sizeof(int), (*outcount)*sizeof(int) };
    PILGRIM_TRACING_2(3, sizes, args);
}
int MPI_Waitall(int count, MPI_Request array_of_requests[], MPI_Status array_of_statuses[])
{
    // TODO: Without the next non-op line, Chombo will crash, no idea why.
    MPI_Request old_reqs[count];

    void *tmp = array_of_statuses;
    if(array_of_statuses == MPI_STATUSES_IGNORE)
        tmp = dlcalloc( count, sizeof(MPI_Status) );

    int idx;
    for(idx = 0; idx < count; idx++) {
        append_request( &(array_of_requests[idx]) );
        old_reqs[idx] = array_of_requests[idx];
    }

    PILGRIM_TRACING_1(int, MPI_Waitall, (count, array_of_requests, array_of_statuses));

    for(idx = 0; idx < count; idx++) {
        if(old_reqs[idx] != MPI_REQUEST_NULL && array_of_requests[idx] == MPI_REQUEST_NULL)
            free_request(&(old_reqs[idx]));
    }

    //TODO include status argument
    void **args = assemble_args_list(1, &count);
    int sizes[] = { sizeof(count) };
    PILGRIM_TRACING_2(1, sizes, args);
}

int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status)
{
    append_request(request);

    PILGRIM_TRACING_1(int, MPI_Test, (request, flag, status));
    void **args = assemble_args_list(1, flag);
    int sizes[] = { sizeof(int) };
    PILGRIM_TRACING_2(1, sizes, args);
}

int MPI_Testany(int count, MPI_Request array_of_requests[], int *index, int *flag, MPI_Status *status)
{
    int idx;
    for(idx = 0; idx < count; idx++)
        append_request( &(array_of_requests[idx]) );

    PILGRIM_TRACING_1(int, MPI_Testany, (count, array_of_requests, index, flag, status));

    void **args = assemble_args_list(3, &count, index, flag);
    int sizes[] = { sizeof(int), sizeof(int), sizeof(int) };

    PILGRIM_TRACING_2(3, sizes, args);
}

int MPI_Testall(int count, MPI_Request array_of_requests[], int *flag, MPI_Status array_of_statuses[])
{
    void *tmp = array_of_statuses;
    if(array_of_statuses == MPI_STATUSES_IGNORE)
        tmp = dlcalloc( count, sizeof(MPI_Status) );

    int idx;
    MPI_Request old_reqs[count];
    for(idx = 0; idx < count; idx++) {
        append_request( &(array_of_requests[idx]) );
        old_reqs[idx] = array_of_requests[idx];
    }

    PILGRIM_TRACING_1(int, MPI_Testall, (count, array_of_requests, flag, array_of_statuses));

    for(idx = 0; idx < count; idx++) {
        if(old_reqs[idx] != MPI_REQUEST_NULL && array_of_requests[idx] == MPI_REQUEST_NULL)
            free_request(&(old_reqs[idx]));
    }

    void **args = assemble_args_list(2, &count, flag);
    int sizes[] = { sizeof(count), sizeof(int) };

    PILGRIM_TRACING_2(2, sizes, args);
}
int MPI_Testsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status array_of_statuses[])
{
    void *tmp = array_of_statuses;
    if(array_of_statuses == MPI_STATUSES_IGNORE)
        tmp = dlcalloc( (*outcount), sizeof(MPI_Status) );

    int idx;
    MPI_Request old_reqs[incount];
    for(idx = 0; idx < incount; idx++) {
        append_request( &(array_of_requests[idx]) );
        old_reqs[idx] = array_of_requests[idx];
    }

	PILGRIM_TRACING_1(int, MPI_Testsome, (incount, array_of_requests, outcount, array_of_indices, array_of_statuses))

    for(idx = 0; idx < incount; idx++) {
        if(old_reqs[idx] != MPI_REQUEST_NULL && array_of_requests[idx] == MPI_REQUEST_NULL)
            free_request(&(old_reqs[idx]));
    }

    //TODO
    void **args = assemble_args_list(3, &incount, outcount, array_of_indices );
    int sizes[] = { sizeof(incount), sizeof(outcount), (*outcount) * sizeof(int)  };
    PILGRIM_TRACING_2(3, sizes, args);
}

int MPI_Request_free(MPI_Request *request)
{
    PILGRIM_TRACING_1(int, MPI_Request_free, (request));
    append_request(request);
    free_request(request);
    void **args = NULL;
    int* sizes = NULL;
    PILGRIM_TRACING_2(0, sizes, args);
}

int MPI_Startall(int count, MPI_Request array_of_requests[])
{
    int idx;
    for (idx = 0; idx < count; idx++)
        append_request(&array_of_requests[idx]);

    PILGRIM_TRACING_1(int, MPI_Startall, (count, array_of_requests));

    void **args = assemble_args_list(1, &count);
    int sizes[] = { sizeof(int) };

    PILGRIM_TRACING_2(1, sizes, args);
}


