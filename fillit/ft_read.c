/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:58:29 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/25 16:58:31 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "fill.h"

int	ft_isvalid(int argc)
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

char    *ft_read(int argc, char **argv)
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
    {
        write(2, "File is unvalid.\n", 17);
        return (NULL);
    }
    return (str);
}

