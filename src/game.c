/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:03:18 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/23 15:58:17 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		map_error("Wrong number of arguments.", &data, 0);
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		map_error("Map has to be in format .ber.", &data, 0);
	init_vars(&data, argv[1]);
	parse_map(&data);
	print_map(&data);
	grid_fill(&data);
	ft_free(&data, 't');
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.map_w * SIZE, \
									data.map.map_h * SIZE, "so_long");
	data.img = mlx_new_image(data.mlx_ptr, data.map.map_h * SIZE, \
								data.map.map_w * SIZE);
	/* data.address = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
										&data.size_line, &data.endian); */
	load_sprites(&data);
	mlx_hook(data.win_ptr, 2, 1L << 0, input_handler, &data);
	mlx_hook(data.win_ptr, 17, 1L << 0, exit_game, &data);
	mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);
	mlx_loop(data.mlx_ptr);
}

void	init_vars(t_data *data, char *map_path)
{
	data->map.path = map_path;
	data->map.map_h = 0;
	data->map.map_w = 0;
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

int	parse_map(t_data *data)
{
	char	*line;
	int		not_rectangular;

	not_rectangular = 0;
	data->map.fd = open(data->map.path, O_RDONLY);
	if (data->map.fd < 0)
		map_error("Map was not found.", data, 0);
	line = get_next_line(data->map.fd);
	while (line)
	{
		data->map.map_h++;
		if (data->map.map_h == 1)
			data->map.map_w = get_line_len(line);
		if (get_line_len(line) != data->map.map_w)
			not_rectangular = 1;
		free(line);
		line = get_next_line(data->map.fd);
	}
	free(line);
	close(data->map.fd);
	if (not_rectangular)
		map_error("The map is not rectangular.", data, 0);
	if (data->map.map_h == 0)
		map_error("Map is empty.", data, 0);
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
	ft_free(data, 'g');
	mlx_destroy_image(data->mlx_ptr, data->win_sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->bgr_sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->floor_sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->p_sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->wall_sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->exit_sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->clctbl_sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
