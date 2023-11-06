#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers.
 * @min: minimum range of numbers to be included in array
 * @max: maximum range of numbers to be included in array
 *
 * Return: pointer to created int array.
 */
int *array_range(int min, int max)
{
	int num, i, j;
	int *p;

	if (min > max)
		return (NULL);
	num = (max - min) + 1;
	p = malloc(num * sizeof(int));
	if (p == NULL)
		return (NULL);
	for (i = 0, j = min; i < num && j <= max; i++, j++)
	{
		p[i] = j;
	}
	return (p);
}
