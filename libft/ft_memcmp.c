/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 13:10:51 by Etienne           #+#    #+#             */
/*   Updated: 2017/04/16 13:18:19 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char *c1;
	char *c2;

	c1 = (char *)s1;
	c2 = (char *)s2;
	while (n--)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	return (0);
}

int main()
{
	char d[10] = "";
	char s[10] = "";
	printf("Real:%d\nMine:%d\n", memcmp(d,s,6), ft_memcmp(d,s,6));
	return (0);
}
