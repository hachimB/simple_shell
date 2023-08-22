#include "lib_funcs.h"

/*
 * free_args - free args
 * @args: args
 */

void superFree_(char **_ARR_)
{
	char **a = _ARR_;

	while (*a)
	{
		free(*a);
		*a = NULL;
		a++;
	}

	free(_ARR_);
}

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
