#include <stdio.h>

/**
 * main - function prints all possible different
 * combination of  3 digits
 *
 * Return: returns 0 if successful
 */
int main(void)
{
	int a, b, c;

	for (a = 48; a < 58; a++)
	{
		for (b = 48; b < 58; b++)
		{
			for (c = 48; c < 58; c++)
			{
				if (a == b || a == c || b == c)
				{
					continue;
				}
				if (c < b || b < a)
				{
					continue;
				}
				putchar(a);
				putchar(b);
				putchar(c);
				if (!(a == 55 && b == 56 && c == 57))
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
