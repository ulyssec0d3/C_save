/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:21:06 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/21 23:39:50 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_somme(int p[16])
{
	int	i;
	int	test;
	int	a;
	int	b;

	i = 0;
	test = i;
	while (i < 4)
	{
		a = p[i] + p[i + 4];
		b = p[i + 8] + p[i + 12];
		if (a < 3 || a > 5 || b < 3 || b > 5)
			test++;
		i++;
	}
	return (test);
}

int	test_sing(int p[16])
{
	int	i;
	int	j;
	int	test;
	int	max;

	i = 0;
	test = i;
	j = 1;
	while (i < 16 && j == 4)
	{
		if (i % 4 == 0)
			max = 0;
		if (p[i] == j)
			max++;
		if (j == 1 && i > 15)
		{
			j = 4;
			i = 0;
		}
		if (max > 1)
			test++;
	}
	return (test);
}

int	test_params(int p[16])
{
	int	i;

	i = 0;
	i += test_sing(p);
	i += test_somme(p);
	return (i);
}
