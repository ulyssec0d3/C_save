/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_include.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:53:30 by aizsak            #+#    #+#             */
/*   Updated: 2022/08/28 14:26:54 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INCLUDE_H
# define FT_INCLUDE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_dict
{
	unsigned int	nb;
	char			*cnb;
	char			*word;
}	t_dict;

int		ft_strlen(char *str);
void	putstr(char *str);
char	*ft_strcat(char *dest, char *src);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_atoi(char *str);
void	ft_sort_str(t_dict *tab);
char	**ft_split(char *tab);
char	*read_file(char *file);
int		find_nb(unsigned int nb, t_dict *dict);
char	*tr_nbgroup(unsigned int nb, t_dict *dict);
//int	main(int argc, char **argv);

#endif
