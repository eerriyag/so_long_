/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerriyag <eerriyag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-26 16:08:57 by eerriyag          #+#    #+#             */
/*   Updated: 2025-02-26 16:08:57 by eerriyag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_characters(char **map, t_allinfo *allinfo)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("10PCE", map[i][j]))
				return (1);
			if (map[i][j] == 'P')
				allinfo->person++;
			else if (map[i][j] == 'C')
				allinfo->nb_cb++;
			else if (map[i][j] == 'E')
				allinfo->exit++;
			j++;
		}
		i++;
	}
	return (allinfo->exit != 1 || allinfo->nb_cb == 0
		|| allinfo->person != 1);
}

static int	validate_walls(char **map, t_allinfo *allinfo)
{
	int	i;

	i = 0;
	if (!map || allinfo->height < 3)
		return (1);
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[allinfo->height - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < allinfo->height)
	{
		if (map[i][0] != '1' || map[i][allinfo->width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	verify_map_dimensions(char **map, t_allinfo *allinfo)
{
	int	i;
	int	len;

	i = 0;
	allinfo->width = ft_strlen(map[0]);
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len != allinfo->width)
			return (1);
		i++;
	}
	return (0);
}

int	validate_map(char **map, t_allinfo *allinfo)
{
	allinfo->collectible = 0;
	allinfo->exit = 0;
	allinfo->person = 0;
	allinfo->map_cpy = NULL;
	if (verify_map_dimensions(map, allinfo) || validate_walls(map, allinfo)
		|| validate_characters(map, allinfo) || duplicate_map(map, allinfo)
		|| validate_map_paths(map, allinfo))
		return (1);
	return (0);
}
