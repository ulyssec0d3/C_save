/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_include.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:53:30 by aizsak            #+#    #+#             */
/*   Updated: 2022/08/28 23:12:54 by ulevallo         ###   ########.fr       */
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
	__uint128_t		nb;
	char			*cnb;
	char			*word;
}	t_dict;

void		ft_aff_num(char *nbr, t_dict *dict);
int			ft_strlen(char *str);
void		putstr(char *str);
char		*ft_strcat(char *dest, char *src);
int			ft_strncmp(char *s1, char *s2, int n);
__uint128_t	ft_atoi(char *str);
void		ft_sort_str(t_dict *tab);
char		**ft_split(char *tab);
char		*read_file(char *file);
__uint128_t	find_nb(__uint128_t nb, t_dict *dict);
char		*tr_nbgroup(__uint128_t nb, t_dict *dict);
t_dict		*parse_dict(char *str);
void		error(void);
void		dict_error(void);
__uint128_t	number_packet(int len);
__uint128_t	ft_atoi_n(char *str, int max);

#endif
