#include "binary_trees.h"

/**
 * array_to_bst -  builds a Binary Search Tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: return a pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int j;

	bst_t *root = NULL;

	for (j = 0; j < size; j++)
		bst_insert(&root, array[j]);

	return (root);
}
