#include "shell.h"

#define READ_SIZE 1024
/**
 * _getline - gets a line from a file descriptor
 * @ln: pointer to store the line
 * @bufsize:size of the buffer
 * @fd:file descriptor
 * Return:number of characters read
 */
ssize_t _getline(char **ln, size_t *bufsize, int fd)
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
