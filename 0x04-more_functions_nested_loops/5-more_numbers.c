#include "main.h"

/**
 * more_numbers -  prints 10 times the numbers, from 0 to 14.
 *
 * Return: void.
 */
void more_numbers(void)
{
	int i, j;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (i == 1 && j > 4)
			{
				break;
			}
			else if (i == 1)
			{
				_putchar('1');
			}
			_putchar(j + '0');
		}
	}
	_putchar('\n');
}
