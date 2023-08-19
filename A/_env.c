#include "lib_funcs.h"
/**
 * d_env - displays the env.
 * Return: nothing.
 */
int d_env(char **env)
{
    int i = 0;
    while (env[i] != NULL)
    {
         write(STDOUT_FILENO, env[i], _strlen(env[i]));
        write(STDOUT_FILENO, "\n", 1);

        i++;
    }

    return (i);
}
