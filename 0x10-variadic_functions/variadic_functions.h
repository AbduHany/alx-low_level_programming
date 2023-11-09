#ifndef VARIADIC_FUN_H
#define VARIADIC_FUN_H
#include <stdarg.h>
/**
 * struct helper - struct containg char and func to be
 * used in printing
 * @c: type of argument (specifier)
 * @fun: function pointer to be called to print.
 */
typedef struct helper
{
	char c;
	void (*fun)(va_list a);
} helper;

int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
