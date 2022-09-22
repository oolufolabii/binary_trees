#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 *
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: Pointer to the created node, otherwise NULL
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp_node = NULL;
	bst_t *next = NULL;
	bst_t *new_node = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	temp_node = *tree;

	while (temp_node)
	{
		next = temp_node;
		if (value < temp_node->n)
			temp_node = temp_node->left;
		else if (value > temp_node->n)
			temp_node = temp_node->right;
		else if (value == temp_node->n)
			return (NULL);
	}

	new_node = binary_tree_node(NULL, value);

	if (next == NULL)
		next = new_node;

	else if (value < next->n)
	{
		next->left = new_node;
		new_node->parent = next;
	}

	else
	{
		next->right = new_node;
		new_node->parent = next;
	}
	return (new_node);
}
