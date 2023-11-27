#include "main.h"

/**
 * read_textfile -  reads a text file and prints it to the
 * POSIX standard output.
 * @filename: string of the filename to be read from.
 * @letters: number of letters to be read and printed.
 *
 * Return: the actual number of letters it could read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t read_letters, written_letters;
	char *buffer = NULL;

	if (filename == NULL)
		return (0);

	buffer = malloc((sizeof(char) * letters));
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(buffer);
		return (0);
	}

	read_letters = read(fd, buffer, letters);
	if (read_letters == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	written_letters = write(STDOUT_FILENO, buffer, letters);
	if (written_letters == -1 || read_letters != written_letters)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer);
	close(fd);
	return (read_letters);
}
