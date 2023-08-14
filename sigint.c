#include "main.h"
/**
 * sigint_handler - handle the sigint.
 * @signum: integer
 * Return: nothing.
 */
void sigint_handler(int signum)
{
char *lineptr = NULL;
(void)signum;
if (lineptr)
{
free(lineptr);
lineptr = NULL;
}
write(STDOUT_FILENO, "\n", 1);
exit(1);
}
