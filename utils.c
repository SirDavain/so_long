/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:58:18 by dulrich           #+#    #+#             */
/*   Updated: 2024/01/15 16:46:44 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(1);
}

size_t	get_line_len(char *str)
{
	size_t	len;

	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

int	get_line_nbr(int fd)
{
	char	*line;
	int		i;
	int		linecount;

	linecount = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else
		{
			free(line);
			linecount++;
		}
	}
	return (linecount);
}

void	start_map_filling(t_data *data, t_pixel *p)
{
	data->map.fd = open(data->map.path, O_RDONLY);
	data->map.grid = malloc(data->map.map_height * sizeof(char *));
	data->map->tiles = malloc(data->map->map_height * sizeof(t_tile *))
	p->pixel_x = 0;
	p->pixel_y = 0;
}

void	allocate_lines(t_data *data, t_pixel grid_pos)
{
	data->map.grid[grid_pos.pixel_y] = malloc((data->map.map_width - 1) \
	* sizeof(char));
	data->map.tiles[grid_pos.pixel_y] = malloc((data->map->map_width - 1) \
	* sizeof(t_tile));
}

int	found_unknown_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'E')
		return (1);
	return (0);
}

void	fill_tiles(t_data *data, char *line, t_pixel grid_pos)
{
	data->map.grid[grid_pos.pixel_x][grid_pos.pixel_y] = line[grid_pos.pixel_x];
	data->map.tiles[grid_pos.pixel_x] [grid_pos.pixel_y].t = line[grid_pos.pixel_x];
	data->map.tiles[grid_pos.pixel_x] [grid_pos.pixel_y].v = line[grid_pos.pixel_x];
	if (found_unknown_char(data->map.tiles[grid_pos.pixel_x][grid_pos.pixel_y].t))
		map_error("There is an unkwnown character insisde the map.");
}

void	count_grid(t_data *data, char c, t_pixel p)
{
	if (c == 'P')
	{
		data->start_found++;
		data->player.position = p;
		data->player.start = p;
	}
	else if (data->map.grid[p.pixel_x][p.pixel_y] == 'C')
		data->collectible++;
	else if (data->map.grid[p.pixel_x][p.pixel_y] == 'E')
		data->exit_found++;
}

int	missing_walls(t_data *data)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < data->map.map_width)
	{
		if (data->map.grid[x][y] != '1')
			return (1);
		else if (data->map.grid[x][data->map.map_height - 1] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (y < data->map.map_height)
	{
		if (data->map.grid[x][y] != '1')
			return (1);
		else if (data->map.grid[data->map.map.width - 1][y] != '1')
			return (1);
		y++;
	}
	return (0);
}

void	check_for_valid_path(t_data *data, t_pixel p)
{
	size_t	width;
	size_t	height;

	width = data->map.map_width;
	height = data->map.map_height;
	if (data->map.grid[p.pixel_x][p.pixel_y] == '1' || \
		data->map.tiles[p.pixel_x][p.pixel_y] == || \
		p.pixel_x < 0 || p.pixel_y < 0 || \
		p.pixel_x > map_width || p.pixel_y > map_height)
			return ;
	data->map.tiles[p.pixel_x][p.pixel_y] = 1;
	if (data->map.grid[p.pixel_x][p.pixel_y] == 'E')
		data->access_to_exit = TRUE;
	if (data->map.grid[p.pixel_x][p.pixel_y] == 'C')
		data->access_to_collectibles++;
	check_for_valid_path((t_pixel){p.pixel_x - 1, p.pixel_y}, data);
	check_for_valid_path((t_pixel){p.pixel_x + 1, p.pixel_y}, data);
	check_for_valid_path((t_pixel){p.pixel_x, p.pixel_y - 1}, data);
	check_for_valid_path((t_pixel){p.pixel_x, p.pixel_y + 1}, data);
	return ;
}

void	map_checker(t_data *data)
{
	if (data->exit_found <= 0)
		map_error("The map is missing an exit");
	if (data->exit_found > 1)
		map_error("Too many exits found on the map.")
	if (!data->access_to_exit)
		map_error("There is no valid path to the exit.");
	if (data->start_found <= 0)
		map_error("There is no starting point on the map.")
	if (data->start_found > 1)
		map_error("Too many starting points found on the map.")
	if (data->collectible < 1)
		map_error("There are too few collectibles.");
	if (data->collectible =! data->access_to_collectibles)
		map_error("Not all collectibles are can be accessed.");
}

int	grid_fill(t_data *data)
{
	t_point	grid_pos;
	char	*line;

	start_map_filling(data, &grid_pos);
	line = get_next_line(data->map.fd);
	while (line)
	{
		allocate_lines(data, grid_pos);
		while (grid_pos.pixel_x < data->map.map_width)
		{
			fill_tiles(data, line, grid_pos);
			count_grid(data, data->map.grid[grid_pos.pixel_x][grid_pos.pixel_y], grid_pos);
			grid_pos.pixel_x++;
		}
		grid_pos.pixel_x = 0;
		grid_pos.pixel_y++;
		line = get_next_line(data->map.fd);
	}
	close(data->map.fd);
	if (missing_walls)
		map_error("There is an issue with the walls of the map.")
	check_for_valid_path(data, data->player.position);
	map_checker(data);
	return (1);
}

void	free_tiles(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.map_height)
	{
		free(data->map.tiles[i]);
		data->map.tiles[i] = NULL;
		i++;
	}
	free(data->map.tiles);
	data->map.tiles = NULL;
}

void	load_sprites(t_data *data)
{
	data->bgr_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "img/bgr_sprite.xpm", \
											&bgr_sprite.pixel_w, &bgr_sprite.pixel_h);
	data->plyr_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "img/plyr_sprite.xpm", \
											&plyr_sprite.pixel_w, &plyr_sprite.pixel_h);
	data->wall_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "img/wall_sprite.xpm", \
											&wall_sprite.pixel_w, &wall_sprite.pixel_h);
	data->floor_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "img/floor_sprite.xpm", \
											&floor_sprite.pixel_w, &floor_sprite.pixel_h);
	data->clctbl_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "img/clctbl_sprite.xpm", \
											&clctbl_sprite.pixel_w, &clctbl_sprite.pixel_h);
	data->start_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "img/start_sprite.xpm", \
											&start_sprite.pixel_w, &start_sprite.pixel_h);
	data->exit_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "img/exit_sprite.xpm", \
											&exit_sprite.pixel_w, &exit_sprite.pixel_h);
	data->win_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "img/win_sprite.xpm", \
											&win_sprite.pixel_w, &win_sprite.pixel_h);
}

int	input_handler(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit_game(data);
	else if (keycode == UP && !data.won)
		update_player_pos(&data, (t_pixel){data->player.position.pixel_x, \
											data->player.position.pixel_y + 1)};
	else if (keycode == DOWN && !data.won)
		update_player_pos(&data, (t_pixel){data->player.position.pixel_x, \
											data->player.position.pixel_y - 1)};
	else if (keycode == RIGHT && !data.won)
		update_player_pos(&data, (t_pixel){data->player.position.pixel_x + 1, \
											data->player.position.pixel_y)};
	else if (keycode == LEFT && !data.won)
		update_player_pos(&data, (t_pixel){data->player.position.pixel_x - 1, \
											data->player.position.pixel_y)};
	return (0);
}

void	exit_game(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int	update_player_pos(t_data *data, t_pixel new_pos)
{
	ft_printf("Total moves: %d\n", ++data->moves);
	if (new_pos.pixel_x < data->map.map_width && new_pos.pixel_y < data->map.map_height)
	{
		if (data->map.grid[new_pos.pixel_x][new_pos.pixel_y] == 'C')
		{
			data->collected++;
			data->player.position = new_pos;
			if (data->collected == data->collectible)
				data->exit_unlocked == 1;
		}
		else if (data->map.grid[new_pos.pixel_x][new_pos.pixel_y] == 'E' \
																		&& data->exit_unlocked)
		{
			data->player.position = new_pos;
			data->won = TRUE;
		}
		else if (data->map.grid[new_pos.pixel_x][new_pos.pixel_y] != '1')
			data->player.position = new_pos;
	}
}

void	render_background(t_data *data)
{
	t_pixel	start;
	t_pixel	end;

	start.pixel_x = 0;
	start.pixel_y = 0;
	end.pixel_x = data->map.map_width * SIZE;
	end.pixel_y = data->map.map_height * SIZE;
	while (start.pixel_y < end.pixel_y)
	{
		while (start.pixel_x < end.pixel_x)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bgr_sprite.img, \
															start.pixel_x, start.pixel_y);
			start.pixel_x += SIZE;
		}
		start.pixel_x = 0;
		start.pixel_y += SIZE;
	}
}

void	render_map(t_data *data)
{
	t_pixel	a;

	a.pixel_x = 0;
	a.pixel_y = 0;
	while (a.pixel_y < data->map.map_height * SIZE)
	{
		while (a.pixel_x < data->map.map_height * SIZE)
		{
			if (data->map.grid[a.pixel_x / SIZE][a.pixel_y / SIZE] == '1')
				put_sprite(data, a, '1');
			else if (data->map.grid[a.pixel_x / SIZE][a.pixel_y / SIZE] == '0')
				put_sprite(data, a, '0');
			else if (data->map.grid[a.pixel_x / SIZE][a.pixel_y / SIZE] == 'C')
				put_sprite(data, a, 'C');
			else if (data->map.grid[a.pixel_x / SIZE][a.pixel_y / SIZE] == 'P')
				put_sprite(data, a, 'P');
			else if (data->map.grid[a.pixel_x / SIZE][a.pixel_y / SIZE] == 'E')
				put_sprite(data, a, 'E');
			a.pixel_x += SIZE;
		}
		a.pixel_x = 0;
		a.pixel_y += SIZE;
	}
}

void	render_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->plyr_sprite.img, \
				data->player.position.pixel_x * SIZE, data->player.position.pixel_y * SIZE);
}

void	put_sprite(t_data *data, t_pixel a, char b)
{
	if (b == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall_sprite.img, \
				a.pixel_x, a.pixel_y);
	else if (b == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_sprite.img, \
				a.pixel_x, a.pixel_y);
	else if (b == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->clctbl_sprite.img, \
				a.pixel_x, a.pixel_y);
	else if (b == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->start_sprite.img, \
				a.pixel_x, a.pixel_y);
	else if (b == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_sprite.img, \
				a.pixel_x, a.pixel_y);
}
