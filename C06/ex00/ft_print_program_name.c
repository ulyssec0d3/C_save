/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 23:06:17 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/18 23:18:27 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	temp;

	temp = 0;
	while (argv[0][temp] && argc == 1)
	{
		write(1, &argv[0][temp], 1);
		temp++;
	}
	write(1, "\n", 1);
	return (0);
}
