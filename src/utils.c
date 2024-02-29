/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:58:18 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/29 12:11:26 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocate_line(t_data *data, t_pixel grid_pos)
{
	data->map.grid[grid_pos.px_y] = malloc((data->map.map_w) * \
														sizeof(char));
	data->map.tiles[grid_pos.px_y] = malloc((data->map.map_w) * \
														sizeof(t_tile));
	if (!(data->map.tiles[grid_pos.px_y]) || !(data->map.grid[grid_pos.px_y]))
		map_error("Error when allocating space.", data, 1);
}

void	count_grid(t_data *data, char c, t_pixel p)
{
	if (c == 'P')
	{
		data->start_found++;
		data->player.position = p;
		data->player.start = p;
	}
	else if (data->map.grid[p.px_y][p.px_x] == 'C')
		data->collectible++;
	else if (data->map.grid[p.px_y][p.px_x] == 'E')
		data->exit_found++;
}

void	ft_free(t_data *data, char a)
{
	size_t	i;

	i = 0;
	if (a == 't')
	{
		while (i < data->map.map_h)
		{
			free(data->map.tiles[i]);
			data->map.tiles[i] = NULL;
			i++;
		}
		free(data->map.tiles);
		data->map.tiles = NULL;
	}
	else if (a == 'g')
	{
		while (i < data->map.map_h)
		{
			free(data->map.grid[i]);
			data->map.grid[i] = NULL;
			i++;
		}
		free(data->map.grid);
		data->map.grid = NULL;
	}
}

int	input_handler(int keycode, t_data *data)
{
	if (keycode == 53 || keycode == 65307)
		exit_game(data);
	else if (keycode == UP && !data->won)
		update_player_pos(data, (t_pixel){data->player.position.px_x, \
											data->player.position.px_y - 1});
	else if (keycode == DOWN && !data->won)
		update_player_pos(data, (t_pixel){data->player.position.px_x, \
											data->player.position.px_y + 1});
	else if (keycode == RIGHT && !data->won)
		update_player_pos(data, (t_pixel){data->player.position.px_x + 1, \
											data->player.position.px_y});
	else if (keycode == LEFT && !data->won)
		update_player_pos(data, (t_pixel){data->player.position.px_x - 1, \
											data->player.position.px_y});
	return (0);
}

void	update_player_pos(t_data *data, t_pixel new_pos)
{
	if (new_pos.px_x < data->map.map_w && new_pos.px_y < data->map.map_h)
	{
		if (data->map.grid[new_pos.px_y][new_pos.px_x] != '1')
		{
			data->player.position = new_pos;
			ft_printf("Total moves: %d\n", ++data->moves);
			render_map(data);
		}
		if (data->map.grid[new_pos.px_y][new_pos.px_x] == 'C')
		{
			data->collected++;
			data->player.position = new_pos;
			data->map.grid[new_pos.px_y][new_pos.px_x] = '0';
			if (data->collected == data->collectible)
				data->exit_unlocked = 1;
		}
		else if (data->map.grid[new_pos.px_y][new_pos.px_x] == 'E' \
												&& data->exit_unlocked)
		{
			data->player.position = new_pos;
			data->won = TRUE;
			put_win_screen(data);
		}
	}
}
