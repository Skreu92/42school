/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:13:00 by etranchi          #+#    #+#             */
/*   Updated: 2017/04/10 16:14:14 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	disp_file(int fd)
{
	char	buffer;

	while (read(fd, &buffer, 1) != 0)
		write(1, &buffer, 1);
}

int		main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		if (argc > 2)
			write(1, "Too many arguments.\n", 20);
		if (argc < 2)
			write(1, "File name missing.\n", 19);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	disp_file(fd);
	close(fd);
	return (0);
}
