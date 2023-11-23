#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index.
 * @n: pointer to the unsigned long int to be changed.
 * @index: index where bit to be changed to 1.
 *
 * Return: 1 if successful, -1 if failed.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int temp_num;

	if (index > 64)
		return (-1);
	temp_num = 1 << index;
	*n = temp_num | (*n);
	return (1);
}
