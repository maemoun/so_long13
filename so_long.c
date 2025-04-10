/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:57:47 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/10 11:07:52 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_list	list;

	if (ac != 2)
		ft_print_error("Error\nInvalid args!\n", NULL, NULL);
	ft_check_file_name(av[1]);
	ft_read_maps(av[1], &list);
	ft_check_maps_errors(&list);
	ft_start_game(&list);
}
