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
	int cents, quarter, dime, nickel, penny;

	quarter = dime = nickel = penny = 0;
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
	while (cents >= 25)
	{
		quarter++;
		cents -= 25;
	}
	while (cents >= 10)
	{
		dime++;
		cents -= 10;
	}
	while (cents >= 5)
	{
		nickel++;
		cents -= 5;
	}
	while (cents > 0)
	{
		penny++;
		cents -= 1;
	}
	printf("%d\n", quarter + dime + nickel + penny);
	return (0);
}
