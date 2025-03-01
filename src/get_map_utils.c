/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:53:07 by kosakats          #+#    #+#             */
/*   Updated: 2025/02/23 18:06:16 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**resize_map(char **map, size_t current_size, size_t new_size)
{
	char	**new_map;
	size_t	i;

	new_map = malloc(sizeof(char *) * (new_size + 1));
	if (!new_map)
		return (NULL);
	new_map[new_size] = NULL;
	i = 0;
	while (i < new_size)
		new_map[i++] = NULL;
	i = 0;
	while (i < current_size && map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			free_map(new_map);
			return (NULL);
		}
		i++;
	}
	free_map(map);
	return (new_map);
}

char	**return_val(size_t *height, char **map, int fd, t_info *info)
{
	if (*height == 0)
		return (free_map(map), close(fd), exit_error("Empty map file", info),
			NULL);
	return (close(fd), map);
}

char	**resize_map_reserve(t_size *size, char **map, size_t *height)
{
	size->map_size *= 2;
	map = resize_map(map, *height, size->map_size);
	return (map);
}
