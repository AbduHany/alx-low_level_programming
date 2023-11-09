#include <stdarg.h>

/**
 * sum_them_all - returns sum of all its parameters.
 * @n: number of arguments passed to function.
 *
 * Return: value of sum of the arguments.
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i, sum;
	va_list a;

	if (n == 0)
		return (0);
	va_start(a, n);
	for (i = 0, sum = 0; i < n; i++)
	{
		sum = sum + va_arg(a, int);
	}
	va_end(a);
	return (sum);
}
