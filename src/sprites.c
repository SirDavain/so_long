/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:01:40 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/08 14:54:03 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_data *data)
{
	data->bgr_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"img/bgr_sprite.xpm", &data->bgr_sprite.pixel_w, \
		&data->bgr_sprite.pixel_h);
	data->p_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"img/p_sprite.xpm", &data->p_sprite.pixel_w, \
		&data->p_sprite.pixel_h);
	data->wall_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"img/wall_sprite.xpm", &data->wall_sprite.pixel_w, \
		&data->wall_sprite.pixel_h);
	data->floor_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"img/floor_sprite.xpm", &data->floor_sprite.pixel_w, \
		&data->floor_sprite.pixel_h);
	data->clctbl_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"img/clctbl_sprite.xpm", &data->clctbl_sprite.pixel_w, \
		&data->clctbl_sprite.pixel_h);
	data->start_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"img/start_sprite.xpm", &data->start_sprite.pixel_w, \
		&data->start_sprite.pixel_h);
	data->exit_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"img/exit_sprite.xpm", &data->exit_sprite.pixel_w, \
		&data->exit_sprite.pixel_h);
	data->win_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"img/win_sprite.xpm", &data->win_sprite.pixel_w, \
		&data->win_sprite.pixel_h);
}

void	put_sprite(t_data *data, t_pixel a, char b)
{
	if (b == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->wall_sprite.img, a.px_x, a.px_y);
	else if (b == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->floor_sprite.img, a.px_x, a.px_y);
	else if (b == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->clctbl_sprite.img, a.px_x, a.px_y);
	else if (b == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->start_sprite.img, a.px_x, a.px_y);
	else if (b == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->exit_sprite.img, a.px_x, a.px_y);
}

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
		while (a.px_x < data->map.map_h * SIZE)
		{
			if (data->map.grid[a.px_x / SIZE][a.px_y / SIZE] == '1')
				put_sprite(data, a, '1');
			else if (data->map.grid[a.px_x / SIZE][a.px_y / SIZE] == '0')
				put_sprite(data, a, '0');
			else if (data->map.grid[a.px_x / SIZE][a.px_y / SIZE] == 'C')
				put_sprite(data, a, 'C');
			else if (data->map.grid[a.px_x / SIZE][a.px_y / SIZE] == 'P')
				put_sprite(data, a, 'P');
			else if (data->map.grid[a.px_x / SIZE][a.px_y / SIZE] == 'E')
				put_sprite(data, a, 'E');
			a.px_x += SIZE;
		}
		a.px_x = 0;
		a.px_y += SIZE;
	}
}

void	render_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->p_sprite.img, \
	data->player.position.px_x * SIZE, data->player.position.px_y * SIZE);
}
