#include "hsh.h"

/**
 * _strtok - tokenizes a string.
 * @str: the string to be tokenized.
 * @delim: the delimiter.
 * Return: the tokenized string.
 */
char *_strtok(char *str, const char *delim)
{
	static char *nextToken = NULL;
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
	ptr = malloc(sizeof(char ) * _strlen(nextToken) + 1);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; nextToken[i] && strchr(delim, nextToken[i]) == NULL; i++)
		ptr[i] = nextToken[i];
	ptr[i] = '\0';
	nextToken += 1;
	return (ptr);
}
