#include "main.h"

/**
 * _strncat - concatenates number of bytes of string to another string.
 * @dest: pointer to destination string.
 * @src: pointer to source string.
 * @n: number of bytes to be concatenated.
 *
 * Return: pointer to concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, dest_len;

	i = 0;
	dest_len = 0;
	while (dest[i] != '\0')
	{
		dest_len++;
		i++;
	}
	for (i = 0; src[i] != '\0' && i < n; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
