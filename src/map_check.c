/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:53:07 by kosakats          #+#    #+#             */
/*   Updated: 2025/02/21 22:41:31 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	size_t	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	count_total_items(t_info *info)
{
	size_t	total;
	int		y;
	int		x;

	total = 0;
	info->map_info.total_items = 0;
	y = 0;
	while (info->map_info.map[y])
	{
		x = 0;
		while (info->map_info.map[y][x])
		{
			if (info->map_info.map[y][x] == 'C')
				total++;
			x++;
		}
		y++;
	}
	info->map_info.total_items = total;
}

int	check_walls(char **map, size_t width, size_t height)
{
	size_t	i;

	if (width != height)
	{
		i = 0;
		while (i < width)
		{
			if (map[0][i] != '1' || map[height - 1][i] != '1')
				return (0);
			i++;
		}
		i = 0;
		while (i < height)
		{
			if (map[i][0] != '1' || map[i][width - 1] != '1')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	check_elements(char **map, t_map *map_info)
{
	size_t	x;
	size_t	y;

	map_info->player_count = 0;
	map_info->exit_count = 0;
	map_info->item_count = 0;
	y = 0;
	while (y < map_info->height)
	{
		x = 0;
		while (x < map_info->width)
		{
			if (map[y][x] == 'P')
				map_info->player_count++;
			else if (map[y][x] == 'E')
				map_info->exit_count++;
			else if (map[y][x] == 'C')
				map_info->item_count++;
			x++;
		}
		y++;
	}
	return (map_info->player_count == 1 && map_info->exit_count == 1
		&& map_info->item_count >= 1);
}

int	validate_map_structure(char **map, size_t width, size_t height,
		t_info *info)
{
	t_map	map_info;

	map_info.width = width;
	map_info.height = height;
	map_info.player_count = 0;
	map_info.item_count = 0;
	map_info.exit_count = 0;
	if (!check_walls(map, width, height))
	{
		exit_error("Invalid map boundaries", info);
	}
	if (!check_elements(map, &map_info))
	{
		exit_error("Invalid map elements", info);
	}
	if (!dfs_main(map, &map_info))
	{
		exit_error("Invalid map connectivity", info);
	}
	return (1);
}
