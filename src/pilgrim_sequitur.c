#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mpi.h"
#include "pilgrim_sequitur.h"

static Grammar grammar;
static size_t memory_usage = 0;
static size_t peak_memory = 0;
static int peak_digrams;
static int peak_rules;


void* mymalloc(size_t size) {
    memory_usage += size;
    if(memory_usage > peak_memory) {
        peak_memory = memory_usage;
        peak_digrams = HASH_COUNT(grammar.digram_table);
        Symbol *tmp;
        DL_COUNT(grammar.rules, tmp, peak_rules);
    }
    return malloc(size);
}
void myfree(void *ptr, size_t size) {
    memory_usage -= size;
    free(ptr);
}

void delete_symbol(Symbol *sym) {
    symbol_delete(sym->rule, sym);
}

/**
 * Replace a digram by a rule (non-terminal)
 *
 * @delete_digram: we only put digram after we perform check_digram();
 * during the process of check_digram, we found a match and try to this==match
 * In this case, the matched digram is already in the digram table, however the
 * new digram has not been inserted into the table yet, so we don't delete becuase
 * other rules body may have the same key.
 *
 */
void replace_digram(Symbol *origin, Symbol *rule, bool delete_digram) {
    if(!IS_RULE_HEAD(rule))
        ERROR_ABORT("replace_digram: not a rule head?\n");

    // Create an non-terminal
    Symbol *replaced = new_symbol(rule->val, false, rule);

    // carefule here, if orgin is the first symbol, then
    // NULL will be used as the tail node.
    Symbol *prev = NULL;
    if(origin->rule->rule_body != origin)
        prev = origin->prev;
    if(prev != NULL)
        digram_delete(&grammar.digram_table, prev);

    // delete digram before deleting symbols, otherwise we won't have correct digrams
    if(delete_digram) {
        digram_delete(&grammar.digram_table, origin);
        digram_delete(&grammar.digram_table, origin->next);
    }

    delete_symbol(origin);
    delete_symbol(origin->next);

    symbol_put(origin->rule, prev, replaced);

    // Add a new symbol (replaced) after prev
    // may introduce another repeated digram that we need to check
    if( check_digram(prev) == 0) {
        check_digram(replaced);
    }
}

/**
 * Rule Utility
 * Replace a rule with its body if the rule is used only once
 *
 * @sym: is an non-terminal which should be replaced by sym->rule_head->rule_body
 */
void expand_instance(Symbol *sym) {
    Symbol *rule = sym->rule_head;
    // just double check to make sure
    if(rule->ref != 1)
        ERROR_ABORT("Attempt to delete a rule that has multiple references!\n");

    digram_delete(&grammar.digram_table, sym);


    int n = 0;
    Symbol *this;
    Symbol *tail = sym;
    DL_FOREACH(rule->rule_body, this) {
        digram_delete(&grammar.digram_table, this);

        Symbol *s = new_symbol(this->val, this->terminal, this->rule_head);
        symbol_put(sym->rule, tail, s);
        tail = s;
        n++;
    }

    this = sym->next;
    for(int i = 0; i < n; i++) {
        digram_put(&grammar.digram_table, this);
        this = this->next;
    }

    delete_symbol(sym);
    rule_delete(&grammar.rules, rule);
}

/**
 * Handle the case in which a just-created digram matches
 * a previously existing one.
 *
 */
void process_match(Symbol *this, Symbol *match) {
    Symbol *rule = NULL;

    // 1. The match consists of entire body of a rule
    // Then we replace the new digram with this rule
    if(match->prev == match->next) {
        rule = match->rule;
        replace_digram(this, match->rule, false);
    } else {
        // 2. Otherwise, we create a new rule and replace the repeated digrams with this rule
        rule = new_rule();
        symbol_put(rule, rule->rule_body, new_symbol(this->val, this->terminal, this->rule_head));
        symbol_put(rule, rule->rule_body->prev, new_symbol(this->next->val, this->next->terminal, this->next->rule_head));
        rule_put(&grammar.rules, rule);

        replace_digram(match, rule, true);
        replace_digram(this, rule, false);

        // Insert the rule body into the digram table
        digram_put(&grammar.digram_table, rule->rule_body);
    }


    // Check for "Rule Utility"
    // The first symbol of the just-created rule,
    // if is an non-terminal could be underutilized
    if(rule && rule->rule_body) {
        Symbol* tocheck = rule->rule_body->rule_head;
        if(tocheck && tocheck->ref < 2) {
            #ifdef DEBUG
                printf("rule utility:%d %d\n", tocheck->val, tocheck->ref);
            #endif
            expand_instance(rule->rule_body);
        }
    }

}

/**
 * Return 1 means the digram is replaced by a rule
 * (Either a new rule or an exisiting rule)
 */
int check_digram(Symbol *sym) {

    if(sym == NULL || sym->next == NULL || sym->next == sym)
        return 0;

    Symbol *match = digram_get(grammar.digram_table, sym->val, sym->next->val);

    if(match == NULL) {
        // Case 1. new digram, put it in the table
        #ifdef DEBUG
            printf("new digram %d %d\n", sym->val, sym->next->val);
        #endif
        digram_put(&grammar.digram_table, sym);
        return 0;
    }

    if(match->next == sym) {
        // Case 2. match found but overlap: do nothing
        #ifdef DEBUG
            printf("found digram but overlap\n");
        #endif
        return 0;
    } else {
        // Case 3. non-overlapping match found
        #ifdef DEBUG
            printf("found non-overlapping digram %d %d\n", sym->val, sym->next->val);
        #endif
        process_match(sym, match);
        return 1;
    }

}

Symbol* append_terminal(int val) {
    Symbol *sym = new_symbol(val, true, NULL);

    Symbol *main_rule = grammar.rules;
    Symbol *tail;
    if(main_rule->rule_body)
        tail = main_rule->rule_body->prev;  // Get the last symbol
    else
        tail = main_rule->rule_body;        // NULL, no symbol yet

    symbol_put(main_rule, tail, sym);
    check_digram(sym->prev);

    return sym;
}


void print_digrams() {
    Digram *digram, *tmp;

    printf("digrams count: %d\n", HASH_COUNT(grammar.digram_table));
    HASH_ITER(hh, grammar.digram_table, digram, tmp) {
        int v1, v2;
        memcpy(&v1, digram->key, sizeof(int));
        memcpy(&v2, digram->key+sizeof(int), sizeof(int));

        if(digram->symbol->rule)
            printf("digram(%d, %d, rule:%d): %d %d\n", v1, v2, digram->symbol->rule->val, digram->symbol->val, digram->symbol->next->val);
        else
            printf("digram(%d, %d, rule:): %d %d\n", v1, v2, digram->symbol->val, digram->symbol->next->val);
    }
}

void print_rules() {
    Symbol *rule, *sym;
    int rules_count = 0, symbols_count = 0;
    DL_COUNT(grammar.rules, rule, rules_count);

    DL_FOREACH(grammar.rules, rule) {
        printf("Rule %d :-> ", rule->val);

        int count;
        DL_COUNT(rule->rule_body, sym, count);
        symbols_count += count;

        DL_FOREACH(rule->rule_body, sym) {
            printf("%d ", sym->val);
        }
        printf("\n");
    }

    printf("\n=======================\nNumber of rule: %d\n", rules_count);
    printf("Number of symbols: %d\n", symbols_count);
    printf("Number of Digrams: %d\n=======================\n", HASH_COUNT(grammar.digram_table));
}


void sequitur_init() {
    grammar.digram_table = NULL;
    grammar.rules = NULL;

    // Add the main rule: S, which will be the head of the rule list
    rule_put(&grammar.rules, new_rule());
}

void sequitur_finalize() {
    int mpi_rank, mpi_size;
    PMPI_Comm_size(MPI_COMM_WORLD, &mpi_size);
    PMPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);

    if(mpi_rank == 0) {
        print_rules();
        print_digrams();
    }

    printf("Peak memory usage: %ldKB, digrams: %d, rules: %d\n", peak_memory/1024, peak_digrams, peak_rules);

    // Write grammars from all ranks to one file
    sequitur_dump("logs/grammars.txt", &grammar, mpi_rank, mpi_size);

    // clean up
    Digram *digram, *tmp;
    HASH_ITER(hh, grammar.digram_table, digram, tmp) {
        free(digram->key);
    }
    HASH_CLEAR(hh, grammar.digram_table);

    Symbol *rule, *sym, *tmp2, *tmp3;
    DL_FOREACH_SAFE(grammar.rules, rule, tmp2) {
        DL_FOREACH_SAFE(rule->rule_body, sym, tmp3) {
            DL_DELETE(rule->rule_body, sym);
            free(sym);
        }
        DL_DELETE(grammar.rules, rule);
        free(rule);
    }
}

