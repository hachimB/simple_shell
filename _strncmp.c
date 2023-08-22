#include "lib_funcs.h"
/**
 * _strncmp - compares two strings.
 * @s1: first string.
 * @s2: second string.
 * @n: number of elements to compare.
 * Return: an integer.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
size_t i;
for (i = 0; i < n; i++)
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
if (s1[i] == '\0')
return (0);
}
return (0);
}
