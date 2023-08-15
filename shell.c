#include "shell.h"

#define MAX_INPUT_SIZE 1024

/**
 * simple_shell - Entry point of the simple shell program
 */

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
/**
 * execute_custom_command - Execute a command using execvp
 * @command: The command to be executed
 *
 * Description: This function creates a child process to execute the specified
 *              command using the execvp system call.
 */
void execute_custom_command(const char *command)
{
	char *args[MAX_INPUT_SIZE];

	args[0] = (char *)command;
	args[1] = NULL;

	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
	}
	else if (child_pid == 0)
	{
	execvp(args[0], args);
	perror("execvp");
	exit(EXIT_FAILURE);
	}
	else
	{
	wait(NULL);
	}
}
