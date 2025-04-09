/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:45:47 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/09 20:11:59 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_texture(t_list *list)
{
	list->wall_txt = mlx_load_png("wall.png");
	list->coin_txt = mlx_load_png("coin.png");
	list->player_txt = mlx_load_png("player.png");
	list->grnd_txt = mlx_load_png("grnd.png");
	list->exit_txt = mlx_load_png("exit.png");
	if (!list->wall_txt || !list->coin_txt || !list->player_txt
		|| !list->grnd_txt || !list->exit_txt)
	{
		if (list->player_txt)
			mlx_delete_texture(list->player_txt);
		ft_del_textures(list);
		ft_print_error("Error\nFailed : textures!", list->map, NULL);
	}
}

void	ft_mlx_image(t_list *list)
{
	list->wall_img = mlx_texture_to_image(list->win, list->wall_txt);
	list->coin_img = mlx_texture_to_image(list->win, list->coin_txt);
	list->player_img = mlx_texture_to_image(list->win, list->player_txt);
	list->grnd_img = mlx_texture_to_image(list->win, list->grnd_txt);
	list->exit_img = mlx_texture_to_image(list->win, list->exit_txt);
	ft_del_textures(list);
	if (!list->wall_img || !list->coin_img || !list->player_img
		|| !list->grnd_img || !list->exit_img)
	{
		if (list->player_txt)
			mlx_delete_texture(list->player_txt);
		ft_del_images(list);
		ft_print_error("Error\nFailed : textures to images!\n", list->map, NULL);
	}
}

void	ft_mlx_image_to_window(t_list *list)
{
	list->i = 0;
	while (list->i < list->map_height)
	{
		list->j = 0;
		while (list->j < list->map_width)
		{
			list->c = list->map[list->i][list->j];
			if (list->c == '0' || list->c == 'P')
				mlx_image_to_window(list->win, list->grnd_img, list->j * 70, list->i * 70);
			if (list->c == '1')
				mlx_image_to_window(list->win, list->wall_img, list->j * 70, list->i * 70);
			if (list->c == 'C')
				mlx_image_to_window(list->win, list->coin_img, list->j * 70, list->i * 70);
			if (list->c == 'P')
				mlx_image_to_window(list->win, list->player_img, list->j * 70, list->i * 70);
			if (list->c == 'E')
				mlx_image_to_window(list->win, list->exit_img, list->j * 70, list->i * 70);
			list->j++;
		}
		list->i++;
	}
}

void	ft_start_game(t_list *list)
{
	list->win_width = list->map_width * 70;
	list->win_height = list->map_height * 70;
	if (list->win_width > 2400 || list->win_height > 1350)
	{
		ft_print_error("Error\nLong Map...!", list->map, NULL);
	}
	list->win = mlx_init(list->win_width, list->win_height, "SO_LONG", 0);
	ft_mlx_texture(list);
	ft_mlx_image(list);
	ft_mlx_image_to_window(list);
	list->move_count = 0;
	mlx_key_hook(list->win, ft_keyboard_key, list);
	mlx_loop(list->win);
	mlx_delete_texture(list->player_txt);
	ft_free_map(list->map);
	mlx_terminate(list->win);
}
