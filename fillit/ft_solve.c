/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:42:00 by etranchi          #+#    #+#             */
/*   Updated: 2017/04/24 13:42:02 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

void ft_solve(t_map *map, int x ,int y)
{
	int x_size;
	int y_size;
	t_piece *lst;

	lst = map->lst_piece;

	while (lst->putted == 1 && lst->next != NULL)
		lst = lst->next;	
	y_size = -1;
	if (lst->putted == 1 && lst->next == NULL)
	{
		ft_scale_map(map);
		if(map->size_map < map->best_size)
		{
			draw_empty_map(map->best_map);
			ft_save(map);
			ft_print_map(map);
		}	
		return ;

	}
	while (y_size++ < map->best_size)
	{
		x_size = -1;
		while (x_size++ < map->best_size)
			ft_may_pose(map, lst, x_size, y_size);
	}
	if (lst->putted == 1 && lst->next == NULL)
	{
		ft_print_map(map);
		return ;
	}
	return ;
}

void		ft_save(t_map *map)
{
	int		y;
	int		x;

	y = -1;

	while (++y < map->size_map)
	{
		x = -1;
		while (++x < map->size_map)
			map->best_map[y][x] = map->map[y][x];
	}
	map->best_size = map->size_map;
}
