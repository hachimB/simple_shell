#include "lib_funcs.h"

/**
 * toPath - converts to path.
 * @_PDIR_: _PDIR_.
 * @cmd: command.
 * Return: a string.
 */
char *toPath(char **_PDIR_, char *cmd)
{
char **_PATHDIR_ = _PDIR_, *_CONC;
while (*_PATHDIR_)
{
_CONC = malloc(_strlen(*_PATHDIR_) + _strlen(cmd) + 2);
if (!_CONC)
return (NULL);
_strcpy(_CONC, *_PATHDIR_);
_strcat(_CONC, "/");
_strcat(_CONC, cmd);
if (access(_CONC, F_OK) == 0)
return (_CONC);
free(_CONC);
_CONC = NULL;
_PATHDIR_++;
}
_CONC = _strdup(cmd);
return (_CONC);
}
