#include <stdio.h>

/**
 * main - entry point
 *
 * Description: program prints first 50 fibonacci numbers.
 * Return: 0 if successful
 */
int main(void)
{
	unsigned __int128 n1
	unsigned __int128 n2;
	unsigned __int128 n3;
	int i;

	n1 = 0;
	n2 = 1;
	for (i = 1; i < 98; i++)
	{
		n3 = n1 + n2;
		printf("%llu, ", n3);
		n1 = n2;
		n2 = n3;
	}
	printf("%llu\n", n1 + n2);
	return (0);
}
