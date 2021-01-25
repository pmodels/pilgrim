#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pilgrim_sequitur.h"
#include "pilgrim_utils.h"
#include "mpi.h"


/**
 * Store the Grammer in an integer array
 *
 * | #rules |
 * | rule 1 head | #symbols of rule 1 | symbol 1, ..., symbol N |
 * | rule 2 head | #symbols of rule 2 | symbol 1, ..., symbol N |
 * ...
 *
 * @len: [out] the length of the array: 1 + 2 * number of rules + number of symbols
 * @return: return the array, need to be freed by the caller
 *
 */
int* serialize_grammar(Grammar *grammar, size_t *len) {

    int total_integers = 1, symbols_count = 0, rules_count = 0;

    Symbol *rule, *sym;
    DL_COUNT(grammar->rules, rule, rules_count);

    total_integers += 2 * rules_count;

    DL_FOREACH(grammar->rules, rule) {
        DL_COUNT(rule->rule_body, sym, symbols_count);
        total_integers += symbols_count;
    }

    int i = 0;
    int *data = mymalloc(sizeof(int) * total_integers);
    data[i++]  = rules_count;
    DL_FOREACH(grammar->rules, rule) {
        DL_COUNT(rule->rule_body, sym, symbols_count);
        data[i++] = rule->val;
        data[i++] = symbols_count;

        DL_FOREACH(rule->rule_body, sym) {
            data[i++] = sym->val;       // rule id does not change
        }

    }

    *len = total_integers;
    return data;
}


/**
 * Use MPI to gather grammars from all ranks
 *
 * @total_len: output parameter, is length of the returned grammar (interger array)
 * @return: gathered grammars in a 1D integer array
 */
int* gather_grammars(Grammar *grammar, int mpi_rank, int mpi_size, size_t* len_sum) {
    size_t len = 0;
    int *local_grammar = serialize_grammar(grammar, &len);


    /*
    unsigned char hash[33];
    pilgrim_sha256((const unsigned char*)local_grammar, sizeof(int)*len, hash);
    char* str = base64encode(hash, 32);
    printf("%d: %s\n", mpi_rank, str);
    */

    int recvcounts[mpi_size], displs[mpi_size];
    PMPI_Gather(&len, 1, MPI_INT, recvcounts, 1, MPI_INT, 0, MPI_COMM_WORLD);

    displs[0] = 0;
    *len_sum = recvcounts[0];
    for(int i = 1; i < mpi_size;i++) {
        *len_sum += recvcounts[i];
        displs[i] = displs[i-1] + recvcounts[i-1];
    }

    int *gathered_grammars = NULL;
    if(mpi_rank == 0)
        gathered_grammars = mymalloc(sizeof(int) * (*len_sum));

    PMPI_Gatherv(local_grammar, len, MPI_INT, gathered_grammars, recvcounts, displs, MPI_INT, 0, MPI_COMM_WORLD);

    myfree(local_grammar, len);
    return gathered_grammars;
}

typedef struct RuleHash_t {
    void *key;
    int key_len;
    int count;
    UT_hash_handle hh;
} RuleHash;

static RuleHash *rules_table;
void compress2(const char* path, int *gathered, int world_size) {
    int rank = 0;
    int *ptr = gathered;
    int total_rules = 0;
    size_t total_size = 0;
    while(rank < world_size) {
        int rules = *ptr;
        total_rules += rules;
        ptr++;

        for(int i = 0; i < rules; i++) {
            int rule_id = *ptr;
            ptr++;

            int symbols = *ptr;
            ptr++;

            RuleHash* entry;
            HASH_FIND(hh, rules_table, ptr, sizeof(int)*symbols, entry);
            if(entry) {
                entry->count++;
            } else {
                entry = pilgrim_malloc(sizeof(RuleHash));
                entry->key = pilgrim_malloc(sizeof(int) * symbols);
                entry->key_len = sizeof(int) * symbols;
                entry->count = 0;
                memcpy(entry->key, ptr, entry->key_len);
                HASH_ADD_KEYPTR(hh, rules_table, entry->key, entry->key_len, entry);
                total_size += (entry->key_len);
            }

            ptr += symbols;
        }
        rank++;
    }
    int unique_rules = HASH_COUNT(rules_table);

    Grammar grammar;
    sequitur_init(&grammar);

    RuleHash *r, *tmp;
    HASH_ITER(hh, rules_table, r, tmp) {
        ptr = (int*) r->key;
        for(int i = 0; i < r->key_len/sizeof(int); i++) {
            int symbol_id = ptr[i];
            if(symbol_id < 0)
                symbol_id = 100000 + (-symbol_id);

            append_terminal(&grammar, symbol_id);

        }
        HASH_DEL(rules_table, r);
        pilgrim_free(r->key, r->key_len);
        pilgrim_free(r, sizeof(RuleHash));
    }

    size_t compressed_len;
    int* compressed_grammar = serialize_grammar(&grammar, &compressed_len);
    sequitur_cleanup(&grammar);

    errno = 0;
    FILE* f = fopen(path, "wb");
    if(f) {
        fwrite(compressed_grammar, sizeof(int), compressed_len, f);
        fclose(f);
    } else {
        printf("Open file: %s failed, errno: %d!\n", path, errno);
    }
    myfree(compressed_grammar, sizeof(int)*compressed_len);

    printf("[pilgrim] total rules: %d, unique rules: %d, total size: %fMB, another sequitur pass: %.2f KB\n",
            total_rules, unique_rules, total_size/1024.0/1024.0, compressed_len*sizeof(int)/1024.0);
}

/*
 * After collecting grammars from all ranks
 * Do a second Sequitur pass to generate a
 * grammar that represents all grammars.
 * This pass severs as inter-process compression
 * as many ranks should have similar grammar.
 */
void compress_gathered_grammars(const char* path, int *gathered_grammars, size_t len) {
    int max = 0;
    for(size_t i = 0; i < len; i++)
        if(gathered_grammars[i] > max)
            max = gathered_grammars[i];

    Grammar grammar;
    sequitur_init(&grammar);
    for(size_t i = 0; i < len; i++) {
        int symbol_id = gathered_grammars[i];
        if(symbol_id < 0)
            symbol_id = (symbol_id * (-1)) + max;
        append_terminal(&grammar, symbol_id);
    }

    size_t compressed_len;
    int* compressed_grammar = serialize_grammar(&grammar, &compressed_len);
    sequitur_cleanup(&grammar);

    printf("%s: Original Total integers: %ld, Second Sequitor pass: %ld, max terminal id: %d\n", path, len, compressed_len, max);

    FILE* f = fopen(path, "wb");
    fwrite(compressed_grammar, sizeof(int), compressed_len, f);
    fclose(f);
    myfree(compressed_grammar, sizeof(int)*compressed_len);
}

void sequitur_dump(const char* path, Grammar *grammar, int mpi_rank, int mpi_size) {
    // gathered_grammars is NULL except rank 0
    size_t len;
    int *gathered_grammars = gather_grammars(grammar, mpi_rank, mpi_size, &len);

    if(mpi_rank == 0) {
        compress2(path, gathered_grammars, mpi_size);
        //compress_gathered_grammars(path, gathered_grammars, len);
        myfree(gathered_grammars, sizeof(int)*len);
    }
}
