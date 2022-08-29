/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:51:05 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/23 13:32:07 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		test_params(int p[16]);

int		ft_forcegrd(char grd[4][4], int *p, int line, char **index);

char	**ft_generate_lines(void);

void	init(char grd[4][4])
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < 4)
	{
		b = 0;
		while (b < 4)
		{
			grd[a][b] = '0';
			b++;
		}
		a++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		p[16];
	char	grd[4][4];
	char	**index;

	i = -1;
	index = ft_generate_lines();
	init(grd);
	if (argc == 2)
		while (++i < 16)
			p[i] = argv[1][i * 2] - '0';
	if (!test_params(p) && argc == 2)
		ft_forcegrd(grd, p, 0, index);
	else
		write(1, "Error\n", 6);
	i = 0;
	while (i < 25)
	{
		free(index[i]);
		index[i++] = 0;
	}
	return (1);
}
