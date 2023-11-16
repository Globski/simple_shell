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

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 100
#define BUFFER_SIZE 1024
#define MAX_ALIASES 100

extern char **environ;

typedef struct {
        char *name;
        char *value;
} Alias;

static Alias aliases[MAX_ALIASES];
static int numAliases = 0;

/* string-handler.c */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *d, char *s);
char *_strcat(char *d, char *s);
char *_strchr(char *s, char c);

/* builtin_handler.c */
void handle_setenv(char *variable, char *value);
void handle_unsetenv(char *variable);
void handle_env(void);
void handle_exit(char *status);

/* command_handler.c */
void handle_command(char *command);

void handle_path(char **args);
void execute_command(char *args[]);
char *_strtok(char *str, const char *delim);

/* alias_handler.c */
void handle_alias(char *args[]);
void add_alias(char *name, char *value);
void print_alias(void);
void cleanup_aliases(void);

void handle_logical_or(char *command);
void handle_logical_and(char *command);
void handle_command_separator(char *command);

#endif /* #ifndef HSH_H */
