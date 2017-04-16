/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 09:35:43 by Etienne           #+#    #+#             */
/*   Updated: 2017/04/16 12:45:14 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>

void *ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
	char *s;
	char *d;

	s = (char *)src;
	d = (char *)dst;
	while (n--)
	{
		*d++ = *s;
		if ((unsigned char)*s == (unsigned char)c)
			return (d);
		s++;
	}
	return (NULL);
}

int main()
{
	char d[10] = "coucou";
	char s[10] = "aaaaaa";
	int c = 97;
	printf("Real%s\nMine:%s\n",memccpy(d,s,c,5),ft_memccpy(d,s,c,5));
	return (0);
}
