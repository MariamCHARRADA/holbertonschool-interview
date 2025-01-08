#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * checkHeight - Calculates the height of a binary tree
 * @tree: Pointer to the node to start the height calculation
 *
 * Return: The height of the tree starting at @node
 */
static size_t checkHeight(const binary_tree_t *tree)
{
	size_t h_left;
	size_t h_right;

	if (!tree)
		return (0);

	h_left	= tree->left ? 1 + checkHeight(tree->left) : 0;
	h_right = tree->right ? 1 + checkHeight(tree->right) : 0;

	return (h_left > h_right ? h_left : h_right);
}

/**
 * preorderTraversal - Traverses the binary tree using pre-order traversal
 *                     and finds the last node at the deepest level
 * @root: Pointer to the root of the tree
 * @node: Pointer to store the last node in the tree
 * @h: Height of the tree
 * @l: Current level in the traversal
 */
void preorderTraversal(heap_t *root, heap_t **node, size_t h, size_t l)
{
	if (!root)
		return;

	if (h == l)
		*node = root;

	l++;
	if (root->left)
		preorderTraversal(root->left, node, h, l);
	if (root->right)
		preorderTraversal(root->right, node, h, l);
}

/**
 * sort - Restores the Max Binary Heap property after extracting the root
 * @tmp: Pointer to the heap root node
 *
 * Return: Pointer to the last node in the heap
 */
heap_t *sort(heap_t *tmp)
{
	int n;

	while (tmp->left || tmp->right)
	{
		if (!tmp->right || tmp->left->n > tmp->right->n)
		{
			n			 = tmp->n;
			tmp->n		 = tmp->left->n;
			tmp->left->n = n;
			tmp			 = tmp->left;
		}
		else if (!tmp->left || tmp->left->n < tmp->right->n)
		{
			n			  = tmp->n;
			tmp->n		  = tmp->right->n;
			tmp->right->n = n;
			tmp			  = tmp->right;
		}
	}
	return (tmp);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root of the heap
 *
 * Return: The value stored in the root node, or 0 if the heap is empty
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *tmp, *node;

	if (!root || !*root)
		return (0);

	tmp	  = *root;
	value = tmp->n;

	if (!tmp->left && !tmp->right)
	{
		*root = NULL;
		free(tmp);
		return (value);
	}

	preorderTraversal(tmp, &node, checkHeight(tmp), 0);

	tmp->n = node->n;

	if (node->parent->right == node)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;

	free(node);

	tmp = sort(*root);

	return (value);
}
