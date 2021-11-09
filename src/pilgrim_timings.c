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

static inline int min(int a, int b) {
    return a < b ? a: b;
}

static inline int get_bin_id(double val) {
    if(val <= 10*TIME_RESOLUTION)
        return 0;
        //return ZERO_BIN_ID;      // a constant number to represent 0

    int id = ceil(log(val)/log(BASE));
    if(id < 0) id = -id;
    id = min(255, id);
    return id;
}

static inline int get_bin_id_int(int val) {
    if(val <= 1000)
        return 0;
        //return ZERO_BIN_ID;      // a constant number to represent 0

    int id = ceil(log(val)/log(BASE));
    if(id < 0) id = -id;
    id = min(255, id);
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
    static double max_duration_rel_err;
    static double max_interval_rel_err;
    double saved_duration = 0, saved_interval = 0;
    if(*duration_id != ZERO_BIN_ID)
        saved_duration = pow(BASE, *duration_id) * TIME_RESOLUTION;
    if(*interval_id != ZERO_BIN_ID)
        saved_interval = pow(BASE, *interval_id) * TIME_RESOLUTION;

    err = fabs(saved_interval - interval);
    rel_err = err / interval;
    */
}



/**
 * We can also store lossless timing
 * Later, we can use external compressor tool like fpzip to compress it
 */
void handle_nocomp_timing(RecordHash *entry, Record* record, double *duration, double *interval) {
    *duration = record->tend - record->tstart;        // in seconds
    *interval = record->tstart;                       // for interval, we just store absolute tstart

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
    RecordHash *entry, *tmp;
    TimingNode *elt, *tmp2;

    char dur_path[32] = {0};
    char raw_dur_path[32] = {0};
    sprintf(dur_path, "./durations.%d", mpi_rank);
    sprintf(raw_dur_path, "./durations_raw.%d", mpi_rank);

    FILE* f_dur = fopen(dur_path, "w");
    FILE* f_raw_dur = fopen(raw_dur_path, "w");

    HASH_ITER(hh, cst, entry, tmp) {

        short func_id;
        memcpy(&func_id, entry->key, sizeof(short));
        fprintf(f_dur, "%s\n", func_names[func_id]);
        fprintf(f_raw_dur, "%s\n", func_names[func_id]);

        LL_FOREACH_SAFE(entry->durations, elt, tmp2) {
            fprintf(f_dur, "%d, ", get_bin_id(elt->val));
            fprintf(f_raw_dur, "%d\n", (int)(elt->val/TIME_RESOLUTION));    // in us
        }

        fprintf(f_dur, "\n");
        fprintf(f_raw_dur, "\n");
    }

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

void write_zfp_timings(RecordHash* cst, int mpi_rank, int mpi_size, char* dur_path, char* int_path, TimingNode *g_durations)  {

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


    /*
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
    */

    zfp_type type = zfp_type_double;                                     // array scalar type
    zfp_field* field = zfp_field_1d(local_durations, type, local_total); // array metadata

    // initialize metadata for a compressed stream
    zfp_stream* zfp = zfp_stream_open(NULL);                  // compressed stream and parameters
    zfp_stream_set_accuracy(zfp, 10*TIME_RESOLUTION);         // set tolerance for fixed-accuracy mode, this is absolute error
    //  zfp_stream_set_precision(zfp, precision);             // alternative: fixed-precision mode
    //  zfp_stream_set_rate(zfp, rate, type, 3, 0);           // alternative: fixed-rate mode

    // allocate buffer for compressed data
    size_t bufsize = zfp_stream_maximum_size(zfp, field);     // capacity of compressed buffer (conservative)
    void* buffer = pilgrim_malloc(bufsize);                   // storage for compressed stream

    // associate bit stream with allocated buffer
    bitstream* stream = stream_open(buffer, bufsize);         // bit stream to compress to
    zfp_stream_set_bit_stream(zfp, stream);                   // associate with compressed stream
    zfp_stream_rewind(zfp);                                   // rewind stream to beginning

    // compress array
    size_t zfpsize = zfp_compress(zfp, field);                // return value is byte size of compressed stream
    void* raw = stream_data(stream);
    printf("ZFP compression ratio: %f\n", 1.0*local_total/zfpsize*sizeof(double));

    pilgrim_free(local_durations, sizeof(double)*local_total);
    pilgrim_free(local_intervals, sizeof(double)*local_total);

    zfp_stream_close(zfp);
    stream_close(stream);
    pilgrim_free(buffer, bufsize);

    /* write to file
    if(mpi_rank == 0)  {
        FILE* f;
        f = fopen("./durations.zfp", "w");
        fwrite(raw, 1, zfpsize, f);
        fclose(f);
    }
    */
    PMPI_Barrier(MPI_COMM_WORLD);
}

#define SetBit(A,k)     ( A[(k)/8] |= (1 << ((k)%8)) )
#define ClearBit(A,k)   ( A[(k)/8] &= ~(1 << ((k)%8)) )
#define TestBit(A,k)    ( A[(k)/8] & (1 << ((k)%8)) )

void write_hist_timings(RecordHash* cst, int mpi_rank, int mpi_size, char* dur_path, char* int_path) {

    RecordHash *entry, *tmp;
    TimingNode *elt, *tmp2;

    int local_total = 0;
    HASH_ITER(hh, cst, entry, tmp) {
        int count = 0;
        LL_COUNT(entry->intervals, elt, count);
        local_total += count;
    }

    // large enough buffer for compression
    size_t buff_size = local_total*4;
    uint8_t* buff = pilgrim_malloc(buff_size);
    memset(buff, 0, buff_size);
    int buff_idx = 0;

    HASH_ITER(hh, cst, entry, tmp) {
        int count;
        LL_COUNT(entry->durations, elt, count);

        int *local_dur_ids = pilgrim_malloc(sizeof(int) * count);
        int i = 0;
        LL_FOREACH_SAFE(entry->durations, elt, tmp2) {
            local_dur_ids[i++] = get_bin_id(elt->val);
        }


        if(count < 8) {
            for(int i = 0; i < count; i++) {
                uint8_t id = local_dur_ids[i];
                id = 0b10000000 | id;
                buff[buff_idx++] = id;
            }
        } else {

            int top_eight[8];
            int c = top_eight_counts_sum(local_dur_ids, count, top_eight);
            //printf("%d/%d\n", c, count);

            int hi = 1;
            for(i = 0; i < count; i++) {
                int one_of_top_eight = -1;
                for(int j = 0; j < 8; j++) {
                    if(top_eight[j] == local_dur_ids[i]) {
                        one_of_top_eight = j;
                        break;
                    }
                }

                if(one_of_top_eight != -1) {
                    uint8_t bits = (uint8_t) one_of_top_eight;
                    if( hi ) {
                        buff[buff_idx] = (0b01110000 & (bits << 4));
                        hi = 0;
                    } else {
                        buff[buff_idx] |= (0b00000111 & bits);
                        hi = 1;
                        buff_idx++;
                    }
                } else {
                    uint8_t id = local_dur_ids[i];
                    id = 0b10000000 | id;
                    if(hi) {
                        buff[buff_idx] = id;
                        buff_idx++;
                    } else {
                        buff[buff_idx] |= (id >> 4);
                        buff_idx++;
                        buff[buff_idx] |= (id << 4);
                    }
                }
            }

            pilgrim_free(local_dur_ids, sizeof(int) * count);
        }
    }

    size_t zstd_buff_size = ZSTD_compressBound(buff_idx);
    void* zstd_buff = pilgrim_malloc(buff_size);
    size_t compressed_bytes = ZSTD_compress(zstd_buff, zstd_buff_size, buff, buff_idx*sizeof(uint8_t), 1);

    pilgrim_free(zstd_buff, zstd_buff_size);
    pilgrim_free(buff, buff_size);
    printf("HIST copmression ratio without ZSTD: %f, with ZSTD: %f\n",
            1.0*local_total/buff_idx/sizeof(uint8_t)*sizeof(double), 1.0*local_total/compressed_bytes*sizeof(double));
    PMPI_Barrier(MPI_COMM_WORLD);
}


void write_sz_timings(RecordHash* cst, int mpi_rank, int mpi_size, char* dur_path, char* int_path, TimingNode *g_durations) {

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

    /*
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
    */



    size_t outsize;

    SZ_Init(NULL);
    //void* raw = SZ_compress_args(SZ_DOUBLE, local_durations, &outsize, 0, 0, 0, 0, local_total);
    void* raw = SZ_compress_args(SZ_DOUBLE, local_durations, &outsize,
            PW_REL, 0, 0, REL_ERR,
            0, 0, 0, 0, local_total);
    free(raw);
    printf("SZ copmression ratio: %f\n", (1.0*local_total/outsize*sizeof(double)));
    SZ_Finalize();

    pilgrim_free(local_durations, sizeof(double)*local_total);
    pilgrim_free(local_intervals, sizeof(double)*local_total);

    PMPI_Barrier(MPI_COMM_WORLD);
}

void write_zstd_timings(RecordHash* cst, int mpi_rank, int mpi_size, char* dur_path, char* int_path, TimingNode *g_durations) {

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

    /*
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
    */

    size_t buff_size = ZSTD_compressBound(local_total*sizeof(double));
    void* buff = pilgrim_malloc(buff_size);

    size_t compressed_bytes = ZSTD_compress(buff, buff_size, local_durations, local_total*sizeof(double), 1);

    pilgrim_free(buff, buff_size);

    pilgrim_free(local_durations, sizeof(double)*local_total);
    pilgrim_free(local_intervals, sizeof(double)*local_total);

    PMPI_Barrier(MPI_COMM_WORLD);
    printf("ZSTD compression ratio: %f\n", (1.0*local_total/compressed_bytes*sizeof(double)));
}
