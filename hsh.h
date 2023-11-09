#ifndef HSH_H
#define HSH_H

/**
 * Description - Header file containing all function prototype used in the
 *               simple shell project.
 */

#include <stdio.h>
#include <stddef.h>

extern char **environ;

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *d, char *s);
char *_strcat(char *d, char *s);
char *_strchr(char *s, char c);
int handle_env(void);
void handle_exit(char *args);

#endif /* #ifndef HSH_H */
