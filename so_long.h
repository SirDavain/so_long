/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:03:54 by dulrich           #+#    #+#             */
/*   Updated: 2023/11/27 15:37:24 by dulrich          ###   ########.fr       */
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

typedef struct	s_img
{
	void	*dolphin_normal;
	void	*dolphin_backwards;
	void	*background;
	void	*fish;
}				t_img;


typedef struct	s_data
{
	void	*win_ptr;
	void	*mlx_ptr;
	int		size_x;
	int		size_y;
	t_map	*map;
	t_img	*img;
}				t_data;

typedef struct	s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		fish;
}				t_map;

// Utilities

int	find_line_len(int fd);



#endif
