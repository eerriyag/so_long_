/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: studentname <studentemail@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:00:00 by studentname       #+#    #+#             */
/*   Updated: 2025/02/24 12:00:00 by studentname      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *file_name, t_allinfo *allinfo)
{
	char	*map;
	char	*line;

	allinfo->fd = open(file_name, O_RDONLY);
	if (allinfo->fd < 0)
		return (NULL);
	allinfo->height = 0;
	map = ft_strdup("");
	if (!map)
		return (NULL);
	while (1)
	{
		line = get_next_line(allinfo->fd);
		if (!line)
			break ;
		if (line[0] == '\n' || line[0] == '\0')
			return (free(line), free(map), NULL);
		map = ft_strjoin(map, line);
		free(line);
		allinfo->height += 1;
	}
	return (ft_split(map, '\n'));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	check_file_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[0] != '\0')
	{
		while (str[i] != '.')
			i--;
		if (i == 0 || ft_strcmp(&str[i], ".ber") != 0)
			return (1);
	}
	return (0);
}

void	free_memory(char **map, int i)
{
	if (map)
	{
		while (i >= 0)
		{
			free(map[i]);
			i--;
		}
		free(map);
	}
}

void	locate_player_and_exit(char **map, t_allinfo *allinfo)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				allinfo->ydoor = i;
				allinfo->xdoor = j;
			}
			else if (map[i][j] == 'P')
			{
				allinfo->yp = i;
				allinfo->xp = j;
			}
			j++;
		}
		i++;
	}
}
