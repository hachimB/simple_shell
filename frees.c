#include "lib_funcs.h"
/**
 * frees - variadic function that frees args.
 * @args: args.
 * Return: nothing.
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
