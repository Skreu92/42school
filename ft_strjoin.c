#include <stdlib.h>

int ft_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	int len;
	char *ctn;
	int i;
	int j;

	len = ft_strlen(s1) + ft_strlen(s2);
	ctn = (char *)malloc((len + 1) * sizeof(char));
	if (!ctn)
		return (NULL);
	ctn[len] = '\0';
	i = 0;
	while (s1[i])
	{
		ctn[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ctn[i + j] = s2[j];
		j++;
	}
	return (ctn);
}

int main()
{
	printf("%s\n", ft_strjoin("coucoy", "tranchier"));
return (0);
}
