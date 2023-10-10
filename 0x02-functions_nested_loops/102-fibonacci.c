#include <stdio.h>

/**
 * main - entry point
 *
 * Description: program prints first 50 fibonacci numbers.
 * Return: 0 if successful
 */
int main(void)
{
	unsigned int i, n1, n2, n3;

	n1 = 0;
	n2 = 1;
	printf("1, ");
	for (i = 1; i < 50; i++)
	{
		n3 = n1 + n2;
		printf("%u, ", n3);
		n1 = n2;
		n2 = n3;
	}
	printf("\n");
	return (0);
}
