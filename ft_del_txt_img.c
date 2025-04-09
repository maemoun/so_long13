/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_txt_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:18:26 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/09 20:11:28 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_del_textures(t_list *list)
{
	if (list->wall_txt)
		mlx_delete_texture(list->wall_txt);
	if (list->coin_txt)
		mlx_delete_texture(list->coin_txt);
	if (list->grnd_txt)
		mlx_delete_texture(list->grnd_txt);
	if (list->exit_txt)
		mlx_delete_texture(list->exit_txt);
}

void	ft_del_images(t_list *list)
{
	if (list->wall_img)
		mlx_delete_image(list->win, list->wall_img);
	if (list->coin_img)
		mlx_delete_image(list->win, list->coin_img);
	if (list->grnd_img)
		mlx_delete_image(list->win, list->grnd_img);
	if (list->player_img)
		mlx_delete_image(list->win, list->player_img);
	if (list->exit_img)
		mlx_delete_image(list->win, list->exit_img);
}
