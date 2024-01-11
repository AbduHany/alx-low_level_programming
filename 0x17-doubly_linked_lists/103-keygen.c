#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * main - keygen for the crackme5 executable.
 * @argc: number of arguments.
 * @argv: pointer to argument strings.
 *
 * Return: 0 if successful.
 */
int main(int argc, char **argv)
{
	char *username, key[7], *ref;
	int len, i, x;

	(void)argc;
	username = argv[1];
	len = strlen(username);
	ref = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	key[0] = *(((len ^ 0x3b) & 0x3f) + ref);
	for (i = 0, x = 0; i < len; i++)
		x += username[i];
	key[1] = *(((x ^ 0x4f) & 0x3f) + ref);
	for (i = 0, x = 1; i < len; i++)
		x *= username[i];
	key[2] = *(((x ^ 0x55) & 0x3f) + ref);
	for (x = username[0], i = 0; i < len; i++)
	{
		if (username[i] > x)
			x = username[i];
	}
	srand(x ^ 0xe);
	key[3] = *((rand() & 0x3f) + ref);
	for (x = 0, i = 0; i < len; i++)
		x = (x + (username[i] * username[i]));
	key[4] = *(((x ^ 0xef) & 0x3f) + ref);
	for (x = 0, i = 0; i < username[0]; i++)
		x = rand();
	key[5] = *(((x ^ 0xe5) & 0x3f) + ref);
	key[6] = '\0';
	printf("%s", key);
	return (0);
}
