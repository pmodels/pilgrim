/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "uthash.h"
#include "pilgrim.h"

typedef struct PatternHash_t {
    void *key;              // key is the call signature without the field will be compressed.
    int key_len;
    int a, b;               // Pattern is: val = a*rank + b, where x is the rank
    int rank, val;          // val could be dest/src or tag dependes on calls

    bool first;             // first time we insert the entry, will compute a and b next time.
    bool failed;            // if this pattern failed for some record

    UT_hash_handle hh;
} PatternHash;

PatternHash *isend_pattern_table;


void compress_isend(RecordHash *record) {
    int args[7];
    memcpy(args, record->key+sizeof(short), sizeof(args));
    int val = args[4];  // tag
    args[4] = 0;        // reset 'tag'

    PatternHash* entry = NULL;
    HASH_FIND(hh, isend_pattern_table, args, sizeof(args), entry);
    if(entry) {
        // first time here, now we have two entries
        // so we can compute a and b.
        if(entry->first) {
            int x1 = record->rank;
            int y1 = val;
            int x2 = entry->rank;
            int y2 = entry->val;
            if(x1 != x2) {
                entry->a = (y1-y2) / (x1-x2);
                entry->b = y1 - entry->a*x1;
                entry->first = false;
            }
        }
        // Otherwise, examine if the previous computed pattern
        // works for the new record as well, if not, need to mark
        // this pattern as failed so we won't test for this pattern
        // in future again.
        else {
            if(!entry->failed)
                entry->failed = (entry->a*record->rank+entry->b != val);
        }
    } else {
        entry = pilgrim_malloc(sizeof(PatternHash));
        entry->key = pilgrim_malloc(sizeof(args));
        entry->key_len = sizeof(args);
        entry->rank = record->rank;
        entry->val = val;
        entry->first = true;
        entry->failed = false;
        memcpy(entry->key, args, sizeof(args));
        HASH_ADD_KEYPTR(hh, isend_pattern_table, entry->key, entry->key_len, entry);
    }

}

void linear_regression(RecordHash* merged_cst) {
    isend_pattern_table = NULL;

    RecordHash *entry, *tmp;
    HASH_ITER(hh, merged_cst, entry, tmp) {
        short func_id;
        memcpy(&func_id, entry->key, sizeof(func_id));
        if(func_id == ID_MPI_Isend)
            compress_isend(entry);
    }

    PatternHash *pattern, *tmp2;
    HASH_ITER(hh, isend_pattern_table, pattern, tmp2) {
        if(!pattern->failed && !pattern->first)
            printf("Pattern found: %d*rank+%d\n", pattern->a, pattern->b);
        HASH_DEL(isend_pattern_table, pattern);
        pilgrim_free(pattern->key, pattern->key_len);
        pilgrim_free(pattern, sizeof(PatternHash));
    }
}
