/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:26:27 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/10 13:44:22 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_file_name(char *s)
{
	int	len;

	len = ft_len(s);
	len--;
	if (s[len] == 'r' && s[len - 1] == 'e'
		&& s[len - 2] == 'b' && s[len - 3] == '.')
		return ;
	ft_print_error("Error\nInvalid file name!\n", NULL, NULL);
}
