#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

extern char *_input_line_;
extern char **environ;

void sigint_handler(int signum);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char** inpToArray(char *inp);

#endif
