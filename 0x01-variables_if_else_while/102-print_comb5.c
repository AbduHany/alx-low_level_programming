#include <stdio.h>

/**
 * main - function prints different combination of 4 digits.
 *
 * Return: returns 0 if successful.
 */
int main(void)
{
	int a, b, c, d;

	for (a = 48; a < 58; a++)
	{
		for (b = 48; b < 58; b++)
		{
			for (c = 48; c < 58; c++)
			{
				for (d = 48; d < 58; d++)
				{
					if (a == b && a == c && a == d && b == c && b == d && c == d)
						continue;
					else if ((a == c) && (b == d))
						continue;
					if ((c < a) || (d < b))
						continue;
					putchar(a);
					putchar(b);
					putchar(' ');
					putchar(c);
					putchar(d);
					if (!(a == 57 && b == 56 && c == 57 && d == 57))
					{
						putchar(',');
						putchar(' ');
					}
					else
						break;
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
