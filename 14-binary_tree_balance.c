#include "binary_trees.h"

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
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: balance factor otherwise 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_node_height, right_node_height;

	if (!tree)
		return (0);

	left_node_height = tree->left ? (int)binary_tree_height(tree->left) : -1;
	right_node_height = tree->right ? (int)binary_tree_height(tree->right) : -1;

	return (left_node_height - right_node_height);
}
