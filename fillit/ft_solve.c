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

void ft_solve(t_map *map)
{
	int x_size;
	int y_size;
	t_piece *lst;

	lst = map->lst_piece;
	while (lst->putted == 1 && lst->next != NULL)
		lst = lst->next;
	y_size = -1;
	while (y_size++ < map->size_map)
	{
		x_size = -1;
		while (x_size++ < map->size_map)
			ft_may_pose(map, lst, x_size, y_size);
	}
	if (lst->letter == 'A')
	{
		ft_print_map(map);
	}
	return ;
}
