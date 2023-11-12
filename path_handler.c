#include "hsh.h"

/**
 * handle_path - Locate and update the command path if not an absolute path.
 * @args: Array of strings representing the command and its arguments.
 *
 * Description: This function checks if the command in args[0] is an absolute path. If not,
 * it searches through the directories in the PATH environment variable to find
 * the executable and updates args[0] accordingly. If the executable is found,
 * the function modifies the args array with the full path.
 *
 * Returns: None
 */
void handle_path(char **args)
{
	char *path, *path_copy, *dir, *full_path;

	if (strchr(args[0], '/') == NULL)
	{
		path = getenv("PATH");
		if (path != NULL)
		{
			path_copy = strdup(path);
			dir = strtok(path_copy, ":");
			while (dir != NULL)
			{
				full_path = malloc(strlen(dir) + strlen(args[0]) + 2);
				strcpy(full_path, dir);
				strcat(full_path, "/");
				strcat(full_path, args[0]);

				if (access(full_path, X_OK) == 0)
				{
					free(args[0]);
					args[0] = full_path;
					free(path_copy);
					return;
				}
				free(full_path);
				dir = strtok(NULL, ":");
			}
			free(path_copy);
		}
		fprintf(stderr, "%s: command not found\n", args[0]);
	}
}
