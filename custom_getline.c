#include "shell.h"

#define CUSTOM_READ_SIZE 1024

/**
 * custom_getline - gets a line from a file descriptor
 * @ln: pointer to store the line
 * @bufsize: size of the buffer
 * @fd: file descriptor
 * Return: number of characters read
 */
ssize_t custom_getline(char **ln, size_t *bufsize, int fd)
{
	ssize_t num_chars = 0;

	if (ln == NULL || bufsize == NULL)
		return (-1);

	if (*ln == NULL)
	{
		*ln = malloc(sizeof(char) * CUSTOM_READ_SIZE);
		if (*ln == NULL)
			return (-1);
		*bufsize = CUSTOM_READ_SIZE;
	}

	num_chars = read(fd, *ln, *bufsize);
	if (num_chars == -1)
	{
		free(*ln);
		return (-1);
	}

	return (num_chars);
}
