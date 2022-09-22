#include "binary_trees.h"

/**
 * avl_func - builds an AVL tree from an array
 * @root: double pointer to the root node of the subtree
 * @array: a pointer to the first element of the array to be converted
 * @low_end: lower bound index
 * @high_end: upper bound index
 */
void avl_func(avl_t **root, int *array, size_t low_end, size_t high_end)
{
	avl_t *new = NULL;
	size_t mid_point;

	if (high_end - low_end > 1)
	{
		mid_point = (high_end - low_end) / 2 + low_end;
		new = binary_tree_node(*root, array[mid_point]);
		if (array[mid_point] > (*root)->n)
			(*root)->right = new;
		else if (array[mid_point] < (*root)->n)
			(*root)->left = new;
		avl_func(&new, array, low_end, mid_point);
		avl_func(&new, array, mid_point, high_end);
	}
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t middle;

	if (!array)
		return (NULL);
	middle = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[middle]);

	avl_func(&tree, array, -1, middle);
	avl_func(&tree, array, middle, size);

	return (tree);
}
