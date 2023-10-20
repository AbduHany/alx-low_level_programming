#include "main.h"

/**
 * rev_str - reverses a string
 * @s: pointer to string to be reversed
 *
 * Return: void.
 */
void rev_str(char *s)
{
	int i, len;
	char temp;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		len++;
		i++;
	}
	for (i = 0; i < (len / 2); i++)
	{
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}
/**
 * infinite_add - adds two numbers.
 * @n1: pointer to first integer string.
 * @n2: pointer to second integer string.
 * @r:  buffer to store the result.
 * @size_r: buffer size.
 *
 * Return: pointer to result string.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, l, len1, len2, carry, d1, d2, sum;

	len1 = len2 = 0;
	for (i = 0; n1[i] != '\0'; i++)
		len1++;
	for (i = 0; n2[i] != '\0'; i++)
		len2++;
	if (len1 >= size_r || len2 >= size_r)
		return (0);
	carry = 0;
	for (i = len1 - 1, j = len2 - 1, l = 0;
	i >= 0 || j >= 0 || carry == 1; i--, j--, l++)
	{
		d1 = i < 0 ? 0 : n1[i] - '0';
		d2 = j < 0 ? 0 : n2[j] - '0';
		sum = d1 + d2 + carry;
		if (l >= (size_r - 1))
			return (0);
		r[l] = (sum % 10) + '0';
		carry = sum / 10;
	}
	l--;
	if (l == size_r)
		return (0);
	r[l] = '\0';
	rev_str(r);
	return (r);
}
