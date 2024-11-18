#include "binary_trees.h"

/**
 * height - Computes the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree or 0 if tree is NULL.
 */
int height(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    int left_height = height(tree->left);
    int right_height = height(tree->right);
    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_bst - Checks if a binary tree is a Binary Search Tree (BST).
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum value allowed in the current subtree.
 * @max: Maximum value allowed in the current subtree.
 *
 * Return: 1 if the tree is a valid BST, otherwise 0.
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
 * is_avl_helper - Helper function to check if a binary tree is AVL.
 * @tree: Pointer to the root node of the tree to check.
 * @height: Pointer to store the height of the tree.
 *
 * Return: 1 if the tree is a valid AVL Tree, otherwise 0.
 */
int is_avl_helper(const binary_tree_t *tree, int *height)
{
    if (!tree)
    {
        *height = 0;
        return (1);
    }

    int left_height = 0, right_height = 0;

    if (!is_avl_helper(tree->left, &left_height) ||
        !is_avl_helper(tree->right, &right_height))
        return (0);

    *height = 1 + (left_height > right_height ? left_height : right_height);

    if (abs(left_height - right_height) > 1)
        return (0);

    return (is_bst(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid AVL Tree, otherwise 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int height = 0;

    if (!tree)
        return (0);

    return (is_avl_helper(tree, &height));
}
