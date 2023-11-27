#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: name of file where text is to be appended to.
 * @text_content: pointer to string to be appended to file.
 *
 * Return: 1 if successful, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, strlen, i;
	ssize_t written_bytes;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	for (i = 0, strlen = 0; text_content[i] != '\0'; i++)
		strlen++;
	written_bytes = write(fd, text_content, strlen);
	if (written_bytes == -1)
		return (-1);

	close(fd);
	return (1);
}
