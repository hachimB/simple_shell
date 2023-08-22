#include "lib_funcs.h"

/**
 * main - Main function
 * @argc: Arguments count
 * @argv: Arguments
 * @env: Enviremnt variables
 * Return: 0 Success
 */


int main(int argc, char **argv, char **env)
{
pid_t _pid;
size_t n = 0;
ssize_t l;
int mode = isatty(0), _status, _ch_exit_status;
unsigned int _cmd_count_ = 0, envLen = 0;
char **args, *_INPUT__ = NULL, *_str_cc_;
char *_PATH = _getenv("PATH") ? _getenv("PATH") : "_";
char **_PATHDIR_, *path;
signal(SIGINT, sigint_handler);
signal(SIGTSTP, ststp_handler);
(void)argc;
while (1)
{
if (mode)
write(STDOUT_FILENO, "$ ", 2);
l = getline(&_INPUT__, &n, stdin;
if (l == -1)
{
if (mode)
write(STDOUT_FILENO, "\n", 1);
free(_INPUT__);
exit(errno);
}
while (*env)
{
envLen++, env++;
}
args = toArray(_INPUT__, " \t\n");
_PATHDIR_ = toArray(_PATH, ":");
path = toPath(_PATHDIR_, args[0]);
_cmd_count_++;
if (_strcmp("exit", args[0]) == 0)
{
if (args[1])
{
if (str2int(args[1]) >= 0)
{
errno = str2int(args[1]);
frees(_PATHDIR_, args, path, _INPUT__, NULL);
_PATHDIR_ =  args = (char **)NULL;
path = _INPUT__ = (char *)NULL;
exit (errno);
}
_str_cc_ = int2str(_cmd_count_);
printerr(argv[0], _str_cc_, args[0], ": Illegal number: ", args[1]);
frees(_PATHDIR_, args, path, _INPUT__, _str_cc_, NULL);
_PATHDIR_ =  args = (char **)NULL;
path = _INPUT__ = _str_cc_ = (char *)NULL;
errno = 2;
continue;
}
frees(_PATHDIR_, args, path, _INPUT__, NULL);
_PATHDIR_ =  args = (char **)NULL;
path = _INPUT__ = (char *)NULL;
exit(_cmd_count_ != 1 ? errno : 0);
}
if (_strcmp("env", args[0]) == 0)
{
d_env();
errno = 0;
continue;
}
if (access(path, F_OK) != 0 || *args[0] == '\0')
{
errno = 0;
if (*args[0] != '\0')
{
_str_cc_ = int2str(_cmd_count_);
printerr(argv[0], _str_cc_, args[0], ": not found", NULL);
free(_str_cc_);
_str_cc_ = NULL;
errno = 127;
}
frees(_PATHDIR_, args, path, _INPUT__, NULL);
_PATHDIR_ = args = (char **)NULL;
path = _INPUT__ = (char *)NULL;
continue;
}
_pid = fork();
if (_pid < 0)
{
perror("Fork"), frees(_PATHDIR_, args, path, _INPUT__, NULL);
_PATHDIR_ =  args = (char **)NULL;
path = _INPUT__ = _str_cc_ = (char *)NULL;
exit(EXIT_FAILURE);
}
if (_pid == 0)
{
if (execve(path, args, env) == -1)
{
frees(_PATHDIR_, args, path, _INPUT__, NULL);
_PATHDIR_ =  args = (char **)NULL;
path = _INPUT__ = (char *)NULL;
exit(2);
}
}
wait(&_status);
if (WIFEXITED(_status))
_ch_exit_status = WEXITSTATUS(_status);
errno = _ch_exit_status;
frees(_PATHDIR_, args, path, _INPUT__, NULL);
_PATHDIR_ =  args = (char **)NULL;
path = _INPUT__ = (char *)NULL;
}
return (0);
}
