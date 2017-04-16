/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 04:47:57 by etranchi          #+#    #+#             */
/*   Updated: 2017/03/22 17:35:00 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(char *src)
{
	char	*pc;
	int		i;

	i = 0;
	pc = NULL;
	while (src[i])
		i++;
	pc = malloc((i) * sizeof(pc));
	pc[i] = '\0';
	if (pc != NULL)
	{
		while (--i >= 0)
			pc[i] = src[i];
	}
	return (pc);
}
