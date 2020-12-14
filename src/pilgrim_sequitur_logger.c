#include <stdio.h>
#include <stdlib.h>
#include "pilgrim_sequitur.h"
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
int* grammar_to_array(Grammar *grammar, int* update_terminal_id, int *len) {

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
            data[i++] = update_terminal_id[sym->val];
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
int* gather_grammars(Grammar *grammar, int* update_terminal_id, int mpi_rank, int mpi_size, int* len_sum) {
    int len = 0;
    int *local_grammar = grammar_to_array(grammar, update_terminal_id, &len);
    printf("Grammar size: %ld\n", len*4);

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

void sequitur_dump(char* path, Grammar *grammar, int* update_terminal_id, int mpi_rank, int mpi_size) {
    // gathered_grammars is NULL except rank 0
    int len;
    int *gathered_grammars = gather_grammars(grammar, update_terminal_id, mpi_rank, mpi_size, &len);
    if( mpi_rank != 0)
        return;

    FILE* f = fopen(path, "wb");
    /*
    for(int i = 0; i < len; i++) {
        fprintf(f, "%d ", gathered_grammars[i]);
        if( i != 0 && i % 20 == 0)
            fprintf(f, "\n");
    }
    */

    fwrite(gathered_grammars, sizeof(int), len, f);

    fclose(f);
    myfree(gathered_grammars, len);
}
