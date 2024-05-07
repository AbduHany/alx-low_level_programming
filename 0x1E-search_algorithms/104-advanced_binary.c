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

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i != high)
			printf(", ");
	}
	printf("\n");
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

	print_arr(array, low, high);

	if (low >= high)
	{
		if (value == array[low])
			return (low);
		else
			return (-1);
	}
	mid = (low + high) / 2;
	if (array[mid] == value)
	{
		if (array[mid - 1] == array[mid])
			return (bin_recur(array, low, mid, value));
		else
			return (mid);
	}
	else if (value > array[mid])
		return (bin_recur(array, mid + 1, high, value));
	else
		return (bin_recur(array, low, mid, value));
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

	if (array == NULL || size == 0)
		return (-1);
	return (bin_recur(array, 0, size - 1, value));
}
