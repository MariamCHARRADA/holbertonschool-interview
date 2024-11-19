#include "binary_trees.h"

/**
 * validate_avl - Recursively validates an AVL tree
 * @tree: Pointer to the root node of the subtree
 * @min: Minimum value allowed for the current node
 * @max: Maximum value allowed for the current node
 * @height: Pointer to store the height of the current subtree
 *
 * Return: 1 if the subtree is a valid AVL tree, otherwise 0
 */
int validate_avl(const binary_tree_t *tree, int min, int max, int *height)
{
    int left_height = 0, right_height = 0;

    if (!tree)
    {
        *height = 0;
        return (1);
    }

    if (tree->n <= min || tree->n >= max)
        return (0);

    if (!validate_avl(tree->left, min, tree->n, &left_height) ||
        !validate_avl(tree->right, tree->n, max, &right_height))
        return (0);

    *height = 1 + (left_height > right_height ? left_height : right_height);

    if (abs(left_height - right_height) > 1)
        return (0);

    return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer
 *
 * Return: 1 if the tree is a valid AVL tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int height = 0;

    if (!tree)
        return (0);

    return (validate_avl(tree, INT_MIN, INT_MAX, &height));
}
