/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 11:01:53 by etranchi          #+#    #+#             */
/*   Updated: 2017/04/27 12:54:12 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

int			ft_scale_map(t_map *map, int size)
{
	int i;
	int j;

	j = size - 1;
	i = size - 1;
	while (i--)
	{
		j = size;
		while (j--)
		{
			if (map->map[j][size - 1] != '.' || map->map[size - 1][i] != '.')
				return (size);
		}
	}
	return (ft_scale_map(map, size - 1));
}

void		ft_print_map(t_map *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->best_size)
	{
		j = -1;
		while (++j < map->best_size)
		{
			write(1, &map->best_map[i][j], 1);
		}
		write(1, "\n", 1);
	}
}

void		draw_empty_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->size_map)
	{
		j = 0;
		while (j < map->size_map)
		{
			map->map[i][j] = '.';
			j++;
		}
		i++;
	}
}

int			check_value_tuple(t_map *map, int x, int y, t_tuple *tuple)
{
	if (x + tuple->x > -1)
		if (y + tuple->y < map->size_map && x + tuple->x < map->size_map)
			if (map->map[y + tuple->y][x + tuple->x] == '.' &&
					map->map[y + tuple->y][x + tuple->x] != '\n')
				return (1);
	return (0);
}

int			ft_to_check(t_map *map, t_piece *piece, int x, int y)
{
	if (check_value_tuple(map, x, y, piece->init))
		if (check_value_tuple(map, x, y, piece->first))
			if (check_value_tuple(map, x, y, piece->second))
				if (check_value_tuple(map, x, y, piece->third))
					return (0);
	return (1);
}
