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

/**
 * _strcmp - compares two string.
 * @s1: pointer to the first string.
 * @s2: pointer to the second string.
 * Return: difference of the length of both string, otherwise 0.
 */
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

/**
 * _strcpy - copies a string pointed to by s including the '\0' to a buffer pointerd to by d.
 * @d: destination pointer.
 * @s: source pointer.
 * Return: pointer to the newly copied string.
 */
char *_strcpy(char *d, char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';

	return (d);
}
