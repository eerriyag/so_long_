/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerriyag <eerriyag@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-28 14:15:11 by eerriyag          #+#    #+#             */
/*   Updated: 2025-02-28 14:15:11 by eerriyag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	handle_errors(t_allinfo *allinfo)
{
	free_memory(allinfo->map, allinfo->height);
	free_memory(allinfo->map_cpy, allinfo->height);
	mlx_destroy_window(allinfo->mlx, allinfo->window);
	free(allinfo->mlx);
	return (write(1, "Error\n", 6), 1);
}

int	main(int ac, char **av)
{
	t_allinfo	allinfo;

	if (ac != 2)
		return (write(1, "Error\n", 6), 1);
	if (check_file_name(av[1]) == 1)
		return (write(1, "Error\n", 6), 1);
	allinfo.map = read_map(av[1], &allinfo);
	close(allinfo.fd);
	if (!allinfo.map || !allinfo.map[0])
		return (free_memory(allinfo.map, allinfo.height),
			write(1, "Error\nin read map", 17), 1);
	if (validate_map(allinfo.map, &allinfo) == 1)
	{
		free_memory(allinfo.map, allinfo.height);
		free_memory(allinfo.map_cpy, allinfo.height);
		return (write(1, "Error\n", 6), 1);
	}
	if ((allinfo.width * 50) > 2560 || (allinfo.height * 50) > 1440)
		return (write(1, "Error\n", 6), 1);
	if (render_game(&allinfo) == 1)
		return (handle_errors(&allinfo));
	return (0);
}
