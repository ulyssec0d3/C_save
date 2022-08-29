/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:09:07 by mjourno           #+#    #+#             */
/*   Updated: 2022/08/28 18:11:57 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"
#include <stdio.h>

int	is_valid_row(char *str, int i)
{
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	if ('0' <= str[i] && str[i] <= '9')
	{
		while ('0' <= str[i] && str[i] <= '9')
			i++;
		while (str[i] == ' ')
			i++;
		if (str[i] == ':')
		{
			i++;
			while (str[i] == ' ')
				i++;
			if ('!' <= str[i] && str[i] <= '~')
			{
				return (1);
			}
		}
	}
	return (0);
}

int	len_dict(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_valid_row(str, i))
			count++;
		while (str[i] && str[i] != '\n')
			i++;
		i++;
	}
	return (count);
}

int	affect_values(t_dict *dict, char *str, int i, int j)
{
	char	**splitted;

	splitted = ft_split(str + j);
	if (!splitted)
		return (0);
	dict[i].nb = ft_atoi(splitted[0]);
	dict[i].cnb = splitted[0];
	dict[i].word = splitted[1];
	free(splitted);
	return (1);
}

int	parse_values(char *str, t_dict *dict, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (str[j])
		{
			if (is_valid_row(str, j))
			{
				if (affect_values(dict, str, i, j))
					i++;
				else
					return (0);
			}
			while (str[j] && str[j] != '\n')
				j++;
			j++;
		}
	}
	return (1);
}

t_dict	*parse_dict(char *str)
{
	t_dict	*dict;
	int		len;

	len = len_dict(str);
	dict = malloc(sizeof(t_dict) * (len + 1));
	if (!dict)
	{
		free(str);
		return (NULL);
	}
	dict[len].nb = 0;
	dict[len].cnb = NULL;
	dict[len].word = NULL;
	if (!parse_values(str, dict, len))
		return (NULL);
	free(str);
	return (dict);
}
/*
int	main (void)
{
	char *a;
	a = read_file("numbers.dict");
	if (!a)
	{
		putstr("Dict Error\n");
		return (0);
	}
	t_dict	*b = parse_dict(a);
	if (!b)
	{
		putstr("Dict Error\n");
		return (0);
	}
	int	i = 0;
	while (b[i].cnb)
	{
		printf("%u\n", b[i].nb);
		printf("%s\n",b[i].cnb);
		printf("%s\n\n",b[i].word);
		free(b[i].cnb);
		free(b[i].word);
		i++;
	}
	free(b);
	return (0);
}
*/
