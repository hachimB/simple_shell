#include "lib_funcs.h"

/**
 * inpToArray - input to array
 * @inp: Input
 * Return: arr
 */

char **inpToArray(char *inp)
{
char *_sp = " \t", *i = inp, *in = inp, *tokn, **arr;
int n = 1, c = 0;
while (*i)
{
if ((*i == ' ' && *(i + 1) != ' ' && *(i + 1) != '\0')
|| (*i == '\r' && *(i + 1) != ' ' && *(i + 1) != '\0')
|| (*i == '\t' && *(i + 1) != ' ' && *(i + 1) != '\0')
|| (*i == '\n' && *(i + 1) != ' ' && *(i + 1) != '\0'))
n++;
i++;
}
tokn = strtok(in, _sp);
arr = malloc(sizeof(char *) * (n + 1));
while (tokn)
{
arr[c] = tokn;
c++;
tokn = strtok(NULL, _sp);
}
arr[0] = in;
arr[c != 0 ? c : 1] = NULL;
return (arr);
}
