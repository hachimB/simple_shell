#include "main.h"

/**
 * inpToArray - input to array
 * @inp: Input
 * Return: arr
 */

char **inpToArray(char *inp)
{
        char *_sp = " ", *i = inp, *tokn, **arr;
        int n = 1, c = 0;

        while (*i)
        {
                if (*i == ' ' && *(i + 1) != ' ' && *(i + 1) != '\0')
                        n++;
                i++;
        }

        tokn = strtok(inp, _sp);

        arr = malloc(sizeof(char *) * (n + 1));
	
	if (!arr)
		return (NULL);

        while (tokn)
        {
                arr[c] = tokn;
                c++;
                tokn = strtok(NULL, _sp);
        }
        arr[0] = inp;
        arr[c != 0 ? c : 1] = NULL;

        return (arr);
}
