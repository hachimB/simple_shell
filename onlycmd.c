#include "lib_funcs.h"

/**
 * onlyCMD - only command
 * @_cmd: command
 * Return: command(string).
 */
char *onlyCMD(char *_cmd)
{
char *cmd = _cmd;
if (*cmd != '/')
return (cmd);
cmd += _strlen(cmd) - 1;
while (*cmd != '/')
cmd--;
cmd++;
return (cmd);
}
