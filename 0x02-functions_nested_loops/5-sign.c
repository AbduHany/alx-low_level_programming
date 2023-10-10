#include "main.h"

/**
 * print_sign - prints the sign of a number.
 * @n: the number whose sign is being printed.
 *
 * Return: return 1 if n is positive.
 * returns 0 if n is zero.
 * returns -1 if n is negative.
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}
