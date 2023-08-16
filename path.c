#include "shell.h"
/**
 * _env - gets the environement
 * @n: name of the environement
 * Return: always 0
 */
char *_env(char *n)
{
	int j = 0;
	ssize_t length = _strlen(n);

	for (; environ[j]; j++)
	{
		if (strncmp(environ[j], n, length) == 0 && environ[j][length] == '=')
		{
			return (&environ[j][length + 1]);
		}
	}
	return (0);
}
/**
 * get_command - locate and return the full path
 * @cmd: command to be found
 * Return: multiple conditions
*/
char *get_command(char *cmd)
{
	char *pa;
	char *pacpy;
	char *patok;
	char *pafile;
	int lendir, lencmd;
	struct stat buff;

	pa = _env("PATH");
	if (pa)
	{
		pacpy = _strdup(pa);
		lencmd = _strlen(cmd);
		patok = strtok(pacpy, ":");
		while (patok)
		{
			lendir = _strlen(patok);
			pafile = malloc(lencmd + lendir + 2);
			_strcpy(pafile, patok);
			_strcat(pafile, "/");
			_strcat(pafile, cmd);
			_strcat(pafile, "\0");
			if (stat(pafile, &buff) == 0)
			{
				free(pacpy);
				return (pafile);
			}
			else
			{
				free(pafile);
				patok = strtok(NULL, ":");
			}
		}
		free(pacpy);
		if (stat(cmd, &buff) == 0)
		{
			return (cmd);
		}
		return (0);
	}
	return (0);
}
