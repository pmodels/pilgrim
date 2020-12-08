/**
 * Interval ID and Duration ID stored in the key
 */
#include <math.h>
#include <limits.h>
#include "pilgrim.h"
#include "pilgrim_timings.h"
#include "uthash.h"

typedef struct IntervalHash_t {
    void *key;
    int key_len;
    double tstart;
    UT_hash_handle hh;
} IntervalHash;

static IntervalHash *interval_table = NULL;


int get_id(double val) {
    if(val==0)
        return INT_MIN;
    double base = 1.1;
    int res = log(val) / log(base);
    return res;
}


double get_interval(const Record *record) {
    int i;
    int key_len = sizeof(record->func_id);
    for(i = 0; i < record->arg_count; i++)
        key_len += record->arg_sizes[i];

    void *key = dlmalloc(key_len);
    memcpy(key, &(record->func_id), sizeof(record->func_id));

    int pos = sizeof(record->func_id);
    for(i = 0; i < record->arg_count; i++) {
        memcpy(key+pos, record->args[i], record->arg_sizes[i]);
        pos += record->arg_sizes[i];
    }

    IntervalHash *entry;
    HASH_FIND(hh, interval_table, key, key_len, entry);

    double interval;
    if(entry) {                         // Found
        dlfree(key);
        interval = record->tstart - entry->tstart;
    } else {                            // Not exist, add to hash table
        entry = (IntervalHash*) dlmalloc(sizeof(IntervalHash));
        entry->key = key;
        entry->key_len = key_len;
        entry->tstart = record->tstart;

        HASH_ADD_KEYPTR(hh, interval_table, entry->key, key_len, entry);

        interval = -1;
    }

    return interval;
}

int get_interval_id(const Record* record) {
    double interval = get_interval(record);
    return get_id(interval);
}

int get_duration_id(double duration) {
    return get_id(duration);
}

