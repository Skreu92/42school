/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:14:35 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/27 12:21:41 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "fill.h"

static int	ft_lstsize(t_piece *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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

int			main(int argc, char **argv)
{
	char	*str;
	t_piece	*lst;
	t_map	*map;

	if (!(str = ft_read(argc, argv)))
		return (0);
	if (!(lst = init_lst(str)))
		return (0);
	if (!(map = init_map(lst, (ft_lstsize(lst)))))
		return (0);
	ft_solve(map);
	ft_print_map(map);
	free(map);
	return (0);
}
