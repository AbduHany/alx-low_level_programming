#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins to make change
 * for an amount of money.
 * @argc: number of arguments.
 * @argv: array of argument strings.
 *
 * Return: 0 if successful
 */
int main(int argc, char **argv)
{
	int cents, quarter, dime, nickel, penny, twocent;

	quarter = dime = nickel = penny = twocent = 0;
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	cents = atoi(argv[1]);
	if (cents < 0)
	{
		printf("0\n");
		return (1);
	}
	for (; cents >= 25; cents -= 25)
		quarter++;
	for (; cents >= 10; cents -= 10)
		dime++;
	for (; cents >= 5; cents -= 5)
		nickel++;
	for (; cents >= 2; cents -= 2)
		twocent++;
	for (; cents > 0; cents--)
		penny++;
	printf("%d\n", quarter + dime + nickel + twocent + penny);
	return (0);
}
