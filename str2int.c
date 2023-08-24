#include "lib_funcs.h"

/**
 * str2int - str to int
 * @str: str
 * Return: int
*/

int str2int(char *str)
{
char *s = str;
int t = 1, sum = 0;
while (*s)
{
s++;
}
s--;
while (*s != *str)
{
if (*s < '0' || *s > '9')
return (-1);
sum += (*s - 48) * t;
t *= 10;
s--;
}
return (sum);
}
