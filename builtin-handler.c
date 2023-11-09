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
