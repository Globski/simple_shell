#include "hsh.h"

/**
 * handle_path - Locates and executes a command in the PATH environment
 * @command: The command to locate and execute
 *
 * Description: This function checks if the provided command is an absolute
 * path. If yes, it attempts to execute the command. If the command is not
 * found or not executable, an error message is displayed. If the command is
 * not an absolute path, the function searches for it in the directories listed
 * in the PATH environment variable. If found, the command is executed;
 * otherwise, an error message is displayed. The function also handles
 * cases where the PATH environment variable is not set.
 */

void handle_path(char *command)
{
        if (command[0] == '/')
        {
                if (access(command, X_OK) == 0)
                {
                        char *args[] = {command, NULL};
                        execve(command, args, environ);

                        perror("execve");
                        exit(EXIT_FAILURE);
                }
                else
                {
                        fprintf(stderr, "Error: Command not found: %s\n", command);
                        return;
                }
        }

        char *path = getenv("PATH");
        if (path == NULL)
        {
                fprintf(stderr, "Error: PATH environment variable not set\n");
                return;
        }

        char *path_copy = strdup(path);
        if (path_copy == NULL)
        {
                perror("strdup");
                exit(EXIT_FAILURE);
        }

        char *dir = _strtok(path_copy, ":");
        while (dir != NULL)
        {
                char full_path[BUFFER_SIZE];
                snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);

                if (access(full_path, X_OK) == 0)
                {
                        char *args[] = {full_path, NULL};
                        execve(full_path, args, environ);

                        perror("execve");
                        exit(EXIT_FAILURE);
                }

                dir = _strtok(NULL, ":");
        }

        fprintf(stderr, "Error: Command not found: %s\n", command);

        free(path_copy);
}
