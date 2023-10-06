#include <stdio.h>

/**
 * main - function prints all single digit number separated by ", "
 *
 * Return: returns 0 if successful.
 */
int main(void)
{
	int a;

	for (a = 48; a <= 57; a++)
	{
		putchar(a);
		if (a < 57)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
