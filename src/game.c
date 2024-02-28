/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:03:18 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/28 16:35:36 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		map_error("Wrong number of arguments.", &data, 0);
	if (!ft_format(argv[1], &data))
		map_error("Map has to be in format '.ber'.", &data, 0);
	init_vars(&data, argv[1]);
	parse_map(&data);
	grid_fill(&data);
	ft_free(&data, 't');
	init_mlx_win_img(&data);
	init_flags(&data);
	init_sprites(&data);
	render_map(&data);
	mlx_hook(data.win_ptr, 2, (1L << 0), input_handler, &data);
	mlx_hook(data.win_ptr, 17, (1L << 0), exit_game, &data);
	mlx_loop(data.mlx_ptr);
}

int	ft_format(char *str, t_data *data)
{
	int		i;
	int		len;
	char	*format;

	i = -1;
	format = malloc(sizeof(char) * 5);
	if (!format)
		map_error("Problem while malloc'ing", data, 0);
	len = ft_strlen(str);
	if (len > 4)
	{
		while (++i < 4)
			format[i] = str[len - 1 - i];
	}
	format[i] = '\0';
	if (ft_strncmp(format, "reb.", 4) == 0)
	{
		free(format);
		return (1);
	}
	return (0);
}

void	init_mlx_win_img(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		map_error("Failed to initialize the mlx pointer.", data, 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map.map_w * SIZE, \
									data->map.map_h * SIZE, "so_long");
	if (!data->win_ptr)
		map_error("Failed to initialize the window pointer.", data, 1);
	data->img = mlx_new_image(data->mlx_ptr, data->map.map_h * SIZE, \
								data->map.map_w * SIZE);
	if (!data->img)
		map_error("Failed to initialize the img pointer.", data, 1);
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

int	exit_game(t_data *data)
{
	ft_free(data, 'g');
	mlx_destroy_image(data->mlx_ptr, data->bgr_sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->floor_sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->wall_sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->p_sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->clctbl_sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->exit_sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->win_sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
