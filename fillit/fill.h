/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:06:21 by etranchi          #+#    #+#             */
/*   Updated: 2017/04/22 11:13:07 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_H
# define FILL_H
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "includes/libft.h"
#define ABS(x) x >= 0 ? x : -x
typedef struct s_tuple
{
	int x;
	int y;
}				t_tuple;
typedef struct s_piece
{
	char letter;
	t_tuple *init;
	t_tuple *first;
	t_tuple *second;
	t_tuple *third;
	int putted;
}				t_piece;
typedef struct s_map
{
	t_piece **tab_piece;
	int size_tab;
	int nb_tetri;
	char **map;
}				t_map;

int check_mate(char *str, int i, int countx, int county);
int check_error(int countbox, int placebox);
int ft_golst(char *str);
t_piece *malloc_piece(void);
void set_zero_tuple(t_tuple *tuple);
t_piece *create_piece(char *str, int nb_tetri);
int ft_set_tuple(t_piece *piece, int nb, int i);
int add_piece_tab(t_piece **tab, t_piece *piece);
t_piece **init_tab(char *str);
int check_str(char *str);
int init_map(t_piece **tab, int i);
int try_put_piece(t_map *map, int x, int y, int nb_piece);
void draw_empty_map(t_map *map);
int ft_may_pose(t_map *map, t_piece *piece, int x, int y);
void draw_piece(char **map, t_piece *piece, int x, int y);
int check_value_tuple(t_map *map, int x, int y, t_tuple *tuple);
void ft_print_map(t_map *map);
void check_all_piece_put(t_map *map);
void		ft_scale_map(t_map *map);

#endif
