#ifndef _PILGRIM_TIMINGS_H_
#define _PILGRIM_TIMINGS_H_

#include "pilgrim_logger.h"

#define TIMING_MODE_AGGREGATED      0
#define TIMING_MODE_NONAGGREGATED   1
#define TIMING_MODE_LOSSLESS        2

#define microseconds    (0.000001)
#define TIME_RESOLUTION (10*microseconds)

void handle_aggregated_timing(RecordHash* entry, Record* record);
void handle_non_aggregated_timing(RecordHash* entry, Record* record, int* duration_id, int* interval_id);
void handle_lossless_timing(RecordHash* entry, Record* record, double* duration, double* interval);

void write_lossless_timings(RecordHash* cst, int mpi_rank, int mpi_size, char* dur_path, char* int_path);

#endif
