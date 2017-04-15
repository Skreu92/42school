#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int len;
	char *ctn;
	unsigned int i;

	i = 0;
	len = ft_strlen(s);
	ctn = (char *)malloc(len * sizeof(char));
	if (!ctn)
		return (NULL);
	while (s[i] & i < len)
	{
		ctn[i] = f(i, s[i]);
		i++;
	}
	return (ctn);
}
