#include <stdio.h>

/**
 * main - function prints all possible different
 * combination of values
 *
 * Return: returns 0 if successful
 */
int main(void)
{
	int a, b;

	for (a = 48; a < 58; a++)
	{
		for (b = 48; b < 58; b++)
		{
			if (a == b)
			{
				continue;
			}
			if (b < a)
			{
				continue;
			}
			putchar(a);
			putchar(b);
			if ( !(a == 56 && b == 57))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar ('\n');
	return (0);
}
