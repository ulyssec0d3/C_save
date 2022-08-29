/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:14:42 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/29 15:05:24 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*laya;
	int		i;

	i = 0;
	while (src[i])
		i++;
	*laya = malloc(sizeof(char) * i);
	i = 0;
	while (src[i])
	{
		laya[i] = src[i];
		i++;
	}
	laya[i] = '\0';
	return (laya);
}

/*
void main()
{
	char *b;
	char c[] = "lalalla";

	b = ft_strdup(c);
	printf("%s", b);
	free(b);
}
*/
