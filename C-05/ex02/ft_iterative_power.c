/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:31:38 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/25 18:20:13 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	nbr;

	nbr = nb;
	i = 0;
	if (power < 0)
		return (0);
	if (!power)
		return (1);
	while (++i < power)
		nbr *= nb;
	return (nbr);
}
