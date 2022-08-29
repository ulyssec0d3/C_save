/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:30:06 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/29 18:35:57 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

void	fill_str(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i++] = '\0';
	}
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

int	ft_strtotlen(char *sep, int size, char **strs)
{
	int	i;
	int	len;

	len = ft_strlen(sep) * size + 1;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		lentot;
	int		i;
	char	*strtot;

	if (!size)
	{
		strtot = malloc(sizeof(char));
		*strtot = '\0';
		return (strtot);
	}
	lentot = ft_strtotlen(sep, size, strs);
	strtot = malloc(sizeof(char) * lentot);
	if (strtot == 0)
		return (NULL);
	fill_str(strtot, lentot);
	i = 0;
	while (ft_strlen(strtot) < lentot)
	{
		ft_strcat(strtot, strs[i]);
		if (i < size)
			ft_strcat(strtot, sep);
		i++;
	}
	strtot[lentot - 1] = '\0';
	return (strtot);
}
/*
#include <stdio.h>

int main()
{
    char *str[4];
    char *k;
    char *l = "---\\";
    char *o = "laya";
    char *t = "est";
    char *q = "";
    char *a = "gauffre";

    str[0] = o;
    str[1] = t;
    str[2] = q;
    str[3] = a;

    k = ft_strjoin(0, str, l);
    printf("%s", k);
    free(k);
    return (0);
}
*/
