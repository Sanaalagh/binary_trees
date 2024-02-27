#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/* Function prototypes for clarity and forward declaration */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
void print_current_level(
		const binary_tree_t *tree, size_t level, void (*func)(int));

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node, value of the node will
 *        be passed as a parameter to this function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	size_t height = binary_tree_height(tree);

	for (size_t level = 0; level <= height; level++)
		print_current_level(tree, level, func);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);

	size_t left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	size_t right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return ((left_height > right_height) ? left_height : right_height);
}

/**
 * print_current_level - Prints nodes at the given level of a binary tree
 * @tree: Pointer to the root node of the tree
 * @level: Level of the tree to print
 * @func: Pointer to a function to call for each node
 */
void print_current_level(
		const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (!tree || !func)
		return;

	if (level == 0)
		func(tree->n);
	else
	{
		print_current_level(tree->left, level - 1, func);
		print_current_level(tree->right, level - 1, func);
	}
}
