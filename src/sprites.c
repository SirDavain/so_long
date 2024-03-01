/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:01:40 by dulrich           #+#    #+#             */
/*   Updated: 2024/03/01 16:54:49 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_data *data)
{
	data->floor_sprite.img = ft_load_sprite(data, "img/floor_sprite.xpm", \
		&data->floor_sprite.pixel_w, &data->floor_sprite.pixel_h);
	data->flag.floor_sprite = 1;
	data->wall_sprite.img = ft_load_sprite(data, "img/wall_sprite.xpm", \
		&data->wall_sprite.pixel_w, &data->wall_sprite.pixel_h);
	data->flag.wall_sprite = 1;
	data->p_sprite.img = ft_load_sprite(data, "img/p_sprite.xpm", \
		&data->p_sprite.pixel_w, &data->p_sprite.pixel_h);
	data->flag.p_sprite = 1;
	data->clctbl_sprite.img = ft_load_sprite(data, "img/clctbl_sprite.xpm", \
		&data->clctbl_sprite.pixel_w, &data->clctbl_sprite.pixel_h);
	data->flag.clctbl_sprite = 1;
	data->exit_sprite.img = ft_load_sprite(data, "img/exit_sprite.xpm", \
		&data->exit_sprite.pixel_w, &data->exit_sprite.pixel_h);
	data->flag.exit_sprite = 1;
	data->win_sprite.img = ft_load_sprite(data, "img/win_sprite.xpm", \
		&data->win_sprite.pixel_w, &data->win_sprite.pixel_h);
	data->flag.win_sprite = 1;
}

void	*ft_load_sprite(t_data *data, char *str, int *px_w, int *px_h)
{
	t_data	*sprite;

	sprite = mlx_xpm_file_to_image(data->mlx_ptr, str, px_w, px_h);
	if (!sprite)
	{
		free_sprites(data);
		map_error("A sprite couldn't be found.", data, 1);
	}
	return (sprite);
}

void	free_sprites(t_data *data)
{
	if (data->flag.floor_sprite)
		mlx_destroy_image(data->mlx_ptr, data->floor_sprite.img);
	if (data->flag.wall_sprite)
		mlx_destroy_image(data->mlx_ptr, data->wall_sprite.img);
	if (data->flag.p_sprite)
		mlx_destroy_image(data->mlx_ptr, data->p_sprite.img);
	if (data->flag.clctbl_sprite)
		mlx_destroy_image(data->mlx_ptr, data->clctbl_sprite.img);
	if (data->flag.exit_sprite)
		mlx_destroy_image(data->mlx_ptr, data->exit_sprite.img);
	if (data->flag.win_sprite)
		mlx_destroy_image(data->mlx_ptr, data->win_sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
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
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->floor_sprite.img, a.px_x, a.px_y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->clctbl_sprite.img, a.px_x, a.px_y);
	}
	else if (b == 'E')
	{
		if (data->exit_unlocked == TRUE)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
				data->win_sprite.img, a.px_x, a.px_y);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
				data->exit_sprite.img, a.px_x, a.px_y);
	}
}
