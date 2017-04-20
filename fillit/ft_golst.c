/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_golst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:07:50 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/20 17:51:13 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "fill.h"

int check_mate(char *str, int i, int countx, int county)
{
	int placebox;

	placebox = 0;
	if (str[i + 1] == '#' && countx != 3)
		placebox++;
    if (str[i + 5] == '#'  && county < 3)
	   placebox++;
	if (str[i - 1] == '#' && countx > 0)
		placebox++;
	if (str[i - 5] == '#' && county > 0)
		placebox++;
	return (placebox);
}

int check_error(int countbox, int placebox)
{
	if (countbox != 4)
	{
		write(2, "bad count of #.\n", 17);
		return (0);
	}
    if (placebox != 6 && placebox != 8)
    {
        write (2, "bad placement of #.\n", 21);
        return (0);
    }
    return (1);
}

void add_piece_tab(t_piece **tab, t_piece *piece);
t_piece *create_piece(char *str, int nb_tetri);
int	ft_golst(char *str, t_piece **tab)
{
	size_t	i;
	int 	county;
	int		countx;
	int		countbox;
	int 	placebox;
	int 	count_tetri;

	i = 0;
	count_tetri = 0;
	while (str[i] != '\0')
	{
		county = 0;
		countbox = 0;
        placebox = 0;

		while (county != 4)
		{
			countx = 0;
			while (str[i] != '\n')
			{
				if (str[i] == '#')
				{
					placebox += check_mate(str, i, countx, county);					
					countbox++;
				}
				i++;
				countx++;
			}
			if (countx != 4)
			{
				return (0);
			}
			i++;
			county++;
		}
		if (!(check_error(countbox, placebox)))
			return (0);
		add_piece_tab(tab,create_piece(&str[i - 20], count_tetri));
		count_tetri++;
		i++;
	}
	return (1);
}

t_piece *malloc_piece(void)
{
	t_piece *piece;

	piece = (t_piece *)malloc(sizeof(t_piece));
	piece->letter = (char)malloc(sizeof(char));
	piece->init = (t_tuple *)malloc(sizeof(t_tuple));
	piece->first = (t_tuple *)malloc(sizeof(t_tuple));
	piece->second = (t_tuple *)malloc(sizeof(t_tuple));
	piece->third = (t_tuple *)malloc(sizeof(t_tuple));
	return (piece);
}


void ft_set_tuple(t_piece *piece, int nb, int i);

t_piece *create_piece(char *str, int nb_tetri)
{
	char *alpha;
	t_piece *piece;
	int i;
	int j;

	i = 0;
	j = 0;
	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	piece = malloc_piece();
	piece->letter = alpha[nb_tetri];
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (j == 0)
			{
				piece->init->x = i % 5;
				piece->init->y = i / 5;
			printf("ref_x:%i  ref_y:%i\n",piece->init->x, piece->init->y);
		j++;
			}
			if (str[i + 1] == '#')
			{
				ft_set_tuple(piece, j, i + 1);
			}
			else if (str[i + 5] == '#')
			{
				ft_set_tuple(piece, j, i + 5);
			}
		}
		i++;
	}
	return (piece);
}


void ft_set_tuple(t_piece *piece, int nb, int i)
{
	int ref_x;
	int ref_y;
	
	ref_x = piece->init->x;
	ref_y = piece->init->y;

	if (nb == 1)
	{
		piece->first->x = (i % 5);
		piece->first->y = (i / 5);
	}
	if (nb == 2)
	{
		piece->second->x = i % 5;
		piece->second->y = i / 5;
	}
	if (nb == 3)
	{
		piece->third->x = i % 5;
		piece->third->y = i / 5;
	}
}

void add_piece_tab(t_piece **tab, t_piece *piece)
{
	int i;

	i = piece->letter - 'A';
	tab[i] = piece;


	printf("piece:%c \n[%i][%i]\n[%i][%i]\n[%i][%i]\n[%i][%i]\n",piece->letter,0, 0, piece->first->x, piece->first->y, piece->second->x,piece->second->y,piece->third->x,piece->third->y);
}
