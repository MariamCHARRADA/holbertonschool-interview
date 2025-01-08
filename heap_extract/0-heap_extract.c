#include "binary_trees.h"

/**
 * calculate_height - Calculates the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree
 */
static size_t calculate_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height	 = calculate_height(tree->left);
	right_height = calculate_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * find_last_node - Finds the last node in a binary tree
 * @root: Pointer to the root node of the tree
 * @target_node: Pointer to store the last node found
 * @height: The height of the tree
 * @level: The current level of traversal
 */
static void find_last_node(heap_t *root, heap_t **target_node, size_t height,
						   size_t level)
{
	if (!root)
		return;

	if (level == height)
		*target_node = root;

	level++;

	if (root->left)
		find_last_node(root->left, target_node, height, level);
	if (root->right)
		find_last_node(root->right, target_node, height, level);
}

/**
 * heapify_down - Restores the max-heap property by heapifying downward
 * @node: Pointer to the root node of the heap
 *
 * Return: Pointer to the final position of the swapped node
 */
static heap_t *heapify_down(heap_t *node)
{
	int temp;

	while (node->left || node->right)
	{
		if (!node->right || (node->left && node->left->n > node->right->n))
		{
			temp		  = node->n;
			node->n		  = node->left->n;
			node->left->n = temp;
			node		  = node->left;
		}
		else
		{
			temp		   = node->n;
			node->n		   = node->right->n;
			node->right->n = temp;
			node		   = node->right;
		}
	}

	return (node);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: The value stored in the root node, or 0 if the heap is empty
 */
int heap_extract(heap_t **root)
{
	int root_value;
	heap_t *last_node, *node_to_remove;

	if (!root || !*root)
		return (0);

	node_to_remove = *root;
	root_value	   = node_to_remove->n;

	if (!node_to_remove->left && !node_to_remove->right)
	{
		*root = NULL;
		free(node_to_remove);
		return (root_value);
	}

	find_last_node(node_to_remove, &last_node, calculate_height(node_to_remove),
				   0);
	node_to_remove = heapify_down(node_to_remove);

	node_to_remove->n = last_node->n;

	if (last_node->parent->right == last_node)
		last_node->parent->right = NULL;
	else
		last_node->parent->left = NULL;

	free(last_node);
	return (root_value);
}
