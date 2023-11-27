#ifndef SO_LONG_H
 # define SO_LONG_H

# include <stdlib.h>
# include "mlx.h"
# include "X11/keysym.h"
# include <errno.h>

typedef struct	s_data
{
	void	*win_ptr;
	void	*mlx_ptr;
	void	*textures[5];
	t_map	*map;
}				t_data;

typedef struct	s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		fish;
}				t_map;


#endif
