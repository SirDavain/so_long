/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:03:18 by dulrich           #+#    #+#             */
/*   Updated: 2023/12/15 10:33:19 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\n", keysym);
	return (0);
}

void	init_game(t_data *data, char *map_path)
{
	data->map.path = map_path;
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

	ft = open(map->path, O_RDONLY);
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
		map_error("Wrong number of arguments.")
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		map_error("Map has to be in format .ber.");
	get_window_size(&data, argv[1]);
	init_game(&data, argv[1]);
	parse_map(&data.map);

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 600, 400, "hello there");
	if (!win_ptr)
		return (free(mlx_ptr), 1);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}