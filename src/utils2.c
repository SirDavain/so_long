/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:27:07 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/29 11:54:39 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	get_line_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	put_win_screen(t_data *data)
{
	render_background(data);
	ft_printf("\033[1;32mCongratulations, you won in %d moves!\033[0m\n", \
				data->moves);
	exit_game(data);
}

void	init_vars(t_data *data, char *map_path)
{
	data->map.path = map_path;
	data->map.map_h = 0;
	data->map.map_w = 0;
	data->exit_unlocked = FALSE;
	data->access_to_exit = FALSE;
	data->access_to_collectibles = 0;
	data->collectible = 0;
	data->collected = 0;
	data->moves = 0;
	data->won = FALSE;
	data->exit_found = 0;
	data->start_found = 0;
}

void	init_flags(t_data *data)
{
	data->flag.bgr_sprite = 0;
	data->flag.floor_sprite = 0;
	data->flag.wall_sprite = 0;
	data->flag.p_sprite = 0;
	data->flag.clctbl_sprite = 0;
	data->flag.exit_sprite = 0;
	data->flag.win_sprite = 0;
}