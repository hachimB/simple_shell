#ifndef LIB_FUNCS_H
#define LIB_FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

extern char **environ;
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char **inpToArray(char *inp);
void sigint_handler(int signum);
void ststp_handler(int signum);
char *int2str(unsigned int n);
char *_getenv(const char *name);

#endif
