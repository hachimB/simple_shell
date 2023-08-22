#include "lib_funcs.h"
/**
 * _strcpy - copy a string in another.
 *
 *@dest : first string.
 *
 *@src : second string.
 *
 * Return: a string.
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;
while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}
