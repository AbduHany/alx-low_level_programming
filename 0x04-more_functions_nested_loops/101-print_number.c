#include "main.h"

/**
 * print_number - prints an integer using _putchar().
 * @n: integer to be printed.
 *
 * Return: void.
 */
void print_number(int n)
{
	int i, dig_count, temp_num, temp_dig, temp_div;

	temp_num = n;
	dig_count = 0;
	while (temp_num != 0)
	{
		temp_num /= 10;
		dig_count++;
	}
	if (n < 0)
	{
		_putchar('-');
		n *= -1;
	}
	if (n == 0)
		_putchar('0');
	temp_div = 1;
	for (i = 1; i < dig_count; i++)
		temp_div *= 10;
	temp_num = n;
	for (i = 1; i <= dig_count; i++)
	{
		temp_dig = temp_num / temp_div;
		_putchar(temp_dig + '0');
		temp_num = temp_num % temp_div;
		temp_div /= 10;
	}
}
