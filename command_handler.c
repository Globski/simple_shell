#include "hsh.h"

/**
 * get_args - Function that gets the argument and tokenizes it.
 * @command: the argument.
 * @args: the buffer to store the array of strings.
 */
void get_args(char *command, char *args[])
{
	int i = 0;
	char *token;

	token = strtok(command, " ");
	while (token != NULL)
	{
		args[i] = token;
		i += 1;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}

/**
 * handle_command - Execute built-in commands or external commands.
 * @command: The input command string to be processed.
 *
 * Description: This function parses the input command, identifies whether it is a
 * built-in command (exit, env, setenv, unsetenv) or an external command,
 * and then executes the appropriate action.
 */
void handle_command(char *command)
{
	char *args[MAX_TOKENS];
	int is_builtin = 0;

	get_args(command, args);
	if (strcmp(args[0], "exit") == 0)
	{
		handle_exit(args);
		is_builtin = 1;
	}
	else if (strcmp(args[0], "env") == 0)
	{
		handle_env(args);
		is_builtin = 1;
	}
	else if (strcmp(args[0], "setenv") == 0)
	{
		handle_setenv(args);
		is_builtin = 1;
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
		handle_unsetenv(args);
		is_builtin = 1;
	}
	if (!is_builtin)
		execute_command(args);
}
