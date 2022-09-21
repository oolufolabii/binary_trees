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
 * binary_tree_postorder - goes through a binary tree using post-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 * @level: the level of the tree to call func upon
 */
void binary_tree_postorder(const binary_tree_t *tree,
						   void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		binary_tree_postorder(tree->left, func, level - 1);
		binary_tree_postorder(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - goes through a binary
 * 		tree using level-order traversal
 *
 * @tree: pointer to the root node of the tree to traverse
 * @func:  pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t current_level, max_level;

	if (!tree || !func)
		return;

	max_level = binary_tree_height(tree) + 1;

	for (current_level = 1; current_level <= max_level; current_level++)
		binary_tree_postorder(tree, func, current_level);
}
