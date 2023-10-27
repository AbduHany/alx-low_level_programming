#include <stdio.h>

/**
 * main - prints the number of arguments passed into it.
 * @argc: number of arguments
 * @argv: array of argument strings.
 *
 * Return: 0 if successful.
 */
int main(int argc, char __attribute__ ((unused)) **argv)
{
	printf("%d\n", argc - 1);
	return (0);
}
