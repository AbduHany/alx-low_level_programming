#include <stdio.h>

/**
 * main - function prints all single digit numbers of base 10.
 *
 * Return: returns 0 if successful.
 */
int main(void)
{
	int a;

	for (a = 0; a < 10; a++)
	{
		printf("%d", a);
	}
	putchar('\n');
	return (0);
}
