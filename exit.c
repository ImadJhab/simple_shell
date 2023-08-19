#include "shell.h"
/**
 * exit_sh - exists the shell
 *@toks: tokens
 *@buff: buffer
 * Return: integer
 */
int exit_sh(char **toks, char *buff)
{
	int counter = 0;
	int es = 0;

	while (toks[counter])
	{
		counter++;
	}
	if (counter == 1)
	{
		free_tokens(toks);
		free(buff);
		exit(0);
	}
	if (_atoi(toks[1]) == -1)
	{
		fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", toks[1]);
		return (2);
	}
	es = atoi(toks[1]);
	free_tokens(toks);
	free(buff);
	exit(es);
}
