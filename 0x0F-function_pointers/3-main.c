#include "3-calc.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * main - entry point
 * @argc: number of arguments.
 * @argv: pointer to argument strings.
 * Return: returns 0 if successful
 * 98 if number of arguments is wrong
 * 99 if operator is none of the used operators.
 * 100 if user divides by 0.
 */
int main(int argc, char **argv)
{
	int num1, num2, result;
	int (*ptr)(int a, int b);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	if (strlen(argv[2]) != 1 || (argv[2][0] != '+' && argv[2][0] != '-'
	&& argv[2][0] != '*' && argv[2][0] != '/' && argv[2][0] != '%'))
	{
		printf("Error\n");
		exit(99);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	if (num2 == 0 && (argv[2][0] == '/' || argv[2][0] == '%'))
	{
		printf("Error\n");
		exit(100);
	}
	ptr = get_op_func(argv[2]);
	result = ptr(num1, num2);
	printf("%d\n", result);
	return (0);
}
