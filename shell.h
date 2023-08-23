#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>

#define BUFSIZE 1024

extern char **environ;

int env1(void);
int exit_sh(char **toks, char *buff);
int _atoi(char *ptr);
int execute_command(char **agv, char *buf);
int _builtin(char **toks, char *buff);
void free_tokens(char **toks);
char *get_command(char *cmd);
int _strcmp(char *ss1, char *ss2);
int _putchar(char c);
int _strlen(char *p);
char *_strcpy(char *go, char *sr);
void _puts(char *str);
char *_strdup(char *str);
char *_strcat(char *go, char *sr);
char *_strncpy(char *dest, char *src, int n);
char *_env(char *n);
void tokenizes(char *buff, char **tok);
ssize_t _getline(char **ln, size_t *bufsize, int fd);

#endif
