/**
 * Interval ID and Duration ID stored in the key
 */
#include <math.h>
#include <limits.h>
#include "pilgrim.h"
#include "pilgrim_timings.h"
#include "uthash.h"


static inline int min(int a, int b) {
    return a < b ? a: b;
}

static inline int get_bin_id(double val) {
    if(val==0)
        val = 0.000001;
    double base = 1.2;
    int id = log(val) / log(base);
    if(id < 0) id = -id;
    id = min(999999, id);
    return id;
}

/*
 * By default, keep only aggregated timing inofrmation
 */
void handle_aggregated_timing(RecordHash* entry, Record* record) {
    double duration = record->tend - record->tstart;
    double t = (duration - entry->avg_duration);
    unsigned previous_count = entry->count - 1;

    entry->avg_duration = (entry->avg_duration * previous_count + duration) / entry->count;
    entry->std_duration = (entry->std_duration * previous_count +  t*t) / entry->count;
}

/*
 * If required, we can also store non-aggregated timing information
 */
void handle_non_aggregated_timing(RecordHash* entry, Record* record, int *interval_id, int* duration_id) {
    double duration = record->tend - record->tstart;        // in seconds
    double interval = record->tstart - entry->ext_tstart;   // in seconds
    int duration_i = duration / TIME_RESOLUTION;
    int interval_i = interval / TIME_RESOLUTION;

    *duration_id = get_bin_id(duration_i);
    *interval_id = get_bin_id(interval_i);
}

/**
 * We can also store lossless timing
 * Later, we can use external compressor tool like fzip to compress it
 */
void handle_lossless_timing(RecordHash *entry, Record* record, double *duration, double *interval) {
    *duration = record->tend - record->tstart;        // in seconds
    *interval = record->tstart - entry->ext_tstart;   // in seconds
    entry->ext_tstart = record->tstart;
}
