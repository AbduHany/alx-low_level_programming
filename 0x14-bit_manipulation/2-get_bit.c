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
	unsigned int bitlength = 0, temp_num;
	int bitval;

	temp_num = n;
	while ((temp_num >> 1) != 0)
	{
		bitlength++;
		temp_num = temp_num >> 1;
	}
	if (index > bitlength)
		return (-1);
	bitval = (n >> index) & 1;
	return (bitval);
}
