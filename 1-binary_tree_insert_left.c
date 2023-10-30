#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as a left-child of
 *                           of another in a binary tree.
 * @parent: Pointer to the node to insert the left-child in.
 * @value: Value to store the new node in.
 *
 * Return: NULL - if parent is NULL or an error occurs.
 *         Otherwise  Pointer to the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)

{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		node->left = parent->left;
		parent->left->parent = node;
	}
	parent->left = node;

	return (node);
}