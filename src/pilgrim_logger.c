#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "pilgrim.h"
#include "pilgrim_sequitur.h"
#include "utlist.h"
#include "uthash.h"
#include "mpi.h"

#define TIME_RESOLUTION 0.000001

static int hash_id = 0;

// Entry in uthash
typedef struct RecordHash_t {
    void *key;      // func_id + concated arguments, used as key
    int key_len;
    int id;         // terminal id used for sequitur compression
    UT_hash_handle hh;
} RecordHash;

struct Logger {
    int rank;
    int nprocs;
    bool recording;                 // set to true only after initialization
    LocalMetadata local_metadata;   // Local metadata information

    RecordHash *hash_head;          // head of hash table
};

// Global object to access the Logger fileds
struct Logger __logger;


/**
 * Merge the local function entries into
 * a contiguous memory space.
 * | number of entries |
 * | terminal id 1 | key 1 |  ... | terminal id N | key N |
 *
 * @len: output, the length of this memory space
 * @return: the address of this memory space.
 *
 */
void* merge_function_entries(int *len) {
    *len = sizeof(int);

    RecordHash *entry, *tmp;
    HASH_ITER(hh, __logger.hash_head, entry, tmp) {
        *len = *len + sizeof(int) + entry->key_len;
    }

    int count = HASH_COUNT(__logger.hash_head);
    void *res = malloc(*len);
    void *ptr = res;

    memcpy(ptr, &count, sizeof(int));
    ptr += sizeof(int);

    HASH_ITER(hh, __logger.hash_head, entry, tmp) {
        memcpy(ptr, &entry->id, sizeof(int));
        memcpy(ptr+sizeof(int), entry->key, entry->key_len);
        ptr += sizeof(int) + entry->key_len;
    }

    return res;
}

/**
 * Collect function entries in the hash table from all ranks
 * so we can write them out to a single file
 *
 * @len_sum: output, the length of all function entries.
 * @return: gathered function entries in a contiguous memory space
 */
void* gather_function_entries(int *len_sum) {
    int len_local;
    void *local = merge_function_entries(&len_local);

    int recvcounts[__logger.nprocs], displs[__logger.nprocs];

    // Gahter the length from other ranks
    PMPI_Gather(&len_local, 1, MPI_INT, recvcounts, 1, MPI_INT, 0, MPI_COMM_WORLD);

    displs[0] = 0;
    *len_sum = recvcounts[0];
    for(int i = 1; i < __logger.nprocs; i++) {
        *len_sum += recvcounts[i];
        displs[i] = displs[i-1] + recvcounts[i-1];
    }

    void *gathered = NULL;
    if(__logger.rank == 0)
        gathered = malloc(*len_sum);
    PMPI_Gatherv(local, len_local, MPI_BYTE, gathered, recvcounts, displs, MPI_BYTE, 0, MPI_COMM_WORLD);

    free(local);
    return gathered;
}


void write_to_file() {

    // Write out local metadata information
    /*
    FILE* meta_file = fopen("./logs/metadata.txt", "wb");
    __logger.local_metadata.tend = pilgrim_wtime(),
    fwrite(&__logger.local_metadata, sizeof(__logger.local_metadata), 1, __logger.metadata_file);
    fclose(meta_file);
    */

    // Collect function entries from all ranks and write to a single file
    int len;
    void* gathered = gather_function_entries(&len);

    // gathered will be NULL for all ranks except 0
    if(__logger.rank == 0) {
        FILE *trace_file = fopen("./logs/funcs.dat", "wb");
        fwrite(gathered, len, 1, trace_file);
        fclose(trace_file);
        free(gathered);
    }
}

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
    for(i = 0; i < record.arg_count; i++)
        key_len += record.arg_sizes[i];

    // Concat func_id+arguments and use it as the key
    void *key = malloc(key_len);
    memcpy(key, &(record.func_id), sizeof(record.func_id));
    int pos = sizeof(record.func_id);
    for(i = 0; i < record.arg_count; i++) {
        memcpy(key+pos, record.args[i], record.arg_sizes[i]);
        pos += record.arg_sizes[i];
    }


    RecordHash *entry;
    HASH_FIND(hh, __logger.hash_head, key, key_len, entry);
    if(entry) {                         // Found, insert the (tstart, tend) pair.

    } else {                            // Not exisit, add to hash table
        entry = (RecordHash*) malloc(sizeof(RecordHash));
        entry->key = key;
        entry->key_len = key_len;
        entry->id = hash_id;
        hash_id++;
        HASH_ADD_KEYPTR(hh, __logger.hash_head, entry->key, key_len, entry);
    }

    append_terminal(entry->id);
}

void logger_init(int rank, int nprocs) {
    __logger.rank = rank;
    __logger.nprocs = nprocs;
    __logger.local_metadata.tstart = pilgrim_wtime();
    __logger.local_metadata.records_count = 0;
    __logger.local_metadata.compressed_records = 0;
    __logger.local_metadata.rank = rank;
    __logger.hash_head = NULL;          // Must be NULL initialized

    mkdir("logs", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

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

    sequitur_init();
    __logger.recording = true;
}


void logger_exit() {
    __logger.recording = false;

    printf("[Pilgrim] Rank: %d, Hash: %d, Number of records: %d\n", __logger.rank,
            HASH_COUNT(__logger.hash_head), __logger.local_metadata.records_count);

    write_to_file();

    sequitur_finalize();

    // Clean up the hash table
    RecordHash *entry, *tmp;
    HASH_ITER(hh, __logger.hash_head, entry, tmp) {
        free(entry->key);
    }
    HASH_CLEAR(hh, __logger.hash_head);
}
