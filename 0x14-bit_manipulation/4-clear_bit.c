#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 * @n: pointer to int whose bit value is to be changed to 0.
 * @index: index of bit to be changed to 0.
 *
 * Return: 1 if successful, -1 if error.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int temp_num;

	if (index > 64)
		return (-1);
	if ((((*n) >> index) & 1) == 0)
		return (1);
	temp_num = 1 << index;
	*n = temp_num ^ (*n);
	return (1);

}
