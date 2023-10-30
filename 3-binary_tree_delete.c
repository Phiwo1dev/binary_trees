#include "binary_trees.h"

/**
 * binary_tree_delete - A function that deletes a binary tree.
 * @tree: Pointer to the root node of the tree to be delete.
 */
void binary_tree_delete(binary_tree_t *tree)

{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
