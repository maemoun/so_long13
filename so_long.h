/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:57:50 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/09 12:32:57 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./get_next_lines/get_next_line.h"
# include <stdio.h>

typedef struct s_list
{
	char	**map;
	int		map_width;
	int		map_height;
	int		i;
	int		count_c;
	int		count_e;
	int		count_p;
	int		j;
	char	c;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	char	**cpy_map;
}	t_list;

void	ft_check_file_name(char *s);
void	ft_print_error(char *s, char **map, char *line);
size_t	ft_len(const char *s);
char	*ft_linejoin(char *str, char *line);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void	ft_free_map(char **map);
void	ft_read_maps(char *map, t_list *list);
void	ft_check_maps_errors(t_list *list);
void	ft_check_valid_map(t_list *list);

#endif