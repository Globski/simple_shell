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
char *_strcat(char *d, char *s);
int handle_env(void);

#endif /* #ifndef HSH_H */
