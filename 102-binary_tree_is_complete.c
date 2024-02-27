#include "binary_trees.h"
#include <stdbool.h>

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * @index: index of the current node
 * @total_nodes: total number of nodes in the tree
 * Return: true if complete, false otherwise
 */
bool is_complete(const binary_tree_t *tree, int index, int total_nodes);

/**
 * count_nodes - Counts the nodes in a binary tree
 * @tree: pointer to the root node of the tree to count the nodes of
 * Return: number of nodes in the tree
 */
int count_nodes(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	int total_nodes = count_nodes(tree);

	return (is_complete(tree, 0, total_nodes));
}

bool is_complete(const binary_tree_t *tree, int index, int total_nodes)
{
	if (!tree)
		return (true);

	if (index >= total_nodes)
		return (false);

	return (is_complete(tree->left, 2 * index + 1, total_nodes) &&
		is_complete(tree->right, 2 * index + 2, total_nodes));
}

int count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}
