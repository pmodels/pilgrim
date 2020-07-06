#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "pilgrim.h"

#define TIME_RESOLUTION 0.000001

static int uncompressed_ids[400];
static int total_ids[400];


struct Logger {
    int rank;
    FILE *trace_file;               // log file
    FILE *metadata_file;            // metadata file
    bool recording;                 // set to true only after initialization
    LocalMetadata local_metadata;   // Local metadata information

    // For Recorder Compression Mode
    int window_size;
    Record *records_window;
};
// Global object to access the Logger fileds
struct Logger __logger;


/**
 * ------------------------------------------------------------- //
 *
 * Memory buffer to hold records. Write out when its full
 *
 */
struct MemBuf {
    void *buffer;
    int size;
    int pos;
    void (*release) (struct MemBuf*);
    void (*append)(struct MemBuf*, const void* ptr, int length);
    void (*dump) (struct MemBuf*);
};

// global object to access the MemBuf methods
struct MemBuf __membuf;

void membufRelease(struct MemBuf *membuf) {
    free(membuf->buffer);
    membuf->pos = 0;
}
void membufAppend(struct MemBuf* membuf, const void *ptr, int length) {
    if (length >= membuf->size) {
        membuf->dump(membuf);
        fwrite(ptr, 1, length, __logger.trace_file);
        return;
    }
    if (membuf->pos + length >= membuf->size) {
        membuf->dump(membuf);
    }
    memcpy(membuf->buffer+membuf->pos, ptr, length);
    membuf->pos += length;
}
void membufDump(struct MemBuf *membuf) {
    fwrite(membuf->buffer, 1, membuf->pos, __logger.trace_file);
    membuf->pos = 0;
}
void membufInit(struct MemBuf* membuf) {
    membuf->size = 12*1024*1024;            // 12M
    membuf->buffer = malloc(membuf->size);
    membuf->pos = 0;
    membuf->release = membufRelease;
    membuf->append = membufAppend;
    membuf->dump = membufDump;
}
// --------------- End of Memory Buffer ------------------------ //





static inline Record get_diff_record(Record old_record, Record new_record) {
    Record diff_record;
    diff_record.status = 0b10000000;
    diff_record.arg_count = 999;    // initialize an impossible large value at first
    diff_record.arg_sizes = new_record.arg_sizes;

    // Get the number of different arguments
    int count = 0;
    int i;
    for(i = 0; i < old_record.arg_count; i++) {
        if(memcmp(old_record.args[i], new_record.args[i], new_record.arg_sizes[i]) !=0)
            count++;
    }

    // record.args store only the different arguments
    // record.status keeps track the position of different arguments
    diff_record.arg_count = count;
    int idx = 0;
    diff_record.args = malloc(sizeof(void *) * count);
    static char diff_bits[] = {0b10000001, 0b10000010, 0b10000100, 0b10001000,
                                0b10010000, 0b10100000, 0b11000000};

    for(i = 0; i < old_record.arg_count; i++) {
        if(memcmp(old_record.args[i], new_record.args[i], new_record.arg_sizes[i]) !=0) {
            diff_record.args[idx++] = new_record.args[i];
            diff_record.status = diff_record.status | diff_bits[i];
        }
    }

    return diff_record;
}

// 0. Helper function, write all function arguments
static inline void writeArguments(FILE* f, Record record) {
    int arg_count = record.arg_count;
    void **args = record.args;
    int *sizes = record.arg_sizes;

    void *null_ptr;

    int i, j;
    for(i = 0; i < arg_count; i++) {
        if(args[i] == NULL) {
            null_ptr = malloc(sizes[i]);
            memset(null_ptr, 0, sizes[i]);
            __membuf.append(&__membuf, null_ptr, sizes[i]);
            free(null_ptr);
        } else {
            __membuf.append(&__membuf, args[i], sizes[i]);
        }
    }
}

// Mode 2. Write in binary format, no compression
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

static inline bool exist_exact_match(Record new_record) {
    int i, j;
    for(i = 0; i < __logger.window_size; i++) {
        Record record = __logger.records_window[i];

        if(new_record.func_id != record.func_id || new_record.arg_count != record.arg_count)
            continue;

        bool match = true;
        for(j = 0; j < new_record.arg_count; j++) {
            if(record.args[j] == NULL || new_record.args[j]==NULL) {
                if(record.args[j] == NULL && new_record.args[j]==NULL)
                    continue;
                else {
                    match = false;
                    break;
                }
            }

            if(memcmp(record.args[j], new_record.args[j], new_record.arg_sizes[j]) !=0) {
                match = false;
                break;
            }
        }

        if(match) return true;
    }

    return false;
}


// Mode 3. Write in Recorder format (binary + peephole compression)
static inline void writeInRecorder(FILE* f, Record new_record) {
    bool compress = false;
    Record diff_record;
    int min_diff_count = 999;
    short ref_window_id;
    short i;
    for(i = 0; i < __logger.window_size; i++) {
        Record record = __logger.records_window[i];
        // Only meets the following conditions that we consider to compress it:
        // 1. same function as the one in sliding window
        // 2. has at least 1 arguments
        // 3. has less than 8 arguments
        // 4. the number of different arguments is less the number of total arguments
        if ((record.func_id == new_record.func_id) && (new_record.arg_count < 8) &&
            (new_record.arg_count > 0) && (record.arg_count == new_record.arg_count)) {
            Record tmp_record = get_diff_record(record, new_record);

            // Cond.4
            if(tmp_record.arg_count >= new_record.arg_count)
                continue;

            // Currently has the minimum number of different arguments
            if(tmp_record.arg_count < min_diff_count) {
                min_diff_count = tmp_record.arg_count;
                ref_window_id = i;
                compress = true;
                diff_record = tmp_record;
            }
        }
    }

    if (exist_exact_match(new_record)) {
        __logger.local_metadata.compressed_records++;
    } else {
        uncompressed_ids[new_record.func_id]++;
    }
    total_ids[new_record.func_id]++;

    if (compress) {
        diff_record.tstart = new_record.tstart;
        diff_record.tend = new_record.tend;
        diff_record.func_id = ref_window_id;
        diff_record.res = new_record.res;
        writeInBinary(__logger.trace_file, diff_record);
    } else {
        new_record.status = 0b00000000;
        writeInBinary(__logger.trace_file, new_record);
    }


    // Update the most recent records window
    if(__logger.window_size < 1) return;
    for(i = __logger.window_size-1; i > 0; i--)
        __logger.records_window[i] = __logger.records_window[i-1];
    __logger.records_window[0] = new_record;
}

void write_record(Record record) {
    if (!__logger.recording) return;       // have not initialized yet
    /*
    printf("[Pilgrim (rank=%d)] tstart:%.6lf, tend:%.6f, func id:%d\n", __logger.rank,
            record.tstart-__logger.local_metadata.tstart,
            record.tend-__logger.local_metadata.tstart, record.func_id);
    */
    __logger.local_metadata.records_count++;
    writeInRecorder(__logger.trace_file, record);
}

void logger_init(int rank, int nprocs) {
    __logger.rank = rank;
    __logger.local_metadata.tstart = pilgrim_wtime();
    __logger.local_metadata.records_count = 0;
    __logger.local_metadata.compressed_records = 0;
    __logger.local_metadata.rank = rank;

    mkdir("logs", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    char logfile_name[256];
    char metafile_name[256];
    sprintf(logfile_name, "logs/%d.itf", rank);
    sprintf(metafile_name, "logs/%d.mt", rank);
    __logger.trace_file = fopen(logfile_name, "wb");
    __logger.metadata_file = fopen(metafile_name, "wb");


    __logger.window_size = 3;
    const char* window_size_str = getenv("PILGRIM_WINDOW_SIZE");
    if(window_size_str)
        __logger.window_size = atoi(window_size_str);
    __logger.records_window = (Record*) malloc(sizeof(Record) * __logger.window_size);
    int i;
    for(i = 0; i < __logger.window_size; i++)
        __logger.records_window[i].func_id = -1;


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

    membufInit(&__membuf);
    __logger.recording = true;
}


void logger_exit() {
    __logger.recording = false;
    free(__logger.records_window);

    /* Write out local metadata information */
    __logger.local_metadata.tend = pilgrim_wtime(),
    fwrite(&__logger.local_metadata, sizeof(__logger.local_metadata), 1, __logger.metadata_file);
    printf("[Pilgrim] Rank: %d, Compressed (exact match): %d, Number of records: %d\n", __logger.rank, __logger.local_metadata.compressed_records, __logger.local_metadata.records_count);

    __membuf.dump(&__membuf);
    __membuf.release(&__membuf);
    /* Close the log file */
    if ( __logger.trace_file) {
        fclose(__logger.trace_file);
        __logger.trace_file = NULL;
    }

    int i;
    for(i = 0; i < 400; i++) {
        if( uncompressed_ids[i] > 0)
            printf("[Pilgrim] Rank: %d, Unmatched/Total : %s %d/%d\n", __logger.rank, func_names[i], uncompressed_ids[i], total_ids[i]);
    }
}