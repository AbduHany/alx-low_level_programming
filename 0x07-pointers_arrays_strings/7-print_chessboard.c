#include "main.h"

/**
 * print_chessboard - prints the chessboard.
 * @a: a pointer to an [8][8] array.
 *
 * Return: void.
 */
void print_chessboard(char (*a)[8])
{
	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			_putchar(a[i][j]);
			if ((j % 7) == 0 && j != 0)
			{
				_putchar('\n');
			}
		}
	}
}
