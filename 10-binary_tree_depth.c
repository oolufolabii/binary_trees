#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 *
 * @tree: pointer to the node to measure the depth
 * Return: returns the depth of the node, otherwise null if empty node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t tree_depth = 0;

	while (tree->parent)
	{
		tree_depth++;
		tree = tree->parent;
	}
}
