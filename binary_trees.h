#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>

/* Basic Binary Tree Structure */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/* Function Prototypes */
size_t binary_tree_size(const binary_tree_t *tree);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/* Basic operations */
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);

/* Traversal */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/* Measurements */
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);

/* Binary Tree Properties */
int binary_tree_is_bst(const binary_tree_t *tree);

/* BST operations */
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);

/* AVL Tree operations */
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);
avl_t *avl_search(const avl_t *tree, int value);

/* Heap operations */
heap_t *heap_insert(heap_t **root, int value);
int heap_extract(heap_t **root);
int *heap_to_array(const heap_t *heap, size_t *size);

/* Special */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);

int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

int binary_tree_is_bst(const binary_tree_t *tree);

bst_t *bst_insert(bst_t **tree, int value);

bst_t *array_to_bst(int *array, size_t size);

/* Function to print binary tree (provided) */
void binary_tree_print(const binary_tree_t *);

#endif /* BINARY_TREES_H */
