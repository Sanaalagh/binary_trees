#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/* Function to print binary tree in 2D */
void print2DUtil(binary_tree_t *root, int space) {
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->n);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void binary_tree_print(const binary_tree_t *root) {
    // Cast away const qualifier
    print2DUtil((binary_tree_t *)root, 0);
}
