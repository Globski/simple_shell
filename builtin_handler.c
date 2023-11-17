#include "hsh.h"

/**
 * handle_setenv - Handles the 'setenv' built-in command
 * @variable: The environment variable to set
 * @value: The value to assign to the environment variable
 *
 * Description: This function implements the 'setenv' command, allowing
 * the user to set or update the value of an environment variable. It
 * checks for correct usage and prints an error message if arguments are
 * missing. If the 'setenv' system call fails, it prints an error message.
 */
void handle_setenv(char *variable, char *value)
{
	(void) numAliases, (void) aliases;

	if (variable == NULL || value == NULL)
	{
		fprintf(stderr, "Error: Usage - setenv VARIABLE VALUE\n");
		return;
	}
	if (setenv(variable, value, 1) != 0)
	{
		perror("setenv");
		return;
	}
}

/**
 * handle_unsetenv - Handles the 'unsetenv' built-in command
 * @variable: The environment variable to unset
 *
 * Description: This function implements the 'unsetenv' command, allowing
 * the user to remove an environment variable. It checks for correct usage
 * and prints an error message if the variable argument is missing. If the
 * 'unsetenv' system call fails, it prints an error message.
 */
void handle_unsetenv(char *variable)
{
	(void) numAliases, (void) aliases;

	if (variable == NULL)
	{
		fprintf(stderr, "Error: Usage - unsetenv VARIABLE\n");
		return;
	}
	if (unsetenv(variable) != 0)
	{
		perror("unsetenv");
		return;
	}
}

/**
 * handle_exit - Handles the 'exit' built-in command
 * @status: The exit status as a string
 *
 * Description: This function processes the 'exit' command, allowing
 * the user to exit the shell. If no status is provided, it exits with
 * EXIT_SUCCESS. If a numeric status is provided, it exits with the
 * corresponding exit code. Otherwise, it prints an error message.
 */
void handle_exit(char *status)
{
	int valid = 1, exit_code;
	size_t i;
	(void) numAliases, (void) aliases;

	if (status == NULL)
		exit(EXIT_SUCCESS);
	else
	{
		valid = 1;
		for (i = 0; i < strlen(status); i++)
		{
			if (!isdigit(status[i]))
			{
				valid = 0;
				break;
			}
		}

		if (valid)
		{
			exit_code = atoi(status);
			exit(exit_code);
		}
		else
			fprintf(stderr, "/bin/sh: 1: exit: Illegal number: %s\n", status);
	}
}

/**
 * handle_env - Displays the current environment variables
 *
 * Description: This function iterates through the current environment
 * variables and prints each one to the standard output.
 */
void handle_env(void)
{
	char **env_var = environ;
	(void) numAliases, (void) aliases;

	while (*env_var != NULL)
	{
		printf("%s\n", *env_var);
		env_var++;
	}
}

/**
 * handle_cd - Change the current working directory.
 * @dir: The target directory path.
 *
 * Change the current working directory based on the specified
 * directory path. Supports changing to the home directory, the
 * previous directory, or a specific directory.
 */
void handle_cd(char *dir)
{
	char *home_dir = getenv("HOME"), new_dir[MAX_ARGS];
	char *previous_dir = getenv("PWD"), current_dir[MAX_ARGS];
	(void) numAliases, (void) aliases;

	if (dir == NULL)
	{
		if (home_dir == NULL)
		{
			fprintf(stderr, "Error: HOME environment variable not set\n");
			return;
		}
		else
			strncpy(new_dir, home_dir, sizeof(new_dir) - 1);
	}
	else if (strcmp(dir, "-") == 0)
	{
		if (previous_dir == NULL)
		{
			fprintf(stderr, "Error: Previous directory not set\n");
			return;
		}
		else
			strncpy(new_dir, previous_dir, sizeof(new_dir) - 1);
	}
	else
		strncpy(new_dir, dir, sizeof(new_dir) - 1);
	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("getcwd");
		return;
	}
	if (chdir(new_dir) != 0)
	{
		perror("chdir");
		return;
	}
	if (setenv("PWD", current_dir, 1) != 0)
	{
		perror("setenv");
		return;
	}
}
