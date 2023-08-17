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
	pid_t p;
	size_t n = 0;
	ssize_t l;
	int mode = isatty(0);
	unsigned int _cmd_count_ = 1;
	char **args, *_input_line_ = NULL, *_nospace_, *_str_cc_;

	signal(SIGINT, sigint_handler);
	signal(SIGTSTP, ststp_handler);

	(void)argc;
	(void)argv;

	errno = 0;

	printf(" %s ", _getenv("PATH"));

	while(1)
	{
		if (mode == 1)
		{
			if(write(STDOUT_FILENO, "$ ", 2) < 0)
			{
				perror("Write");
				exit(1);
			}
		}
		if ((l = getline(&_input_line_, &n, stdin)) == -1)
		{
			if (!_input_line_)
			{
				perror("Allocation failed");
				exit(1);
			}
			/*	if (errno != 0)
				{
				free(_input_line_);
				perror("Error");				exi(1);
				}*/
			if (mode == 1)
			{
				if(write(STDOUT_FILENO, "\n", 1) < 0)
				{
					perror("Write");
					free(_input_line_);
					exit(1);
				}
			}

			free(_input_line_);
			exit(0);
		}

		_input_line_[l - 1] = '\0';

		_nospace_ = _input_line_;

		while (*_nospace_ == '\t' || *_nospace_ == ' ')

		{
			_nospace_++;
		}

		args = inpToArray(_nospace_);

		if (_strcmp("exit", _nospace_) == 0)
		{
			if (errno != 0)
			{
				free(args);
				_nospace_ = NULL;
				free(_input_line_);
				_input_line_ = NULL;
				exit(0);
			}

			free(args);
			_nospace_ = NULL;
			free(_input_line_);
			_input_line_ = NULL;
			exit(0);
		}

		p = fork();

		if (p < 0)
		{
			perror("Fork");
			free(args);
			_nospace_ = NULL;
			free(_input_line_);
			exit(1);
		}

		if (p == 0) {
			_str_cc_ = int2str(_cmd_count_);


			if(*_nospace_ != '\0' && execve(_nospace_, args, env) == -1)
			{
				/if (write(STDOUT_FILENO, argv[0], _strlen(argv[0])) < 0 ||
				  write(STDOUT_FILENO, ": ", 2) < 0 ||
				  write(STDOUT_FILENO, _str_cc_, _strlen(_str_cc_)) < 0 ||
				  write(STDOUT_FILENO, ": ", 2) < 0 ||
				  write(STDOUT_FILENO, _nospace_, _strlen(_nospace_)) < 0 ||
				  write(STDOUT_FILENO, ": not found\n", 12) < 0)
				  {
				  perror("Write");
				  free(args);
				  _nospace_ = NULL;
				  free(_input_line_);
				  free(_str_cc_);
				  _str_cc_ = NULL;
				  _input_line_ = NULL;
				  exit(errno);
				  }*/
			}

			free(args);
			_nospace_ = NULL;
			free(_input_line_);
			free(_str_cc_);
			_str_cc_ = NULL;
			_input_line_ = NULL;
			exit(127);
		}
		else
		{
			if(wait(NULL) == -1)
			{
				perror("Wait");
				exit(1);
			}

			_cmd_count_++;
			free(args);
			_nospace_ = NULL;
			free(_input_line_);
			_input_line_ = NULL;
		}

	}

	return (0);
}
