#include "main.h"

/**
 * _strstr - locates a substring in a string.
 * @haystack: pointer to string.
 * @needle: pointer to substring.
 *
 * Return: pointer to location of substring in string.
 */
char *_strstr(char *haystack, char *needle)
{
	int i;
	char *h, *n;

	for (i = 0; *(haystack + i) != '\0'; i++)
	{
		if (*(haystack + i) == *needle)
		{
			h = (haystack + i);
			n = needle;
			while ((*h == *n) && (*n != '\0'))
			{
				h++;
				n++;
			}
			if (*n == '\0')
			{
				return (haystack + i);
			}
		}
	}
	return (0);
}
