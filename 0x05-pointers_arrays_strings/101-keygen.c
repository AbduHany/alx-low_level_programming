#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - program that generates random valid passwords for the program
 *
 * Return: 0 if successful.
 */
int main(void)
{
	int i, sum, random;

	srand(time(NULL));
	sum = 2772;
	for (i = 0; sum > 128; i++)
	{
		random = rand() % 128;
		printf("%c", random);
		sum = sum - random;
	}
	printf("%c", sum);
	return (0);
}
