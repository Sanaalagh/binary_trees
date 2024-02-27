#include "binary_trees.h"

/**
 * height - helper function to measure the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */
static int height(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (!tree)
        return (0);
    left_height = height(tree->left);
    right_height = height(tree->right);
    return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return (height(tree->left) - height(tree->right));
}
