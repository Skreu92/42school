#include <unistd.h>

void ft_putendl(char const *s)
{
	int i;

	i = 0;
	while (s1[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, '\n', 1);
}
