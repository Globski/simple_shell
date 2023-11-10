#include "hsh.h"

/**
 * handle_env - Display environment variables
 * @args: Ignored argument for compatibility
 */
void handle_env(char **args)
{
	(void)args;
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * handle_exit - Handles the exit built-in commands with or without an exit status.
 * @args: the argument that will be passed.
 */
void handle_exit(char *args)
{
	int status;
	
	if (_strcmp(args, "exit") == 0)
		exit(0);
	
	if (strncmp(args, "exit ", 5) == 0)
	{
		status = atoi(args + 5);
		exit(status);
	}
}
