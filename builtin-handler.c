#include "hsh.h"

/**
 * handle_env - Display environment variables.
 * @args: Ignored argument for compatibility.
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
 * handle_exit - Handle the 'exit' command.
 * @args: An array of command arguments.
 */
void handle_exit(char **args)
{
	int status;
	if (args[1] != NULL)
	{
		status = atoi(args[1]);
		if (status == 0 && strcmp(args[1], "0") != 0)
		{
			fprintf(stderr, "Error: Invalid argument for exit\n");
			return;
		}
		exit(status);
	}
	else
		exit(0);
}
