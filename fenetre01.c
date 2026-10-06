/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerriyag <eerriyag@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-16 15:38:44 by eerriyag          #+#    #+#             */
/*   Updated: 2025-02-16 15:38:44 by eerriyag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_moves(t_allinfo *allinfo, int x, int y)
{
	if (allinfo->map[y][x] != '1')
	{
		if (allinfo->map[y][x] == 'C')
			allinfo->nb_cb -= 1;
		allinfo->map[allinfo->yp][allinfo->xp] = '0';
		allinfo->xp = x;
		allinfo->yp = y;
		allinfo->map[y][x] = 'P';
		allinfo->move_count += 1;
		if (x == allinfo->xdoor && y == allinfo->ydoor && allinfo->nb_cb == 0)
		{
			ft_putnbr(allinfo->move_count);
			write(1, "\n", 1);
			free_memory(allinfo->map, allinfo->height);
			free_memory(allinfo->map_cpy, allinfo->height);
			exit(1);
		}
		ft_putnbr(allinfo->move_count);
		write(1, "\n", 1);
	}
	render_all_map(allinfo);
}

int	handle_keys(int keycode, t_allinfo *allinfo)
{
	int	new_x;
	int	new_y;

	new_x = allinfo->xp;
	new_y = allinfo->yp;
	if (keycode == 53)
	{
		free_memory(allinfo->map, allinfo->height);
		free_memory(allinfo->map_cpy, allinfo->height);
		exit(1);
	}
	else if (keycode == 2)
		new_x++;
	else if (keycode == 0)
		new_x--;
	else if (keycode == 1)
		new_y++;
	else if (keycode == 13)
		new_y--;
	if (new_x != allinfo->xp || new_y != allinfo->yp)
		handle_moves(allinfo, new_x, new_y);
	return (0);
}

int	destroy_window(void *allinfo)
{
	t_allinfo	*stop;

	stop = allinfo;
	free_memory(stop->map, stop->height);
	free_memory(stop->map_cpy, stop->height);
	exit(1);
}
