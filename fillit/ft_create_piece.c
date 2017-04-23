/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 11:13:24 by etranchi          #+#    #+#             */
/*   Updated: 2017/04/22 11:13:40 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

t_piece *malloc_piece(void)
{
	t_piece *piece;

	if(!(piece = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	if(!(piece->init = (t_tuple *)malloc(sizeof(t_tuple))))
		return (NULL);
	set_zero_tuple(piece->init);
	if(!(piece->first = (t_tuple *)malloc(sizeof(t_tuple))))
		return (NULL);
	set_zero_tuple(piece->first);
	if(!(piece->second = (t_tuple *)malloc(sizeof(t_tuple))))
		return (NULL);
	set_zero_tuple(piece->second);
	if(!(piece->third = (t_tuple *)malloc(sizeof(t_tuple))))
		return (NULL);
	set_zero_tuple(piece->third);
	return (piece);
}

void	set_zero_tuple(t_tuple *tuple)
{
	tuple->x = 0;
	tuple->y = 0;
}



t_piece *create_piece(char *str, int nb_tetri)
{
	t_piece *piece;
	int i;
	int nb;

	i = 0;
	nb = 0;
	if (!(piece = malloc_piece()))
		return (NULL);
	piece->letter = 'A' + nb_tetri;
	piece->putted = 0;
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
		return (1);
	i = piece->letter - 'A';
	tab[i] = piece;
	return (0);
}
