#include "main.h"
#include <stdio.h>

/**
 * print_times_table - prints a number times table, starting with 0.
 * @n: the number whose time table will be printed.
 * Return: void.
 */
void print_times_table(int n)
{
	int i, j, k;

	if (n < 15 && n > 0)
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				k = i * j;
				if (j == 0)
				{
					printf("%d", k);
				}
				else if (k < 10 && j != 0)
				{
					printf(",   %d", k);
				}
				else if (k >= 10 && k < 100)
				{
					printf(",  %d", k);
				}
				else if (k >= 100)
				{
					printf(", %d", k);
				}
			}
			printf("\n");
		}
	}
	else if (n == 0)
		printf("0\n");
}
