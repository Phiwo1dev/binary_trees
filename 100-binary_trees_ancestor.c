#include "binary_trees.h"

/**
 * binary_trees_ancestor - Function that finds the lowest common ancestor
 *				of two nodes
 * @first: pointer to the first node
 * @second: pointer to the 2nd node.
 *
 * Return: NULL - If no common ancestors, else return common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ma, *pa;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	ma = first->parent, pa = second->parent;
	if (first == pa || !ma || (!ma->parent && pa))
		return (binary_trees_ancestor(first, pa));
	else if (ma == second || !pa || (!pa->parent && ma))
		return (binary_trees_ancestor(ma, second));
	return (binary_trees_ancestor(ma, pa));
}
