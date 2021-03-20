#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pilgrim_sequitur.h"
#include "pilgrim_utils.h"
#include "mpi.h"
#include "uthash.h"

typedef struct UniqueGrammar_t {
    void *key;
    int count;
    UT_hash_handle hh;
} UniqueGrammar;

static UniqueGrammar *unique_grammars;

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
        total_integers += symbols_count*2;  // val and exp
    }

    int i = 0;
    int *data = pilgrim_malloc(sizeof(int) * total_integers);
    data[i++]  = rules_count;
    DL_FOREACH(grammar->rules, rule) {
        DL_COUNT(rule->rule_body, sym, symbols_count);
        data[i++] = rule->val;
        data[i++] = symbols_count;

        DL_FOREACH(rule->rule_body, sym) {
            data[i++] = sym->val;       // rule id does not change
            data[i++] = sym->exp;
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
        gathered_grammars = pilgrim_malloc(sizeof(int) * (*len_sum));

    PMPI_Gatherv(local_grammar, len, MPI_INT, gathered_grammars, recvcounts, displs, MPI_INT, 0, MPI_COMM_WORLD);

    if(mpi_rank == 0) {
        for(int i = 0; i < mpi_size; i++) {
            int* key = gathered_grammars+displs[i];
            int key_len = recvcounts[i] * sizeof(int);
            UniqueGrammar *entry = NULL;
            HASH_FIND(hh, unique_grammars, key, key_len, entry);
            if(entry)
                entry->count++;
            else {
                entry = pilgrim_malloc(sizeof(UniqueGrammar));
                entry->key = key;   // use the existing memory, do not copy it
                HASH_ADD_KEYPTR(hh, unique_grammars, entry->key, key_len, entry);
            }
        }
    }

    pilgrim_free(local_grammar, len);
    return gathered_grammars;
}

double compress_and_dump(const char* path, int* gathered, size_t len) {
    int num_unique_grammars = HASH_COUNT(unique_grammars);
    printf("[pilgrim] unique grammars: %d\n", num_unique_grammars);

    // run a second sequitur pass
    Grammar grammar;
    int start_rule_id = min_in_array(gathered, len)  -1;
    sequitur_init_rule_id(&grammar, start_rule_id);

    int rules, rule_val, symbols, symbol_val, symbol_exp;

    UniqueGrammar *ug, *tmp;
    HASH_ITER(hh, unique_grammars, ug, tmp) {
        int *data = (int*) ug->key;

        int i = 0;
        rules = data[i++];
        append_terminal(&grammar, rules, 1);

        for(int rule_idx = 0; rule_idx < rules; rule_idx++) {
            rule_val = data[i++];
            symbols = data[i++];
            append_terminal(&grammar, rule_val, 1);
            append_terminal(&grammar, symbols, 1);
            // All symbols of one rule
            for(int sym_id = 0; sym_id < symbols; sym_id++) {
                symbol_val = data[i++];
                symbol_exp = data[i++];
                append_terminal(&grammar, symbol_val, symbol_exp);
            }
        }

        HASH_DEL(unique_grammars, ug);
        // No need to free ug->key, it will be freed later.
        pilgrim_free(ug, sizeof(UniqueGrammar));
    }

    //print_rules(&grammar);

    size_t compressed_len;
    int* compressed_grammar = serialize_grammar(&grammar, &compressed_len);
    sequitur_cleanup(&grammar);

    errno = 0;
    FILE* f = fopen(path, "wb");
    if(f) {
        printf("[pilgrim] Uncompressed grammar size: %.2fKB, another sequitur pass: %.2fKB\n",
                len/1024.0*sizeof(int), compressed_len/1024.0*sizeof(int));
        fwrite(&start_rule_id, sizeof(int), 1, f);
        fwrite(&len, sizeof(size_t), 1, f);
        fwrite(&compressed_len, sizeof(size_t), 1, f);
        fwrite(compressed_grammar, sizeof(int), compressed_len, f);
        fclose(f);
    } else {
        printf("Open file: %s failed, errno: %d!\n", path, errno);
    }

    pilgrim_free(compressed_grammar, sizeof(int)*compressed_len);
    return (compressed_len/1024.0*sizeof(int));
}


double sequitur_dump(const char* path, Grammar *grammar, int mpi_rank, int mpi_size) {
    double compressed_size = 0;

    // gathered_grammars is NULL except rank 0
    size_t len;
    int *gathered_grammars = gather_grammars(grammar, mpi_rank, mpi_size, &len);

    if(mpi_rank == 0) {
        compressed_size = compress_and_dump(path, gathered_grammars, len);
        pilgrim_free(gathered_grammars, sizeof(int)*len);
    }

    return compressed_size;
}
