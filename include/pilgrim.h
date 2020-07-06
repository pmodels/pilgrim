#ifndef _PILGRIM_H_
#define _PILGRIM_H_

#include <stdio.h>
#include "pilgrim_func_ids.h"
#include "pilgrim_logger.h"
#include "pilgrim_sequitur.h"
#include "pilgrim_utils.h"


/*
#define PILGRIM_TRACING(ret_type, func, func_args, record_arg_count, record_arg_sizes, record_args) \
    short func_id = ID_##func;                                                          \
    double tstart = pilgrim_wtime();                                                    \
    ret_type res = P##func func_args;                                                   \
    double tend = pilgrim_wtime();                                                      \
    Record record = {                                                                   \
        .tstart = tstart,                                                               \
        .tend = tend,                                                                   \
        .res = res,                                                                     \
        .func_id = func_id,                                                             \
        .arg_count = record_arg_count,                                                  \
        .arg_sizes = record_arg_sizes,                                                  \
        .args = record_args,                                                            \
    };                                                                                  \
    write_record(record);                                                               \
    return res;
    */

#define PILGRIM_TRACING(ret_type, func, func_args, record_arg_count, record_arg_sizes, record_args) \
    PILGRIM_TRACING_1(ret_type, func, func_args)                                        \
    PILGRIM_TRACING_2(record_arg_count, record_arg_sizes, record_args)


// First call the original function and stores the elapsed time, func id, etc
// Need to call the function first so the output arguments have the correct value
#define PILGRIM_TRACING_1(ret_type, func, func_args)                                    \
    short func_id = ID_##func;                                                          \
    double tstart = pilgrim_wtime();                                                    \
    ret_type res = P##func func_args;                                                   \
    double tend = pilgrim_wtime();

// Then store every in a Record structure and write it to log
// Copy the arguments in case the application freed/modified the memory
#define PILGRIM_TRACING_2(record_arg_count, record_arg_sizes, record_args)              \
    Record record = {                                                                   \
        .tstart = tstart,                                                               \
        .tend = tend,                                                                   \
        .res = res,                                                                     \
        .func_id = func_id,                                                             \
        .arg_count = record_arg_count,                                                  \
        .arg_sizes = record_arg_sizes,                                                  \
    };                                                                                  \
    record.args = malloc(sizeof(void*) * record_arg_count);                             \
    int i;                                                                              \
    for(i = 0; i < record_arg_count; i++) {                                             \
        record.args[i] = malloc(record_arg_sizes[i]);                                   \
        if(record_args[i])                                                              \
            memcpy(record.args[i], record_args[i], record_arg_sizes[i]);                \
        else                                                                            \
            memset(record.args[i], 0, record_arg_sizes[i]);                             \
    }                                                                                   \
    write_record(record);                                                               \
    return res;

#endif
