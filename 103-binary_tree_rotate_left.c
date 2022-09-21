#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 *
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp_rotor = NULL, *parent;

	if (!tree || !tree->right)
		return (NULL);

	temp_rotor = tree;
	parent = tree->parent;
	tree = tree->right;
	tree->parent = NULL;

	if (tree->left)
	{
		temp_rotor->right = tree->left;
		tree->left->parent = temp_rotor;
	}

	else
		temp_rotor->right = NULL;
	temp_rotor->parent = tree;
	tree->left = temp_rotor;

	if (parent)
		parent->right = tree;
	tree->parent = parent;

	return (tree);
}
