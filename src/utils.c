/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:58:18 by dulrich           #+#    #+#             */
/*   Updated: 2024/03/01 18:52:08 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocate_line(t_data *data, t_pixel grid_pos, char *line)
{
	data->map.grid[grid_pos.px_y] = malloc((data->map.map_w) * \
														sizeof(char));
	if (!(data->map.grid[grid_pos.px_y]))
	{
		free(line);
		ft_free(data, 'g');
		ft_free(data, 't');
		map_error("Issue with allocating space.", data, 0);
	}
	data->map.tiles[grid_pos.px_y] = malloc((data->map.map_w) * \
														sizeof(t_tile));
	if (!(data->map.tiles[grid_pos.px_y]))
	{
		free(line);
		ft_free(data, 'g');
		ft_free(data, 't');
		map_error("Issue with allocating space.", data, 0);
	}
}

void	count_grid(t_data *data, char c, t_pixel p)
{
	if (c == 'P')
	{
		data->start_found++;
		data->player.position = p;
		data->player.start = p;
		data->player.last_pos = p;
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
		while (i < data->map.map_h && data->map.tiles != NULL \
				&& data->map.tiles[i] != NULL)
		{
			free(data->map.tiles[i]);
			data->map.tiles[i++] = NULL;
		}
		free(data->map.tiles);
		data->map.tiles = NULL;
	}
	else if (a == 'g')
	{
		while (i < data->map.map_h && data->map.grid != NULL \
				&& data->map.grid[i] != NULL)
		{
			free(data->map.grid[i]);
			data->map.grid[i++] = NULL;
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
	t_pixel	tmp;

	if (data->map.grid[new_pos.px_y][new_pos.px_x] != '1')
	{
		ft_printf("Total moves: %d\n", ++data->moves);
		tmp = data->player.last_pos;
		if (data->map.grid[new_pos.px_y][new_pos.px_x] == 'E')
		data->player.last_pos = data->player.position;
		data->player.position = new_pos;
		render_player(data);
		if (data->map.grid[new_pos.px_y][new_pos.px_x] == 'C')
		{
			data->collected++;
			data->map.grid[new_pos.px_y][new_pos.px_x] = '0';
			if (data->collected == data->collectible)
			{
				data->exit_unlocked = TRUE;
				render_map(data);
			}
		}
		else if (data->map.grid[new_pos.px_y][new_pos.px_x] == 'E')
		{
			data->player.last_pos = tmp;
			//render_player(data);
			if (data->exit_unlocked)
				put_win_screen(data);
		}
	}
}
