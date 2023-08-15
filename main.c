#include "lib_funcs.h"

/**
 * main - Main function
 * @argc: Arguments count
 * @argv: Arguments
 * Return: 0 Success
 */

int main(int argc, char **argv, char **env)
{
        pid_t p;
        size_t n = 0;
        ssize_t l;
        char **args;

	char *_input_line_ = NULL, *_nospace_;

        signal(SIGINT, sigint_handler);
	signal(SIGTSTP, ststp_handler);

        if (argc != 1)
	{
                perror("Arguments Error");
                exit(2);
        }

        while(1)
        {
                if(write(STDOUT_FILENO, "$ ", 2) < 0)
                {
                        perror("Write");
                        exit(1);
                }

                if ((l = getline(&_input_line_, &n, stdin)) == -1)
                {
			if (!_input_line_)
			{
				perror("Allocation failed");
				exit(1);
			}
			if (errno != 0)
			{
				free(_input_line_);
				perror("Error");
				exit(1);
			}

                        if(write(STDOUT_FILENO, "\n", 1) < 0)
                        {
                                perror("Write");
				free(_input_line_);
                                exit(1);
                        }

                        free(_input_line_);
                        exit(0);
                }

                _input_line_[l - 1] = '\0';

		_nospace_ = _input_line_;

		while (*_nospace_ == ' ')
		{
			_nospace_++;
		}

                args = inpToArray(_nospace_);

                if (_strcmp("exit", _nospace_) == 0)
                {
                        free(args);
			_nospace_ = NULL;
                        free(_input_line_);
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
                        if(*_nospace_ != '\0' && execve(_nospace_, args, env) == -1)
                                perror(argv[0]);

                        free(args);
			_nospace_ = NULL;
                        free(_input_line_);
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

                        free(args);
			_nospace_ = NULL;
                        free(_input_line_);
                        _input_line_ = NULL;
                }

        }

                return (0);
}
