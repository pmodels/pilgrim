/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#ifndef _PILGRIM_UTILS_H_
#define _PILGRIM_UTILS_H_

void* pilgrim_malloc(size_t size);
void pilgrim_free(void* ptr, size_t size);
void pilgrim_report_memory_status();


double pilgrim_wtime();

/* Put multiple arguments (char *) in a list (char**) */
void** assemble_args_list(int arg_count, ...);

void* concat_function_args(short func_id, int arg_count, void** args, int* arg_sizes, int comm_size, int* key_len);

int randint();

int min_in_array(int* arr, size_t len);

/**
 * We provide these functions to replace the one
 * included in <math.h> Becuase some math.h functions
 * cause Pilgrim hang.
 *
 * Not sure why, potentially due to Intel MKL multi-threading?
 */
double pilgrim_log2(int val);
int pilgrim_ceil(double val);

int pilgrim_sum_array(int* arr, int n);

void print_bt();

#endif
