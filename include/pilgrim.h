#ifndef _PILGRIM_H_
#define _PILGRIM_H_

#include <stdio.h>
#include "pilgrim_func_ids.h"
#include "pilgrim_logger.h"
#include "pilgrim_utils.h"


#define PILGRIM_TRACING(ret_type, func, func_call, record_arg_count, record_arg_sizes, record_args) \
    short func_id = ID_##func;                                                          \
    double tstart = pilgrim_wtime();                                                    \
    ret_type res = func_call;                                                           \
    double tend = pilgrim_wtime();                                                      \
    Record record = {                                                                   \
        .tstart = tstart,                                                               \
        .tend = tend,                                                                   \
        .func_id = func_id,                                                             \
        .arg_count = record_arg_count,                                                  \
        .arg_sizes = record_arg_sizes,                                                  \
        .args = record_args,                                                            \
    };                                                                                  \
    write_record(record);                                                               \
    return res;

#endif

