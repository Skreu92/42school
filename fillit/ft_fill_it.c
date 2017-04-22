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

int init_map(t_piece **tab, int size)
{
	t_map *map;

	if(!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	map->tab_piece = tab;
	map->size_tab = size;
	if(!(map->map = (char **)malloc(sizeof(char*) * (map->size_tab + 1))))
		return (0);
	map->map[map->size_tab] = NULL;
	while (size-- > 0)
	{
		if(!(map->map[size] = (char *)malloc(sizeof(char) * (map->size_tab + 1))))
			return (0);
		map->map[size][map->size_tab] = '\0';
	}
	draw_empty_map(map);
	if(!(try_put_piece(map, 0, 0, 0)))
		return (0);
	ft_print_map(map);
	return (1);
}
void check_all_piece_put(t_map *map)
{
	int i;

	i = 0;
	while (map->tab_piece[i])
	{
		if (map->tab_piece[i]->putted == 0)
			init_map(map->tab_piece, map->size_tab + 1);
		i++;
	}
}

int try_put_piece(t_map *map, int x, int y, int nb_piece)
{
	if(x == map->size_tab - 1  && y == map->size_tab - 1 )
	{
		check_all_piece_put(map);
		return (1);
	}
	if (map->map[y][x] != '.')
		try_put_piece(map, (x + 1) % map->size_tab, (x + (y + 1))/map->size_tab, nb_piece);
	while (map->tab_piece[nb_piece])
	{
		if(ft_may_pose(map, map->tab_piece[nb_piece], x % map->size_tab, y / map->size_tab))
		{
			draw_piece(map->map, map->tab_piece[nb_piece], x , y);
			map->tab_piece[nb_piece]->putted = 1;
			printf("piece%d putted\n", nb_piece);
			nb_piece++;
		}
		else
		{
			try_put_piece(map, (x + 1)% map->size_tab, (x + (y + 1))/map->size_tab, nb_piece);
		}
	}
	return (1);

}

void ft_print_map(t_map *map)
{
	int i;
	i = 0;
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
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
		ft_memset(map->map[i], '.',map->size_tab);
		j = 0;
		i++;
	}
}
int check_value_tuple(int map_size, int tuple)
{
	if (tuple >= 0 || tuple < map_size)
		return (0);
	else
		return (1);
}

int ft_may_pose(t_map *map, t_piece *piece, int x, int y)
{
	int map_size;
	char **mapi;

	map_size = map->size_tab;
	mapi = map->map;
	if(mapi[y][x] == '.')
	{
		if (!(check_value_tuple(map_size, y + piece->first->y)) && !(check_value_tuple(map_size,x + piece->first->x)))
			if(mapi[y + piece->first->y][x + piece->first->x] == '.')
			{
				if (!(check_value_tuple(map_size, y + piece->second->y)) && !(check_value_tuple(map_size,x + piece->second->x)))
					if(mapi[y + piece->second->y][x + piece->second->x] == '.')
					{
						if (!(check_value_tuple(map_size,y + piece->third->y)) && !(check_value_tuple(map_size,x + piece->third->x)))
							if(mapi[y + piece->third->y][x + piece->third->x] == '.')
							{
								draw_piece(mapi, piece, x, y);
								return (1);	
							}
					}
			}
	}
	return (0);
}

void draw_piece(char **map, t_piece *piece, int x, int y)
{
	map[y][x] = piece->letter;
	map[y + piece->first->y][x + piece->first->x] = piece->letter;
	map[y + piece->second->y][x + piece->second->x] = piece->letter;
	map[y + piece->third->y][x + piece->third->x] = piece->letter;

}