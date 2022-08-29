/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:00:45 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/29 13:49:56 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>

int	ft_check_line(int brd[10], int pos)
{
	int	i;
	int	j;
	int	same;

	i = 0;
	while (i <= 9)
	{
		j = 0;
		same = 0;
		while (j <= pos)
		{
			if (brd[j] == i)
				same++;
			++j;
		}
		if (same > 1)
			break ;
		i++;
	}
	return (same < 2);
}

int	ft_check_diag(int brd[10], int pos)
{
	int	i;
	int	j;
	int	dif;

	i = 0;
	dif = 0;
	while (i <= 9 && dif != 100)
	{
		j = pos;
		while (j >= 0)
		{
			dif = pos - j;
			if (((brd[j] + dif == brd[pos])
					|| (brd[j] - dif == brd[pos])) && dif)
				dif = 100;
			if (dif == 100)
				break ;
			--j;
		}
		i++;
	}
	return (dif != 100);
}

void	ft_find_solution(int *p, int brd[10], int pos)
{
	int		row;
	char	c;

	row = 0;
	if (pos == 10)
	{
		while (row < 10)
		{
			c = brd[row++] + '0';
			write(1, &c, 1);
		}
		write(1, "\n", 1);
		(*p)++;
	}
	while (row < 10)
	{
		brd[pos] = row;
		if (ft_check_diag(brd, pos) && ft_check_line(brd, pos))
			ft_find_solution(p, brd, pos + 1);
		row++;
	}
	return ;
}

int	ft_ten_queens_puzzle(void)
{
	int	p;
	int	board[10];

	p = 0;
	ft_find_solution(&p, board, 0);
	return (p);
}
