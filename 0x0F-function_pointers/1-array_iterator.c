#include <stdlib.h>

/**
 * array_iterator - executes a function given as a parameter
 * on each element of an array
 * @array: pointer to an array of ints.
 * @size: size of the array.
 * @action: pointer to function to be executed.
 *
 * Return: void.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	int i;

	if (array == NULL || action == NULL)
		return;
	else if (size <= 0)
		return;
	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
