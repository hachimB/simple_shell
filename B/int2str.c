#include "lib_funcs.h"

/**
 * int2str - integer to string function
 * @n: integer
 * Return: string
 */

char *int2str(unsigned int n)
{
	char *s;
	int n_len = 0, k;
	unsigned int n_c = n;

	while (n_c > 0)
	{
		n_c /= 10;
		n_len++;
	}

	n_c = n;
	k = n_len - 1;

	s = malloc(sizeof(char) * (n_len + 1));

	if (s == NULL)
		return (NULL);

	if (n_c == 0)
	{
		s[0] = '0';
		s[1] = '\0';

		return (s);
	}

	while (k >= 0)
	{
		s[k] = '0' + (n_c % 10);
		n_c /= 10;
		k--;
	}
	s[n_len] = '\0';

	return (s);
}
