#include "hsh.h"

/**
 * execute_command - Execute the given command.
 * @command: The command string to execute.
 */
void execute_command(char *command)
{
	char *args[MAX_ARGS];
	substitute_variables(command);
	tokenize_command(command, args);

	if (args[0] != NULL)
	{
		if (strcmp(args[0], "cd") == 0)
		{
			char *dir = args[1];
			handle_cd(dir);
		}
		else
			execute_external_command(args);
	}
}

/**
 * tokenize_command - Tokenize the given command into an array of arguments.
 * @command: The command string to tokenize.
 * @args: An array to store the resulting arguments.
 */
void tokenize_command(char *command, char *args[])
{
    int i = 0;
    char *token = _strtok(command, " ");

    while (token != NULL)
    {
        args[i++] = token;
        token = _strtok(NULL, " ");
    }

    args[i] = NULL;
}
