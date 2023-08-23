#include "shell.h"

/**
 * tokenizes - tokenizes a string
 * @buff: buffer
 * @toks: tokens
 * Return: none
*/
void tokenizes(char *buff, char **toks)
{
	const char *delimiter = " \t\r\n\a";
	size_t lentok;
	char *tok = 0;
	char *buffsize = strdup(buff);
	int i = 0;

	if (buffcopy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	
	tok = strtok(buffcopy, delimiter);
	while (tok)
	{
		toks[i] = strdup(tok);
		if (toks[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		i++;
		tok = strtok(NULL, delimiter);
	}
	free(buffcopy);
	toks[i] = NULL;
}
/**
 * execute_command - executes a command
 * @agv: argument vector
 * @buf: buffer
 * Return: quits the loop
*/
int execute_command(char **agv, char *buf)
{
	char *cmnd = 0;
	pid_t child_pid;
	int quit;

	quit = _builtin(agv, buf);
	if (quit == -1)
	{
		cmnd = get_command(agv[0]);
		if (!cmnd)
		{
			_puts("Command not found");
			return (2);
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			if (execve(cmnd, agv, environ) == -1)
			{
				perror("execve");
				free_tokens(agv);
				free(buf);
				exit(2);
			}
		}
		else
		{
			waitpid(child_pid, &quit, 0);
			if (quit != 0)
				quit = 2;
		}
		if (_strcmp(cmnd, agv[0]) != 0)
			free(cmnd);
	}
	return (quit);
}
