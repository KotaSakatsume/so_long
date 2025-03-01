/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:53:07 by kosakats          #+#    #+#             */
/*   Updated: 2025/02/21 22:45:37 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_info *info)
{
	if (info->map_info.map)
		free_map(info->map_info.map);
	if (info->images_info.player)
		mlx_destroy_image(info->mlx, info->images_info.player);
	if (info->images_info.exit)
		mlx_destroy_image(info->mlx, info->images_info.exit);
	if (info->images_info.item)
		mlx_destroy_image(info->mlx, info->images_info.item);
	if (info->images_info.tile)
		mlx_destroy_image(info->mlx, info->images_info.tile);
	if (info->images_info.wall)
		mlx_destroy_image(info->mlx, info->images_info.wall);
	if (info->window)
		mlx_destroy_window(info->mlx, info->window);
	if (info->mlx)
		mlx_destroy_display(info->mlx);
	free(info->mlx);
	free(info);
	exit(0);
	return (0);
}

void	exit_error(char *str, t_info *info)
{
	ft_printf("Error\n");
	if (ft_strlen(str) == 0)
	{
		ft_printf("Invalid map");
	}
	ft_printf("%s\n", str);
	on_destroy(info);
	exit(1);
}

int	check_file(const char *filename, t_info *info)
{
	size_t	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 5))
	{
		exit_error("invalid extension", info);
		return (0);
	}
	return (1);
}

int	on_keypress(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		on_destroy(info);
	else if (keycode == W && can_move_to(info, info->player_info.x,
			info->player_info.y - 1))
		move_player(info, 0, -1);
	else if (keycode == A && can_move_to(info, info->player_info.x - 1,
			info->player_info.y))
		move_player(info, -1, 0);
	else if (keycode == S && can_move_to(info, info->player_info.x,
			info->player_info.y + 1))
		move_player(info, 0, 1);
	else if (keycode == D && can_move_to(info, info->player_info.x + 1,
			info->player_info.y))
		move_player(info, 1, 0);
	return (0);
}

int	main(int ac, char **av)
{
	size_t	width;
	size_t	height;
	t_info	*info;

	info = init_info();
	if (ac != 2)
		exit_error("Different number of arguments", info);
	check_file(av[1], info);
	info->map_info.map = read_map(av[1], &width, &height, info);
	validate_map_structure(info->map_info.map, width, height, info);
	if (info->map_info.map)
		find_player_position(info);
	count_total_items(info);
	info->mlx = mlx_init();
	info->window = mlx_new_window(info->mlx, TILE_SIZE * width, TILE_SIZE
			* height, "so_long");
	mlx_hook(info->window, KeyPress, KeyPressMask, &on_keypress, info);
	mlx_hook(info->window, DestroyNotify, StructureNotifyMask, &on_destroy,
		info);
	load_images(info, &width, &height);
	draw_map(info);
	mlx_loop(info->mlx);
	return (0);
}
