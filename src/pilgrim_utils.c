#include <sys/time.h>
#include <stdarg.h>     // for va_list, va_start and va_end
#include <stdlib.h>
#include <stdio.h>
#include "pilgrim_utils.h"

inline double pilgrim_wtime()
{
    struct timeval time;
    gettimeofday(&time, 0);
    return (time.tv_sec + ((double)time.tv_usec / 1000000));
}

/* Put many arguments (char *) in a list (char**) */
inline char** assemble_args_list(int arg_count, ...) {
    char** args = malloc(sizeof(char*) * arg_count);
    int i;
    va_list valist;
    va_start(valist, arg_count);
    for(i = 0; i < arg_count; i++)
        args[i] = va_arg(valist, char*);
    va_end(valist);
    return args;
}


/* Integer to stirng */
inline char* itoa(int val) {
    char *str = malloc(sizeof(char) * 16);
    sprintf(str, "%d", val);
    return str;
}

/* Float to stirng */
inline char* ftoa(double val) {
    char *str = malloc(sizeof(char) * 24);
    sprintf(str, "%f", val);
    return str;
}

/* Pointer to string */
inline char* ptoa(const void *ptr) {
    char *str = malloc(sizeof(char) * 16);
    sprintf(str, "%p", ptr);
    return str;
}
