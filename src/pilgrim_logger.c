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

#include "pilgrim.h"
#include "pilgrim_sequitur.h"
#include "pilgrim_timings.h"
#include "utlist.h"
#include "uthash.h"
#include "mpi.h"


#define OUTPUT_DIR              "pilgrim-logs"
char GRAMMAR_OUTPUT_PATH[256];
char FUNCS_OUTPUT_PATH[256];
char METADATA_OUTPUT_PATH[256];


#define TIME_RESOLUTION 0.000001

static int current_terminal_id = 0;


// Entry in uthash
typedef struct RecordHash_t {
    void *key;                      // func_id + arguments + duration, used as key
    int key_len;
    int terminal_id;                // terminal id used for sequitur compression
    double tstart;                  // last call's tstart
    UT_hash_handle hh;
} RecordHash;


typedef struct OffsetNode_t {
    MPI_Offset offset;              // could be offset or size.
    struct OffsetNode_t *next;
} OffsetNode;


struct Logger {
    int rank;
    int nprocs;
    bool recording;                 // set to true only after initialization
    LocalMetadata local_metadata;   // local metadata information

    RecordHash *hash_head;          // head of function entries hash table

    OffsetNode *offset_list;        // List of MPI_Offset

    Grammar grammar;                // Context-free-grammar for the function calls
    Grammar durations_grammar;
    Grammar intervals_grammar;
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

void cleanup_function_entry_table(RecordHash* table) {
    RecordHash *entry, *tmp;
    HASH_ITER(hh, table, entry, tmp) {
        HASH_DEL(table, entry);
        pilgrim_free(entry->key, entry->key_len);
        pilgrim_free(entry, sizeof(RecordHash));
    }
    table = NULL;
}


/**
 * Serialize the local function entries into
 * a contiguous memory space.
 * | number of entries |
 * | terminal id 1 | key len 1 | key 1 |
 * ...
 * | terminal id N | key len N | key N |
 *
 * @len: output, the length of this memory space
 * @return: the address of this memory space.
 *
 */
void* serialize_function_entries(RecordHash *table, size_t *len) {
    *len = sizeof(int);

    RecordHash *entry, *tmp;
    HASH_ITER(hh, table, entry, tmp) {
        *len = *len + entry->key_len + sizeof(int)*2;
    }

    int count = HASH_COUNT(table);
    void *res = pilgrim_malloc(*len);
    void *ptr = res;

    memcpy(ptr, &count, sizeof(int));
    ptr += sizeof(int);

    HASH_ITER(hh, table, entry, tmp) {

        memcpy(ptr, &entry->terminal_id, sizeof(int));
        ptr = ptr + sizeof(int);

        memcpy(ptr, &entry->key_len, sizeof(int));
        ptr = ptr + sizeof(int);

        memcpy(ptr, entry->key, entry->key_len);
        ptr = ptr + entry->key_len;
    }

    return res;
}

// Caller need to be sure that data containts no duplicated keys
// We don't check it when inserting entries into the hash table.
RecordHash* deserialize_function_entries(void *data) {
    int num;
    memcpy(&num, data, sizeof(int));

    void *ptr = data + sizeof(int);

    RecordHash *table = NULL, *entry = NULL;
    for(int i = 0; i < num; i++) {
        entry = pilgrim_malloc(sizeof(RecordHash));

        memcpy( &(entry->terminal_id), ptr, sizeof(int) );
        ptr += sizeof(int);

        memcpy( &(entry->key_len), ptr, sizeof(int) );
        ptr += sizeof(int);

        entry->key = pilgrim_malloc(entry->key_len);
        memcpy( entry->key, ptr, entry->key_len );
        ptr += entry->key_len;

        HASH_ADD_KEYPTR(hh, table, entry->key, entry->key_len, entry);
    }

    return table;
}




/**
 * Collect function signatures from all ranks
 * Will be compressed and write out later.
 *
 * @len_sum: output, the length of all function entries.
 * @return: gathered function entries in a contiguous memory space
 */
void* gather_function_entries(size_t *len_sum) {
    size_t len_local_tmp = 0;
    void *local = NULL;
    local = serialize_function_entries(__logger.hash_head, &len_local_tmp);
    int len_local = (int)len_local_tmp;

    int recvcounts[__logger.nprocs], displs[__logger.nprocs];

    // Gahter the length from other ranks
    PMPI_Gather(&len_local, 1, MPI_INT, recvcounts, 1, MPI_INT, 0, MPI_COMM_WORLD);

    *len_sum = 0;
    displs[0] = 0;
    *len_sum = recvcounts[0];
    for(int i = 1; i < __logger.nprocs; i++) {
        *len_sum += recvcounts[i];
        displs[i] = displs[i-1] + recvcounts[i-1];
    }

    void *gathered = NULL;
    if(__logger.rank == 0) {
        gathered = pilgrim_malloc(*len_sum);
    }

    PMPI_Gatherv(local, len_local, MPI_BYTE, gathered, recvcounts, displs, MPI_BYTE, 0, MPI_COMM_WORLD);

    pilgrim_free(local, len_local);
    return gathered;
}

RecordHash* copy_function_entries(RecordHash* origin) {
    RecordHash* table = NULL;
    RecordHash *entry, *tmp, *new_entry;
    HASH_ITER(hh, origin, entry, tmp) {
        new_entry = pilgrim_malloc(sizeof(RecordHash));
        new_entry->terminal_id = entry->terminal_id;
        new_entry->key_len = entry->key_len;
        new_entry->key = pilgrim_malloc(entry->key_len);
        memcpy(new_entry->key, entry->key, entry->key_len);
        HASH_ADD_KEYPTR(hh, table, new_entry->key, new_entry->key_len, new_entry);
    }
    return table;
}

RecordHash* merge_function_entries() {
    int gap = 2;
    int rank = __logger.rank;
    int terminal_id = 0;

    RecordHash* merged_table = copy_function_entries(__logger.hash_head);

    while(gap <= __logger.nprocs) {
        size_t size;
        void* buf;
        if(rank % gap == 0) {                 // RECEIVER

            PMPI_Recv(&size, sizeof(size), MPI_BYTE, rank+gap/2, gap, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            buf = pilgrim_malloc(size);
            PMPI_Recv(buf, size, MPI_BYTE, rank+gap/2, gap, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            int added = 0;
            int entries, key_len;
            void *ptr = buf;
            memcpy(&entries, ptr, sizeof(int));
            ptr = ptr + sizeof(int);
            for(int i = 0; i < entries; i++) {
                // skip 4 bytes terminal id
                ptr = ptr + sizeof(int);

                // 4 bytes key length
                memcpy(&key_len, ptr, sizeof(int));
                ptr = ptr + sizeof(int);

                // key length bytes key
                void *key = pilgrim_malloc(key_len);
                memcpy(key, ptr, key_len);
                ptr = ptr + key_len;

                // Check to see if this function entry is already in the table
                RecordHash *entry = NULL;
                HASH_FIND(hh, merged_table, key, key_len, entry);

                // Rank 0 needs to update terminal id to ensure
                // everyone has unique terminal id
                if(entry) {
                    pilgrim_free(key, key_len);
                    entry->terminal_id = terminal_id++;
                } else {                                // Not exist, add to hash table
                    entry = (RecordHash*) pilgrim_malloc(sizeof(RecordHash));
                    entry->key = key;
                    entry->key_len = key_len;
                    entry->terminal_id = terminal_id++;
                    HASH_ADD_KEYPTR(hh, merged_table, key, key_len, entry);
                    added++;
                }
            }

            pilgrim_free(buf, size);

        } else if((rank+gap/2) % gap ==0) {   // SENDER

            buf = serialize_function_entries(merged_table, &size);
            PMPI_Send(&size, sizeof(size), MPI_BYTE, rank-gap/2, gap, MPI_COMM_WORLD);
            PMPI_Send(buf, size, MPI_BYTE, rank-gap/2, gap, MPI_COMM_WORLD);
            pilgrim_free(buf, size);

        } else {                              // DO NOTHING
        }
        gap = gap * 2;
    }

    return merged_table;
}


/**
 * Once we gathered function entries from every rank
 * we merge them by inserting them into one hash table
 *
 */
int* dump_function_entries() {
    // 1. Collect function entries from all ranks
    // Eventually, rank 0 will have the fully merged table.
    RecordHash* merged_table = merge_function_entries();

    // 2. Broadcast the merged function table to all ranks
    size_t merged_size;
    void *merged;
    if(__logger.rank !=0 )
        cleanup_function_entry_table(merged_table);
    else
        merged = serialize_function_entries(merged_table, &merged_size);

    PMPI_Bcast(&merged_size, sizeof(merged_size), MPI_BYTE, 0, MPI_COMM_WORLD);
    if(__logger.rank != 0)
        merged = pilgrim_malloc(merged_size);
    PMPI_Bcast(merged, merged_size, MPI_BYTE, 0, MPI_COMM_WORLD);

    // 3. Rank 0 write the merged function table to the file
    if(__logger.rank == 0) {
        errno = 0;
        FILE *trace_file = fopen(FUNCS_OUTPUT_PATH, "wb");
        if(trace_file) {
            printf("[pilgrim] FST Size: %.2f KB\n", merged_size/1024.0);
            fwrite(merged, 1, merged_size, trace_file);
            fclose(trace_file);
        } else {
            printf("[pilgrim] Open file: %s failed, errno: %d\n", FUNCS_OUTPUT_PATH, errno);
        }
        cleanup_function_entry_table(merged_table);
    }

    // 4. Update function entry's terminal id
    merged_table = deserialize_function_entries(merged);
    pilgrim_free(merged, merged_size);

    int *update_terminal_id = pilgrim_malloc(sizeof(int) * current_terminal_id);
    RecordHash *entry, *tmp, *res;
    HASH_ITER(hh, __logger.hash_head, entry, tmp) {
        HASH_FIND(hh, merged_table, entry->key, entry->key_len, res);
        if(res)
            update_terminal_id[entry->terminal_id] = res->terminal_id;
        else
            printf("[pilgrim] %d Not possible! Not exist in merged table?\n", __logger.rank);
    }

    cleanup_function_entry_table(merged_table);
    return update_terminal_id;
}


void write_record(Record record) {
    if (!__logger.recording) return;       // have not initialized yet

    /*
    if(__logger.rank == 0)
       printf("[Pilgrim (rank=%d)] tstart:%.6lf, tend:%.6f, func:%s\n", __logger.rank,
       record.tstart-__logger.local_metadata.tstart,
       record.tend-__logger.local_metadata.tstart, func_names[record.func_id]);
    */
    __logger.local_metadata.records_count++;

    // Compose key: (func_id, arguments)
    // Compute key length first, note func_id is a short type
    int i;
    int key_len = sizeof(record.func_id);
    for(i = 0; i < record.arg_count; i++)
        key_len += record.arg_sizes[i];

    // Actually set the key
    int pos = 0;
    void *key = pilgrim_malloc(key_len);
    memcpy(key+pos, &(record.func_id), sizeof(record.func_id));
    pos += sizeof(record.func_id);

    for(i = 0; i < record.arg_count; i++) {
        memcpy(key+pos, record.args[i], record.arg_sizes[i]);
        pos += record.arg_sizes[i];
    }

    double duration = record.tend - record.tstart;
    double interval = 0;

    RecordHash *entry = NULL;
    HASH_FIND(hh, __logger.hash_head, key, key_len, entry);
    if(entry) {                         // Found
        interval = record.tstart - entry->tstart;
        entry->tstart = record.tstart;
        pilgrim_free(key, key_len);
    } else {                            // Not exist, add to hash table
        entry = (RecordHash*) pilgrim_malloc(sizeof(RecordHash));
        entry->key = key;
        entry->key_len = key_len;
        entry->tstart = record.tstart;
        entry->terminal_id = current_terminal_id;
        current_terminal_id++;
        HASH_ADD_KEYPTR(hh, __logger.hash_head, entry->key, key_len, entry);
    }

    append_terminal(&(__logger.grammar), entry->terminal_id);


    /*
     * Durations and Intervals
     * Ignore them for now.
     *
     int dur_id = get_duration_id(duration);
     int interval_id = get_interval_id(interval);
     append_terminal(&(__logger.durations_grammar), dur_id);
     append_terminal(&(__logger.intervals_grammar), interval_id);
     if(__logger.rank == 0)
     printf("duration: %f, id: %d, interval: %f, id: %d\n", duration, dur_id, interval, interval_id);
     */
}

void logger_init(int rank, int nprocs) {
    __logger.rank = rank;
    __logger.nprocs = nprocs;
    __logger.local_metadata.tstart = pilgrim_wtime();
    __logger.local_metadata.records_count = 0;
    __logger.local_metadata.compressed_records = 0;
    __logger.local_metadata.rank = rank;
    __logger.hash_head = NULL;          // Must be NULL initialized
    __logger.offset_list = NULL;

    // Set the output paths in advance because
    // application may change the cwd duration execution
    char cwd[256] = {0};
    getcwd(cwd, 256);
    sprintf(METADATA_OUTPUT_PATH, "%s/%s/pilgrim.mt", cwd, OUTPUT_DIR);
    sprintf(GRAMMAR_OUTPUT_PATH,  "%s/%s/grammars.dat", cwd, OUTPUT_DIR);
    sprintf(FUNCS_OUTPUT_PATH,    "%s/%s/funcs.dat", cwd, OUTPUT_DIR);

    if(rank == 0) {
        mkdir(OUTPUT_DIR, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    }
    PMPI_Barrier(MPI_COMM_WORLD);

    // Global metadata, include compression mode, time resolution
    if (rank == 0) {
        FILE* global_metafh = fopen(METADATA_OUTPUT_PATH, "wb");
        GlobalMetadata global_metadata= {
            .time_resolution = TIME_RESOLUTION,
            .ranks = nprocs,
        };
        fwrite(&global_metadata, sizeof(GlobalMetadata), 1, global_metafh);
        fclose(global_metafh);
    }

    sequitur_init(&(__logger.grammar));
    sequitur_init(&(__logger.intervals_grammar));
    sequitur_init(&(__logger.durations_grammar));
    install_mem_hooks();
    __logger.recording = true;
}

void count_func_entries() {
    int count[400];
    for(int i = 0; i < 400; i++)
        count[i] = 0;

    RecordHash *entry, *tmp;
    HASH_ITER(hh, __logger.hash_head, entry, tmp) {
        if(__logger.rank == 0) {
            short func_id;
            memcpy(&func_id, entry->key, sizeof(short));
            count[func_id]++;

            int args[5];
            int arg_start = sizeof(short);
            if(func_id == ID_MPI_Isend) {
                memcpy(args, entry->key+arg_start, sizeof(args));
                printf("buf id: %d, count: %d, datatype: %d, dest: %d, tag: %d\n",
                        args[0], args[1], args[2], args[3], args[4]);
            }
        }
    }

    for(int i = 0; i < 400; i++) {
        if(count[i] > 0)
            printf("Func: %s, count: %d\n", func_names[i], count[i]);
    }
}


void logger_exit() {

    uninstall_mem_hooks();
    __logger.recording = false;

    //printf("[pilgrim] Rank: %d, Hash: %d, Number of records: %d\n", __logger.rank,
    //        HASH_COUNT(__logger.hash_head), __logger.local_metadata.records_count);

    // 1. Dump loacl metadata and call signatures
    int* update_terminal_id = dump_function_entries();

    // 2. Merge and dump grammars
    sequitur_update(&(__logger.grammar), update_terminal_id);
    pilgrim_free(update_terminal_id, sizeof(int)*current_terminal_id);

    sequitur_finalize(GRAMMAR_OUTPUT_PATH, &(__logger.grammar));
    //sequitur_finalize("logs/durations.dat", &(__logger.durations_grammar), NULL);
    //sequitur_finalize("logs/intervals.dat", &(__logger.intervals_grammar), NULL);

    // 3. Clean up all resources
    count_func_entries();
    cleanup_function_entry_table(__logger.hash_head);
    OffsetNode *elt, *tmp2;
    LL_FOREACH_SAFE(__logger.offset_list, elt, tmp2) {
        LL_DELETE(__logger.offset_list, elt);
        pilgrim_free(elt, sizeof(OffsetNode));
    }

    MPI_OBJ_CLEANUP_ALL();

    if(__logger.rank == 0)
        pilgrim_report_memory_status();
}
