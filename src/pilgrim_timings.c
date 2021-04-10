/**
 * Interval ID and Duration ID stored in the key
 */
#include <math.h>
#include <limits.h>
#include "pilgrim.h"
#include "pilgrim_timings.h"
#include "uthash.h"

int get_id(double val) {
    if(val==0)
        val = 0.000001;
    double base = 1.2;
    int res = log(val) / log(base);
    return res;
}

inline int min(int a, int b) {
    return a < b? a: b;
}
inline int max(int a, int b) {
    return a > b ? a: b;
}

int get_interval_id(double interval) {
    int id = get_id(interval);
    if(id < 0)
        id = -id;
    id = min(999999, id);
    return id;
}

int get_duration_id(double duration) {
    int id = get_id(duration);
    if(id < 0)
        id = -id;
    id = min(999999, id);
    return id;
}

