#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of tree, otherwise NULL if empty
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (NULL);

	size_t left_node_height = 0;
	size_t right_node_height = 0;

	left_node_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_node_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (left_node_height > right_node_height ?
				left_node_height : right_node_height);
}
