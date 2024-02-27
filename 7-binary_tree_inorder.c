#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node. The value in the node
 *        must be passed as a parameter to this function.
 *
 * Description: This function traverses the tree using in-order traversal,
 * which means it visits the left subtree, the root, and then the right
 * subtree. This order of traversal is especially useful in binary search
 * trees where it retrieves the nodes in sorted order.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func); /* Visit left subtree */
	func(tree->n);                         /* Visit node */
	binary_tree_inorder(tree->right, func); /* Visit right subtree */
}
