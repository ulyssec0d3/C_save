/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:12:47 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/29 13:28:48 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long int	i;

	i = 0;
	while (i * i <= nb)
	{
		if (nb == i * i)
			return (i);
		i++;
	}
	return (0);
}

int	main(void)
{
	printf("%d\n", ft_sqrt(1));
}
