#include "hsh.h"

/**
 * handle_env - Prints the current environment variables.
 * one per line.
 *
 * Description: It iterates through the `environ` array and
 * prints each variable.
 *
 * Return: No return value.
 */
int handle_env(void)
{
	char **env = environ;

	if (!env)
		return (-1);

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
