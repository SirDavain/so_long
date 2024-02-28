/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:29:25 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/28 16:36:01 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_background(t_data *data)
{
	t_pixel	start;
	t_pixel	end;

	start.px_x = 0;
	start.px_y = 0;
	end.px_x = data->map.map_w * SIZE;
	end.px_y = data->map.map_h * SIZE;
	while (start.px_y < end.px_y)
	{
		while (start.px_x < end.px_x)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
				data->bgr_sprite.img, start.px_x, start.px_y);
			start.px_x += SIZE;
		}
		start.px_x = 0;
		start.px_y += SIZE;
	}
}

void	render_map(t_data *data)
{
	t_pixel	a;

	a.px_x = 0;
	a.px_y = 0;
	while (a.px_y < data->map.map_h * SIZE)
	{
		while (a.px_x < data->map.map_w * SIZE)
		{
			if (data->map.grid[a.px_y / SIZE][a.px_x / SIZE] == '1')
				put_sprite(data, a, '1');
			else if (data->map.grid[a.px_y / SIZE][a.px_x / SIZE] == '0' ||
						data->map.grid[a.px_y / SIZE][a.px_x / SIZE] == 'P')
				put_sprite(data, a, '0');
			else if (data->map.grid[a.px_y / SIZE][a.px_x / SIZE] == 'C')
				put_sprite(data, a, 'C');
			else if (data->map.grid[a.px_y / SIZE][a.px_x / SIZE] == 'E')
				put_sprite(data, a, 'E');
			a.px_x += SIZE;
		}
		a.px_x = 0;
		a.px_y += SIZE;
	}
	render_player(data);
}

void	render_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->p_sprite.img, \
	data->player.position.px_x * SIZE, data->player.position.px_y * SIZE);
}
