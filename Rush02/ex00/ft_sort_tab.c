/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:41:58 by aizsak            #+#    #+#             */
/*   Updated: 2022/08/28 17:18:41 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

void	ft_sort_str(t_dict *tab)
{
	int		i;
	t_dict	tmp;
	int		len;

	i = 0;
	while (tab[i].word)
		i++;
	len = i;
	i = 0;
	while (len >= 0)
	{
		i = 0;
		while (i < len - 1)
		{
			if (tab[i].nb > tab[i + 1].nb)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		len--;
	}
}
