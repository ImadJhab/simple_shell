#include "shell.h"

#define CUSTOM_READ_SIZE 1024

/**
 * readLine - Reads a line from a file descriptor.
 * @ln: Pointer to store the line.
 * @bufsize: Size of the buffer.
 * @fd: File descriptor.
 * Return: Number of characters read.
 */
ssize_t readLine(char **ln, size_t *bufsize, int fd)

{
	ssize_t numChars = 0;

	if (ln == NULL || bufsize == NULL)
		return (-1);

	if (*ln == NULL)
	{
		*ln = malloc(sizeof(char) * CUSTOM_READ_SIZE);
		if (*ln == NULL)
			return (-1);
		*bufsize = CUSTOM_READ_SIZE;
	}

	numChars = read(fd, *ln, *bufsize);
	if (numChars == -1)
	{
		free(*ln);
		return (-1);
	}

	return (numChars);
}

/**
 * initializeBuffer - Initializes the line buffer.
 * @ln: Pointer to store the line.
 * @bufsize: Size of the buffer.
 */
void initializeBuffer(char **ln, size_t *bufsize)

{
	if (ln != NULL && *ln == NULL && bufsize != NULL)
	{
		*ln = malloc(sizeof(char) * CUSTOM_READ_SIZE);
		if (*ln != NULL)
			*bufsize = CUSTOM_READ_SIZE;
	}
}

/**
 * freeBuffer - Frees the line buffer.
 * @ln: Pointer to the line buffer.
 */
void freeBuffer(char **ln)

{
	if (ln != NULL && *ln != NULL)
	{
		free(*ln);
		*ln = NULL;
	}
}
