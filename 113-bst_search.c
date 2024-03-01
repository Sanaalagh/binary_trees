#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: A pointer to the root node of the BST to search
 * @value: The value to search in the tree
 *
 * Return: A pointer to the node containing a value equals to value
 *         If tree is NULL or if nothing is found, returns NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	/* If the current node's value matches the search value */
	if (tree->n == value)
		return ((bst_t *)tree);

	/* If the search value is less than the current node's value */
	if (value < tree->n)
		return (bst_search(tree->left, value));
	/* Otherwise, search the right subtree */
	else
		return (bst_search(tree->right, value));
}
