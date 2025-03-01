/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_check._utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:53:07 by kosakats          #+#    #+#             */
/*   Updated: 2025/02/21 22:46:44 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arr(int **arr, size_t height)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (i < height)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	find_player_po(char **map, t_player_po *player_po)
{
	int	h;
	int	w;

	player_po->w = 0;
	player_po->h = 0;
	h = 0;
	while (map[h])
	{
		w = 0;
		while (map[h][w])
		{
			if (map[h][w] == 'P')
			{
				player_po->w = w;
				player_po->h = h;
				return ;
			}
			w++;
		}
		h++;
	}
}

int	check_if_escape(int w, int h, int **arr, char **map)
{
	if (!arr || !map)
		return (1);
	if (!(0 <= w && 0 <= h))
		return (1);
	if (arr[h][w] == 1)
		return (1);
	if (map[h][w] == '1' || map[h][w] == 'E')
		return (1);
	return (0);
}
