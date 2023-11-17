#ifndef HSH_H
#define HSH_H

/**
 * Description - Header file containing all function prototype used in the
 *               simple shell project.
 */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024
#define BUFFER_SIZE 1024

extern char **environ;

/* string-handler.c */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *d, char *s);
char *_strcat(char *d, char *s);
char *_strchr(char *s, char c);

/* builtin_handler.c */
void handle_setenv(char *arg);
void handle_unsetenv(char *arg);
void handle_exit(char *arg);
void handle_env(void);
void handle_cd(char *dir);

/* command_handler.c */
void tokenize_command(char *command, char *args[]);
void process_builtin_commands(char *input);

/* execute_command.c */
void execute_command(char *args[]);

/* external_handler.c */
char *_strtok(char *str, const char *delim);
void handle_comment(char *command);
char *_getline();

/* operators_handler.c */
void handle_command_separator(char *command);
void handle_logical_and(char *command);
void handle_logical_or(char *command);

#endif /* #ifndef HSH_H */
