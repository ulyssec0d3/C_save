/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:06:53 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/29 16:26:01 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*str;
	int	i;

	i = 0;
	str = malloc(sizeof(int) * (max - min));
	if (str == 0)
		return (0);
	while (min < max)
	{
		str[i] = min;
		min++;
		i++;
	}
	return (str);
}
/*
int	main(int argc, char **argv)
{
	int min = atoi(argv[1]);
	int max = atoi(argv[2]);
	int *inta = ft_range(min, max);
	int	i = 0;

	while (i < max - min)
	{
		printf("%d\n", inta[i]);
		i++;
	}
	free (inta);
}
*/
