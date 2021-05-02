#ifndef _PILGRIM_TIMINGS_H_
#define _PILGRIM_TIMINGS_H_

#include "pilgrim_logger.h"

#define microseconds    (0.000001)
#define TIME_RESOLUTION (10*microseconds)

void store_aggregated_timing(RecordHash* entry, Record* record);
void store_non_aggregated_timing(RecordHash* entry, Record* record, int* interval_id, int* duration_id);
void store_lossless_timing(RecordHash* entry, Record* record, double* duration, double* interval);

#endif
