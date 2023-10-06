#include <stdio.h>

/**
 * main - function prints the alphabet in lowercase.
 *
 * Return: 0 if successful
 */
int main(void)
{
	char a;

	a = 'a';
	while (a <= 'z')
	{
		putchar(a);
		a++;
	}
	putchar('\n');
	return (0);
}
