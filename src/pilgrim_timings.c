/**
 * Interval ID and Duration ID stored in the key
 */
#include <math.h>
#include <limits.h>
#include "pilgrim.h"
#include "pilgrim_timings.h"
#include "uthash.h"


static inline int min(int a, int b) {
    return a < b ? a: b;
}

static inline int get_bin_id(double val) {
    if(val==0)
        val = 0.000001;
    double base = 1.1;
    int id = log(val) / log(base);
    if(id < 0) id = -id;
    id = min(999999, id);
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
}

/*
 * If required, we can also store non-aggregated timing information
 */
void handle_non_aggregated_timing(RecordHash* entry, Record* record, int *duration_id, int* interval_id) {
    double duration = record->tend - record->tstart;        // in seconds
    double interval = record->tstart - entry->ext_tstart;   // in seconds
    int duration_i = duration / TIME_RESOLUTION;
    int interval_i = interval / TIME_RESOLUTION;

    *duration_id = get_bin_id(duration_i);
    *interval_id = get_bin_id(interval_i);
}

/**
 * We can also store lossless timing
 * Later, we can use external compressor tool like fpzip to compress it
 */
void handle_lossless_timing(RecordHash *entry, Record* record, double *duration, double *interval) {
    *duration = record->tend - record->tstart;        // in seconds
    *interval = record->tstart;                       // for interval, we just start abs tstart
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
