#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes,
 *         or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *current, *ancestor;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	/* Traverse up the tree from the first node looking for second */
	for (current = first; current != NULL; current = current->parent)
	{
		for (ancestor = second; ancestor != NULL; ancestor = ancestor->parent)
		{
			if (current == ancestor)
				return ((binary_tree_t *)current);
		}
	}

	return (NULL);
}
