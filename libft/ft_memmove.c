/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 12:45:55 by Etienne           #+#    #+#             */
/*   Updated: 2017/04/16 12:59:30 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
	char *tmp;
	char *s;
	
	tmp = (char *)dst;
	s = (char *)src;
	if (len == 0 || s == NULL)
	{
		dst = NULL;
		return (dst);
	}
	while (len--)
	{
		*tmp = s[len];
		tmp++;
	}
	return (dst);
}

int main()
{
	char d[10] = "coucou";
	char s[10] = "aaaaa";
	printf("Real:%s\nMine:%s\n", memmove(d,s,1), ft_memmove(d,s,1));
	return (0);
}
