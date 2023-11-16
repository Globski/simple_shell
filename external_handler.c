#include "hsh.h"

/**
 * _strtok - tokenizes a string.
 * @str: the string to be tokenized.
 * @delim: the delimiter.
 * Return: the tokenized string.
 */
char *_strtok(char *str, const char *delim)
{
	static char *nextToken;
	char *ptr;
	int i;

	if (str != NULL)
		nextToken = str;
	else if (nextToken == NULL)
		return (NULL);
	while (*nextToken != '\0' && strchr(delim, *nextToken) != NULL)
		nextToken++;
	if (*nextToken == '\0')
		return (NULL);
	ptr = malloc(sizeof(char) * _strlen(nextToken) + 1);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; nextToken[i] && strchr(delim, nextToken[i]) == NULL; i++)
		ptr[i] = nextToken[i];
	ptr[i] = '\0';
	nextToken += 1;
	return (ptr);
}

/**
 * handle_comment - Handles comments in the input command
 * @command: The input command string
 *
 * Description: This function searches for a '#' character in the input
 * command and, if found, truncates the command at the '#' character,
 * effectively removing the rest of the string as it is considered a comment.
 */
void handle_comment(char *command)
{
	char *comment_position = strchr(command, '#');

	if (comment_position != NULL)
		*comment_position = '\0';
}


/**
 * _getline - Custom getline function to read a line from standard input
 *
 * Return: On success, returns a pointer to the read line. On failure or
 * end of file, returns NULL.
 */
char *_getline()
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index;
	static size_t buffer_size;
	size_t end_position, line_size, read_size, i;
	char *line;

	buffer_index = 0;
	buffer_size = 0;

	if (buffer_index >= buffer_size)
	{
		read_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		else if (read_size == 0)
			return (NULL);

		buffer_size = (size_t)read_size;
		buffer_index = 0;
	}

	end_position = buffer_index;
	while (end_position < buffer_size && buffer[end_position] != '\n')
		end_position++;

	line_size = end_position - buffer_index;
	line = (char *)malloc(line_size + 1);
	if (!line)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < line_size; i++)
		line[i] = buffer[buffer_index + i];

	line[line_size] = '\0';

	if (end_position < buffer_size && buffer[end_position] == '\n')
		buffer_index = end_position + 1;
	else
		buffer_index = buffer_size;

	return (line);
}
