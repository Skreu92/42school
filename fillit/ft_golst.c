/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_golst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:07:50 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/22 11:13:31 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "fill.h"

int check_mate(char *str, int i, int countx, int county)
{
	int placebox;

	placebox = 0;
	if (str[i + 1] == '#' && countx != 3)
		placebox++;
    if (str[i + 5] == '#'  && county < 3)
	   placebox++;
	if (str[i - 1] == '#' && countx > 0)
		placebox++;
	if (str[i - 5] == '#' && county > 0)
		placebox++;
	return (placebox);
}

int check_error(int countbox, int placebox)
{
	if (countbox != 4)
	{
		write(2, "bad count of #.\n", 17);
		return (0);
	}
    if (placebox != 6 && placebox != 8)
    {
        write (2, "bad placement of #.\n", 21);
        return (0);
    }
    return (1);
}

int	ft_golst(char *str)
{
	t_piece *lst;
	t_map *map;

	if (!(check_str(str)))
		return (0);
	if (!(lst = init_tab(str)))
		return (0);
	printf("RAYANNNN\n");
	map = init_map(lst);
	printf("AHHH");
	ft_solve(map);
	return (1);
}

int check_str(char *str)
{
	size_t	i;
	int 	county;
	int		countx;
	int		countbox;
	int 	placebox;

	i = 0;
	while (str[i] != '\0')
	{
		county = 0;
		countbox = 0;
        placebox = 0;

		while (county != 4)
		{
			countx = 0;
			while (str[i] != '\n')
			{
				if (str[i] == '#')
				{
					placebox += check_mate(str, i, countx, county);					
					countbox++;
				}
				i++;
				countx++;
			}
			if (countx != 4)
			{
				return (0);
			}
			i++;
			county++;
		}
		if (!(check_error(countbox, placebox)))
			return (0);
		i++;
	}
	return (1);
}

t_map *init_map(t_piece *lst)
{
	t_map *map;
	int i;
	int size;

	i = 1;
	lst = lst->next;
	if(!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	while (lst && lst->next != NULL)
	{
		printf("%c\n", lst->letter);
		lst = lst->next;
		i++;
	}
	map->nb_tetri = i;
	map->lst_piece = lst;
	map->size_map = ( i * 4 );
	if(!(map->map = (char **)malloc(sizeof(char*) * (map->size_map + 1))))
		return (0);
	printf("ahhh\n");
	map->map[map->size_map] = NULL;
	size = map->size_map ;
	printf("size = %d\n", size);
	while (size-- > 0)
	{
		if(!(map->map[size] = (char *)malloc(sizeof(char) * (map->size_map + 1))))
			return (0);
		map->map[size][map->size_map] = '\0';
	}
	map->size_map = map->size_map;
	draw_empty_map(map);
	printf("fin\n");
	return (map);
}

t_piece *init_tab(char *str)
{
	size_t j;
	int count_tetri;
	size_t i;
	t_piece *lst;

	i = 0;
	if (!(lst = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	while (str[i])
		i++;
	j = 0;
	count_tetri = 0;
	while (str[j] != '\0' && i > j)
	{
		lst = add_piece_tab(lst,create_piece(&str[j], count_tetri));
		count_tetri++;
		j += 21;
	}
	return (lst);
}