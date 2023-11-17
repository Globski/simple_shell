#include "hsh.h"

/**
 * execute_external_command - Execute an external command with arguments.
 * @args: Array containing the command and its arguments.
 */
void execute_external_command(char *args[])
{
	int status;
	pid_t pid = fork;

	if (pid == 0)
	{
		char *path = getenv("PATH");
		char *token = _strtok(path, ":");

		while (token != NULL)
		{
			char full_path[MAX_INPUT_SIZE];

			snprintf(full_path, sizeof(full_path), "%s/%s", token, args[0]);
			if (access(full_path, X_OK) == 0)
			{
				execve(full_path, args, NULL);
				perror("hsh");
				exit(EXIT_FAILURE);
			}
			token = _strtok(NULL, ":");
		}
		fprintf(stderr, "%s: command not found\n", args[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("hsh");
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/**
 * process_external_command - Process an external command.
 * @input: The command string to process.
 */
void process_external_command(char *input)
{
    execute_command(input);
}
