#include "lib_funcs.h"

/**
 * main - Main function
 * @argc: Arguments count
 * @argv: Arguments
 * @env: Environment variables
 * Return: 0 Success
 */

int main(int argc, char **argv, char **env)
{
	pid_t _pid;
	size_t iptl = 0;
	ssize_t __length;
	int _MODE_ = isatty(0), _status, _ch_exit_status, isValidCMD = 0;
	unsigned int _cmdsCount_ = 0, _ = 1;
	char **_args__, **_PATHDIR_, *_path__,
		*_INPUT__ = NULL, *_str_cc_, *PATH_ = _getenv("PATH") ? _getenv("PATH") : "_";

	(void) argc;

	signal(SIGINT, sigint_handler), signal(SIGTSTP, ststp_handler);

	while ( !!_++ )
	{
		if (_MODE_) write(STDOUT_FILENO, "$ ", 2);
		if ((__length = getline(&_INPUT__, &iptl, stdin)) == -1)
		{
			if (_MODE_) write(STDOUT_FILENO, "\n", 1);
			free(_INPUT__), exit(errno);
		}
		_args__ = toArray(_INPUT__, " \t\n"), _PATHDIR_ = toArray(PATH_, ":");
		_path__ = toPath(_PATHDIR_, _args__[0], &isValidCMD);
		_cmdsCount_++;

		if (__builtIn__(&_PATHDIR_, &_args__, &argv, &_path__, &_INPUT__, &_str_cc_, &_cmdsCount_)
		|| __handleInvalidCMD__(&_PATHDIR_,&_args__,&argv,&_path__,&_str_cc_,
		&_INPUT__,&PATH_,&isValidCMD,&_cmdsCount_))
			continue;

		__startForkin__(
			&_pid,
			&_PATHDIR_, &_args__, &env,
			&_path__, &_INPUT__,
			&_status, &_ch_exit_status);
	}
	return (0);
}
