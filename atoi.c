#include "shell.h"
/**
 * _atoi - converts strings to integers
 * @ptr: string to converte
 * Return: converted value
 */
int _atoi(char *ptr)
{
	int count = 0;
	int num = 0;

	if (ptr[count] == '+')
	{
		count++;
	}
	while (ptr[count])
	{
		if (ptr[count] < 48 || ptr[count] > 57)
		{
			return (-1);
		}
		num = (num * 10) + (ptr[count] - 48);
		count++;
	}
	return (num);
}
