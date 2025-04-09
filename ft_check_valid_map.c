/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:50:17 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/09 11:46:39 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_player_position(t_list *list)
{
	list->i = 0;
	list->Player_x = 0;
	list->Player_y = 0;
	while (list->i < list->map_height - 1)
	{
		list->j = 0;
		while (list->j < list->map_width)
		{
			list->c = list->map[list->i][list->j];
			if (list->c == 'P')
			{
				list->Player_x = list->j;
				list->Player_y = list->i;
			}
			if (list->c == 'E')
			{
				list->Exit_x = list->j;
				list->Exit_y = list->i;
			}
			list->j++;
		}
		list->i++;
	}
}

void    ft_copy_map(t_list *list)
{
	list->cpy_map = malloc((list->map_height + 1) * sizeof(char *));
	if (!list->cpy_map)
		ft_print_error("Error!\nAllocation failed\n", list->map, NULL);
	list->i = 0;
	while (list->i < list->map_height)
	{
		list->j = 0;
		list->cpy_map[list->i] = malloc((list->map_width + 1) * sizeof(char));
		if (!list->cpy_map[list->i])
		{
			ft_free_map(list->cpy_map);
			ft_print_error("Error!\nAllocation failed\n", list->map, NULL);
		}
		while (list->j < list->map_width)
		{
			list->cpy_map[list->i][list->j] = list->map[list->i][list->j];
			list->j++;
		}
		list->cpy_map[list->i][list->j] = '\0';
		list->i++;
	}
	list->cpy_map[list->i] = NULL;
}

void	ft_flood_fill(char **cpy_map, int x, int y)
{
	if (cpy_map[y][x] == '1')
		return ;
	cpy_map[y][x] = '1';
	ft_flood_fill(cpy_map, x + 1, y);
	ft_flood_fill(cpy_map, x - 1, y);
	ft_flood_fill(cpy_map, x, y + 1);
	ft_flood_fill(cpy_map, x, y - 1);
}

void	ft_check_flood_fill(t_list *list)
{
	list->i = 0;
	
	while (list->i < list->map_height)
	{
		list->j = 0;
		while (list->j < list->map_width)
		{
			list->c = list->cpy_map[list->i][list->j];
			if (list->c != '1' && list->c != '0')
			{
				ft_free_map(list->cpy_map);
				ft_print_error("Error\nInvalid Player Path!\n", list->map, NULL);
			}
			list->j++;
		}
		list->i++;
	}
	ft_free_map(list->cpy_map);
}

void	ft_check_valid_map(t_list *list)
{
	ft_player_position(list);
	ft_copy_map(list);
	ft_flood_fill(list->cpy_map, list->Player_x, list->Player_y);
	ft_check_flood_fill(list);
}
