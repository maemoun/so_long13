/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_maps_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:09:36 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/08 15:43:39 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_same_lines(t_list *list)
{
	int len_line;

	list->map_width = ft_len(list->map[0]);
	list->i = 1;
	while (list->i < list->map_height)
	{
		len_line = ft_len(list->map[list->i]);
		if (len_line != list->map_width)
			ft_print_error("Error\nLines Different!\n", list->map, NULL);
		list->i++;
	}
}

void	ft_maps_sides(t_list *list)
{
	list->i = 0;
	while (list->map[0][list->i])
	{
		if (list->map[0][list->i] != '1')
			ft_print_error("Error!\nInvalid Map Sides!", list->map, NULL);
		list->i++;
	}
	list->i = 0;
	while (list->map[list->map_height - 1][list->i])
	{
		if (list->map[list->map_height - 1][list->i] != '1')
			ft_print_error("Error!\nInvalid Map Sides!", list->map, NULL);
		list->i++;
	}
	list->i = 1;
	while (list->i < list->map_height - 1)
	{
		if (list->map[list->i][0] != '1' || list->map[list->i][list->map_width - 1] != '1')
			ft_print_error("Error!\nInvalid Map Sides!", list->map, NULL);
		list->i++;
	}
}

void	ft_check_chars(t_list *list)
{
	list->count_c = 0;
	list->count_e = 0;
	list->count_p = 0;
	list->i = 1;
	while (list->i < list->map_height - 1)
	{
		list->j = 1;
		while (list->map[list->i][list->j])
		{
			list->c = list->map[list->i][list->j];
			if (list->c == 'C')
				list->count_c++;
			if (list->c == 'E')
				list->count_e++;
			if (list->c == 'P')
				list->count_p++;
			if (list->c != '1' && list->c != '0' && list->c != 'C' && list->c != 'E' && list->c != 'P')
				ft_print_error("Error!\nInvalid map chars..!", list->map, NULL);
			list->j++;
		}
		list->i++;
	}
	if (list->count_c == 0 || list->count_e != 1 || list->count_p != 1)
		ft_print_error("Error!\nInvalid map chars..!", list->map, NULL);
}

void	ft_check_maps_errors(t_list *list)
{
	ft_check_same_lines(list);
	ft_maps_sides(list);
	ft_check_chars(list);
	ft_check_valid_map(list);
}