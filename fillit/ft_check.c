/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:07:50 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/25 17:06:02 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "fill.h"

int	check_error(int countbox, int placebox)
{
	if (countbox != 4)
	{
		write(2, "bad count of #.\n", 17);
		return (0);
	}
	if (placebox != 6 && placebox != 8)
	{
		write(2, "bad placement of #.\n", 21);
		return (0);
	}
	return (1);
}

int	check_mate(char *str)
{
	int i;
	int j;
	int placebox;
	int countbox;
	
	i = 0;
	while (str[i] != '\0')
	{
		countbox = 0;
		placebox = 0;
		j = 0;
		while (j <= 21)
		{
			if (str[i + j] == '#')
			{
				
                if (str[i + j + 1] == '#' && j < 21)
                {
                    placebox++;
                }
				if (str[i + j + 5] == '#' && j < 16)
                {
                    placebox++;
                }
				if (str[i + j - 1] == '#' && j > 0)
                {
                    placebox++;
                }
				if (str[i + j - 5] == '#' && j > 4)
                {
                    placebox++;
                }
				countbox++;
			}
            j++;
		}
		if (!(check_error(countbox, placebox)))
			return (0);
		i = i + j;
	}
	return (1);
}

int	check_str(char *str)
{
	size_t	i;
	int		county;
	int		countx;

	i = 0;
	while (str[i] != '\0')
	{
		county = 0;
		while (county != 4)
		{
			countx = 0;
			while (str[i] && str[i] != '\n')
			{
				i++;
				countx++;
			}
			if (countx != 4)
				return (0);
			i++;
			county++;
		}
		i++;
	}
	return (1);
}

int	ft_check(char *str)
{
	if (!(check_str(str)))
		return (0);
	if (!(check_mate(str)))
		return (0);
	return (1);
}
