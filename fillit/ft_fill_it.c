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
	while (i < map->best_size)
	{
		j = -1;
		while (j++ < map->best_size)
			write(1, &map->best_map[i][j], 1);
		write(1, "\n", 1);
		i++;
	}
}

void draw_empty_map(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
}
int check_value_tuple(t_map *map, int x ,int y, t_tuple *tuple)
{
	if (x + tuple->x > -1) 
		if (y + tuple->y < map->size_map && x + tuple->x < map->size_map)
			if (map->map[y + tuple->y][x + tuple->x] == '.')
				return (1);
	return (0);
}

int ft_to_check(t_map *map,t_piece *piece, int x, int y)
{
	if (check_value_tuple(map, x, y, piece->init))
		if (check_value_tuple(map, x, y, piece->first))
			if (check_value_tuple(map, x, y, piece->second))
				if (check_value_tuple(map, x, y, piece->third))
				{
					return (0);
				}
	return (1);
}

void ft_may_pose(t_map *map, t_piece *piece, int x, int y)
{

	if (ft_to_check(map,piece,x,y))
		return ;
	draw_clear_piece(map, piece, x, y, 0);

	ft_solve(map);

	draw_clear_piece(map,piece, x,y, 1);
}

void draw_clear_piece(t_map *map, t_piece *piece, int x, int y, int value)
{
	char c;

	if (value == 0)
	{
		piece->putted = 1;
		c = piece->letter;
	}
	else
	{
		piece->putted = 0;
		c = '.';

	}
	map->map[y][x] = c;
	map->map[y + piece->first->y][x + piece->first->x] = c;
	map->map[y + piece->second->y][x + piece->second->x] = c;
	map->map[y + piece->third->y][x + piece->third->x] = c;	

}