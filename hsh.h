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
#define MAX_ARGS 100
#define BUFFER_SIZE 1024
#define MAX_ALIASES 100

extern char **environ;

/**
 * struct Alias - Represents an alias in the shell.
 * @name: The name of the alias.
 * @value: The value associated with the alias.
 */
typedef struct Alias
{
/* Structure to represent an alias */
	char *name;
	char *value;
} Alias;

/* Array to store aliases */
static Alias aliases[MAX_ALIASES];

/* Counter for the number of aliases */
static int numAliases;

/* string-handler.c */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *d, char *s);
char *_strcat(char *d, char *s);
char *_strchr(char *s, char c);

/* builtin_handler.c */
void handle_setenv(char *arg);
void handle_unsetenv(char *arg);
void handle_env(void);
void handle_exit(char *status);
void handle_cd(char *dir);

/* command_handler.c */
void handle_command(char *command);
void free_arguments(char *args[]);

/* path_handler.c */
void handle_path(char *command);

/* file_handler.c */
void run_file_command(const char *filename);

/* execute_command.c */
void execute_command(char *args[]);

/* external_handler.c */
char *_strtok(char *str, const char *delim);
void handle_comment(char *command);
char *_getline();

/* alias_handler.c */
void add_alias(char *name, char *value);
void print_alias(void);
void cleanup_aliases(void);
void replace_alias(char *name, char *value);
void set_alias(char *name, char *value);

/* operators_handler.c */
void handle_command_separator(char *command);
void handle_logical_and(char *command);
void handle_logical_or(char *command);

/* handle_alias.c */
void handle_alias(char *args[]);

/* variable_handler.c */
void handle_variable_replacement(char *command);
void handle_variable_assignment(char *assignment);

#endif /* #ifndef HSH_H */
