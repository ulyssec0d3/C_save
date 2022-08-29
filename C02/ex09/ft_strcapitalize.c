/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:04:46 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/22 14:02:55 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	credit;

	i = 0;
	credit = 1;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z' && !credit)
			str[i] += 32;
		if ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] >= 'A' && str[i] <= 'Z' && credit == 1))
			credit = 0;
		if ((str[i] < 'a' || str[i] > 'z')
			&& (str[i] < 'A' || str[i] > 'Z')
			&& (str[i] < '0' || str[i] > '9'))
			credit = 1;
		if (str[i] >= 'a' && str[i] <= 'z' && credit == 1)
		{
			str[i] -= 32;
			credit = 0;
		}
		++i;
	}
	return (str);
}
