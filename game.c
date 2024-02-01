/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:03:18 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/01 14:06:28 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		map_error("Wrong number of arguments.");
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		map_error("Map has to be in format .ber.");
	init_game(&data, argv[1]);
	parse_map(data.map);
	grid_fill(&data);
	free_tiles(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map->map_h * SIZE, \
									data.map->map_w * SIZE, "so_long");
	data.img = mlx_new_image(data.mlx_ptr, data.map->map_h * SIZE, \
									data.map->map_w * SIZE);
	data.address = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
									&data.size_line, &data.endian);
	load_sprites(&data);
	mlx_hook(data.win_ptr, 2, 1L << 0, input_handler, &data);
	mlx_hook(data.win_ptr, 17, 1L << 0, exit_game, &data);
	mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);
	return (0);
}

void	init_game(t_data *data, char *map_path)
{
	data->map->path = map_path;
	data->exit_unlocked = FALSE;
	data->access_to_exit = FALSE;
	data->access_to_collectibles = 0;
	data->collectible = 0;
	data->collected = 0;
	data->moves = 0;
	data->won = FALSE;
	data->exit_found = 0;
	data->start_found = 0;
}

int	parse_map(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		map_error("Map was not found.");
	map->map_h = 0;
	map->map_w = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->map_h++;
		if (map->map_h == 1)
			map->map_w = get_line_len(line);
		if (get_line_len(line) != map->map_w)
			map_error("The map is not rectangular.");
		line = get_next_line(fd);
	}
	close(fd);
	if (map->map_h == 0)
		map_error("Map is empty.");
	return (0);
}

int	render_next_frame(t_data *data)
{
	render_background(data);
	if (!data->won)
	{
		render_map(data);
		render_player(data);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->win_sprite.img, 0, 0);
	}
	return (0);
}

int	exit_game(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}
