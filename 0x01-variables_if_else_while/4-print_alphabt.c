#include <stdio.h>

/**
 * main - function prints all alphabets except letters q & e.
 *
 * Return: 0 if successful.
 */
int main(void)
{
	char a;

	a = 'a';
	while (a <= 'z')
	{
		if (a == 'q' || a == 'e')
		{
			a++;
			continue;
		}
		putchar(a);
		a++;
	}
	putchar('\n');
	return (0);
}
