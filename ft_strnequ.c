#include <stlib.h>

int ft_strlen(char const *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_strnequ(char const *s1, char const *s2)
{
	int len;
	int i;

	i = 0;
	if (ft_strlen(s1) >= ft_strlen(s2))
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1);
	while (i < len)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
