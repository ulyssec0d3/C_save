/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:32:40 by mjourno           #+#    #+#             */
/*   Updated: 2022/08/28 20:36:44 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

int	len_file(char *file)
{
	int		i;
	int		fd;
	char	*garbage[1];

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	i = 0;
	while (read(fd, garbage, 1))
	{
		i++;
	}
	if (close(fd) == -1)
	{
		return (0);
	}
	return (i);
}

char	*read_file(char *file)
{
	int		fd;
	int		len;
	char	*result;

	len = len_file(file);
	if (!len)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		return (NULL);
	}
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	read(fd, result, len);
	result[len] = '\0';
	if (close(fd) == -1)
	{
		return (NULL);
	}
	return (result);
}
/*
int	main(void)
{
	char	*a = read_file("numbers.dict");
	putstr(a);
	free(a);
}
*/
