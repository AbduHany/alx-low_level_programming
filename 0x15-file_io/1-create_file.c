#include "main.h"

/**
 * create_file - creates a file.
 * @filename: string of filename to be created.
 * @text_context: string to text to be added to newly created file.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, strlen, i;
	ssize_t written_bytes;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}
	
	for (strlen = 0, i = 0; text_content[i] != '\0'; i++)
		strlen++;
	written_bytes = write(fd, text_content, strlen);
	if (written_bytes == -1)
		return (-1);
	close(fd);
	return (1);
}
