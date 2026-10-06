/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerriyag <eerriyag@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 21:06:28 by eerriyag          #+#    #+#             */
/*   Updated: 2024-12-10 21:06:28 by eerriyag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*copy;
	int		lengh;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	lengh = ft_strlen(str);
	copy = malloc(lengh + 1);
	if (!copy)
		return (NULL);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *new_buffer, char *buffer)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!new_buffer)
		return (ft_strdup(buffer));
	join = malloc((ft_strlen(new_buffer) + ft_strlen(buffer)) + 1);
	if (!join)
		return (free(new_buffer), NULL);
	while (new_buffer[i])
	{
		join[i] = new_buffer[i];
		i++;
	}
	while (buffer[j])
	{
		join[i] = buffer[j];
		i++;
		j++;
	}
	join[i] = '\0';
	free(new_buffer);
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
