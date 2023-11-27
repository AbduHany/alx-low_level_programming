#include "main.h"

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
	ssize_t read_bytes, written_bytes;
	char buffer[BUFFERSIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(argv[1], O_RDONLY); /* FD to read from */
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd_to = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);/* FD to write to */
	if (fd_to == -1)
	{
		close(fd_from);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	do {
		read_bytes = read(fd_from, buffer, BUFFERSIZE);
		written_bytes = write(fd_to, buffer, read_bytes);
		if (written_bytes == -1)
			exit(99);
	} while (read_bytes > 0);
	if (close(fd_from) != 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d", fd_from);
		exit(100);
	}
	if (close(fd_to) != 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d", fd_to);
		exit(100);
	}
	return (0);

}
