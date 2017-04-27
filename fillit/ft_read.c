/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:58:29 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/27 12:17:29 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

int		ft_isvalid(int argc)
{
	if (argc != 2)
	{
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		else if (argc > 2)
			write(2, "Too many arguments.\n", 20);
		write(2, "Fillit <file name>\n", 19);
		return (0);
	}
	return (1);
}

char	*ft_read(int argc, char **argv)
{
	char	buff;
	int		fd;
	char	*str;
	size_t	i;

	if (!(ft_isvalid(argc)))
		return (0);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (read(fd, &buff, 1) != 0)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * i)))
		return (0);
	close(fd);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (read(fd, &buff, 1) != 0)
	{
		str[i] = buff;
		i++;
	}
	str[i] = '\0';
	if (!(ft_check(str)))
		return (NULL);
	return (str);
}

t_piece	*malloc_piece(void)
{
	t_piece *piece;

	if (!(piece = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	if (!(piece->init = (t_tuple *)malloc(sizeof(t_tuple))))
		return (NULL);
	set_zero_tuple(piece->init);
	if (!(piece->first = (t_tuple *)malloc(sizeof(t_tuple))))
		return (NULL);
	set_zero_tuple(piece->first);
	if (!(piece->second = (t_tuple *)malloc(sizeof(t_tuple))))
		return (NULL);
	set_zero_tuple(piece->second);
	if (!(piece->third = (t_tuple *)malloc(sizeof(t_tuple))))
		return (NULL);
	set_zero_tuple(piece->third);
	if (!(piece->next = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	piece->next = NULL;
	return (piece);
}
