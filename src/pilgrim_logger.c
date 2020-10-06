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
#include "pilgrim_mem_hooks.h"
#include "dlmalloc-2.8.6.h"
#include "utlist.h"
#include "uthash.h"
#include "mpi.h"

#define TIME_RESOLUTION 0.000001

static int current_terminal_id = 0;
static int current_addr_id = 0;
static int invalid_request_id = -1;
static int allocated_request_id = 0;

// Entry in uthash
typedef struct RecordHash_t {
    void *key;                      // func_id + arguments + duration, used as key
    int key_len;
    int terminal_id;                // terminal id used for sequitur compression
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
    AvlTree addr_tree;              // root of memory addresses AVL tree

    RequestHash *reqs_table;        // Active MPI_Request, mapping of <MPI_Request, id>
    RequestNode *reqs_list;         // List of free ids to be used for MPI_Request mapping
    OffsetNode *offset_list;        // List of MPI_Offset
};

// Global object to access the Logger fileds
struct Logger __logger;


/**
 * Symbolic representation for memory addresses.
 */
int* addr2id(const void* buffer) {
    AvlTree node = avl_search(__logger.addr_tree, (intptr_t) buffer);
    if(node == AVL_EMPTY) {
        // Not found in addr_tree suggests that this buffer is not dynamically allocated
        // Maybe a stack buffer so we don't know excatly the size
        // We assume it as a 1 byte memory area.
        AvlTree new_node = avl_insert(&__logger.addr_tree, (intptr_t)buffer, 1);
        new_node->id = current_addr_id++;
        return &(new_node->id);
    } else {
        // First use
        if(node->id == -1)
            node->id = current_addr_id++;
        return &(node->id);
    }
}

/*
 * Symbolic representation for MPI_Request
 */
RequestHash* request_hash_entry(MPI_Request *req) {
    if(req==NULL || *req == MPI_REQUEST_NULL)
        return NULL;

    RequestHash *entry = NULL;
    HASH_FIND(hh, __logger.reqs_table, req, sizeof(MPI_Request), entry);
    return entry;
}

int* request2id(MPI_Request *req, int source, int tag) {
    if(req==NULL || *req == MPI_REQUEST_NULL) {
        return &invalid_request_id;
    }

    RequestHash *entry = request_hash_entry(req);
    if(entry == NULL) {
        entry = dlmalloc(sizeof(RequestHash));
        entry->key = dlmalloc(sizeof(MPI_Request));
        memcpy(entry->key, req, sizeof(MPI_Request));
        entry->key_len = sizeof(MPI_Request);
        entry->req_node = __logger.reqs_list;               // get the first (head) free id
        entry->any_source = (source == MPI_ANY_SOURCE);
        entry->any_tag = (tag == MPI_ANY_TAG);

        if(entry->req_node == NULL) {                       // free list is empty, create one according to allocated_request_id
            entry->req_node = (RequestNode*) dlmalloc(sizeof(RequestNode));
            entry->req_node->id = allocated_request_id++;
        } else {                                            // free list is not empty, get the first one and remove it from list
            DL_DELETE(__logger.reqs_list, entry->req_node);
        }

        HASH_ADD_KEYPTR(hh, __logger.reqs_table, entry->key, entry->key_len, entry);
    }
    return &(entry->req_node->id);
}

void free_request(MPI_Request *req) {
    RequestHash *entry = request_hash_entry(req);
    if(entry) {
        dlfree(entry->key);
        DL_APPEND(__logger.reqs_list, entry->req_node);    // Add the id back to the free list
        HASH_DEL(__logger.reqs_table, entry);
    }
}

void append_offset(MPI_Offset offset) {
    OffsetNode *new_node = (OffsetNode*) dlmalloc(sizeof(OffsetNode));
    new_node->offset = offset;
    LL_PREPEND(__logger.offset_list, new_node);
}

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
void* merge_local_function_entries(RecordHash *hash_head, int *len) {
    *len = sizeof(int);

    RecordHash *entry, *tmp;
    HASH_ITER(hh, hash_head, entry, tmp) {
        *len = *len + sizeof(int) * 2 + entry->key_len;
    }

    int count = HASH_COUNT(__logger.hash_head);
    void *res = dlmalloc(*len);
    void *ptr = res;

    memcpy(ptr, &count, sizeof(int));
    ptr += sizeof(int);

    HASH_ITER(hh, hash_head, entry, tmp) {

        memcpy(ptr, &entry->terminal_id, sizeof(int));
        ptr = ptr + sizeof(int);

        memcpy(ptr, &entry->key_len, sizeof(int));
        ptr = ptr + sizeof(int);

        memcpy(ptr, entry->key, entry->key_len);
        ptr = ptr + entry->key_len;
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
    void *local = merge_local_function_entries(__logger.hash_head, &len_local);

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
        gathered = dlmalloc(*len_sum);
    PMPI_Gatherv(local, len_local, MPI_BYTE, gathered, recvcounts, displs, MPI_BYTE, 0, MPI_COMM_WORLD);

    dlfree(local);
    return gathered;
}


/**
 * Once we gathered function entries from every rank
 * we compress them by inserting them into one hash table
 *
 * Then we transfer the compressed table into a contiguous memory space
 */
void* compress_gathered_function_entries(void *gathered, int *out_len) {
    RecordHash *compressed_table = NULL;
    int terminal_id, key_len;
    void *ptr = gathered;
    void *key;

    int before = 0, after = 0;

    for(int rank = 0; rank < __logger.nprocs; rank++) {
        int count;
        memcpy(&count, ptr, sizeof(int));
        ptr = ptr + sizeof(int);

        // function entries for one rank
        for(int i = 0 ; i < count; i++) {

            // 4 bytes terminal id
            ptr = ptr + sizeof(int);

            // 4 bytes key length
            memcpy(&key_len, ptr, sizeof(int));
            ptr = ptr + sizeof(int);

            // key length bytes key
            key = dlmalloc(key_len);
            memcpy(key, ptr, key_len);
            ptr = ptr + key_len;

            // Check to see if this function entry is already in the table
            RecordHash *entry;
            HASH_FIND(hh, compressed_table, key, key_len, entry);
            if(entry) {                         // Found, do nothing for now...
                dlfree(key);
            } else {                            // Not exist, add to hash table
                entry = (RecordHash*) dlmalloc(sizeof(RecordHash));
                entry->key = key;
                entry->key_len = key_len;
                HASH_ADD_KEYPTR(hh, compressed_table, entry->key, key_len, entry);
                after++;
            }
            before++;
        }
    }

    printf("Inter-process function entry compression: before: %d, after: %d\n", before, after);
    void *compressed = merge_local_function_entries(compressed_table, out_len);

    // Clean this compressed table as it is no longer used
    RecordHash *entry, *tmp;
    HASH_ITER(hh, compressed_table, entry, tmp) {
        dlfree(entry->key);
    }
    HASH_CLEAR(hh, compressed_table);

    return compressed;
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

        int compressed_len;
        void* compressed = compress_gathered_function_entries(gathered, &compressed_len);
        dlfree(gathered);

        FILE *trace_file = fopen("./logs/funcs.dat", "wb");
        fwrite(compressed, compressed_len, 1, trace_file);
        fclose(trace_file);
        dlfree(compressed);
    }
}

void write_record(Record record) {
    if (!__logger.recording) return;       // have not initialized yet
    /*
    if(__logger.rank == 1)
        printf("[Pilgrim (rank=%d)] tstart:%.6lf, tend:%.6f, func id:%s\n", __logger.rank,
                record.tstart-__logger.local_metadata.tstart,
                record.tend-__logger.local_metadata.tstart, func_names[record.func_id]);
    */
    __logger.local_metadata.records_count++;

    // Get key length
    int i;
    int key_len = sizeof(record.func_id);
    for(i = 0; i < record.arg_count; i++)
        key_len += record.arg_sizes[i];

    // Concat func_id+arguments and use it as the key
    void *key = dlmalloc(key_len);
    memcpy(key, &(record.func_id), sizeof(record.func_id));
    int pos = sizeof(record.func_id);
    for(i = 0; i < record.arg_count; i++) {
        memcpy(key+pos, record.args[i], record.arg_sizes[i]);
        pos += record.arg_sizes[i];
    }


    RecordHash *entry;
    HASH_FIND(hh, __logger.hash_head, key, key_len, entry);
    if(entry) {                         // Found, insert the (tstart, tend) pair.
        dlfree(key);
    } else {                            // Not exist, add to hash table
        entry = (RecordHash*) dlmalloc(sizeof(RecordHash));
        entry->key = key;
        entry->key_len = key_len;
        entry->terminal_id = current_terminal_id;
        current_terminal_id++;
        HASH_ADD_KEYPTR(hh, __logger.hash_head, entry->key, key_len, entry);
    }

    append_terminal(entry->terminal_id);
}

void logger_init(int rank, int nprocs) {
    __logger.rank = rank;
    __logger.nprocs = nprocs;
    __logger.local_metadata.tstart = pilgrim_wtime();
    __logger.local_metadata.records_count = 0;
    __logger.local_metadata.compressed_records = 0;
    __logger.local_metadata.rank = rank;
    __logger.hash_head = NULL;          // Must be NULL initialized
    __logger.reqs_table = NULL;
    __logger.reqs_list = NULL;
    __logger.offset_list = NULL;


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
    install_hooks(__logger.rank, &__logger.addr_tree);
    __logger.recording = true;
}


void logger_exit() {
    remove_hooks();
    __logger.recording = false;

    printf("[Pilgrim] Rank: %d, Hash: %d, Number of records: %d, Remaining requests: %d\n", __logger.rank,
            HASH_COUNT(__logger.hash_head), __logger.local_metadata.records_count, HASH_COUNT(__logger.reqs_table));

    write_to_file();

    sequitur_finalize();

    // Clean up the hash table
    RecordHash *entry, *tmp;
    HASH_ITER(hh, __logger.hash_head, entry, tmp) {
        dlfree(entry->key);
    }
    HASH_CLEAR(hh, __logger.hash_head);

    avl_destroy(__logger.addr_tree);
}
