#include "main.h"

/**
 * create_file - creates a file
 * @filename: filename
 * @text_content: NULL-terminated string to write (may be NULL)
 *
 * Return: 1 on success, -1 on failure
 *
 * Notes:
 * - Permissions: rw------- (0600)
 * - Truncate existing file
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t len = 0, w;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[len])
			len++;
		w = write(fd, text_content, len);
		if (w != len)
		{
			close(fd);
			return (-1);
		}
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}
