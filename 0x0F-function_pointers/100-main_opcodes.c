#include <stdlib.h>
#include <stdio.h>

/**
 * main - entry point
 * @argc: number of arguments.
 * @argv: pointer to argument strings.
 *
 * Return: 0 if successful
 * 1 or 2 if error.
 */
int main(int argc, char **argv)
{
	int i, byte_num;
	unsigned char *ptr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	byte_num = atoi(argv[1]);
	if (byte_num < 0)
	{
		printf("Error\n");
		exit(2);
	}
	ptr = (unsigned char *) main;
	for (i = 0; i < byte_num; i++)
	{
		printf("%02x ", ptr[i]);
	}
	printf("\n");
	return (0);
}
