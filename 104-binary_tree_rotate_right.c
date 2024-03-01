#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: A pointer to the root node of the tree to rotate
 *
 * Return: A pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *tmp;

	/* Check if the tree or its left child is NULL */
	if (!tree || !tree->left)
		return (tree);

	/* Store the new root (current left child) */
	new_root = tree->left;
	/* Store the right child of the new root */
	tmp = new_root->right;

	/* Perform the rotation */
	new_root->right = tree;  /* Move the tree to the right of the new root */
	tree->left = tmp;

	/* Update parent pointers */
	if (tmp)
		tmp->parent = tree;    /* Set the parent of the old root's left child */
	new_root->parent = tree->parent; /* Set the parent of the new root */

	tree->parent = new_root; /* Set the parent of the old root */

	/* Return the new root */
	return (new_root);
}
