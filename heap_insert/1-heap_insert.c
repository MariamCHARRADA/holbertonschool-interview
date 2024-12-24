#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 * Return: Depth of the node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const heap_t *tree)
{
	size_t depth = 0;

	while (tree && tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const heap_t *tree)
{
	if (!tree)
		return (0);

	size_t h_left  = binary_tree_height(tree->left);
	size_t h_right = binary_tree_height(tree->right);

	return ((h_left > h_right ? h_left : h_right) + 1);
}

/**
 * insert_node_at_level - Inserts a node at the specified level
 * @tree: Pointer to the root node of the tree
 * @level: Target level for insertion
 * @value: Value to insert
 * Return: Pointer to the inserted node, or NULL on failure
 */
binary_tree_t *insert_node_at_level(binary_tree_t *tree, size_t level,
									int value)
{
	if (!tree)
		return (NULL);

	if (binary_tree_depth(tree) == level)
	{
		if (!tree->left)
			return (tree->left = binary_tree_node(tree, value));
		if (!tree->right)
			return (tree->right = binary_tree_node(tree, value));
		return (NULL);
	}

	binary_tree_t *left = insert_node_at_level(tree->left, level, value);

	return (left ? left : insert_node_at_level(tree->right, level, value));
}

/**
 * heapify - Restores the Max-Heap property
 * @node: Pointer to the newly inserted node
 * Return: Pointer to the node after heapify
 */
heap_t *heapify(heap_t *node)
{
	while (node && node->parent && node->n > node->parent->n)
	{
		int temp = node->n;

		node->n			= node->parent->n;
		node->parent->n = temp;

		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to insert
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

	size_t height = binary_tree_height(*root);
	heap_t *node  = NULL;

	for (size_t level = 0; level <= height; level++)
	{
		node = (heap_t *) insert_node_at_level((binary_tree_t *) *root, level,
											   value);
		if (node)
			break;
	}

	return (heapify(node));
}
