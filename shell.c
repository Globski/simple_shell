#include "hsh.h"

/**
 * run_non_interactive_mode - Run the shell in non-interactive mode, processing input.
 */
void run_non_interactive_mode()
{
    char *input;

    while ((input = _getline()) != NULL)
    {
        execute_command(input);
        free(input);
    }
}
/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Description: Sets up signal handlers, saves original terminal settings,
 * and runs interactive or non-interactive mode based on the number of
 * command-line arguments.
 *
 * Return: 0 if successful.
 */
int main(int argc, char **argv)
{
	signal(SIGINT, handle_signals);
	signal(SIGTSTP, handle_signals);

	tcgetattr(STDIN_FILENO, &orig_termios);

	if (argc == 1)
		run_interactive_mode();
	else if (argc == 2)
		run_non_interactive_mode();
	else
	{
		fprintf(stderr, "Usage: %s [script]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	cleanup();

	return (0);
}

