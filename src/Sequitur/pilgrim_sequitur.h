#ifndef _PILGRIM_SEQUITUR_H_
#define _PILGRIM_SEQUITUR_H_

#include <stdbool.h>
#include "utlist.h"
#include "uthash.h"

#define IS_RULE_HEAD(sym) ((!(sym)->terminal) && ((sym)->rule_head==NULL))
#define IS_NONTERMINAL(sym) ((!(sym)->terminal) && ((sym)->rule_head!=NULL))
#define IS_TERMINAL(sym) ((sym)->terminal)

#define ERROR_ABORT(msg) {fprintf(stderr, msg);abort();}

//#define DEBUG



/**
 * There are three types of Symbols
 *
 * 1. Terminal:
 *      `rule` filed is the rule (rule head) it blongs to
 *      `rule_head`, `ref_body` and `ref` are ignored
 *
 * 2. Non-terminal:
 *      `rule` filed is the rule (rule head) it blongs to
 *      `rule_head` points to the rule_head node
 *      `ref_body` and `ref` are ignored
 *
 *  Terminals and Non-terminals are both stored in rule_body list.
 *
 * 3. Rule head:
 *      Represents a rule.  This is a special type that are stored in the rule list
 *      It will never be inserted into the rules body.
 *      `rule_body` is the right hand side
 *      `ref` is the number of usages
 *      `rule` and `rule_head` filed are ignored
 *
 */
typedef struct Symbol_t {           // utlist node
    int val;
    bool terminal;

    // For terminal and non-termial this filed
    // keeps the rule (rule head) they belong to
    struct Symbol_t *rule;

    // Only used by non-terminal, points to the rule it represents
    struct Symbol_t *rule_head;

    // if this is a rule (non-terminal)
    // rule_body will be a list of symbols this rule represent
    // ref will be the number of usages of this rule
    struct Symbol_t *rule_body;
    int ref;

    struct Symbol_t *prev, *next;
} Symbol;


typedef struct Digram_t {           // uthash node
    void *key;
    Symbol *symbol;                 // first symbol of the digram
    UT_hash_handle hh;
} Digram;

typedef struct Grammar_t {
    Symbol *rules;
    Digram *digram_table;
} Grammar;


Symbol* new_symbol(int val, bool terminal, Symbol* rule_head);
void symbol_put(Symbol *rule, Symbol *pos, Symbol *sym);
void symbol_delete(Symbol *rule, Symbol *sym);

Symbol* digram_get(Digram *digram_table, int v1, int v2);
int digram_put(Digram **digram_table, Symbol *symbol);
int digram_delete(Digram **digram_table, Symbol *symbol);

Symbol* new_rule();
void rule_put(Symbol **rules_head, Symbol *rule);
void rule_delete(Symbol **rules_head, Symbol *rule);
void rule_ref(Symbol *rule);
void rule_deref(Symbol *rule);

int check_digram(Symbol *sym);

#endif