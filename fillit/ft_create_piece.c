/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 11:13:24 by etranchi          #+#    #+#             */
/*   Updated: 2017/04/26 11:33:02 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

void	set_zero_tuple(t_tuple *tuple)
{
	tuple->x = 0;
	tuple->y = 0;
}

t_piece	*create_piece(char *str, int nb_tetri)
{
	t_piece	*piece;
	int		i;
	int		nb;

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
			if (!(ft_set_tuple(piece, nb, i)))
				return (NULL);
			nb++;
		}
		i++;
	}
	return (piece);
}

void	init_tuple(t_tuple *tuple, int ref_x, int ref_y, int i)
{
	tuple->x = (i % 5) - ref_x;
	tuple->y = (i / 5) - ref_y;
}

int		ft_set_tuple(t_piece *piece, int nb, int i)
{
	int ref_x;
	int ref_y;

	if (piece == NULL)
		return (0);
	ref_x = piece->init->x;
	ref_y = piece->init->y;
	if (nb == 0)
		init_tuple(piece->init, ref_x, ref_y, i);
	if (nb == 1)
		init_tuple(piece->first, ref_x, ref_y, i);
	if (nb == 2)
		init_tuple(piece->second, ref_x, ref_y, i);
	if (nb == 3)
		init_tuple(piece->third, ref_x, ref_y, i);
	return (1);
}

t_piece	*add_piece_tab(t_piece *lst, t_piece *piece)
{
	if (!(lst->letter >= 'A' && lst->letter <= 'Z'))
	{
		lst = piece;
		return (lst);
	}
	while (lst->next)
		lst = lst->next;
	lst->next = piece;
	return (lst);
}
