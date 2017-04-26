/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:42:00 by etranchi          #+#    #+#             */
/*   Updated: 2017/04/26 12:46:28 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

void ft_solve(t_map *map)
{
	int x_size;
	int y_size;
	t_piece *lst;
	int tmp_size;
    int i;
    
    i = 0;
	lst = map->lst_piece;

    while (lst->putted == 1 && lst->next != NULL)
	{
		lst = lst->next;
	}
    if (lst->putted == 1 && lst->next == NULL)
   	{
   		tmp_size = ft_scale_map(map, map->size_map);  			
   		if (tmp_size < map->best_size)
   		{
   			   map->best_size = tmp_size;
   			ft_save(map);
   		}
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

void		ft_save(t_map *map)
{
	int		y;
	int		x;

	y = -1;

	while (++y < map->best_size)
	{
		x = -1;
		while (++x < map->best_size)
			map->best_map[y][x] = map->map[y][x];
	}

}
