#ifndef _PILGRIM_SEQUITUR_H_
#define _PILGRIM_SEQUITUR_H_

#include <stdbool.h>
#include "../include/utlist.h"
#include "../include/uthash.h"

typedef struct Symbol_t {
    bool terminal;
    int val;
} Symbol;

typedef struct SymbolNode_t {           // utlist node
    Symbol symbol;
    struct SymbolNode_t *prev, *next;
} SymbolNode;


typedef struct {
    Symbol s1, s2;
} DigramHashKey;

typedef struct DigramHash_t {           // uthash node
    DigramHashKey key;
    SymbolNode *symbol_node;
    UT_hash_handle hh;
} DigramHash;


typedef struct RuleHash_t {             // Rule (non-terminal Symbol) -> Symbols
    void *key;                          // Symbols as key
    int key_len;                        // N * sizeof(struct Symbol_t)
    Symbol symbol;                      // Rule(non-terminal Symbol) as value
    UT_hash_handle hh;
} RuleHash;

typedef struct {
    RuleHash *rule_table;
    DigramHash *digram_table;
    SymbolNode *symbols;
} Grammar;

SymbolNode* insert_symbol(Grammar *grammar, SymbolNode *pos, Symbol s);
void read_terminal(Grammar *grammar, int val);
void clean_grammar(Grammar *grammar);

#endif
