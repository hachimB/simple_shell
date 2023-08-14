#include "main.h"
/**
 * sigint_handler - handle the sigint.
 * @signum: integer
 * Return: nothing.
 */
void sigint_handler(int signum)
{
(void)signum;
if (_input_line_)
free(_input_line_);
write(STDOUT_FILENO, "\n", 1);
exit(1);
}
