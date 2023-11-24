#include "main.h"

/**
 * get_endianness - checks the endianness.
 * Return: 1 if little endian and
 * 0 if big endian.
 */
int get_endianness(void)
{
	char *y;
	int x;

	x = 1;
	y = (char *)&x;
	return ((int)*y);
}
