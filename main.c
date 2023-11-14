#include "hsh.h"
/**
 * main - Entry point of the shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Description: This function represents the main loop of a simple shell program. It prompts
 * the user for commands, processes the input, and executes either built-in
 * commands (exit, env, setenv, unsetenv) or external commands.
 *
 * Return: Always returns 0.
 */
int main(int argc, char *argv[])
{
	(void) argc, (void) argv;
	char *command = NULL;

	while (1)
	{
		printf("$ ");
		size_t commandSize = 0;
		ssize_t bytes_read = getline(&command, &commandSize, stdin);

		if (bytes_read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				exit(0);
			}
			else
			{
				perror("getline");
				exit(-1);
			}
		}

		if (bytes_read == 1)
		{
			free(command);
			continue;
		}

		if (command[bytes_read - 1] == '\n')
			command[bytes_read - 1] = '\0';

		handle_command(command);
		free(command);
	}

	return (0);
}
