#include "lib_funcs.h"

void __startForkin__(
    pid_t *_pid,
    char ***_PATHDIR_, char ***args, char ***env,
    char **path, char **_INPUT__,
    int *_status, int *_ch_exit_status)
{
    *_pid = fork();
    if (*_pid < 0)
        perror("Fork"), frees(&*_PATHDIR_, &*args, &*path, &*_INPUT__, NULL), exit(EXIT_FAILURE);
    if (*_pid == 0)
    {
        if (execve(*path, *args, *env) == -1)
            perror("perror"), frees(&*_PATHDIR_, &*args, &*path, &*_INPUT__, NULL), exit(2);
    }
    wait(&*_status);
    if (WIFEXITED(*_status))
        *_ch_exit_status = WEXITSTATUS(*_status);
    errno = *_ch_exit_status;
    frees(&*_PATHDIR_, &*args, &*path, &*_INPUT__, NULL);
}
