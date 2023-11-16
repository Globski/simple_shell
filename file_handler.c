#include "hsh.h"

/**
 * run_file_command - Executes commands from a file line by line.
 * @filename: The name of the file containing commands.
 *
 * Description: This function opens the specified file, reads its contents line
 * by line, and executes each line as a separate command using handle_command.
 * The file is expected to contain one command per line. It handles errors
 * related to file operations and command execution appropriately.
 */

void run_file_command(const char *filename)
{
	char buffer[MAX_ARGS];
	ssize_t bytesRead;
	int file_descriptor;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	while ((bytesRead = read(file_descriptor, buffer, sizeof(buffer))) > 0)
	{
		for (ssize_t i = 0; i < bytesRead; i++)
		{
			if (buffer[i] == '\n')
			{
				handle_command(buffer);
				memset(buffer, 0, sizeof(buffer));
			}
		}
	}

	if (bytesRead == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}

	close(file_descriptor);
}
