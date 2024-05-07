#include "search_algos.h"

/**
 * print_arr - prints an array.
 * @array: array of ints to be printed.
 * @low: beginning index of the array.
 * @high: ending index of the array.
 *
 * Return: void.
 */
void print_arr(int *array, size_t low, size_t high)
{
	size_t i;

	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i != high)
			printf(", ");
	}
}

/**
 * bin_search - searches for a value in a sorted array of
 * integers using the Binary search algorithm
 * @array: array of integers to be searched.
 * @low: low bound of array being searched.
 * @high: high bound of array being searched.
 * @value: value that's being searched for.
 *
 * Return: index of the value if found
 * if not found or array is NULL, returns -1.
 */
int bin_search(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (array == NULL)
		return (-1);
	while (low <= high)
	{
		printf("Searching in array: ");
		print_arr(array, low, high);
		printf("\n");
		mid = (low + high) / 2;
		if (array[mid] == value)
			return (mid);
		else if (value > array[mid])
			low = mid + 1;
		else if (value < array[mid])
			high = mid - 1;
	}
	return (-1);
}

/**
 * exponential_search - searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: array on integers being searched.
 * @size: size of the array being searched.
 * @value: target value being searched for in array.
 *
 * Return: the first index where value is located,
 * -1 if array is NULL or value isn't found.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i, low, high;

	if (array == NULL)
		return (-1);
	i = 1;
	while (array[i] < value && i < size)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		i *= 2;
	}
	low = i / 2;
	high = i < size - 1 ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", low, high);
	return (bin_search(array, low, high, value));
}
