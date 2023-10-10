#include "main.h"
#include <stdlib.h>

/**
 * print_last_digit - prints the last digit of a number.
 * @a: the number whose last digit is being printed.
 *
 * Return: the value of the last digit.
 */
int print_last_digit(int n)
{
	n = abs(n);
	_putchar((n % 10) + '0');
	return (n % 10);
}
