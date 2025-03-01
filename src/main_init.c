/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:53:07 by kosakats          #+#    #+#             */
/*   Updated: 2025/02/21 21:59:44 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map_info)
{
	if (!map_info)
		return ;
	map_info->map = NULL;
	map_info->player_count = 0;
	map_info->item_count = 0;
	map_info->total_items = 0;
	map_info->exit_count = 0;
	map_info->width = 0;
	map_info->height = 0;
}

void	init_player(t_player *player_info)
{
	if (!player_info)
		return ;
	player_info->x = 0;
	player_info->y = 0;
	player_info->item_count = 0;
	player_info->move_count = 0;
}

void	init_images(t_images *images_info)
{
	if (!images_info)
		return ;
	images_info->tile = NULL;
	images_info->wall = NULL;
	images_info->item = NULL;
	images_info->exit = NULL;
	images_info->player = NULL;
	images_info->size = 0;
}

t_info	*init_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->mlx = NULL;
	info->window = NULL;
	info->player_info.item_count = 0;
	info->player_info.move_count = 0;
	init_map(&info->map_info);
	init_player(&info->player_info);
	init_images(&info->images_info);
	return (info);
}
