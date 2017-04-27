/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:42:00 by etranchi          #+#    #+#             */
/*   Updated: 2017/04/27 12:57:24 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

void		new_map_to_save(t_map *map)
{
	int tmp_size;

	tmp_size = ft_scale_map(map, map->size_map);
	if (tmp_size < map->best_size)
	{
		map->best_size = tmp_size;
		ft_save(map);
	}
}

void		ft_solve(t_map *map)
{
	int		x_size;
	int		y_size;
	t_piece	*lst;
	int		i;

	i = 0;
	lst = map->lst_piece;
	while (lst->putted == 1 && lst->next != NULL)
		lst = lst->next;
	if (lst->putted == 1 && lst->next == NULL)
	{
		new_map_to_save(map);
		return ;
	}
	y_size = -1;
	while (y_size++ < map->size_map)
	{
		x_size = -1;
		while (x_size++ < map->size_map)
			ft_may_pose(map, lst, x_size, y_size);
	}
	return ;
}

void		ft_may_pose(t_map *map, t_piece *piece, int x, int y)
{
	set_zero_tuple(piece->init);
	if (ft_to_check(map, piece, x, y))
		return ;
	draw_piece(map, piece, x, y);
	ft_solve(map);
	clear_piece(map, piece, x, y);
}

void		clear_piece(t_map *map, t_piece *piece, int x, int y)
{
	piece->putted = 0;
	map->map[y][x] = '.';
	map->map[y + piece->first->y][x + piece->first->x] = '.';
	map->map[y + piece->second->y][x + piece->second->x] = '.';
	map->map[y + piece->third->y][x + piece->third->x] = '.';
}

void		draw_piece(t_map *map, t_piece *piece, int x, int y)
{
	piece->putted = 1;
	map->map[y][x] = piece->letter;
	map->map[y + piece->first->y][x + piece->first->x] = piece->letter;
	map->map[y + piece->second->y][x + piece->second->x] = piece->letter;
	map->map[y + piece->third->y][x + piece->third->x] = piece->letter;
}
