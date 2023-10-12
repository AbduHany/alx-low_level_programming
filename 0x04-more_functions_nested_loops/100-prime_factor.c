#include <stdio.h>

/**
 * main - finds and prints the largest prime factor of the number 612852475143.
 *
 * Return: 0 if successful.
 */
int main(void)
{
	long int i, num, largest;

	num = 612852475143;
	largest = 0;
	for (i = 1; i < num; i++)
	{
		if ((num % i) == 0)
		{
			if (i > largest)
			{
				largest = i;
			}
			num = num / i;
		}
	}
	largest = num;
	printf("%ld\n", largest);
	return (0);
}
