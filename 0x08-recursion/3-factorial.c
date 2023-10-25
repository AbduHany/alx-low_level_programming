#include "main.h"

/**
 * factorial - returns the factorial of a given number.
 * @n: number whose factorial will be calculated.
 *
 * Return: int value to factorial of n.
 */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0)
	{
		return (1);
	}
	return (n * factorial(n - 1));
}
