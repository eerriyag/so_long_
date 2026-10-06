/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerriyag <eerriyag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:26:29 by eerriyag          #+#    #+#             */
/*   Updated: 2025/02/26 16:26:29 by eerriyag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_image(t_allinfo *allinfo, void *pic, int x, int y)
{
	mlx_put_image_to_window(allinfo->mlx, allinfo->window, pic, x * 50, y * 50);
}

void	render_all_map(t_allinfo *allinfo)
{
	int	x;
	int	y;

	y = 0;
	while (y < allinfo->height)
	{
		x = 0;
		while (x < allinfo->width)
		{
			if (allinfo->map_cpy[y][x] == '1')
				read_image(allinfo, allinfo->wall, x, y);
			else if (allinfo->map_cpy[y][x] == 'M'
				|| allinfo->map_cpy[y][x] == '0')
				read_image(allinfo, allinfo->vide, x, y);
			if (allinfo->map[y][x] == 'C')
				read_image(allinfo, allinfo->collectible, x, y);
			x++;
		}
		y++;
	}
	read_image(allinfo, allinfo->door, allinfo->xdoor, allinfo->ydoor);
	read_image(allinfo, allinfo->player, allinfo->xp, allinfo->yp);
}

void	*put_xmp(t_allinfo *allinfo, char *src)
{
	void	*pic;
	int		w;
	int		h;

	pic = mlx_xpm_file_to_image(allinfo->mlx, src, &h, &w);
	if (!pic)
		return (NULL);
	return (pic);
}

int	init_images(t_allinfo *allinfo)
{
	allinfo->door = put_xmp(allinfo, "./textures/port.xpm");
	if (!allinfo->door)
		return (1);
	allinfo->wall = put_xmp(allinfo, "./textures/woodblock.xpm");
	if (!allinfo->wall)
		return (1);
	allinfo->collectible = put_xmp(allinfo, "./textures/collectible1.xpm");
	if (!allinfo->collectible)
		return (1);
	allinfo->player = put_xmp(allinfo, "./textures/player.xpm");
	if (!allinfo->player)
		return (1);
	allinfo->vide = put_xmp(allinfo, "./textures/vide.xpm");
	if (!allinfo->vide)
		return (1);
	render_all_map(allinfo);
	return (0);
}

int	render_game(t_allinfo *allinfo)
{
	int	height_w;
	int	width_w;

	height_w = allinfo->height * 50;
	width_w = allinfo->width * 50;
	allinfo->move_count = 0;
	allinfo->mlx = mlx_init();
	if (!allinfo->mlx)
		return (1);
	if (allinfo->width * 50 > 2560 || allinfo->height * 50 > 1440)
		return (1);
	allinfo->window = mlx_new_window(allinfo->mlx, width_w, height_w,
			"so_long");
	if (!allinfo->window)
		return (free(allinfo->mlx), 1);
	if (init_images(allinfo) == 1)
		return (1);
	mlx_key_hook(allinfo->window, handle_keys, allinfo);
	mlx_hook(allinfo->window, 17, 0, destroy_window, allinfo);
	mlx_loop(allinfo->mlx);
	return (0);
}
