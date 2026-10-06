/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerriyag <eerriyag@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 21:03:04 by eerriyag          #+#    #+#             */
/*   Updated: 2024-12-10 21:03:04 by eerriyag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*delete_until_line(char *new_buffer)
{
	char	*until_line;
	int		length;
	int		i;
	int		j;

	i = 0;
	length = ft_strlen(new_buffer);
	while (new_buffer[i] && new_buffer[i] != '\n')
		i++;
	if (new_buffer[i] == '\n')
		i++;
	until_line = malloc((length - i) + 1);
	if (!until_line)
		return (free(new_buffer), new_buffer = NULL, NULL);
	j = 0;
	while (i < length)
	{
		until_line[j++] = new_buffer[i++];
	}
	until_line[j] = '\0';
	free(new_buffer);
	return (until_line);
}

char	*ft_get_line(char *s)
{
	char	*line;
	int		length;
	int		i;

	i = 0;
	length = 0;
	while (s[length] && s[length] != '\n')
		length++;
	if (s[length] == '\n')
		length++;
	line = malloc(length + 1);
	if (!line)
		return (NULL);
	while (i < length)
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_content(int fd, char *new_buffer)
{
	char	*buffer;
	int		bytes;

	bytes = 1;
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(new_buffer), new_buffer = NULL, NULL);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(new_buffer), new_buffer = NULL, NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		new_buffer = ft_strjoin(new_buffer, buffer);
		if (!new_buffer || ft_strchr(new_buffer, '\n'))
			break ;
	}
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*new_buffer;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE > INT_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	new_buffer = read_content(fd, new_buffer);
	if (!new_buffer || new_buffer[0] == '\0')
		return (free(new_buffer), new_buffer = NULL, NULL);
	line = ft_get_line(new_buffer);
	if (!line)
		return (free(new_buffer), new_buffer = NULL, NULL);
	new_buffer = delete_until_line(new_buffer);
	return (line);
}
