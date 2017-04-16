/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 07:24:27 by etranchi          #+#    #+#             */
/*   Updated: 2017/03/22 19:43:46 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int i;

	i = 0;
	tab = NULL;
	if (min >= max)
	{
		return (tab);
	}
	while (min + i < max)
		i++;
	tab = malloc((i) * sizeof(int));
	if (tab == NULL)
		return (tab);
	while (--i >= 0)
	{
		tab[i] = --max;
	}
	return (tab);
}
