/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:56:18 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/14 16:36:18 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	lenght(int a)
{
	int	i;

	i = 0;
	while (a > 9)
	{
		++i;
		a /= 10;
	}
	a = i;
	i = 1;
	while (a > 0)
	{
		i *= 10;
		--a;
	}
	return (i);
}

void	ft_putnbr(int a)
{
	int	i;
	int	n;

	if (a == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (a < 0)
	{
		write(1, "-", 1);
		a *= -1;
	}
	n = lenght(a);
	while (n > 0)
	{
		i = a / n + '0';
		a %= n;
		n /= 10;
		write(1, &i, 1);
	}
}
