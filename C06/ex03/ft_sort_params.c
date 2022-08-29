/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:46:03 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/25 14:57:55 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_switch(char **tab, int a, int b)
{
	char	*temp;

	temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}

void	ft_sort_char_tab(char **argv, int argc)
{
	int	a;
	int	b;

	a = argc - 1;
	if (argc < 1)
	{
		return ;
	}
	while (a > 1)
	{
		b = 1;
		while (b < a)
		{
			if (ft_strcmp(argv[b], argv[b + 1]) > 0)
				ft_switch(argv, b, b + 1);
			b++;
		}
		a--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	len;

	ft_sort_char_tab(argv, argc);
	i = 0;
	while (++i < argc)
	{
		len = 0;
		while (argv[i][len])
			len++;
		write(1, argv[i], len);
		write(1, "\n", 1);
	}
	return (0);
}
