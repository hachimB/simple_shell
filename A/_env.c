#include "lib_funcs.h"
/**
 * d_env - displays the env.
 * Return: nothing.
 */
void d_env(void)
{
    int i = 0;
    while (environ[i] != NULL)
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}
