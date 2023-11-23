#include "main.h"

/**
 * get_bit -  returns the value of a bit at a given index.
 * @n: number to get bit value from.
 * @index: index where bit value is to be obtained from n.
 *
 * Return: returns the value of the bit, 0 or 1.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bitval;

	bitval = (n >> index) & 1;
	if (bitval != 0 || bitval != 1)
		return (-1);
	return (bitval);
}
