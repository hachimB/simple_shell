#ifndef STRFUNCS_H
#define STRFUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

char *lineptr = NULL;

/**
 * inpToArray - input to array
 * @input: Input
 * Return: arr
 */

int _strcmp(char *s1, char *s2)
{
        int i = 0;
        while (s1[i] != '\0' && s2[i] != '\0')
        {
                if (s1[i] != s2[i])
                        return (s1[i] - s2[i]);
                i++;
        }

        if (s1[i] != '\0')
                return (1);

        else if (s2[i] != '\0')
                return (-1);

        return (0);
}

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

        arr = malloc(sizeof(char *) * (n + 1));

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

int _strlen(char *s)
{
        int i = 0;
        while (s[i] != '\0')
                i++;
        return (i);
	int i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *_strcat(char *dest, char *src)
{
        int i = 0;
        int j = 0;

        while (dest[i] != '\0')
        {
        i++;
        }

        while (src[j] != '\0')
        {
                dest[i] = src[j];
                i++;
                j++;

        }

        dest[i] = '\0';
        return (dest);
	int i = 0;
	int j = 0;
	while (dest[i] != '\0')
	{
	i++;
	}

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

#endif
