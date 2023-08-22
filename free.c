#include "lib_funcs.h"

/**
 * superFree_ - free args
 * @_ARR_: args
 * return: nothing.
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
