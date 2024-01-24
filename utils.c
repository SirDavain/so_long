/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:58:18 by dulrich           #+#    #+#             */
/*   Updated: 2024/01/24 15:17:03 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocate_lines(t_data *data, t_pixel grid_pos)
{
	data->map.grid[grid_pos.px_y] = malloc((data->map.map_w - 1) \
	* sizeof(char));
	data->map.tiles[grid_pos.px_y] = malloc((data->map->map_w - 1) \
	* sizeof(t_tile));
}

void	count_grid(t_data *data, char c, t_pixel p)
{
	if (c == 'P')
	{
		data->start_found++;
		data->player.position = p;
		data->player.start = p;
	}
	else if (data->map.grid[p.px_x][p.px_y] == 'C')
		data->collectible++;
	else if (data->map.grid[p.px_x][p.px_y] == 'E')
		data->exit_found++;
}

void	free_tiles(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.map_h)
	{
		free(data->map.tiles[i]);
		data->map.tiles[i] = NULL;
		i++;
	}
	free(data->map.tiles);
	data->map.tiles = NULL;
}

int	input_handler(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit_game(data);
	else if (keycode == UP && !data.won)
		update_player_pos(&data, (t_pixel){data->player.position.px_x, \
											data->player.position.px_y + 1)};
	else if (keycode == DOWN && !data.won)
		update_player_pos(&data, (t_pixel){data->player.position.px_x, \
											data->player.position.px_y - 1)};
	else if (keycode == RIGHT && !data.won)
		update_player_pos(&data, (t_pixel){data->player.position.px_x + 1, \
											data->player.position.px_y)};
	else if (keycode == LEFT && !data.won)
		update_player_pos(&data, (t_pixel){data->player.position.px_x - 1, \
											data->player.position.px_y)};
	return (0);
}

int	update_player_pos(t_data *data, t_pixel new_pos)
{
	ft_printf("Total moves: %d\n", ++data->moves);
	if (new_pos.px_x < data->map.map_w && new_pos.px_y < data->map.map_h)
	{
		if (data->map.grid[new_pos.px_x][new_pos.px_y] == 'C')
		{
			data->collected++;
			data->player.position = new_pos;
			if (data->collected == data->collectible)
				data->exit_unlocked == 1;
		}
		else if (data->map.grid[new_pos.px_x][new_pos.px_y] == 'E' \
												&& data->exit_unlocked)
		{
			data->player.position = new_pos;
			data->won = TRUE;
		}
		else if (data->map.grid[new_pos.px_x][new_pos.px_y] != '1')
			data->player.position = new_pos;
	}
}
