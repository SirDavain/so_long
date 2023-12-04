/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:03:18 by dulrich           #+#    #+#             */
/*   Updated: 2023/11/30 10:45:18 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\n", keysym);
	return (0);
}

void	get_window_size(t_data *data, char *str)
{
	int	fd;
	int	sreen_size;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		perror("Error:\n Invalid map\n");
		exit(EXIT_FAILURE);
	}
	if (!ft_strnstr(str, ".ber", ft_strlen(str)))
	{
		perror("Error:\n Map has to be in format .ber\n");
		exit(EXIT_FAILURE);
	}

	data->size_x = get_line_len(str);
	data->size_y = get_line_nbr(fd);
	mlx_get_screen_size(data->mlx_ptr, data->size_x, data->size_y);
}

int main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	find_window_size(&data, argv[1]);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 600, 400, "hello there");
	if (!win_ptr)
		return (free(mlx_ptr), 1);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}