#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * print2DUtil - Function to print binary tree in 2D
 * @root: Pointer to the root node of the tree to print
 * @space: Initial space for the root
 */
void print2DUtil(binary_tree_t *root, int space)
{
	if (root == NULL)
		return;

	space += 10;

	print2DUtil(root->right, space);

	printf("\n");
	for (int i = 10; i < space; i++)
		printf(" ");
	printf("%d\n", root->n);

	print2DUtil(root->left, space);
}

/**
 * binary_tree_print - Wrapper over print2DUtil()
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	print2DUtil((binary_tree_t *)tree, 0);
}
