#include "binary_trees.h"
#include <stdio.h>

int count_nodes(const binary_tree_t *tree);
int is_complete(const binary_tree_t *tree, int index, int number_nodes);

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if complete, 0 if not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int node_count;

	if (tree == NULL)
		return (0);

	node_count = count_nodes(tree);
	return (is_complete(tree, 0, node_count));
}

/**
 * count_nodes - counts the nodes in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: number of nodes
 */
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete - util function to check if binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: index of the current node
 * @number_nodes: total number of nodes in the tree
 * Return: 1 if complete, 0 if not
 */
int is_complete(const binary_tree_t *tree, int index, int number_nodes)
{
	if (tree == NULL)
		return (1);
	if (index >= number_nodes)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, number
}
