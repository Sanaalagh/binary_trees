#include "binary_trees.h"
#include <limits.h>

int bst_helper(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * bst_helper - Helper function to check BST validity within min/max bounds
 * @tree: Pointer to the current node of the tree to check
 * @min: Minimum valid value for current node
 * @max: Maximum valid value for current node
 * Return: 1 if tree is a valid BST within min/max bounds, 0 otherwise
 */
int bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (bst_helper(tree->left, min, tree->n) &&
			bst_helper(tree->right, tree->n, max));
}
