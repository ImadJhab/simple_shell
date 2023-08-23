#include "shell.h"
#include <unistd.h>
#include <fcntl.h>

#define MAX_TOKENS 100
/**
 * main - main function
 * Return: stat of the shell
*/
int main(void)
{
	int stat = 0;
	char *buff = NULL;
	bool exe = true;
	ssize_t n;
	size_t buffsize = 0;
	char *toks[MAX_TOKENS] = {0};

	while (exe)
	{
		if (isatty(STDIN_FILENO))
			if (write(STDOUT_FILENO, "$ ", 2) == -1) {
				perror("write");
				exit(EXIT_FAILURE);
			}
		else
			exe = false;

		n = getline(&buff, &buffsize, stdin);

		if (n == -1)
		{
			if (!isatty(STDIN_FILENO))
			{
				free(buff);
				break;
			}
			perror("getline");
			free(buff);
			exit(stat);
		}
		else if (*buff == '\n' || (*buff == ' ' || *buff == '\t'))
		{
			continue;
		}
		tokenizes(buff, toks);
		stat = execute_command(toks, buff);
		free_tokens(toks);
		free(buff);
		buff = NULL;
		buffsize = 0;
	}
	free(buff);
	return (stat);
}
