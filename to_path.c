#include "lib_funcs.h"

/**
 * toaPath - cmd2path
 * @cmd: cmd
 * Return: path
 */

char *toaPath(char *cmd)
{
char *_PATH = _strdup(_getenv("PATH")),
**_PATHDIR_;
_PATHDIR_ = toArray(_PATH, ":");
while (*_PATHDIR_)
{
_strcat(*_PATHDIR_, "/");
_strcat(*_PATHDIR_, cmd);
if (access(*_PATHDIR_, F_OK) == 0)
return (*_PATHDIR_);
_PATHDIR_++;
}
return (cmd);
}
