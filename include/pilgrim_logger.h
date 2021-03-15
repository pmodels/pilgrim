#ifndef _PILGRIM_LOG_FORMAT_H_
#define _PILGRIM_LOG_FORMAT_H_
#include <stdbool.h>
#include "mpi.h"
#include "uthash.h"

// Global variables
int g_mpi_rank;
int g_mpi_size;


typedef struct _Record {
    double tstart, tend;
    short func_id;              // 2 bytes function id
    int arg_count;
    int *arg_sizes;             // size of each argument
    void **args;                // Store all arguments in array
    int res;                    // result returned from the original function call
} Record;

// Entry in uthash
// Call signature as Key
// Terminal symbol as Val
typedef struct RecordHash_t {
    void *key;                      // func_id + arguments + duration, used as key
    int key_len;
    int rank;
    int terminal_id;                // terminal id used for sequitur compression
    double ext_tstart;              // last call's extrapolated tstart
    UT_hash_handle hh;
} RecordHash;


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


void logger_init();
void logger_exit();
void* compose_call_signature(Record *record, int *key_len);
void write_record(Record record);


bool is_recording();
void append_offset(MPI_Offset offset);


#endif
