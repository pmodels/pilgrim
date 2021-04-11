#ifndef _PILGRIM_TIMINGS_H_
#define _PILGRIM_TIMINGS_H_

#include "pilgrim_logger.h"

#define TIME_RESOLUTION (0.000001*10)

void update_timings_info(RecordHash* entry, Record* record, int* interval_id, int* duration_id);

#endif
