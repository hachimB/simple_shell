#include "lib_funcs.h"
/**
 * _strdup - duplicate a string.
 * @s: string
 * Return: a string.
 */
char *_strdup(const char *s)
{
size_t i = 0;
size_t j = 0;
char *dup;
while (s[i] != '\0')
i++;
dup = malloc(i + 1);
if (dup == NULL)
return (NULL);
else
{
for (j = 0; j < (i + 1); j++)
dup[j] = s[j];
}
return (dup);
}
