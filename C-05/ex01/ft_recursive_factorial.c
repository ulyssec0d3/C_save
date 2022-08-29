/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:26:17 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/25 18:19:55 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	if (!nb)
		return (1);
	if (nb == 2)
		return (2);
	i = nb;
		nb *= ft_recursive_factorial(i - 1);
	return (nb);
}
