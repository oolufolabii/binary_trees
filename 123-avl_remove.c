#include "binary_trees.h"

/**
 * bst_min_node - checks and returns the smallest node.
 * @root: a pointer to the root node of the tree
 * Return: a pointer to the smallest node
 */
bst_t *bst_min_node(bst_t *root)
{
	bst_t *min = root;

	while (min->left)
		min = min->left;

	return (min);
}

/**
 * avl_remove - function that removes a node from a AVL Tree
 *
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after
 * removing the desired value, otherwise NULL
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);

	else if (value > root->n)
		root->right = avl_remove(root->right, value);

	else
	{
		if (!root->left)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = bst_min_node(root->right);

		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}

	return (root);
}
