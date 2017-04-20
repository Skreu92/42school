/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_golst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:07:50 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/18 18:41:09 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>

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

int	ft_golst(char *str)
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
				if(str[i] == '#')
				{
					placebox += check_mate(str, i, countx, county);					
					countbox++;
					printf("[%i][%i]\n", county,countx);
				}
				i++;
				countx++;
			}
			if (countx != 4)
			{
				write(2, "bad count of x.\n", 17);
				return (0);
			}
			i++;
			county++;
		}
		if(!(check_error(countbox, placebox)))
			return (0);
		printf("TETRIMINOS\n");
		i++;
	}
	return (1);
}
