/**
 * Binary search tree (BST) to keep
 * existing duration bins.
 *
 * Each function has its own BST
 */
#include <math.h>
#include "pilgrim_timings.h"

int get_id(double val) {
    double base = 1.1;
    int res = log(val) / log(base);
    return res;
}

int get_interval_id(double interval) {
    return get_id(interval);
}

int get_duration_id(double duration) {
    return get_id(duration);
}

