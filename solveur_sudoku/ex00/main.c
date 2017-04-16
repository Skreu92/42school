/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 06:26:57 by dfouquet          #+#    #+#             */
/*   Updated: 2017/03/22 12:38:52 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_fill_it(char **argv);

int		ft_strlen(char *str, char *tab)
{
	int		i;

	i = -1;
	while (++i < 9)
		tab[i] = '0';
	i = -1;
	while (++i < 9 && str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			return (0);
		if (str[i] != '.')
		{
			if (tab[str[i] - '0' - 1] != '0')
				return (0);
			tab[str[i] - '0' - 1] = '1';
		}
	}
	if (str[i] && i == 9)
		return (0);
	return (1);
}

int		ft_is_true_column(char **grid, char *tab)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < 9)
	{
		k = -1;
		while (++k < 9)
			tab[k] = '0';
		j = 0;
		while (++j < 10)
		{
			if ((grid[j][i] < '0' || grid[j][i] > '9') && grid[j][i] != '.')
				return (0);
			if (grid[j][i] >= '0' && grid[j][i] <= '9')
			{
				if (tab[grid[j][i] - '0' - 1] != '0')
					return (0);
				tab[grid[j][i] - '0' - 1] = '1';
			}
		}
	}
	return (1);
}

int		ft_check_square(char **grid, char *tab, int i, int j)
{
	int		i2;
	int		j2;
	int		k;

	k = -1;
	while (++k < 9)
		tab[k] = '0';
	i2 = -1;
	while (++i2 < 3)
	{
		j2 = -1;
		while (++j2 < 3)
		{
			if (grid[3 * i + i2 + 1][3 * j + j2] != '.')
			{
				if (tab[grid[3 * i + i2 + 1][3 * j + j2] - '0' - 1] != '0')
					return (0);
				tab[grid[3 * i + i2 + 1][3 * j + j2] - '0' - 1] = '1';
			}
		}
	}
	return (1);
}

int		ft_is_true_square(char **grid, char *tab)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			if (!ft_check_square(grid, tab, i, j))
				return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*tab;

	if (argc != 10)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	tab = (char*)malloc(sizeof(tab) * 9);
	i = 0;
	while (++i < argc)
		if (!ft_strlen(argv[i], tab))
		{
			write(1, "Error\n", 6);
			return (0);
		}
	if (!ft_is_true_column(argv, tab) || !ft_is_true_square(argv, tab))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_fill_it(argv);
	return (0);
}
