#ifndef LIB_FUNCS_H
#define LIB_FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>

extern char **__environ;
extern char **environ;

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(const char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
void sigint_handler(int signum);
void ststp_handler(int signum);
char *int2str(unsigned int n);
int str2int(char *str);
char **inpToArray(char *inp);
char *_getenv(const char *name);
void printerr(char *prgm, char* cmd_C, char *cmd, char *err, char *err1);
void superFree_(char **_ARR_);
int d_env();
char **toArray(char *str, char *_sep_);
char *toPath(char **_PDIR_, char *cmd, int *_notValidCMD_);
char *onlyCMD(char *_cmd);

#endif
