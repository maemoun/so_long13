/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:47:00 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/09 12:34:46 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_maps(char *map, t_list *list)
{
	int		fd;
	char	*line;
	char	*line_join;
	char	*tmp;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_print_error("Error\nCan't Open File Map!\n", NULL, line);
	line = get_next_line(fd);
	if (!line)
		ft_print_error("Error:\nEmpty file / Nothing ..!\n", NULL, NULL);
	list->map_height = 0;
	line_join = ft_strdup("");
	while (line != NULL)
	{
		tmp = ft_linejoin(line_join, line);
		free(line_join);
		free (line);
		line_join = tmp;
		line = get_next_line(fd);
		list->map_height++;
	}
	list->map = ft_split(line_join, '\n');
	free(line_join);
	close(fd);
}
