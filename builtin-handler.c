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
 *
 * Description: This function processes the 'exit' command, which can include an optional
 * exit status. It takes an array of strings (command arguments) and
 * checks if it's the 'exit' command or 'exit' with an optional status.
 * If an exit status is provided, it exits the program with that status,
 * otherwise, it exits with a status of 0. If the argument is not a valid
 * integer or '0', it displays an error message.
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

