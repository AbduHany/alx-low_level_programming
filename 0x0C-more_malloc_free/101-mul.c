#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * revstr - reverses a string.
 * @str: a pointer to the string.
 *
 * Return: a pointer to the reserved string.
 */
void revstr(char *str)
{
	int i, len;
	char tmp;

	for (i = 0, len = 0; str[i] != '\0'; i++)
		len++;
	for (i = 0; i < (len / 2); i++)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
}

/**
 * mul - multiplies 2 digit strings and adds
 * result to third string.
 * @res: pointer to result of multiplication string.
 * @s1: pointer to first string to be multiplied.
 * @s2: pointer to second string to be multiplied.
 * @len1: length of first digit string.
 * @len2: length of second digit string.
 *
 * Return: void
 */
void mul(int *res, char *s1, char *s2, int len1, int len2)
{
	int i, j, digit;

	for (i = 0; i < len1; i++)
	{
		for (j = 0; j < len2; j++)
		{
			digit = (s1[i] - '0') * (s2[j] - '0');
			res[i + j] += digit;
			res[i + j + 1] += res[i + j] / 10;
			res[i + j] = res[i + j] % 10;
		}
	}
}

/**
 * checklen - counts the length of the string and checks if its only digits.
 * @s: pointer to the string that it checks.
 *
 * Return: returns the int value of the length of the number string.
 */
int checklen(char *s)
{
	int i, len;

	for (i = 0, len = 0; s[i] != '\0'; i++)
	{
		if (!(s[i] >= 48 && s[i] <= 57))
		{
			printf("Error\n");
			exit(98);
		}
		else
			len++;
	}
	return (len);
}
/**
 * main - program that multiplies 2 positive numbers.
 * @argc: number of arguments.
 * @argv: pointer to argument strings.
 *
 * Return: 0 if successful
 * 98 if there's an error.
 */
int main(int argc, char **argv)
{
	int i, len1, len2;
	int *res;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	len1 = checklen(argv[1]);
	len2 = checklen(argv[2]);
	if ((atoi(argv[1]) == 0) || (atoi(argv[2]) == 0))
	{
		printf("0\n");
		return (0);
	}
	revstr(argv[1]);
	revstr(argv[2]);
	res = calloc(len1 + len2, sizeof(int));
	if (res == NULL)
	{
		printf("Error\n");
		exit(98);
	}
	mul(res, argv[1], argv[2], len1, len2);
	i = len1 + len2 - 1;
	while (res[i] == 0 && i >= 0)
		i--;
	for (; i >= 0; i--)
	{
		if (res[i] >= 10)
		{
			_putchar((res[i] / 10) + '0');
			_putchar((res[i] % 10) + '0');
		}
		else
			_putchar(res[i] + '0');
	}
	_putchar('\n');
	free(res);
	return (0);
}
