/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:53:07 by kosakats          #+#    #+#             */
/*   Updated: 2025/02/23 11:59:22 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_line(const char *line)
{
	while (*line)
	{
		if (*line != '1' && *line != '0' && *line != 'P' && *line != 'E'
			&& *line != 'C')
			return (0);
		line++;
	}
	return (1);
}

int	check_line_width(const char *line, size_t expected_width)
{
	return (ft_strlen(line) == expected_width);
}

static char	*process_line(char *line, size_t *temp_width, size_t line_count)
{
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	if (line_count == 0)
		*temp_width = ft_strlen(line);
	return (line);
}

char	**init_mapinfo(size_t *width, size_t *height, t_size *size)
{
	char	**map;
	size_t	i;

	*width = 0;
	*height = 0;
	size->map_size = 10;
	i = 0;
	map = malloc(sizeof(char *) * (size->map_size + 1));
	if (!map)
		return (NULL);
	while (i <= size->map_size)
	{
		map[i] = NULL;
		i++;
	}
	return (map);
}

char	**read_map(char *filename, size_t *width, size_t *height, t_info *info)
{
	int		fd;
	char	**map;
	char	*line;
	t_size	size;

	map = init_mapinfo(width, height, &size);
	fd = open(filename, O_RDONLY);
	if (!map || fd < 0)
		return (exit_error("Failed to open", info), NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*height >= size.map_size)
		{
			map = resize_map_reserve(&size, map, height);
			if (!map)
				return (free(line), free_map(map), close(fd), NULL);
		}
		line = process_line(line, width, *height);
		if (!check_line_width(line, *width) || !validate_map_line(line))
			return (close(fd), exit_error("", info), NULL);
		map[(*height)++] = line;
		line = get_next_line(fd);
	}
	return (return_val(height, map, fd, info));
}
