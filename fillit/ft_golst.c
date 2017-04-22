/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_golst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:07:50 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/21 16:13:55 by etranchi         ###   ########.fr       */
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

int add_piece_tab(t_piece **tab, t_piece *piece);
t_piece *create_piece(char *str, int nb_tetri);
int	ft_golst(char *str, t_piece **tab)
{
	size_t	i;
	int 	county;
	int		countx;
	int		countbox;
	int 	placebox;
	int 	count_tetri;
	size_t j;

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
		printf("indice : %zu", i);
		i++;
	}
	j = 0;
	while (str[j] != '\0' && i > j)
	{

		if(!(add_piece_tab(tab,create_piece(&str[j], count_tetri))))
		{
			write(2,"erreur au malloc", 16);
			return (0);
		}
		j += 20 + count_tetri;
		count_tetri++;
	}
	return (1);
}

t_piece *malloc_piece(void)
{
	t_piece *piece;

	if(!(piece = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	if(!(piece->init = (t_tuple *)malloc(sizeof(t_tuple))))
		return (NULL);
	if(!(piece->first = (t_tuple *)malloc(sizeof(t_tuple))))
		return (NULL);
	if(!(piece->second = (t_tuple *)malloc(sizeof(t_tuple))))
		return (NULL);
	if(!(piece->third = (t_tuple *)malloc(sizeof(t_tuple))))
		return (NULL);
	return (piece);
}


int ft_set_tuple(t_piece *piece, int nb, int i);

t_piece *create_piece(char *str, int nb_tetri)
{
	char *alpha;
	t_piece *piece;
	int i;
	int nb;

	i = 0;
	nb = 0;
	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (!(piece = malloc_piece()))
		return (NULL);
	piece->letter = alpha[nb_tetri];
	printf("string:%s", str);
	while (i < 21)
	{
		if (str[i] == '#')
		{
			if (str[i] == '#')
			{
				if (!(ft_set_tuple(piece, nb, i)))
						return (NULL);
				nb++;
			}
		}
		i++;
	}
	return (piece);
}


int ft_set_tuple(t_piece *piece, int nb, int i)
{
	int ref_x;
	int ref_y;
	
	if (piece == NULL)
		return (0);
	ref_x = piece->init->x;
	ref_y = piece->init->y;
	if (nb == 0)
	{
		piece->init->x = (i % 5) - ref_x;
		piece->init->y = (i / 5) - ref_y;
	}
	if (nb == 1)
	{
		piece->first->x = (i % 5) - ref_x;
		piece->first->y = (i / 5) - ref_y;
	}
	if (nb == 2)
	{
		piece->second->x = (i % 5) - ref_x;
		piece->second->y = (i / 5) - ref_y;
	}
	if (nb == 3)
	{
		piece->third->x = (i % 5) - ref_x;
		piece->third->y = (i / 5) - ref_y;
	}
	return (1);
}

int add_piece_tab(t_piece **tab, t_piece *piece)
{
	int i;

	if(piece == NULL)
		return (0);
	i = piece->letter - 'A';
	tab[i] = piece;


	printf("piece:%c \n[0][0]\n[%i][%i]\n[%i][%i]\n[%i][%i]\n",piece->letter, piece->first->x, piece->first->y, piece->second->x,piece->second->y,piece->third->x,piece->third->y);
	return (1);
}
