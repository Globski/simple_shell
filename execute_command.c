#include "hsh.h"

/**
 * execute_command - Executes an external command
 * @args: An array of command arguments, with the command as the first element
 *
 * Description: This function forks a new process to execute the specified
 * external command. In the child process, it calls handle_path to find and
 * execute the command. The parent process waits for the child process to
 * complete and collects its exit status.
 */
void execute_command(char *args[])
{
	int status;
	pid_t child_pid;
	(void) numAliases, (void) aliases;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		handle_path(args[0]);
		perror("handle_path");
		exit(EXIT_FAILURE);
	}
	else
		waitpid(child_pid, &status, 0);
}
