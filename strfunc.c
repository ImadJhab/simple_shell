#include "shell.h"
/**
 * _strcmp - compares two strings
 * @ss1: pointer of the first string
 * @ss2: pointer of the second string
 * Return: integer
 */
int _strcmp(char *ss1, char *ss2)
{
	while (*ss1 != '\0' && *ss1 == *ss2)
	{
		ss1++;
		ss2++;
	}
	return (*(unsigned char *)ss1 - *(unsigned char *)ss2);
}
/**
 * _strlen - returns the length of a string
 * @p: pointer of a string
 * Return: len
 */
int _strlen(char *p)
{
	int len = 0;

	while (*p != '\0')
	{
		len++;
		p++;
	}
	return (len);
}
/**
 * _strcpy - copies the string pointed to
 * @sr: string pointed to
 * @go: new string
 * Return: none
 */
char *_strcpy(char *go, char *sr)
{
	int i;

	for (i = 0; sr[i]; i++)
	{
		go[i] = sr[i];
	}
	go[i++] = '\0';
	return (go);
}
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *  which contains a copy of the string given as a parameter
 * @str: string given
 * Return: 0 in first condition, pointer in the second one,
 * 0 int the third
*/
char *_strdup(char *str)
{
	int ln;
	char *sec;

	if (str == 0)
	{
		return (0);
	}

	ln = _strlen(str);
	sec = (char *) malloc((ln + 1) * sizeof(char));

	if (sec == 0)
	{
		return (0);
	}
	_strcpy(sec, str);
	return (sec);
}
/**
*_strcat - function that concatenates two strings.
*@go: pointer to destination string.
*@sr: pointer to source string.
*
*Return: pointer to the resulting string
 */
char *_strcat(char *go, char *sr)
{
	int length, i;

	length = 0;
	while (go[length] != '\0')
	{
		length++;
	}
	for (i = 0; sr[i] != '\0'; i++, length++)
	{
		go[length] = sr[i];
	}
	go[length] = '\0';
	return (go);
}
