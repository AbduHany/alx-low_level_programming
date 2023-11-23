#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip to get
 * from one number to another.
 * @n: first number to compare.
 * @m: second number to compare.
 *
 * Return: number of flips to be done.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int a, b, i;
	unsigned int flips = 0;

	for (i = 63; i >= 0; i--)
	{
		a = (n >> i) & 1;
		b = (m >> i) & 1;

		if (a ^ b)
		{
			flips++;
		}
	}
	return (flips);
}
