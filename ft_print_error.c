/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:35:04 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/08 13:17:39 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_print_error(char *s, char **map, char *line)
{
	if (map != NULL)
		ft_free_map(map);
	if (line != NULL)
		free(line);
	int i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	exit(1);
}