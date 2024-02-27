#include "binary_trees.h"

/**
 * find_depth - finds depth of the leftmost node
 * @tree: pointer to the root node
 * Return: depth of the leftmost node
 */
static int find_depth(const binary_tree_t *tree)
{
    int d = 0;
    while (tree) {
        d++;
        tree = tree->left;
    }
    return d;
}

/**
 * is_perfect_rec - recursive function to check if binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @depth: depth of the tree
 * @level: current level in the tree
 * Return: 1 if perfect, 0 otherwise
 */
static int is_perfect_rec(const binary_tree_t *tree, int depth, int level)
{
    if (!tree)
        return (1);

    if (!tree->left && !tree->right)
        return (depth == level + 1);

    if (!tree->left || !tree->right)
        return (0);

    return is_perfect_rec(tree->left, depth, level + 1) &&
           is_perfect_rec(tree->right, depth, level + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if not or tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int d = find_depth(tree);
    return is_perfect_rec(tree, d, 0);
}
