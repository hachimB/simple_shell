#include "lib_funcs.h"
/**
 * sigint_handler - handle sigint.
 * @sigint: integer.
 * Return: nothing.
 */
void sigint_handler(int signum)
{
char *lineptr = NULL;
(void)signum;
if (lineptr)
free(lineptr);
write(STDOUT_FILENO, "\n", 1);
exit(1);
}
