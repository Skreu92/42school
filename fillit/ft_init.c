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

int		get_square(int size)
{
	int i;

	i = 1;
	while ((i * i) < size)
		i++;
	if ((i * i) > size)
		i = i - 1;
	if (size == 1)
		return (0);
	if (size == 8)
		return (3);
	if (size > 9 && size < 15)
		return (4);
	if (size >= 15 && size < 20)
		return (5);
	if (size >= 20 && size < 25)
		return (6);
	if (size >= 25)
		return (8);
	return (i);
}

int		init_char_map(t_map *map)
{
	int size;
	int i;

	size = -1;
	while (++size < map->size_map)
	{
		if (!(map->map[size] = (char *)malloc(sizeof(char) *
			(map->size_map + 1))))
			return (0);
		if (!(map->best_map[size] = (char *)malloc(sizeof(char)
			* (map->size_map + 1))))
			return (0);
		map->map[size][map->size_map] = '\0';
		i = -1;
		while (++i < map->size_map)
			map->map[size][i] = '.';
	}
	return (1);
}

t_map	*init_map(t_piece *lst, int size)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	map->lst_piece = lst;
	map->size_map = 4 + get_square(size);
	map->best_size = 10000;
	if (!(map->map = (char **)malloc(sizeof(char*) * (map->size_map + 1))))
		return (0);
	if (!(map->best_map = (char **)malloc(sizeof(char*) * (map->size_map + 1))))
		return (0);
	map->map[map->size_map] = NULL;
	if (!(init_char_map(map)))
		return (0);
	return (map);
}
