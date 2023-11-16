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
