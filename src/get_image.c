/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:53:07 by kosakats          #+#    #+#             */
/*   Updated: 2025/02/21 22:26:12 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_info *info, size_t *width, size_t *height)
{
	int	img_width;
	int	img_height;

	img_width = (int)(*width);
	img_height = (int)(*height);
	info->images_info.wall = mlx_xpm_file_to_image(info->mlx,
			"textures/wall/wall.xpm", &img_width, &img_height);
	info->images_info.tile = mlx_xpm_file_to_image(info->mlx,
			"textures/tile/tile.xpm", &img_width, &img_height);
	info->images_info.player = mlx_xpm_file_to_image(info->mlx,
			"textures/player/player1.xpm", &img_width, &img_height);
	info->images_info.item = mlx_xpm_file_to_image(info->mlx,
			"textures/item/item.xpm", &img_width, &img_height);
	info->images_info.exit = mlx_xpm_file_to_image(info->mlx,
			"textures/exit/exit.xpm", &img_width, &img_height);
	if (!info->images_info.wall || !info->images_info.tile
		|| !info->images_info.player || !info->images_info.item
		|| !info->images_info.exit)
	{
		exit_error("Failed to load images.", info);
	}
}

void	draw_tile(t_info *info, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(info->mlx, info->window, info->images_info.wall,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == '0')
		mlx_put_image_to_window(info->mlx, info->window, info->images_info.tile,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(info->mlx, info->window,
			info->images_info.player, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(info->mlx, info->window, info->images_info.item,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(info->mlx, info->window, info->images_info.exit,
			x * TILE_SIZE, y * TILE_SIZE);
	else
		exit_error("Invalid map tile encountered", info);
}

void	draw_map(t_info *info)
{
	int	x;
	int	y;

	if (!info->map_info.map)
		exit_error("Map is NULL", info);
	y = 0;
	while (info->map_info.map[y])
	{
		x = 0;
		while (info->map_info.map[y][x])
		{
			draw_tile(info, info->map_info.map[y][x], x, y);
			x++;
		}
		y++;
	}
}
