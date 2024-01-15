/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:03:18 by dulrich           #+#    #+#             */
/*   Updated: 2024/01/15 14:28:04 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int keysym, t_data *data)
{
	
	return (0);
}

void	init_game(t_data *data, char *map_path)
{
	data->map->path = map_path;
	data->exit_unlocked = FALSE;
	data->collected = 0;
	data->moves = 0;
	data->won = FALSE;
	data->exit_found = 0;
}

int	parse_map(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		map_error("Map was not found.");
	map->map_height = 0;
	map->map_width = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->map_height++;
		if (map->map_height == 1)
			map->map_width = get_line_len(line);
		if (get_line_len(line) != map->map_width)
			map_error("The map is not rectangular.");
		line = get_next_line(fd);
	}
	close(fd);
	if (map->map_height == 0)
		map_error("Map is empty.");
	return (0);
}

int main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	if (argc != 2)
		map_error("Wrong number of arguments.");
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		map_error("Map has to be in format .ber.");
	init_game(&data, argv[1]);
	parse_map(&data.map);
	grid_fill(&data);
	free_tiles(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map->map_height * SIZE, \
									data.map->map_width * SIZE, "so_long");
	data.img = mlx_new_image(data.mlx_ptr, data.map->map_height * SIZE, \
									data.map->map_width * SIZE);
	data.address = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
									&data.size_line, &data.endian);
	load_sprites(&data);
	mlx_key_hook(data.win_ptr, input_handler(), &data);
	mlx_loop();
	mlx_loop_hook(data->win_ptr, render_next_frame, data);
	return (0);
}

int	render_next_frame()
{
	
}
