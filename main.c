#include "shell.h"
/**
 * free_tokens - free the tokens
 * @toks: tokens to be freed
 */
void free_tokens(char **toks)
{
	int count = 0;

	while (toks[count])
	{
		free(toks[count]);
		count++;
	}
}
/**
 * main - main function
 * Return: stat of the shell
*/
int main(void)
{
	int statt = 0;
	char *buff = NULL;
	bool exe = true;
	ssize_t n;
	size_t buffsize = 0;
	char *toks[100] = {0};

	while (exe)
	{
		if (isatty(STDIN_FILENO))
		{
			fflush(stdin);
			write(1, "$ ", 2);
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
			exit(statt);
		}
		if (*buff == '\n' || (*buff == ' ' || *buff == '\t'))
			continue;
		tokenizes(buff, toks);
		statt = execute_command(toks, buff);
		free(buff);
		free_tokens(toks);
		buff = NULL;
		buffsize = 0;
	}
	free(buff);
	return (statt);
}
