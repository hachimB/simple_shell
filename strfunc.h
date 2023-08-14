#ifndef STRFUNCS_H
#define STRFUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char **inpToArray(char *inp);
void sigint_handler(int signum);

#endif
