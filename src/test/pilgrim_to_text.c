#include <stdio.h>
#include <stdlib.h>
#include "pilgrim.h"
#include "pilgrim_reader.h"

int main(int argc, char** argv) {

    char* directory = argv[1];
    char cfg_path[256];
    char cst_path[256];
    sprintf(cfg_path, "%s/grammars.dat", directory);
    sprintf(cst_path, "%s/funcs.dat", directory);

    int nprocs = atoi(argv[2]);
    int num_symbols[nprocs];
    int** decoded_symbols = read_cfg(cfg_path, nprocs, num_symbols);

    for(int rank = 0; rank < nprocs; rank++) {
        for(int i = 0; i < num_symbols[rank]; i++)
            printf("%d ", decoded_symbols[rank][i]);
        printf("\n");

        free(decoded_symbols[rank]);
    }
    free(decoded_symbols);


    int num_sigs;
    read_cst(cst_path, &num_sigs);

    return 0;
}
