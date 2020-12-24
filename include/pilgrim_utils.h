#ifndef _PILGRIM_UTILS_H_
#define _PILGRIM_UTILS_H_

void* pilgrim_malloc(size_t size);
void pilgrim_free(void* ptr, size_t size);
void pilgrim_report_memory_status();


double pilgrim_wtime();

/* Put many arguments (char *) in a list (char**) */
void** assemble_args_list(int arg_count, ...);

int randint();


unsigned char* pilgrim_sha256(const unsigned char *d, unsigned long n, unsigned char *md);
char *base64encode(const void *b64_encode_this, int encode_this_many_bytes);

#endif
