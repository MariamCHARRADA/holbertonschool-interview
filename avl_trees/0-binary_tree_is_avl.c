#include "binary_trees.h"
#include <limits.h>


/**
 * is_bst - Checks if a binary tree is a binary search tree.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum value allowed for the current node.
 * @max: Maximum value allowed for the current node.
 *
 * Return: 1 if tree is a BST, 0 otherwise.
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
    if (!tree)
        return (1);

    if (tree->n <= min || tree->n >= max)
        return (0);

    return (is_bst(tree->left, min, tree->n) &&
            is_bst(tree->right, tree->n, max));
}

/**
 * height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree, or -1 if tree is NULL.
 */
int height(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (!tree)
        return (-1);

    left_height = height(tree->left);
    right_height = height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_avl_helper - Checks if a binary tree is an AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is AVL, 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *tree)
{
    int left_height, right_height, balance;

    if (!tree)
        return (1);

    if (!is_bst(tree, INT_MIN, INT_MAX))
        return (0);

    left_height = height(tree->left);
    right_height = height(tree->right);
    balance = left_height - right_height;

    if (balance < -1 || balance > 1)
        return (0);

    return (is_avl_helper(tree->left) && is_avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is AVL, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (is_avl_helper(tree));
}
