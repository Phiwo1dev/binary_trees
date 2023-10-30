#include "binary_trees."

/**
 * binary_tree_leaves - A function that counts the leaves in a binary tree.
 * @tree: Pointer to the root node of the tree with leaves to count.
 *
 * Return: Number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)

{
	size_t num = 0;

	if (tree)
	{
		num += (!tree->left && !tree->right) ? 1 : 0;
		num += binary_tree_leaves(tree->left);
		num += binary_tree_leaves(tree->right);
	}
	return (num);
}
