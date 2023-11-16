#include "hsh.h"

/**
 * handle_alias - Handles the 'alias' built-in command
 * @args: An array of command arguments, with the command as the first element
 *
 * This function implements the 'alias' command, allowing the user to manage
 * aliases. If no arguments are provided, it prints the current list of aliases
 * using the print_alias function. If the user provides proper arguments,
 * it allows adding or replacing aliases. If the second argument is ' = ', it
 * replaces an existing alias with a new value using replace_alias. Otherwise,
 * it adds a new alias using the add_alias function.
 */
void handle_alias(char *args[])
{
	if (args[1] == NULL)
		print_alias();
	else if (args[2] != NULL && strcmp(args[2], "=") == 0)
		replace_alias(args[1], args[3]);
	else
		add_alias(args[1], args[2]);
}

/**
 * print_alias - Prints the current list of aliases
 *
 * Description: This function iterates through the array of aliases and prints
 * each alias along with its corresponding value in the format "name='value'".
 */
void print_alias(void)
{
	for (int i = 0; i < numAliases; i++)
	{
		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
	}
}
