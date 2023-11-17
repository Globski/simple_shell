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
		{
			execute_external_command(args);
		}
	}
}
