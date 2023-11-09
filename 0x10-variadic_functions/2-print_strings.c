#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - prints strings, followed by a new line.
 * @separator: string to be printed between the strings
 * @n: number of strings passed to the function.
 *
 * Return: void.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *tmp;
	va_list a;

	va_start(a, n);
	for (i = 0; i < n; i++)
	{
		tmp = (char *) va_arg(a, char *);
		if (tmp == NULL)
			printf("(nil)");
		else
			printf("%s", tmp);
		if (separator != NULL && i != (n - 1))
			printf("%s", separator);
	}
	printf("\n");
	va_end(a);
}
