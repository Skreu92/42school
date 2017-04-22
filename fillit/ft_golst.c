/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_golst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:07:50 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/22 11:13:31 by etranchi         ###   ########.fr       */
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

int	ft_golst(char *str, t_piece **tab)
{
	if (!(check_str(str)))
		return (0);
	if (!(init_tab(str, tab)))
		return (0);
	int i = 0;
	while(tab[i])
	{
		printf("caractere piece:%c\n", tab[i]->letter);
		i++;
	}
	if(!(init_map(tab, i)))
		return (0);
	return (1);
}

int check_str(char *str)
{
	size_t	i;
	int 	county;
	int		countx;
	int		countbox;
	int 	placebox;

	i = 0;
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
		i++;
	}
	return (1);
}

int init_tab(char *str, t_piece **tab)
{
	size_t j;
	int count_tetri;
	size_t i;

	i = 0;
	while (str[i])
		i++;
	j = 0;
	count_tetri = 0;
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