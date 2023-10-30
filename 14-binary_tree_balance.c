#include "binary_trees.h"

/**
 * binary_tree_balance - A function that measures the balance factor.
 * @tree: Pointer to the root node of tree to measure the balance factor of.
 *
 * Return: 0 or the balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)

{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - measures height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure height of.
 *
 * Return: 0 if tree is Null, otherwise height.
 */
size_t binary_tree_height(const binary_tree_t *tree)

{
	if (tree)
	{
		size_t h = 0, r = 0;

		h = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
