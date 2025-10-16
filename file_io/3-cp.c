#include "main.h"
#include <stdio.h>   /* dprintf */

/**
 * close_fd - closes fd and handles error
 * @fd: file descriptor
 */
static void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 *
 * Usage: cp file_from file_to
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_fd(fd_from);
		exit(99);
	}

	while ((r = read(fd_from, buf, sizeof(buf))) > 0)
	{
		w = write(fd_to, buf, r);
		if (w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close_fd(fd_from);
			close_fd(fd_to);
			exit(99);
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close_fd(fd_from);
		close_fd(fd_to);
		exit(98);
	}

	close_fd(fd_from);
	close_fd(fd_to);
	return (0);
}
