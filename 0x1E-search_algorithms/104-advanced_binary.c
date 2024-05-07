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
 * bin_recur - performs binary search in recursion.
 * @array: array being searched.
 * @low: the lower bound of array being searched.
 * @high: the higher bound of array being searched.
 * @value: the target value being searched.
 *
 * Return: index of the value in array, -1
 * if value not found.
 */
int bin_recur(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	mid = (low + high) / 2;
        if (array[mid] == value)
		return (mid);
	else if (value > array[mid])
		return (bin_recur(array, mid + 1, high, value));
	return (bin_recur(array, low, mid - 1, value));
}


/**
 * advanced_binary - searches for a value in a sorted array of integers.
 * @array: the array of integers to be searched.
 * @size: size of the array being searched.
 * @value: the target value being searched in array.
 *
 * Return: the index where value is located,
 * -1 if array is NULL or value isn't found.
 */
int advanced_binary(int *array, size_t size, int value)
{

	if (array == NULL)
		return (-1);
	return (bin_recur(array, 0, size - 1, value));
}
