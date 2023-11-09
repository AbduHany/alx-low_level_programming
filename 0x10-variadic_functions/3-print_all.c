#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_c - prints characters
 * @a: va_list variable.
 *
 * Return: void
 */
void print_c(va_list a)
{
	printf("%c", va_arg(a, int));
}
/**
 * print_i - prints integers
 * @a: va_list variable.
 *
 * Return: void
 */
void print_i(va_list a)
{
	printf("%d", va_arg(a, int));
}
/**
 * print_f - prints floats
 * @a: va_list variable.
 *
 * Return: void
 */
void print_f(va_list a)
{
	printf("%f", va_arg(a, double));
}
/**
 * print_s - prints strings
 * @a: va_list variable.
 *
 * Return: void
 */
void print_s(va_list a)
{
	char *tmp;

	tmp = va_arg(a, char *);
	if (tmp == NULL)
	{
		tmp = "(nil)";
	}
	printf("%s", tmp);
}

/**
 * print_all - prints anything.
 * @format: list of types of arguments passed to the function
 *
 * Return: void.
 */
void print_all(const char * const format, ...)
{
	int i, j;
	va_list a;
	helper b[] = {
		{'c', print_c},
		{'i', print_i},
		{'f', print_f},
		{'s', print_s},
		{'\0', NULL}
	};
	char *e = "";

	va_start(a, format);
	i = 0;
	while (format[i] && format)
	{
		j = 0;
		while (b[j].c != '\0')
		{
			if (format[i] == b[j].c)
			{
				printf("%s", e);
				b[j].fun(a);
				e = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(a);
}
