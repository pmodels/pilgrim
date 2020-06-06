#ifndef _PILGRIM_LOG_FORMAT_H_
#define _PILGRIM_LOG_FORMAT_H_

typedef struct _Record {
    char status;                // peephole compressed or not
    double tstart, tend;
    short func_id;              // 2 bytes function id or ref id
    int arg_count;
    int *arg_sizes;                 // size of each argument
    void **args;                // Store all arguments in array
    int res;                    // result returned from the original function call
} Record;


typedef struct _LocalMetadata {
    double tstart;
    double tend;
    int records_count;
} LocalMetadata;

typedef struct _GlobalMetadata {
    double time_resolution;
    int ranks;
} GlobalMetadata;


void logger_init(int rank, int nprocs);
void logger_exit();
void write_record(Record record);

#endif
