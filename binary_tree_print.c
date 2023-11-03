#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"


/**
 * print_t - A function that stores recursively
 *		each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: The depth of the node
 * @s: The buffer
 *
 * Return: The length of printed tree.
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, i;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];
	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - Function that measures the height of a binary tree
 *
 * @tree: Pointer to the node.
 *
 * Return: Height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - A function that prints a binary tree
 *
 * @tree: A pointer to the root node of the tree to be printed
 */
void binary_tree_print(const binary_tree_t *tree)

{
	char **t;
	size_t height, i, j;

	if (!tree)
		return;
	height = _height(tree);
	t = malloc(sizeof(*t) * (height + 1));
	if (!t)
		return;
	for (i = 0; i < height + 1; i++)
	{
		t[i] = malloc(sizeof(**t) * 255);
		if (!t[i])
			return;
		memset(t[i], 32, 255);
	}
	print_t(tree, 0, 0, t);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (t[i][j] != ' ')
				break;
			t[i][j] = '\0';
		}
		printf("%s\n", t[i]);
		free(t[i]);
	}
	free(t);
}
