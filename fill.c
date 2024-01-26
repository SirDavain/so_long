/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:07:19 by dulrich           #+#    #+#             */
/*   Updated: 2024/01/26 13:40:38 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_map_filling(t_data *data, t_pixel *p)
{
	data->map->fd = open(data->map->path, O_RDONLY);
	data->map->grid = malloc(data->map->map_h * sizeof(char *));
	data->map->tiles = malloc(data->map->map_h * sizeof(t_tile *));
	p->px_x = 0;
	p->px_y = 0;
}

void	fill_tiles(t_data *data, char *line, t_pixel grid_pos)
{
	data->map->grid[grid_pos.px_x][grid_pos.px_y] = line[grid_pos.px_x];
	data->map->tiles[grid_pos.px_x][grid_pos.px_y].t = line[grid_pos.px_x];
	data->map->tiles[grid_pos.px_x][grid_pos.px_y].v = line[grid_pos.px_x];
	if (found_unknown_char(data->map->tiles[grid_pos.px_x][grid_pos.px_y].t))
		map_error("There is an unkwnown character insisde the map.");
}

int	grid_fill(t_data *data)
{
	t_pixel	grid_pos;
	char	*line;

	start_map_filling(data, &grid_pos);
	line = get_next_line(data->map->fd);
	while (line)
	{
		allocate_lines(data, grid_pos);
		while (grid_pos.px_x < data->map->map_w)
		{
			fill_tiles(data, line, grid_pos);
			count_grid(data, data->map->grid[grid_pos.px_x][grid_pos.px_y], \
																grid_pos);
			grid_pos.px_x++;
		}
		grid_pos.px_x = 0;
		grid_pos.px_y++;
		line = get_next_line(data->map->fd);
	}
	close(data->map->fd);
	if (missing_walls)
		map_error("There is an issue with the walls of the map.");
	check_for_valid_path(data->player.position, data);
	map_checker(data);
	return (1);
}

size_t	get_line_len(char *str)
{
	size_t	len;

	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}
