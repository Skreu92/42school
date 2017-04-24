/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 11:01:53 by etranchi          #+#    #+#             */
/*   Updated: 2017/04/22 11:09:01 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fill.h"


void	ft_scale_map(t_map *map)
{
	int i;

	i = map->size_map;
	while (i--)
	{
		if (map->map[i][map->size_map - 1] != '.')
			return ;
		if (map->map[map->size_map - 1][i] != '.')
			return ;
	}
	map->size_map--;
	if (map->size_map == 0)
		return ;
	ft_scale_map(map);
}

void ft_print_map(t_map *map)
{
	int i;
	i = 0;
	int j;

	printf("sizze : %i\n", map->size_map);
	while (map->map[i] && i < map->size_map)
	{
		j = -1;
		while (map->map[i][++j] && j < map->size_map)
			write(1, &map->map[i][j], 1);
		write(1, "\n", 1);
		i++;
	}
}

void draw_empty_map(t_map *map)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (map->map[i] != NULL)
	{
		ft_memset(map->map[i], '.',map->size_map);
		j = 0;
		i++;
	}
}
int check_value_tuple(t_map *map, int x ,int y, t_tuple *tuple)
{
	if (y + tuple->y >= map->size_map || x + tuple->x >= map->size_map)
		return (1);
	if (map->map[y + tuple->y][x + tuple->x] == '.')
	{
		return (0);
	}
	else
		return (1);
}

void ft_may_pose(t_map *map, t_piece *piece, int x, int y)
{
	int map_size;
	char **mapi;

	map_size = map->size_map;
	mapi = map->map;
	if(mapi[y][x] == '.')
		if (!(check_value_tuple(map, x , y ,piece->first))) 
			if (!(check_value_tuple(map, x, y, piece->second))) 
				if (!(check_value_tuple(map, x, y, piece->third)))
					if(mapi[y + piece->first->y][x + piece->first->x] == '.')					
						if(mapi[y + piece->second->y][x + piece->second->x] == '.')
							if(mapi[y + piece->third->y][x + ABS(piece->third->x)] == '.')
							{
								draw_piece(mapi, piece, x, y);
								ft_solve(map);
							}
	return ;
}

void draw_piece(char **map, t_piece *piece, int x, int y)
{
	map[y][x] = piece->letter;
	map[y + piece->first->y][x + piece->first->x] = piece->letter;
	map[y + piece->second->y][x + piece->second->x] = piece->letter;
	map[y + piece->third->y][x + piece->third->x] = piece->letter;
	piece->putted = 1;

}