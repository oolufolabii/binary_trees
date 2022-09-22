#include "binary_trees.h"

/**
 * @brief 
 * 
 * @param array 
 * @param size 
 * @return avl_t* 
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int i;
	avl_t *root = NULL;

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
	
}
