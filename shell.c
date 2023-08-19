#include "shell.h"

#define MAX_INPUT_SIZE 1024
/**
 * tokenizes - tokenizes a string
 * @buff: buffer
 * @toks: tokens
 * Return: none
*/
void tokenizes(char *buff, char **toks)
{
	const char *delimiter = "\t\r\n\a";
	size_t lentok;
	char *tok = 0;
	char *buffsize = 0;
	int i = 0;

	buffsize = _strdup(buff);
	tok = strtok(buffsize, delimiter);
	for (i = 0; tok; i++)
	{
		lentok = _strlen(tok);
		toks[i] = malloc(sizeof(char *) * lentok);
		_strncpy(toks[i], tok, lentok + 1);
		tok = strtok(0, delimiter);
	}
	free(buffsize);
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
