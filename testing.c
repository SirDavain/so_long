#include "so_long.h"

int	build_map()
{
	int	filled_map = 1;
	/*flood_fill with:
	0 for an empty space,
	1 for a wall,
	C for a collectible,
	E for a map exit,
	P for the player’s starting position.*/
	return (filled_map);
}

int	check_map()
{
	if (exit != 1 || player != 1 || !(collectible >= 1))
		return (ERROR and abort);
	else
		return (map_valid);
}

// cap maps at something reasonable - like screensize (MLX function for screensize)

/* recursive function to check if map is valid etc.: 
if (all_collectables_collected && exit_count == 1)
	return map_valid;
if (on_wall)
	return map_invalid;
if (on_collectable)
	collectables++;
if (on_exit)
	exits++;
replace_current_position_with_wall;
if (one_of_the_four_adjacent_directions_is_possible)
	return map_valid;
return map_invalid; */

int	reg_keypress(int keycode, t_data *data)
{
	if (keycode == 'ESC')
		ft_move();
	return (0);
}

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 600, 400, "hello there");
	if (!win_ptr)
		return (free(mlx_ptr), 1);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}