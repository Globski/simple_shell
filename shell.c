#include "hsh.h"
/**
 * main - Entry point for the simple shell program
 *
 * Description: This function sets the initial PATH environment
 * variable, enters a loop to continuously prompt for
 * user input, and processes each input command
 * using the handle_command function. The loop continues
 * until the user decides to exit the shell.
 * After the loop, it cleans up any allocated memory used for aliases.
 *
 * Return: Always returns 0 on successful completion.
 */
int main(void)
{
	setenv("PATH", "/bin:/usr/bin", 1);

	char *input;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		input = _getline();

		if (input == NULL)
		{
			printf("\n");
			break;
		}

		handle_command(input);

		free(input);
	}

	cleanup_aliases();

	return (0);
}
