#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: char pointer to binary string.
 *
 * Return: the converted binary to unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{
	char *cursor;
	unsigned int dec = 0, len = 0, mul = 1;
	int i;

	cursor = (char *)b;
	if (b == NULL)
		return (0);
	for (i = 0; cursor[i] != '\0'; i++) /* bin string length */
	{
		if (cursor[i] < 48 || cursor[i] > 49)
			return (0);
		len++;
	}
	for (i = (len - 1); i >= 0; i--)
	{
		if (cursor[i] == 49)
		{
			dec = dec + mul;
			mul = mul * 2;
		}
		else
			mul = mul * 2;
	}
	return (dec);
}
