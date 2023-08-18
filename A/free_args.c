#include "lib_funcs.h"

/*
 * free_args - free args
 * @args: args
 */

 void free_args(char **args)
 {
    char **a = args;
    
    while (*a)
    {
        free(*a);
        a++;
    }
 }