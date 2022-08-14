/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */
#include <math.h>
#include <limits.h>
#include "pilgrim.h"
#include "pilgrim_timings.h"
#include "uthash.h"
#include "mpi.h"
#include "zstd.h"

#define REL_ERR     (0.1)
#define BASE        (1.0+REL_ERR)
#define ZERO_BIN_ID (9999999)

// in seconds
//#define ZFP_DUR_ABS_ERR (0.001)
//#define ZFP_INT_ABS_ERR (0.01)
#define ZFP_DUR_ABS_ERR (10*TIME_RESOLUTION)
#define ZFP_INT_ABS_ERR (10*TIME_RESOLUTION)

static double mse_cfg_duration;
static double mse_cfg_interval;
static double max_cfg_duration;
static double max_cfg_interval;

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

void report_psnr(double* org, double* noise, int n) {
    int i;
    double mse = 0, psnr = 0;
    double max_signal = 0;
    for(i = 0; i < n; i++) {
        double diff = noise[i] - org[i];
        if(diff < 0) diff = -diff;
        if(org[i] > max_signal)
            max_signal = org[i];
        mse += diff*diff;
    }

    int rank;
    PMPI_Comm_rank(MPI_COMM_WORLD, &rank);

    mse = mse / n;
    psnr = 20*log10(max_signal) - 10*log10(mse);
    if(rank == 0)
        printf("mse: %f, max signal: %f, n: %d, PSNR: %f\n", mse, max_signal, n, psnr);
}

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
    id = mymin(32766, id);         // cap it to 2^15-1
    return id;
}

static inline int get_bin_id_int(int val) {
    if(val <= 10)
        return 0;
        //return ZERO_BIN_ID;      // a constant number to represent 0

    int id = 0;
    id = myceil(log(val)/log(BASE));
    if(id < 0) id = -id;
    id = mymin(32766, id);         // cap it to 2^15-1
    return id;
}

void dump_timings(void* buf, size_t buf_size, const char* filename) {
    PMPI_Barrier(MPI_COMM_WORLD);
    int rank;
    PMPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if(rank == 0)
        remove(filename);
    PMPI_Barrier(MPI_COMM_WORLD);

    int size = (int) buf_size;
    int offset;
    // A prefix sum to decide the offset of my write
    PMPI_Scan(&size, &offset, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    MPI_File file;
    PMPI_File_open(MPI_COMM_WORLD, filename, MPI_MODE_WRONLY|MPI_MODE_CREATE, MPI_INFO_NULL, &file);
    PMPI_File_write_at_all(file, offset, buf, size, MPI_BYTE, MPI_STATUS_IGNORE);
    PMPI_File_close(&file);
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
    double saved_duration = 0, saved_interval = 0;
    int id;
    if(*duration_id > 0) {
        id = *duration_id;
        if(duration_i < 1) id = -(*duration_id);
        saved_duration = pow(BASE, id) * TIME_RESOLUTION;
    }
    if(*interval_id > ZERO_BIN_ID) {
        id = *interval_id;
        if(interval_i < 1) id = -(*interval_id);
        saved_interval = pow(BASE, id) * TIME_RESOLUTION;
    }
    if(duration > max_cfg_duration)
        max_cfg_duration = duration;
    if(interval > max_cfg_interval)
        max_cfg_interval = interval;
    mse_cfg_duration += fabs(saved_duration - duration);
    mse_cfg_interval += fabs(saved_interval - interval);
    */
}


/**
 * We can also store lossless timing
 * Later, we can use external compressor tool like zstd/sz/zfp to compress it
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



void report(size_t local_dur_bytes, size_t local_int_bytes, double total_calls,
        double preprocess_time, double compress_time, double io_time, const char* algo_str) {

    double dur_kb = 0, int_kb = 0;
    double local_kb;

    local_kb = local_dur_bytes/ 1024.0;
    PMPI_Reduce(&local_kb, &dur_kb, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    local_kb = local_int_bytes/ 1024.0;
    PMPI_Reduce(&local_kb, &int_kb, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    int mpi_rank;
    PMPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);
    if(mpi_rank == 0) {
        double total_time = preprocess_time + compress_time + io_time;
        printf("%-15s Duration CR: %5.2f, Interval CR: %5.2f, Total Calls: %8.6f, Copmression: %10.2f MB/s Pre: %7.5f, Comp: %7.5f, IO: %7.5f\n",
                algo_str,
                total_calls*1e6/dur_kb/1024.0*sizeof(double), total_calls*1e6/int_kb/1024.0*sizeof(double),
                total_calls, total_calls*1e6/1024.0/1024.0/(compress_time+preprocess_time)*sizeof(double)*2, preprocess_time, compress_time, io_time);
    }
}

void* write_hist_timings_core(RecordHash* cst, int mpi_rank, bool dur, size_t* compressed_bytes) {

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

    double mse = 0, noise = 0, max_signal = 0, psnr = 0;

    HASH_ITER(hh, cst, entry, tmp) {
        int count;
        LL_COUNT(entry->durations, elt, count);

        // 1. First fill in duration or interval bining ids
        int *local_ids = pilgrim_malloc(sizeof(int) * count);
        int i = 0;
        if(dur) {
            LL_FOREACH_SAFE(entry->durations, elt, tmp2) {
                local_ids[i++] = get_bin_id(elt->val);
                // for PSNR
                /*
                noise = 0;
                int id = local_ids[i-1];
                if(id > 0) {
                    // ln(elt->val) < 0 then get_bin_id() make it positive
                    if(elt->val < 1) id = -id;
                    noise = pow(BASE, id);
                }
                mse += fabs(noise-elt->val);
                if(elt->val > max_signal) max_signal = elt->val;
                */
            }
        } else {
            LL_FOREACH_SAFE(entry->intervals, elt, tmp2) {
                local_ids[i++] = get_bin_id(elt->val);
                // PSNR
                /*
                noise = 0;
                int id = local_ids[i-1];
                if(id > 0) {
                    // ln(elt->val) < 0 then get_bin_id() make it positive
                    if(elt->val < 1) id = -id;
                    noise = pow(BASE, id);
                }
                mse += fabs(noise-elt->val);
                if(elt->val > max_signal) max_signal = elt->val;
                */
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
        int c = top_eight_counts_sum(local_ids, mymin(count, 100), top_eight);

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

    /*
    mse = mse / local_total;
    psnr = 20*log10(max_signal) - 10*log10(mse);
    if(mpi_rank == 0)
        printf("mse: %f, max signal: %f, n: %d, PSNR: %f\n", mse, max_signal, local_total, psnr);
    */

    size_t uncompressed_bytes = buff_idx * sizeof(uint16_t);
    size_t zstd_buff_size = ZSTD_compressBound(uncompressed_bytes);
    void* zstd_buff = malloc(zstd_buff_size);
    *compressed_bytes = ZSTD_compress(zstd_buff, zstd_buff_size, buff, uncompressed_bytes, 1);
    pilgrim_free(buff, buff_size);

    return zstd_buff;
}

void write_hist_timings(RecordHash* cst, int mpi_rank, double total_calls, char* dur_path, char* int_path) {
    PMPI_Barrier(MPI_COMM_WORLD);
    double t1 = PMPI_Wtime();

    size_t buf_size, dur_bytes, int_bytes;
    void   *dur_buf, *int_buf;
    double local_kb;
    double dur_kb = 0, int_kb = 0;

    // compress durations
    dur_buf = write_hist_timings_core(cst, mpi_rank, true, &dur_bytes);

    // compress intervals
    int_buf = write_hist_timings_core(cst, mpi_rank, false, &int_bytes);

    PMPI_Barrier(MPI_COMM_WORLD);
    double t2 = PMPI_Wtime();

    // write to files
    dump_timings(dur_buf, dur_bytes, dur_path);
    dump_timings(int_buf, int_bytes, int_path);

    PMPI_Barrier(MPI_COMM_WORLD);
    double t3 = PMPI_Wtime();

    report(dur_bytes, int_bytes, total_calls, 0, t2-t1, t3-t2, "HIST");

    free(dur_buf);
    free(int_buf);

}

void write_cfg_timings(Grammar* duration_grammar, Grammar* interval_grammar, int mpi_rank, double total_calls, char* dur_path, char* int_path, double cfg_ts) {

    PMPI_Barrier(MPI_COMM_WORLD);
    double t1 = PMPI_Wtime();

    // report psnr
    /*
    if(mpi_rank == 0) {
        double psnr;
        int t = (int) (total_calls*1e6);
        mse_cfg_duration  = mse_cfg_duration / t;
        mse_cfg_interval  = mse_cfg_interval / t;
        psnr = 20*log10(max_cfg_duration) - 10*log10(mse_cfg_duration);
        printf("CFG duration mse: %f, max signal: %f, n: %d, PSNR: %f\n", mse_cfg_duration, max_cfg_duration, t, mpi_rank, psnr);
        psnr = 20*log10(max_cfg_interval) - 10*log10(mse_cfg_interval);
        printf("CFG interval mse: %f, max signal: %f, n: %d, PSNR: %f\n", mse_cfg_interval, max_cfg_interval, t, mpi_rank, psnr);
    }
    */

    int compressed_integers;
    int* compressed_grammar;

    size_t zstd_buf_size;
    size_t dur_bytes, int_bytes;
    void   *dur_buf, *int_buf;

    /**
     * Simple local ZSTD
     */
    compressed_grammar = serialize_grammar(duration_grammar, &compressed_integers);
    zstd_buf_size = ZSTD_compressBound(sizeof(int)*compressed_integers);
    dur_buf = malloc(zstd_buf_size);
    dur_bytes = ZSTD_compress(dur_buf, zstd_buf_size, compressed_grammar, sizeof(int)*compressed_integers, 1);
    pilgrim_free(compressed_grammar, sizeof(int)*compressed_integers);

    compressed_grammar = serialize_grammar(interval_grammar, &compressed_integers);
    zstd_buf_size = ZSTD_compressBound(sizeof(int)*compressed_integers);
    int_buf = malloc(zstd_buf_size);
    int_bytes = ZSTD_compress(int_buf, zstd_buf_size, compressed_grammar, sizeof(int)*compressed_integers, 1);
    pilgrim_free(compressed_grammar, sizeof(int)*compressed_integers);

    PMPI_Barrier(MPI_COMM_WORLD);
    double t2 = PMPI_Wtime();
    dump_timings(dur_buf, dur_bytes, dur_path);
    dump_timings(int_buf, int_bytes, int_path);

    PMPI_Barrier(MPI_COMM_WORLD);
    double t3 = PMPI_Wtime();

    report(dur_bytes, int_bytes, total_calls, 0, cfg_ts+t2-t1, t3-t2, "CFG");

    free(dur_buf);
    free(int_buf);

    /*
     *
     * inter-process Sequitur pass + ZSTD
     *
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
    */

    sequitur_cleanup(duration_grammar);
    sequitur_cleanup(interval_grammar);
}

#ifdef WITH_SZ
void* write_sz_timings_core(double* buf, size_t count, size_t* compressed_bytes) {
    SZ_Init(NULL);
    void* raw_c = SZ_compress_args(SZ_DOUBLE, buf, compressed_bytes, PW_REL, 0, 0, REL_ERR, 0, 0, 0, 0, count);
    //raw_d = SZ_decompress(SZ_DOUBLE, raw_c, duration_outsize, 0, 0, 0, 0, local_total);
    //report_psnr(local_durations, (double*)raw_d, local_total);
    //free(raw_c);
    //free(raw_d);
    SZ_Finalize();
    return raw_c;
}

void write_sz_timings(RecordHash* cst, int mpi_rank, double total_calls, char* dur_path, char* int_path,
                      TimingNode *g_durations, TimingNode* g_intervals, bool clustering) {

    PMPI_Barrier(MPI_COMM_WORLD);
    double t1 = PMPI_Wtime();

    RecordHash *entry, *tmp;
    TimingNode *elt, *tmp2;

    // Local function calls count
    int local_total = 0;
    if(clustering) {
        HASH_ITER(hh, cst, entry, tmp) {
            int count = 0;
            LL_COUNT(entry->intervals, elt, count);
            local_total += count;
        }
    } else {
        LL_COUNT(g_durations, elt, local_total);
    }

    double *local_durations = pilgrim_malloc(sizeof(double) * local_total);
    double *local_intervals = pilgrim_malloc(sizeof(double) * local_total);

    // Combine all timestamps to form a 1D array
    int i = 0, j = 0;
    if(clustering) {
        HASH_ITER(hh, cst, entry, tmp) {
            LL_FOREACH_SAFE(entry->durations, elt, tmp2) {
                local_durations[i++] = elt->val;
            }
            LL_FOREACH_SAFE(entry->intervals, elt, tmp2) {
                local_intervals[j++] = elt->val;
            }
        }
    } else {
        LL_FOREACH_SAFE(g_durations, elt, tmp2) {
            local_durations[i++] = elt->val;
        }
        LL_FOREACH_SAFE(g_intervals, elt, tmp2) {
            local_intervals[j++] = elt->val;
        }
    }
    /*
    if(!clustering && mpi_rank == 0) {
        for(int k = 0; k < j; k++) {
            if(k % 10 == 0)
                printf("\n");
            printf("%f ", local_intervals[k]);
        }
        printf("\n");
    }
    */
    PMPI_Barrier(MPI_COMM_WORLD);
    double t2 = PMPI_Wtime();


    size_t dur_bytes, int_bytes;
    void* dur_buf = write_sz_timings_core(local_durations, local_total, &dur_bytes);
    void* int_buf = write_sz_timings_core(local_intervals, local_total, &int_bytes);

    pilgrim_free(local_durations, sizeof(double)*local_total);
    pilgrim_free(local_intervals, sizeof(double)*local_total);
    PMPI_Barrier(MPI_COMM_WORLD);
    double t3 = PMPI_Wtime();

    dump_timings(dur_buf, dur_bytes, dur_path);
    dump_timings(int_buf, int_bytes, int_path);
    PMPI_Barrier(MPI_COMM_WORLD);
    double t4 = PMPI_Wtime();

    report(dur_bytes, int_bytes, total_calls, t2-t1, t3-t2, t4-t3, clustering?"SZ-clustered":"SZ");

    free(dur_buf);
    free(int_buf);
}
#endif

#ifdef WITH_ZFP
void* write_zfp_timings_core(void* in, size_t count, size_t* outsize) {
    zfp_type type = zfp_type_double;                                     // array scalar type
    zfp_field* field = zfp_field_1d(in, type, count);                    // array metadata
    zfp_stream* zfp = zfp_stream_open(NULL);                             // compressed stream and parameters
    zfp_stream_set_accuracy(zfp, ZFP_DUR_ABS_ERR);                       // set tolerance for fixed-accuracy mode, this is absolute error
    size_t bufsize = zfp_stream_maximum_size(zfp, field);                // capacity of compressed buffer (conservative)
    void* out = malloc(bufsize);                                         // storage for compressed stream
    bitstream* stream = stream_open(out, bufsize);                       // bit stream to compress to
    zfp_stream_set_bit_stream(zfp, stream);                              // associate with compressed stream
    zfp_stream_rewind(zfp);                                              // rewind stream to beginning
    *outsize = zfp_compress(zfp, field);                                 // return value is byte size of compressed stream
    zfp_stream_close(zfp);
    stream_close(stream);

    return out;

    /*
    double* decompressed = pilgrim_malloc(sizeof(double)*local_total);
    field = zfp_field_1d(decompressed, type, local_total);
    zfp = zfp_stream_open(NULL);
    zfp_stream_set_accuracy(zfp, ZFP_DUR_ABS_ERR);
    stream = stream_open(buffer, duration_outsize);
    zfp_stream_set_bit_stream(zfp, stream);
    zfp_stream_rewind(zfp);
    if(!zfp_decompress(zfp, field))
        printf("zfp decompress error\n");
    else
        report_psnr(local_durations, decompressed, local_total);
    zfp_stream_close(zfp);
    stream_close(stream);
    pilgrim_free(decompressed, sizeof(double)*local_total);
    */
}

void write_zfp_timings(RecordHash* cst, int mpi_rank, double total_calls, char* dur_path, char* int_path,
                       TimingNode *g_durations, TimingNode* g_intervals, bool clustering) {
    PMPI_Barrier(MPI_COMM_WORLD);
    double t1 = PMPI_Wtime();

    // Identical pre-process code as in SZ
    RecordHash *entry, *tmp;
    TimingNode *elt, *tmp2;

    // Local function calls count
    int local_total = 0;
    if(clustering) {
        HASH_ITER(hh, cst, entry, tmp) {
            int count = 0;
            LL_COUNT(entry->intervals, elt, count);
            local_total += count;
        }
    } else {
        LL_COUNT(g_durations, elt, local_total);
    }

    double *local_durations = pilgrim_malloc(sizeof(double) * local_total);
    double *local_intervals = pilgrim_malloc(sizeof(double) * local_total);

    // Combine all timestamps to form a 1D array
    int i = 0, j = 0;
    if(clustering) {
        HASH_ITER(hh, cst, entry, tmp) {
            LL_FOREACH_SAFE(entry->durations, elt, tmp2) {
                local_durations[i++] = elt->val;
            }
            LL_FOREACH_SAFE(entry->intervals, elt, tmp2) {
                local_intervals[j++] = elt->val;
            }
        }
    } else {
        LL_FOREACH_SAFE(g_durations, elt, tmp2) {
            local_durations[i++] = elt->val;
        }
        LL_FOREACH_SAFE(g_intervals, elt, tmp2) {
            local_intervals[j++] = elt->val;
        }
    }
    PMPI_Barrier(MPI_COMM_WORLD);
    double t2 = PMPI_Wtime();

    size_t dur_bytes, int_bytes;
    void* dur_buf = write_zfp_timings_core(local_durations, local_total, &dur_bytes);
    void* int_buf = write_zfp_timings_core(local_intervals, local_total, &int_bytes);
    pilgrim_free(local_durations, sizeof(double)*local_total);
    pilgrim_free(local_intervals, sizeof(double)*local_total);

    PMPI_Barrier(MPI_COMM_WORLD);
    double t3 = PMPI_Wtime();

    dump_timings(dur_buf, dur_bytes, dur_path);
    dump_timings(int_buf, int_bytes, int_path);

    PMPI_Barrier(MPI_COMM_WORLD);
    double t4 = PMPI_Wtime();

    report(dur_bytes, int_bytes, total_calls, t2-t1, t3-t2, t4-t3, clustering?"ZFP-clustered":"ZFP");

    free(dur_buf);
    free(int_buf);
}
#endif

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
