#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mpi.h"
#include "pilgrim_sequitur.h"
#include "dlmalloc-2.8.6.h"

static size_t memory_usage = 0;
static size_t peak_memory = 0;
int mpi_rank, mpi_size;


void* mymalloc(size_t size) {
    memory_usage += size;
    if(memory_usage > peak_memory)
        peak_memory = memory_usage;
    return dlmalloc(size);
}
void myfree(void *ptr, size_t size) {
    memory_usage -= size;
    dlfree(ptr);
}

void delete_symbol(Symbol *sym) {
    symbol_delete(sym->rule, sym);
}


int check_digram(Grammar *grammar, Symbol *sym);

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
void replace_digram(Grammar *grammar, Symbol *origin, Symbol *rule, bool delete_digram) {
    if(!IS_RULE_HEAD(rule))
        ERROR_ABORT("replace_digram: not a rule head?\n");

    // Create an non-terminal
    Symbol *replaced = new_symbol(rule->val, 1, false, rule);

    // carefule here, if orgin is the first symbol, then
    // NULL will be used as the tail node.
    Symbol *prev = NULL;
    if(origin->rule->rule_body != origin)
        prev = origin->prev;
    if(prev != NULL)
        digram_delete(&(grammar->digram_table), prev);

    // delete digram before deleting symbols, otherwise we won't have correct digrams
    if(delete_digram) {
        digram_delete(&(grammar->digram_table), origin);
        digram_delete(&(grammar->digram_table), origin->next);
    }

    // delete symbol will set origin to NULL
    // so we need to store its rule and also delete origin->next first.
    Symbol *origin_rule = origin->rule;
    delete_symbol(origin->next);
    delete_symbol(origin);

    symbol_put(origin_rule, prev, replaced);

    // Add a new symbol (replaced) after prev
    // may introduce another repeated digram that we need to check
    if( check_digram(grammar, prev) == 0) {
        check_digram(grammar, replaced);
    }
}

/**
 * Rule Utility
 * Replace a rule with its body if the rule is used only once
 *
 * @sym: is an non-terminal which should be replaced by sym->rule_head->rule_body
 */
void expand_instance(Grammar *grammar, Symbol *sym) {
    Symbol *rule = sym->rule_head;
    // just double check to make sure
    if(rule->ref != 1)
        ERROR_ABORT("Attempt to delete a rule that has multiple references!\n");

    digram_delete(&(grammar->digram_table), sym);

    int n = 0;
    Symbol *this, *tmp;
    Symbol *tail = sym;
    DL_FOREACH_SAFE(rule->rule_body, this,  tmp) {
        // delete the digram of the old rule (rule body)
        digram_delete(&(grammar->digram_table), this);

        Symbol *s = new_symbol(this->val, this->exp, this->terminal, this->rule_head);
        symbol_put(sym->rule, tail, s);
        tail = s;
        n++;

        // delete the symbol of the old rule (rule body)
        delete_symbol(this);
    }

    this = sym->next;
    for(int i = 0; i < n; i++) {
        digram_put(&(grammar->digram_table), this);
        this = this->next;
    }

    delete_symbol(sym);
    rule_delete(&(grammar->rules), rule);
}

/**
 * Handle the case in which a just-created digram matches
 * a previously existing one.
 *
 */
void process_match(Grammar *grammar, Symbol *this, Symbol *match) {
    Symbol *rule = NULL;

    // 1. The match consists of entire body of a rule
    // Then we replace the new digram with this rule
    if(match->prev == match->next) {
        rule = match->rule;
        replace_digram(grammar, this, match->rule, false);
    } else {
        // 2. Otherwise, we create a new rule and replace the repeated digrams with this rule
        rule = new_rule(grammar);
        symbol_put(rule, rule->rule_body, new_symbol(this->val, this->exp, this->terminal, this->rule_head));
        symbol_put(rule, rule->rule_body->prev, new_symbol(this->next->val, this->next->exp, this->next->terminal, this->next->rule_head));
        rule_put(&(grammar->rules), rule);

        replace_digram(grammar, match, rule, true);
        replace_digram(grammar, this, rule, false);

        // Insert the rule body into the digram table
        digram_put(&(grammar->digram_table), rule->rule_body);
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
            expand_instance(grammar, rule->rule_body);
        }
    }

}

/**
 * Return 1 means the digram is replaced by a rule
 * (Either a new rule or an exisiting rule)
 */
int check_digram(Grammar *grammar, Symbol *sym) {

    if(sym == NULL || sym->next == NULL || sym->next == sym)
        return 0;
    // First of all, check if digram is of form a^i a^j
    // If so, make it to a^(i+j)
    if(sym->val == sym->next->val) {
        digram_delete(&(grammar->digram_table), sym->prev);
        sym->exp += sym->next->exp;
        delete_symbol(sym->next);
        return check_digram(grammar, sym->prev);
    }

    Symbol *match = digram_get(grammar->digram_table, sym, sym->next);

    if(match == NULL) {
        // Case 1. new digram, put it in the table
        #ifdef DEBUG
            printf("new digram %d %d\n", sym->val, sym->next->val);
        #endif
        digram_put(&(grammar->digram_table), sym);
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
        process_match(grammar, sym, match);
        return 1;
    }

}

Symbol* append_terminal(Grammar* grammar, int val) {
    Symbol *sym = new_symbol(val, 1, true, NULL);

    Symbol *main_rule = grammar->rules;
    Symbol *tail;
    if(main_rule->rule_body)
        tail = main_rule->rule_body->prev;  // Get the last symbol
    else
        tail = main_rule->rule_body;        // NULL, no symbol yet

    symbol_put(main_rule, tail, sym);
    check_digram(grammar, sym->prev);

    return sym;
}


void print_digrams(Grammar *grammar) {
    Digram *digram, *tmp;

    printf("digrams count: %d\n", HASH_COUNT(grammar->digram_table));
    HASH_ITER(hh, grammar->digram_table, digram, tmp) {
        int v1, v2;
        memcpy(&v1, digram->key, sizeof(int));
        memcpy(&v2, digram->key+sizeof(int), sizeof(int));

        if(digram->symbol->rule)
            printf("digram(%d, %d, rule:%d): %d %d\n", v1, v2, digram->symbol->rule->val, digram->symbol->val, digram->symbol->next->val);
        else
            printf("digram(%d, %d, rule:): %d %d\n", v1, v2, digram->symbol->val, digram->symbol->next->val);
    }
}

void print_rules(Grammar *grammar) {
    Symbol *rule, *sym;
    int rules_count = 0, symbols_count = 0;
    DL_COUNT(grammar->rules, rule, rules_count);

    DL_FOREACH(grammar->rules, rule) {
        int count;
        DL_COUNT(rule->rule_body, sym, count);
        symbols_count += count;

        //#ifdef DEBUG
        printf("Rule %d :-> ", rule->val);

        DL_FOREACH(rule->rule_body, sym) {
            if(sym->exp > 1)
                printf("%d^%d ", sym->val, sym->exp);
            else
                printf("%d ", sym->val);
        }
        printf("\n");
        //#endif
    }

    /*
    printf("\n=======================\nNumber of rule: %d\n", rules_count);
    printf("Number of symbols: %d\n", symbols_count);
    printf("Number of Digrams: %d\n=======================\n", HASH_COUNT(grammar.digram_table));
    printf("memory usage: %ldB, %ldB\n", memory_usage, (rules_count+symbols_count)*sizeof(Symbol)+80*HASH_COUNT(grammar.digram_table));
    */

    printf("[pilgrim] Rank: %d, Rules: %d, Symbols: %d\n", mpi_rank, rules_count, symbols_count);
}

void sequitur_cleanup(Grammar *grammar) {
    Digram *digram, *tmp;
    HASH_ITER(hh, grammar->digram_table, digram, tmp) {
        HASH_DEL(grammar->digram_table, digram);
        dlfree(digram->key);
        dlfree(digram);
    }

    Symbol *rule, *sym, *tmp2, *tmp3;
    DL_FOREACH_SAFE(grammar->rules, rule, tmp2) {
        DL_FOREACH_SAFE(rule->rule_body, sym, tmp3) {
            DL_DELETE(rule->rule_body, sym);
            dlfree(sym);
        }
        DL_DELETE(grammar->rules, rule);
        dlfree(rule);
    }

    grammar->digram_table = NULL;
    grammar->rules = NULL;
    grammar->rule_id = -1;
}

void sequitur_init_rule_id(Grammar *grammar, int start_rule_id) {
    grammar->digram_table = NULL;
    grammar->rules = NULL;
    grammar->rule_id = start_rule_id;

    PMPI_Comm_size(MPI_COMM_WORLD, &mpi_size);
    PMPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);

    // Add the main rule: S, which will be the head of the rule list
    rule_put(&(grammar->rules), new_rule(grammar));
}

void sequitur_init(Grammar *grammar) {
    sequitur_init_rule_id(grammar, -1);
}

void sequitur_update(Grammar *grammar, int *update_terminal_id) {
    Symbol* rule, *sym;
    DL_FOREACH(grammar->rules, rule) {
        DL_FOREACH(rule->rule_body, sym) {
            if(sym->val >= 0)
                sym->val = update_terminal_id[sym->val];
        }
    }
}

void sequitur_finalize(const char* output_path, Grammar *grammar) {

    if(mpi_rank == 0) {
        print_rules(grammar);
        // print_digrams();
    }

    // Write grammars from all ranks to one file
    sequitur_dump(output_path, grammar, mpi_rank, mpi_size);
    sequitur_cleanup(grammar);
}
