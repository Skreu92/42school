/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 13:01:17 by Etienne           #+#    #+#             */
/*   Updated: 2017/04/16 13:10:29 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	char *src;
	char d;

	src = (char *)s;
	d = (unsigned char)c;
	while (n--)
	{
		if ((unsigned char)*src == d)
			return (src);
		src++;
	}
	return (NULL);
}

int main()
{
	char s[10] = "";
	int c = 97;
	printf("Real:%s\nMine:%s\n", memchr(s,c,10), ft_memchr(s,c,10));
	return (0);
}
