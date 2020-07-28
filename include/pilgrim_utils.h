#ifndef _PILGRIM_UTILS_H_
#define _PILGRIM_UTILS_H_


double pilgrim_wtime();

/* Put many arguments (char *) in a list (char**) */
void** assemble_args_list(int arg_count, ...);


#endif
