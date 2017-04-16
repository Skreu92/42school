/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 12:45:09 by Etienne           #+#    #+#             */
/*   Updated: 2017/04/16 09:35:27 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdlib.h>

void *memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int i;

	i = -1;
	while (i++ < n)
	{
		*dst = *src;
		dst++;
		src++;
	}
}
