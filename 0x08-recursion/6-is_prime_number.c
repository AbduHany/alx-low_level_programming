#include "main.h"

/**
 * test - tests if number is divisable by multiple numbers
 * @n: number to be tested.
 * @m: test divisor.
 *
 * Return: returns 0 if divisible by tested number
 * otherwise returns 1.
 */
int test(int n, int m)
{
	if (n == m)
	{
		return (1);
	}
	else if ((n % m) == 0)
	{
		return (0);
	}
	return test(n, (m + 1));
}
/**
 * is_prime_number - checks if number is a prime number or not.
 * @n: number to be checked.
 *
 * Return: returns 1 if n is prime
 * otherwise 0.
 */
int is_prime_number(int n)
{
	if (n < 0)
	{
		n = -n;
	}
	if (n == 1)
	{
		return (0);
	}
	return (test(n, 2));
}
