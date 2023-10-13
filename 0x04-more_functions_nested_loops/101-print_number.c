#include "main.h"

/**
 * print_number - prints an integer using _putchar().
 * @n: integer to be printed.
 *
 * Return: void.
 */
void print_number(int n)
{
	unsigned int number = n;

	if (number < 0)
	{
		_putchar('-');
		number = -number;
	}
	if (number == 0)
	{
		_putchar('0');
		return;
	}
	if (number / 10)
	{
		print_number(number / 10);
	}
	_putchar((number % 10) + '0');
}

