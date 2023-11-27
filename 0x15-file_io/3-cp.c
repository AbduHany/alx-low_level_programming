#include "main.h"

/**
 * teleportdata - transfers data from one FD to another.
 * @fd_from: file descriptor to read from.
 * @fd_to: file descriptor to write to.
 * @buffer: array of characters to use while reading and
 * writing.
 * @from: string of first argument in command-line.
 * @to: string of second argument in command-line.
 *
 * Return: void.
 */
void teleportdata(int fd_from, int fd_to, char *buffer, char *from, char *to)
{
	ssize_t w_bytes, r_bytes;

	do {
		r_bytes = read(fd_from, buffer, BUFFERSIZE);
		if (r_bytes == -1)
		{
			close(fd_from);
			close(fd_to);
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from);
			exit(98);
		}
		w_bytes = write(fd_to, buffer, r_bytes);
		if (w_bytes == -1)
		{
			close(fd_from);
			close(fd_to);
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to);
			exit(99);
		}
	} while (r_bytes > 0);
}

/**
 * main - program copies content from a file to another file.
 * @argc: number of argument count.
 * @argv: pointer to argument strings.
 *
 * Return: 0 if successful, otherwise another
 * value if error encountered.
 */
int main(int argc, char **argv)
{
	int fd_to, fd_from;
	char buffer[BUFFERSIZE];
	char *from, *to;

	from = argv[1];
	to = argv[2];
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(from, O_RDONLY); /* FD to read from */
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from);
		exit(98);
	}
	fd_to = open(to, O_WRONLY | O_TRUNC | O_CREAT, 0664);/* FD to write to */
	if (fd_to == -1)
	{
		close(fd_from);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to);
		exit(99);
	}
	teleportdata(fd_from, fd_to, buffer, from, to);
	if (close(fd_from) != 0)
	{
		close(fd_to);
		dprintf(STDERR_FILENO, "Error: Can't close fd %d", fd_from);
		exit(100);
	}
	if (close(fd_to) != 0)
	{
		close(fd_from);
		dprintf(STDERR_FILENO, "Error: Can't close fd %d", fd_to);
		exit(100);
	}
	return (0);
}
