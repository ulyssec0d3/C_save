/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:43:30 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/21 16:48:29 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	create_grd(int *p, int size, int **grd)
{
	int i;
	int j;

	i = 0;
	while (i < size + 2)
	{
		grd[i++] = malloc(sizeof(char)*(size+2));
	}
	i = 0;
	j = 0;
	while (i < size + 2 || j < size + 2)
	{
		grd[j][i++] = 0;
		if (i > size + 1)
		{
			j++;
			i = 0;
		}
	}
	i = 1;
	while (i < size)
	{
		grd[0][i] = p[i];
		grd[size + 1][i] = p[i + size];
		grd[i][0] = p[i + (size*2)];
		grd[i][size + 1] = p[i + (size*3)];
	}
}

void	free_gd(int **grd, int size)
{
	int	i;

	i = 0;
	while (i < size + 2)
	{
		free(grd[i]);
	}
	free(grd);
}

void	print_grd(int **grd, int size)
{
	int i;
	int j;
	char prt[2];

	i = 1;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			prt[0] = grd[i][j] + '0';
			if (j == size - 1)
				prt[1] = '\n';
			else
				prt[1] = ' ';
			write(1, prt, 2);
			j++;
		}
		i++;
	}
}
int	main(int argc, char **argv)
{
	int i;
	int size;
	int *p;
	int **grd;

	p = malloc(sizeof(char)*(argc - (argc % 4)));
	size = argc / 4;
	grd = malloc(sizeof(char *)*(size + 2));
	i = 0;
	while (i < argc - i)
		p[i++] = (*argv)[i + 1] - '0';
	create_grd(p, size, grd);
	free(p);
	print_grd(grd, size);
	free_gd(grd, size);
}
