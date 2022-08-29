/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:56:03 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/13 17:10:26 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	firstline(long long cx, long long size)
{
	char	c;

	c = 'A';
	if (size > 2 && cx < size && cx > 1)
	{
		c = 'B';
	}
	if (size > 1 && cx == size)
	{
		c = 'C';
	}
	return (c);
}

char	midline(long long cx, long long size)
{
	char	c;

	c = 'B';
	if (size > 2 && cx < size && cx > 1)
	{
		c = ' ';
	}
	if (size > 1 && cx == size)
	{
		c = 'B';
	}
	return (c);
}

char	lastline(long long cx, long long size)
{
	char	c;

	c = 'C';
	if (size > 2 && cx < size && cx > 1)
	{
		c = 'B';
	}
	if (size > 1 && cx == size)
	{
		c = 'A';
	}
	return (c);
}

void	rush(long long x, long long y)
{
	long long	cx;
	long long	cy;

	cy = 1;
	while (cy <= y)
	{
		cx = 1;
		while (cx <= x)
		{
			if (cy == 1)
				ft_putchar(firstline(cx, x));
			if (y > 2 && cy < y && cy > 1)
				ft_putchar(midline(cx, x));
			if (y > 1 && cy == y)
				ft_putchar(lastline(cx, x));
			cx++;
		}
		ft_putchar('\n');
		cy++;
	}
}
