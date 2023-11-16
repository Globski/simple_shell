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
	char *rest = command, *env_value;

	while ((token = strtok_r(rest, " \t\n", &rest)))
	{
		if (token[0] == '$')
		{
			if (strcmp(token, "$") == 0)
				printf("%d ", getpid());
			else if (strcmp(token, "$$") == 0)
				printf("%d ", getpid());
			else if (strcmp(token, "$?") == 0)
				printf("%d ", WEXITSTATUS(getpid()));
			else
			{
				env_value = getenv(token + 1);
				if (env_value != NULL)
					printf("%s ", env_value);
				else
					fprintf(stderr, "Error: Undefined variable '%s'\n", token);
			}
		}
		else
			printf("%s ", token);
	}

	printf("\n");
}


