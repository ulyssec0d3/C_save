/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_recursive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:34:33 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/23 13:53:14 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	see_line(char grd[4][4], int line);
int	see_col(char grd[4][4], int col);
int	same_tower(char grd[4][4], int col);

void	print_grd(char grd[4][4])
{
	int		i;
	int		j;
	char	prt[2];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			prt[0] = grd[i][j];
			if (j == 3)
				prt[1] = '\n';
			else
				prt[1] = ' ';
			write(1, prt, 2);
			j++;
		}
		i++;
	}
}

int	test_last_line(char grd[4][4], int *p)
{
	int	i;
	int	j;
	int	test;

	i = 0;
	test = 0;
	while (i < 4)
	{
		test = same_tower(grd, i);
		j = see_col(grd, i);
		if (j / 10 != p[i] || j % 10 != p[4 + i])
			test++;
		if (test != 0)
			break ;
		i++;
	}
	return (!test);
}

int	ft_forcegrd(char grd[4][4], int *p, int line, char **index)
{
	int		try;
	int		i;

	if (line == 4)
	{
		if (test_last_line(grd, p))
			print_grd(grd);
		else
			return (0);
	}
	try = 0;
	while (try < 24 && line < 4)
	{
		printf("%s\n", index[try++]);
	}
	while (try < 24 && line < 4)
	{
		i = -1;
		while (++i < 4)
			grd[line][i] = index[try][i];
		i = see_line(grd, line);
		if (i / 10 == p[8 + line] && i % 10 == p[12 + line])
			ft_forcegrd(grd, p, line + 1, index);
		try++;
	}
	if (line == 0 && try == 24)
		write(1, "Error\n", 6);
	return (0);
}
