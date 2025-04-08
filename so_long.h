/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:57:50 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/08 13:31:08 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./get_next_line/get_next_line.h"


#include <stdio.h>



typedef struct s_list
{
	char **map;
	int map_width;
	int map_height;
	int	i;
	int	count_c;
	int count_e;
	int count_p;
	int	j;
	char	c;
} t_list;


void    ft_check_file_name(char *s);
void    ft_print_error(char *s, char **map, char *line);
size_t	ft_len(const char *s);
char	*ft_linejoin(char *str, char *line);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void    ft_read_maps(char *map, t_list *list);
void	ft_check_maps_errors(t_list *list);

#endif