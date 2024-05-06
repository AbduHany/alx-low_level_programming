#include "search_algos.h"
#include "stdlib.h"

/**
 * interpolation_search - searches for a value in a sorted array of
 * integers using the Interpolation search algorithm
 * @array: array of integers being searched.
 * @size: size of the array being searched.
 * @value: target value being searched.
 *
 * Return: the first index where value is located,
 * -1 if array is NULL or value not found.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low, high, pos;

	if (array == NULL)
		return (-1);
	low = 0;
	high = size - 1;
	while (low <= high)
	{
		pos = (low + (((double)(high - low) / (array[high] - array[low])) *
			      (value - array[low])));
		if (pos >= size)
		{
			printf("Value checked array[%ld] is out of range\n", pos);
			break;
		}
		else
			printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
			return (pos);
		if (value > array[pos])
			low = pos + 1;
		else if (value < array[pos])
			high = pos - 1;
	}
	return (-1);
}
