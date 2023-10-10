#include <stdio.h>

/**
 * main - entry point
 *
 * Description: program prints first 50 fibonacci numbers.
 * Return: 0 if successful
 */
int main(void)
{
	unsigned long int i, n1, n2, n3, sum;

	n1 = 0;
	n2 = 1;
	sum = 0;
	for (i = 1; i < 50; i++)
	{
		if ((n1 + n2) < 4000000)
		{
			n3 = n1 + n2;
			if ((n3 % 2) == 0)
			{
				sum += n3;
			}
			n1 = n2;
			n2 = n3;
		}
	}
	printf("%lu\n", sum);
	return (0);
}
