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
        int valid = 1;
        size_t i;

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
                        int exit_code = atoi(status);
                        exit(exit_code);
                }
                else
                        fprintf(stderr, "/bin/sh: 1: exit: Illegal number: %s\n", status);
        }
}
