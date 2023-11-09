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

	return (len);
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

/**
 * _strcat - Concatenates two strins.
 * @s: source string.
 * @d: destination string.
 * Return: pointer to the appended string.
 */
char *_strcat(char *d, char *s)
{
	int i, len;

	len = _strlen(d);
	for (i = 0; s[i] != '\0'; i++)
	{
		d[len + i] = s[i];
	}
	d[len + _strlen(s)] = '\0';

	return (d);
}

/**
 * _strchr - locates a character in a string.
 * @s: pointer to the string.
 * @c: character to be located.
 * Return: pointer to the manipulated string.
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s != c)
			s++;
		if (*s == c)
			return (s);
	}
	return (NULL);
}
