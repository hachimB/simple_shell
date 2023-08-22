#include "lib_funcs.h"
/**
 * _getenv - displays the environment.
 * @name: string.
 * Return: a string.
 */

char *_getenv(const char *name)
{
size_t name_length;
int i;
char *c_env;
if (name == NULL || environ == NULL)
{
return (NULL);
}
name_length = strlen(name);
for (i = 0; environ[i] != NULL; i++)
{
c_env = environ[i];
if (_strncmp(c_env, name, name_length) == 0 && c_env[name_length] == '=')
{
return (c_env + name_length + 1);
}
}
return (NULL);
}
