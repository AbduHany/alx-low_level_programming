#include "main.h"

/**
 * read_textfile -  reads a text file and prints it to the POSIX standard output.
 * @filename: string of the filename to be read from.
 * @letters: number of letters to be read and printed.
 *
 * Return: the actual number of letters it could read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t read_letters;
	char *buffer;

	if (filename == NULL)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	read(fd, buffer, letters);
	read_letters = write(STDOUT_FILENO, buffer, letters);
	if (read_letters < 0)
		return (0);
	return (read_letters);
}
