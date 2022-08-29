/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:38:08 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/21 22:38:10 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	see_line(char grd[4][4], int line)
{
	int	i;
	int	see;
	int	maxl;
	int	maxr;

	maxl = 0;
	maxr = 0;
	i = 0;
	see = 0;
	while (i < 4)
	{
		if (maxl < (grd[line][i] - '0'))
		{
			see += 10;
			maxl = (grd[line][i] - '0');
		}
		if (maxr < (grd[line][3 - i] - '0'))
		{
			see++;
			maxr = (grd[line][3 - i] - '0');
		}
		i++;
	}
	return (see);
}

int	see_col(char grd[4][4], int col)
{
	int	i;
	int	see;
	int	maxlow;
	int	maxup;

	maxlow = 0;
	maxup = 0;
	i = 0;
	see = 0;
	while (i < 4)
	{
		if (maxlow < (grd[i][col] - '0'))
		{
			see += 10;
			maxlow = (grd[i][col] - '0');
		}
		if (maxup < (grd[3 - i][col] - '0'))
		{
			see++;
			maxup = (grd[3 - i][col] - '0');
		}
		i++;
	}
	return (see);
}

int	same_tower(char grd[4][4], int col)
{
	int	i;
	int	nbc;
	int	same;

	i = 0;
	same = 0;
	nbc = 1;
	while (nbc < 5)
	{
		if ((grd[i][col] - '0') == nbc)
			same++;
		if (same > 1)
			break ;
		i++;
		if (i > 3)
		{
			i = 0;
			same = 0;
			nbc++;
		}
	}
	return (same);
}
/*
int main()
{
	char grid[4][4];
	grid[0][0] = '1';
	grid[0][1] = '2';
	grid[0][2] = '3';
	grid[0][3] = '4';
	grid[1][0] = '2';
	grid[1][1] = '3';
	grid[1][2] = '4';
	grid[1][3] = '1';
	grid[2][0] = '3';
	grid[2][1] = '2';
	grid[2][2] = '1';
	grid[2][3] = '4';
	grid[3][0] = '4';
	grid[3][1] = '1';
	grid[3][2] = '2';
	grid[3][3] = '3';
	printf("line = %d\n",see_line(grid, 3));
	printf("col = %d\n",see_col(grid, 0));
	printf("same = %d\n",same_tower(grid, 0));
}
*/
