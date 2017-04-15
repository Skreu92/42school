/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 11:47:04 by Etienne           #+#    #+#             */
/*   Updated: 2017/04/15 12:04:07 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>

void *ft_memset(void *b, int c, size_t len)
{
	int i;
	unsigned char *str;

	str = (unsigned char *)b;
	i = 0;
	if (len == 0)
		return (b);
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

int main()
{
	char str[7] = "coucou";
	int i = 'd';
	printf("Real:%s\nMine:%s\n",memset(str, 'd', 7), ft_memset(str, 'd', 10));	
	return (0);
}
