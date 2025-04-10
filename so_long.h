/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:57:50 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/10 13:44:59 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "/Users/maeskhai/Desktop/MLX42/include/MLX42/MLX42.h"

typedef struct s_list
{
	char			**map;
	int				map_width;
	int				map_height;
	int				i;
	int				count_c;
	int				count_e;
	int				count_p;
	int				move_count;
	int				j;
	char			c;
	int				player_x;
	int				player_y;
	int				exit_x;
	int				exit_y;
	char			**cpy_map;
	mlx_t			*win;
	int				win_width;
	int				win_height;
	mlx_texture_t	*wall_txt;
	mlx_texture_t	*coin_txt;
	mlx_texture_t	*player_txt;
	mlx_texture_t	*grnd_txt;
	mlx_texture_t	*exit_txt;
	mlx_image_t		*wall_img;
	mlx_image_t		*coin_img;
	mlx_image_t		*player_img;
	mlx_image_t		*grnd_img;
	mlx_image_t		*exit_img;
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
void	ft_start_game(t_list *list);
void	ft_del_textures(t_list *list);
void	ft_del_images(t_list *list);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_keyboard_key(mlx_key_data_t k, void	*tmp);

char	*get_next_line(int fd);
void	ft_readjoin(int fd, char **next1);
char	*ft_new_line(char *next1);
char	*ft_next(char *next1);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
void	ft_free(char **s1, char **s2);
size_t	ft_strlen(char *s);

#endif
