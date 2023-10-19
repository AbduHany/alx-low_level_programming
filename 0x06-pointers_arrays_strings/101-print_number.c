#include "main.h"

/**
 * print_number - prints an integer.
 * @n: the integer to be printed.
 *
 * Return: Void.
 */
void print_number(int n)
{
	unsigned int num;

	num = n;
	if (n < 0)
	{
		_putchar('-');
		num *= -1;
	}
	if ((num / 10) != 0)
	{
		print_number(num / 10);
	}
	_putchar((num % 10) + '0');

}
