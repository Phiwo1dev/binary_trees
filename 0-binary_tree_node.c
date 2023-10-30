#include "binary_trees.h"

/**
 * binary_tree_node - A function that creates a binary tree node.
 * @parent: Pointer to the parent of the node to create.
 * @value: Value to put in the new node.
 *
 * Return: NULL if an error occurs
 *         pointer to the new node, otherwise.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)

{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
