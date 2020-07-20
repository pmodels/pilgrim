#include <stdio.h>
#include "pilgrim_sequitur.h"

#define DIGRAM_KEY_LEN sizeof(int)*2

void* build_digram_key(int v1, int v2) {
    void *key = mymalloc(DIGRAM_KEY_LEN);
    memcpy(key, &v1, sizeof(int));
    memcpy(key+sizeof(int), &v2, sizeof(int));
    return key;
}


/**
 * Look up a digram in the hash table
 *
 * @param v1 The symbol value of the first symbol of the digram
 * @param v2 The symbol value of the second symbol of the digram
 */
Symbol* digram_get(Digram *digram_table, int v1, int v2) {

    void* key = build_digram_key(v1, v2);

    Digram *found;
    HASH_FIND(hh, digram_table, key, DIGRAM_KEY_LEN, found);
    myfree(key, DIGRAM_KEY_LEN);

    if(found)
        return found->symbol;
    return NULL;
}

/**
 * Insert a digram into the hash table
 *
 * @param symbol The first symbol of the digram
 *
 */
int digram_put(Digram **digram_table, Symbol *symbol) {
    if (symbol == NULL || symbol->next == NULL)
        return -1;

    void* key = build_digram_key(symbol->val, symbol->next->val);

    Digram *found;
    HASH_FIND(hh, *digram_table, key, DIGRAM_KEY_LEN, found);

    // Found a same digram in the table already
    if(found) {
        myfree(key, DIGRAM_KEY_LEN);
        return 1;
    } else {
        Digram *digram = mymalloc(sizeof(Digram));
        digram->key = key;
        digram->symbol = symbol;
        HASH_ADD_KEYPTR(hh, *digram_table, digram->key, DIGRAM_KEY_LEN, digram);
        return 0;
    }
}


int digram_delete(Digram **digram_table, Symbol *symbol) {
    if(symbol == NULL || symbol->next == NULL)
        return 0;

    void* key = build_digram_key(symbol->val, symbol->next->val);

    Digram *found;
    HASH_FIND(hh, *digram_table, key, DIGRAM_KEY_LEN, found);

    if(found) {
        HASH_DELETE(hh, *digram_table, found);
        myfree(found, sizeof(Digram));
        return 0;
    }
    myfree(key, DIGRAM_KEY_LEN);
    return -1;
}

