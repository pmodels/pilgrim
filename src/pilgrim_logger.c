#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "pilgrim.h"
#include "utlist.h"
#include "uthash.h"

#define TIME_RESOLUTION 0.000001


// Node in utlist
typedef struct TimesPair_t {
    int start;
    int end;
    struct TimesPair_t *next;
} TimesPair;

// Entry in uthash
typedef struct RecordHash_t {
    void *key;      // func_id + concated arguments, used as key
    int key_len;
    TimesPair *times;
    UT_hash_handle hh;
} RecordHash;

struct Logger {
    int rank;
    FILE *trace_file;               // log file
    FILE *metadata_file;            // metadata file
    bool recording;                 // set to true only after initialization
    LocalMetadata local_metadata;   // Local metadata information

    RecordHash *hash_head;          // head of hash table
};

// Global object to access the Logger fileds
struct Logger __logger;





// Mode 2. Write in binary format, no compression
/*
static inline void writeInBinary(FILE *f, Record record) {
    int tstart = (record.tstart - __logger.local_metadata.tstart) / TIME_RESOLUTION;
    int tend   = (record.tend - __logger.local_metadata.tstart) / TIME_RESOLUTION;
    __membuf.append(&__membuf, &(record.status), sizeof(record.status));
    __membuf.append(&__membuf, &tstart, sizeof(tstart));
    __membuf.append(&__membuf, &tend, sizeof(tend));
    __membuf.append(&__membuf, &(record.res), sizeof(record.res));
    __membuf.append(&__membuf, &(record.func_id), sizeof(record.func_id));
    writeArguments(f, record);
}
*/

void write_record(Record record) {
    if (!__logger.recording) return;       // have not initialized yet
    /*
    printf("[Pilgrim (rank=%d)] tstart:%.6lf, tend:%.6f, func id:%d\n", __logger.rank,
            record.tstart-__logger.local_metadata.tstart,
            record.tend-__logger.local_metadata.tstart, record.func_id);
    */
    __logger.local_metadata.records_count++;

    // Get key length
    int i;
    int key_len = sizeof(record.func_id);
    for(i = 0; i < record.arg_count; i++) {
        key_len += record.arg_sizes[i];
    }

    // Concat func_id+arguments and use it as the key
    void *key = malloc(key_len);
    memcpy(key, &(record.func_id), sizeof(record.func_id));
    int pos = sizeof(record.func_id);
    for(i = 0; i < record.arg_count; i++) {
        memcpy(key+pos, record.args[i], record.arg_sizes[i]);
        pos += record.arg_sizes[i];
    }

    // Construct the Timestamp pair
    TimesPair *t = malloc(sizeof(TimesPair));
    t->start = record.tstart;
    t->end = record.tend;

    RecordHash *entry;
    HASH_FIND(hh, __logger.hash_head, key, key_len, entry);
    if(entry) {                     // Found, insert the (tstart, tend) pair.
        LL_PREPEND(entry->times, t);
    } else {                        // Not exisit, add to hash table
        entry = (RecordHash*) malloc(sizeof(RecordHash));
        entry->key = key;
        entry->times = NULL;        // The utlist head must be NULL initialized
        LL_PREPEND(entry->times, t);
        HASH_ADD_KEYPTR(hh, __logger.hash_head, entry->key, key_len, entry);
    }

}

void logger_init(int rank, int nprocs) {
    __logger.rank = rank;
    __logger.local_metadata.tstart = pilgrim_wtime();
    __logger.local_metadata.records_count = 0;
    __logger.local_metadata.compressed_records = 0;
    __logger.local_metadata.rank = rank;
    __logger.hash_head = NULL;         // Must be NULL initialized

    mkdir("logs", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    char logfile_name[256];
    char metafile_name[256];
    sprintf(logfile_name, "logs/%d.itf", rank);
    sprintf(metafile_name, "logs/%d.mt", rank);
    __logger.trace_file = fopen(logfile_name, "wb");
    __logger.metadata_file = fopen(metafile_name, "wb");


    // Global metadata, include compression mode, time resolution
    if (rank == 0) {
        FILE* global_metafh = fopen("logs/pilgrim.mt", "wb");
        GlobalMetadata global_metadata= {
            .time_resolution = TIME_RESOLUTION,
            .ranks = nprocs,
        };
        fwrite(&global_metadata, sizeof(GlobalMetadata), 1, global_metafh);
        fclose(global_metafh);
    }

    __logger.recording = true;
}


void logger_exit() {
    __logger.recording = false;

    /* Write out local metadata information */
    __logger.local_metadata.tend = pilgrim_wtime(),
    fwrite(&__logger.local_metadata, sizeof(__logger.local_metadata), 1, __logger.metadata_file);
    printf("[Pilgrim] Rank: %d, Number of records: %d\n", __logger.rank, __logger.local_metadata.records_count);

    int num = HASH_COUNT(__logger.hash_head);
    printf("hash count: %d\n", num);

    /* Clean up the hash table and list of time pair */
    RecordHash *entry, *tmp;
    TimesPair *node, *tmp2;
    HASH_ITER(hh, __logger.hash_head, entry, tmp) {
        free(entry->key);
        LL_FOREACH_SAFE(entry->times, node, tmp2) {
            LL_DELETE(entry->times, node);
            free(node);
        }
    }
    HASH_CLEAR(hh, __logger.hash_head);

    /* Close the log file */
    if ( __logger.trace_file) {
        fclose(__logger.trace_file);
        __logger.trace_file = NULL;
    }
}
