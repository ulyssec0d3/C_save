/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:21:27 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/15 10:13:29 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_switch(int *tab, int a, int b)
{
	int	temp;

	temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	a;

	a = 0;
	if (size == 1)
	{
		return ;
	}
	while (a < size - 1)
	{
		if (tab[a] > tab[a + 1])
		{
			ft_switch(tab, a, a + 1);
			a = -1;
		}
		a++;
	}
}
