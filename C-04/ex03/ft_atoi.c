/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:22:52 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/18 21:44:10 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	unsigned int	i;
	unsigned int	temp;
	int				neg;

	neg = 1;
	i = 0;
	temp = i;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		++i;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp += str[i++] - '0';
		if (str[i] >= '0' && str[i] <= '9')
			temp *= 10;
	}
	return (temp * neg);
}
