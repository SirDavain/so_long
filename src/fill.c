/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:07:19 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/29 12:39:10 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_map_filling(t_data *data, t_pixel *p)
{
	data->map.fd = open(data->map.path, O_RDONLY);
	if (data->map.fd < 0)
		map_error("Map was not found.", data, 0);
	data->map.grid = malloc(data->map.map_h * sizeof(char *));
	data->map.tiles = malloc(data->map.map_h * sizeof(t_tile *));
	if (!data->map.grid || !data->map.tiles)
		map_error("Issue while malloc'ing.", data, 1);
	p->px_x = 0;
	p->px_y = 0;
}

int	fill_tiles(t_data *data, char *line, t_pixel grid_pos)
{
	size_t	i;

	i = 0;
	data->map.grid[grid_pos.px_y][grid_pos.px_x] = line[grid_pos.px_x];
	data->map.tiles[grid_pos.px_y][grid_pos.px_x].t = line[grid_pos.px_x];
	data->map.tiles[grid_pos.px_y][grid_pos.px_x].v = 0;
	if (found_unknown_char(data->map.tiles[grid_pos.px_y][grid_pos.px_x].t))
		map_error("There is an unknown character inside the map.", data, 1);
	return (0);
}

void	grid_fill_helper(t_data *data, t_pixel grid_pos)
{
	char	*line;

	line = get_next_line(data->map.fd);
	if (!line)
		map_error("Couldn't read the line.", data, 1);
	while (line)
	{
		allocate_line(data, grid_pos);
		while (grid_pos.px_x < data->map.map_w)
		{
			fill_tiles(data, line, grid_pos);
			count_grid(data, data->map.grid[grid_pos.px_y][grid_pos.px_x], \
																grid_pos);
			grid_pos.px_x++;
		}
		grid_pos.px_x = 0;
		grid_pos.px_y++;
		free(line);
		line = get_next_line(data->map.fd);
		if (!line)
			map_error("Couldn't read the line.", data, 1);
	}
	free(line);
	close(data->map.fd);
}

int	grid_fill(t_data *data)
{
	t_pixel	grid_pos;

	start_map_filling(data, &grid_pos);
	grid_fill_helper(data, grid_pos);
	if (missing_walls(data))
		map_error("There is an issue with the walls of the map.", data, 1);
	if (data->start_found <= 0)
		map_error("There is no starting point on the map.", data, 1);
	check_for_valid_path(data->player.position, data);
	map_checker(data);
	return (1);
}

/* void	print_map(t_data *data)
{
	char	*line;

	data->map.fd = open(data->map.path, O_RDONLY);
	line = get_next_line(data->map.fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(data->map.fd);
	}
	close(data->map.fd);
} */