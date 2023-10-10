#include <stdio.h>

/**
 * main - entry point
 *
 * Description: program prints first 50 fibonacci numbers.
 * Return: 0 if successful
 */
int main(void)
{
	unsigned long int i, n1, n2, n3;

	n1 = 0;
	n2 = 1;
	for (i = 1; i < 98; i++)
	{
		n3 = n1 + n2;
		printf("%lu, ", n3);
		n1 = n2;
		n2 = n3;
	}
	printf("%lu\n", n1 + n2);
	return (0);
}
