#ifndef STRFUNCS
#define STRFUNCS

int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int j;
	while (s1[i] != '\0')
		i++;

	while (s2[i] != '\0')
		i++;
	for (j = 0; j <= i; j++)
	{
		if (s1[j] != s2[j])
		return (s1[j] - s2[j]);
	}
return (0);
}
int _strlen(char *s)
{
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
}

#endif
