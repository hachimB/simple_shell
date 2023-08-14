#include "main.h"
/**
 * main - Main function
 * @argc: Arguments count
 * @argv: Arguments
 * Return: 0 Success
 */

extern **environ;

char *_input_line_;

void initializeGlobals() {
    _input_line_ = NULL;
}

int main(int argc, char **argv)
{
        pid_t p;
        size_t n = 0;
        ssize_t l;
        char **args;

	initializeGlobals();

        signal(SIGINT, sigint_handler);

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
                        if(write(STDOUT_FILENO, "\n", 1) < 0)
                        {
                                perror("Write");
                                exit(1);
                        }

                        free(_input_line_);
                        exit(1);
                }

                _input_line_[l - 1] = '\0';

                args = inpToArray(_input_line_);

                if (_strcmp("exit", _input_line_) == 0)
                {
                        free(args);
                        free(_input_line_);
                        exit(0);
                }

                p = fork();

                if (p < 0)
                {
                        perror("Fork");
                        free(args);
                        free(_input_line_);
                        exit(1);
                }

                if (p == 0) {
                        if(execve(_input_line_, args, environ) == -1)
                                perror(argv[0]);

                        free(args);
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
                        free(_input_line_);
                        _input_line_ = NULL;
                }

        }

                return (0);
}
