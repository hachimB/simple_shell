#include "strfunc.h"
/**
 * _sterlen - return the number of element of string.
 * @s: string
 * Return: integer.
 */
int _strlen(char *s)
{
int i = 0;
while (s[i] != '\0')
i++;
return (i);
}
