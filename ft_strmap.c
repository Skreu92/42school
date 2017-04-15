#include <stlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);	
}

char *ft_strmap(char const *s, char (*f)(char))
{
	int len;
	char *ctn;

	len = ft_strlen(s);
	ctn = (char *)malloc(len * sizeof(char));
	if (!ctn)
		return (NULL);
	while (s[len--])
		ctn[len] = f(s[len]);
	return (ctn);
}
