#include <sys/time.h>
#include <stdarg.h>     // for va_list, va_start and va_end
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <openssl/sha.h>
#include <openssl/pem.h>
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
    /*
       struct timeval time;
       gettimeofday(&time, 0);
       return (time.tv_sec + ((double)time.tv_usec / 1000000));
       */
    return PMPI_Wtime();
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

char *base64encode (const void *b64_encode_this, int encode_this_many_bytes){
    BIO *b64_bio, *mem_bio;      //Declares two OpenSSL BIOs: a base64 filter and a memory BIO.
    BUF_MEM *mem_bio_mem_ptr;    //Pointer to a "memory BIO" structure holding our base64 data.
    b64_bio = BIO_new(BIO_f_base64());                      //Initialize our base64 filter BIO.
    mem_bio = BIO_new(BIO_s_mem());                           //Initialize our memory sink BIO.
    BIO_push(b64_bio, mem_bio);            //Link the BIOs by creating a filter-sink BIO chain.
    BIO_set_flags(b64_bio, BIO_FLAGS_BASE64_NO_NL);  //No newlines every 64 characters or less.
    BIO_write(b64_bio, b64_encode_this, encode_this_many_bytes); //Records base64 encoded data.
    BIO_flush(b64_bio);   //Flush data.  Necessary for b64 encoding, because of pad characters.
    BIO_get_mem_ptr(mem_bio, &mem_bio_mem_ptr);  //Store address of mem_bio's memory structure.
    BIO_set_close(mem_bio, BIO_NOCLOSE);   //Permit access to mem_ptr after BIOs are destroyed.
    BIO_free_all(b64_bio);  //Destroys all BIOs in chain, starting with b64 (i.e. the 1st one).
    BUF_MEM_grow(mem_bio_mem_ptr, (*mem_bio_mem_ptr).length + 1);   //Makes space for end null.
    (*mem_bio_mem_ptr).data[(*mem_bio_mem_ptr).length] = '\0';  //Adds null-terminator to tail.
    return (*mem_bio_mem_ptr).data; //Returns base-64 encoded data. (See: "buf_mem_st" struct).
}

char *base64decode (const void *b64_decode_this, int decode_this_many_bytes){
    BIO *b64_bio, *mem_bio;      //Declares two OpenSSL BIOs: a base64 filter and a memory BIO.
    char *base64_decoded = calloc( (decode_this_many_bytes*3)/4+1, sizeof(char) ); //+1 = null.
    b64_bio = BIO_new(BIO_f_base64());                      //Initialize our base64 filter BIO.
    mem_bio = BIO_new(BIO_s_mem());                         //Initialize our memory source BIO.
    BIO_write(mem_bio, b64_decode_this, decode_this_many_bytes); //Base64 data saved in source.
    BIO_push(b64_bio, mem_bio);          //Link the BIOs by creating a filter-source BIO chain.
    BIO_set_flags(b64_bio, BIO_FLAGS_BASE64_NO_NL);          //Don't require trailing newlines.
    int decoded_byte_index = 0;   //Index where the next base64_decoded byte should be written.
    while ( 0 < BIO_read(b64_bio, base64_decoded+decoded_byte_index, 1) ){ //Read byte-by-byte.
        decoded_byte_index++; //Increment the index until read of BIO decoded data is complete.
    } //Once we're done reading decoded data, BIO_read returns -1 even though there's no error.
    BIO_free_all(b64_bio);  //Destroys all BIOs in chain, starting with b64 (i.e. the 1st one).
    return base64_decoded;        //Returns base-64 decoded data with trailing null terminator.
}

unsigned char* pilgrim_sha256(const unsigned char *d, unsigned long n, unsigned char *md) {
    return SHA256(d, n, md);
}

