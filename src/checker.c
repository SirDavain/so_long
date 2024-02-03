/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:39:52 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/03 15:25:06 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	found_unknown_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'E')
		return (1);
	return (0);
}

void	map_error(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(1);
}

int	missing_walls(t_data *data)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < data->map.map_w)
	{
		if (data->map.grid[x][y] != '1')
			return (1);
		else if (data->map.grid[x][data->map.map_h - 1] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (y < data->map.map_h)
	{
		if (data->map.grid[x][y] != '1')
			return (1);
		else if (data->map.grid[data->map.map_w - 1][y] != '1')
			return (1);
		y++;
	}
	return (0);
}

void	check_for_valid_path(t_pixel p, t_data *data)
{
	size_t	width;
	size_t	height;

	width = data->map.map_w;
	height = data->map.map_h;
	if (data->map.grid[p.px_x][p.px_y] == '1' || \
		data->map.tiles[p.px_x][p.px_y].v == 1 || \
		p.px_x > width || p.px_y > height)
		return ;
	data->map.tiles[p.px_x][p.px_y].v = 1;
	if (data->map.grid[p.px_x][p.px_y] == 'E')
		data->access_to_exit = TRUE;
	if (data->map.grid[p.px_x][p.px_y] == 'C')
		data->access_to_collectibles++;
	check_for_valid_path((t_pixel){p.px_x - 1, p.px_y}, data);
	check_for_valid_path((t_pixel){p.px_x + 1, p.px_y}, data);
	check_for_valid_path((t_pixel){p.px_x, p.px_y - 1}, data);
	check_for_valid_path((t_pixel){p.px_x, p.px_y + 1}, data);
	return ;
}

void	map_checker(t_data *data)
{
	if (data->exit_found <= 0)
		map_error("The map is missing an exit");
	if (data->exit_found > 1)
		map_error("Too many exits found on the map.");
	if (!data->access_to_exit)
		map_error("There is no valid path to the exit.");
	if (data->start_found <= 0)
		map_error("There is no starting point on the map.");
	if (data->start_found > 1)
		map_error("Too many starting points found on the map.");
	if (data->collectible < 1)
		map_error("There are too few collectibles.");
	if (data->collectible != data->access_to_collectibles)
		map_error("Not all collectibles can be accessed.");
}
