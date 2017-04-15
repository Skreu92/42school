#include <stdlib.h>

int ft_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_strequ(char const *s1, char const *s2)
{
	int len1;
	int len2;
	int len;
	int i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 >= len2)
		len = len2;
	else
		len = len1;
	while (i < len)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	printf("%d\n", ft_strequ(av[1], av[2]));
return (0);

}
