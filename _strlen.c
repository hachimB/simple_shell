#include "main.h"
/**
 * _strlen - counts the number of elements of the string.
 *
 *@s: string.
 *
 * Return: an integer.
 */
int _strlen(char *s)
{
int i = 0;
while (s[i] != '\0')
i++;
return (i);
}
