#include "hsh.h"

/**
 * _strlen - calculates the length of a string.
 * @s: pointer to the string.
 * Return: length of the string.
 */
int _strlen(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;

	return (len)
}

int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return (*s1 - *s2);
	}
	return (0);
}
