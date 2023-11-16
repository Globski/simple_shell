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
