#include "hsh.h"

/**
 * handle_command - Parses and handles user input commands
 * @command: The input command string
 *
 * This function tokenizes the input command, processes built-in commands
 * such as exit, env, setenv, unsetenv, cd, alias, and source, and executes
 * external commands using execute_command. It also handles source commands
 * by running the specified file if provided. The function frees allocated
 * memory for command arguments after processing.
 */
void handle_command(char *command)
{
	char *args[MAX_ARGS], *token;
	size_t i = 0;
	(void) numAliases, (void) aliases;

	token = strtok(command, " \t\n");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i] = strdup(token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	args[i] = NULL;
	if (i == 0 || args[0] == NULL)
		return;
	if (strchr(command, '=') != NULL)
		handle_variable_assignment(command);
	if (strcmp(args[0], "exit") == 0)
		handle_exit(args[1]);
	else if (strcmp(args[0], "env") == 0)
		handle_env();
	else if (strcmp(args[0], "setenv") == 0)
		handle_setenv(args[1], args[2]);
	else if (strcmp(args[0], "unsetenv") == 0)
		handle_unsetenv(args[1]);
	else if (strcmp(args[0], "cd") == 0)
		handle_cd(args[1]);
	else if (strcmp(args[0], "alias") == 0)
		handle_alias(args);
	else if (strcmp(args[0], "source") == 0)
	{
		if (args[1] == NULL || args[2] != NULL)
		{
		}
		else
			run_file_command(args[1]);
	}
	else
		execute_command(args);
	free_arguments(args);
}

/**
 * tokenize_command - Tokenize the given command into an array of arguments.
 * @command: The command string to tokenize.
 * @args: An array to store the resulting arguments.
 */
void tokenize_command(char *command, char *args[])
{
    int i = 0;
    char *token = _strtok(command, " ");

    while (token != NULL)
    {
        args[i++] = token;
        token = _strtok(NULL, " ");
    }

    args[i] = NULL;
}
