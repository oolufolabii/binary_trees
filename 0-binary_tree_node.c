#include "binary_trees.h"

/**
 * binary_tree_node - this creates a binary tree node
 *
 * @parent: pointer to the parent node.
 * @value: value to input to the new node.
 * Return: Pointer to the new node created or Null on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{

	binary_tree_t *new_node;
	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return NULL;
	
	new_node->n = value;
	new_node->parent = parent;
	new_node->right, new_node->left = NULL;
	return new_node;

}