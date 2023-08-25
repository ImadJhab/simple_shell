#include "shell.h"

#define READ_SIZE 1024

/**
 * custom_getline - Gets a line from a file descriptor.
 * @ln: Pointer to store the line.
 * @bufsize: Size of the buffer.
 * @fd: File descriptor.
 *
 * Return: Number of characters read, -1 on failure.
 */
ssize_t custom_getline(char **ln, size_t *bufsize, int fd)
{
	ssize_t n_chars = 0;

	if (ln == NULL || bufsize == NULL)
		return (-1);

	if (*ln == NULL)
	{
		*ln = malloc(sizeof(char) * READ_SIZE);
		if (*ln == NULL)
			return (-1);
		*bufsize = READ_SIZE;
	}

	n_chars = read(fd, *ln, *bufsize);
	if (n_chars == -1)
	{
		free(*ln);
		return (-1);
	}

	return (n_chars);
}
