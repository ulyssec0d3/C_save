/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transalte_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:38:40 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/28 23:11:43 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

__uint128_t	find_nb(__uint128_t nb, t_dict *dict)
{
	__uint128_t	i;

	i = 0;
	while ((dict[i].nb != nb) && dict[i].word)
		i++;
	if (!dict[i].word)
		return (0);
	else
		return (i);
}

int	nb_len(__uint128_t nb, t_dict *dict)
{
	int	len;

	len = 0;
	if (!nb)
		return (ft_strlen(dict[find_nb(0, dict)].word));
	if (nb >= 100)
	{
		len += ft_strlen(dict[find_nb(nb / 100, dict)].word)
			+ ft_strlen(dict[find_nb(100, dict)].word) + 2;
		nb %= 100;
	}
	if (nb >= 20)
		len += ft_strlen(dict[find_nb(nb - (nb % 10), dict)].word) + 1;
	else if (nb >= 10)
	{
		len += ft_strlen(dict[find_nb(nb, dict)].word) + 1;
		return (len);
	}
	nb %= 10;
	if (nb)
		len += ft_strlen(dict[find_nb(nb, dict)].word) + 1;
	return (len);
}

char	*ft_strcat2(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = ' ';
	return (dest);
}

char	*init_nbstr(int len)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * len);
	if (str == 0)
		return (NULL);
	while (i < len)
		str[i++] = '\0';
	return (str);
}

char	*tr_nbgroup(__uint128_t nb, t_dict *dict)
{
	char			*wnumber;
	unsigned int	len;

	len = nb_len(nb, dict);
	wnumber = init_nbstr(len);
	if (!nb)
		return (ft_strcat2(wnumber, dict[find_nb(0, dict)].word));
	if (nb >= 100)
	{
		ft_strcat2(wnumber, dict[find_nb(nb / 100, dict)].word);
		ft_strcat2(wnumber, dict[find_nb(100, dict)].word);
		nb %= 100;
	}
	if (nb >= 20)
		ft_strcat2(wnumber, dict[find_nb(nb - (nb % 10), dict)].word);
	else if (nb >= 10)
	{
		ft_strcat(wnumber, dict[find_nb(nb, dict)].word);
		return (wnumber);
	}
	nb %= 10;
	if (nb)
		ft_strcat2(wnumber, dict[find_nb(nb, dict)].word);
	wnumber[len - 1] = '\0';
	return (wnumber);
}
