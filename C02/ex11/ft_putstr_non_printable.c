/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:27:18 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/23 11:04:08 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	translate(int a)
{
	char	*basehex;
	char	test[3];

	basehex = "0123456789abcdef";
	test[0] = '\\';
	test[1] = basehex[a / 16];
	test[2] = basehex[a % 16];
	write(1, test, 3);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] >= 127)
			translate(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
