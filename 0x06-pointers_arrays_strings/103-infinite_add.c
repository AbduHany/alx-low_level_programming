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
	int i = 0, j = 0, l = 0, len1 = 0;
	int len2 = 0, len3 = 0, carry = 0, d1 = 0, d2 = 0, sum = 0;

	for (i = 0; n1[i] != '\0'; i++)
		len1++;
	for (i = 0; n2[i] != '\0'; i++)
		len2++;
	if (len1 > size_r || len2 > size_r)
		return (0);
	rev_str(n1);
	rev_str(n2);
	i = 0;
	j = 0;
	l = 0;
	carry = 0;
	while (i < len1 || j < len2)
	{
		d1 = i < len1 ? n1[i] - '0' : 0;
		d2 = j < len2 ? n2[j] - '0' : 0;
		if (sum + carry > 9)
		{
			carry++;
			sum = 0;
		}
		sum = d1 + d2 + carry;
		r[l] = (sum % 10) + '0';
		carry = sum / 10;
		i++;
		j++;
		l++;
	}
	if (carry == 1)
	{
		r[l] = '1';
		r[l + 1] = '\0';
		len3 = l + 1;
	}
	else
	{
		r[l] = '\0';
		len3 = l;
	}
	if (len3 > size_r)
	{
		return (0);
	}
	return (r);
}
