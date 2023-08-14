#include "shell.h"

#define MAX_INPUT_SIZE 1024

void simple_shell(void)
{
	while (1)
	{
	printf("($) ");
	char input[MAX_INPUT_SIZE];

	if (fgets(input, sizeof(input), stdin) == NULL)
	{
		perror("fgets");
	break;
	}
	input[strcspn(input, "\n")] = '\0';
	}
}
