/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerriyag <eerriyag@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-15 11:51:17 by eerriyag          #+#    #+#             */
/*   Updated: 2025-02-15 11:51:17 by eerriyag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**allocate_map_memory(t_allinfo *allinfo)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (allinfo->height + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < allinfo->height)
	{
		map[i] = (char *)malloc(sizeof(char) * (allinfo->width + 1));
		if (!map[i])
		{
			free_memory(map, i);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	duplicate_map(char **map, t_allinfo *allinfo)
{
	int	i;
	int	j;

	i = 0;
	allinfo->map_cpy = allocate_map_memory(allinfo);
	if (!allinfo->map_cpy)
		return (1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			allinfo->map_cpy[i][j] = map[i][j];
			j++;
		}
		allinfo->map_cpy[i][j] = '\0';
		i++;
	}
	allinfo->map_cpy[i] = NULL;
	return (0);
}
