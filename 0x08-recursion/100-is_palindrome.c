#include "main.h"

/**
 * test - tests if string characters at end and start are alike.
 * @start: string pointer to be tested
 * @end: string length.
 * @max: number of tests.
 * Return: 1 is all characters match.
 * 0 if otherwise.
 */
int test(char *start, char *end, int max)
{
	if (max == 0)
	{
		return (1);
	}
	else if (*(start) != *(end))
	{
		return (0);
	}
	return (test(start + 1, end - 1, max - 1));
}
/**
 * is_palindrome -  returns 1 if a string is a palindrome and 0 if not.
 * @s: pointer to string to be tested.
 *
 * Return: 1 if string is palindrome
 * 0 if otherwise.
 */
int is_palindrome(char *s)
{
	int len, i, max;
	char *end;

	len = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		len++;
		i++;
	}
	if (len == 0)
	{
		return (1);
	}
	end = &(s[len - 1]);
	max = len / 2;
	return (test(s, end, max));
}
