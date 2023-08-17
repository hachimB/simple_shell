#include "lib_funcs.h"
/**
 * _getenv - displays the environment.
 * @name: string.
 * Return: a string.
 */
char *_getenv(const char *name)
{
int i = 0;
char *c_env = environ[i];
char *var;
char *val;
for (i = 0; environ[i] != NULL; i++)
{
c_env = environ[i];
var = strtok(c_env, "=");
val = strtok(NULL, "=");
if (var != NULL && val != NULL)
{
if (_strcmp(var, (char *)name) == 0)
return (val);
}
}
return (NULL);
}
