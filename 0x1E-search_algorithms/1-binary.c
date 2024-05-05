#include "search_algos.h"
#include <stdlib.h>

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
 * binary_search - searches for a value in a sorted array of
 * integers using the Binary search algorithm
 * @array: array of integers to be searched.
 * @size: size of the array being searched.
 * @value: value that's being searched for.
 *
 * Return: index of the value if found
 * if not found or array is NULL, returns -1.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t low, high, mid;

	if (array == NULL)
		return (-1);
	low = 0;
	high = size - 1;
	while ( low <= high)
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
