/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_may_pose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:01:39 by dfouquet          #+#    #+#             */
/*   Updated: 2017/03/19 17:23:14 by dfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_number_line(char **grid, int number, int line)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grid[line][i] == number)
			return (0);
		i++;
	}
	return (1);
}

int		ft_number_column(char **grid, int number, int col)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grid[i][col] == number)
			return (0);
		i++;
	}
	return (1);
}

int		ft_number_square(char **grid, int number, int col, int line)
{
	int i;
	int j;
	int k;
	int l;

	k = 0;
	i = line / 3;
	j = col / 3;
	while (k < 3)
	{
		l = 0;
		while (l < 3)
		{
			if (grid[i * 3 + l][j * 3 + k] == number)
				return (0);
			l++;
		}
		k++;
	}
	return (1);
}

int		ft_may_pose(char **grid, int number, int col, int line)
{
	if (ft_number_line(grid, number, line) == 0 ||
			ft_number_column(grid, number, col) == 0 ||
			ft_number_square(grid, number, col, line) == 0)
		return (0);
	return (1);
}
