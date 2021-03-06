/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:27:01 by etranchi          #+#    #+#             */
/*   Updated: 2017/03/25 13:26:12 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char *))
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]))
			count++;
		i++;
	}
	return (count);
}
