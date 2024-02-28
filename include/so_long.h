/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:03:54 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/28 16:32:49 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stddef.h>
# include <aio.h>
# include <fcntl.h>
# include <errno.h>
# include <mlx.h>
# include <X11/keysym.h>
# include "../libft/libft.h"

# define FALSE 0
# define TRUE 1
# ifndef SIZE
#  define SIZE 48
# endif
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

typedef struct s_pixel
{
	size_t	px_x;
	size_t	px_y;
}				t_pixel;

typedef struct s_sprite
{
	int		pixel_w;
	int		pixel_h;
	void	*img;
}				t_sprite;

typedef struct s_sprite_flag
{
	int	bgr_sprite;
	int	floor_sprite;
	int	wall_sprite;
	int	p_sprite;
	int	clctbl_sprite;
	int	exit_sprite;
	int	win_sprite;
}				t_sprite_flag;

typedef struct s_tile
{
	char	t;
	int		v;
}				t_tile;

typedef struct s_player
{
	t_pixel	position;
	t_pixel	start;
}				t_player;

typedef struct s_map
{
	char	*path;
	char	**grid;
	size_t	map_h;
	size_t	map_w;
	t_tile	**tiles;
	int		fd;
	int		x;
	int		y;
}				t_map;

typedef struct s_data
{
	void			*win_ptr;
	void			*mlx_ptr;
	void			*img;
	char			*address;
	int				size_x;
	int				size_y;
	t_player		player;
	t_map			map;
	t_sprite_flag	flag;
	t_sprite		bgr_sprite;
	t_sprite		floor_sprite;
	t_sprite		wall_sprite;
	t_sprite		p_sprite;
	t_sprite		clctbl_sprite;
	t_sprite		exit_sprite;
	t_sprite		win_sprite;
	int				exit_unlocked;
	int				collectible;
	int				collected;
	int				moves;
	int				start_found;
	int				exit_found;
	int				access_to_exit;
	int				access_to_collectibles;
	int				endian;
	int				bits_per_pixel;
	int				size_line;
	int				won;
}				t_data;

// game.c

int		main(int argc, char **argv);
int		parse_map(t_data *data);
void	init_mlx_win_img(t_data *data);
int		exit_game(t_data *data);
int		ft_format(char *str, t_data *data);

// utils.c

void	allocate_line(t_data *data, t_pixel grid_pos);
void	count_grid(t_data *data, char c, t_pixel p);
void	ft_free(t_data *data, char a);
int		input_handler(int keycode, t_data *data);
void	update_player_pos(t_data *data, t_pixel new_pos);

// utils2.c

size_t	get_line_len(char *str);
void	put_win_screen(t_data *data);
void	init_vars(t_data *data, char *map_path);
void	init_flags(t_data *data);

// sprites.c

void	init_sprites(t_data *data);
void	*ft_load_sprite(t_data *data, char *str, int *px_w, int *px_h);
void	put_sprite(t_data *data, t_pixel a, char b);
void	free_sprites(t_data *data);

// rendering.c

void	render_background(t_data *data);
void	render_map(t_data *data);
void	render_player(t_data *data);

// checker.c

int		found_unknown_char(char c);
void	map_error(char *str, t_data *data, int flag);
int		missing_walls(t_data *data);
void	check_for_valid_path(t_pixel p, t_data *data);
void	map_checker(t_data *data);

// fill.c

void	start_map_filling(t_data *data, t_pixel *p);
int		fill_tiles(t_data *data, char *line, t_pixel grid_pos);
int		grid_fill(t_data *data);
void	grid_fill_helper(t_data *data, int uc, t_pixel grid_pos);

#endif