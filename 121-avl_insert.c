#include "binary_trees.h"

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

/**
 * avl_insert - function that inserts a value in an AVL Tree
 *
 * @tree: double pointer to the root node of the AVL tree for inserting the value
 * @value: value to store in the node to be inserted
 * Return: return a pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance = 0;
	avl_t *node = bst_insert(tree, value);

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < node->left->n)
		return (binary_tree_rotate_right(node));

	if (balance < -1 && value > node->right->n)
		return (binary_tree_rotate_left(node));

	if (balance > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}

	if (balance < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}

	return (node);
}
