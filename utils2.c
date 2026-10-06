/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerriyag <eerriyag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-15 14:19:54 by eerriyag          #+#    #+#             */
/*   Updated: 2025-02-15 14:19:54 by eerriyag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	explore_map(char **map, int x, int y, t_allinfo *allinfo)
{
	if (x < 0 || x >= allinfo->width || y < 0 || y >= allinfo->height
		|| map[y][x] == 'M' || map[y][x] == '1')
		return ;
	map[y][x] = 'M';
	explore_map(map, x, y + 1, allinfo);
	explore_map(map, x, y - 1, allinfo);
	explore_map(map, x + 1, y, allinfo);
	explore_map(map, x - 1, y, allinfo);
}

int	has_unreachable_coins_or_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_map_paths(char **map, t_allinfo *allinfo)
{
	locate_player_and_exit(map, allinfo);
	explore_map(allinfo->map_cpy, allinfo->xp, allinfo->yp, allinfo);
	if (has_unreachable_coins_or_exit(allinfo->map_cpy))
	{
		free_memory(allinfo->map_cpy, allinfo->height);
		allinfo->map_cpy = NULL;
		return (1);
	}
	return (0);
}
