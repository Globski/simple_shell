#include "hsh.h"

/**
 * handle_setenv - Set environment variable with given name and value.
 * @arg: String containing name and value separated by a space.
 */
void handle_setenv(char *arg)
{
    char *name = _strtok(arg, " ");
    char *value = _strtok(NULL, " ");

    if (name != NULL && value != NULL)
    {
        handle_special_characters(value);

        if (setenv(name, value, 1) != 0)
            fprintf(stderr, "setenv: Unable to set environment variable\n");
    }
    else
        fprintf(stderr, "setenv: Invalid syntax\n");
}

/**
 * handle_unsetenv - Unset environment variable with given name.
 * @arg: String containing the name of the variable to unset.
 */
void handle_unsetenv(char *arg)
{
    char *name = _strtok(arg, " ");

    if (name != NULL)
    {
        if (unsetenv(name) != 0)
            fprintf(stderr, "unsetenv: Unable to unset environment variable\n");
    }
    else
        fprintf(stderr, "unsetenv: Invalid syntax\n");
}

/**
 * handle_exit - Exit the shell with the specified exit code.
 * @arg: String containing the exit code as a decimal number.
 */
void handle_exit(char *arg)
{
    char *endptr;
    long exitCode = strtol(arg, &endptr, 10);

    if (*endptr == '\0')
        exit(exitCode);
    else
        fprintf(stderr, "/bin/sh: 3: exit: Illegal number: %s\n", arg);
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
