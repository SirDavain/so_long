/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:03:54 by dulrich           #+#    #+#             */
/*   Updated: 2024/01/02 15:05:31 by dulrich          ###   ########.fr       */
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
#ifndef
# define SIZE 100
#endif

typedef	struct 	s_pixel
{
	size_t	pixel_x;
	size_t	pixel_y;
}				t_pixel;

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
}				t_data;

typedef struct	s_map
{
	char	**grid;
	char	*path;
	size_t	map_height;
	size_t	map_width;
	t_tile	**tiles;
	int		fd;
	int		x;
	int		y;
	int		fish;
}				t_map;

// Utilities

int	find_line_len(int fd);
int	get_line_nbr(int fd);


#endif
