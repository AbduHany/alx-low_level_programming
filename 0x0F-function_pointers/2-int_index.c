#include <stdlib.h>

/**
 * int_index - searches for an integer.
 * @array: pointer to array to search in.
 * @size: size of array.
 * @cmp: pointer to function used in comparison.
 *
 * Return: index of first element where cmp doesn't
 * return 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
