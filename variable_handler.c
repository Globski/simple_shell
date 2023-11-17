#include "hsh.h"

/**
 * handle_variable_replacement - Handles variable replacement
 * in the input command.
 *
 * @command: The input command string containing potential variable references
 *
 * Description: This function searches for variable references in the command,
 * denoted by '$', and replaces them with their corresponding values.
 * It supports special variables like '$', '$$', and '$?', as well
 * as environment variables. The modified command is then printed to stdout.
 */
void handle_variable_replacement(char *command)
{
	char *token;
	char *rest = command;
	(void) numAliases, (void) aliases;

	while ((token = _strtok(rest, " \t\n")) != NULL)
	{
		if (token[0] == '$')
		{
			if (strcmp(token, "$") == 0)
			{
				printf("%d ", getpid());
			}
			else if (strcmp(token, "$$") == 0)
			{
				printf("%d ", getpid());
			}
			else if (strcmp(token, "$?") == 0)
			{
				printf("%d ", WEXITSTATUS(getpid()));
			}
			else
			{
				char *env_value = getenv(token + 1);

				if (env_value != NULL)
					printf("%s ", env_value);
				else
					fprintf(stderr, "Error: Undefined variable '%s'\n", token);
			}
		}
		else
			printf("%s ", token);
		rest = NULL;
	}

	printf("\n");
}
/**
 * handle_variable_assignment - Handles variable assignments in the shell.
 * @assignment: The string containing the variable assignment.
 *
 * This function parses the input string containing a variable assignment,
 * separates the variable name and value, removes leading and trailing
 * whitespaces, and sets the environment variable accordingly
 * using setenv. If the assignment is invalid,
 * an error message is printed to stderr.
 */
void handle_variable_assignment(char *assignment)
{
	char *equal_sign, *variable, *value;
	size_t value_length;
	(void) numAliases, (void) aliases;

	equal_sign = strchr(assignment, '=');
	if (equal_sign == NULL || equal_sign == assignment)
	{
		fprintf(stderr, "Error: Invalid variable assignment: %s\n", assignment);
		return;
	}

	*equal_sign = '\0';
	variable = assignment;
	value = equal_sign + 1;

	while (*variable != '\0' && isspace(*variable))
		variable++;

	value_length = strlen(value);
	while (value_length > 0 && isspace(value[value_length - 1]))
		value_length--;

	value[value_length] = '\0';

	if (setenv(variable, value, 1) != 0)
	{
		perror("setenv");
		return;
	}
}
