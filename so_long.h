/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerriyag <eerriyag@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-26 16:06:16 by eerriyag          #+#    #+#             */
/*   Updated: 2025-02-26 16:06:16 by eerriyag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include "g_n_l/get_next_line.h"

typedef struct s_allinfo
{
	int		fd;
	char	**map;
	char	**map_cpy;
	int		width;
	int		height;
	int		person;
	int		exit;
	int		xp;
	int		yp;
	int		xdoor;
	int		ydoor;
	int		nb_cb;
	void	*mlx;
	void	*window;
	void	*wall;
	void	*vide;
	void	*collectible;
	void	*door;
	void	*player;
	int		move_count;
}	t_allinfo;

int		init_images(t_allinfo *allinfo);
int		render_game(t_allinfo *allinfo);
int		check_file_name(char *str);
char	**read_map(char *file_name, t_allinfo *allinfo);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	**ft_split(char *s, char c);
void	free_memory(char **map, int i);
int		validate_map(char **map, t_allinfo *allinfo);
int		validate_map_paths(char **map, t_allinfo *allinfo);
void	locate_player_and_exit(char **map, t_allinfo *allinfo);
int		duplicate_map(char **map, t_allinfo *allinf);
void	ft_putnbr(int nbr);
int		handle_keys(int keycode, t_allinfo *allinfo);
void	handle_moves(t_allinfo *allinfo, int x, int y);
int		destroy_window(void *allinfo);
void	render_all_map(t_allinfo *allinfo);

#endif