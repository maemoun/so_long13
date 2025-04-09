/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:09:25 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/09 12:26:05 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_linejoin(char *line_join, char *line)
{
	int		i;
	int		j;
	int		len;
	char	*s;

	len = (ft_len(line_join) + ft_len(line));
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (line_join[i])
		s[j++] = line_join[i++];
	i = 0;
	while (line[i])
		s[j++] = line[i++];
	s[j] = '\0';
	return (s);
}
