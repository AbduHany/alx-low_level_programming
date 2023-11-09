#include <stdarg.h>
#include <stdio.h>
/**
 * my_print - prints optional argument
 * @c: specifier character.
 * @a: va_list variable.
 *
 * Return: void
 */
void my_print(char c, va_list a)
{
	if (c == 'c')
		printf("%c", va_arg(a, int));
	else if (c == 'i')
		printf("%d", va_arg(a, int));
	else if (c == 'f')
		printf("%f", va_arg(a, double));
	else if (c == 's')
	{
		char *tmp;

		tmp = va_arg(a, char *);
		if (tmp == NULL)
			printf("(nil)");
		else
			printf("%s", tmp);
	}
}

/**
 * print_all - prints anything.
 * @format: list of types of arguments passed to the function
 *
 * Return: void.
 */
void print_all(const char * const format, ...)
{
	int i;
	va_list a;

	va_start(a, format);
	i = 0;
	while (format[i] != '\0' && i < 9)
	{
		while (format[i] == 'c' || format[i] == 'i'
		|| format[i] == 'f' || format[i] == 's')
		{
			my_print(format[i], a);
			if (format[i + 1] != '\0')
				printf(", ");
			i++;
		}
		i++;
	}
	printf("\n");
	va_end(a);
}
