#include "lib_funcs.h"

/**
 * toArray - input to array
 * @str: str
 * @_sep_: separators
 * Return: array.
 */
char **toArray(char *str, char *_sep_)
{
char *_str = _strdup(str), *tokn, **arr;
int n = 0, c = 0;
if (!_str)
return (NULL);
tokn = NULL;
if (_strcmp(_str, "") != 0)
tokn = strtok(_str, _sep_);
while (tokn)
{
tokn = strtok(NULL, _sep_);
n++;
}
free(_str);
_str = _strdup(str);
if (!_str)
return (NULL);
if (_strcmp(_str, "") != 0)
tokn = strtok(_str, _sep_);
n = n ? n : 1;
arr = malloc(sizeof(char *) * (n + 1));
if (!arr)
return (NULL);
while (tokn)
{
arr[c] = _strdup(tokn);
if (!arr[c])
return (NULL);
tokn = strtok(NULL, _sep_);
c++;
}
arr[0] = c ? arr[0] : _strdup("");
arr[c ? c : 1] = (char *)NULL;
free(_str);
return (arr);
}
