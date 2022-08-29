/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:20:09 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/21 18:43:50 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*void	ft_forcegrd(grd, p)
{}*/

/*int	*ft_comb(char tab[24][4])
{
	char	base[4];
	int		test[5];
	int		i;
	int		j;

	i = 0;
	j = 0;
	base = "1234";
	while ()
	{
		test = "1234\0";
		ft_test_4digits(base, test);
		if (test[4] == 1)
		{
			j = 0;
			while (j < 4)
			{
			tab[i][j++] = base[j];
			}
			i++;
		}
		base[3 -j]++;
		if (base[3 - j] > '4')
		{
			reset_tab();
		}
	}
}

void	ft_test_4digits(char base[4], int test)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!test[4])
	{
		if (base[j] == (test[i] + '0'))
		{
			test[i] = 0;
			i++;
			j = 0;
			if (i == 4)
				test[4] = 1;
		}
		if (j == 4 && test[i])
			test[4] = -1;
		j++;
	}
}*/

tab = {"1234","1243","1324","1342","1423","1432","2134","2143","2314","2341","2413","2431","3124","3142","3214","3241",
"3412","3421","4123","4132","4213","4231","4312","4321"};
