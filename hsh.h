#ifndef HSH_H
#define HSH_H

/**
 * Description - Header file containing all function prototype used in the
 *               simple shell project.
 */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TOKENS 100
extern char **environ;

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *d, char *s);
char *_strcat(char *d, char *s);
char *_strchr(char *s, char c);
void handle_env(char **args);
void handle_setenv(char *variable, char *value);
void handle_unsetenv(char *variable);
void handle_command(char *command);
void get_args(char *command, char *args[]);
void handle_path(char **args);
void execute_command(char **args);
char *_strtok(char *str, const char *delim);

void handle_exit(char *status);

#endif /* #ifndef HSH_H */
