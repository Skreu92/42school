#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strtrim(char const *s)
{
	char *ctn;
	int len;
	int i;
	int j;

	i = 0;
	while (s[i] < 33)
		s++;
	len = ft_strlen(s);
	while (s[len - i] < 33)
		i++;
	ctn = (char *)malloc((len + 1) * sizeof(char));
	if (!ctn)
		return (NULL);
	ctn[len] = '\0';
	j = 0;
	while (j < len - i && s != '\0')
	{
		ctn[j] = s[j];
		j++;	
	}
	return (ctn);			
}
