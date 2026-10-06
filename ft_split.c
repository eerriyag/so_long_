/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerriyag <eerriyag@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 13:38:32 by eerriyag          #+#    #+#             */
/*   Updated: 2024-10-28 13:38:32 by eerriyag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_word_len(char *s, char c)
{
	int	len_w;
	int	i;

	len_w = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		len_w++;
		i++;
	}
	return (len_w);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

static int	ft_count_words(char *s, char c)
{
	int	count_w;
	int	i;

	count_w = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count_w++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count_w);
}

static char	**free_mem(char **c, int i)
{
	int	index;

	index = 0;
	while (index < i)
	{
		free(c[index]);
		index++;
	}
	free(c);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**arr;
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	arr = (char **)malloc(sizeof(char *) * (ft_count_words(str, c) + 1));
	if (!arr)
		return (NULL);
	while (i < ft_count_words((char *)s, c))
	{
		while (*str == c)
			str++;
		arr[i] = (char *)malloc(sizeof(char) * (ft_word_len(str, c) + 1));
		if (!arr[i])
			return (free_mem(arr, i));
		ft_strlcpy(arr[i], str, (ft_word_len(str, c) + 1));
		str = str + ft_word_len(str, c);
		i++;
	}
	arr[i] = NULL;
	free(s);
	return (arr);
}
