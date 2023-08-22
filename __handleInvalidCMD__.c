#include "lib_funcs.h"

int __handleInvalidCMD__(
    char ***_PATHDIR_, char ***args, char ***argv,
    char **path, char **_str_cc_, char **_INPUT__, char **_PATH,
    int *isValidCMD,
    unsigned int *_cmd_count_)
{
    if (access(*path, F_OK) != 0 || *(*args)[0] == '\0' 
    || (_strcmp(*_PATH, "_") == 0 && **path != '/' && !*isValidCMD))
    {
        errno = 0;
        if (*(*args)[0] != '\0')
        {
            *_str_cc_ = int2str(*_cmd_count_);
            printerr((*argv)[0], *_str_cc_, (*args)[0], ": not found", NULL);
            free(*_str_cc_), *_str_cc_ = NULL;
            errno = 127;
        }
        frees(&*_PATHDIR_, &*args, &*path, &*_INPUT__, NULL);
        return (1);
    }
    return (0);
}
