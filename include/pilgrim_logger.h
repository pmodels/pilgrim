#ifndef _PILGRIM_LOG_FORMAT_H_
#define _PILGRIM_LOG_FORMAT_H_
#include <stdbool.h>
#include "mpi.h"
#include "uthash.h"

typedef struct _Record {
    double tstart, tend;
    short func_id;              // 2 bytes function id
    int arg_count;
    int *arg_sizes;             // size of each argument
    void **args;                // Store all arguments in array
    int res;                    // result returned from the original function call
} Record;


typedef struct _LocalMetadata {
    int rank;
    double tstart;
    double tend;
    int records_count;
    int compressed_records;
} LocalMetadata;

typedef struct _GlobalMetadata {
    double time_resolution;
    int ranks;
} GlobalMetadata;

typedef struct RequestHash_t {
    void *key;
    int key_len;
    int request_id;
    bool any_source;
    bool any_tag;
    UT_hash_handle hh;
} RequestHash;


void logger_init(int rank, int nprocs);
void logger_exit();
void write_record(Record record);
int* addr2id(const void *buffer);

RequestHash* request_hash_entry(MPI_Request* request);
int* request2id(MPI_Request* request, int source, int tag);
void free_request(MPI_Request* request);

void append_offset(MPI_Offset offset);


void** read_record_args(FILE*f, int func_id);
void** read_record_args_special(FILE*f, int func_id);


#endif
