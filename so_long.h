/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:03:54 by dulrich           #+#    #+#             */
/*   Updated: 2024/01/24 15:21:01 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
 # define SO_LONG_H

# include <stdlib.h>
# include <stddef.h>
# include <aio.h>
# include <fcntl.h>
# include <errno.h>
# include "mlx.h"
# include "X11/keysym.h"
# include "./libft/libft.h"

# define FALSE 0
# define TRUE 1
#ifndef SIZE
 # define SIZE 100
#endif
# define ESC 27
# define UP 87
# define DOWN 83
# define LEFT 65
# define RIGHT 68

typedef	struct 	s_pixel
{
	size_t	px_x;
	size_t	px_y;
}				t_pixel;

typedef	struct 	s_sprite
{
	int		pixel_w;
	int		pixel_h;
	void	*img;
}				t_sprite;

typedef struct	s_img
{
	void	*dolphin;
	void	*dolphin_backwards;
	void	*background;
	void	*fish;
}				t_img;

typedef	struct 	s_tile
{
	char	t;
	int		v;
}				t_tile;

typedef	struct 	s_player
{
	t_pixel	position;
	t_pixel	start;
}				t_player;


typedef struct	s_data
{
	void		*win_ptr;
	void		*mlx_ptr;
	void		*img;
	char		*address;
	int			size_x;
	int			size_y;
	t_player	player;
	t_map		*map;
	t_img		*img;
	t_sprite	p_sprite;
	t_sprite	bgr_sprite;
	t_sprite	wall_sprite;
	t_sprite	floor_sprite;
	t_sprite	clctbl_sprite;
	t_sprite	start_sprite;
	t_sprite	exit_sprite;
	t_sprite	win_sprite;
	int			exit_unlocked;
	int			collectible;
	int			collected;
	int			moves;
	int			start_found;
	int			exit_found;
	int			access_to_exit;
	int			access_to_collectibles;
	int			endian;
	int			bits_per_pixel;
	int			size_line;
	int			won;
	int			moves;
}				t_data;

typedef struct	s_map
{
	char	**grid;
	char	*path;
	size_t	map_h;
	size_t	map_w;
	t_tile	**tiles;
	int		fd;
	int		x;
	int		y;
	int		fish;
}				t_map;

// Utilities

void	allocate_lines(t_data *data, t_pixel grid_pos);
void	count_grid(t_data *data, char c, t_pixel p);
void	free_tiles(t_data *data);
int		input_handler(int keycode, t_data *data);
int		update_player_pos(t_data *data, t_pixel new_pos);

// game.c

int 	main(int argc, char **argv);
void	init_game(t_data *data, char *map_path);
int		parse_map(t_map *map);
int		render_next_frame(t_data *data);
void	exit_game(t_data *data);

// sprites.c

void	load_sprites(t_data *data);
void	put_sprite(t_data *data, t_pixel a, char b);
void	render_background(t_data *data);
void	render_map(t_data *data);
void	render_player(t_data *data);

// checker.c

int		found_unknown_char(char c);
void	map_error(char *str);
int		missing_walls(t_data *data);
void	check_for_valid_path(t_data *data, t_pixel p);
void	map_checker(t_data *data);

// fill.c

void	start_map_filling(t_data *data, t_pixel *p);
void	fill_tiles(t_data *data, char *line, t_pixel grid_pos);
int		grid_fill(t_data *data);


#endif
