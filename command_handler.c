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
 * handle_command - Execute built-in commands or external commands.
 * @command: The input command string to be processed.
 *
 * Description: This function parses the input command, identifies whether it is a
 * built-in command (exit, env, setenv, unsetenv) or an external command,
 * and then executes the appropriate action.
 */
void handle_command(char *command)
{
	char *args[MAX_TOKENS];
	int is_builtin = 0;

	get_args(command, args);
	if (strcmp(args[0], "exit") == 0)
	{
		handle_exit(args);
		is_builtin = 1;
	}
	else if (strcmp(args[0], "env") == 0)
	{
		handle_env(args);
		is_builtin = 1;
	}
	else if (strcmp(args[0], "setenv") == 0)
	{
		handle_setenv(args);
		is_builtin = 1;
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
		handle_unsetenv(args);
		is_builtin = 1;
	}
	if (!is_builtin)
		execute_command(args);
}

/**
 * execute_command - Execute a command in a child process.
 * @args: Array of strings representing the command and its arguments.
 *
 * Description: This function forks a child process to execute the specified command.
 * It utilizes the handle_path function to locate and update the command path.
 * If the fork or execution fails, the child process exits with an error code.
 * The parent process waits for the child process to complete.
 *
 * Returns: None
 */
void execute_command(char **args)
{
	int status;
	
	pid_t child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(-1);
	}
	else if (child_pid == 0)
	{
		handle_path(args);
		if (execve(args[0], args, environ) == -1)
			exit(-1);
	}
	else
		wait(&status);
}
