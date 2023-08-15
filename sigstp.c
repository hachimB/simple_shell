#include "lib_funcs.h"
/**
 * ststp_handler - handle sigstp.
 * @signum: integer.
 * Return: nothing.
 */
void ststp_handler(int signum)
{
(void)signum;
write(STDOUT_FILENO, "", 0);
fflush(stdout);
}
