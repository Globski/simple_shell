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

/**
 * handle_command - Reads and processes user commands in a shell loop.
 *
 * @argv: The command-line arguments of the shell program.
 */

void handle_command(char *argv[])
{
	ssize_t bytes_read = 0;
	char *command = NULL;
	size_t commandSize = 0;
	pid_t child_pid;
	int status;

	while (1)
	{
		printf("$ ");
		bytes_read = getline(&command, &commandSize, stdin);

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
			continue;

		if (command[bytes_read - 1] == '\n')
			command[bytes_read - 1] = '\0';
		child_pid = fork();
		if (child_pid == -1)
			exit(-1);
		if (child_pid == 0)
			handle_args(command, argv);
		else
			wait(&status);
	}
	free(command);
}
