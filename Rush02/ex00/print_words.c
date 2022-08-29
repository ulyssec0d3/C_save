/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:51:07 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/28 23:11:46 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

__uint128_t	number_packet(int len)
{
	__uint128_t	num;

	num = 1;
	while (--len > 0)
	{
		num *= 1000;
	}
	if (num == 1)
		return (0);
	return (num);
}

__uint128_t	ft_atoi_n(char *str, int max)
{
	__uint128_t	n;

	n = 0;
	if (!*str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str >= '0' && *str <= '9' && max > 0)
	{
		n *= 10;
		n += *str - '0';
		str++;
		max--;
	}
	return (n);
}

void	print_d(char *str, int space)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	if (space)
		write(1, " ", 1);
}

void	ft_aff_num(char *nbr, t_dict *dict)
{
	int		len;
	char	*buffer;
	int		rest;

	len = ft_strlen(nbr) / 3 + ((ft_strlen(nbr) % 3) != 0);
	if (!ft_atoi(nbr))
	{
		print_d(dict[find_nb(0, dict)].word, 0);
		return ;
	}
	while (len > 0)
	{
		rest = !(ft_strlen(nbr) % 3) * 3 + ft_strlen(nbr) % 3;
		buffer = tr_nbgroup(ft_atoi_n(nbr, rest), dict);
		if (ft_atoi_n(nbr, rest))
		{
			print_d(buffer, ft_atoi(nbr + rest) || len > 1);
			if (len > 1)
				print_d(dict[find_nb(number_packet(len), dict)].word,
					ft_atoi(nbr + rest));
		}
		nbr += rest;
		len--;
	}
	free(buffer);
}
