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
