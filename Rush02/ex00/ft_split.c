/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:14:00 by mjourno           #+#    #+#             */
/*   Updated: 2022/08/28 18:32:29 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

int	ft_len_first_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
		i++;
	return (i);
}

int	ft_len_second_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ' ' <= str[i] && str[i] <= '~')
		i++;
	return (i);
}

char	*ft_affect_word(char *str, int nb)
{
	char	*word;
	int		len;
	int		i;

	if (nb == 0)
		len = ft_len_first_word(str);
	else if (nb == 1)
		len = ft_len_second_word(str);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_error_split(char **result)
{
	if (!result[0] && !result[1])
	{
		free(result);
		return (NULL);
	}
	else if (!result[0] && result[1])
	{
		free(result[1]);
		free(result);
		return (NULL);
	}
	else if (result[0] && !result[1])
	{
		free(result[0]);
		free(result);
		return (NULL);
	}
	return (result);
}

char	**ft_split(char *str)
{
	char	**result;
	int		i;

	i = 0;
	result = malloc(sizeof(char *) * 2);
	if (!result)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13) || str[i] == '+')
			i++;
		if (str[i] && '0' <= str[i] && str[i] <= '9')
			result[0] = ft_affect_word(str + i, 0);
		while (str[i] && (('0' <= str[i] && str[i] <= '9') || str[i] == ' '))
			i++;
		if (str[i] == ':')
			i++;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && ' ' <= str[i] && str[i] <= '~')
			result[1] = ft_affect_word(str + i, 1);
		while (str[i] && ' ' <= str[i] && str[i] <= '~')
			i++;
	}
	return (ft_error_split(result));
}
/*
#include <stdio.h>
int	main (int argc, char **argv)
{
	(void)argc;
	char	**res = ft_split(argv[1]);
	printf("%s %s\n", res[0], res[1]);
	free(res[0]);
	free(res[1]);
	free(res);
}
*/
