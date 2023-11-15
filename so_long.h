#ifndef SO_LONG_H
 # define SO_LONG_H

# include <stdlib.h>
# include "mlx.h"


typedef struct	s_data
{
	void	*win_ptr;
	void	*mlx_ptr;
	void	*textures[];
	t_map	*map;
}				t_data;

#endif
