#include "hsh.h"

/**
 * tokenize_command - Tokenize the given command into an array of arguments.
 * @command: The command string to tokenize.
 * @args: An array to store the resulting arguments.
 */
void tokenize_command(char *command, char *args[])
{
    int i = 0;
    char *token = _strtok(command, " ");

    while (token != NULL)
    {
        args[i++] = token;
        token = _strtok(NULL, " ");
    }

    args[i] = NULL;
}
