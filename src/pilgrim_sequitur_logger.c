#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pilgrim_sequitur.h"
#include "pilgrim_utils.h"
#include "mpi.h"
#include "uthash.h"

typedef struct UniqueGrammar_t {
    int ugi;                // unique grammar id
    void *key;              // serialized grammar stream as key
    int count;
    UT_hash_handle hh;
} UniqueGrammar;

static UniqueGrammar *unique_grammars;
static int current_ugi = 0;

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
int* serialize_grammar(Grammar *grammar, int *integers) {

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

    *integers = total_integers;
    return data;
}


/**
 * Inter-process compression of CFGs
 *
 * Grammar* lg [in]: local grammar
 * return: a compressed grammar.
 */
Grammar* compress_grammars(Grammar *lg, int mpi_rank, int mpi_size, size_t *uncompressed_integers) {
    int integers = 0;
    int *local_grammar = serialize_grammar(lg, &integers);

    int recvcounts[mpi_size], displs[mpi_size];
    PMPI_Gather(&integers, 1, MPI_INT, recvcounts, 1, MPI_INT, 0, MPI_COMM_WORLD);

    displs[0] = 0;
    size_t gathered_integers = recvcounts[0];
    for(int i = 1; i < mpi_size;i++) {
        gathered_integers += recvcounts[i];
        displs[i] = displs[i-1] + recvcounts[i-1];
    }

    int *gathered_grammars = NULL;
    if(mpi_rank == 0)
        gathered_grammars = pilgrim_malloc(sizeof(int) * gathered_integers);

    PMPI_Gatherv(local_grammar, integers, MPI_INT, gathered_grammars, recvcounts, displs, MPI_INT, 0, MPI_COMM_WORLD);
    pilgrim_free(local_grammar, sizeof(int)*integers);

    if(mpi_rank !=0) return NULL;

    // Run a final Sequitur pass to compress the gathered grammars
    Grammar *grammar = pilgrim_malloc(sizeof(Grammar));
    grammar->start_rule_id = min_in_array(gathered_grammars, gathered_integers)  -1;
    sequitur_init_rule_id(grammar, grammar->start_rule_id);
    int rules, rule_val, symbols, symbol_val, symbol_exp;


    *uncompressed_integers = 0;

    // Go through each rank's grammar
    for(int i = 0; i < mpi_size; i++) {

        // Serialized grammar of rank i
        int* g = gathered_grammars + displs[i];
        int g_len = recvcounts[i] * sizeof(int);

        UniqueGrammar *entry = NULL;
        HASH_FIND(hh, unique_grammars, g, g_len, entry);

        if(entry) {
            entry->count++;

            // A duplicated grammar, only need to store its id
            //append_terminal(grammar, entry->ugi, 1);
        } else {
            entry = pilgrim_malloc(sizeof(UniqueGrammar));
            entry->ugi = current_ugi++;
            entry->key = g;   // use the existing memory, do not copy it
            HASH_ADD_KEYPTR(hh, unique_grammars, entry->key, g_len, entry);

            // A unseen grammar, fully store it.
            int k = 0;
            rules = g[k++];
            append_terminal(grammar, rules, 1);
            *uncompressed_integers += 2;

            for(int rule_idx = 0; rule_idx < rules; rule_idx++) {
                rule_val = g[k++];
                symbols = g[k++];
                append_terminal(grammar, rule_val, 1);
                append_terminal(grammar, symbols, 1);
                *uncompressed_integers += 4;
                for(int sym_id = 0; sym_id < symbols; sym_id++) {
                    symbol_val = g[k++];
                    symbol_exp = g[k++];
                    append_terminal(grammar, symbol_val, symbol_exp);
                    *uncompressed_integers += 2;
                }
            }
        }
    } // end of for loop

    // Clean up the hash table, and gathered grammars
    int num_unique_grammars = HASH_COUNT(unique_grammars);
    printf("[pilgrim] unique grammars: %d\n", num_unique_grammars);

    UniqueGrammar *ug, *tmp;
    HASH_ITER(hh, unique_grammars, ug, tmp) {
        HASH_DEL(unique_grammars, ug);
        pilgrim_free(ug, sizeof(UniqueGrammar));
    }
    pilgrim_free(gathered_grammars, gathered_integers*sizeof(int));

    return grammar;
}


// Return the size of compressed grammar in KB
double sequitur_dump(const char* path, Grammar *local_grammar, int mpi_rank, int mpi_size) {
    int compressed_integers = 0;

    // Compressed grammar is NULL except rank 0
    size_t uncompressed_integers = 0;
    Grammar *grammar = compress_grammars(local_grammar, mpi_rank, mpi_size, &uncompressed_integers);

    // Serialize the compressed grammar and write it to file
    if(mpi_rank == 0) {
        int* compressed_grammar = serialize_grammar(grammar, &compressed_integers);

        errno = 0;
        FILE* f = fopen(path, "wb");
        if(f) {
            fwrite(&(grammar->start_rule_id), sizeof(int), 1, f);
            fwrite(&uncompressed_integers, sizeof(size_t), 1, f);
            fwrite(compressed_grammar, sizeof(int), compressed_integers, f);
            fclose(f);
        } else {
            printf("Open file: %s failed, errno: %d!\n", path, errno);
        }

        sequitur_cleanup(grammar);
        pilgrim_free(grammar, sizeof(Grammar));
        pilgrim_free(compressed_grammar, compressed_integers*sizeof(int));
    }

    return (compressed_integers/1024.0*sizeof(int));
}
