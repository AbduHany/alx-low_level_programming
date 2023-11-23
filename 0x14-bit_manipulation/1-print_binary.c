#include "main.h"

/**
 * print_binary -  prints the binary representation of a number.
 * @n: number to be printed in binary.
 *
 * Return: void.
 */
void print_binary(unsigned long int n)
{
	unsigned long int divisor = 1, temp_num;

	if (n == 0 || n > 4294967295)
	{
		_putchar('0');
		return;
	}
	temp_num = n;
	while (temp_num != 0)
	{
		divisor = divisor << 1;
		temp_num = temp_num >> 1;
	}
	if ((n & divisor) == 0)
		divisor = divisor >> 1;
	while (divisor != 0)
	{
		if (n & divisor)
		{
			_putchar('1');
			divisor = divisor >> 1;
		}
		else
		{
			_putchar('0');
			divisor = divisor >> 1;
		}
	}
}
