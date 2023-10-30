#include "binary_trees.h"

/**
 * binary_tree_is_root - A function that checks if a given node is a root.
 * @node: Pointer to the node to be checked.
 *
 * Return: 1 - if the node is a root.
 *         Otherwise - 0.
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
