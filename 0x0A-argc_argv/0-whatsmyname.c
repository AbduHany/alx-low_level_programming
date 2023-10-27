#include <stdio.h>

/**
 * main - prints its name, followed by a new line.
 * @argc: number of arguments.
 * @argv: array to argument strings.
 *
 * Return: 0 if successful.
 */
int main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", argv[0]);
	return (0);
}
