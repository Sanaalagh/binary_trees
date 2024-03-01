#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: A pointer to the root node of the tree where to remove a node
 * @value: The value to remove from the tree
 *
 * Return: A pointer to the new root node of the tree after removing the
 *         desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *temp;

    if (root == NULL)
        return NULL;

    /* If the value to be removed is smaller than the root value,
       it's in the left subtree */
    if (value < root->n)
        root->left = bst_remove(root->left, value);

    /* If the value to be removed is greater than the root value,
       it's in the right subtree */
    else if (value > root->n)
        root->right = bst_remove(root->right, value);

    /* If the value to be removed is equal to the root value */
    else
    {
        /* If the root has no children or only one child */
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        /* If the root has two children,
           find the in-order successor (smallest in the right subtree) */
        temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        /* Copy the value of the in-order successor to the root */
        root->n = temp->n;

        /* Remove the in-order successor from the right subtree */
        root->right = bst_remove(root->right, temp->n);
    }

    return root;
}
