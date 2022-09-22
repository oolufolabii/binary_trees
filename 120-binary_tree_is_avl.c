#include "binary_trees.h"

/**
 * bt_avl_help_func - checks if a binary tree is an avl
 * @tree: pointer to the root node of the tree
 * @min: minimum value
 * @max: maximum value
 *
 * Return: 1 if tree is avl, 0 otherwise
 */
int bt_avl_help_func(const binary_tree_t *tree, int min, int max)
{
	int left_path, right_path;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	left_path = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_path = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(left_path - right_path) > 1)
		return (0);

	return (bt_avl_help_func(tree->left, min, tree->n - 1) &&
			bt_avl_help_func(tree->right, tree->n + 1, max));
	/* This is part of the BST check logic */
}

/**
 * node_height - calculates the height of a binary tree's node.
 * @tree: The binary tree.
 * @n: The accumulated height.
 * @height: A pointer to the maximum height in the node's tree.
 */
void node_height(const binary_tree_t *tree, size_t n, size_t *height)
{
	if (tree != NULL)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
		{
			if (n > *height)
			{
				*height = n;
			}
		}
		else
		{
			node_height(tree->left, n + 1, height);
			node_height(tree->right, n + 1, height);
		}
	}
}

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of tree, otherwise NULL if empty
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	node_height(tree, 0, &height);
	return (height);
}

/**
 * binary_tree_is_avl - pointer to the root node of the tree to check
 *
 * @tree: pointer to the root node of the tree to check
 * Return: return 1 if tree is a valid AVL Tree, and 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bt_avl_help_func(tree, INT_MIN, INT_MAX));
}
