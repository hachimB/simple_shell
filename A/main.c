#include "lib_funcs.h"

/**
 * main - Main function
 * @argc: Arguments count
 * @argv: Arguments
 * @env: Enviremnt variables
 * Return: 0 Success
 */

void frees(char **args, ...)
{
	char *farg;

	va_list vl;
	va_start(vl, args);

	if (args)
		free_args(args);

	farg = va_arg(vl, char *);

	while (farg)
	{
		free(farg);
		farg = va_arg(vl, char *);
	}

	va_end(vl);
}

int main(int argc, char **argv, char **env)
{
	pid_t _pid;
	size_t n = 0;
	ssize_t l;
	int mode = isatty(0), _status, _ch_exit_status, _ = 0;
	unsigned int _cmd_count_ = 0;
	char **args, *_input_line_ = NULL, *_nospace_, *_str_cc_;

	signal(SIGINT, sigint_handler);
	signal(SIGTSTP, ststp_handler);
	(void)argc;
	while (1)
	{
		if (mode)
		{
			if (write(STDOUT_FILENO, "$ ", 2) < 0)
			{
				perror("Write");
				continue;
			}
		}
		if ((l = getline(&_input_line_, &n, stdin)) == -1)
		{
			if (!_input_line_)
			{
				perror("Allocation failed");
				_input_line_ = NULL;
				continue;
			}
			if (mode)
			{
				if (write(STDOUT_FILENO, "\n", 1) < 0)
				{
					perror("Write");
					free(_input_line_);
					continue;
				}
			}
			free(_input_line_);
			exit(errno);
		}

		_input_line_[l - 1] = '\0';

		while (_input_line_[_] != '\0' && _input_line_[_] != '#')
			_++;

		_input_line_[_] = '\0';

		_nospace_ = _input_line_;
		while (*_nospace_ == '\t' || *_nospace_ == ' ')
			_nospace_++;

		args = inpToArray(_nospace_);
		_cmd_count_++;

		if (_strcmp("exit", _nospace_) == 0)
		{
			frees(args, args, _input_line_, NULL);
			_input_line_ = NULL;
			exit(_cmd_count_ ? errno : 0);
		}
		else if (_strcmp("env", _nospace_) == 0)
		{
			d_env(env);
			continue;
		}
		if (access(_nospace_, X_OK) == 0)
		{
			_pid = fork();
		}
		else
		{
			errno = 0;

			if (*_nospace_ != '\0')
			{
				_str_cc_ = int2str(_cmd_count_);
				printerr(argv[0], _str_cc_, _nospace_);
				free(_str_cc_);
				errno = 127;
			}
			frees(args, args, _input_line_, NULL);
			_nospace_ = _str_cc_ = _input_line_ = NULL;
			continue;
		}
		if (_pid < 0)
		{
			perror("Fork");
			frees(args, args, _input_line_, NULL);
			_nospace_ = NULL;
			exit(EXIT_FAILURE);
		}
		if (_pid == 0)
		{
			if (execve(_nospace_, args, env) == -1)
			{
				frees(args, args, _input_line_, _str_cc_, NULL);
				_nospace_ = _str_cc_ = _input_line_ = NULL;
				exit(2);
			}
		}
		if (wait(&_status) == -1)
		{
			perror("Wait");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(_status))
		{
			_ch_exit_status = WEXITSTATUS(_status);
		}
		errno = _ch_exit_status;
		frees(args, args, _input_line_, NULL);
		_input_line_ = _nospace_ = NULL;
	}

	return (0);
}
