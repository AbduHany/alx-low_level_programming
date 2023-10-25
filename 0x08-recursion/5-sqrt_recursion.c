#include "main.h"

/**
 * guessnum - guesses the number of square root of a number
 * @n: number to be tested
 * @m: guessed number.
 *
 * Return: return the guessed number that's equal to square root.
 */
int guessnum(int n, int m)
{
	if (m >= n)
	{
		return (-1);
	}
	else if ((m * m) % n == 0)
	{
		return (m);
	}
	return (guessnum(n, m + 1));
}
/**
 * _sqrt_recursion - returns natural square root of a number.
 * @n: number whose square root is to be calculated.
 *
 * Return: int value of square root of number.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 1)
	{
		return (1);
	}
	return (guessnum(n, 1));
}
