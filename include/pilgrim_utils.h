#ifndef _PILGRIM_UTILS_H_
#define _PILGRIM_UTILS_H_


double pilgrim_wtime();

/* Put many arguments (char *) in a list (char**) */
void** assemble_args_list(int arg_count, ...);


char* itoa(int val);
char* ftoa(double val);
char* ptoa(const void *ptr);

#endif
