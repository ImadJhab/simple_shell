#include "shell.h"
/**
 * _builtin - handls the builtin commands
 * @toks: tokens
 * @buff: buffer
 * Return: multiple conditions
*/
int _builtin(char **toks, char *buff)
{
	if (_strcmp(toks[0], "exit") == 0)
	{
		return (exit_sh(toks, buff));
	}
	else if (_strcmp(toks[0], "env") == 0)
	{
		return (env1());
	}
	else
	{
		return (-1);
	}
}
/**
 * env1 - gets the env
 * Return: Always 0
 */
int env1(void)
{
	int co;

	for (co = 0; environ[co]; co++)
	{
		_puts(environ[co]);
	}
	return (0);
}
