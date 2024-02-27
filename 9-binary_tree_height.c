#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0, right_height = 0;

    if (tree == NULL)
        return (0);

    // Check if left child exists, then get its height recursively
    if (tree->left != NULL)
        left_height = binary_tree_height(tree->left) + 1;

    // Check if right child exists, then get its height recursively
    if (tree->right != NULL)
        right_height = binary_tree_height(tree->right) + 1;

    // Return the greater of the two heights
    return (left_height > right_height ? left_height : right_height);
}
