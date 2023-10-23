#include "main.h"
#include <stdio.h>

/**
 * print_diagsums -  prints the sum of the two diagonals
 * of a square matrix of integers.
 * @a: pointer to 2D array.
 * @size: size of square array.
 *
 * Return: void.
 */
void print_diagsums(int *a, int size)
{
	int i, j, d1, d2;

	d1 = 0;
	d2 = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i == j)
			{
				d1 += *(a + (i * size) + j);
			}
			if ((i + j) == (size - 1))
			{
				d2 += *(a + (i * size) + j);
			}
		}
	}
	printf("%d, %d\n", d1, d2);
}
