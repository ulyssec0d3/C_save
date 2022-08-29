/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:03:14 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/20 14:22:24 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printf_n(char *tab, int size)
{
	write(1, tab, size);
}

void	ft_reset_tab(char *tab, int na, int n)
{
	while (na < n -1 && n > 1)
	{
		tab[na + 1] = tab[na] + 1;
		na++;
	}
}

void	ft_recurs_combn(char *tab, int n, int gbl_cntr)
{
	ft_printf_n(tab, n);
	if (tab[0] <= (9 - n) + '0')
		write(1, ", ", 2);
	if (tab[n - 1 - gbl_cntr] >= (9 - gbl_cntr + '0')
		&& tab[0] <= (9 - n) + '0')
	{
		gbl_cntr++;
		tab[n -1 - gbl_cntr]++;
		ft_reset_tab(tab, n - gbl_cntr - 1, n);
		ft_recurs_combn(tab, n, gbl_cntr);
	}
	if (tab[n - 1 - gbl_cntr] < (9 - gbl_cntr + '0'))
	{
		if (gbl_cntr != 0)
			gbl_cntr = 0;
		tab[n -1 - gbl_cntr]++;
		ft_recurs_combn(tab, n, gbl_cntr);
	}
}

void	ft_print_combn(int n)
{
	char	tab[10];
	int		gbl_cntr;

	gbl_cntr = 0;
	tab[0] = '0';
	ft_reset_tab(tab, 0, n);
	ft_recurs_combn(tab, n, gbl_cntr);
}
