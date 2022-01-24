/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */
#define UNW_LOCAL_ONLY

#include <sys/time.h>
#include <stdarg.h>     // for va_list, va_start and va_end
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
//#include <libunwind.h>
#include "pilgrim_utils.h"
#include "dlmalloc-2.8.6.h"
#include "mpi.h"

static size_t memory_usage = 0;
static size_t peak_memory = 0;

void* pilgrim_malloc(size_t size) {
    memory_usage += size;
    if(memory_usage > peak_memory)
        peak_memory = memory_usage;
    return dlmalloc(size);
}

void pilgrim_free(void *ptr, size_t size) {
    memory_usage -= size;
    dlfree(ptr);
}

void pilgrim_report_memory_status() {
    printf("[pilgrim] Current memory usage: %ld, Peak memory usage: %ld\n", memory_usage, peak_memory);
}


inline double pilgrim_wtime()
{
    return PMPI_Wtime();
}

/* Put many arguments (char *) in a list (char**) */
inline void** assemble_args_list(int arg_count, ...) {
    void** args = pilgrim_malloc(sizeof(void*) * arg_count);

    int i;
    va_list valist;
    va_start(valist, arg_count);
    for(i = 0; i < arg_count; i++)
        args[i] = va_arg(valist, void*);
    va_end(valist);
    return args;
}

void* concat_function_args(short func_id, int arg_count, void** args, int* arg_sizes, int comm_size, int* key_len) {

    // Compute key length first, note func_id is a short type
    int i;
    *key_len = sizeof(func_id);
    if(comm_size != -1)
        *key_len += sizeof(comm_size);

    for(i = 0; i < arg_count; i++)
        *key_len += arg_sizes[i];

    // Actually set the key
    int pos = 0;
    void *key = pilgrim_malloc(*key_len);
    memcpy(key+pos, &func_id, sizeof(func_id));
    pos += sizeof(func_id);

    if(comm_size != -1) {
        memcpy(key+pos, &comm_size, sizeof(comm_size));
        pos += sizeof(comm_size);
    }

    for(i = 0; i < arg_count; i++) {
        if(args[i])
            memcpy(key+pos, args[i], arg_sizes[i]);
        else
            memset(key+pos, 0, arg_sizes[i]);

        pos += arg_sizes[i];
    }

    return key;
}

int randint() {
    time_t t;
    int rank;
    PMPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int pid = getpid();
    srand((unsigned) time(&t) + rank * pid);
    return rand();
}

int min_in_array(int* arr, size_t len) {
    int min_val = arr[0];
    for(int i = 1; i < len; i++) {
        if(arr[i] < min_val)
            min_val = arr[i];
    }
    return min_val;
}

double pilgrim_log2(int val) {
    return log(val)/log(2);
}

int pilgrim_ceil(double val) {
    int tmp = (int) val;
    if(val > tmp)
        return tmp + 1;
}

int pilgrim_sum_array(int* arr, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

/*
void print_bt() {
    unw_cursor_t cursor;
    unw_context_t context;
    // Initialize cursor to current frame for local unwinding.
    unw_getcontext(&context);
    unw_init_local(&cursor, &context);

    // Unwind frames one by one, going up the frame stack.
    while (unw_step(&cursor) > 0) {
        unw_word_t offset, pc;
        unw_get_reg(&cursor, UNW_REG_IP, &pc);
        if (pc == 0) {
            break;
        }
        printf("0x%lx:", pc);

        char sym[256];
        if (unw_get_proc_name(&cursor, sym, sizeof(sym), &offset) == 0) {
            printf(" (%s+0x%lx)\n", sym, offset);
        } else {
            printf(" -- error: unable to obtain symbol name for this frame\n");
        }
    }
}
*/
