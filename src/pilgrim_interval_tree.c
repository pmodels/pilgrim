/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "pilgrim_utils.h"
#include "pilgrim_interval_tree.h"

// A utility function to create a new BST node
IntervalNode* newIntervalNode(intptr_t start, size_t size, bool heap)
{
	IntervalNode* temp = pilgrim_malloc(sizeof(IntervalNode));
	temp->start = start;
	temp->size = size;
    temp->id_node = NULL;
	temp->left = temp->right = NULL;
    temp->heap = heap;
	return temp;
}

// A utility function to do inorder traversal of BST
void itree_inorder(IntervalNode* root)
{
	if (root != NULL) {
		itree_inorder(root->left);
		printf("(%ld, %ld)\n", root->start, root->size);
		itree_inorder(root->right);
	}
}

/* A utility function to insert a new node with given addr_start in BST */
IntervalNode* itree_insert(IntervalNode* node, intptr_t start, size_t size, bool heap)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return newIntervalNode(start, size, heap);

	/* Otherwise, recur down the tree */
	if (start < node->start)
		node->left = itree_insert(node->left, start, size, heap);
	else
		node->right = itree_insert(node->right, start, size, heap);

	/* return the (unchanged) node pointer */
	return node;
}

void itree_destroy(IntervalNode* node) {
    if(node == NULL) return;
    if(node->left == NULL && node->right == NULL) {
        pilgrim_free(node, sizeof(IntervalNode));
        return;
    }
    if(node->left)
        itree_destroy(node->left);
    if(node->right)
        itree_destroy(node->right);
    pilgrim_free(node, sizeof(IntervalNode));
}

IntervalNode* itree_search(IntervalNode* root, intptr_t key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || (root->start <= key && root->start+root->size > key))
       return root;

    // Key is greater than root's key
    if (root->start < key)
       return itree_search(root->right, key);
    // Key is smaller than root's key
    return itree_search(root->left, key);
}


/* Given a binary search tree and a addr_start, this function
deletes the key and returns the new root */
IntervalNode* itree_delete(IntervalNode* root, intptr_t start)
{
	// Base case
	if (root == NULL)
		return root;

	// Recursive calls for ancestors of
	// node to be deleted
	if (root->start > start) {
		root->left = itree_delete(root->left, start);
		return root;
	} else if (root->start < start) {
		root->right = itree_delete(root->right, start);
		return root;
	}

	// We reach here when root is the node
	// to be deleted.

	// If one of the children is empty
	if (root->left == NULL) {
		IntervalNode* temp = root->right;
		pilgrim_free(root, sizeof(IntervalNode));
		return temp;
	}
	else if (root->right == NULL) {
		IntervalNode* temp = root->left;
		pilgrim_free(root, sizeof(IntervalNode));
		return temp;
	}

	// If both children exist
	else {

		IntervalNode* succParent = root;

		// Find successor
		IntervalNode* succ = root->right;
		while (succ->left != NULL) {
			succParent = succ;
			succ = succ->left;
		}

		// Delete successor. Since successor
		// is always left child of its parent
		// we can safely make successor's right
		// right child as left of its parent.
		// If there is no succ, then assign
		// succ->right to succParent->right
		if (succParent != root)
			succParent->left = succ->right;
		else
			succParent->right = succ->right;

		// Copy Successor Data to root
		root->start = succ->start;
		root->size = succ->size;

		// Delete Successor and return root
		pilgrim_free(succ, sizeof(IntervalNode));
		return root;
	}
}
/*
int main()
{
	IntervalNode* root = NULL;
	root = itree_insert(root, 15, 20);
	root = itree_insert(root, 10, 30);
	root = itree_insert(root, 5, 20);
	root = itree_insert(root, 12, 15);
	root = itree_insert(root, 17, 19);
	root = itree_insert(root, 30, 40);

	printf("Inorder traversal of the given tree \n");
	itree_inorder(root);


	printf("Inorder traversal of the given tree \n");
    root = itree_delete(root, 15);
	itree_inorder(root);

    IntervalNode *res = itree_search(root, 10);
    printf("Search for 10: (%ld %ld)\n", res->start, res->size);

    itree_destroy(root);

	return 0;
}
*/
