#include "hsh.h"

/**
 * add_alias - Adds a new alias or updates an existing one.
 * @name: The name of the alias to add or update.
 * @value: The value to assign to the alias.
 *
 * Description: This function adds a new alias or updates the value of an
 * existing alias. It utilizes the set_alias function to set or update the
 * value of the specified alias, ensuring that the alias is added or
 * modified accordingly.
 */
void add_alias(char *name, char *value)
{
	set_alias(name, value);
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

/**
 * cleanup_aliases - Frees memory allocated for alias names and values.
 *
 * Description: This function iterates through the array of aliases and frees
 * the memory allocated for both alias names and values. It ensures proper
 * cleanup to prevent memory leaks after using aliases in the shell.
 */
void cleanup_aliases(void)
{
	int i;

	for (i = 0; i < numAliases; i++)
	{
		free(aliases[i].name);
		free(aliases[i].value);
	}
}

/**
 * replace_alias - Replaces an existing alias or sets a new one.
 * @name: The name of the alias to replace or set.
 * @value: The value to assign to the alias.
 *
 * Description: This function replaces an existing alias with the provided
 * name if found, or sets a new alias if the name does not exist. It delegates
 * the replacement or setting operation to the set_alias function, ensuring
 * proper handling of memory allocation. Any existing value associated with
 * the alias is freed before updating.
 */
void replace_alias(char *name, char *value)
{
	set_alias(name, value);
}

/**
 * set_alias - Sets or updates an alias with the provided name and value.
 * @name: The name of the alias to set or update.
 * @value: The value to assign to the alias.
 *
 * Description: Searches for an existing alias with the given name. If found,
 * updates the alias with the provided value. If not found and the maximum
 * aliases is not reached, adds a new alias. Memory is dynamically allocated
 * for the alias name and value. Any existing value is freed before updating.
 */
void set_alias(char *name, char *value)
{
	int i;

	for (i = 0; i < numAliases; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			free(aliases[i].value);
			aliases[i].value = strdup(value);
			if (!aliases[i].value)
			{
				perror("strdup");
				exit(EXIT_FAILURE);
			}
			return;
		}
	}
	if (numAliases >= MAX_ALIASES)
	{
		fprintf(stderr, "Error: Maximum number of aliases reached\n");
		exit(EXIT_FAILURE);
	}

	aliases[numAliases].name = strdup(name);
	aliases[numAliases].value = strdup(value);
	if (!aliases[numAliases].name || !aliases[numAliases].value)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	numAliases++;
}
