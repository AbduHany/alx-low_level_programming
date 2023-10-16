#include "main.h"

/**
 * swap_int - swaps the values of two integers.
 * @a: pointer to first variable to be swapped.
 * @b: pointer to second variable to be swapped.
 *
 * Return: Void.
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
