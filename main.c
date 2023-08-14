#include "main.h"
/**
 * main - Main function
 * @argc: Arguments count
 * @argv: Arguments
 * Return: 0 Success
 */
int main(int argc, char **argv)
{
        pid_t p;
        size_t n = 0;
        ssize_t l;
	char *lineptr = NULL;
        char **args, *env[1] = {NULL};

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

                if ((l = getline(&lineptr, &n, stdin)) == -1)
                {
                        if(write(STDOUT_FILENO, "\n", 1) < 0)
                        {
                                perror("Write");
                                exit(1);
                        }

                        free(lineptr);
                        exit(1);
                }

                lineptr[l - 1] = '\0';

                args = inpToArray(lineptr);

                if (_strcmp("exit", lineptr) == 0)
                {
                        free(args);
                        free(lineptr);
                        exit(0);
                }

                p = fork();

                if (p < 0)
                {
                        perror("Fork");
                        free(args);
                        free(lineptr);
                        exit(1);
                }

                if (p == 0) {
                        /*args[0] = lineptr;
                        args[1] = NULL;*/

                        if(execve(lineptr, args, env) == -1)
                                perror(argv[0]);

                        free(args);
                        free(lineptr);
                        lineptr = NULL;
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
                        free(lineptr);
                        lineptr = NULL;
                }

        }

                return (0);
}
