#include "lib_funcs.h"
/**
 * d_env - displays the env.
 * Return: integer.
 */
int d_env(void)
{
int i = 0;
while (__environ[i] != NULL)
{
write(STDOUT_FILENO, __environ[i], _strlen(__environ[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
return (i);
}
