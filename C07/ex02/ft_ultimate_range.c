/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:01:22 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/29 16:26:16 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	*range = malloc(sizeof(int) * (max - min));
	if (range == 0)
		return (0);
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (**range);
}
/*
int	main(int argc, char **argv)
{
	int min = atoi(argv[1]);
	int max = atoi(argv[2]);
	int *inta;
	ft_ultimate_range(&inta, min, max);
	int	i = 0;

	while (i < max - min)
	{
		printf("%d\n", inta[i]);
		i++;
	}
	free (inta);
}
*/
