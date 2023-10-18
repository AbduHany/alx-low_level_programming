#include "main.h"

/**
 * _strncpy - copies n bytes of a string.
 * @dest: pointer to destination string.
 * @src: pointer to source string.
 * @n: number of bytes to be copied.
 *
 * Return: pointer to copied string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, len;

	len = 0;
	i = 0;
	while (src[i] != '\0')
	{
		len++;
		i++;
	}
	for (i = 0; dest[i] != '\0' && i < n; i++)
	{
		if (i < len)
		{
			dest[i] = src[i];
		}
		else
		{
			dest[i] = '\0';
		}
	}
	return (dest);
}
