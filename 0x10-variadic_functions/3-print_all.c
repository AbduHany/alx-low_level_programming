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
	char d;

	d = va_arg(a, int);
	printf("%c", d);
}
/**
 * print_i - prints integers
 * @a: va_list variable.
 *
 * Return: void
 */
void print_i(va_list a)
{
	int d;

	d = va_arg(a, int);
	printf("%d", d);
}
/**
 * print_f - prints floats
 * @a: va_list variable.
 *
 * Return: void
 */
void print_f(va_list a)
{
	float d;

	d = va_arg(a, double);
	printf("%f", d);
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
	if (!tmp)
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
	void (*tmp)(va_list a);
	helper b[] = {
		{'c', print_c},
		{'i', print_i},
		{'f', print_f},
		{'s', print_s},
		{'\0', NULL}
	};
	char *d = "";

	va_start(a, format);
	i = 0;
	while (format[i] && format)
	{
		j = 0;
		while (b[j].c != '\0')
		{
			if (format[i] == b[j].c)
			{
				printf("%s", d);
				tmp = b[j].fun;
				tmp(a);
				d = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(a);
}
