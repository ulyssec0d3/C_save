/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:28:32 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/13 17:07:55 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	firstline(long long cx, long long size)
{
	char	c;

	c = '/';
	if (size > 2 && cx < size && cx > 1)
	{
		c = '*';
	}
	if (size > 1 && cx == size)
	{
		c = '\\';
	}
	return (c);
}

char	midline(long long cx, long long size)
{
	char	c;

	c = '*';
	if (size > 2 && cx < size && cx > 1)
	{
		c = ' ';
	}
	if (size > 1 && cx == size)
	{
		c = '*';
	}
	return (c);
}

char	lastline(long long cx, long long size)
{
	char	c;

	c = '\\';
	if (size > 2 && cx < size && cx > 1)
	{
		c = '*';
	}
	if (size > 1 && cx == size)
	{
		c = '/';
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
