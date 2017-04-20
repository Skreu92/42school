/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:14:35 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/20 17:18:03 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "fill.h"

int	ft_golst(char *str, t_piece **tab);

int	main(int argc, char **argv)
{
	char	buff;
	int		fd;
	char	*str;
	size_t	i;
	t_piece **tab;
	
	if (argc != 2)
	{
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		else if (argc > 2)
			write(2, "Too many arguments.\n", 20);
		write(2, "Fillit <file name>\n", 19);
		return (0);
	}
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (read(fd, &buff, 1) != 0)
		i++;
	printf("taille:%zu\n", i);
	if(!(str = (char*)malloc(sizeof(char) * i)))
		return (0);
	close (fd);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (read(fd, &buff, 1) != 0)
	{
		str[i] = buff;
		i++;
	}
	str[i] = '\0';
	tab = (t_piece **)malloc(sizeof(t_piece *) * 27);
	if (!(ft_golst(str, tab)))
	{
		write(2, "File is unvalid.\n", 17);
		return (0);
	}
	printf("%s", str);
	return (0);
}
