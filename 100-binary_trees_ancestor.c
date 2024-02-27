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
	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	const binary_tree_t *f_parent = first, *s_parent = second;

	while (f_parent)
	{
		s_parent = second;
		while (s_parent)
		{
			if (s_parent == f_parent)
				return ((binary_tree_t *)f_parent);
			s_parent = s_parent->parent;
		}
		f_parent = f_parent->parent;
	}

	return (NULL);
}
