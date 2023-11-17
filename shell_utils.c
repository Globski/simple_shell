#include "hsh.h"

/**
 * substitute_variables - Replace environment variable references in a command.
 * @command: The command string to process.
 */
void substitute_variables(char *command)
{
	char *ptr = command;
	char *var_value, *var_name;
	unsigned int var_len;

	while ((ptr = strchr(ptr, '$')) != NULL)
	{
		if (isalpha(*(ptr + 1)))
		{
			char *var_start = ptr + 1;
			char *var_end = var_start + 1;

			while (isalnum(*var_end) || *var_end == '_')
			{
				var_end++;
			}
			var_len = var_end - var_start;
			var_name = (char *)malloc(var_len + 1);
			strncpy(var_name, var_start, var_len);
			var_name[var_len] = '\0';
			var_value = getenv(var_name);
			if (var_value != NULL)
			{
				memmove(ptr, var_value, strlen(var_value));
				ptr += strlen(var_value);
			}
			else
				ptr++;

			free(var_name);
		}
		else
			ptr++;
	}
}

/**
 * cleanup - Free allocated resources, if any.
 */
void cleanup()
{
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
}

/**
 * handle_special_characters - Escape specific characters in a string.
 * @string: The input string to process.
 */
void handle_special_characters(char *string)
{
	unsigned int j = 0;
	unsigned int i;
	char *escaped_string = (char *)malloc(strlen(string) * 2 + 1);

	if (escaped_string == NULL)
	{
		perror("handle_special_characters");
		exit(EXIT_FAILURE);
	}

	for (i = 0; string[i] != '\0'; ++i)
	{
		if (string[i] == '\\' && (string[i + 1] == '"'  string[i + 1] == '\''  string[i + 1] == '`'  string[i + 1] == '\\'  string[i + 1] == '*'  string[i + 1] == '&'  string[i + 1] == '#'))
		{
			escaped_string[j++] = string[++i];
		}
		else
			escaped_string[j++] = string[i];
	}
	escaped_string[j] = '\0';

	strcpy(string, escaped_string);
	free(escaped_string);
}
