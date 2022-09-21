#include "binary_trees.h"

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
 * helper_function - checks for complete binary tree
 * @tree: a pointer to the root node of the tree
 * @index: node index to check
 * @size: number of nodes in the tree
 *
 * Return: 1 if the tree is complete, otherwise 0
 */
int helper_function(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (helper_function(tree->left, 2 * index + 1, size) &&
			helper_function(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is complete, otherwise 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	return (helper_function(tree, 0, size));
}