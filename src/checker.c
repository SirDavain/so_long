/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:39:52 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/29 16:54:51 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	found_unknown_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'E')
		return (0);
	return (1);
}

void	map_error(char *str, t_data *data, int flag)
{
	ft_printf("\033[1;31mError\n");
	ft_printf("%s\033[0m\n", str);
	if (flag == 1)
	{
		if (data->map.grid != NULL)
			ft_free(data, 'g');
		if (data->map.tiles != NULL)
			ft_free(data, 't');
	}
	/* else if (flag == 2)
	{
		get_next_line(-1);
		
	} */
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
		if (data->map.grid[y][x] != '1')
			return (1);
		else if (data->map.grid[data->map.map_h - 1][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (y < data->map.map_h)
	{
		if (data->map.grid[y][x] != '1')
			return (1);
		else if (data->map.grid[y][data->map.map_w - 1] != '1')
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
	if (data->map.grid[p.px_y][p.px_x] == '1' || \
		data->map.tiles[p.px_y][p.px_x].v == 1 || \
		p.px_x > width || p.px_y > height)
		return ;
	data->map.tiles[p.px_y][p.px_x].v = 1;
	if (data->map.grid[p.px_y][p.px_x] == 'E')
		data->access_to_exit = TRUE;
	if (data->map.grid[p.px_y][p.px_x] == 'C')
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
		map_error("The map is missing an exit", data, 1);
	if (data->exit_found > 1)
		map_error("Too many exits found on the map.", data, 1);
	if (!data->access_to_exit)
		map_error("There is no valid path to the exit.", data, 1);
	if (data->start_found > 1)
		map_error("Too many starting points found on the map.", data, 1);
	if (data->collectible < 1)
		map_error("There are too few collectibles.", data, 1);
	if (data->collectible != data->access_to_collectibles)
		map_error("Not all collectibles can be accessed.", data, 1);
}
