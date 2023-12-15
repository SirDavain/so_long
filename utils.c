/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:58:18 by dulrich           #+#    #+#             */
/*   Updated: 2023/12/15 10:26:29 by dulrich          ###   ########.fr       */
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
