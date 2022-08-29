/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:26:13 by aizsak            #+#    #+#             */
/*   Updated: 2022/08/28 23:15:13 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

char	*verif_enter(char *start)
{
	__uint128_t	nbr;
	__uint128_t	max;
	int			i;

	i = -1;
	while (start[++i])
		if (!('0' <= start[i] && start[i] <= '9'))
			return (NULL);
	nbr = ft_atoi(start);
	max = 1000000000;
	max *= 1000000000;
	max *= 1000000000;
	max *= 1000000000;
	max *= 1000;
	if (nbr >= max)
	{
		return (NULL);
	}
	return (start);
}

void	launch_functions(char *nbr, char *dico_name)
{
	char	*str;
	t_dict	*dict;
	int		i;

	str = read_file(dico_name);
	if (!str)
		return (dict_error());
	dict = parse_dict(str);
	if (!dict)
	{
		free(str);
		return (dict_error());
	}
	ft_sort_str(dict);
	ft_aff_num(nbr, dict);
	i = 0;
	while (dict[i].cnb)
	{
		free(dict[i].cnb);
		free(dict[i].word);
		i++;
	}
	free (dict);
}

int	main(int argc, char **argv)
{
	char		*nbr;
	char		*dict;

	if (argc > 1 && argc <= 3)
	{
		dict = "numbers.dict";
		nbr = argv[1];
		if (argc == 3)
		{
			dict = argv[1];
			nbr = argv[2];
		}
		if (!(verif_enter(nbr)))
		{
			error();
			write (1, "\n", 1);
			return (0);
		}
		launch_functions(nbr, dict);
		write (1, "\n", 1);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
