#include "binary_trees.h"

size_t depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - Function that finds the lowest
 *			common ancestor of two nodes.
 * @first: A pointer to the 1st node
 * @second: Pointer to the 2nd node
 *
 * Return: NULL if no common ancestors, otherwise return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t depth1, depth2;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);

	for (depth1 = depth(first); depth1 > 1; depth1--)
		first = first->parent;
	for (depth2 = depth(second); depth2 > 1; depth2--)
		second = second->parent;

	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);
	else
		return (NULL);
}

/**
 * depth - Function that measures the depth of a node in a binary tree.
 * @tree: Pointer to the node to measure depth of
 *
 * Return: 0 if tree is NULL, otherwise return depth.
 */
size_t depth(const binary_tree_t *tree)

{
	return ((tree->parent != NULL) ? 1 + depth(tree->parent) : 0);
}
