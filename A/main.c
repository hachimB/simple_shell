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
	unsigned int _cmd_count_ = 0;
	char **args, *_input_line_ = NULL, *_nospace_, *_str_cc_;

	signal(SIGINT, sigint_handler);
	signal(SIGTSTP, ststp_handler);

	(void)argc;
	(void)argv;

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
		_nospace_ = _input_line_;

		while (*_nospace_ == '\t' || *_nospace_ == ' ')
			_nospace_++;

		args = inpToArray(_nospace_);

		if (_strcmp("exit", _nospace_) == 0)
		{
			free_args(args);
			free(args);
			_nospace_ = NULL;
			free(_input_line_);
			_input_line_ = NULL;

			exit(errno);
		}
		else if (_strcmp("env", _nospace_) == 0)
		{
			d_env();
			_cmd_count_++;
			
			continue;
		}

		if (access(_nospace_, X_OK) == 0)
		{
			_pid = fork();
		}
		else
		{
			_cmd_count_++;

			if (*_nospace_ != '\0')
			{
				_str_cc_ = int2str(_cmd_count_);
				printerr(argv[0], _str_cc_, _nospace_);
				free(_str_cc_);
			}

			errno = 127;

			free_args(args);
			free(args);
			free(_input_line_);
			_nospace_ = _str_cc_ = _input_line_ = NULL;

			continue;
		}

		if (_pid < 0)
		{
			perror("Fork");
			free_args(args);
			free(args);
			free(_input_line_);
			_nospace_ = NULL;

			exit(EXIT_FAILURE);
		}

		if (_pid == 0)
		{
			if (execve(_nospace_, args, env) == -1)
			{
				free_args(args);
				free(args);
				free(_input_line_);
				free(_str_cc_);
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

		free_args(args);
		free(args);
		free(_input_line_);

		_input_line_ = _nospace_ = NULL;
	}

	return (0);
}
