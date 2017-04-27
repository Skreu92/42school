/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:14:35 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/27 15:08:36 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int			ft_check_plus_plus(char *str, int i)
{
	if (str[i] != '\n' && str[i] != '\0')
	{
		write(1, "error", 6);
		exit(1);
	}
	if (str[i] == '\n' && str[i + 1] != '\0')
		return (1);
	return (0);
}
