/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <math.h>
#include <unistd.h>
#include <pthread.h>

#include "pilgrim.h"
#include "pilgrim_sequitur.h"
#include "pilgrim_timings.h"
#include "pilgrim_pattern_recognition.h"
#include "utlist.h"
#include "uthash.h"
#include "mpi.h"

pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;


#define OUTPUT_DIR                  "pilgrim-logs"
char GRAMMAR_OUTPUT_PATH[256];
char INTERVALS_OUTPUT_PATH[256];
char DURATIONS_OUTPUT_PATH[256];
char FUNCS_OUTPUT_PATH[256];
char METADATA_OUTPUT_PATH[256];

static int current_terminal_id = 0;

typedef struct OffsetNode_t {
    MPI_Offset offset;              // could be offset or size.
    struct OffsetNode_t *next;
} OffsetNode;

TimingNode *g_durations = NULL;
TimingNode *g_intervals = NULL;


struct Logger {
    int rank;
    int nprocs;
    bool debug;                     // enable debug output
    bool recording;                 // set to true only after initialization
    LocalMetadata local_metadata;   // local metadata information

    RecordHash *hash_head;          // head of CST hash table

    OffsetNode *offset_list;        // List of MPI_Offset

    Grammar grammar;                // Context-free-grammar for the MPI calls
    Grammar durations_grammar;
    Grammar intervals_grammar;

    double final_grammar_size;      // compressed grammar size (in KB)
    double final_cst_size;          // compressed cst size (in KB)

    char *timing_mode;              // check pilgrim_timing.h
};

// Global object to access the Logger fileds
struct Logger __logger;


void append_offset(MPI_Offset offset) {
    /*
    OffsetNode *new_node = (OffsetNode*) pilgrim_malloc(sizeof(OffsetNode));
    new_node->offset = offset;
    LL_PREPEND(__logger.offset_list, new_node);
    */
}

bool is_recording() {
    return __logger.recording;
}


void cleanup_cst(RecordHash* table) {
    RecordHash *entry, *tmp;
    HASH_ITER(hh, table, entry, tmp) {
        HASH_DEL(table, entry);

        TimingNode *elt, *tmp2;
        LL_FOREACH_SAFE(entry->durations, elt, tmp2) {
            LL_DELETE(entry->durations,  elt);
            pilgrim_free(elt, sizeof(TimingNode));
        }
        LL_FOREACH_SAFE(entry->intervals, elt, tmp2) {
            LL_DELETE(entry->intervals,  elt);
            pilgrim_free(elt, sizeof(TimingNode));
        }

        pilgrim_free(entry->key, entry->key_len);
        pilgrim_free(entry, sizeof(RecordHash));
    }
    table = NULL;
}

/**
 * Serialize the local CST into
 * a contiguous memory space.
 * | number of entries |
 * | terminal id 1 | rank | key len 1 | count | key 1 |
 * ...
 * | terminal id N | rank | key len N | count | key N |
 *
 * @len: output, the length of this memory space
 * @return: the address of this memory space.
 *
 */
void* serialize_cst(RecordHash *table, size_t *len) {
    *len = sizeof(int);

    RecordHash *entry, *tmp;
    HASH_ITER(hh, table, entry, tmp) {
        *len = *len + entry->key_len + sizeof(int)*3 + sizeof(unsigned);
    }

    int count = HASH_COUNT(table);
    void *res = pilgrim_malloc(*len);
    void *ptr = res;

    memcpy(ptr, &count, sizeof(int));
    ptr += sizeof(int);

    HASH_ITER(hh, table, entry, tmp) {

        memcpy(ptr, &entry->terminal_id, sizeof(int));
        ptr = ptr + sizeof(int);

        memcpy(ptr, &entry->rank, sizeof(int));
        ptr = ptr + sizeof(int);

        memcpy(ptr, &entry->key_len, sizeof(int));
        ptr = ptr + sizeof(int);

        memcpy(ptr, &entry->count, sizeof(unsigned));
        ptr = ptr + sizeof(unsigned);

        memcpy(ptr, entry->key, entry->key_len);
        ptr = ptr + entry->key_len;
    }

    return res;
}

// Caller need to be sure that data containts no duplicated keys
// We don't check it when inserting entries into the hash table.
RecordHash* deserialize_cst(void *data) {
    int num;
    memcpy(&num, data, sizeof(int));

    void *ptr = data + sizeof(int);

    RecordHash *table = NULL, *entry = NULL;
    for(int i = 0; i < num; i++) {
        entry = pilgrim_malloc(sizeof(RecordHash));

        memcpy( &(entry->terminal_id), ptr, sizeof(int) );
        ptr += sizeof(int);

        memcpy( &(entry->rank), ptr, sizeof(int) );
        ptr += sizeof(int);

        memcpy( &(entry->key_len), ptr, sizeof(int) );
        ptr += sizeof(int);

        memcpy( &(entry->count), ptr, sizeof(unsigned) );
        ptr += sizeof(unsigned);

        entry->key = pilgrim_malloc(entry->key_len);
        memcpy( entry->key, ptr, entry->key_len );
        ptr += entry->key_len;

        entry->durations = NULL;
        entry->intervals = NULL;
        HASH_ADD_KEYPTR(hh, table, entry->key, entry->key_len, entry);
    }

    return table;
}


RecordHash* copy_cst(RecordHash* origin) {
    RecordHash* table = NULL;
    RecordHash *entry, *tmp, *new_entry;
    HASH_ITER(hh, origin, entry, tmp) {
        new_entry = pilgrim_malloc(sizeof(RecordHash));
        new_entry->terminal_id = entry->terminal_id;
        new_entry->key_len = entry->key_len;
        new_entry->rank = entry->rank;
        new_entry->count = entry->count;
        new_entry->key = pilgrim_malloc(entry->key_len);
        new_entry->durations = NULL;
        new_entry->intervals = NULL;
        memcpy(new_entry->key, entry->key, entry->key_len);
        HASH_ADD_KEYPTR(hh, table, new_entry->key, new_entry->key_len, new_entry);
    }
    return table;
}

/**
 * Inter-process compression for CSTs
 *
 * Log(P) phases pair-wise merge algorithm
 *
 * Hypercube like communication pattern, i.e., one dimension at a time.
 * The sends of each phase will not participate in the following phases.
 *
 * 8 ranks example:
 * phase 0: 011 --> 010
 * phase 0: 111 --> 110
 * phase 0: 001 --> 000
 * phase 0: 101 --> 100
 * phase 1: 110 --> 010
 * phase 1: 100 --> 100
 * phase 2: 010 --> 000
 *
 */
RecordHash* compress_csts() {
    int my_rank = __logger.rank;
    int other_rank;
    int mask = 1;
    bool done = false;

    int phases = pilgrim_ceil(pilgrim_log2(__logger.nprocs));

    RecordHash* merged_table = copy_cst(__logger.hash_head);

    for(int k = 0; k < phases; k++, mask*=2) {
        if(done) break;

        other_rank = my_rank ^ mask;     // other_rank = my_rank XOR 2^k

        if(other_rank >= __logger.nprocs) continue;

        size_t size;
        void* buf;

        // bigger ranks send to smaller ranks
        if(my_rank < other_rank) {
            PMPI_Recv(&size, sizeof(size), MPI_BYTE, other_rank, mask, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            buf = pilgrim_malloc(size);
            PMPI_Recv(buf, size, MPI_BYTE, other_rank, mask, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            int cst_rank, entries, key_len;
            unsigned count;
            void *ptr = buf;
            memcpy(&entries, ptr, sizeof(int));
            ptr = ptr + sizeof(int);
            for(int i = 0; i < entries; i++) {
                // skip 4 bytes terminal id
                ptr = ptr + sizeof(int);

                // 4 bytes rank
                memcpy(&cst_rank, ptr, sizeof(int));
                ptr = ptr + sizeof(int);

                // 4 bytes key length
                memcpy(&key_len, ptr, sizeof(int));
                ptr = ptr + sizeof(int);

                // 4 bytes count
                memcpy(&count, ptr, sizeof(unsigned));
                ptr = ptr + sizeof(unsigned);

                // key length bytes key
                void *key = pilgrim_malloc(key_len);
                memcpy(key, ptr, key_len);
                ptr = ptr + key_len;

                // Check to see if this function entry is already in the table
                RecordHash *entry = NULL;
                HASH_FIND(hh, merged_table, key, key_len, entry);
                if(entry) {
                    pilgrim_free(key, key_len);
                    entry->count += count;
                } else {                                // Not exist, add to hash table
                    entry = (RecordHash*) pilgrim_malloc(sizeof(RecordHash));
                    entry->key = key;
                    entry->key_len = key_len;
                    entry->rank = cst_rank;
                    entry->count = count;
                    entry->durations = NULL;
                    entry->intervals = NULL;
                    HASH_ADD_KEYPTR(hh, merged_table, key, key_len, entry);
                }
            }
            pilgrim_free(buf, size);

        } else {   // SENDER
            buf = serialize_cst(merged_table, &size);
            PMPI_Send(&size, sizeof(size), MPI_BYTE, other_rank, mask, MPI_COMM_WORLD);
            PMPI_Send(buf, size, MPI_BYTE, other_rank, mask, MPI_COMM_WORLD);
            pilgrim_free(buf, size);
            done = true;
        }
    }

    // Eventually the root (rank 0) will get the fully merged CST
    // Update (re-assign) terminal id for all unique signatures
    if(my_rank == 0) {
        //linear_regression(merged_table);
        int terminal_id = 0;
        RecordHash *entry, *tmp;
        HASH_ITER(hh, merged_table, entry, tmp) {
            entry->terminal_id = terminal_id++;
        }
    } else {
        cleanup_cst(merged_table);
    }
    return merged_table;
}

void print_cst(RecordHash *cst) {
    unsigned int us[400], count[400];
    for(int i = 0; i < 400; i++) {
        us[i] = 0;
        count[i] = 0;
    }

    RecordHash *entry, *tmp;
    HASH_ITER(hh, cst, entry, tmp) {
        short func_id;
        memcpy(&func_id, entry->key, sizeof(short));

        us[func_id]++;
        count[func_id] += entry->count;

        int args[7];
        int arg_start = sizeof(short);
        /*
        if(func_id == ID_MPI_Igatherv) {
            memcpy(args, entry->key+arg_start, sizeof(args));
            printf("[pilgrim] sendbuf: %d, sencount: %d, sendtype: %d, recvbuf: %d, recvconts: %d, displs: %d\n",
                    args[0], args[1], args[2], args[3], args[4], args[5]);
        }
        if(func_id == ID_MPI_Send) {
            memcpy(args, entry->key+arg_start+sizeof(MemPtrAttr), sizeof(int)*4);
            printf("[pilgrim] MPI_Send, count: %d, datatype: %d, dest: %d, tag: %d\n",
                    args[0], args[1], args[2], args[3]);
        }
        if(func_id == ID_MPI_Irecv) {
            memcpy(args, entry->key+arg_start+sizeof(MemPtrAttr), sizeof(int)*4);
            printf("[pilgrim] MPI_Irecv, count: %d, datatype: %d, source: %d, tag: %d\n",
                    args[0], args[1], args[2], args[3]);
        }
        */
        /*
        if(func_id == ID_MPI_Isend) {
            memcpy(args, entry->key+arg_start, sizeof(args));
            printf("[pilgrim] buf id: %d, count: %d, datatype: %d, dest: %d, tag: %d, req: %d\n",
                    args[0], args[1], args[2], args[3], args[4], args[7]);
        }
        if(func_id == ID_MPI_Waitsome) {
            int incount, outcount;
            memcpy(&incount, entry->key+arg_start, sizeof(int));
            int *reqs = pilgrim_malloc(sizeof(int) * incount);
            memcpy(reqs, entry->key+arg_start+sizeof(int), sizeof(int)*incount);
            memcpy(&outcount, entry->key+arg_start+sizeof(int)*(1+incount), sizeof(int));
            printf("[pilgrim] Waitsome(intcount=%d, reqs:", incount);
            for(int i = 0; i < incount; i++)
                printf("%d ", reqs[i]);
            pilgrim_free(reqs, sizeof(int) * incount);
            printf(", outcount: %d)\n", outcount);
        }
        */
    }

    for(int i = 0; i < 400; i++) {
        if(count[i] > 0 && __logger.debug)
            printf("%s, %d, %d\n", func_names[i], us[i], count[i]);
            //printf("Func: %s, unique signatures: %d, total count: %d\n", func_names[i], us[i], count[i]);
    }
}


/**
 * Once we gathered function entries from every rank
 * we merge them by inserting them into one hash table
 *
 */
int* dump_cst() {
    // 1. Inter-process copmression for CSTs
    // Eventually, rank 0 will have the compressed table.
    RecordHash* compressed_cst = compress_csts();

    // 2. Broadcast the merged CST to all ranks
    size_t cst_stream_size;
    void *cst_stream;

    if(__logger.rank == 0) {
        cst_stream = serialize_cst(compressed_cst, &cst_stream_size);
        PMPI_Bcast(&cst_stream_size, sizeof(cst_stream_size), MPI_BYTE, 0, MPI_COMM_WORLD);
        PMPI_Bcast(cst_stream, cst_stream_size, MPI_BYTE, 0, MPI_COMM_WORLD);

        // 3. Rank 0 write out the compressed CST
        errno = 0;
        FILE *trace_file = fopen(FUNCS_OUTPUT_PATH, "wb");
        if(trace_file) {
            fwrite(cst_stream, 1, cst_stream_size, trace_file);
            fclose(trace_file);
        } else {
            printf("[pilgrim] Open file: %s failed, errno: %d\n", FUNCS_OUTPUT_PATH, errno);
        }
    } else {
        PMPI_Bcast(&cst_stream_size, sizeof(cst_stream_size), MPI_BYTE, 0, MPI_COMM_WORLD);
        cst_stream = pilgrim_malloc(cst_stream_size);
        PMPI_Bcast(cst_stream, cst_stream_size, MPI_BYTE, 0, MPI_COMM_WORLD);

        // 3. Other rank get the compressed cst stream from rank 0
        // then convert it to the CST
        compressed_cst = deserialize_cst(cst_stream);
    }

    __logger.final_cst_size = cst_stream_size / 1024.0;


    // 4. Update function entry's terminal id
    int *update_terminal_id = pilgrim_malloc(sizeof(int) * current_terminal_id);
    RecordHash *entry, *tmp, *res;
    HASH_ITER(hh, __logger.hash_head, entry, tmp) {
        HASH_FIND(hh, compressed_cst, entry->key, entry->key_len, res);
        if(res)
            update_terminal_id[entry->terminal_id] = res->terminal_id;
        else
            printf("[pilgrim] %d Not possible! Not exist in merged table?\n", __logger.rank);
    }

    if(__logger.rank == 0 && __logger.debug)
        print_cst(compressed_cst);
    cleanup_cst(compressed_cst);
    pilgrim_free(cst_stream, cst_stream_size);
    return update_terminal_id;
}

// Compose key: (func_id, arguments)
void* compose_call_signature(Record *record, int *key_len) {
    return concat_function_args(record->func_id, record->arg_count,
            record->args, record->arg_sizes, record->comm_size, key_len);
}

void write_record(Record record) {
    if (!__logger.recording) return;       // have not initialized yet

    pthread_mutex_lock(&g_mutex);

    /*
    if(__logger.rank == 0)
       printf("[Pilgrim (rank=%d)] tstart:%.6lf, tend:%.6f, func:%s\n", __logger.rank,
       record.tstart-__logger.local_metadata.tstart,
       record.tend-__logger.local_metadata.tstart, func_names[record.func_id]);
    */

    __logger.local_metadata.records_count++;

    int key_len;
    void *key = compose_call_signature(&record, &key_len);

    RecordHash *entry = NULL;
    HASH_FIND(hh, __logger.hash_head, key, key_len, entry);
    if(entry) {                         // Found
        int c = entry->count;
        entry->avg_duration = (entry->avg_duration*c+(record.tend-record.tstart))/(c+1);
        entry->count++;
        pilgrim_free(key, key_len);
    } else {                            // Not exist, add to hash table
        entry = (RecordHash*) pilgrim_malloc(sizeof(RecordHash));
        entry->key = key;
        entry->key_len = key_len;
        entry->rank = __logger.rank;
        entry->terminal_id = current_terminal_id++;
        entry->count = 1;
        entry->tstart = record.tstart;
        entry->ext_tstart = record.tstart;

        // TODO check if we need to store lossless info
        entry->durations = NULL;
        entry->intervals = NULL;

        HASH_ADD_KEYPTR(hh, __logger.hash_head, entry->key, entry->key_len, entry);
    }

    // Store timings infomraiton
    if(strcmp(__logger.timing_mode, TIMING_MODE_AGGREGATED) == 0) {
        handle_aggregated_timing(entry, &record);
    } else if(strcmp(__logger.timing_mode, TIMING_MODE_CFG) == 0) {
        int duration_id, interval_id;
        handle_cfg_timing(entry, &record, &duration_id, &interval_id);
        append_terminal(&(__logger.intervals_grammar), interval_id, 1);
        append_terminal(&(__logger.durations_grammar), duration_id, 1);
    } else {
        TimingNode *dur_node = (TimingNode*) pilgrim_malloc(sizeof(TimingNode));
        TimingNode *int_node = (TimingNode*) pilgrim_malloc(sizeof(TimingNode));
        handle_lossless_timing(entry, &record, &(dur_node->val), &(int_node->val));
        LL_PREPEND(entry->durations, dur_node);
        LL_PREPEND(entry->intervals, int_node);

        // TODO remeber to delete global durations
        TimingNode *dur_node2 = (TimingNode*) pilgrim_malloc(sizeof(TimingNode));
        dur_node2->val = dur_node->val;
        LL_PREPEND(g_durations, dur_node2);

        TimingNode *int_node2 = (TimingNode*) pilgrim_malloc(sizeof(TimingNode));
        int_node2->val = int_node->val;
        LL_PREPEND(g_intervals, int_node2);
    }

    // Grow the MPI call grammar
    append_terminal(&(__logger.grammar), entry->terminal_id, 1);

    pthread_mutex_unlock(&g_mutex);
}

void logger_init() {
    g_program_start_time = pilgrim_wtime();
    __logger.rank = g_mpi_rank;
    __logger.nprocs = g_mpi_size;
    __logger.local_metadata.tstart = g_program_start_time;
    __logger.local_metadata.records_count = 0;
    __logger.local_metadata.rank = g_mpi_rank;
    __logger.hash_head = NULL;          // Must be NULL initialized
    __logger.offset_list = NULL;
    __logger.timing_mode = strdup(TIMING_MODE_AGGREGATED);

    // Check if users want to store non-aggregated timings
    char* tm = NULL;
    tm  = getenv("PILGRIM_TIMING_MODE");
    if(tm)
        __logger.timing_mode = strdup(tm);
    else
        __logger.timing_mode = strdup(TIMING_MODE_AGGREGATED);


    if(getenv("PILGRIM_DEBUG"))
        __logger.debug = true;


    // Set the output paths in advance because
    // application may change the cwd duration execution
    char cwd[256] = {0};
    getcwd(cwd, 256);
    sprintf(METADATA_OUTPUT_PATH, "%s/%s/pilgrim.mt", cwd, OUTPUT_DIR);
    sprintf(GRAMMAR_OUTPUT_PATH,  "%s/%s/grammars.dat", cwd, OUTPUT_DIR);
    sprintf(INTERVALS_OUTPUT_PATH,  "%s/%s/intervals.dat", cwd, OUTPUT_DIR);
    sprintf(DURATIONS_OUTPUT_PATH,  "%s/%s/durations.dat", cwd, OUTPUT_DIR);
    sprintf(FUNCS_OUTPUT_PATH,    "%s/%s/funcs.dat", cwd, OUTPUT_DIR);

    if(__logger.rank == 0)
        mkdir(OUTPUT_DIR, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    PMPI_Barrier(MPI_COMM_WORLD);

    // Global metadata, include compression mode, time resolution
    if (__logger.rank == 0) {
        FILE* global_metafh = fopen(METADATA_OUTPUT_PATH, "wb");
        GlobalMetadata global_metadata= {
            .time_resolution = TIME_RESOLUTION,
            .ranks = g_mpi_size,
            .timing_mode = 0, // TODO need to store the actual mode
        };
        fwrite(&global_metadata, sizeof(GlobalMetadata), 1, global_metafh);
        fclose(global_metafh);
    }

    sequitur_init(&(__logger.grammar));
    if(strcmp(__logger.timing_mode, TIMING_MODE_CFG) == 0) {
        sequitur_init(&(__logger.intervals_grammar));
        sequitur_init(&(__logger.durations_grammar));
    }

    install_mem_hooks();
    __logger.recording = true;
}


void logger_exit() {
    uninstall_mem_hooks();
    __logger.recording = false;

    //printf("[pilgrim] Rank: %d, Hash: %d, Number of records: %d\n", __logger.rank,
    //        HASH_COUNT(__logger.hash_head), __logger.local_metadata.records_count);
    double local_calls = __logger.local_metadata.records_count/1000.0/1000.0;
    double total_calls;
    PMPI_Reduce(&local_calls, &total_calls, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // 1. Inter-process compression of CSTs
    double cst_compression_time = pilgrim_wtime();
    int* update_terminal_id = dump_cst();
    sequitur_update(&(__logger.grammar), update_terminal_id);
    pilgrim_free(update_terminal_id, sizeof(int)*current_terminal_id);
    cst_compression_time = pilgrim_wtime() - cst_compression_time;

    // 2. Inter-process copmression of CFGs
    double cfg_compression_time = pilgrim_wtime();
    __logger.final_grammar_size = sequitur_finalize(GRAMMAR_OUTPUT_PATH, &(__logger.grammar));
    cfg_compression_time = pilgrim_wtime() - cfg_compression_time;

    // 3. Write out timing information
    if(strcmp(__logger.timing_mode, TIMING_MODE_CFG) == 0)
        write_cfg_timings(&(__logger.durations_grammar), &(__logger.intervals_grammar), __logger.rank, __logger.nprocs, total_calls);
    if(strcmp(__logger.timing_mode, TIMING_MODE_TEXT) == 0)
        write_text_timings(__logger.hash_head, __logger.rank);
    if(strcmp(__logger.timing_mode, TIMING_MODE_LOSSLESS) == 0)
        write_lossless_timings(__logger.hash_head, __logger.rank, __logger.nprocs, DURATIONS_OUTPUT_PATH, INTERVALS_OUTPUT_PATH);
    if(strcmp(__logger.timing_mode, TIMING_MODE_ZFP) == 0)
        write_zfp_timings(__logger.hash_head, __logger.rank, total_calls, DURATIONS_OUTPUT_PATH, INTERVALS_OUTPUT_PATH, g_durations, g_intervals);
    if(strcmp(__logger.timing_mode, TIMING_MODE_SZ) == 0)
        write_sz_timings(__logger.hash_head, __logger.rank, total_calls, DURATIONS_OUTPUT_PATH, INTERVALS_OUTPUT_PATH, g_durations, g_intervals);
    if(strcmp(__logger.timing_mode, TIMING_MODE_HIST) == 0)
        write_hist_timings(__logger.hash_head, __logger.rank, __logger.nprocs, DURATIONS_OUTPUT_PATH, INTERVALS_OUTPUT_PATH);
    if(strcmp(__logger.timing_mode, TIMING_MODE_ZSTD) == 0)
        write_zstd_timings(__logger.hash_head, __logger.rank, __logger.nprocs, DURATIONS_OUTPUT_PATH, INTERVALS_OUTPUT_PATH, g_durations);

    /*
    if(strcmp(__logger.timing_mode, TIMING_MODE_CFG) != 0) {
        //write_zstd_timings(__logger.hash_head, __logger.rank, __logger.nprocs, DURATIONS_OUTPUT_PATH, INTERVALS_OUTPUT_PATH, g_durations);

        write_zfp_timings(__logger.hash_head, __logger.rank, total_calls, DURATIONS_OUTPUT_PATH, INTERVALS_OUTPUT_PATH, g_durations, g_intervals);
        write_zfp_clustering_timings(__logger.hash_head, __logger.rank, total_calls, DURATIONS_OUTPUT_PATH, INTERVALS_OUTPUT_PATH);

        write_sz_timings(__logger.hash_head, __logger.rank, total_calls, DURATIONS_OUTPUT_PATH, INTERVALS_OUTPUT_PATH, g_durations, g_intervals);
        write_sz_clustering_timings(__logger.hash_head, __logger.rank, total_calls, DURATIONS_OUTPUT_PATH, INTERVALS_OUTPUT_PATH);

        write_hist_timings(__logger.hash_head, __logger.rank, total_calls, DURATIONS_OUTPUT_PATH, INTERVALS_OUTPUT_PATH);
    }
    */

    // 4. Clean up all resources
    cleanup_cst(__logger.hash_head);
    OffsetNode *elt, *tmp2;
    LL_FOREACH_SAFE(__logger.offset_list, elt, tmp2) {
        LL_DELETE(__logger.offset_list, elt);
        pilgrim_free(elt, sizeof(OffsetNode));
    }

    MPI_OBJ_CLEANUP_ALL();

    // Output statistics
    if(__logger.rank == 0 && __logger.debug) {
        pilgrim_report_memory_status();

        printf("[pilgrim] Total mpi calls: %f *1e6\n", total_calls);
        printf("[pilgrim] CST inter-process compression time: %.2f\n", cst_compression_time);
        printf("[pilgrim] CFG inter-process compression time: %.2f\n", cfg_compression_time);
        printf("[pilgrim] CST Size: %.2fKB, CFG Size: %.2fKB, Total: %.2fKB\n",
                __logger.final_cst_size, __logger.final_grammar_size, __logger.final_cst_size + __logger.final_grammar_size);
        fflush(stdout);
    }

    free(__logger.timing_mode);
}
