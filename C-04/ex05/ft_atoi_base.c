/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:55:51 by ulevallo          #+#    #+#             */
/*   Updated: 2022/08/24 13:21:43 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (base[i])
	{
		c = base[i];
		j = i++;
		while (base[++j])
			if (c == base[j] || c == '+' || c == '-'
				|| base[j] == ' ' || (base[j] >= '\t' && base[j] <= '\r'))
				return (0);
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int				i;
	int				len;
	int				sign;
	unsigned int	res;

	len = check_base(base);
	if (len = 0)
		return (0);
	i = 0;
	res = 0;

	while ()
	{

	}

}
