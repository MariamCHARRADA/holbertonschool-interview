#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Size of the tree
 */
static size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * find_insert_position - Finds the next insertion position
 * @root: Pointer to the root node of the tree
 * @index: Current index in the traversal
 * @size: Target position for the new node
 * Return: Pointer to the parent of the new node
 */
static binary_tree_t *find_insert_position(binary_tree_t *root, size_t index,
										   size_t size)
{
	if (!root)
		return (NULL);

	if (index == size / 2)
		return (root);

	binary_tree_t *left = find_insert_position(root->left, 2 * index + 1, size);

	if (left)
		return (left);

	return (find_insert_position(root->right, 2 * index + 2, size));
}

/**
 * heapify_up - Restores the Max Heap property by swapping upwards
 * @node: Pointer to the inserted node
 */
static void heapify_up(binary_tree_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		int temp = node->n;

		node->n			= node->parent->n;
		node->parent->n = temp;
		node			= node->parent;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the new node
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size_t size			  = binary_tree_size(*root) + 1;
	binary_tree_t *parent = find_insert_position(*root, 0, size);

	if (!parent)
		return (NULL);

	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	heapify_up(new_node);

	return (new_node);
}
