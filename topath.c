#include "lib_funcs.h"

/**
 * toPath - converts to path.
 * @_PDIR_: _PDIR_.
 * @cmd: command.
 * @_notValidCMD_: not valid command.
 * Return: a string.
 */

char *toPath(char **_PDIR_, char *cmd, int *_notValidCMD_)
{
char **_PATHDIR_ = _PDIR_, *_CONC;
while (*_PATHDIR_)
{
_CONC = malloc(_strlen(*_PATHDIR_) + _strlen(cmd) + 2);
if (!_CONC)
return (NULL);
strcpy(_CONC, *_PATHDIR_);
strcat(_CONC, "/");
strcat(_CONC, cmd);
if (access(_CONC, F_OK) == 0)
{
*_notValidCMD_ = 1;
return (_CONC);
}
free(_CONC);
_CONC = NULL;
_PATHDIR_++;
}
_CONC = strdup(cmd);
*_notValidCMD_ = 0;
return (_CONC);
}
