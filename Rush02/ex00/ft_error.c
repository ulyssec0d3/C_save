/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:01:11 by aizsak            #+#    #+#             */
/*   Updated: 2022/08/28 23:10:21 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

void	error(void)
{
	write (1, "Error", 5);
}

void	dict_error(void)
{
	write (1, "Dict Error", 10);
}

int	find_nb_err(__uint128_t nb, t_dict *dict)
{
	int	i;

	i = 0;
	while ((dict[i].nb != nb) && dict[i].word)
		i++;
	if (!dict[i].word)
		return (1);
	else
		return (0);
}

int	ft_terminado2(int nb, t_dict *dict)
{
	int	err;

	err = 0;
	if (!nb)
		return (find_nb_err(0, dict));
	if (nb >= 100)
	{
		err += find_nb_err(nb / 100, dict) + find_nb_err(100, dict);
		nb %= 100;
	}
	if (nb >= 20)
		err += find_nb_err(nb - (nb % 10), dict);
	else if (nb >= 10)
	{
		err += find_nb_err(nb, dict);
		return (err);
	}
	nb %= 10;
	if (nb)
		err += find_nb_err(nb, dict);
	return (err);
}

int	ft_terminado(char *nbr, t_dict *dict)
{
	int	err;
	int	len;
	int	rest;

	err = 0;
	len = ft_strlen(nbr) / 3 + ((ft_strlen(nbr) % 3) != 0);
	if (!ft_atoi(nbr))
	{
		err += find_nb_err(0, dict);
		return (err);
	}
	while (len > 0)
	{
		rest = !(ft_strlen(nbr) % 3) * 3 + ft_strlen(nbr) % 3;
		if (ft_atoi_n(nbr, rest))
			err += ft_terminado2(ft_atoi_n(nbr, rest), dict);
		if (ft_atoi_n(nbr, rest))
		{
			if (len > 1)
				err += find_nb_err(number_packet(len), dict);
		}
		nbr += rest;
		len--;
	}
	return (err);
}
/*
int	main(int argc, char **argv)
{
	t_dict	*b;

	b = parse_dict(read_file("numbers.dict"));
	if (argc == 2)
		printf("%d\n", ft_terminado(argv[1], b));
}
*/
