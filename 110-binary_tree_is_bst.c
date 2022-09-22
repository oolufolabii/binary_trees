#include "binary_trees.h"

/**
 * bst_helper_func - checks if a binary tree is a valid BST
 * @tree: pointer to the tree's root node to check.
 * @min: lower level of checked nodes
 * @max: highest level of checked nodes
 *
 * Return: 1 if a valid BST otherwise 0
 */
int bst_helper_func(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (bst_helper_func(tree->left, min, tree->n - 1) &&
			bst_helper_func(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checker for a valid BST
 *
 * @tree: pointer to binary tree to be checked
 * Return: 1 if BST otherwise 0.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (bst_helper_func(tree, INT_MIN, INT_MAX));
}
