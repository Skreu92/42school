/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:15:14 by dfouquet          #+#    #+#             */
/*   Updated: 2017/03/19 17:23:47 by dfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_may_pose(char **grid, int number, int col, int line);

void	ft_copy(char **grid, char **result)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			result[i][j] = grid[i][j];
			j++;
		}
		i++;
	}
}

void	ft_print(char **result)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			write(1, &result[i][j], 1);
			if (j != 8)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

int		ft_res(char **grid, char **result, int col, int line)
{
	int		tot;
	int		i;

	if (col == 9 || line == 9)
	{
		ft_copy(grid, result);
		return (1);
	}
	i = '0';
	tot = 0;
	if (grid[line][col] != '0')
		tot += ft_res(grid, result, (col + 1) % 9, line + (col + 1) / 9);
	while (++i <= '9')
	{
		if (ft_may_pose(grid, i, col, line) == 1 && grid[line][col] == '0')
		{
			grid[line][col] = i;
			tot += ft_res(grid, result, (col + 1) % 9, line + (col + 1) / 9);
			if (tot > 1)
				return (tot);
			grid[line][col] = '0';
		}
	}
	return (tot);
}

void	ft_initialize(char **argv, char **grid)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			if (argv[i + 1][j] != '.')
				grid[i][j] = argv[i + 1][j];
			if (argv[i + 1][j] == '.')
				grid[i][j] = '0';
		}
	}
}

void	ft_fill_it(char **argv)
{
	int		i;
	int		t;
	char	**grid;
	char	**result;

	grid = (char**)malloc(sizeof(grid) * 9);
	result = (char**)malloc(sizeof(result) * 9);
	i = -1;
	while (++i < 9)
	{
		grid[i] = (char*)malloc(sizeof(*grid) * 9);
		result[i] = (char*)malloc(sizeof(*result) * 9);
	}
	ft_initialize(argv, grid);
	if ((t = ft_res(grid, result, 0, 0)) == 1)
		ft_print(result);
	else
		write(1, "Error\n", 6);
}
