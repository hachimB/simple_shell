#include "strfunc.h"

/**
 * inpToArray - input to array
 * @input: Input
 * Return: arr
 */

char **inpToArray(char *inp)
{
char *_sp = " ", *i = inp, *tokn, **arr;
int n = 1, c = 0;
while (*i)
{
if (*i == ' ')
n++;
i++;
}
tokn = strtok(inp, _sp);
arr = malloc(sizeof(char *) * (n + 1));
while (tokn)
{
arr[c] = tokn;
c++;
tokn = strtok(NULL, _sp);
}
arr[0] = inp;
arr[c != 0 ? c : 1] = NULL;
return (arr);
}
