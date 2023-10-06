#include <stdio.h>

/**
 * main - function prints all numbers of base 16.
 *
 * Return: returns 0 if successful.
 */
int main(void)
{
	char a;

	for (a = 48; a < 58; a++)
	{
		putchar(a);
	}
	for (a = 97; a < 103; a++)
	{
		putchar(a);
	}
	putchar('\n');
	return (0);
}
