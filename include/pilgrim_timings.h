/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#ifndef _PILGRIM_TIMINGS_H_
#define _PILGRIM_TIMINGS_H_

#include "pilgrim_logger.h"

// Aggregated
#define TIMING_MODE_AGGREGATED      "AGGREGATED"

// Lossless
#define TIMING_MODE_NOCOMP          "NOCOMP"
#define TIMING_MODE_TEXT            "TEXT"
#define TIMING_MODE_ZSTD            "ZSTD"

// Lossy
#define TIMING_MODE_CFG             "CFG"
#define TIMING_MODE_HIST            "HIST"
#define TIMING_MODE_SZ              "SZ"
#define TIMING_MODE_ZFP             "ZFP"

#define microseconds    (0.000001)
#define TIME_RESOLUTION (1*microseconds)

void handle_aggregated_timing(RecordHash* entry, Record* record);
void handle_cfg_timing(RecordHash* entry, Record* record, int* duration_id, int* interval_id);
void handle_nocomp_timing(RecordHash* entry, Record* record, double* duration, double* interval);

void write_nocomp_timings(RecordHash* cst, int mpi_rank, int mpi_size, char* dur_path, char* int_path);
void write_zfp_timings(RecordHash* cst, int mpi_rank, int mpi_size, char* dur_path, char* int_path, TimingNode* g_durations);
void write_sz_timings(RecordHash* cst, int mpi_rank, int mpi_size, char* dur_path, char* int_path, TimingNode* g_durations);
void write_zstd_timings(RecordHash* cst, int mpi_rank, int mpi_size, char* dur_path, char* int_path, TimingNode* g_durations);
void write_hist_timings(RecordHash* cst, int mpi_rank, int mpi_size, char* dur_path, char* int_path);

void write_text_timings(RecordHash* cst, int mpi_rank);


#endif
