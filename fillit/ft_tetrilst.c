#include "libft.h"
#include <stdlib.h>

char **ft_strtogrid(char * str)
{
	char **tab;
	int x;
	int y;
	int i;
	
	if (!(tab = (char**)malloc(sizeof(char) * 17)))
	{
		return (NULL);
	}
	y = 0;
	i = 0;
	while (str[i] != '\0')
	{
		x = 0;
		while (str[i] != '\n')
		{
			tab[y][x] = str[i];
			i++;
			x++;
		}
		y++;
	}
	tab[x][y] = '\0';
	return (tab);
}

t_list ft_tetrilst(char *str)
{
	t_list *tetrilst;
	char *straplha;
	int i;
	
	i = 0;
	stralpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	tetrilst = ft_lstnew(ft_strtogrid(str), 17);
}
	
	
