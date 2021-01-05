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


void logger_init(int rank, int nprocs);
void logger_exit();
void write_record(Record record);


bool is_recording();
void append_offset(MPI_Offset offset);



void** read_record_args(int func_id, void* buff, int* nargs);
void** read_record_args_special(int func_id, void* buff, int* nargs);


#endif
