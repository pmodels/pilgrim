/**
 * Binary search tree (BST) to keep
 * existing duration bins.
 *
 * Each function has its own BST
 */
#include "dlmalloc-2.8.6.h"
#include "pilgrim_timings.h"

typedef struct BSTNode_t {
    double val;
    double err;
    int id;
    struct BSTNode_t *left, *right;
} BSTNode;

typedef struct BST_t {
    BSTNode* root;
    double tolerance;
    int current_id;
} BST;


BST duration_trees[400];        // One duration list per function
BST interval_tree;              // One interval tree for all calls


BSTNode* bst_new_node(double val, int id) {
    BSTNode* node =  (BSTNode*) dlmalloc(sizeof(BSTNode));
    node->val = val;
    node->id = id;
    node->left = node->right = NULL;
    return node;
}

// Note the returned node is not necessarily the inserted one
BSTNode* bst_insert(BSTNode* node, double val, int id) {
    if (node == NULL)
        return bst_new_node(val, id);
    if (val <= node->val)
        node->left  = bst_insert(node->left, val, id);
    else if (val > node->val)
        node->right = bst_insert(node->right, val, id);
    return node;
}

BSTNode* bst_search(BSTNode* root, double val, double err) {
    if (root == NULL )
        return NULL;

    // With in user expected error ratio
    if( (1-err)*root->val <= val &&
        (1+err)*root->val >= val )
        return root;

    if (root->val < val)
        return bst_search(root->right, val, err);
    else
        return bst_search(root->left, val, err);
}

void bst_free(BSTNode *root) {
	if (root != NULL) {
		bst_free(root->left);
		bst_free(root->right);
		dlfree(root);
	}
}


/**
 * Expose to outsiders.
 */
void bst_init() {
    int i;
    for(i = 0; i < 400; i++) {
        duration_trees[i].tolerance = 0.1;
        duration_trees[i].root = NULL;
        duration_trees[i].current_id = 0;
    }
}

void bst_finalize() {
    int i;
    for(i = 0; i < 400; i++) {
        bst_free(duration_trees[i].root);
    }
    bst_free(interval_tree.root);
}


int bst_get_id(BST *bst, double val) {
    // Find the closet existing duration/interval
    BSTNode* found = bst_search(bst->root, val, bst->tolerance);
    if(found) {
        return found->id;
    } else {
        bst_insert(bst->root, val, bst->current_id);
        return bst->current_id++;
    }
}

int get_interval_id(double interval) {
    return bst_get_id(&interval_tree, interval);
}

int get_duration_id(int func_id, double duration) {
    BST *bst = & (duration_trees[func_id]);
    return bst_get_id(bst, duration);
}

