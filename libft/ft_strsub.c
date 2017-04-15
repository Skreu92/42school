#include <stdlib.h>
#include <string.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strsub(char const *s, unsigned int start ,size_t size)
{
	int len;
	char *ctn;
	size_t i;

	if (!*s)
		return (NULL);
	len = ft_strlen(s);
	if (start > len)
		return (NULL);
	ctn = (char *)malloc(len * sizeof(char))
	if (!ctn)
		return (NULL);
	i = 0;
	while (i < size && s[start] != '\0')
	{
		ctn[i] = s[start + i];		
		i++;
	}
	ctn[i] = '\0';
	return (ctn);
}
