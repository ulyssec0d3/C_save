/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:51:07 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/17 15:11:23 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	c;
	int	temp;

	c = 0;
	size--;
	while (c < size)
	{
		temp = tab[size];
		tab[size] = tab[c];
		tab[c] = temp;
		c++;
		size--;
	}
}
