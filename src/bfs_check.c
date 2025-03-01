/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:53:07 by kosakats          #+#    #+#             */
/*   Updated: 2025/02/21 22:58:15 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs(int w, int h, int **arr, char **map)
{
	if (check_if_escape(w, h, arr, map))
		return ;
	arr[h][w] = 1;
	dfs(w + 1, h, arr, map);
	dfs(w - 1, h, arr, map);
	dfs(w, h + 1, arr, map);
	dfs(w, h - 1, arr, map);
}

int	map_check(char **map, t_map *map_info, int **arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < map_info->height)
	{
		j = 0;
		while (j < map_info->width)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				if (map[i][j] == 'C' && arr[i][j] == 0)
					return (1);
				if (map[i][j] == 'E' && !(arr[i][j + 1] == 1 || arr[i][j
						- 1] == 1 || arr[i + 1][j] == 1 || arr[i - 1][j] == 1))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	dfs_main(char **map, t_map *map_info)
{
	t_player_po	player_po;
	int			**arr;
	size_t		i;

	i = 0;
	arr = malloc(sizeof(int *) * (map_info->height + 1));
	while (i < map_info->height)
		arr[i++] = ft_calloc(sizeof(int), map_info->width);
	player_po.w = 0;
	player_po.h = 0;
	find_player_po(map, &player_po);
	dfs(player_po.w, player_po.h, arr, map);
	if (map_check(map, map_info, arr))
	{
		free_arr(arr, map_info->height);
		return (0);
	}
	free_arr(arr, map_info->height);
	return (1);
}
