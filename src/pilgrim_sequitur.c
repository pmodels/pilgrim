#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/pilgrim_sequitur.h"

static int rule_number = -1;






// Struct Symbol used in keys of Rules
// Need to make sure the paddings are zeroed when adding/querying the rule table
void zero_set_symbol(Symbol *symbol) {
    bool terminal = symbol->terminal;
    int val = symbol->val;

    memset(symbol, 0, sizeof(Symbol));
    symbol->terminal = terminal;
    symbol->val = val;
}


RuleHash* create_rule(Symbol left, Symbol right) {
    zero_set_symbol(&left);
    zero_set_symbol(&right);

    RuleHash *rule = malloc(sizeof(RuleHash));
    int key_len = 2*sizeof(Symbol);
    rule->key = malloc(key_len);
    rule->key_len = key_len;
    memcpy(rule->key, &left, sizeof(Symbol));
    memcpy(rule->key+sizeof(Symbol), &right, sizeof(Symbol));
    rule->symbol.terminal = false;
    rule->symbol.val = rule_number;
    rule_number--;

    return rule;
}

void replace_with_new_rule(Grammar *grammar, SymbolNode *pos1, SymbolNode *pos2) {
    // Create a new rule to represent this digram
    RuleHash* rule = create_rule(pos1->symbol, pos1->next->symbol);
    HASH_ADD_KEYPTR(hh, grammar->rule_table, rule->key, rule->key_len, rule);

    SymbolNode *p1, *p2, *p3, *p4;
    p1 = pos1; p2 = pos1->next; p3 = pos2; p4 = pos2->next;

    insert_symbol(grammar, pos1->next, rule->symbol);
    DL_DELETE(grammar->symbols, pos1);
    DL_DELETE(grammar->symbols, pos1->next);

    insert_symbol(grammar, pos2->next, rule->symbol);
    DL_DELETE(grammar->symbols, pos2);
    DL_DELETE(grammar->symbols, pos2->next);

    free(p1); free(p2); free(p3); free(p4);
}

bool symbol_equal(Symbol lhs, Symbol rhs) {
    return (lhs.terminal == rhs.terminal && lhs.val == rhs.val);
}

SymbolNode* exists_digram(Grammar *grammar, SymbolNode *left, SymbolNode *right) {
    SymbolNode* tmp;
    for(tmp = grammar->symbols; tmp!=left && tmp->next!=left; tmp = tmp->next) {
        if(symbol_equal(tmp->symbol, left->symbol) && symbol_equal(tmp->next->symbol, right->symbol))
            return tmp;
    }
    return NULL;
}

void new_digram(Grammar *grammar, SymbolNode *left, SymbolNode *right) {
    RuleHash *rule_table = grammar->rule_table;
    zero_set_symbol(&left->symbol);
    zero_set_symbol(&right->symbol);

    // Check rule table to see if this digram can be represented by a rule
    void *key = malloc(2 * sizeof(Symbol));
    memcpy(key, &left->symbol, sizeof(Symbol));
    memcpy(key+sizeof(Symbol), &right->symbol, sizeof(Symbol));

    RuleHash *found_rule;
    HASH_FIND(hh, rule_table, key, 2*sizeof(Symbol), found_rule);
    free(key);

    if(found_rule) {
        // Repalce the left, right nodes with the rule symbol
        SymbolNode *pos = left->prev;
        DL_DELETE(grammar->symbols, right);
        DL_DELETE(grammar->symbols, left);
        free(left);
        free(right);
        SymbolNode *sn = insert_symbol(grammar, pos, found_rule->symbol);

        if(sn->next)
            new_digram(grammar, sn, sn->next);
        if(grammar->symbols != sn)
            new_digram(grammar, sn->prev, sn);

    } else {
        // Check to see if this is a repeated digram
        SymbolNode *pos = exists_digram(grammar, left, right);
        if(pos)
            replace_with_new_rule(grammar, pos, left);
    }
}

// Insert one symbol after pos
SymbolNode* insert_symbol(Grammar *grammar, SymbolNode *pos, Symbol s) {
    SymbolNode *sn = malloc(sizeof(SymbolNode));
    sn->symbol = s;
    DL_APPEND_ELEM(grammar->symbols, pos, sn);

    return sn;
}


void read_terminal(Grammar *grammar, int val) {
    SymbolNode *sn = malloc(sizeof(SymbolNode));
    sn->symbol.terminal = false;
    sn->symbol.val = val;
    DL_APPEND(grammar->symbols, sn);

    if(grammar->symbols != sn)
        new_digram(grammar, sn->prev, sn);
}


void clean_grammar(Grammar *grammar) {
    SymbolNode *symbols = grammar->symbols;
    RuleHash *rule_table = grammar->rule_table;

    SymbolNode *elt, *tmp1;
    int count;
    DL_COUNT(symbols, elt, count);
    printf("symbols count: %d\n", count);
    DL_FOREACH_SAFE(symbols, elt, tmp1) {
        DL_DELETE(symbols, elt);
        //printf("delete symbol: %d\n", elt->symbol.val);
        free(elt);
    }

    printf("rules count: %d\n", HASH_COUNT(rule_table));
    RuleHash *rule, *tmp2;
    HASH_ITER(hh, rule_table, rule, tmp2) {
        HASH_DEL(rule_table, rule);
        //printf("delete rule %d --> ", rule->symbol.val);
        int n = rule->key_len / sizeof(Symbol);
        Symbol s;
        for(int i = 0; i < n; i++) {
            memcpy(&s, rule->key+i*sizeof(Symbol), sizeof(Symbol));
            //printf("%d ", s.val);
        }
        //printf("\n");
        free(rule);
    }
}

int main() {
    Grammar grammar;
    grammar.rule_table = NULL;
    grammar.symbols = NULL;

    read_terminal(&grammar, 1);
    read_terminal(&grammar, 2);
    read_terminal(&grammar, 1);
    read_terminal(&grammar, 2);
    read_terminal(&grammar, 1);
    read_terminal(&grammar, 2);
    read_terminal(&grammar, 1);
    read_terminal(&grammar, 2);

    clean_grammar(&grammar);
}
