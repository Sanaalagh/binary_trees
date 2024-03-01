#include <stdlib.h>
#include "binary_trees.h"

/**
 * transplant - Replaces one subtree as a child of its parent .
 * @root: double pointer to the root node of the tree
 * @u: pointer to the node to be replaced
 * @v: pointer to the node to replace with
 *
 * Description: This function replaces the subtree rooted at node `u` with
 * the subtree rooted at node `v`. `u`'s parent becomes `v`'s parent, and `u`'s
 * parent ends up having `v` as its appropriate child.
 */
void transplant(bst_t **root, bst_t *u, bst_t *v)
{
	if (!u->parent)
		*root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v)
		v->parent = u->parent;
}

/**
 * tree_minimum - Finds the minimum value in a binary search tree.
 * @node: pointer to the root node of the tree to search
 *
 * Return: pointer to the node containing the minimum value
 */
bst_t *tree_minimum(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: pointer to the root node of the tree where you will remove a node.
 * @value: The value to remove in the tree.
 *
 * Return: pointer to the new root node of
 *  the tree after removing the desired value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);

	bst_t *temp, *node_to_remove = root;

	while (node_to_remove && node_to_remove->n != value)
	{
		if (value < node_to_remove->n)
			node_to_remove = node_to_remove->left;
		else
			node_to_remove = node_to_remove->right;
	}

	if (!node_to_remove)  /* Node not found */

		return (root);

	if (!node_to_remove->left)
		transplant(&root, node_to_remove, node_to_remove->right);
	else if (!node_to_remove->right)
		transplant(&root, node_to_remove, node_to_remove->left);
	else
	{
		temp = tree_minimum(node_to_remove->right);
		if (temp->parent != node_to_remove)
		{
			transplant(&root, temp, temp->right);
			temp->right = node_to_remove->right;
			temp->right->parent = temp;
		}
		transplant(&root, node_to_remove, temp);
		temp->left = node_to_remove->left;
		temp->left->parent = temp;
	}

	free(node_to_remove);
	return (root);
}
