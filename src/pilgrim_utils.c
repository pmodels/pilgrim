#include <sys/time.h>
#include <stdarg.h>     // for va_list, va_start and va_end
#include <stdlib.h>
#include <stdio.h>
#include "pilgrim_utils.h"
#include "dlmalloc-2.8.6.h"

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

