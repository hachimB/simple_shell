#include "lib_funcs.h"

/**
 * inpToArray - input to array
 * @inp: Input
 * Return: arr
 */

char **toArray(char *str, char *_sep_)
{
    char *_str = strdup(str), *tokn, **arr;
    int n = 0, c = 0;

    if (!_str)
        return (NULL);

    tokn = NULL;

    if (strcmp(_str, "") != 0)
        tokn = strtok(_str, _sep_);
   

    while (tokn)
    {
        tokn = strtok(NULL, _sep_);
        n++;
    }

    free(_str);

    _str = strdup(str);
    if (!_str)
        return (NULL);

    if (strcmp(_str, "") != 0)
        tokn = strtok(_str, _sep_);

    n = n ? n : 1;

    arr = malloc(sizeof(char *) * (n + 1));
    if (!arr)
        return (NULL);

    while (tokn)
    {
        arr[c] = strdup(tokn);
        if (!arr[c])
            return (NULL);

        tokn = strtok(NULL, _sep_);
        c++;
    }

    arr[0] = c ? arr[0] : strdup("");
    arr[c ? c : 1] = (char *)NULL;

    free(_str);
    return (arr);
}

char *toPath(char **_PDIR_, char *cmd)
{
    char **_PATHDIR_ = _PDIR_, *_CONC;

    while (*_PATHDIR_)
    {
        _CONC = malloc(_strlen(*_PATHDIR_) + _strlen(cmd) + 2);
        if (!_CONC) return (NULL);

        strcpy(_CONC, *_PATHDIR_);
        strcat(_CONC, "/");
        strcat(_CONC, cmd);

        if (access(_CONC, F_OK) == 0)
            return (_CONC);

        free(_CONC);
        _CONC = NULL;
        _PATHDIR_++;
    }
    _CONC = strdup(cmd);

    return (_CONC);
}
