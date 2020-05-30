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
#define RECORD_WINDOW_SIZE 3        // A sliding window for peephole compression


struct Logger {
    int rank;
    FILE *trace_file;               // log file
    FILE *metadata_file;            // metadata file
    bool recording;                 // set to true only after initialization
    LocalMetadata local_metadata;   // Local metadata information

    // For Recorder Compression Mode
    Record recordWindow[RECORD_WINDOW_SIZE];
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

    // Same function should normally have the same number of arguments
    if (old_record.arg_count != new_record.arg_count)
        return diff_record;

    // Get the number of different arguments
    int count = 0;
    int i;
    for(i = 0; i < old_record.arg_count; i++)
        if(memcmp(old_record.args[i], new_record.args[i], new_record.arg_sizes[i]) !=0)
            count++;

    // record.args store only the different arguments
    // record.status keeps track the position of different arguments
    diff_record.arg_count = count;
    int idx = 0;
    diff_record.args = malloc(sizeof(char *) * count);
    static char diff_bits[] = {0b10000001, 0b10000010, 0b10000100, 0b10001000,
                                0b10010000, 0b10100000, 0b11000000};
    for(i = 0; i < old_record.arg_count; i++) {
        if(memcmp(old_record.args[i], new_record.args[i], new_record.arg_sizes[i]) !=0) {
            diff_record.args[idx++] = new_record.args[i];
            if(i < 7) {
                diff_record.status = diff_record.status | diff_bits[i];
            }
        }
    }
    return diff_record;
}

// 0. Helper function, write all function arguments
static inline void writeArguments(FILE* f, Record record) {
    int arg_count = record.arg_count;
    void **args = record.args;
    int *sizes = record.arg_sizes;

    int i, j;
    for(i = 0; i < arg_count; i++) {
        __membuf.append(&__membuf, " ", 1);
        __membuf.append(&__membuf, args[i], sizes[i]);
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


// Mode 3. Write in Recorder format (binary + peephole compression)
static inline void writeInRecorder(FILE* f, Record new_record) {

    bool compress = false;
    Record diff_record;
    int min_diff_count = 999;
    short ref_window_id;
    short i;
    for(i = 0; i < RECORD_WINDOW_SIZE; i++) {
        Record record = __logger.recordWindow[i];
        // Only meets the following conditions that we consider to compress it:
        // 1. same function as the one in sliding window
        // 2. has at least 1 arguments
        // 3. has less than 8 arguments
        // 4. the number of different arguments is less the number of total arguments
        if ((record.func_id == new_record.func_id) && (new_record.arg_count < 8) &&
             (new_record.arg_count > 0) && (record.arg_count > 0)) {
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

    compress = false;
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

    __logger.recordWindow[2] = __logger.recordWindow[1];
    __logger.recordWindow[1] = __logger.recordWindow[0];
    __logger.recordWindow[0] = new_record;

}

void write_record(Record record) {
    if (!__logger.recording) return;       // have not initialized yet
    writeInRecorder(__logger.trace_file, record);
    printf("[Pilgrim (rank=%d)] tstart:%.6lf, tend:%.6f, func id:%d\n", __logger.rank,
            record.tstart-__logger.local_metadata.tstart,
            record.tend-__logger.local_metadata.tstart, record.func_id);
}

void logger_init(int rank, int nprocs) {

    __logger.rank = rank;
    __logger.local_metadata.tstart = pilgrim_wtime();

    mkdir("logs", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    char logfile_name[256];
    char metafile_name[256];
    sprintf(logfile_name, "logs/%d.itf", rank);
    sprintf(metafile_name, "logs/%d.mt", rank);
    __logger.trace_file = fopen(logfile_name, "wb");
    __logger.metadata_file = fopen(metafile_name, "wb");


    // Global metadata, include compression mode, time resolution
    /*
    if (rank == 0) {
        FILE* global_metafh = fopen("logs/recorder.mt", "wb");
        RecorderGlobalDef global_def = {
            .time_resolution = TIME_RESOLUTION,
            .total_ranks = nprocs,
            .compression_mode = __logger.compMode,
            .peephole_window_size = RECORD_WINDOW_SIZE
        };
        fwrite(&global_def, sizeof(RecorderGlobalDef), 1, global_metafh);

        unsigned int i;
        for(i = 0; i < 256; i++) {
            const char *funcname = get_function_name_by_id(i);
            if(funcname) {
                fwrite(funcname, strlen(funcname), 1, global_metafh);
                fwrite("\n", sizeof(char), 1, global_metafh);
            } else {
                break;
            }
        }
        fclose(global_metafh);


        FILE* version_file = fopen("logs/VERSION", "w");
        fwrite("2.1", 3, 1, version_file);
        fclose(version_file);
    }
    */

    membufInit(&__membuf);
    __logger.recording = true;
}


void logger_exit() {
    __logger.recording = false;

    /* Write out local metadata information */
    __logger.local_metadata.tend = pilgrim_wtime(),
    fwrite(&__logger.local_metadata, sizeof(__logger.local_metadata), 1, __logger.metadata_file);


    __membuf.dump(&__membuf);
    __membuf.release(&__membuf);
    /* Close the log file */
    if ( __logger.trace_file) {
        fclose(__logger.trace_file);
        __logger.trace_file = NULL;
    }
}
