#include <stdio.h>
#include "main.h"

/**
 * print_array - prints n elements of an array of integers.
 * @a: pointer to the array to be printed.
 * @n: number of elements to be printed.
 *
 * Return: void.
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < (n - 2); i++)
	{
		printf("%d, ", a[i]);
	}
	printf("%d\n", a[n-1]);
}
