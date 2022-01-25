/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#ifndef _PILGRIM_LOG_FORMAT_H_
#define _PILGRIM_LOG_FORMAT_H_
#include <stdbool.h>
#include "mpi.h"
#include "uthash.h"

// Global variables
int g_mpi_rank;
int g_mpi_size;
double g_program_start_time;


// Store a list of lossless duration or interval
typedef struct TimingNode_t {
    double val;
    struct TimingNode_t *next;
} TimingNode;


typedef struct _Record {
    double tstart, tend;
    short func_id;              // 2 bytes function id
    int arg_count;
    int *arg_sizes;             // size of each argument
    void **args;                // Store all arguments in array
    int res;                    // result returned from the original function call
    int comm_size;              // used to determine array argument's length during post-processing
} Record;

/*
 * Entry of the Call Signature Table
 * key: call signature
 */
typedef struct RecordHash_t {
    void *key;                      // [func_id + arguments] as key
    int key_len;

    int rank;
    int terminal_id;                // terminal id used for sequitur compression
    double tstart;                  // last call's actual tstart
    double ext_tstart;              // last call's extrapolated tstart, used by non-aggregated timing mdoe

    // statistics information
    // for aggregated timing mode
    double avg_duration;            // average duration
    double std_duration;            // standard deviation of the duration
    unsigned count;                 // count of this call signature

    // Lossless timing mode
    TimingNode *intervals;
    TimingNode *durations;

    UT_hash_handle hh;
} RecordHash;


typedef struct _LocalMetadata {
    int rank;
    double tstart;
    double tend;
    unsigned long records_count;
} LocalMetadata;


typedef struct _GlobalMetadata {
    double time_resolution;
    int ranks;
    int timing_mode;
} GlobalMetadata;


void logger_init();
void logger_exit();
void* compose_call_signature(Record *record, int *key_len);
void write_record(Record record);


bool is_recording();
void append_offset(MPI_Offset offset);


#endif
