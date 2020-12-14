#include <sys/time.h>
#include <stdarg.h>     // for va_list, va_start and va_end
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
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
    printf("Current memory usage: %ld, Peak memory usage: %ld\n", memory_usage, peak_memory);
}


inline double pilgrim_wtime()
{
    struct timeval time;
    gettimeofday(&time, 0);
    return (time.tv_sec + ((double)time.tv_usec / 1000000));
}

/* Put many arguments (char *) in a list (char**) */
inline void** assemble_args_list(int arg_count, ...) {
    void** args = dlmalloc(sizeof(void*) * arg_count);

    int i;
    va_list valist;
    va_start(valist, arg_count);
    for(i = 0; i < arg_count; i++)
        args[i] = va_arg(valist, void*);
    va_end(valist);
    return args;
}

int randint() {
    time_t t;
    int rank;
    PMPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int pid = getpid();
    srand((unsigned) time(&t) + rank * pid);
    return rand();
}
