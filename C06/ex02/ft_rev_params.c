/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:23:23 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/19 11:24:57 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	temp;
	int	i;

	temp = 0;
	i = argc - 1;
	while (i > 0)
	{
		write(1, &argv[i][temp], 1);
		temp++;
		if (!argv[i][temp])
		{
			write(1, "\n", 1);
			i--;
			temp = 0;
		}
	}
	return (0);
}
