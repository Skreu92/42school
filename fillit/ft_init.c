/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:58:40 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/26 11:43:09 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "fill.h"

t_piece	*init_lst(char *str)
{
	size_t	j;
	int		count_tetri;
	size_t	i;
	t_piece	*lst;
	t_piece	*tmp;

	i = 0;
	if (!(lst = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	if (!(tmp = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	while (str[i])
		i++;
	j = 0;
	count_tetri = 0;
	while (str[j] != '\0' && i > j)
	{
		tmp = add_piece_tab(lst, create_piece(&str[j], count_tetri));
		if (count_tetri == 0)
			lst = tmp;
		count_tetri++;
		j += 21;
	}
	return (lst);
}

t_map	*init_map(t_piece *lst, int size)
{
	t_map	*map;
	int		i;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	map->lst_piece = lst;
	printf("siwze : %d\n",size );
	map->size_map = 4 ;
	map->best_size = 10000;
	if (!(map->map = (char **)malloc(sizeof(char*) * (map->size_map + 1))))
		return (0);
	if (!(map->best_map = (char **)malloc(sizeof(char*) * (map->size_map + 1))))
		return (0);
	map->map[map->size_map] = NULL;
	size = 0;
	while (size < map->size_map)
	{
		if (!(map->map[size] = (char *)malloc(sizeof(char) * (map->size_map + 1))))
			return (0);
		if (!(map->best_map[size] = (char *)malloc(sizeof(char) * (map->size_map + 1))))
			return (0);
		map->map[size][map->size_map] = '\0';
		i = 0;
		while (i < map->size_map)
		{
			map->map[size][i] = '.';
			i++;
		}
		size++;
	}
	return (map);
}