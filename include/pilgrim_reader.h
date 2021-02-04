#ifndef _PILGRIM_READER_H_
#define _PILGRIM_READER_H_

typedef struct CallSignature_t {
    short func_id;
    int arg_count;
    int* arg_sizes;
    void **args;
} CallSignature;


void read_record_args(int func_id, void* buff, CallSignature *cs);
void read_record_args_special(int func_id, void* buff, CallSignature *cs);

#endif

