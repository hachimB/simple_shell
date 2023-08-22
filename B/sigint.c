#include "lib_funcs.h"
/**
 * sigint_handler - handle sigint.
 * @signum: integer.
 * Return: nothing.
 */
void sigint_handler(int signum)
{
(void)signum;
write(STDOUT_FILENO, "\n$ ", 3);
fflush(stdout);
}
