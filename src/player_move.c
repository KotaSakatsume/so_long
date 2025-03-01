/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:53:07 by kosakats          #+#    #+#             */
/*   Updated: 2025/02/21 23:03:55 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_item(t_info *info, int x, int y)
{
	if (info->map_info.map[y][x] == 'C')
	{
		info->map_info.map[y][x] = '0';
		info->player_info.item_count++;
	}
}

void	find_player_position(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (info->map_info.map[y])
	{
		x = 0;
		while (info->map_info.map[y][x])
		{
			if (info->map_info.map[y][x] == 'P')
			{
				info->player_info.x = x;
				info->player_info.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	can_move_to(t_info *info, int x, int y)
{
	char	tile;

	tile = info->map_info.map[y][x];
	if (tile == '1')
		return (0);
	return (1);
}

void	move_player(t_info *info, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = info->player_info.x + dx;
	new_y = info->player_info.y + dy;
	if (info->map_info.map[new_y][new_x] == 'E')
	{
		if (info->player_info.item_count == info->map_info.total_items)
		{
			on_destroy(info);
			return ;
		}
		return ;
	}
	info->map_info.map[info->player_info.y][info->player_info.x] = '0';
	collect_item(info, new_x, new_y);
	info->player_info.x = new_x;
	info->player_info.y = new_y;
	info->map_info.map[info->player_info.y][info->player_info.x] = 'P';
	info->player_info.move_count++;
	ft_printf("move_count:%d\n", info->player_info.move_count);
	draw_map(info);
}
