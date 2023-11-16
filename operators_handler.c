#include "hsh.h"

/**
 * handle_command_separator - Handles command separation using semicolons
 * @command: The input command string with semicolon-separated commands
 *
 * Description: This function tokenizes the input command using semicolons
 * as delimiters, allowing the execution of multiple commands in sequence.
 * Each separated command is then processed using the handle_command function.
 */
void handle_command_separator(char *command)
{
	char *commands[MAX_ARGS];
	int i = 0;

	_strtok(command, ";", commands, MAX_ARGS);

	while (commands[i] != NULL)
	{
		handle_command(commands[i]);
		i++;
	}
}

/**
 * handle_logical_and - Handles logical AND command chaining
 * @command: The input command string with '&&'-separated commands
 *
 * Description: This function tokenizes the input command using '&&'
 * as a delimiter, allowing the execution of multiple commands in sequence.
 * Each command is executed, and if any command fails (returns a non-zero
 * exit status), the execution stops. It utilizes the system function for
 * command execution.
 */
void handle_logical_and(char *command)
{
	char *commands[MAX_ARGS];
	int i = 0, result;

	_strtok(command, "&&", commands, MAX_ARGS);
	while (commands[i] != NULL)
	{
		result = system(commands[i]);
		if (result != 0)
			break;
		i++;
	}
}

/**
 * handle_logical_or - Handles logical OR command chaining
 * @command: The input command string with ''-separated commands
 *
 * Description: This function tokenizes the input command using ''
 * as a delimiter, allowing the execution of multiple commands in sequence.
 * Each command is executed, and if any command succeeds (returns a zero
 * exit status), the execution stops. It utilizes the system function for
 * command execution.
 */
void handle_logical_or(char *command)
{
	char *commands[MAX_ARGS];
	int i = 0, result;

	_strtok(command, "||", commands, MAX_ARGS);
	while (commands[i] != NULL)
	{
		result = system(commands[i]);
		if (result == 0)
			break;
		i++;
	}
}
