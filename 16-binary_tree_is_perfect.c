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
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of tree otherwise 0 if tree is empty
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) +
			binary_tree_size(tree->right));
}

/**
 * exponent_recurs - returns the value of x raised to the power of y
 * @x: the value to exponentiate
 * @y: the power to raise x to
 * Return: x to the power of y, or -1 if y is negative
 */

int exponent_recurs(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * exponent_recurs(x, y - 1));
}

/**
 * binary_tree_is_perfect - a function to check if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t tree_height = 0;
	size_t tree_nodes = 0;
	size_t exp = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	tree_height = binary_tree_height(tree);
	tree_nodes = binary_tree_size(tree);

	exp = (size_t)exponent_recurs(2, tree_height + 1);
	return (exp - 1 == tree_nodes);
}
