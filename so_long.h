/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:03:54 by dulrich           #+#    #+#             */
/*   Updated: 2023/12/13 14:21:12 by dulrich          ###   ########.fr       */
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

typedef struct	s_img
{
	void	*dolphin;
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
	int		exit_unlocked;
	int		collected;
	int		moves;
	int		won;
}				t_data;

typedef struct	s_map
{
	char	**map;
	void	*object;
	char	*path;
	int		x;
	int		y;
	int		fish;
}				t_map;

// Utilities

int	find_line_len(int fd);
int	get_line_nbr(int fd);


#endif
