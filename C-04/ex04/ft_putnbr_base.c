/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:27:33 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/18 22:59:53 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str, int temp, int neg)
{
	if (neg)
		write(1, "-", 1);
	while (temp >= 0)
	{
		if (str[temp] >= ' ' && str[temp] != 127)
			write(1, &str[temp], 1);
		temp--;
	}
}

int	check_base(char *base)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (base[i])
	{
		c = base[i];
		j = i++;
		while (base[++j])
			if (c == base[j] || c == '+' || c == '-')
				return (0);
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;
	unsigned int	nb;
	char			res[32];
	int				size;
	int				neg;

	i = 0;
	neg = 0;
	size = check_base(base);
	if (size < 2)
		return ;
	if (nbr < 0)
		nb = nbr * (--neg);
	else
		nb = nbr;
	while (nb > 0)
	{
		res [i] = base[nb % size];
		nb /= size;
		i++;
	}
	ft_putstr(res, i - 1, neg);
}
