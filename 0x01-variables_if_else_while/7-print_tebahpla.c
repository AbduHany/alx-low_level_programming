#include <stdio.h>

/**
 * main - function prints alphabets in reverse.
 *
 * Return: returns 0 if successful.
 */
int main(void)
{
	char a;

	for (a = 'z'; a >= 'a'; a--)
	{
		putchar(a);
	}
	putchar('\n');
	return (0);
}
