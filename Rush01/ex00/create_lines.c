/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:04:47 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/23 14:19:29 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check_doubles(int pos, char *row)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (row[i] == row[pos])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_add_grid(char **grid, char *row, int i)
{
	int j;

	j = 0;
	grid[i] = (char *) malloc(sizeof(char) * 5);
	if (grid[i] == NULL)
		return NULL;
	while (j < 4)
	{
		grid[i][j] = row[j];
		j++;
	}
	return (NULL);
}

void	ft_backtrack(int *i, int pos, char **grid,char *row)
{
	if (pos == 4)
	{
		ft_add_grid(grid, row, *i);
		*i += 1;
		return ;
	}
	row[pos] = '1';
	while (row[pos] <=  '4')
	{
		if (!ft_check_doubles(pos, row))
			ft_backtrack(&(*i), pos + 1, grid, row);
		row[pos] += 1;
	}
	row[pos] = 0;
}

char	**ft_generate_lines(void)
{
	char **grid;
	int i;
	char row[5];

	grid = NULL;
	grid = (char **) malloc(sizeof(char *) * 25);
	if (grid == NULL)
		return (NULL);
	i = 0;
	ft_backtrack(&i, 0, grid, row);
	grid[24] = 0;
	return (grid);
}

#include <stdio.h>

int main(void)
{
	char **grid;
	int i;
	grid = ft_generate_lines();
	i = 0;
	while (grid[i])
		printf("%s\n", grid[i++]);
	return (0);
}
