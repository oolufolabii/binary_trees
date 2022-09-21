#include "binary_trees.h"

/**
 * binary_tree_rotate_right - - performs a right-rotation on a binary tree
 *
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp_rotor = NULL, *parent;

	if (!tree || !tree->left)
		return (NULL);

	temp_rotor = tree;
	parent = tree->parent;
	tree = tree->left;
	tree->parent = NULL;

	if (tree->right)
	{
		temp_rotor->left = tree->right;
		tree->right->parent = temp_rotor;
	}

	else
		temp_rotor->left = NULL;
	temp_rotor->parent = tree;
	tree->right = temp_rotor;

	if (parent)
		parent->left = tree;
	tree->parent = parent;

	return (tree);
}
