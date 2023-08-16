#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

void simple_shell(void);
void execute_custom_command(const char *command);
char *get_command(char *cmd);
int _strcmp(char *ss1, char *ss2);
int _strlen(char *p);
char *_strcpy(char *go, char *sr);
char *_strdup(char *str);
char *_strcat(char *go, char *sr);
char *_env(char *n);

#endif
