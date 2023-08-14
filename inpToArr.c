#include <string.h>
#include <stdlib.h>

/**
 * inpToArray - input to array
 * @input: Input
 * Return: arr
 */

char **inpToArray(char *inp)
{
	char *_sp = " ", *i = inp, *tokn, **arr;
	int n = 1, c = 0;

	while (*i)
	{
		if (*i == ' ')
			n++;
		i++;
	}

	tokn = strtok(inp, _sp);

	arr = malloc(sizeof(char) * (n + 1));

	while (tokn)
	{
		arr[c] = tokn;
		tokn = strtok(NULL, _sp);
		c++;
	}
	arr[c] = NULL;

	return (arr);
}
