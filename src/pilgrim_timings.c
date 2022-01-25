/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */
#include <math.h>
#include <limits.h>
#include "pilgrim.h"
#include "pilgrim_timings.h"
#include "uthash.h"

#include "zfp.h"
#include "sz.h"
#include "zstd.h"

#define REL_ERR     (0.1)
#define BASE        (1.0+REL_ERR)
#define ZERO_BIN_ID (9999999)

double mean(int arr[], int N)
{
    double avg = 0;
    for (int i = 0; i < N; i++) {
        if(arr[i] != ZERO_BIN_ID)
            avg += (arr[i] - avg) / (i + 1);
    }
    return avg;
}


struct hist_entry {
    int val;
    int count;
};

static int int_comp(const void *p1, const void *p2)
{
    struct hist_entry *he1 = (struct hist_entry*) p1;
    struct hist_entry *he2 = (struct hist_entry*) p2;
    if ( he1->count == he2->count ) return 0;
    else if ( he1->count < he2->count ) return 1;
    else return -1;
}

int top_eight_counts_sum(int arr[], int N, int* top_eight) {
    int count[256] = {0};
    for(int i = 0; i < N; i++) {
        count[arr[i]]++;
    }

    struct hist_entry hists[256];
    for(int i = 0; i < 256; i++) {
        hists[i].val = i;
        hists[i].count = count[i];
    }

    qsort(hists, 256, sizeof(struct hist_entry), int_comp);

    int sum = 0;
    for(int i = 0; i < 8; i++) {
        sum += hists[i].count;
        top_eight[i] = hists[i].val;
    }
    return sum;
}

static inline int mymin(int a, int b) {
    return a < b ? a: b;
}

static inline int myceil(double v) {
    double a = v - ((int)v);
    if(a > 0.5)
        return 1 + (int)v;
    return (int)v;
}

static inline int get_bin_id(double val) {
    if(val <= 10*TIME_RESOLUTION)
        return 0;
        //return ZERO_BIN_ID;      // a constant number to represent 0

    int id = myceil(log(val)/log(BASE));
    if(id < 0) id = -id;
    id = mymin(255, id);
    return id;
}

static inline int get_bin_id_int(int val) {
    if(val <= 10)
        return 0;
        //return ZERO_BIN_ID;      // a constant number to represent 0

    int id = 0;
    id = myceil(log(val)/log(BASE));
    if(id < 0) id = -id;
    id = mymin(255, id);
    return id;
}

/*
 * By default, keep only aggregated timing inofrmation
 */
void handle_aggregated_timing(RecordHash* entry, Record* record) {
    double duration = record->tend - record->tstart;
    double t = (duration - entry->avg_duration);
    unsigned previous_count = entry->count - 1;

    entry->avg_duration = (entry->avg_duration * previous_count + duration) / entry->count;
    entry->std_duration = (entry->std_duration * previous_count +  t*t) / entry->count;

    entry->tstart = record->tstart;
}

/*
 * If required, we can also store non-aggregated timing information
 *
 * We bin durations and intervals with exponential bins,
 * thus bonding the relative error to (BASE-1.0).
 */
void handle_cfg_timing(RecordHash* entry, Record* record, int *duration_id, int* interval_id) {
    double duration = record->tend - record->tstart;        // in seconds
    double interval = record->tstart - entry->ext_tstart;   // in seconds
    int duration_i = duration / TIME_RESOLUTION;
    int interval_i = interval / TIME_RESOLUTION;

    *duration_id = get_bin_id_int(duration_i);
    *interval_id = get_bin_id_int(interval_i);

    entry->tstart = record->tstart;
    entry->ext_tstart += interval_i * TIME_RESOLUTION;

    /*
     * Code for calculating abs/rel errors
     */
    /*
    static double max_duration_rel_err;
    static double max_interval_rel_err;
    double saved_duration = 0, saved_interval = 0;
    if(*duration_id != ZERO_BIN_ID)
        saved_duration = pow(BASE, *duration_id) * TIME_RESOLUTION;
    if(*interval_id != ZERO_BIN_ID)
        saved_interval = pow(BASE, *interval_id) * TIME_RESOLUTION;
    double err = fabs(saved_duration - duration);
    double re = err / interval;
    assert(re <= REL_ERR);
    */
}



/**
 * We can also store lossless timing
 * Later, we can use external compressor tool like fpzip to compress it
 */
void handle_lossless_timing(RecordHash *entry, Record* record, double *duration, double *interval) {
    *duration = record->tend - record->tstart;        // in seconds
    *interval = record->tstart - entry->tstart;

    entry->tstart = record->tstart;
}

void write_to_file(char* duration_path, char* interval_path, double* durations, double* intervals, int total) {
    FILE* f;
    f = fopen(duration_path, "w");
    fwrite(durations, sizeof(double), total, f);
    fclose(f);

    f = fopen(interval_path, "w");
    fwrite(intervals, sizeof(double), total, f);
    fclose(f);
}

void write_text_timings(RecordHash* cst, int mpi_rank) {
    if(mpi_rank != 1) return;

    RecordHash *entry, *tmp;
    TimingNode *tn;

    char dur_path[64] = {0};
    char raw_dur_path[64] = {0};
    sprintf(dur_path, "./durations.%d", mpi_rank);
    sprintf(raw_dur_path, "./durations_raw.%d", mpi_rank);

    FILE* f_dur = fopen(dur_path, "w");
    FILE* f_raw_dur = fopen(raw_dur_path, "w");

    int i = 0;
    HASH_ITER(hh, cst, entry, tmp) {
        int count;
        LL_COUNT(entry->durations, tn, count);

        //if(count > 100) {
            short func_id;
            memcpy(&func_id, entry->key, sizeof(short));
            fprintf(f_dur, "%s\n", func_names[func_id]);
            fprintf(f_raw_dur, "%s\n", func_names[func_id]);

            int j = 0;
            LL_FOREACH(entry->durations, tn) {
                //fprintf(f_dur, "%d, ", get_bin_id(tn->val));
                fprintf(f_raw_dur, "%d\n", (int)(tn->val/TIME_RESOLUTION));    // in us
                //if( j++ > 100) break;
            }

            fprintf(f_dur, "\n");
            fprintf(f_raw_dur, "\n");
        //}
    }

    fflush(f_dur);
    fflush(f_raw_dur);
    fclose(f_dur);
    fclose(f_raw_dur);
}

/**
 * Save the lossless timings into files
 */
void write_lossless_timings(RecordHash* cst, int mpi_rank, int mpi_size, char* dur_path, char* int_path) {
    RecordHash *entry, *tmp;
    TimingNode *elt, *tmp2;

    int local_total = 0;
    HASH_ITER(hh, cst, entry, tmp) {
        int count = 0;
        LL_COUNT(entry->intervals, elt, count);
        local_total += count;
    }

    double *local_durations = pilgrim_malloc(sizeof(double) * local_total);
    double *local_intervals = pilgrim_malloc(sizeof(double) * local_total);
    double *global_durations, *global_intervals;

    int i = 0, j = 0;
    HASH_ITER(hh, cst, entry, tmp) {
        LL_FOREACH_SAFE(entry->durations, elt, tmp2) {
            local_durations[i++] = elt->val;
        }
        LL_FOREACH_SAFE(entry->intervals, elt, tmp2) {
            local_intervals[j++] = elt->val;
        }
    }

    int recv_counts[mpi_size], displs[mpi_size];
    PMPI_Gather(&local_total, 1, MPI_INT, recv_counts, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int global_total = recv_counts[0];
    displs[0] = 0;
    for(int i = 1; i < mpi_size; i++) {
        global_total += recv_counts[i];
        displs[i] = displs[i-1] + recv_counts[i-1];
    }


    if(mpi_rank == 0) {
        global_durations = pilgrim_malloc(sizeof(double)*global_total);
        global_intervals = pilgrim_malloc(sizeof(double)*global_total);
    }

    PMPI_Gatherv(local_durations, local_total, MPI_DOUBLE, global_durations, recv_counts, displs, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    PMPI_Gatherv(local_intervals, local_total, MPI_DOUBLE, global_intervals, recv_counts, displs, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    pilgrim_free(local_durations, sizeof(double)*local_total);
    pilgrim_free(local_intervals, sizeof(double)*local_total);

    PMPI_Barrier(MPI_COMM_WORLD);
    if(mpi_rank == 0) {
        write_to_file(dur_path, int_path, global_durations, global_intervals, global_total);
        pilgrim_free(global_durations, sizeof(double)*global_total);
        pilgrim_free(global_intervals, sizeof(double)*global_total);
    }
}

void write_zfp_timings(RecordHash* cst, int mpi_rank, double total_calls, char* dur_path, char* int_path, TimingNode *g_durations, TimingNode* g_intervals)  {
    TimingNode *elt, *tmp;

    int local_total = 0;
    LL_COUNT(g_durations, elt, local_total);

    double *local_durations = pilgrim_malloc(sizeof(double) * local_total);
    double *local_intervals = pilgrim_malloc(sizeof(double) * local_total);

    int i = 0;
    LL_FOREACH_SAFE(g_durations, elt, tmp) {
        local_durations[i++] = elt->val;
    }
    i = 0;
    LL_FOREACH_SAFE(g_intervals, elt, tmp) {
        local_intervals[i++] = elt->val;
    }

    // ---------------------
    // 1. Durations
    zfp_type type = zfp_type_double;                                     // array scalar type
    zfp_field* field = zfp_field_1d(local_durations, type, local_total); // array metadata
    // initialize metadata for a compressed stream
    zfp_stream* zfp = zfp_stream_open(NULL);                  // compressed stream and parameters
    zfp_stream_set_accuracy(zfp, 10*TIME_RESOLUTION);         // set tolerance for fixed-accuracy mode, this is absolute error
    // allocate buffer for compressed data
    size_t bufsize = zfp_stream_maximum_size(zfp, field);     // capacity of compressed buffer (conservative)
    void* buffer = pilgrim_malloc(bufsize);                   // storage for compressed stream
    // associate bit stream with allocated buffer
    bitstream* stream = stream_open(buffer, bufsize);         // bit stream to compress to
    zfp_stream_set_bit_stream(zfp, stream);                   // associate with compressed stream
    zfp_stream_rewind(zfp);                                   // rewind stream to beginning
    // compress array
    size_t duration_outsize = zfp_compress(zfp, field);       // return value is byte size of compressed stream
    void* raw = stream_data(stream);
    zfp_stream_close(zfp);
    stream_close(stream);
    pilgrim_free(buffer, bufsize);
    // ---------------------


    // ---------------------
    // 2. Intervals
    field = zfp_field_1d(local_intervals, type, local_total); // array metadata
    // initialize metadata for a compressed stream
    zfp = zfp_stream_open(NULL);                              // compressed stream and parameters
    zfp_stream_set_accuracy(zfp, 10*TIME_RESOLUTION);         // set tolerance for fixed-accuracy mode, this is absolute error
    // allocate buffer for compressed data
    bufsize = zfp_stream_maximum_size(zfp, field);            // capacity of compressed buffer (conservative)
    buffer = pilgrim_malloc(bufsize);                         // storage for compressed stream
    // associate bit stream with allocated buffer
    stream = stream_open(buffer, bufsize);                    // bit stream to compress to
    zfp_stream_set_bit_stream(zfp, stream);                   // associate with compressed stream
    zfp_stream_rewind(zfp);                                   // rewind stream to beginning
    // compress array
    size_t interval_outsize = zfp_compress(zfp, field);       // return value is byte size of compressed stream
    raw = stream_data(stream);
    zfp_stream_close(zfp);
    stream_close(stream);
    pilgrim_free(buffer, bufsize);
    // ---------------------

    pilgrim_free(local_durations, sizeof(double)*local_total);
    pilgrim_free(local_intervals, sizeof(double)*local_total);

    double local_dur_kb = duration_outsize / 1024.0;
    double local_int_kb = interval_outsize / 1024.0;
    double total_dur_kb , total_int_kb;
    PMPI_Reduce(&local_dur_kb, &total_dur_kb, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    PMPI_Reduce(&local_int_kb, &total_int_kb, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if(mpi_rank == 0) {
        printf("ZFP duration compression ratio: %f, interval compression ratio: %f\n",
                total_calls*1e6/total_dur_kb/1024.0*sizeof(double), total_calls*1e6/total_int_kb/1024.0*sizeof(double));
    }

    PMPI_Barrier(MPI_COMM_WORLD);
}

void write_zfp_clustering_timings(RecordHash* cst, int mpi_rank, double total_calls, char* dur_path, char* int_path)  {

    RecordHash *entry, *tmp;
    TimingNode *elt, *tmp2;

    int local_total = 0;
    HASH_ITER(hh, cst, entry, tmp) {
        int count = 0;
        LL_COUNT(entry->intervals, elt, count);
        local_total += count;
    }

    double *local_durations = pilgrim_malloc(sizeof(double) * local_total);
    double *local_intervals = pilgrim_malloc(sizeof(double) * local_total);
    int i = 0, j = 0;

    HASH_ITER(hh, cst, entry, tmp) {
        LL_FOREACH_SAFE(entry->durations, elt, tmp2) {
            local_durations[i++] = elt->val;
        }
        LL_FOREACH_SAFE(entry->intervals, elt, tmp2) {
            local_intervals[j++] = elt->val;
        }
    }

    // 1. Durations
    zfp_type type = zfp_type_double;                                     // array scalar type
    zfp_field* field = zfp_field_1d(local_durations, type, local_total); // array metadata
    // initialize metadata for a compressed stream
    zfp_stream* zfp = zfp_stream_open(NULL);                  // compressed stream and parameters
    zfp_stream_set_accuracy(zfp, 10*TIME_RESOLUTION);         // set tolerance for fixed-accuracy mode, this is absolute error
    // allocate buffer for compressed data
    size_t bufsize = zfp_stream_maximum_size(zfp, field);     // capacity of compressed buffer (conservative)
    void* buffer = pilgrim_malloc(bufsize);                   // storage for compressed stream
    // associate bit stream with allocated buffer
    bitstream* stream = stream_open(buffer, bufsize);         // bit stream to compress to
    zfp_stream_set_bit_stream(zfp, stream);                   // associate with compressed stream
    zfp_stream_rewind(zfp);                                   // rewind stream to beginning
    // compress array
    size_t duration_outsize = zfp_compress(zfp, field);       // return value is byte size of compressed stream
    void* raw = stream_data(stream);
    zfp_stream_close(zfp);
    stream_close(stream);
    pilgrim_free(buffer, bufsize);

    // 2. Intervals
    field = zfp_field_1d(local_intervals, type, local_total); // array metadata
    // initialize metadata for a compressed stream
    zfp = zfp_stream_open(NULL);                              // compressed stream and parameters
    zfp_stream_set_accuracy(zfp, 10*TIME_RESOLUTION);         // set tolerance for fixed-accuracy mode, this is absolute error
    // allocate buffer for compressed data
    bufsize = zfp_stream_maximum_size(zfp, field);            // capacity of compressed buffer (conservative)
    buffer = pilgrim_malloc(bufsize);                         // storage for compressed stream
    // associate bit stream with allocated buffer
    stream = stream_open(buffer, bufsize);                    // bit stream to compress to
    zfp_stream_set_bit_stream(zfp, stream);                   // associate with compressed stream
    zfp_stream_rewind(zfp);                                   // rewind stream to beginning
    // compress array
    size_t interval_outsize = zfp_compress(zfp, field);       // return value is byte size of compressed stream
    raw = stream_data(stream);
    zfp_stream_close(zfp);
    stream_close(stream);
    pilgrim_free(buffer, bufsize);

    pilgrim_free(local_durations, sizeof(double)*local_total);
    pilgrim_free(local_intervals, sizeof(double)*local_total);

    double local_dur_kb = duration_outsize / 1024.0;
    double local_int_kb = interval_outsize / 1024.0;
    double total_dur_kb , total_int_kb;
    PMPI_Reduce(&local_dur_kb, &total_dur_kb, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    PMPI_Reduce(&local_int_kb, &total_int_kb, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if(mpi_rank == 0) {
        printf("ZFP clustering duration compression ratio: %f, interval compression ratio: %f\n",
                total_calls*1e6/total_dur_kb/1024*sizeof(double), total_calls*1e6/total_int_kb/1024*sizeof(double));
    }

    PMPI_Barrier(MPI_COMM_WORLD);
}

double write_hist_timings_core(RecordHash* cst, int mpi_rank, char* dur_path, char* int_path, bool dur) {

    RecordHash *entry, *tmp;
    TimingNode *elt, *tmp2;

    int local_total = 0;
    HASH_ITER(hh, cst, entry, tmp) {
        int count = 0;
        LL_COUNT(entry->intervals, elt, count);
        local_total += count;
    }

    // large enough buffer for compression
    size_t buff_size = local_total*sizeof(uint16_t);
    uint16_t* buff = pilgrim_malloc(buff_size);
    memset(buff, 0, buff_size);

    int buff_idx = 0;

    HASH_ITER(hh, cst, entry, tmp) {
        int count;
        LL_COUNT(entry->durations, elt, count);

        // 1. First fill in duration or interval bining ids
        int *local_ids = pilgrim_malloc(sizeof(int) * count);
        int i = 0;
        if(dur) {
            LL_FOREACH_SAFE(entry->durations, elt, tmp2) {
                local_ids[i++] = get_bin_id(elt->val);
            }
        } else {
            LL_FOREACH_SAFE(entry->intervals, elt, tmp2) {
                local_ids[i++] = get_bin_id(elt->val);
            }
        }

        // 2. Then encode those ids one by one using a histogram based algorithm

        // if this signature has less than 8 calls, store them uncompressed
        if(count < 8) {
            for(int i = 0; i < count; i++) {
                uint16_t id = local_ids[i];
                id = 0b1000000000000000 | id;
                buff[buff_idx++] = id;
            }
            continue;
        }

        int top_eight[8];
        int c = top_eight_counts_sum(local_ids, count, top_eight);

        int mask_idx = 0;
        uint16_t masks[4] = { 0b0111000000000000, 0b0000011100000000,
                                0b0000000001110000, 0b0000000000000111};

        for(i = 0; i < count; i++) {
            int one_of_top_eight = -1;
            for(int j = 0; j < 8; j++) {
                if(top_eight[j] == local_ids[i]) {
                    one_of_top_eight = j;
                    break;
                }
            }

            if(one_of_top_eight != -1) {
                uint16_t bits = (uint16_t) one_of_top_eight;
                buff[buff_idx] |= masks[mask_idx] & ( bits << (12-3*mask_idx) );

                mask_idx++;
                if(mask_idx == 4) {
                    mask_idx = 0;
                    buff_idx++;
                }

            } else {
                uint16_t id = local_ids[i];
                id = 0b1000000000000000 | id;
                if(mask_idx == 0) {
                    buff[buff_idx++] = id;
                } else if(mask_idx == 1) {
                    buff[buff_idx++] |= (id >> 4);
                    buff[buff_idx] = (id << 12);
                } else if(mask_idx == 2) {
                    buff[buff_idx++] |= (id >> 8);
                    buff[buff_idx] = (id << 8);
                } else if(mask_idx == 3) {
                    buff[buff_idx++] |= (id >> 12);
                    buff[buff_idx] = (id << 4);
                }
            }
        }
        pilgrim_free(local_ids, sizeof(int) * count);
    }

    size_t uncompressed_bytes = buff_idx * sizeof(uint16_t);
    size_t zstd_buff_size = ZSTD_compressBound(uncompressed_bytes);
    void* zstd_buff = pilgrim_malloc(zstd_buff_size);
    size_t compressed_bytes = ZSTD_compress(zstd_buff, zstd_buff_size, buff, uncompressed_bytes, 1);

    pilgrim_free(zstd_buff, zstd_buff_size);
    pilgrim_free(buff, buff_size);

    double local_kb = compressed_bytes / 1024.0;
    double total_kb = 0;
    PMPI_Reduce(&local_kb, &total_kb, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    //printf("buff idx: %d/%d, local_kb: %f\n", buff_idx, local_total, local_kb);
    return total_kb;
}

void write_hist_timings(RecordHash* cst, int mpi_rank, double total_calls, char* dur_path, char* int_path) {
    double total_dur_kb = write_hist_timings_core(cst, mpi_rank, dur_path, int_path, true);
    double total_int_kb = write_hist_timings_core(cst, mpi_rank, dur_path, int_path, false);
    if(mpi_rank == 0) {
        printf("total_dur_kb: %f, total int kb: %f\n", total_dur_kb, total_int_kb);
        printf("HIST duration compression ratio: %f, interval compression ratio: %f\n",
                total_calls*1e6/total_dur_kb/1024.0*sizeof(double), total_calls*1e6/total_int_kb/1024.0*sizeof(double));
    }
    PMPI_Barrier(MPI_COMM_WORLD);
}


void write_sz_timings(RecordHash* cst, int mpi_rank, double total_calls, char* dur_path, char* int_path, TimingNode *g_durations, TimingNode* g_intervals) {

    TimingNode *elt, *tmp2;

    int local_total = 0;
    LL_COUNT(g_durations, elt, local_total);

    double *local_durations = pilgrim_malloc(sizeof(double) * local_total);
    double *local_intervals = pilgrim_malloc(sizeof(double) * local_total);

    int i = 0;
    LL_FOREACH_SAFE(g_durations, elt, tmp2) {
        local_durations[i++] = elt->val;
    }
    i = 0;
    LL_FOREACH_SAFE(g_intervals, elt, tmp2) {
        local_intervals[i++] = elt->val;
    }

    size_t duration_outsize, interval_outsize;
    void* raw;

    SZ_Init(NULL);
    raw = SZ_compress_args(SZ_DOUBLE, local_durations, &duration_outsize, PW_REL, 0, 0, REL_ERR, 0, 0, 0, 0, local_total);
    free(raw);
    SZ_Finalize();

    SZ_Init(NULL);
    raw = SZ_compress_args(SZ_DOUBLE, local_intervals, &interval_outsize, PW_REL, 0, 0, REL_ERR, 0, 0, 0, 0, local_total);
    free(raw);
    SZ_Finalize();

    pilgrim_free(local_durations, sizeof(double)*local_total);
    pilgrim_free(local_intervals, sizeof(double)*local_total);

    double local_dur_kb = duration_outsize / 1024.0;
    double local_int_kb = interval_outsize / 1024.0;


    double total_dur_kb , total_int_kb;
    PMPI_Reduce(&local_dur_kb, &total_dur_kb, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    PMPI_Reduce(&local_int_kb, &total_int_kb, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if(mpi_rank == 0) {
        printf("SZ duration compression ratio: %f, interval compression ratio: %f\n",
                total_calls*1e6/total_dur_kb/1024.0*sizeof(double), total_calls*1e6/total_int_kb/1024.0*sizeof(double));
    }

    PMPI_Barrier(MPI_COMM_WORLD);
}

void write_sz_clustering_timings(RecordHash* cst, int mpi_rank, double total_calls, char* dur_path, char* int_path) {

    RecordHash *entry, *tmp;
    TimingNode *elt, *tmp2;

    int local_total = 0;
    HASH_ITER(hh, cst, entry, tmp) {
        int count = 0;
        LL_COUNT(entry->intervals, elt, count);
        local_total += count;
    }

    double* local_durations = pilgrim_malloc(sizeof(double) * local_total);
    double* local_intervals = pilgrim_malloc(sizeof(double) * local_total);
    int i = 0, j = 0;

    HASH_ITER(hh, cst, entry, tmp) {
        LL_FOREACH_SAFE(entry->durations, elt, tmp2) {
            local_durations[i++] = elt->val;
        }
        LL_FOREACH_SAFE(entry->intervals, elt, tmp2) {
            local_intervals[j++] = elt->val;
        }
    }

    size_t duration_outsize, interval_outsize;
    void* raw;

    SZ_Init(NULL);
    raw = SZ_compress_args(SZ_DOUBLE, local_durations, &duration_outsize, PW_REL, 0, 0, REL_ERR, 0, 0, 0, 0, local_total);
    free(raw);
    SZ_Finalize();

    SZ_Init(NULL);
    raw = SZ_compress_args(SZ_DOUBLE, local_intervals, &interval_outsize, PW_REL, 0, 0, REL_ERR, 0, 0, 0, 0, local_total);
    free(raw);
    SZ_Finalize();

    pilgrim_free(local_durations, sizeof(int)*local_total);
    pilgrim_free(local_intervals, sizeof(int)*local_total);

    double local_dur_kb = duration_outsize / 1024.0;
    double local_int_kb = interval_outsize / 1024.0;
    double total_dur_kb , total_int_kb;
    PMPI_Reduce(&local_dur_kb, &total_dur_kb, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    PMPI_Reduce(&local_int_kb, &total_int_kb, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if(mpi_rank == 0) {
        printf("SZ clustering duration compression ratio: %f, interval compression ratio: %f\n",
                total_calls*1e6/total_dur_kb/1024.0*sizeof(double), total_calls*1e6/total_int_kb/1024.0*sizeof(double));
    }

    PMPI_Barrier(MPI_COMM_WORLD);
}


void write_zstd_timings(RecordHash* cst, int mpi_rank, int mpi_size,
                        char* dur_path, char* int_path,
                        TimingNode *g_durations) {

    RecordHash *entry, *tmp;
    TimingNode *elt, *tmp2;

    int local_total = 0;
    LL_COUNT(g_durations, elt, local_total);

    double *local_durations = pilgrim_malloc(sizeof(double) * local_total);
    double *local_intervals = pilgrim_malloc(sizeof(double) * local_total);

    int i = 0;
    LL_FOREACH_SAFE(g_durations, elt, tmp2) {
        local_durations[i++] = elt->val;
    }

    size_t buff_size = ZSTD_compressBound(local_total*sizeof(double));
    void* buff = pilgrim_malloc(buff_size);

    size_t compressed_bytes = ZSTD_compress(buff, buff_size, local_durations, local_total*sizeof(double), 1);

    pilgrim_free(buff, buff_size);

    pilgrim_free(local_durations, sizeof(double)*local_total);
    pilgrim_free(local_intervals, sizeof(double)*local_total);

    PMPI_Barrier(MPI_COMM_WORLD);
    printf("ZSTD compression ratio: %f\n", (1.0*local_total/compressed_bytes*sizeof(double)));
}

void write_cfg_timings(Grammar* duration_grammar, Grammar* interval_grammar, int mpi_rank, int mpi_size, double total_calls) {
    int compressed_integers;
    int* compressed_grammar;

    size_t zstd_buf_size;
    size_t duration_compressed_bytes, interval_compressed_bytes;
    void* zstd_buf;

    compressed_grammar = compress_serialize_grammars(mpi_rank, mpi_size, duration_grammar, &compressed_integers);
    if(mpi_rank == 0) {
        zstd_buf_size = ZSTD_compressBound(sizeof(int)*compressed_integers);
        zstd_buf = pilgrim_malloc(zstd_buf_size);
        duration_compressed_bytes = ZSTD_compress(zstd_buf, zstd_buf_size, compressed_grammar, sizeof(int)*compressed_integers, 1);
        pilgrim_free(zstd_buf, zstd_buf_size);
        pilgrim_free(compressed_grammar, sizeof(int)*compressed_integers);
    }

    compressed_grammar = compress_serialize_grammars(mpi_rank, mpi_size, interval_grammar, &compressed_integers);
    if(mpi_rank == 0) {
        zstd_buf_size = ZSTD_compressBound(sizeof(int)*compressed_integers);
        zstd_buf = pilgrim_malloc(zstd_buf_size);
        interval_compressed_bytes = ZSTD_compress(zstd_buf, zstd_buf_size, compressed_grammar, sizeof(int)*compressed_integers, 1);
        pilgrim_free(zstd_buf, zstd_buf_size);
        pilgrim_free(compressed_grammar, sizeof(int)*compressed_integers);

        printf("[pilgrim] CFG durations compression ratio: %f, CFG intervals compression ratio: %f\n",
                    total_calls*1e6/duration_compressed_bytes*sizeof(double),
                    total_calls*1e6/interval_compressed_bytes*sizeof(double));
    }

    sequitur_cleanup(duration_grammar);
    sequitur_cleanup(interval_grammar);
}
