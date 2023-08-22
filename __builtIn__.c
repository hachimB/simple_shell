#include "lib_funcs.h"

int __builtIn__(
    char ***_PATHDIR_, char ***args, char ***argv,
    char **path, char **_INPUT__, char **_str_cc_,
    unsigned int *_cmd_count_)
{
    if (_strcmp("exit", (*args)[0]) == 0)
    {
        if ((*args)[1])
        {
            if (str2int((*args)[1]) >= 0)
            {
                errno = str2int((*args)[1]);
                frees(&*_PATHDIR_, &*args, &*path, &*_INPUT__, NULL);
                exit(errno);
            }
            *_str_cc_ = int2str(*_cmd_count_);
            printerr(*argv[0], *_str_cc_, (*args)[0], ": Illegal number: ", (*args)[1]);
            frees(&*_PATHDIR_, &*args, &*path, &*_INPUT__, &*_str_cc_, NULL);
            errno = 2;
            return (1);
        }

        frees(&*_PATHDIR_, &*args, &*path, &*_INPUT__, NULL);
        exit(*_cmd_count_ != 1 ? errno : 0);
    }
    if (_strcmp("env", (*args)[0]) == 0)
    {
        d_env();
        errno = 0;
        frees(&*_PATHDIR_, &*args, &*path, &*_INPUT__, NULL);
        return (1);
    }

    return (0);
}
