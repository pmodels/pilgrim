/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include <mpi.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "pilgrim.h"

static int invalid_request_id = -1;



typedef struct IdupReqHash_t {
    void *key;              // idup_req
    MPI_Comm *newcomm;
    int id;
    bool idup_req_completed;
    MPI_Request *ibcast_req;
    UT_hash_handle hh;
} IdupReqHash;

static int idup_reqs_counter = 0;
IdupReqHash *idup_reqs_table = NULL;


static int int_comp(const void *p1, const void *p2)
{
    int i1 = *(int*) p1;
    int i2 = *(int*) p2;
    if ( i1 == i2 ) return 0;
    else if ( i1 < i2 ) return 1;
    else return -1;
}

// Check if the given request is genereated from MPI_Comm_idup.
// and if it is completed.
// if so, wait on the ibcast request
void check_idup_request(MPI_Request *req) {
    IdupReqHash* entry = NULL;
    HASH_FIND(hh, idup_reqs_table, req, sizeof(MPI_Request), entry);
    if(entry) {
        PMPI_Wait(entry->ibcast_req, MPI_STATUS_IGNORE);

        add_mpi_comm_hash_entry(entry->newcomm, entry->id);

        pilgrim_free(entry->key, sizeof(MPI_Request));
        pilgrim_free(entry->newcomm, sizeof(MPI_Comm));
        pilgrim_free(entry->ibcast_req, sizeof(MPI_Request));
        HASH_DEL(idup_reqs_table, entry);
    }
}

void check_idup_requests(int count, MPI_Request reqs[], int indices[], bool all) {
    int i;
    for(i = 0; i < count; i++) {
        MPI_Request *req;
        if(all)
            req = &(reqs[i]);
        else
            req = &(reqs[indices[i]]);
        check_idup_request(req);
    }
}

void check_idup_request_test(MPI_Request *req, int *flag) {
    IdupReqHash* entry = NULL;
    HASH_FIND(hh, idup_reqs_table, req, sizeof(MPI_Request), entry);

    // Not a idup request, do nothing
    if(!entry)
        return;

    // Completed by a previous Test but the ibcast_req
    // at that time has not yet completed. Now, we need
    // to test the ibcast_req again
    if(entry && entry->idup_req_completed) {
        int ibcast_completed;
        //PMPI_Test(ibcast_req, &ibcast_completed);
        if(ibcast_completed) {
            *flag = 1;
        }
    }
}

bool is_completed_idup_request(MPI_Request *req) {
    IdupReqHash* entry = NULL;
    HASH_FIND(hh, idup_reqs_table, req, sizeof(MPI_Request), entry);
    if(entry && entry->idup_req_completed)
        return true;
    return false;
}


#define GET_STATUS_INFO(req, status, flag)                          \
    RequestHash* entry = NULL;                                      \
    entry = request_hash_entry(req);                                \
    int status_info[] = {0, 0};                                     \
    int req_id = invalid_request_id;                                \
    if(entry && entry->req_node)                                    \
        req_id = entry->req_node->id;                               \
    else                                                            \
        req_id = invalid_request_id;                                \
    if(flag) {                                                      \
        if(entry && status && status != MPI_STATUS_IGNORE) {        \
            if(entry->any_source)                                   \
                status_info[0] = g_mpi_rank - status->MPI_SOURCE;   \
            if(entry->any_tag)                                      \
                status_info[1] = g_mpi_rank - status->MPI_TAG;      \
        }                                                           \
        MPI_OBJ_RELEASE(MPI_Request, req);                          \
    }


#define GET_STATUSES_INFO(outcount, indices, statuses)                                              \
    int iidx;                                                                                       \
    int statuses_info[outcount*2];                                                                  \
    memset(statuses_info, 0, sizeof(int)*2*outcount);                                               \
    for(idx = 0; idx < outcount; idx++) {                                                           \
        iidx = indices[idx];                                                                        \
        if(old_reqs[iidx] != MPI_REQUEST_NULL && array_of_requests[iidx] == MPI_REQUEST_NULL) {     \
            RequestHash* entry = NULL;                                                              \
            entry = request_hash_entry(&old_reqs[iidx]);                                            \
            if(entry && statuses && statuses != MPI_STATUSES_IGNORE) {                              \
                if(entry->any_source)                                                               \
                    statuses_info[idx*2+0] = g_mpi_rank-statuses[idx].MPI_SOURCE;                   \
                if(entry->any_tag)                                                                  \
                    statuses_info[idx*2+1] = g_mpi_rank-statuses[idx].MPI_TAG;                      \
            }                                                                                       \
            MPI_OBJ_RELEASE(MPI_Request, &(old_reqs[iidx]));                                        \
        }                                                                                           \
    }

#define COPY_REQUESTS(count)                                                                        \
    int ids[count];                                                                                 \
    int idx;                                                                                        \
    MPI_Request old_reqs[count];                                                                    \
    for(idx = 0; idx < count; idx++) {                                                              \
        ids[idx] = get_request_id( &(array_of_requests[idx]) );                                     \
        memcpy( &old_reqs[idx],  &array_of_requests[idx], sizeof(MPI_Request));                     \
    }                                                                                               \
    qsort(ids, count, sizeof(int), int_comp);


int get_request_id(MPI_Request* req) {
    return MPI_OBJ_ID(MPI_Request, req);
}


int MPI_Pcontrol(const int level, ...)
{
	void **args = assemble_args_list(1, &level);
	int sizes[] = { sizeof(level) };
	va_list pcontrol_args;
	va_start(pcontrol_args, level);
    PILGRIM_TRACING_1(int, MPI_Pcontrol, (level, pcontrol_args));
    PILGRIM_TRACING_2(1, sizes, args, -1);
}

int MPI_Wait(MPI_Request *request, MPI_Status *status)
{
    MPI_Request old_req;
    memcpy(&old_req, request, sizeof(MPI_Request));

    PILGRIM_TRACING_1(int, MPI_Wait, (request, status));

    check_idup_request(request);

    GET_STATUS_INFO(&old_req, status, true);
    int sizes[] = {sizeof(int), sizeof(status_info)};
    void **args = assemble_args_list(2, &req_id, status_info);

    PILGRIM_TRACING_2(2, sizes, args, -1);
}

int MPI_Waitany(int count, MPI_Request array_of_requests[], int *index, MPI_Status *status)
{
    COPY_REQUESTS(count);

    PILGRIM_TRACING_1(int, MPI_Waitany, (count, array_of_requests, index, status));

    int num_args;
    if(*index != MPI_UNDEFINED) {
        num_args = 4;
        check_idup_request(&old_reqs[*index]);
        GET_STATUS_INFO(&old_reqs[*index], status, true);
        void **args = assemble_args_list(num_args, &count, ids, index, status_info);
        int sizes[] = { sizeof(int), sizeof(int)*count, sizeof(int), sizeof(status_info) };
        PILGRIM_TRACING_2(num_args, sizes, args, -1);
    } else {
        num_args = 3;
        void **args = assemble_args_list(num_args, &count, ids, index);
        int sizes[] = { sizeof(int), sizeof(int)*count, sizeof(int)};
        PILGRIM_TRACING_2(num_args, sizes, args, -1);
    }
}

int MPI_Waitsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status array_of_statuses[])
{

    COPY_REQUESTS(incount);

	PILGRIM_TRACING_1(int, MPI_Waitsome, (incount, array_of_requests, outcount, array_of_indices, array_of_statuses));

    int num_args;
    if(*outcount > 0) {
        num_args = 5;
        check_idup_requests(*outcount, old_reqs, array_of_indices, false);
        GET_STATUSES_INFO(*outcount, array_of_indices, array_of_statuses);
        void **args = assemble_args_list(num_args, &incount, ids, outcount, array_of_indices, statuses_info);
        int sizes[] = { sizeof(incount), sizeof(int)*incount, sizeof(int), (*outcount)*sizeof(int), sizeof(statuses_info) };
        PILGRIM_TRACING_2(num_args, sizes, args, -1);
    } else {
        // *outcount == MPI_UNDEFINED, we don't keep array_of_indices and array_of_statuses
        num_args = 3;
        void **args = assemble_args_list(num_args, &incount, ids, outcount);
        int sizes[] = { sizeof(incount), sizeof(int)*incount, sizeof(int) };
        PILGRIM_TRACING_2(num_args, sizes, args, -1);
    }
}

int MPI_Waitall(int count, MPI_Request array_of_requests[], MPI_Status array_of_statuses[])
{

    COPY_REQUESTS(count);

    PILGRIM_TRACING_1(int, MPI_Waitall, (count, array_of_requests, array_of_statuses));

    check_idup_requests(count, old_reqs, NULL, true);

    int indices[count];
    for(idx = 0; idx < count; idx++) indices[idx] = idx;
    GET_STATUSES_INFO(count, indices, array_of_statuses);

    void **args = assemble_args_list(3, &count, ids, statuses_info);
    int sizes[] = { sizeof(count), count*sizeof(int), sizeof(statuses_info)};
    PILGRIM_TRACING_2(3, sizes, args, -1);
}

int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status)
{
    MPI_Request old_req;
    memcpy(&old_req, request, sizeof(MPI_Request));

    PILGRIM_TRACING_1(int, MPI_Test, (request, flag, status));

    GET_STATUS_INFO(&old_req, status, *flag);
    void **args = assemble_args_list(3, req_id, flag, status_info);
    int sizes[] = { sizeof(int), sizeof(int), sizeof(status_info)};

    PILGRIM_TRACING_2(3, sizes, args, -1);
}

int MPI_Testany(int count, MPI_Request array_of_requests[], int *index, int *flag, MPI_Status *status)
{
    COPY_REQUESTS(count);

    PILGRIM_TRACING_1(int, MPI_Testany, (count, array_of_requests, index, flag, status));

    int num_args;
    if(*index != MPI_UNDEFINED) {
        num_args = 5;
        GET_STATUS_INFO(&old_reqs[*index], status, *flag);
        void **args = assemble_args_list(num_args, &count, ids, index, flag, status_info);
        int sizes[] = { sizeof(int), sizeof(int)*count, sizeof(int), sizeof(int), sizeof(status_info) };
        PILGRIM_TRACING_2(num_args, sizes, args, -1);
    } else {
        num_args = 4;
        void **args = assemble_args_list(num_args, &count, ids, index, flag);
        int sizes[] = { sizeof(int), sizeof(int)*count, sizeof(int), sizeof(int)};
        PILGRIM_TRACING_2(num_args, sizes, args, -1);
    }
}

int MPI_Testall(int count, MPI_Request array_of_requests[], int *flag, MPI_Status array_of_statuses[])
{
    COPY_REQUESTS(count);

    PILGRIM_TRACING_1(int, MPI_Testall, (count, array_of_requests, flag, array_of_statuses));

    int indices[count];
    for(idx = 0; idx < count; idx++) indices[idx] = idx;

    int num_args;
    if(*flag) {
        num_args = 4;
        GET_STATUSES_INFO(count, indices, array_of_statuses);
        void **args = assemble_args_list(num_args, &count, ids, flag);
        int sizes[] = { sizeof(count), count*sizeof(int), sizeof(int), sizeof(statuses_info)};
        PILGRIM_TRACING_2(num_args, sizes, args, -1);
    } else {
        num_args = 3;
        void **args = assemble_args_list(num_args, &count, ids, flag);
        int sizes[] = { sizeof(count), count*sizeof(int), sizeof(int) };
        PILGRIM_TRACING_2(num_args, sizes, args, -1);
    }

    return 0;
}

int MPI_Testsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status array_of_statuses[])
{
    COPY_REQUESTS(incount);

	PILGRIM_TRACING_1(int, MPI_Testsome, (incount, array_of_requests, outcount, array_of_indices, array_of_statuses));

    int num_args = 5;
    if(*outcount > 0) {
        GET_STATUSES_INFO(*outcount, array_of_indices, array_of_statuses);
        void **args = assemble_args_list(num_args, &incount, ids, outcount, array_of_indices, statuses_info);
        int sizes[] = { sizeof(incount), sizeof(int)*incount, sizeof(outcount), (*outcount) * sizeof(int), sizeof(statuses_info) };
        PILGRIM_TRACING_2(num_args, sizes, args, -1);
    } else {
        // *outcount == MPI_UNDEFINED, we don't keep array_of_indices and array_of_statuses
        num_args = 3;
        void **args = assemble_args_list(num_args, &incount, ids, outcount);
        int sizes[] = { sizeof(incount), sizeof(int)*incount, sizeof(outcount) };
        PILGRIM_TRACING_2(num_args, sizes, args, -1);
    }
}

int MPI_Request_free(MPI_Request *request)
{
    MPI_Request *old_req = request;

    int id = get_request_id(request);

    void **args = assemble_args_list(1, &id);
    int sizes[] = {sizeof(int)};
    PILGRIM_TRACING_1(int, MPI_Request_free, (request));

    MPI_OBJ_RELEASE(MPI_Request, request);

    PILGRIM_TRACING_2(1, sizes, args, -1);
}

int MPI_Startall(int count, MPI_Request array_of_requests[])
{
    int ids[count];
    int idx;
    for (idx = 0; idx < count; idx++)
        ids[idx] = get_request_id(&array_of_requests[idx]);

    PILGRIM_TRACING_1(int, MPI_Startall, (count, array_of_requests));

    void **args = assemble_args_list(2, &count, ids);
    int sizes[] = { sizeof(int), count*sizeof(int) };

    PILGRIM_TRACING_2(1, sizes, args, -1);
}

/*
int MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm, MPI_Request *request)

    IdupReqHash *entry = pilgrim_malloc(sizeof(IdupReqHash));

    // Use the output request as the key
    entry->key = pilgrim_malloc(sizeof(MPI_Request));
    memcpy(entry->key, request, sizeof(MPI_Request));

    // Store the newcomm
    entry->newcomm = pilgrim_malloc(sizeof(MPI_Comm));
    memcpy(entry->newcomm, newcomm, sizeof(MPI_Comm));

    int local_rank, global_rank;
    PMPI_Comm_rank(comm, &local_rank);
    PMPI_Comm_rank(MPI_COMM_WORLD, &global_rank);

    // rank 0 decides the newcomm id
    entry->id = pilgrim_malloc(sizeof(MPI_Comm) + sizeof(int));
    if(local_rank = 0) {
        memcpy(entry->id, newcomm, sizeof(MPI_Comm));
        memcpy(entry->id+sizeof(MPI_Comm), &global_rank, sizeof(int));
    }

    entry->ibcast_req = pilgrim_malloc(sizeof(MPI_Request));
    PMPI_Ibcast(entry->id, sizeof(MPI_Comm)+sizeof(int), MPI_BYTE, 0, comm, entry->ibcast_req);

    HASH_ADD_KEYPTR(hh, idup_reqs_table, entry->key, sizeof(MPI_Request), entry);
    idup_reqs_counter++;
}
*/

