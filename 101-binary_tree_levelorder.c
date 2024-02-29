#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	return (left_height > right_height ? left_height : right_height);
}

/**
 * levelorder_helper - helper function to print level order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * @level: level of the tree to print
 */
void levelorder_helper(
		const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL || func == NULL)
		return;

	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		levelorder_helper(tree->left, func, level - 1);
		levelorder_helper(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	for (level = 0; level <= height; level++)
		levelorder_helper(tree, func, level);
}
