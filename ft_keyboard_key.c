/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:47:14 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/09 19:25:15 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_valid_move(t_list *list, int x, int y)
{
	if (list->map[y][x] != '1')
		return (1);
	return(0);
}

void	ft_move_player(t_list *list, int x, int y)
{
	list->player_x = x;
	list->player_y = y;
	list->move_count++;
	mlx_delete_image(list->win, list->player_img);
	if (list->map[y][x] == 'C')
	{
		list->count_c--;
		list->map[y][x] = '0';
		mlx_image_to_window(list->win, list->background_img, x * 70, y * 70);
	}
	ft_putstr("moves == ");
	ft_putnbr(list->move_count);
	ft_putstr("\n");
	list->player_img = mlx_texture_to_image(list->win, list->player_txt);
	mlx_image_to_window(list->win, list->player_img, x * 70, y * 70);
}

void	ft_keyboard_key(mlx_key_data_t k, void	*tmp)
{
	t_list	*list;
	int		x;
	int		y;

	list = (t_list *)tmp;
	x = list->player_x;
	y = list->player_y;
	if (list->map[list->player_y][list->player_x] == 'E' && list->count_c == 0)
	{
		ft_putstr("Finlly ===> Win!");
		return(mlx_close_window(list->win));
	}
	if (k.action == MLX_PRESS || k.action == MLX_REPEAT)
	{
		if (k.key == MLX_KEY_UP && (ft_valid_move(list, x, y - 1) == 1))
			ft_move_player(list, x, y - 1);
		else if (k.key == MLX_KEY_DOWN && (ft_valid_move(list, x, y + 1) == 1))
			ft_move_player(list, x, y + 1);
		else if (k.key == MLX_KEY_LEFT && (ft_valid_move(list, x - 1, y) == 1))
			ft_move_player(list, x - 1, y);
		else if (k.key == MLX_KEY_RIGHT && (ft_valid_move(list, x + 1, y) == 1))
			ft_move_player(list, x + 1, y);
		else if (k.key == MLX_KEY_ESCAPE)
			mlx_close_window(list->win);
	}
}