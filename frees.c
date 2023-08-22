#include "lib_funcs.h"
/**
 * frees - variadic function that frees args.
 * @ARGS: args.
 * @PDIR: pdir
 * @path: path
 * Return: nothing.
 */
void frees(char ***PDIR, char ***ARGS, char **path, ...)
{
char **farg;
va_list vl;
va_start(vl, path);
superFree_(*PDIR);
*PDIR = (char **)NULL;
free(*path);
*path = NULL;
superFree_(*ARGS);
*ARGS = (char **)NULL;
farg = va_arg(vl, char **);
while (farg)
{
free(*farg);
*farg = NULL;
farg = va_arg(vl, char **);
}
va_end(vl);
}
