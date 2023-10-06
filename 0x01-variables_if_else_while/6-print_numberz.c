#include <stdio.h>

/**
 * main - function prints single digits 0-9 using putchar.
 *
 * Return: returns 0 if successful.
 */
int main(void)
{
	int a;

	for (a = 48; a < 58; a++)
	{
		putchar(a);
	}
	putchar('\n');
	return (0);
}
