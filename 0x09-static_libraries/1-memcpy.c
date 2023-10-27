#include "main.h"

/**
 * _memcpy -  copies memory area.
 * @dest: pointer of destination to copy to.
 * @src: pointer of source to copy from.
 * @n: number of bytes to be copied.
 *
 * Return: pointer to copied memory location.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest + i) = *(src + i);
	}
	return (dest);
}
