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

extern char **environ;

/* STR FUNCTIONS */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int str2int(char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *int2str(unsigned int n);

/* SIGNAL HANDLING FUNCTIONS */
void sigint_handler(int signum);
void ststp_handler(int signum);

/* COMMAND HANDLING/CONVERTING-TO-ARRAY FUNCTIONS */
char **inpToArray(char *inp);
char **toArray(char *str, char *_sep_);
char *toPath(char **_PDIR_, char *cmd, int *_notValidCMD_);
char *onlyCMD(char *_cmd);

/* ENVIRONMENT VARIABLES FUNCTIONS*/
int d_env(void);
char *_getenv(const char *name);

/* PRINTING ERROR's */
void printerr(char *prgm, char *cmd_C, char *cmd, char *err, char *err1);

/* MEMORY FREEING FUNCTIONS */
void superFree_(char **_ARR_);
void frees(char ***PDIR, char ***ARGS, char **path, ...);

/** CODE ASSEMBLING FUNCTIONS **/
int __builtIn__(
char ***_PATHDIR_, char ***args, char ***argv,
char **path, char **_INPUT__, char **_str_cc_,
unsigned int *_cmd_count_);

void __startForkin__(
pid_t *_pid,
char ***_PATHDIR_, char ***args, char ***env,
char **path, char **_INPUT__,
int *_status, int *_ch_exit_status);

int __handleInvalidCMD__(
char ***_PATHDIR_, char ***args, char ***argv,
char **path, char **_str_cc_, char **_INPUT__, char **_PATH,
int *isValidCMD, unsigned int *_cmd_count_);

#endif