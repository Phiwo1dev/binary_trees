#include "binary_trees.h"

/**
 * struct node_s - singly linked list
 * @node: const binary tree node
 * @next: points to the next node
 */
typedef struct node_s

{
	const binary_tree_t *node;
	struct node_s *next;
} ll;

ll *append(ll *head, const binary_tree_t *btnode);
void free_list(ll *head);
ll *get_children(ll *head, const binary_tree_t *parent);
void levels_rec(ll *head, void (*func)(int));

/**
 * binary_tree_levelorder - function that goes through a binary tree
 *                          using level-order traversal.
 * @tree: Pointer to the root node of the tree to be traversed
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	ll *children = NULL;

	func(tree->n);
	children = get_children(children, tree);
	levels_rec(children, func);

	free_list(children);
}

/**
 * levels_rec - Function that calls funxion on all nodes at each level.
 * @head: Pointer to head of linked list.
 * @func: pointer to a function to call for each node.
 */
void levels_rec(ll *head, void (*func)(int))

{
	ll *children = NULL, *curr = NULL;

	if (!head)
		return;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		func(curr->node->n);
		children = get_children(children, curr->node);
	}
	levels_rec(children, func);
	free_list(children);
}

/**
 * get_children - Function that appends children of parent to linked list.
 * @head: Pointer to head of linked list with children to be appended.
 * @parent: Pointer to node with children to append.
 * Return: Pointer to head of the linked list.
 */
ll *get_children(ll *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = append(head, parent->left);
	if (parent->right)
		head = append(head, parent->right);
	return (head);
}

/**
 * append - Function that adds a new node at the end of a linked list.
 * @head: Pointer to head of a list
 * @btnode: binary tree node to append
 * Return: pointer to head, or NULL.
 */
ll *append(ll *head, const binary_tree_t *btnode)

{
	ll *new = NULL, *prev = NULL;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->node = btnode;
		new->next = NULL;
		if (!head)
			head = new;
		else
		{
			prev = head;
			while (prev->next)
				prev = prev->next;
			prev->next = new;
		}
	}
	return (head);
}

/**
 * free_list - Frees all the nodes in a list.
 * @head: A pointer to the head of list
 */
void free_list(ll *head)

{
	ll *ptr = NULL;

	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
