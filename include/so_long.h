/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:16:58 by kosakats          #+#    #+#             */
/*   Updated: 2025/02/23 11:59:38 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 32
# define W 119
# define S 115
# define A 97
# define D 100
# define KEY_ESC 65307

typedef struct s_map
{
	char		**map;
	size_t		player_count;
	size_t		item_count;
	size_t		total_items;
	size_t		exit_count;
	size_t		width;
	size_t		height;
}				t_map;

typedef struct s_player
{
	size_t		x;
	size_t		y;
	size_t		item_count;
	size_t		move_count;
}				t_player;

typedef struct s_images
{
	void		*tile;
	void		*wall;
	void		*item;
	void		*exit;
	void		*player;
	int			size;
}				t_images;

typedef struct s_size
{
	size_t		line_count;
	size_t		temp_width;
	size_t		map_size;
}				t_size;

typedef struct s_player_po
{
	int			w;
	int			h;
}				t_player_po;

typedef struct s_info
{
	void		*mlx;
	void		*window;
	t_map		map_info;
	t_player	player_info;
	t_images	images_info;
}				t_info;

char			**read_map(char *filename, size_t *width, size_t *height,
					t_info *info);
void			free_map(char **map);
int				check_line_width(const char *line, size_t expected_width);
int				validate_map_line(const char *line);
int				validate_map_structure(char **map, size_t width, size_t height,
					t_info *info);
int				check_elements(char **map, t_map *map_info);
void			load_images(t_info *info, size_t *width, size_t *height);
void			draw_map(t_info *info);
int				can_move_to(t_info *info, int new_x, int new_y);
void			move_player(t_info *info, int dx, int dy);
int				on_keypress(int keycode, t_info *info);
void			find_player_position(t_info *info);
void			count_total_items(t_info *info);
int				on_destroy(t_info *info);
void			exit_error(char *str, t_info *info);
int				validate_map_structure(char **map, size_t width, size_t height,
					t_info *info);
int				dfs_main(char **map, t_map *map_info);
t_info			*init_info(void);
void			draw_tile(t_info *info, char tile, int x, int y);
char			**resize_map(char **map, size_t current_size, size_t new_size);
void			free_arr(int **arr, size_t height);
void			free_map(char **map);
void			find_player_po(char **map, t_player_po *player_po);
int				check_if_escape(int w, int h, int **arr, char **map);
char			**resize_map_reserve(t_size *size, char **map, size_t *height);
char			**return_val(size_t *height, char **map, int fd, t_info *info);
char			**init_mapinfo(size_t *width, size_t *height, t_size *size);

#endif
